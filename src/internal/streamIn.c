#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "internal/messageBuilder.h"
#ifdef HAVE_ICU
#include "unicode/ucsdet.h"
#include "unicode/uclean.h"
#include "unicode/ucnv.h"
#endif
#include "charsetdetect.h"

const static char *_streamIn_defaultEncodings = "UTF-8";

static void _streamIn_detectb(streamIn_t *streamInp);
static streamInBool_t _streamIn_convertLastBufferToUtf8b(streamIn_t *streamInp);

#ifdef HAVE_ICU
static streamInBool_t _streamIn_ICU_detectb(streamIn_t *streamInp);
static streamInBool_t _streamIn_ICU_convertb(streamIn_t *streamInp, UConverter *convFrom, UConverter *convTo, char *inputs, size_t lengthl);
static streamInBool_t _streamIn_ICU_convertLastBufferToUtf8b(streamIn_t *streamInp);
#endif
static streamInBool_t _streamIn_charsetdetect_detectb(streamIn_t *streamInp);

/*****************************************************************************/
/* Generic class handling read-only streaming on buffers that can ONLY go on */
/*****************************************************************************/
struct streamIn {
  size_t                     nCharBufi;                /* Number of wchar_t buffers (start at zero) */
  char                     **charBufpp;                /* char buffers */
  size_t                    *realSizeCharBufip;        /* Number of bytes effectively available in each buffer */
  streamInBool_t            *managedbp;                /* True if a buffer is managed by the user */
  streamInOption_t           streamInOption;           /* Byte options */
  streamInBool_t             eofb;                     /* EOF flag */

  /* UTF-8 section */
  streamInBool_t             utf8b;                    /* 1 only if streamInUtf8_newp() is called */
  size_t                     utf8BufMaxSizei;          /* A heuristic guess of the utf8 size v.s. realSizeCharBufip[] */
  char                     **utf8Bufpp;                /* char buffers */
  streamInUtf8Option_t       streamInUtf8Option;       /* Char options */
  size_t                     utf8BufferMarki;          /* Buffer index hosting current character */
  size_t                     utf8BufferOffseti;        /* Offset of current character within buffer No utf8BufferMarki */
#ifdef HAVE_ICU
  size_t                      ucharBufMaxSizei;        /* A heuristic guess of the utf16 size v.s. realSizeCharBufip[] */
  UChar                     **ucharBufpp;              /* UChar buffers */
  UConverter                 *ICU_convFrom;            /* Native converter => UTF-16 (ICU's unicode) */
  UConverterFromUCallback     uConverterFromUCallback;
  const void                 *uConverterFromUCallbackCtxp; 
  UConverter                 *ICU_convTo;              /* UTF-16 (ICU's unicode) => UTF-8 */
  UConverterToUCallback       uConverterToUCallback;
  const void                 *uConverterToUCallbackCtxp; 
#endif
};

#define STREAMIN_DEFAULT_BUFMAXSIZEI (1024*1024)

#define STREAMIN_LOG0(logLeveli, msgs)      _streamIn_log_any(streamInp, logLeveli, msgs)
#define STREAMIN_LOGX(logLeveli, fmts, ...) _streamIn_log_any(streamInp, logLeveli, fmts, __VA_ARGS__)

#ifndef STREAMIN_NTRACE
#define STREAMIN_TRACE0(fmts)      STREAMIN_LOG0(STREAMIN_LOGLEVEL_TRACE, fmts)
#define STREAMIN_TRACEX(fmts, ...) STREAMIN_LOGX(STREAMIN_LOGLEVEL_TRACE, fmts, __VA_ARGS__)
#else
#define STREAMIN_TRACE0(fmts)
#define STREAMIN_TRACEX(fmts, ...)
#endif

static streamInBool_t _streamIn_getBufferb (streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);
static streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static streamInBool_t _streamIn_read       (streamIn_t *streamInp);
static void           _streamIn_log_any    (streamIn_t *streamInp, streamInLogLevel_t streamInLogLeveli, const char *fmts, ...);
static void           _streamIn_logCallback(void *logCallbackDatavp, streamIn_t *marpaWrapperp, streamInLogLevel_t logLeveli, const char *msgs);
static streamInBool_t _streamIn_optionb    (streamIn_t *streamInp, streamInOption_t *streamInOptionp);
static streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp);

/***************************/
/* streamIn_optionDefaultb */
/***************************/
streamInBool_t streamIn_optionDefaultb(streamInOption_t *streamInOptionp){
  if (streamInOptionp == NULL) {
    return STREAMIN_BOOL_FALSE;
  }

  streamInOptionp->bufMaxSizei                  = STREAMIN_DEFAULT_BUFMAXSIZEI;
  streamInOptionp->logLevelWantedi              = STREAMIN_LOGLEVEL_WARNING;
  streamInOptionp->logCallbackp                 = NULL;
  streamInOptionp->logCallbackUserDatap         = NULL;
  streamInOptionp->readCallbackp                = NULL;
  streamInOptionp->readCallbackUserDatap        = NULL;
  streamInOptionp->bufFreeCallbackp             = NULL;
  streamInOptionp->bufFreeCallbackUserDatap     = NULL;

  return STREAMIN_BOOL_TRUE;
}

