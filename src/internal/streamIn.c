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

const static char *_streamIn_defaultFromEncodings = "UTF-8";

static C_INLINE streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE void           _streamInUtf8_detectb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_fromConvertb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE void           _streamInUtf8_destroyv(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_readb(streamIn_t *streamInp, size_t bufIndexi);

#ifdef HAVE_ICONV
typedef struct streamIn_ICONV {
  /* With iconv we do a single conversion Native => UTF-8 */
  size_t                     utf8BufMulSizei;          /* A heuristic guess of the utf8 takes maximum twice more space than native bytes */
  char                      *utf8Bufp;                 /* utf8 buffer */
  size_t                     utf8BufMarki;             /* Buffer index hosting current character */
  size_t                     utf8BufOffseti;           /* Offset of current character within buffer No utf8BufMarki */
  size_t                     utf8BufLengthi;           /* Number of valid bytes in utf8 buffer */
} streamIn_ICONV_t;
static C_INLINE streamInBool_t *streamInUtf8_ICONV_newb(streamIn_t *streamInp);
#endif
#ifdef HAVE_ICU
typedef struct streamIn_ICU {
  /* With ICU we do a single conversion Native => UChar                */
  /* into a SINGLE buffer. We maintain a mapping charBufpp[] -> offset */
  int64_t                    *charBuf2UCharByteLengthlp;/* mapping end of char buffers => offset in ucharBufp */
  int64_t                     ucharMarkedOffsetl;       /* Pointer location just after the marked uchar */
  size_t                      ucharBufMulSizei;         /* A heuristic guess of the utf16 takes maximum twice more space than native bytes */
  UChar                      *ucharBufp;                /* UChar buffer */
  int64_t                     ucharBufSizel;            /* Current size of allocated memory */
  int64_t                     ucharByteLengthl;         /* Length in bytes of all UChar characters */
  UConverter                 *uConverterFrom;           /* Native converter => UTF-16 (ICU's unicode) */
  UConverterFromUCallback     uConverterFromUCallback;
  const void                 *uConverterFromUCallbackCtxp;
  UConverterToUCallback       uConverterToUCallback;
  const void                 *uConverterToUCallbackCtxp;
  UText                      *utextp;
} streamIn_ICU_t;
static C_INLINE streamInBool_t  streamInUtf8_ICU_newb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_detectb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_fromConvertb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE unsigned char  _streaminUtf8_ICU_nibbleToHex(uint8_t n);
static C_INLINE signed int     _streamInUtf8_ICU_currenti(streamIn_t *streamInp);
static C_INLINE signed int     _streamInUtf8_ICU_nexti(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_markb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_markPreviousb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromMarkedb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneb(streamIn_t *streamInp);
#endif
static C_INLINE streamInBool_t _streamIn_charsetdetect_detectb(streamIn_t *streamInp);

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
  streamInBool_t             fromEncodingsManagedb;    /* STREAMIN_BOOL_TRUE only if streamInUtf8_newp() is called */
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

#define STREAMIN_FREE(x) { free(x); x = NULL; }
#define STREAMIN_FREE_REPLACEMENT(x, replacement) { free(x); x = replacement; }

static C_INLINE streamInBool_t _streamIn_getBufferb (streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);
static C_INLINE streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamIn_readb      (streamIn_t *streamInp);
static C_INLINE void           _streamIn_log_any    (streamIn_t *streamInp, streamInLogLevel_t streamInLogLeveli, const char *fmts, ...);
static C_INLINE void           _streamIn_logCallback(void *logCallbackDatavp, streamIn_t *marpaWrapperp, streamInLogLevel_t logLeveli, const char *msgs);
static C_INLINE streamInBool_t _streamIn_optionb    (streamIn_t *streamInp, streamInOption_t *streamInOptionp);
static C_INLINE streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp);

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
      errorMsgs = messageBuilder("malloc(): %s at %s:%d", errno, __FILE__, __LINE__);
      (*streamInOptionp->logCallbackp)(streamInOptionp->logCallbackUserDatap, NULL, STREAMIN_LOGLEVEL_ERROR, errorMsgs);
    }
    if (errorMsgs != messageBuilder_internalErrors()) {
      STREAMIN_FREE(errorMsgs);
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
static C_INLINE streamInBool_t *streamInUtf8_ICONV_newb(streamIn_t *streamInp) {
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
static C_INLINE streamInBool_t streamInUtf8_ICU_newb(streamIn_t *streamInp) {
  streamInBool_t  rcb           = STREAMIN_BOOL_TRUE;

  streamInp->streamIn_ICU.charBuf2UCharByteLengthlp = NULL;
  streamInp->streamIn_ICU.ucharMarkedOffsetl       = 0;
  streamInp->streamIn_ICU.ucharBufMulSizei         = 2;
  streamInp->streamIn_ICU.ucharBufp                = NULL;
  streamInp->streamIn_ICU.ucharBufSizel            = 0;
  streamInp->streamIn_ICU.ucharByteLengthl         = 0;
  streamInp->streamIn_ICU.uConverterFrom           = NULL;
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
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d at %s:%d", streamInp->streamInUtf8Option.ICUFromCallback, __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
  }

  switch (streamInp->streamInUtf8Option.ICUToCallback) {
  case STREAMINUTF8OPTION_ICUCALLBACK_SUBSTITUTE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_SUBSTITUTE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_SKIP:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_SKIP;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_STOP:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_STOP;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_ICU:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_ICU;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_JAVA:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_JAVA;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_C:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_C;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_HEX:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_DEC:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
    break;
  case STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_UNICODE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_UNICODE;
    break;
  default:
    /* Cannot happen in theory */
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUToCallback %d at %s:%d", streamInp->streamInUtf8Option.ICUToCallback, __FILE__, __LINE__);
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

  streamInp->utf8b = STREAMIN_BOOL_TRUE;

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
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneBufferb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb           = STREAMIN_BOOL_TRUE;
  int64_t         bytesToRemovel;
  int64_t         ucharsToRemovel;
  int64_t         ucharByteLengthl;
  UChar          *ucharBufp;
  char           *startp;
  UErrorCode      uErrorCode = U_ZERO_ERROR;
  int64_t         ucharLengthl; /* Number of UChar */
  size_t          sizel;
  size_t          i, j;
  int64_t        *charBuf2UCharByteLengthlp;
  int64_t         nativeIndexl;

  if ((bufIndexi + 1) == streamInp->nCharBufi) {
    /* In fact we destroy everything */

    STREAMIN_FREE(streamInp->streamIn_ICU.charBuf2UCharByteLengthlp);
    streamInp->streamIn_ICU.ucharMarkedOffsetl = 0;
    STREAMIN_FREE(streamInp->streamIn_ICU.ucharBufp);
    streamInp->streamIn_ICU.ucharBufSizel = 0;
    streamInp->streamIn_ICU.ucharByteLengthl = 0;

    /* ICU recommends to not close/open utext - so we delay that to the destroy method */
  } else {

    bytesToRemovel = streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[bufIndexi];
    if (bytesToRemovel > 0) {
      ucharByteLengthl = streamInp->streamIn_ICU.ucharByteLengthl;
      if (bytesToRemovel < ucharByteLengthl) {
        /* Something remain in the UChar buffer */
        ucharsToRemovel = bytesToRemovel / sizeof(UChar);
        /* Byte buffer No bufIndexi maps to at least one UChar */
        nativeIndexl = UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp);
        startp = (char *) streamInp->streamIn_ICU.ucharBufp;
        /* Cross the fingers this fits in a size_t */
        sizel = (size_t) (ucharByteLengthl - bytesToRemovel);
        memmove(startp, startp + bytesToRemovel, sizel);
        ucharBufp = realloc(streamInp->streamIn_ICU.ucharBufp, sizel);
        if (ucharBufp == NULL) {
          STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        } else {
          streamInp->streamIn_ICU.ucharBufp = ucharBufp;
          streamInp->streamIn_ICU.ucharBufSizel -= bytesToRemovel;
          streamInp->streamIn_ICU.ucharByteLengthl -= bytesToRemovel;
          ucharLengthl = streamInp->streamIn_ICU.ucharByteLengthl / sizeof(UChar);
          STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);
          streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
          if (U_FAILURE(uErrorCode)) {
            STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
            rcb = STREAMIN_BOOL_FALSE;
          } else {
            nativeIndexl -= ucharsToRemovel;
            UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, nativeIndexl);
          }
        }
        for (j = 0, i = (bufIndexi + 1); i < streamInp->nCharBufi; ++i, ++j) {
          streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[j] = streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[i] - bytesToRemovel;
        }
        /* We have to realloc, taking care of moving backward */
        /* the informations                                   */
        /* Formally, on realloc error, we can continue */
        charBuf2UCharByteLengthlp = realloc(streamInp->streamIn_ICU.charBuf2UCharByteLengthlp, streamInp->nCharBufi * sizeof(int64_t));
        if (charBuf2UCharByteLengthlp == NULL) {
          STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        } else {
          streamInp->streamIn_ICU.charBuf2UCharByteLengthlp = charBuf2UCharByteLengthlp;
        }
      } else {
        /* The full UChar buffer is over */
        STREAMIN_FREE(streamInp->streamIn_ICU.ucharBufp);
        streamInp->streamIn_ICU.ucharBufSizel = 0;
        streamInp->streamIn_ICU.ucharByteLengthl = 0;
        for (j = 0, i = (bufIndexi + 1); i < streamInp->nCharBufi; ++i, ++j) {
          streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[j] = streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[i];
        }
      }
    }
  }


  return rcb;
}
#endif

