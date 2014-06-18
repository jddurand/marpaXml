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
#include "unicode/utext.h"
#endif
#include "charsetdetect.h"

const static char *_streamIn_defaultEncodings = "UTF-8";

static streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static void           _streamInUtf8_detectb(streamIn_t *streamInp);
static streamInBool_t _streamInUtf8_convertb(streamIn_t *streamInp, size_t bufIndexi);
static void           _streamInUtf8_destroyv(streamIn_t *streamInp);
static streamInBool_t _streamInUtf8_readb(streamIn_t *streamInp, size_t bufIndexi);

#ifdef HAVE_ICONV
typedef struct streamIn_ICONV {
  /* With iconv we do a single conversion Native => UTF-8 */
  size_t                     utf8BufMulSizei;          /* A heuristic guess of the utf8 takes maximum twice more space than native bytes */
  char                      *utf8Bufp;                 /* utf8 buffer */
  size_t                     utf8BufMarki;             /* Buffer index hosting current character */
  size_t                     utf8BufOffseti;           /* Offset of current character within buffer No utf8BufMarki */
  size_t                     utf8BufLengthi;           /* Number of valid bytes in utf8 buffer */
} streamIn_ICONV_t;
static streamInBool_t *streamInUtf8_ICONV_newb(streamIn_t *streamInp);
#endif
#ifdef HAVE_ICU
typedef struct streamIn_ICU {
  /* With ICU we do a single conversion Native => UChar                */
  /* into a SINGLE buffer. We maintain a mapping charBufpp[] -> offset */
  size_t                     *charBuf2UCharBufOffsetpp;/* mapping end of char buffers => offset in ucharBufp */
  size_t                      ucharBufMulSizei;        /* A heuristic guess of the utf16 takes maximum twice more space than native bytes */
  UChar                      *ucharBufp;               /* UChar buffer */
  size_t                      ucharBufSizei;           /* Current size of allocated memory */
  int64_t                     ucharByteLengthl;        /* Length in bytes of all UChar characters */
  UConverter                 *uConverter;              /* Native converter => UTF-16 (ICU's unicode) */
  UConverterFromUCallback     uConverterFromUCallback;
  const void                 *uConverterFromUCallbackCtxp;
  UText                      *utextp;
} streamIn_ICU_t;
static streamInBool_t  streamInUtf8_ICU_newb(streamIn_t *streamInp);
static streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp);
static streamInBool_t _streamInUtf8_ICU_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi);
static streamInBool_t _streamInUtf8_ICU_detectb(streamIn_t *streamInp);
static streamInBool_t _streamInUtf8_ICU_convertb(streamIn_t *streamInp, size_t bufIndexi);
static unsigned char  _streaminUtf8_ICU_nibbleToHex(uint8_t n);
static signed int     _streamInUtf8_ICU_currenti(streamIn_t *streamInp);
static signed int     _streamInUtf8_ICU_nexti(streamIn_t *streamInp);
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
  streamInBool_t             utf8b;                    /* STREAMIN_BOOL_TRUE only if streamInUtf8_newp() is called */
  streamInBool_t             nativeIsUtf8b;            /* STREAMIN_BOOL_TRUE only if original stream is rleady UTF-8 */
  streamInUtf8Option_t       streamInUtf8Option;       /* utf8 options */
#ifdef HAVE_ICONV
  streamIn_ICONV_t           streamIn_ICONV;
#endif
#ifdef HAVE_ICU
  streamIn_ICU_t             streamIn_ICU;
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
static streamInBool_t _streamIn_readb      (streamIn_t *streamInp);
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

#ifdef HAVE_ICONV
/***************************/
/* streamInUtf8_ICONV_newp */
/***************************/
static streamInBool_t *streamInUtf8_ICONV_newb(streamIn_t *streamInp) {
  streamInBool_t  rcb               = STREAMIN_BOOL_TRUE;
  streamIn_ICONV_t *streamIn_ICONVp = &(streamInp->streamIn_ICONV);

  streamIn_ICONVp->utf8BufMulSizei          = 2;
  streamIn_ICONVp->utf8Bufp                 = NULL;
  streamIn_ICONVp->utf8BufMarki             = 0;
  streamIn_ICONVp->utf8BufOffseti           = 0;
  streamIn_ICONVp->utf8BufLengthi           = 0;

  return rcb;
}
#endif