/*****************/
/* streamIn_newp */
/*****************/
streamIn_t *streamIn_newp(streamInOption_t *streamInOptionp) {
  streamIn_t      *streamInp;
  char            *errorMsgs = NULL;

  streamInp = malloc(sizeof(streamIn_t));
  if (streamInp == NULL) {
    if (streamInOptionp->logCallbackp != NULL) {
      errorMsgs = messageBuilder("malloc(): %s", errno);
      (*streamInOptionp->logCallbackp)(streamInOptionp->logCallbackUserDatap, NULL, STREAMIN_LOGLEVEL_ERROR, errorMsgs);
    }
    if (errorMsgs != messageBuilder_internalErrors()) {
      free(errorMsgs);
    }
    return NULL;
  }

  streamInp->nCharBufi     = 0;
  streamInp->charBufpp     = NULL;
  streamInp->realSizeCharBufip = NULL;
  streamInp->managedbp     = NULL;
  streamInp->eofb          = 0;
  streamInp->utf8b         = STREAMIN_BOOL_FALSE;

  /* From now on we can use STREAMIN_LOG macro */

  streamIn_optionDefaultb(&(streamInp->streamInOption));
  if (_streamIn_optionb(streamInp, streamInOptionp) == STREAMIN_BOOL_FALSE) {
    streamIn_destroyv(&streamInp);
    return NULL;
  }

  return streamInp;
}

/*********************/
/* streamInUtf8_newp */
/*********************/
streamIn_t *streamInUtf8_newp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamIn_t *streamInp = streamIn_newp(streamInOptionp);

  if (streamInp == NULL) {
    return NULL;
  }

  streamInp->utf8b            = STREAMIN_BOOL_TRUE;
  streamInp->utf8BufMaxSizei  = streamInp->streamInOption.bufMaxSizei * 2;   /* A guess that, initially, a utf8 buffer twice bigger is enough */
  streamInp->utf8Bufpp        = NULL;
#ifdef HAVE_ICU
  streamInp->ucharBufMaxSizei = streamInp->streamInOption.bufMaxSizei * 2;  /* A guess that, initially, a uchar (UTF-16) buffer twice bigger is enough */
  streamInp->ucharBufpp       = NULL;
#endif

  streamInUtf8_optionDefaultb(&(streamInp->streamInUtf8Option));
  if (_streamInUtf8_optionb(streamInp, streamInUtf8Optionp) == STREAMIN_BOOL_FALSE) {
    streamIn_destroyv(&streamInp);
    return NULL;
  }

  return streamInp;
}

/********************************************/
/* _streamIn_doneBufferb                    */
/********************************************/
static streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi)
{
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;
  size_t          i, j;
  char          **charBufpp;
  size_t         *realSizeCharBufip;
  streamInBool_t *managedbp;
  char          **utf8Bufpp;
#ifdef HAVE_ICU
  UChar         **ucharBufpp;
#endif

  /* We want to forget forever buffer at index bufIndexi. */
  /* Any eventual previous buffer will me removed as well  */

  if (streamInp->nCharBufi > 0 && bufIndexi < streamInp->nCharBufi) {

    STREAMIN_TRACEX("Destroying buffers [%d..%d]", 0, bufIndexi);

    /* We destroy the buffers */
    for (i = 0; i <= bufIndexi; ++i) {
      if (streamInp->managedbp[i] == STREAMIN_BOOL_FALSE) {
        free(streamInp->charBufpp[i]);
      } else if (streamInp->streamInOption.bufFreeCallbackp != NULL) {
	(*streamInp->streamInOption.bufFreeCallbackp)(streamInp->streamInOption.bufFreeCallbackUserDatap, streamInp->charBufpp[i]);
      }
      streamInp->charBufpp[i] = NULL;
      if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
        free(streamInp->utf8Bufpp[i]);
        streamInp->utf8Bufpp[i] = NULL;
#ifdef HAVE_ICU
        free(streamInp->ucharBufpp[i]);
        streamInp->ucharBufpp[i] = NULL;
#endif
      }
    }

    if ((bufIndexi + 1) == streamInp->nCharBufi) {
      /* And in fact we destroyed everything */
      free(streamInp->charBufpp);
      streamInp->charBufpp = NULL;
      if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
	free(streamInp->utf8Bufpp);
	streamInp->utf8Bufpp = NULL;
#ifdef HAVE_ICU
	free(streamInp->ucharBufpp);
	streamInp->ucharBufpp = NULL;
#endif
      }

      free(streamInp->realSizeCharBufip);
      streamInp->realSizeCharBufip = NULL;

      free(streamInp->managedbp);
      streamInp->managedbp = NULL;

      streamInp->nCharBufi = 0;
    }
    else {

      STREAMIN_TRACEX("Moving information of buffers [%d..%d] to [0..%d]", bufIndexi + 1, streamInp->nCharBufi, streamInp->nCharBufi - (bufIndexi + 1));

      /* We have to realloc, taking care of moving backward */
      /* the informations                                   */
      for (j = 0, i = (bufIndexi + 1); i < streamInp->nCharBufi; ++i, ++j) {
	streamInp->charBufpp[j] = streamInp->charBufpp[i];
	if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
	  streamInp->utf8Bufpp[j] = streamInp->utf8Bufpp[i];
#ifdef HAVE_ICU
	  streamInp->ucharBufpp[j] = streamInp->ucharBufpp[i];
#endif
	}
	streamInp->realSizeCharBufip[j] = streamInp->realSizeCharBufip[i];
	streamInp->managedbp[j] = streamInp->managedbp[i];
      }

      streamInp->nCharBufi -= (bufIndexi+1);

      /* Formally, on realloc error, we can continue */
      charBufpp = realloc(streamInp->charBufpp, streamInp->nCharBufi * sizeof(char *));
      if (charBufpp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
      } else {
	streamInp->charBufpp = charBufpp;
      }
      if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
	utf8Bufpp = realloc(streamInp->utf8Bufpp, streamInp->nCharBufi * sizeof(char *));
	if (utf8Bufpp == NULL) {
	  STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
	} else {
	  streamInp->utf8Bufpp = utf8Bufpp;
	}