/********************************************/
/* _streamInUtf8_doneBufferb                */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

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
static C_INLINE streamInBool_t _streamInUtf8_readb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {

    if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
      /* User did a streamInUtf8_newp. The very first time, we auto-detect encoding */
      _streamInUtf8_detectb(streamInp);
      if (strcmp(streamInp->streamInUtf8Option.fromEncodings, _streamIn_defaultFromEncodings) == 0) {
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
      rcb = _streamInUtf8_fromConvertb(streamInp, bufIndexi);
    }
  }

  return rcb;
}

/********************************************/
/* _streamIn_doneBufferb                    */
/********************************************/

/* Take care: this routine will destroy buffers, and the call to utf8 stuff */
/* will rely on streamInp->nCharBufi without modify it */
static C_INLINE streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi)
{
  size_t          i, j;
  char          **charBufpp;
  size_t         *realSizeCharBufip;
  streamInBool_t *managedbp;
  size_t          nCharBufi = streamInp->nCharBufi;
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

  /* We want to forget forever buffer at index bufIndexi. */
  /* Any eventual previous buffer will me removed as well  */

  STREAMIN_TRACEX("Destroying buffers [%d..%d]", 0, bufIndexi);

  /* We destroy the buffers */
  for (i = 0; i <= bufIndexi; ++i) {
    if (streamInp->managedbp[i] == STREAMIN_BOOL_FALSE) {
      STREAMIN_FREE(streamInp->charBufpp[i]);
    } else if (streamInp->streamInOption.bufFreeCallbackp != NULL) {
      (*streamInp->streamInOption.bufFreeCallbackp)(streamInp->streamInOption.bufFreeCallbackUserDatap, streamInp->charBufpp[i]);
      streamInp->charBufpp[i] = NULL;
    }
  }

  if ((bufIndexi + 1) == nCharBufi) {
    /* And in fact we destroyed everything */
    STREAMIN_FREE(streamInp->charBufpp);
    STREAMIN_FREE(streamInp->realSizeCharBufip);
    STREAMIN_FREE(streamInp->managedbp);
    nCharBufi = 0;
  }
  else {

    STREAMIN_TRACEX("Moving information of buffers [%d..%d] to [0..%d]", bufIndexi + 1, nCharBufi - 1, nCharBufi - (bufIndexi + 1) - 1);

    /* We have to realloc, taking care of moving backward */
    /* the informations                                   */
    for (j = 0, i = (bufIndexi + 1); i < nCharBufi; ++i, ++j) {
      streamInp->charBufpp[j] = streamInp->charBufpp[i];
      streamInp->realSizeCharBufip[j] = streamInp->realSizeCharBufip[i];
      streamInp->managedbp[j] = streamInp->managedbp[i];
    }

    nCharBufi -= (bufIndexi+1);

    /* Formally, on realloc error, we can continue */
    charBufpp = realloc(streamInp->charBufpp, nCharBufi * sizeof(char *));
    if (charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->charBufpp = charBufpp;
    }

    realSizeCharBufip = realloc(streamInp->realSizeCharBufip, nCharBufi * sizeof(void *));
    if (realSizeCharBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->realSizeCharBufip = realSizeCharBufip;
    }

    managedbp = realloc(streamInp->managedbp, nCharBufi * sizeof(streamInBool_t));
    if (managedbp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->managedbp = managedbp;
    }
  }

  /* Regardless it if failed or not, we have crunched buffers -; */
  rcb = _streamInUtf8_doneBufferb(streamInp, bufIndexi);

  streamInp->nCharBufi = nCharBufi;

  return rcb;
}

