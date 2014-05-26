#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "internal/messageBuilder.h"

/*****************************************************************************/
/* Generic class handling read-only streaming on buffers that can ONLY go on */
/*****************************************************************************/
struct streamIn {
  size_t                     nCharBufi;                /* Number of wchar_t buffers (start at zero) */
  char                     **charBufpp;                /* char buffers */
  size_t                    *realSizeBufip;            /* Number of bytes effectively available in each buffer */
  streamInBool_t            *managedbp;                /* True if a buffer is managed by the user */
  streamInOption_t           streamInOption;           /* Options */
  streamInBool_t             eofb;                     /* EOF flag */
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

  streamInp->nCharBufi                = 0;
  streamInp->charBufpp                = NULL;
  streamInp->realSizeBufip            = NULL;
  streamInp->managedbp                = NULL;
  streamInp->eofb                     = 0;

  /* From now on we can use STREAMIN_LOG macro */

  streamIn_optionDefaultb(&(streamInp->streamInOption));
  if (_streamIn_optionb(streamInp, streamInOptionp) == STREAMIN_BOOL_FALSE) {
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
  size_t         *realSizeBufip;
  streamInBool_t *managedbp;

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
    }

    if ((bufIndexi + 1) == streamInp->nCharBufi) {
      /* And in fact we destroyed everything */
      free(streamInp->charBufpp);
      streamInp->charBufpp = NULL;

      free(streamInp->realSizeBufip);
      streamInp->realSizeBufip = NULL;

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
	streamInp->realSizeBufip[j] = streamInp->realSizeBufip[i];
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

      realSizeBufip = realloc(streamInp->realSizeBufip, streamInp->nCharBufi * sizeof(void *));
      if (realSizeBufip == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
      } else {
	streamInp->realSizeBufip = realSizeBufip;
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
  size_t         *realSizeBufip;
  streamInBool_t *managedbp;
  char           *charManagedArrayp = NULL;

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

    streamInp->realSizeBufip = malloc(sizeof(size_t));
    if (streamInp->realSizeBufip == NULL) {
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

    realSizeBufip = realloc(streamInp->realSizeBufip, nCharBufi * sizeof(size_t));
    if (streamInp->realSizeBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->realSizeBufip = realSizeBufip;
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
  streamInp->managedbp[bufIndexi] = STREAMIN_BOOL_FALSE;
  streamInp->realSizeBufip[bufIndexi] = 0;

  if (streamInp->streamInOption.readCallbackp != NULL) {
    if ((*streamInp->streamInOption.readCallbackp)(streamInp->streamInOption.readCallbackUserDatap, streamInp->streamInOption.bufMaxSizei, &(streamInp->realSizeBufip[bufIndexi]), streamInp->charBufpp[bufIndexi], &charManagedArrayp) == STREAMIN_BOOL_FALSE) {
      return STREAMIN_BOOL_FALSE;
    }
  }

  if (charManagedArrayp != NULL) {
    /* User-defined buffer */
    streamInp->managedbp[bufIndexi]  = STREAMIN_BOOL_TRUE;
    free(streamInp->charBufpp[bufIndexi]);
    streamInp->charBufpp[bufIndexi] = charManagedArrayp;
  }

  STREAMIN_TRACEX("read callback filled %d bytes in buffer No %d", streamInp->realSizeBufip[bufIndexi], bufIndexi);

  if (streamInp->realSizeBufip[bufIndexi] <= 0) {
    /* Nothing read */
    STREAMIN_TRACE0("EOF");
    streamInp->eofb = STREAMIN_BOOL_TRUE;
    streamInp->realSizeBufip[bufIndexi] = 0;
  }


  streamInp->nCharBufi = bufIndexi + 1;

  if (streamInp->realSizeBufip[bufIndexi] <= 0) {
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
  static char          *emptyMessages = "Empty message";

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
    msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap2) : emptyMessages;
    va_end(ap2);
#else
    msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap) : emptyMessages;
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
    bytesInBuffer = streamInp->realSizeBufip[wantedIndexi];
    rcb = STREAMIN_BOOL_TRUE;
  } else {
    /* Ask for next buffers until we reach wantedIndexi */
    while (streamInp->eofb == STREAMIN_BOOL_FALSE) {
      if (_streamIn_read(streamInp) == STREAMIN_BOOL_FALSE) {
	break;
      }
      if (wantedIndexi < streamInp->nCharBufi) {
	charArrayp = streamInp->charBufpp[wantedIndexi];
	bytesInBuffer = streamInp->realSizeBufip[wantedIndexi];
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

  if (streamInp == NULL) {
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

  if (streamInp == NULL) {
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
  if (streamInp == NULL) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_nextBufferb(%p, %p, %p, %p)", streamInp, indexBufferip, charArraypp, bytesInBufferp);

  return _streamIn_getBufferb(streamInp, streamInp->nCharBufi, indexBufferip, charArraypp, bytesInBufferp);
}