#ifdef HAVE_ICU
/*************************/
/* streamInUtf8_ICU_newb */
/*************************/
static streamInBool_t streamInUtf8_ICU_newb(streamIn_t *streamInp) {
  streamInBool_t  rcb           = STREAMIN_BOOL_TRUE;

  streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp = NULL;
  streamInp->streamIn_ICU.ucharBufMulSizei         = 2;
  streamInp->streamIn_ICU.ucharBufp                = NULL;
  streamInp->streamIn_ICU.ucharBufSizei            = 0;
  streamInp->streamIn_ICU.ucharByteLengthl         = 0;
  streamInp->streamIn_ICU.uConverter               = NULL;
  streamInp->streamIn_ICU.utextp                   = NULL;

  switch (streamInp->streamInUtf8Option.ICUFromCallback) {
  case STREAMINUTF8OPTION_ICUCALLBACK_SUBSTITUTE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SUBSTITUTE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_SKIP:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SKIP;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_STOP:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_STOP;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_ICU:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_ICU;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_JAVA:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_JAVA;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_C:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_C;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_HEX:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_DEC:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_UNICODE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_UNICODE;
    break;
  default:
    /* Cannot happen in theory */
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d", streamInp->streamInUtf8Option.ICUFromCallback);
    rcb = STREAMIN_BOOL_FALSE;
  }

  return rcb;
}
#endif

/*********************/
/* streamInUtf8_newp */
/*********************/
streamIn_t *streamInUtf8_newp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamIn_t    *streamInp = streamIn_newp(streamInOptionp);
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInp == NULL) {
    return NULL;
  }

  streamInp->utf8b                    = STREAMIN_BOOL_TRUE;

  streamInUtf8_optionDefaultb(&(streamInp->streamInUtf8Option));
  if (_streamInUtf8_optionb(streamInp, streamInUtf8Optionp) == STREAMIN_BOOL_FALSE) {
    streamIn_destroyv(&streamInp);
  } else {
    switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICONV
    case STREAMINUTF8OPTION_CONVERTER_ICONV:
      rcb = streamInUtf8_ICONV_newb(streamInp);
      break;
#endif
#ifdef HAVE_ICU
    case STREAMINUTF8OPTION_CONVERTER_ICU:
      rcb = streamInUtf8_ICU_newb(streamInp);
      break;
#endif
    }

    if (rcb == STREAMIN_BOOL_FALSE) {
      streamIn_destroyv(&streamInp);
      streamInp = NULL;   /* Formally this is not necessary */
    }
  }

  return streamInp;
}

#ifdef HAVE_ICU
/*********************************/
/* _streamInUtf8_ICU_doneBufferb */
/*********************************/
static streamInBool_t _streamInUtf8_ICU_doneBufferb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb           = STREAMIN_BOOL_TRUE;
  size_t          bytesToRemovei;
  size_t          ucharByteLengthl;
  UChar          *ucharBufp;
  char           *startp;
  UErrorCode      uErrorCode;
  int64_t         ucharLengthl; /* Number of UChar */
	

  if ((bufIndexi + 1) == streamInp->nCharBufi) {
    /* In fact we destroy everything */

    free(streamInp->streamIn_ICU.ucharBufp);
    streamInp->streamIn_ICU.ucharBufp = NULL;
    streamInp->streamIn_ICU.ucharBufSizei = 0;
    streamInp->streamIn_ICU.ucharByteLengthl = 0;

    free(streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp);
    streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp = NULL;

    /* ICU recommends to not close/open utext - so we delay that to the destroy method */
  } else {

    bytesToRemovei = streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp[bufIndexi];
    if (bytesToRemovei > 0) {
      ucharByteLengthl = streamInp->streamIn_ICU.ucharByteLengthl;
      if (bytesToRemovei < ucharByteLengthl) {
	startp = (char *) streamInp->streamIn_ICU.ucharBufp;
	memmove(startp, startp + bytesToRemovei, ucharByteLengthl - bytesToRemovei);
	ucharBufp = (UChar *) realloc(streamInp->streamIn_ICU.ucharBufp, ucharByteLengthl - bytesToRemovei);
	if (ucharBufp == NULL) {
	  STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s", strerror(errno));
	} else {
	  streamInp->streamIn_ICU.ucharBufp = ucharBufp;
	  streamInp->streamIn_ICU.ucharBufSizei -= bytesToRemovei;
	  streamInp->streamIn_ICU.ucharByteLengthl -= bytesToRemovei;
	  ucharLengthl = streamInp->streamIn_ICU.ucharByteLengthl / sizeof(UChar);
	  STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
	  streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
	  if (U_FAILURE(uErrorCode)) {
	    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "utext_openUChars(): %s", u_errorName(uErrorCode));
	    rcb = STREAMIN_BOOL_FALSE;
	  }
	}
      } else {
	/* It is possible that the utf8 stream was not filled up by the following byte buffer */
	free(streamInp->streamIn_ICU.ucharBufp);
	streamInp->streamIn_ICU.ucharBufp = NULL;
	streamInp->streamIn_ICU.ucharBufSizei = 0;
	streamInp->streamIn_ICU.ucharByteLengthl = 0;

	free(streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp);
	streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp = NULL;
      }
    }
  }


  return rcb;
}
#endif