#ifdef HAVE_ICU
/********************************************/
/* _streamInUtf8_ICU_readb                  */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi) {
  UChar          *ucharBufp;
  int64_t        *charBuf2UCharByteLengthlp;
  int64_t         ucharBufSizel = streamInp->streamIn_ICU.ucharBufSizel;

  /* We are called at the end of _streamIn_readb(): the last buffer has already been read */

  if (bufIndexi == 0) {

    charBuf2UCharByteLengthlp = malloc(sizeof(int64_t));
    if (charBuf2UCharByteLengthlp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    ucharBufSizel = sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
    /* Cross the fingers this fits in a size_t */
    ucharBufp = malloc((size_t) ucharBufSizel);
    if (ucharBufp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      free(charBuf2UCharByteLengthlp);
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    charBuf2UCharByteLengthlp = realloc(streamInp->streamIn_ICU.charBuf2UCharByteLengthlp, (bufIndexi + 1) * sizeof(int64_t));
    if (charBuf2UCharByteLengthlp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    if (ucharBufSizel > 0) {
      /* Cross fingers for no overlap, i.e. the user application should know to release buffers regularly */
      ucharBufSizel += sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      /* Cross fingers this fits in a size_t - thread _streamInUtf8_ICU_fromConvertb() method will take care of reallocating if it is too short */
      ucharBufp = realloc(streamInp->streamIn_ICU.ucharBufp, (size_t) ucharBufSizel);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
    } else {
      /* utf8 buffer can be NULL if we destroyed previous buffer(s) and there was not enough bytes */
      /* from it(them) to give at least one UChar */
      ucharBufSizel = sizeof(UChar) * streamInp->realSizeCharBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      /* Cross fingers this fits in a size_t */
      ucharBufp = malloc((size_t) ucharBufSizel);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
    }

  }

  streamInp->streamIn_ICU.charBuf2UCharByteLengthlp = charBuf2UCharByteLengthlp;
  streamInp->streamIn_ICU.ucharBufp = ucharBufp;
  streamInp->streamIn_ICU.ucharBufSizel = ucharBufSizel;

  return STREAMIN_BOOL_TRUE;
}
#endif

/********************************************/
/* _streamIn_readb                          */
/********************************************/
static C_INLINE streamInBool_t _streamIn_readb(streamIn_t *streamInp) {
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
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    streamInp->realSizeCharBufip = malloc(sizeof(size_t));
    if (streamInp->realSizeCharBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    streamInp->managedbp = malloc(sizeof(streamInBool_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    bufIndexi = nCharBufi++;

    charBufpp = realloc(streamInp->charBufpp, nCharBufi * sizeof(char *));
    if (charBufpp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->charBufpp = charBufpp;
    }

    realSizeCharBufip = realloc(streamInp->realSizeCharBufip, nCharBufi * sizeof(size_t));
    if (streamInp->realSizeCharBufip == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->realSizeCharBufip = realSizeCharBufip;
    }

    managedbp = realloc(streamInp->managedbp, nCharBufi * sizeof(size_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->managedbp = managedbp;
    }

  }

  streamInp->charBufpp[bufIndexi]  = malloc(streamInp->streamInOption.bufMaxSizei);
  if (streamInp->charBufpp[bufIndexi] == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
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
    STREAMIN_FREE_REPLACEMENT(streamInp->charBufpp[bufIndexi], charManagedArrayp);
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
      /* If we are working on the first buffer, we can safely call _streamIn_doneBufferb()     */
      /* otherwise there is a leftover of pointers, we only free what has been allocated inside */
      /* No need to redo a realloc. Next eventuall call will simply realloc on the same size.   */
      _streamIn_doneBufferb(streamInp, bufIndexi);
    } else {
      /* Formally, no need to assign NULL since we will reduce */
      STREAMIN_FREE(streamInp->charBufpp[bufIndexi]);
      streamInp->nCharBufi--;     
      charBufpp = realloc(streamInp->charBufpp, streamInp->nCharBufi * sizeof(char *));
      /* We are reducing the array, so formally even in case of error we can continue */
      if (charBufpp == NULL) {
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      } else {
        streamInp->charBufpp = charBufpp;
      }
    }
    return STREAMIN_BOOL_FALSE;
  }


  return _streamInUtf8_readb(streamInp, bufIndexi);
}

/*********************/
/* _streamIn_log_any */
/*********************/
static C_INLINE void _streamIn_log_any(streamIn_t *streamInp, streamInLogLevel_t streamInLogLeveli, const char *fmts, ...) {
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
      /* No need to assign to NULL, we will return just after */
      free(msgs);
    }
  }
}

/*************************/
/* _streamIn_logCallback */
/*************************/
static C_INLINE void _streamIn_logCallback(void *logCallbackDatavp, streamIn_t *streaminp, streamInLogLevel_t logLeveli, const char *msgs) {
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

  /* No need to assign to NULL, we know what we are doing here */
  free(streamInp);
  *streamInpp = NULL;
}

/************************/
/* _streamIn_getBufferb */
/************************/
static C_INLINE streamInBool_t _streamIn_getBufferb(streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp) {
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
static C_INLINE streamInBool_t _streamIn_optionb(streamIn_t *streamInp, streamInOption_t *streamInOptionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInOptionp != NULL) {
    if (streamInOptionp->bufMaxSizei <= 0) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid bufMaxSizei at %s:%d", __FILE__, __LINE__);
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
static C_INLINE void _streamInUtf8_detectb(streamIn_t *streamInp) {
  if (
#ifdef HAVE_ICU
      _streamInUtf8_ICU_detectb(streamInp) == STREAMIN_BOOL_TRUE ||
#endif
      _streamIn_charsetdetect_detectb(streamInp) == STREAMIN_BOOL_TRUE
      ) {
    return;
  }

  STREAMIN_LOG0(STREAMIN_LOGLEVEL_INFO, "Charset detection failure, assuming UTF-8");
  streamInp->streamInUtf8Option.fromEncodings = (char *) _streamIn_defaultFromEncodings;
}

#ifdef HAVE_ICU
/*****************************/
/* _streamInUtf8_ICU_detectb */
/*****************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_detectb(streamIn_t *streamInp) {
  UErrorCode           uErrorCode = U_ZERO_ERROR;
  UCharsetDetector    *uCharsetDetector;
  const UCharsetMatch *uCharsetMatch;
  const char          *fromEncodings;
  int32_t              confidence; 
  streamInBool_t       rcb = STREAMIN_BOOL_TRUE;

  STREAMIN_TRACE0("Determining encoding using ICU");

  STREAMIN_TRACEX("ucsdet_open(%p)", &uErrorCode);
  uCharsetDetector = ucsdet_open(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_setText(%p, %p, %ld, %p)", uCharsetDetector, streamInp->charBufpp[0], (unsigned long) streamInp->realSizeCharBufip[0], &uErrorCode);
  ucsdet_setText(uCharsetDetector, streamInp->charBufpp[0], streamInp->realSizeCharBufip[0], &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_setText(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_detect(%p, %p)", uCharsetDetector, &uErrorCode);
  uCharsetMatch = ucsdet_detect(uCharsetDetector, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (uCharsetMatch == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getName(%p, %p)", uCharsetMatch, &uErrorCode);
  fromEncodings = ucsdet_getName(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (fromEncodings == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (strlen(fromEncodings) <= 0) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned empty string at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getConfidence(%p, %p)", uCharsetMatch, &uErrorCode);
  confidence = ucsdet_getConfidence(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getConfidence(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  if (confidence < 10) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ucsdet_getConfidence() returned encoding \"%s\" with too low confidence %d < 10 - rejected", fromEncodings, confidence);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ICU returned encoding \"%s\" with confidence %d", fromEncodings, confidence);

 ICU_end:

  if (rcb == STREAMIN_BOOL_TRUE) {
    /* Save the result */
    streamInp->streamInUtf8Option.fromEncodings = malloc(sizeof(char) * (strlen(fromEncodings) + 1));
    if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      rcb = STREAMIN_BOOL_FALSE;
    } else {
      strcpy(streamInp->streamInUtf8Option.fromEncodings, fromEncodings);
    }
  }

  if (uCharsetDetector != NULL) {
    STREAMIN_TRACEX("ucsdet_close(%p)", uCharsetDetector);
    ucsdet_close(uCharsetDetector);
  }

  return rcb;
}
#endif

/***********************************/
/* _streamIn_charsetdetect_detectb */
/***********************************/
static C_INLINE streamInBool_t _streamIn_charsetdetect_detectb(streamIn_t *streamInp) {
  csd_t       csdp;
  int         result;
  const char *fromEncodings;
  float       confidencef;

  csdp = csd_open();
  if (csdp == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "csd_open(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return STREAMIN_BOOL_FALSE;
  } else {
    result = csd_consider(csdp, streamInp->charBufpp[0], streamInp->realSizeCharBufip[0]);
    /* We are not going to ask for more data: a reasonable application will at least */
    /* use the default cache of 1M, that must be large enough in any case            */
    if (result < 0) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "csd_consider() failure at %s:%d", __FILE__, __LINE__);
      csd_close(csdp);
      return STREAMIN_BOOL_FALSE;
    } else {
      fromEncodings = csd_close2(csdp, &confidencef);
      if (fromEncodings == NULL) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "csd_close() returned NULL at %s:%d", __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      } else {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "libcharsetdetect returned encoding \"%s\" with confidence %f", fromEncodings, (double) confidencef);
	/* Save the result */
	streamInp->streamInUtf8Option.fromEncodings = malloc(sizeof(char) * (strlen(fromEncodings) + 1));
	if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
	  STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	  return STREAMIN_BOOL_FALSE;
	} else {
	  strcpy(streamInp->streamInUtf8Option.fromEncodings, fromEncodings);
	}
      }
    }
  }

  return STREAMIN_BOOL_TRUE;
}