#ifdef HAVE_ICU
	ucharBufpp = realloc(streamInp->ucharBufpp, streamInp->nCharBufi * sizeof(UChar *));
	if (ucharBufpp == NULL) {
	  STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
	} else {
	  streamInp->ucharBufpp = ucharBufpp;
	}
#endif
      }

      realSizeCharBufip = realloc(streamInp->realSizeCharBufip, streamInp->nCharBufi * sizeof(void *));
      if (realSizeCharBufip == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
      } else {
	streamInp->realSizeCharBufip = realSizeCharBufip;
      }

      managedbp = realloc(streamInp->managedbp, streamInp->nCharBufi * sizeof(streamInBool_t));
      if (managedbp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
      } else {
	streamInp->managedbp = managedbp;
      }
    }
  } else {
    rcb = STREAMIN_BOOL_FALSE;
  }

  return rcb;
}

/********************************************/
/* _streamIn_read                           */
/********************************************/
static streamInBool_t _streamIn_read(streamIn_t *streamInp) {
  size_t          bufIndexi;
  size_t          nCharBufi;
  char          **charBufpp;
  size_t         *realSizeCharBufip;
  streamInBool_t *managedbp;
  char           *charManagedArrayp = NULL;
  char          **utf8Bufpp;
#ifdef HAVE_ICU
  UChar         **ucharBufpp;
#endif

  if (streamInp->eofb == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  bufIndexi = streamInp->nCharBufi;

  STREAMIN_TRACEX("Allocating space for buffer No %d", (int) bufIndexi);

  /* Allocate space */
  if (bufIndexi == 0) {

    streamInp->charBufpp = malloc(sizeof(char *));
    if (streamInp->charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

    if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
      streamInp->utf8Bufpp = malloc(sizeof(char *));
      if (streamInp->utf8Bufpp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      }
#ifdef HAVE_ICU
      streamInp->ucharBufpp = malloc(sizeof(UChar *));
      if (streamInp->ucharBufpp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      }
#endif
    }

    streamInp->realSizeCharBufip = malloc(sizeof(size_t));
    if (streamInp->realSizeCharBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

    streamInp->managedbp = malloc(sizeof(streamInBool_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    nCharBufi = bufIndexi + 1;

    charBufpp = realloc(streamInp->charBufpp, nCharBufi * sizeof(char *));
    if (charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->charBufpp = charBufpp;
    }

    if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
      utf8Bufpp = realloc(streamInp->utf8Bufpp, nCharBufi * sizeof(char *));
      if (utf8Bufpp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      } else {
	streamInp->utf8Bufpp = utf8Bufpp;
      }
#ifdef HAVE_ICU
      ucharBufpp = realloc(streamInp->ucharBufpp, nCharBufi * sizeof(UChar *));
      if (ucharBufpp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      } else {
	streamInp->ucharBufpp = ucharBufpp;
      }
#endif
    }

    realSizeCharBufip = realloc(streamInp->realSizeCharBufip, nCharBufi * sizeof(size_t));
    if (streamInp->realSizeCharBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->realSizeCharBufip = realSizeCharBufip;
    }

    managedbp = realloc(streamInp->managedbp, nCharBufi * sizeof(size_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->managedbp = managedbp;
    }

  }

  streamInp->charBufpp[bufIndexi]  = malloc(streamInp->streamInOption.bufMaxSizei);
  if (streamInp->charBufpp[bufIndexi] == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
    return STREAMIN_BOOL_FALSE;
  }
  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    streamInp->utf8Bufpp[bufIndexi]  = malloc(streamInp->utf8BufMaxSizei);
    if (streamInp->utf8Bufpp[bufIndexi] == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }
#ifdef HAVE_ICU
    streamInp->ucharBufpp[bufIndexi]  = malloc(sizeof(UChar) * streamInp->ucharBufMaxSizei);
    if (streamInp->ucharBufpp[bufIndexi] == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }
#endif
  }
  streamInp->managedbp[bufIndexi] = STREAMIN_BOOL_FALSE;
  streamInp->realSizeCharBufip[bufIndexi] = 0;

  if (streamInp->streamInOption.readCallbackp != NULL) {
    if ((*streamInp->streamInOption.readCallbackp)(streamInp->streamInOption.readCallbackUserDatap, streamInp->streamInOption.bufMaxSizei, &(streamInp->realSizeCharBufip[bufIndexi]), streamInp->charBufpp[bufIndexi], &charManagedArrayp) == STREAMIN_BOOL_FALSE) {
      return STREAMIN_BOOL_FALSE;
    }
  }

  if (charManagedArrayp != NULL) {
    /* User-defined buffer */
    streamInp->managedbp[bufIndexi]  = STREAMIN_BOOL_TRUE;
    free(streamInp->charBufpp[bufIndexi]);
    streamInp->charBufpp[bufIndexi] = charManagedArrayp;
  }

  STREAMIN_TRACEX("read callback filled %d bytes in buffer No %d", streamInp->realSizeCharBufip[bufIndexi], bufIndexi);

  if (streamInp->realSizeCharBufip[bufIndexi] <= 0) {
    /* Nothing read */
    STREAMIN_TRACE0("EOF");
    streamInp->eofb = STREAMIN_BOOL_TRUE;
    streamInp->realSizeCharBufip[bufIndexi] = 0;
  }


  streamInp->nCharBufi = bufIndexi + 1;

  if (streamInp->realSizeCharBufip[bufIndexi] <= 0) {
    if (bufIndexi == 0) {
      /* Nothing was read - this could have been done before, but happens only once, at EOF     */
      /* If we were working on the first buffer, we can safely call _streamIn_doneBufferb()     */
      /* otherwise there is a leftover of pointers, we only free what has been allocated inside */
      /* No need to redo a realloc. Next eventuall call will simply realloc on the same size.   */
      _streamIn_doneBufferb(streamInp, bufIndexi);
    } else {
      free(streamInp->charBufpp[bufIndexi]);
      streamInp->nCharBufi--;     
    }
    return STREAMIN_BOOL_FALSE;
  }

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    if (streamInp->streamInUtf8Option.encodings == NULL) {
      /* User did a streamInUtf8_newp. The very first time, we auto-detect encoding */
      _streamIn_detectb(streamInp);
    }
    /* Convert to UTF-8 */
  }

  return STREAMIN_BOOL_TRUE;
}

/*********************/
/* _streamIn_log_any */
/*********************/
static void _streamIn_log_any(streamIn_t *streamInp, streamInLogLevel_t streamInLogLeveli, const char *fmts, ...) {
  va_list               ap;
#ifdef VA_COPY
  va_list               ap2;
#endif
  char                 *msgs;
  streamInLogCallback_t logCallbackp;
  void                 *logCallbackDatavp;
  static const char    *emptyMessages = "Empty message";

  if (streamInLogLeveli >= streamInp->streamInOption.logLevelWantedi) {

    if (streamInp->streamInOption.logCallbackp == NULL) {
      logCallbackp = &_streamIn_logCallback;
      logCallbackDatavp = NULL;
    } else {
      logCallbackp = streamInp->streamInOption.logCallbackp;
      logCallbackDatavp = streamInp->streamInOption.logCallbackUserDatap;
    }

    va_start(ap, fmts);
#ifdef VA_COPY
    VA_COPY(ap2, ap);
    msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap2) : (char *) emptyMessages;
    va_end(ap2);
#else
    msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap) : (char *) emptyMessages;
#endif
    va_end(ap);

    if (msgs != messageBuilder_internalErrors()) {
      logCallbackp(logCallbackDatavp, streamInp, streamInLogLeveli, msgs);
    } else {
      logCallbackp(logCallbackDatavp, streamInp, STREAMIN_LOGLEVEL_ERROR, msgs);
    }

    if (msgs != emptyMessages && msgs != messageBuilder_internalErrors()) {
      free(msgs);
    }
  }
}