/********************************************/
/* _streamInUtf8_doneBufferb                */
/********************************************/
static streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
    case STREAMINUTF8OPTION_CONVERTER_ICU:
      rcb = _streamInUtf8_ICU_doneBufferb(streamInp, bufIndexi);
      break;
#endif
#ifdef HAVE_ICONV
    case STREAMINUTF8OPTION_CONVERTER_ICONV:
      rcb = _streamInUtf8_ICONV_doneBufferb(streamInp, bufIndexi);
      break;
#endif
    }
  }

  return rcb;
}

/**************************************/
/* _streamInUtf8_readb                */
/**************************************/
static streamInBool_t _streamInUtf8_readb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {

    if (streamInp->streamInUtf8Option.encodings == NULL) {
      /* User did a streamInUtf8_newp. The very first time, we auto-detect encoding */
      _streamInUtf8_detectb(streamInp);
      if (strcmp(streamInp->streamInUtf8Option.encodings, _streamIn_defaultEncodings) == 0) {
        streamInp->nativeIsUtf8b = STREAMIN_BOOL_TRUE;
      } else {
        streamInp->nativeIsUtf8b = STREAMIN_BOOL_FALSE;
      }
    }

    switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
    case STREAMINUTF8OPTION_CONVERTER_ICU:
      rcb = _streamInUtf8_ICU_readb(streamInp, bufIndexi);
      break;
#endif
#ifdef HAVE_ICONV
    case STREAMINUTF8OPTION_CONVERTER_ICONV:
      rcb = _streamInUtf8_ICONV_readb(streamInp, bufIndexi);
      break;
#endif
    }

    if (rcb == STREAMIN_BOOL_TRUE) {
      rcb = _streamInUtf8_convertb(streamInp, bufIndexi);
    }
  }

  return rcb;
}

/********************************************/
/* _streamIn_doneBufferb                    */
/********************************************/
static streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi)
{
  size_t          i, j;
  char          **charBufpp;
  size_t         *realSizeCharBufip;
  streamInBool_t *managedbp;

  /* We want to forget forever buffer at index bufIndexi. */
  /* Any eventual previous buffer will me removed as well  */

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

  return _streamInUtf8_doneBufferb(streamInp, bufIndexi);
}

#ifdef HAVE_ICU
/********************************************/
/* _streamInUtf8_ICU_readb                  */
/********************************************/
  static streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi) {
  UChar          *ucharBufp;
  size_t         *charBuf2UCharBufOffsetpp;
  size_t          ucharBufSizei = streamInp->streamIn_ICU.ucharBufSizei;

  /* We are called at the end of _streamIn_readb(): the last buffer has already been read */

  if (bufIndexi == 0) {

    charBuf2UCharBufOffsetpp = (size_t *) malloc(sizeof(size_t));
    if (charBuf2UCharBufOffsetpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

    ucharBufSizei = sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
    ucharBufp = malloc(ucharBufSizei);
    if (ucharBufp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    charBuf2UCharBufOffsetpp = (size_t *) realloc(streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp, (bufIndexi + 1) * sizeof(size_t));
    if (charBuf2UCharBufOffsetpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    }

    if (ucharBufSizei > 0) {
      /* Cross finger for no overlap, i.e. the user application should know to release buffers regularly */
      ucharBufSizei += sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      ucharBufp = realloc(streamInp->streamIn_ICU.ucharBufp, ucharBufSizei);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      }
    } else {
      /* utf8 buffer can be NULL if we destroyed previous buffer(s) and there was not enough bytes */
      /* from it(them) to give at least one UChar */
      ucharBufSizei = sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      ucharBufp = malloc(ucharBufSizei);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
	return STREAMIN_BOOL_FALSE;
      }
    }

  }

  streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp = charBuf2UCharBufOffsetpp;
  streamInp->streamIn_ICU.ucharBufp = ucharBufp;
  streamInp->streamIn_ICU.ucharBufSizei = ucharBufSizei;

  return STREAMIN_BOOL_TRUE;
}
#endif