/******************************/
/* streamInUtf8_fromEncodings */
/******************************/
streamInBool_t streamInUtf8_fromEncodings(streamIn_t *streamInp, char **fromEncodingsp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  if (fromEncodingsp != NULL) {
    *fromEncodingsp = streamInp->streamInUtf8Option.fromEncodings;
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

/******************************/
/* _streamInUtf8_fromConvertb */
/******************************/
static C_INLINE streamInBool_t _streamInUtf8_fromConvertb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
    case STREAMINUTF8OPTION_CONVERTER_ICU:
      rcb = _streamInUtf8_ICU_fromConvertb(streamInp, bufIndexi);
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
/**********************************/
/* _streamInUtf8_ICU_fromConvertb */
/**********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_fromConvertb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t rcb            = STREAMIN_BOOL_TRUE;
  int64_t        ucharBufSizel  = streamInp->streamIn_ICU.ucharBufSizel;
  UChar         *target         = (UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.ucharByteLengthl);
  UChar         *origTarget     = target;
  const UChar   *targetLimit    = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + ucharBufSizel);
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
  if (streamInp->streamIn_ICU.uConverterFrom == NULL) {
    UBool fallback = (streamInp->streamInUtf8Option.ICUFromFallback == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;

    STREAMIN_TRACEX("ucnv_open(\"%s\", %p)", streamInp->streamInUtf8Option.fromEncodings, &uErrorCode);
    streamInp->streamIn_ICU.uConverterFrom = ucnv_open(streamInp->streamInUtf8Option.fromEncodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    STREAMIN_TRACEX("ucnv_setFromUCallBack(%p, %p, %p, %p, %p, %p)", streamInp->streamIn_ICU.uConverterFrom, streamInp->streamIn_ICU.uConverterFromUCallback, streamInp->streamIn_ICU.uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
    ucnv_setFromUCallBack(streamInp->streamIn_ICU.uConverterFrom, streamInp->streamIn_ICU.uConverterFromUCallback, streamInp->streamIn_ICU.uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucnv_setFromUCallBack(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    STREAMIN_TRACEX("ucnv_setFallback(%p, %d)", streamInp->streamIn_ICU.uConverterFrom, fallback);
    ucnv_setFallback(streamInp->streamIn_ICU.uConverterFrom, fallback);
  }

  do {

    uErrorCode = U_ZERO_ERROR;
    STREAMIN_TRACEX("ucnv_toUnicode(%p, %p, %p, %p, %p, %p, %d, %p)", streamInp->streamIn_ICU.uConverterFrom, &target, targetLimit, &source, sourceLimit, NULL, flushb, &uErrorCode);
    ucnv_toUnicode(streamInp->streamIn_ICU.uConverterFrom, &target, targetLimit, &source, sourceLimit, NULL, flushb, &uErrorCode);

    if (uErrorCode == U_BUFFER_OVERFLOW_ERROR) {
      /* ucnv_toUnicode() is a statefull method.                                 */
      /* We remember for the next time that our heuristic was underestimated and */
      /* expand ourself the current target buffer                                */
      ucharBufSizel *= 2;
      /* Cross fingers this fits in a size_t */
      ucharBufp = realloc(streamInp->streamIn_ICU.ucharBufp, (size_t) ucharBufSizel);
      if (ucharBufp == NULL) {
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
	break;
      }

      streamInp->streamIn_ICU.ucharBufp = ucharBufp;
      /* Realloc can have moved the buffer */
      origTarget = target                   = (UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.ucharByteLengthl);
      targetLimit                           = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + ucharBufSizel);
      streamInp->streamIn_ICU.ucharBufSizel = ucharBufSizel;      

    } else if (U_FAILURE(uErrorCode)) {

      UErrorCode localError = U_ZERO_ERROR;
      errorLength = (int8_t)sizeof(errorBytes);
      STREAMIN_TRACEX("ucnv_getInvalidChars(%p, %p, %p, %p)", streamInp->streamIn_ICU.uConverterFrom, errorBytes, &errorLength, &localError);
      ucnv_getInvalidChars(streamInp->streamIn_ICU.uConverterFrom, errorBytes, &errorLength, &localError);
      if (U_FAILURE(localError) || errorLength == 0) {
        errorLength = 1;
      }

      for (i = 0; i < errorLength; i++) {
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ucnv_toUnicode(): %s: %02x%02x", u_errorName(uErrorCode), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i] >> 4), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i]));
      }

      rcb = STREAMIN_BOOL_FALSE;
      break;

    } else {
      char  *max        = (char *) target;
      char  *min        = (char *) streamInp->streamIn_ICU.ucharBufp;
      UChar *ucharMin   = (UChar *) min;

      streamInp->streamIn_ICU.ucharByteLengthl = max - min;
      ucharLengthl = target - ucharMin;  /* C is taking (UChar *) as unit */

      /* Cross the fingers this fits in a size_t */
      streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[bufIndexi] = streamInp->streamIn_ICU.ucharByteLengthl;
      STREAMIN_TRACEX("streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[%d] = %ld", bufIndexi, (unsigned long) streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[bufIndexi]);

      stopb = STREAMIN_BOOL_TRUE;
    }

  } while (stopb == STREAMIN_BOOL_FALSE);

  if (rcb == STREAMIN_BOOL_TRUE && target > origTarget) {
    if (streamInp->streamIn_ICU.utextp != NULL) {
      int64_t nativeIndexl = UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp);
      /* Reset utext */
      STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);
      streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
      if (U_FAILURE(uErrorCode)) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	rcb = STREAMIN_BOOL_FALSE;
      } else {
	UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, nativeIndexl);
      }
    } else {
      /* Instanciate utext */
      STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);
      streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
      if (U_FAILURE(uErrorCode)) {
	STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	rcb = STREAMIN_BOOL_FALSE;
      }
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

  streamInUtf8Optionp->fromEncodings   = NULL;