/*************************/
/* _streamIn_logCallback */
/*************************/
static void _streamIn_logCallback(void *logCallbackDatavp, streamIn_t *streaminp, streamInLogLevel_t logLeveli, const char *msgs) {
  const char *prefix;

  switch (logLeveli) {
  case STREAMIN_LOGLEVEL_TRACE:     prefix = "TRACE";     break;
  case STREAMIN_LOGLEVEL_DEBUG:     prefix = "DEBUG";     break;
  case STREAMIN_LOGLEVEL_INFO:      prefix = "INFO";      break;
  case STREAMIN_LOGLEVEL_NOTICE:    prefix = "NOTICE";    break;
  case STREAMIN_LOGLEVEL_WARNING:   prefix = "WARNING";   break;
  case STREAMIN_LOGLEVEL_ERROR:     prefix = "ERROR";     break;
  case STREAMIN_LOGLEVEL_CRITICAL:  prefix = "CRITICAL";  break;
  case STREAMIN_LOGLEVEL_ALERT:     prefix = "ALERT";     break;
  case STREAMIN_LOGLEVEL_EMERGENCY: prefix = "EMERGENCY"; break;
  default:                          prefix = "UNKNOWN";   break;
  }

  fprintf(stderr, "[%9s] %s\n", prefix, (msgs != NULL) ? msgs : "No message");
}