/********************************************/
/* _streamIn_readb                          */
/********************************************/
static streamInBool_t _streamIn_readb(streamIn_t *streamInp) {
  size_t          nCharBufi;
  size_t          bufIndexi;
  char          **charBufpp;
  size_t         *realSizeCharBufip;
  streamInBool_t *managedbp;
  char           *charManagedArrayp = NULL;

  if (streamInp->eofb == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  nCharBufi = streamInp->nCharBufi;

  STREAMIN_TRACEX("Allocating space for buffer No %d", (int) nCharBufi);

  /* Allocate space */
  if (nCharBufi == 0) {

    bufIndexi = nCharBufi++;

    streamInp->charBufpp = malloc(sizeof(char *));
    if (streamInp->charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
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

    bufIndexi = nCharBufi++;

    charBufpp = realloc(streamInp->charBufpp, nCharBufi * sizeof(char *));
    if (charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->charBufpp = charBufpp;
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


  return _streamInUtf8_readb(streamInp, bufIndexi);
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

  _streamInUtf8_destroyv(streamInp);

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
      if (_streamIn_readb(streamInp) == STREAMIN_BOOL_FALSE) {
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

  if (streamInp->nCharBufi > 0 && wantedIndexi < streamInp->nCharBufi) {
    return _streamIn_doneBufferb(streamInp, wantedIndexi);
  } else {
    return STREAMIN_BOOL_FALSE;
  }
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

/*************************/
/* _streamInUtf8_detectb */
/*************************/
static void _streamInUtf8_detectb(streamIn_t *streamInp) {
  if (
#ifdef HAVE_ICU
      _streamInUtf8_ICU_detectb(streamInp) == STREAMIN_BOOL_TRUE ||
#endif
      _streamIn_charsetdetect_detectb(streamInp) == STREAMIN_BOOL_TRUE
      ) {
    return;
  }

  STREAMIN_LOG0(STREAMIN_LOGLEVEL_INFO, "Charset detection failure, assuming UTF-8");
  streamInp->streamInUtf8Option.encodings = (char *) _streamIn_defaultEncodings;
}

#ifdef HAVE_ICU
/*****************************/
/* _streamInUtf8_ICU_detectb */
/*****************************/
static streamInBool_t _streamInUtf8_ICU_detectb(streamIn_t *streamInp) {
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
signed int streamInUtf8_nexti(streamIn_t *streamInp) {
  signed int     rci = -1;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rci;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rci = _streamInUtf8_ICU_nexti(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rci = _streamInUtf8_ICONV_nexti(streamInp);
    break;
#endif
  }

  if (rci == -1 && _streamIn_getBufferb(streamInp, streamInp->nCharBufi, NULL, NULL, NULL) == STREAMIN_BOOL_TRUE) {
    return streamInUtf8_nexti(streamInp);
  }

  return rci;
}

/**************************/
/* _streamInUtf8_convertb */
/**************************/
static streamInBool_t _streamInUtf8_convertb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
    case STREAMINUTF8OPTION_CONVERTER_ICU:
      rcb = _streamInUtf8_ICU_convertb(streamInp, bufIndexi);
      break;
#endif
#ifdef HAVE_ICONV
    case STREAMINUTF8OPTION_CONVERTER_ICONV:
      rcb = _streamInUtf8_ICONV_readb(streamInp, bufIndexi);
      break;
#endif
    }
  }

  return rcb;
}

#ifdef HAVE_ICU
/******************************/
/* _streamInUtf8_ICU_convertb */
/******************************/
static streamInBool_t _streamInUtf8_ICU_convertb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t rcb            = STREAMIN_BOOL_TRUE;
  size_t         ucharBufSizei  = streamInp->streamIn_ICU.ucharBufSizei;
  UChar         *target         = (UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.ucharByteLengthl);
  UChar         *origTarget     = target;
  const UChar   *targetLimit    = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + ucharBufSizei);
  const char    *source         = streamInp->charBufpp[bufIndexi];
  const char    *sourceLimit    = streamInp->charBufpp[bufIndexi] + streamInp->realSizeCharBufip[bufIndexi];
  UBool          flushb         = (streamInp->eofb == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;
  streamInBool_t stopb          = STREAMIN_BOOL_FALSE;
  UErrorCode     uErrorCode     = U_ZERO_ERROR;
  int64_t        ucharLengthl;  /* Number of UChar */
  UChar         *ucharBufp;

  /* For error reporting */
  char          errorBytes[32];
  int8_t        errorLength;
  int           i;

  /* Create "From" converter */
  if (streamInp->streamIn_ICU.uConverter == NULL) {
    streamInp->streamIn_ICU.uConverter = ucnv_open(streamInp->streamInUtf8Option.encodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_open(): %s", u_errorName(uErrorCode));
      return STREAMIN_BOOL_FALSE;
    }
    ucnv_setFromUCallBack(streamInp->streamIn_ICU.uConverter, streamInp->streamIn_ICU.uConverterFromUCallback, streamInp->streamIn_ICU.uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_setFromUCallBack(): %s", u_errorName(uErrorCode));
      return STREAMIN_BOOL_FALSE;
    }
  }

  do {

    uErrorCode = U_ZERO_ERROR;
    ucnv_toUnicode(streamInp->streamIn_ICU.uConverter, &target, targetLimit, &source, sourceLimit, NULL, flushb, &uErrorCode);

    if (uErrorCode == U_BUFFER_OVERFLOW_ERROR) {
      /* ucnv_toUnicode() is a statefull method.                                 */
      /* We remember for the next time that our heuristic was underestimated and */
      /* expand ourself the current target buffer                                */
      ucharBufSizei *= 2;
      ucharBufp = (UChar *) realloc(streamInp->streamIn_ICU.ucharBufp, ucharBufSizei);
      if (ucharBufp == NULL) {
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s", strerror(errno));
        rcb = STREAMIN_BOOL_FALSE;
	break;
      }

      /* Realloc can have moved the buffer */
      origTarget = target                   = (UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.ucharByteLengthl);
      targetLimit                           = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + ucharBufSizei);
      streamInp->streamIn_ICU.ucharBufSizei = ucharBufSizei;      

    } else if (U_FAILURE(uErrorCode)) {

      UErrorCode localError = U_ZERO_ERROR;
      errorLength = (int8_t)sizeof(errorBytes);
      ucnv_getInvalidChars(streamInp->streamIn_ICU.uConverter, errorBytes, &errorLength, &localError);
      if (U_FAILURE(localError) || errorLength == 0) {
        errorLength = 1;
      }

      for (i = 0; i < errorLength; i++) {
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "ucnv_toUnicode(): %s: %02x%02x", u_errorName(uErrorCode), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i] >> 4), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i]));
      }

      rcb = STREAMIN_BOOL_FALSE;
      break;

    } else {
      char  *max        = (char *) target;
      char  *min        = (char *) streamInp->streamIn_ICU.ucharBufp;
      UChar *ucharMin   = (UChar *) min;

      streamInp->streamIn_ICU.ucharByteLengthl = max - min;
      ucharLengthl = target - ucharMin;  /* C is taking (UChar *) as unit */

      streamInp->streamIn_ICU.charBuf2UCharBufOffsetpp[bufIndexi] = streamInp->streamIn_ICU.ucharByteLengthl;

      stopb = STREAMIN_BOOL_TRUE;
    }

  } while (stopb == STREAMIN_BOOL_FALSE);

  if (rcb == STREAMIN_BOOL_TRUE && target > origTarget) {

    /* Instanciate or reset utext */
    STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);

    streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "utext_openUChars(): %s", u_errorName(uErrorCode));
      rcb = STREAMIN_BOOL_FALSE;
    }
  }
  return rcb;
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
#ifdef HAVE_ICONV
  streamInUtf8Optionp->converteri      = STREAMINUTF8OPTION_CONVERTER_ICONV;