#ifdef HAVE_ICONV
  streamInUtf8Optionp->converteri      = STREAMINUTF8OPTION_CONVERTER_ICONV;
#endif
#ifdef HAVE_ICU
  streamInUtf8Optionp->converteri      = STREAMINUTF8OPTION_CONVERTER_ICU;
  streamInUtf8Optionp->ICUFromCallback = STREAMINUTF8OPTION_ICUCALLBACK_STOP;
  streamInUtf8Optionp->ICUFromFallback = STREAMIN_BOOL_FALSE;
  streamInUtf8Optionp->ICUToCallback   = STREAMINUTF8OPTION_ICUCALLBACK_STOP;
  streamInUtf8Optionp->ICUToFallback   = STREAMIN_BOOL_FALSE;
#endif

  return STREAMIN_BOOL_TRUE;

}

#ifdef HAVE_ICU
/*****************************/
/* _streamInUtf8_ICU_optionb */
/*****************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
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
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d at %s:%d", streamInUtf8Optionp->ICUFromCallback, __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
      }

      switch (streamInUtf8Optionp->ICUToCallback) {
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
        STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid ICUToCallback %d at %s:%d", streamInUtf8Optionp->ICUToCallback, __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
      }
  }

  return rcb;
}
#endif

/*************************/
/* _streamInUtf8_optionb */
/*************************/
static C_INLINE streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  streamInp->fromEncodingsManagedb = STREAMIN_BOOL_FALSE;

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
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "Invalid converter %d at %s:%d", streamInUtf8Optionp->converteri, __FILE__, __LINE__);
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

    if (streamInUtf8Optionp->fromEncodings != NULL) {
        streamInp->fromEncodingsManagedb = STREAMIN_BOOL_TRUE;
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
static C_INLINE void _streamInUtf8_destroyv(streamIn_t *streamInp) {
  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    if (streamInp->streamInUtf8Option.fromEncodings != NULL && streamInp->fromEncodingsManagedb == STREAMIN_BOOL_FALSE) {
      /* The fromEncodings is not managed by the caller */
      if (streamInp->streamInUtf8Option.fromEncodings != _streamIn_defaultFromEncodings) {
        STREAMIN_FREE(streamInp->streamInUtf8Option.fromEncodings);
      }
    }
#ifdef HAVE_ICU
    if (streamInp->streamIn_ICU.charBuf2UCharByteLengthlp != NULL) {
      free(streamInp->streamIn_ICU.charBuf2UCharByteLengthlp);
    }
    if (streamInp->streamIn_ICU.ucharBufp != NULL) {
      free(streamInp->streamIn_ICU.ucharBufp);
    }
    if (streamInp->streamIn_ICU.utextp != NULL) {
      STREAMIN_TRACEX("utext_close(%p)", streamInp->streamIn_ICU.utextp);
      utext_close(streamInp->streamIn_ICU.utextp);
    }
    if (streamInp->streamIn_ICU.uConverterFrom != NULL) {
      STREAMIN_TRACEX("ucnv_close(%p)", streamInp->streamIn_ICU.uConverterFrom);
      ucnv_close(streamInp->streamIn_ICU.uConverterFrom);
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
static C_INLINE unsigned char _streaminUtf8_ICU_nibbleToHex(uint8_t n) {
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
static C_INLINE signed int _streamInUtf8_ICU_currenti(streamIn_t *streamInp) {
  signed int rci = -1;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rci;
  } else {
    /* A trace here would hog the output */
    /* STREAMIN_TRACEX("UTEXT_CURRENT32(%p)", streamInp->streamIn_ICU.utextp); */
    return UTEXT_CURRENT32(streamInp->streamIn_ICU.utextp);
  }
}
#endif

#ifdef HAVE_ICU
/***************************/
/* _streamInUtf8_ICU_nexti */
/***************************/
static C_INLINE signed int _streamInUtf8_ICU_nexti(streamIn_t *streamInp) {
  signed int rci = -1;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rci;
  } else {
    /* A trace here would hog the output */
    /* STREAMIN_TRACEX("UTEXT_NEXT32(%p)", streamInp->streamIn_ICU.utextp); */
    return UTEXT_NEXT32(streamInp->streamIn_ICU.utextp);
  }
}
#endif

/***********************/
/* _streamInUtf8_markb */
/***********************/
streamInBool_t streamInUtf8_markb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rcb = _streamInUtf8_ICU_markb(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rcb = _streamInUtf8_ICONV_markb(streamInp);
    break;
#endif
  }

  return rcb;
}

#ifdef HAVE_ICU
/***************************/
/* _streamInUtf8_ICU_markb */
/***************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_markb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharMarkedOffsetl = UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp) * sizeof(UChar);
    /* STREAMIN_LOGX(STREAMIN_LOGLEVEL_TRACE, "Marking offset %ld", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}
#endif

/*******************************/
/* _streamInUtf8_markPreviousb */
/*******************************/
streamInBool_t streamInUtf8_markPreviousb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rcb = _streamInUtf8_ICU_markPreviousb(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rcb = _streamInUtf8_ICONV_markPreviousb(streamInp);
    break;
#endif
  }

  return rcb;
}