/*********************/
/* streamIn_destroyv */
/*********************/
void streamIn_destroyv(streamIn_t **streamInpp) {
  streamIn_t *streamInp;

  if (streamInpp == NULL) {
    return;
  }

  streamInp = *streamInpp;
  if (streamInp == NULL) {
    return;
  }

  STREAMIN_TRACEX("streamIn_destroyv(%p)", streamInpp);

  if (streamInp->nCharBufi > 0) {
    _streamIn_doneBufferb(streamInp, streamInp->nCharBufi - 1);
  }
  if (streamInp->streamInUtf8Option.encodings != NULL) {
    if (streamInp->streamInUtf8Option.encodings != _streamIn_defaultEncodings) {
      free(streamInp->streamInUtf8Option.encodings);
    }
  }

#ifdef HAVE_ICU
  if (streamInp->ICU_convTo != NULL) {
    ucnv_close(streamInp->ICU_convTo);
  }
  if (streamInp->ICU_convFrom != NULL) {
    ucnv_close(streamInp->ICU_convFrom);
  }
#ifdef STREAMIN_SINGLE_TEST_APPLICATION_ONLY
  /* ICU recommendation is to NOT call this. This is done automatically at library unload */
  u_cleanup();
#endif
#endif

  free(streamInp);
  *streamInpp = NULL;
}

/************************/
/* _streamIn_getBufferb */
/************************/
static streamInBool_t _streamIn_getBufferb(streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp) {
  char          *charArrayp;
  size_t         bytesInBuffer;
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (wantedIndexi < streamInp->nCharBufi) {
    /* Available */
    charArrayp = streamInp->charBufpp[wantedIndexi];
    bytesInBuffer = streamInp->realSizeCharBufip[wantedIndexi];
    rcb = STREAMIN_BOOL_TRUE;
  } else {
    /* Ask for next buffers until we reach wantedIndexi */
    while (streamInp->eofb == STREAMIN_BOOL_FALSE) {
      if (_streamIn_read(streamInp) == STREAMIN_BOOL_FALSE) {
	break;
      }
      if (wantedIndexi < streamInp->nCharBufi) {
	charArrayp = streamInp->charBufpp[wantedIndexi];
	bytesInBuffer = streamInp->realSizeCharBufip[wantedIndexi];
	rcb = STREAMIN_BOOL_TRUE;
	break;
      }
    }
  }

  if (rcb == STREAMIN_BOOL_TRUE) {
    if (indexBufferip != NULL) {
      *indexBufferip = wantedIndexi;
    }
    if (charArraypp != NULL) {
      *charArraypp = charArrayp;
    }
    if (charArraypp != NULL) {
      *bytesInBufferp = bytesInBuffer;
    }
  }

  return rcb;
}

/***********************/
/* streamIn_getBufferb */
/***********************/
streamInBool_t streamIn_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp) {
  size_t wantedIndexi;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_getBufferb(%p, %d, %p, %p, %p)", streamInp, indexBufferi, indexBufferip, charArraypp, bytesInBufferp);

  if (indexBufferi < 0) {
    wantedIndexi = streamInp->nCharBufi;
    wantedIndexi -= (size_t) -indexBufferi;
  } else {
    wantedIndexi = indexBufferi;
  }

  return _streamIn_getBufferb(streamInp, wantedIndexi, indexBufferip, charArraypp, bytesInBufferp);
}