#endif
#ifdef HAVE_ICU
  streamInUtf8Optionp->converteri      = STREAMINUTF8OPTION_CONVERTER_ICU;
  streamInUtf8Optionp->ICUFromCallback = STREAMINUTF8OPTION_ICUCALLBACK_STOP;
#endif

  return STREAMIN_BOOL_TRUE;

}

#ifdef HAVE_ICU
/*****************************/
/* _streamInUtf8_ICU_optionb */
/*****************************/
static streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInUtf8Optionp != NULL) {
      switch (streamInUtf8Optionp->ICUFromCallback) {
      case STREAMINUTF8OPTION_ICUCALLBACK_SUBSTITUTE:
      case STREAMINUTF8OPTION_ICUCALLBACK_SKIP:
      case STREAMINUTF8OPTION_ICUCALLBACK_STOP:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_ICU:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_JAVA:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_C:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_HEX:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_DEC:
      case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_UNICODE:
	break;
      default:
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d", streamInUtf8Optionp->ICUFromCallback);
        rcb = STREAMIN_BOOL_FALSE;
      }
  }

  return rcb;
}
#endif

/*************************/
/* _streamInUtf8_optionb */
/*************************/
static streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInUtf8Optionp != NULL) {

    if (
#ifdef HAVE_ICU
        streamInUtf8Optionp->converteri != STREAMINUTF8OPTION_CONVERTER_ICU
#endif
#if (defined(HAVE_ICU) && defined(HAVE_ICONV))
        &&
#endif
#ifdef HAVE_ICONV
        streamInUtf8Optionp->converteri != STREAMINUTF8OPTION_CONVERTER_ICONV
#endif
        ) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid converter %d", streamInUtf8Optionp->converteri);
      rcb = STREAMIN_BOOL_FALSE;
    }

    if (rcb == STREAMIN_BOOL_TRUE) {
      switch (streamInUtf8Optionp->converteri) {
#ifdef HAVE_ICU
      case STREAMINUTF8OPTION_CONVERTER_ICU:
        rcb = _streamInUtf8_ICU_optionb(streamInp, streamInUtf8Optionp);
        break;
#endif
#ifdef HAVE_ICONV
        rcb = _streamInUtf8_ICONV_optionb(streamInp, streamInUtf8Optionp);
        break;
#endif
      }
    }

    if (rcb == STREAMIN_BOOL_TRUE) {
      streamInp->streamInUtf8Option = *streamInUtf8Optionp;
    }
  }

  return rcb;
}