#ifdef HAVE_ICU
/***********************************/
/* _streamInUtf8_ICU_markPreviousb */
/***********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_markPreviousb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharMarkedOffsetl = utext_getPreviousNativeIndex(streamInp->streamIn_ICU.utextp) * sizeof(UChar);
    /* STREAMIN_LOGX(STREAMIN_LOGLEVEL_TRACE, "Marking offset %ld", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}
#endif

/********************************/
/* _streamInUtf8_currentFromMarkedb */
/********************************/
streamInBool_t streamInUtf8_currentFromMarkedb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rcb = _streamInUtf8_ICU_currentFromMarkedb(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rcb = _streamInUtf8_ICONV_currentFromMarkedb(streamInp);
    break;
#endif
  }

  return rcb;
}

#ifdef HAVE_ICU
/****************************************/
/* _streamInUtf8_ICU_currentFromMarkedb */
/****************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromMarkedb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This makes the marked character the current character */
    UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharMarkedOffsetl);
    /* STREAMIN_LOGX(STREAMIN_LOGLEVEL_TRACE, "Making offset %ld as current", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}
#endif

/***********************/
/* _streamInUtf8_doneb */
/***********************/
streamInBool_t streamInUtf8_doneb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  switch (streamInp->streamInUtf8Option.converteri) {
#ifdef HAVE_ICU
  case STREAMINUTF8OPTION_CONVERTER_ICU:
    rcb = _streamInUtf8_ICU_doneb(streamInp);
    break;
#endif
#ifdef HAVE_ICONV
  case STREAMINUTF8OPTION_CONVERTER_ICONV:
    rcb = _streamInUtf8_ICONV_doneb(streamInp);
    break;
#endif
  }

  return rcb;
}

#ifdef HAVE_ICU
/***************************/
/* _streamInUtf8_ICU_doneb */
/***************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  size_t         i;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* We search for a byte buffer that maps exactly to ucharMarkedOffsetl */
    /* STREAMIN_LOGX(STREAMIN_LOGLEVEL_TRACE, "Searching for marked offset %ld", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    for (i = 0; i < streamInp->nCharBufi; i++) {
      if (streamInp->streamIn_ICU.charBuf2UCharByteLengthlp[i] == streamInp->streamIn_ICU.ucharMarkedOffsetl) {
	break;
      }
    }
    if (i < streamInp->nCharBufi) {
      /* Got one */
      rcb = _streamIn_doneBufferb(streamInp, i);
    }
  }

  return rcb;
}
#endif