/************************/
/* streamIn_doneBufferb */
/************************/
streamInBool_t streamIn_doneBufferb(streamIn_t *streamInp, int indexBufferi) {
  size_t wantedIndexi;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_doneBufferb(%p, %d)", streamInp, indexBufferi);

  if (indexBufferi < 0) {
    wantedIndexi = streamInp->nCharBufi;
    wantedIndexi -= (size_t) -indexBufferi;
  } else {
    wantedIndexi = indexBufferi;
  }

  return _streamIn_doneBufferb(streamInp, wantedIndexi);
}

/********************/
/* streamIn_optionb */
/********************/
streamInBool_t streamIn_optionb(streamIn_t *streamInp, streamInOption_t *streamInOptionp) {
  if (streamInp == NULL) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_option(%p, %p)", streamInp, streamInOptionp);

  return _streamIn_optionb(streamInp, streamInOptionp);
}

/*********************/
/* _streamIn_optionb */
/*********************/
static streamInBool_t _streamIn_optionb(streamIn_t *streamInp, streamInOption_t *streamInOptionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInOptionp != NULL) {
    if (streamInOptionp->bufMaxSizei <= 0) {
      STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "Invalid bufMaxSizei");
      rcb = STREAMIN_BOOL_FALSE;
    }

    if (rcb == STREAMIN_BOOL_TRUE) {
      streamInp->streamInOption = *streamInOptionp;
    }
  }

  return rcb;
}

/************************/
/* streamIn_nextBufferb */
/************************/
streamInBool_t streamIn_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_nextBufferb(%p, %p, %p, %p)", streamInp, indexBufferip, charArraypp, bytesInBufferp);

  return _streamIn_getBufferb(streamInp, streamInp->nCharBufi, indexBufferip, charArraypp, bytesInBufferp);
}

/*********************/
/* _streamIn_detectb */
/*********************/
static void _streamIn_detectb(streamIn_t *streamInp) {
  if (
#ifdef HAVE_ICU
      _streamIn_ICU_detectb(streamInp) == STREAMIN_BOOL_TRUE ||
#endif
      _streamIn_charsetdetect_detectb(streamInp) == STREAMIN_BOOL_TRUE
      ) {
    return;
  }

  STREAMIN_LOG0(STREAMIN_LOGLEVEL_INFO, "Charset detection failure, assuming UTF-8");
  streamInp->streamInUtf8Option.encodings = (char *) _streamIn_defaultEncodings;
}