/**************************/
/* _streamInUtf8_destroyv */
/**************************/
static void _streamInUtf8_destroyv(streamIn_t *streamInp) {
  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    if (streamInp->streamInUtf8Option.encodings != NULL) {
      if (streamInp->streamInUtf8Option.encodings != _streamIn_defaultEncodings) {
        free(streamInp->streamInUtf8Option.encodings);
      }
    }
#ifdef HAVE_ICU
    if (streamInp->streamIn_ICU.uConverter != NULL) {
      ucnv_close(streamInp->streamIn_ICU.uConverter);
    }
#ifdef STREAMIN_SINGLE_TEST_APPLICATION_ONLY
    /* ICU recommendation is to NOT call this. This is done automatically at library unload */
    u_cleanup();
#endif
#endif
  }
}

/*********************************/
/* _streaminUtf8_ICU_nibbleToHex */
/*********************************/
static unsigned char _streaminUtf8_ICU_nibbleToHex(uint8_t n) {
  n &= 0xf;
  return
    n <= 9 ?
    (unsigned char)(0x30 + n) :
    (unsigned char)((0x61 - 10) + n);
}

/************************/
/* streamInUtf8_current */
/************************/
signed int streamInUtf8_currenti(streamIn_t *streamInp) {
  signed int rci = -1;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rci;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rci = _streamInUtf8_ICU_currenti(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rci = _streamInUtf8_ICONV_currenti(streamInp);
    break;
#endif
  }

  if (rci == -1 && _streamIn_getBufferb(streamInp, streamInp->nCharBufi, NULL, NULL, NULL) == STREAMIN_BOOL_TRUE) {
    return streamInUtf8_currenti(streamInp);
  }

  return rci;
}

#ifdef HAVE_ICU
/******************************/
/* _streamInUtf8_ICU_currenti */
/******************************/
static signed int _streamInUtf8_ICU_currenti(streamIn_t *streamInp) {
  signed int rci = -1;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rci;
  } else {
    return UTEXT_CURRENT32(streamInp->streamIn_ICU.utextp);
  }
}
#endif

#ifdef HAVE_ICU
/***************************/
/* _streamInUtf8_ICU_nexti */
/***************************/
static signed int _streamInUtf8_ICU_nexti(streamIn_t *streamInp) {
  signed int rci = -1;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rci;
  } else {
    return UTEXT_NEXT32(streamInp->streamIn_ICU.utextp);
  }
}
#endif