#ifdef HAVE_ICU
/*************************/
/* _streamIn_ICU_detectb */
/*************************/
static streamInBool_t _streamIn_ICU_detectb(streamIn_t *streamInp) {
  UErrorCode           uErrorCode = U_ZERO_ERROR;
  UCharsetDetector    *uCharsetDetector;
  const UCharsetMatch *uCharsetMatch;
  const char          *encodings;
  int32_t              confidence; 
  streamInBool_t       rcb = STREAMIN_BOOL_TRUE;

  STREAMIN_TRACE0("Determining encoding using ICU");

  uCharsetDetector = ucsdet_open(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_open(): %s", u_errorName(uErrorCode));
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  ucsdet_setText(uCharsetDetector, streamInp->charBufpp[0], streamInp->realSizeCharBufip[0], &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_setText(): %s", u_errorName(uErrorCode));
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  uCharsetMatch = ucsdet_detect(uCharsetDetector, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect(): %s", u_errorName(uErrorCode));
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (uCharsetMatch == NULL) {
    STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect() returned NULL");
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  encodings = ucsdet_getName(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName(): %s", u_errorName(uErrorCode));
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (encodings == NULL) {
    STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned NULL");
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (strlen(encodings) <= 0) {
    STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned empty string");
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  confidence = ucsdet_getConfidence(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getConfidence(): %s", u_errorName(uErrorCode));
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  if (confidence < 10) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "ucsdet_getConfidence() returned encoding %s with too low confidence %d < 10 - rejected", encodings, confidence);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ICU returned encoding %s with confidence %d", encodings, confidence);

 ICU_end:

  if (rcb == STREAMIN_BOOL_TRUE) {
    /* Save the result */
    streamInp->streamInUtf8Option.encodings = malloc(sizeof(char) * (strlen(encodings) + 1));
    if (streamInp->streamInUtf8Option.encodings == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      rcb = STREAMIN_BOOL_FALSE;
    } else {
      strcpy(streamInp->streamInUtf8Option.encodings, encodings);
    }
  }

  /* Create "From" converter */
  if (rcb == STREAMIN_BOOL_TRUE) {
    streamInp->ICU_convFrom = ucnv_open(streamInp->streamInUtf8Option.encodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_open(): %s", u_errorName(uErrorCode));
      rcb = STREAMIN_BOOL_FALSE;
    }
  }
  if (rcb == STREAMIN_BOOL_TRUE) {
    ucnv_setFromUCallBack(streamInp->ICU_convFrom, streamInp->uConverterFromUCallback, streamInp->uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_setFromUCallBack(): %s", u_errorName(uErrorCode));
      rcb = STREAMIN_BOOL_FALSE;
    }
  }
  /* Create "To" converter */
  if (rcb == STREAMIN_BOOL_TRUE) {
    streamInp->ICU_convTo = ucnv_open(_streamIn_defaultEncodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_open(): %s", u_errorName(uErrorCode));
      rcb = STREAMIN_BOOL_FALSE;
    }
  }
  if (rcb == STREAMIN_BOOL_TRUE) {
    ucnv_setToUCallBack(streamInp->ICU_convTo, streamInp->uConverterToUCallback, streamInp->uConverterToUCallbackCtxp, NULL, NULL, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_setToUCallBack(): %s", u_errorName(uErrorCode));
      rcb = STREAMIN_BOOL_FALSE;
    }
  }
  if (rcb == STREAMIN_BOOL_TRUE) {
    UBool fallbackb = (streamInp->streamInUtf8Option.ICUFallbackb == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;
    ucnv_setFallback(streamInp->ICU_convTo, fallbackb);
  }

  if (uCharsetDetector != NULL) {
    ucsdet_close(uCharsetDetector);
  }

  return rcb;
}
#endif

/***********************************/
/* _streamIn_charsetdetect_detectb */
/***********************************/
static streamInBool_t _streamIn_charsetdetect_detectb(streamIn_t *streamInp) {
  csd_t       csdp;
  int         result;
  const char *encodings;
  float       confidencef;

  csdp = csd_open();
  if (csdp == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "csd_open(): %s", strerror(errno));
    return STREAMIN_BOOL_FALSE;
  } else {
    result = csd_consider(csdp, streamInp->charBufpp[0], streamInp->realSizeCharBufip[0]);
    /* We are not going to ask for more data: a reasonable application will at least */
    /* use the default cache of 1M, that must be large enough in any case            */
    if (result < 0) {
      STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "csd_consider() failure");
      csd_close(csdp);
      return STREAMIN_BOOL_FALSE;
    } else {
      encodings = csd_close2(csdp, &confidencef);
      if (encodings == NULL) {
	STREAMIN_LOG0(STREAMIN_LOGLEVEL_ERROR, "csd_close() returned NULL");
	return STREAMIN_BOOL_FALSE;
      } else {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "libcharsetdetect returned encoding %s with confidence %f", encodings, (double) confidencef);
	/* Save the result */
	streamInp->streamInUtf8Option.encodings = malloc(sizeof(char) * (strlen(encodings) + 1));
	if (streamInp->streamInUtf8Option.encodings == NULL) {
	  STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
	  return STREAMIN_BOOL_FALSE;
	} else {
	  strcpy(streamInp->streamInUtf8Option.encodings, encodings);
	}
      }
    }
  }

  return STREAMIN_BOOL_TRUE;
}

/**************************/
/* streamInUtf8_encodings */
/**************************/
streamInBool_t streamInUtf8_encodings(streamIn_t *streamInp, char **encodingsp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  if (encodingsp != NULL) {
    *encodingsp = streamInp->streamInUtf8Option.encodings;
  }

  return STREAMIN_BOOL_TRUE;
}

/*********************/
/* streamInUtf8_next */
/*********************/
signed int streamInUtf8_next(streamIn_t *streamInp) {
  size_t         indexBufferi;
  char          *charArrayp;
  size_t         bytesInBuffer;
  signed int     rci = -1;
  streamInBool_t foundb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rci;
  }

  /* Loop until there an available UTF-8 character or eof */
  do {
    /* If no buffer ask for the next one */
    if (streamInp->nCharBufi <= 0) {
      if (_streamIn_getBufferb(streamInp, streamInp->nCharBufi, &indexBufferi, &charArrayp, &bytesInBuffer) == STREAMIN_BOOL_FALSE) {
	break;
      }
      /* Make sure utf8BufferMarki and utf8BufferOffseti are set */
      streamInp->utf8BufferMarki = 0;
      streamInp->utf8BufferOffseti = 0;
    }
  } while (foundb == STREAMIN_BOOL_FALSE);
  
  return rci;
}

/**************************************/
/* _streamIn_convertLastBufferToUtf8b */
/**************************************/
static streamInBool_t _streamIn_convertLastBufferToUtf8b(streamIn_t *streamInp) {
#ifdef HAVE_ICU
  if (_streamIn_ICU_convertLastBufferToUtf8b(streamInp) == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_TRUE;
  }
#endif
  return STREAMIN_BOOL_FALSE;
}

#ifdef HAVE_ICU
/******************************************/
/* _streamIn_ICU_convertLastBufferToUtf8b */
/******************************************/
static streamInBool_t _streamIn_ICU_convertLastBufferToUtf8b(streamIn_t *streamInp) {
  UErrorCode   err         = U_ZERO_ERROR;
  size_t       lastBufi    = streamInp->nCharBufi;
  UChar       *target      = streamInp->ucharBufpp[lastBufi];
  const UChar *targetLimit = streamInp->ucharBufpp[lastBufi] + streamInp->ucharBufMaxSizei;
  const char  *source      = streamInp->charBufpp[lastBufi];
  const char  *sourceLimit = streamInp->charBufpp[lastBufi] + streamInp->realSizeCharBufip[lastBufi];
  UBool        flush       = (streamInp->utf8b == STREAMIN_BOOL_TRUE) ? 1 : 0;
  UChar        *ucharp;

  do {

    ucnv_toUnicode(streamInp->ICU_convFrom, &target, targetLimit, &source, sourceLimit, flush, NULL, &err);

    if (err == U_BUFFER_OVERFLOW_ERROR) {
      /* ucnv_toUnicode() is a statefull method.                                 */
      /* We remember for the next time that our heuristic was underestimated and */
      /* expand ourself the current target buffer                                */
      ucharp = realloc(streamInp->ucharBufpp[lastBufi], sizeof(UChar) * (streamInp->ucharBufMaxSizei * 2));
      if (ucharp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      }

      /* Realloc can have moved the buffer, so doing target = targetLimit is wrong */
      streamInp->ucharBufpp[lastBufi] = ucharp;
      target = streamInp->ucharBufpp[lastBufi] + streamInp->ucharBufMaxSizei;
      streamInp->ucharBufMaxSizei *= 2;
      targetLimit = streamInp->ucharBufpp[lastBufi] + streamInp->ucharBufMaxSizei;
    }

  } while (err == U_BUFFER_OVERFLOW_ERROR);


}
#endif

/*******************************/
/* streamInUtf8_optionDefaultb */
/*******************************/
streamInBool_t streamInUtf8_optionDefaultb(streamInUtf8Option_t *streamInUtf8Optionp) {
  if (streamInUtf8Optionp == NULL) {
    return STREAMIN_BOOL_FALSE;
  }

  streamInUtf8Optionp->encodings       = NULL;
#ifdef HAVE_ICU
  streamInUtf8Optionp->ICUToCallback   = STREAMINUTF8_ICUCALLBACK_STOP;
  streamInUtf8Optionp->ICUFromCallback = STREAMINUTF8_ICUCALLBACK_STOP;
  streamInUtf8Optionp->ICUFallbackb    = STREAMIN_BOOL_FALSE;
#endif

  return STREAMIN_BOOL_TRUE;

}

/*************************/
/* _streamInUtf8_optionb */
/*************************/
static streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInUtf8Optionp != NULL) {
#ifdef HAVE_ICU
    switch (streamInUtf8Optionp->ICUToCallback) {
    case STREAMINUTF8_ICUCALLBACK_SUBSTITUTE:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_SUBSTITUTE;
      streamInp->uConverterToUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_SKIP:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_SKIP;
      streamInp->uConverterToUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_STOP:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_STOP;
      streamInp->uConverterToUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_ICU:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_ICU;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_JAVA:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_JAVA;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_C:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_C;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML_HEX:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML_DEC:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_UNICODE:
      streamInp->uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
      streamInp->uConverterToUCallbackCtxp = UCNV_ESCAPE_UNICODE;
      break;
    default:
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUToCallback %d", streamInUtf8Optionp->ICUToCallback);
      rcb = STREAMIN_BOOL_FALSE;
    }
    switch (streamInUtf8Optionp->ICUFromCallback) {
    case STREAMINUTF8_ICUCALLBACK_SUBSTITUTE:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SUBSTITUTE;
      streamInp->uConverterFromUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_SKIP:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SKIP;
      streamInp->uConverterFromUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_STOP:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_STOP;
      streamInp->uConverterFromUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = NULL;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_ICU:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_ICU;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_JAVA:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_JAVA;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_C:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_C;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML_HEX:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_XML_DEC:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
      break;
    case STREAMINUTF8_ICUCALLBACK_ESCAPE_UNICODE:
      streamInp->uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
      streamInp->uConverterFromUCallbackCtxp = UCNV_ESCAPE_UNICODE;
      break;
    default:
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d", streamInUtf8Optionp->ICUFromCallback);
      rcb = STREAMIN_BOOL_FALSE;
    }
#endif

    if (rcb == STREAMIN_BOOL_TRUE) {
      streamInp->streamInUtf8Option = *streamInUtf8Optionp;
    }
  }

  return rcb;
}

