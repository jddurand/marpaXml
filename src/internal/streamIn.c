#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include <unicode/ucsdet.h>
#include <unicode/uclean.h>
#include <unicode/ucnv.h>
#include <unicode/utext.h>
#include <unicode/ustring.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "internal/messageBuilder.h"

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#pragma comment(lib, "Ws2_32.lib")
#include <io.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define STREAMIN_OPEN _open
#define STREAMIN_OPEN_STRING "_open"
#define STREAMIN_CLOSE _close
#define STREAMIN_CLOSE_STRING "_close"
#define STREAMIN_READ _read
#define STREAMIN_READ_STRING "_read"
#define STREAMIN_LSEEK _lseek
#define STREAMIN_LSEEK_STRING "_lseek"
#define STREAMIN_STRDUP _strdup
#define STREAMIN_STRDUP_STRING "_strdup"
#else
#define STREAMIN_OPEN open
#define STREAMIN_OPEN_STRING "open"
#define STREAMIN_CLOSE close
#define STREAMIN_CLOSE_STRING "close"
#define STREAMIN_READ read
#define STREAMIN_READ_STRING "read"
#define STREAMIN_LSEEK lseek
#define STREAMIN_LSEEK_STRING "lseek"
#define STREAMIN_STRDUP strdup
#define STREAMIN_STRDUP_STRING "strdup"
#endif

const static char *_streamIn_defaultEncodings = "UTF-8";

static C_INLINE streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE void           _streamInUtf8_detectb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_fromConvertb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_toConvertb(streamIn_t *streamInp, size_t bufIndexi, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp);
static C_INLINE void           _streamInUtf8_destroyv(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_readb(streamIn_t *streamInp, size_t bufIndexi);

typedef struct streamIn_ICU {
  /* With ICU we do a single conversion Native => UChar                */
  /* into a SINGLE buffer. We maintain a mapping byteBufpp[] -> offset */
  int64_t                    *byteBuf2UCharByteLengthlp;/* mapping end of char buffers => offset in ucharBufp */
  int64_t                     ucharMarkedNativeIndexl;  /* Index just after the marked utext */
  int64_t                     ucharMarkedOffsetl;       /* Pointer location just after the marked utext. Per def our utext is a (UChar *), so this is just ucharMarkedNativeIndexl * sizeof(UChar). */
  int64_t                    *ucharUserMarkedNativeIndexl;  /* Index just after the user marked utext */
  int64_t                    *ucharUserMarkedOffsetl;       /* Pointer location just after the user marked utext. Per def our utext is a (UChar *), so this is just ucharMarkedNativeIndexl * sizeof(UChar). */
  size_t                      ucharBufMulSizei;         /* A heuristic guess of the utf16 takes maximum twice more space than native bytes */
  UChar                      *ucharBufp;                /* UChar buffer */
  int64_t                     ucharBufSizel;            /* Current size of allocated memory */
  int64_t                     ucharByteLengthl;         /* Length in bytes of all UChar characters */
  UConverter                 *uConverterFrom;           /* Input => UTF-16 (ICU's unicode) */
  UConverterFromUCallback     uConverterFromUCallback;
  const void                 *uConverterFromUCallbackCtxp;
  UConverter                 *uConverterTo;             /* UTF-16 (ICU's unicode) => Output */
  UConverterToUCallback       uConverterToUCallback;
  const void                 *uConverterToUCallbackCtxp;
  UText                      *utextp;
  streamInBool_t              eofb;
} streamIn_ICU_t;

static C_INLINE streamInBool_t _streamInUtf8_ICU_newb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_detectb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_fromConvertb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_toConvertb(streamIn_t *streamInp, size_t bufIndexi, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_currenti(streamIn_t *streamInp, signed int *currentip);
static C_INLINE streamInBool_t _streamInUtf8_ICU_nexti(streamIn_t *streamInp, signed int *nextip);
static C_INLINE streamInBool_t _streamInUtf8_ICU_markb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_userMarkb(streamIn_t *streamInp, size_t indexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_eofb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_markPreviousb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_userMarkPreviousb(streamIn_t *streamInp, size_t indexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromMarkedb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromMarkedb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromUserMarkedb(streamIn_t *streamInp, size_t indexi);
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromUserMarkedb(streamIn_t *streamInp, size_t indexi, char **destsp, size_t *byteLengthlp, size_t *lengthlp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromIndexesb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp, int64_t index1l, int64_t index2l);
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneb(streamIn_t *streamInp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_userDoneb(streamIn_t *streamInp, size_t indexi);
static C_INLINE void           _streamInUtf8_ICU_destroyv(streamIn_t *streamInp);
static C_INLINE unsigned char  _streaminUtf8_ICU_nibbleToHex(uint8_t n);
static C_INLINE streamInBool_t _streamInUnicode_getBufferb(streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp);

static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromMarkedb(streamIn_t *streamInp, const void **pp, size_t *byteLengthlp, size_t *lengthlp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromUserMarkedb(streamIn_t *streamInp, size_t indexl, const void **pp, size_t *byteLengthlp, size_t *lengthlp);
static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromIndexesb(streamIn_t *streamInp, const void **pp, size_t *byteLengthlp, size_t *lengthlp, int64_t index1l, int64_t index2l);

static C_INLINE streamInBool_t _streamIn_readFromFileDescriptorCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);
static C_INLINE streamInBool_t _streamIn_readFromFILECallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);
static C_INLINE streamInBool_t _streamIn_readFromBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);
static C_INLINE streamInBool_t _streamIn_readFromSocketCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);

/*****************************************************************************/
/* Generic class handling read-only streaming on buffers that can ONLY go on */
/*****************************************************************************/
struct streamIn {
  size_t                     nByteBufi;                /* Number of byte buffers (start at zero) */
  char                     **byteBufpp;                /* char buffers */
  size_t                    *realSizeByteBufip;        /* Number of bytes effectively available in each buffer */
  streamInBool_t            *managedbp;                /* True if a buffer is managed by the user */
  streamInOption_t           streamInOption;           /* Byte options */
  streamInBool_t             eofb;                     /* EOF flag */

  marpaXmlLog_t             *marpaXmlLogp;

  /* UTF-8 section */
  streamInBool_t             utf8b;                    /* STREAMIN_BOOL_TRUE only if streamInUtf8_newp() is called */
  streamInUtf8Option_t       streamInUtf8Option;       /* utf8 options */

  streamIn_ICU_t             streamIn_ICU;
};

#define STREAMIN_DEFAULT_BUFMAXSIZEI (1024*1024)

#define STREAMIN_LOG0(marpaXmlLogLeveli, msgs)      marpaXml_log(streamInp->marpaXmlLogp, marpaXmlLogLeveli, msgs)
#define STREAMIN_LOGX(marpaXmlLogLeveli, fmts, ...) marpaXml_log(streamInp->marpaXmlLogp, marpaXmlLogLeveli, fmts, __VA_ARGS__)

#ifndef STREAMIN_NTRACE
#define STREAMIN_TRACE0(fmts)      STREAMIN_LOG0(MARPAXML_LOGLEVEL_TRACE, fmts)
#define STREAMIN_TRACEX(fmts, ...) STREAMIN_LOGX(MARPAXML_LOGLEVEL_TRACE, fmts, __VA_ARGS__)
#else
#define STREAMIN_TRACE0(fmts)
#define STREAMIN_TRACEX(fmts, ...)
#endif

#define STREAMIN_FREE(x) {			\
    if ((x) != NULL) {				\
      free(x);					\
    } else {					\
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_CRITICAL, "Attempt to free a NULL pointer at %s:%d", __FILE__, __LINE__); \
    }						\
    (x) = NULL;					\
  }
#define STREAMIN_FREE_REPLACEMENT(x, replacement) { STREAMIN_FREE(x); (x) = (replacement); }

#define STREAMIN_MANAGE_BUFFERI(streamInp, indexBufferi, wantedIndexi) { \
    if (indexBufferi < 0) {						\
      wantedIndexi = streamInp->nByteBufi;				\
      wantedIndexi -= (size_t) -indexBufferi;				\
    } else {								\
      wantedIndexi = indexBufferi;					\
    }									\
  }


static C_INLINE streamInBool_t _streamIn_getBufferb (streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp);
static C_INLINE streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi);
static C_INLINE streamInBool_t _streamIn_readb      (streamIn_t *streamInp);
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
  streamInOptionp->allBuffersAreManagedByUserb  = STREAMIN_BOOL_FALSE;
  streamInOptionp->marpaXmlLogp                 = NULL;
  streamInOptionp->readCallbackp                = NULL;
  streamInOptionp->readCallbackDatavp           = NULL;
  streamInOptionp->bufFreeCallbackp             = NULL;
  streamInOptionp->bufFreeCallbackDatavp        = NULL;

  return STREAMIN_BOOL_TRUE;
}

/*****************/
/* streamIn_newp */
/*****************/
streamIn_t *streamIn_newp(streamInOption_t *streamInOptionp) {
  streamIn_t      *streamInp;
  char            *errorMsgs = NULL;
  marpaXmlLog_t   *marpaXmlLogp = (streamInOptionp != NULL) ? streamInOptionp->marpaXmlLogp : NULL;

  streamInp = malloc(sizeof(streamIn_t));
  if (streamInp == NULL) {
    errorMsgs = messageBuilder("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_log(marpaXmlLogp, MARPAXML_LOGLEVEL_ERROR, errorMsgs);
    if (errorMsgs != messageBuilder_internalErrors()) {
      STREAMIN_FREE(errorMsgs);
    }
    return NULL;
  }

  streamInp->nByteBufi         = 0;
  streamInp->byteBufpp         = NULL;
  streamInp->realSizeByteBufip = NULL;
  streamInp->managedbp         = NULL;
  streamInp->eofb              = 0;
  streamInp->utf8b             = STREAMIN_BOOL_FALSE;
  streamInp->marpaXmlLogp      = streamInOptionp->marpaXmlLogp;
  /* From now on we can use STREAMIN_LOG macro */

  streamIn_optionDefaultb(&(streamInp->streamInOption));
  if (_streamIn_optionb(streamInp, streamInOptionp) == STREAMIN_BOOL_FALSE) {
    streamIn_destroyv(&streamInp);
    return NULL;
  }

  return streamInp;
}

/**************************/
/* _streamInUtf8_ICU_newb */
/**************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_newb(streamIn_t *streamInp) {
  streamInBool_t  rcb        = STREAMIN_BOOL_TRUE;
  UErrorCode      uErrorCode = U_ZERO_ERROR;

  /* Formally not needed, but done explicitely to make sure that ICU is initialized */
  u_init(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    return STREAMIN_BOOL_FALSE;
  }

  switch (streamInp->streamInUtf8Option.ICUFromCallback) {
  case STREAMINUTF8OPTION_ICU_DEFAULT:
    break;
  case STREAMINUTF8OPTION_ICU_SUBSTITUTE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SUBSTITUTE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_SKIP:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_SKIP;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_STOP:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_STOP;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_ICU:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_ICU;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_JAVA:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_JAVA;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_C:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_C;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML_HEX:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE:
    streamInp->streamIn_ICU.uConverterFromUCallback     = UCNV_FROM_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterFromUCallbackCtxp = UCNV_ESCAPE_UNICODE;
    break;
  default:
    /* Cannot happen in theory */
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d at %s:%d", streamInp->streamInUtf8Option.ICUFromCallback, __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
  }

  switch (streamInp->streamInUtf8Option.ICUToCallback) {
  case STREAMINUTF8OPTION_ICU_DEFAULT:
    break;
  case STREAMINUTF8OPTION_ICU_SUBSTITUTE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_SUBSTITUTE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_SKIP:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_SKIP;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_STOP:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_STOP;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = NULL;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_ICU:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_ICU;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_JAVA:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_JAVA;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_C:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_C;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML_HEX:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_HEX;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_XML_DEC;
    break;
  case STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE:
    streamInp->streamIn_ICU.uConverterToUCallback     = UCNV_TO_U_CALLBACK_ESCAPE;
    streamInp->streamIn_ICU.uConverterToUCallbackCtxp = UCNV_ESCAPE_UNICODE;
    break;
  default:
    /* Cannot happen in theory */
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Invalid ICUToCallback %d at %s:%d", streamInp->streamInUtf8Option.ICUToCallback, __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
  }

  return rcb;
}

/*********************/
/* streamInUtf8_newp */
/*********************/
streamIn_t *streamInUtf8_newp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamIn_t    *streamInp = streamIn_newp(streamInOptionp);
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInp == NULL) {
    return NULL;
  }

  streamInp->utf8b                                    = STREAMIN_BOOL_TRUE;
  streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp   = NULL;
  streamInp->streamIn_ICU.ucharMarkedNativeIndexl     = 0;
  streamInp->streamIn_ICU.ucharMarkedOffsetl          = 0;
  streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl = NULL;
  streamInp->streamIn_ICU.ucharUserMarkedOffsetl      = NULL;
  streamInp->streamIn_ICU.ucharBufMulSizei            = 2;
  streamInp->streamIn_ICU.ucharBufp                   = NULL;
  streamInp->streamIn_ICU.ucharBufSizel               = 0;
  streamInp->streamIn_ICU.ucharByteLengthl            = 0;
  streamInp->streamIn_ICU.uConverterFrom              = NULL;
  streamInp->streamIn_ICU.uConverterTo                = NULL;
  streamInp->streamIn_ICU.utextp                      = NULL;
  streamInp->streamIn_ICU.eofb                        = STREAMIN_BOOL_FALSE;

  streamInUtf8_optionDefaultb(&(streamInp->streamInUtf8Option));
  if (_streamInUtf8_optionb(streamInp, streamInUtf8Optionp) == STREAMIN_BOOL_FALSE) {
    streamIn_destroyv(&streamInp);
  } else {
    rcb = _streamInUtf8_ICU_newb(streamInp);

    if (rcb == STREAMIN_BOOL_FALSE) {
      streamIn_destroyv(&streamInp);
      streamInp = NULL;   /* Formally this is not necessary */
    }
  }

  return streamInp;
}

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
  int64_t        *byteBuf2UCharByteLengthlp;
  int64_t         nativeIndexl;

  if ((bufIndexi + 1) == streamInp->nByteBufi) {
    /* In fact we destroy everything */

    /* In case of EOF, these buffers can be NULL */
    if (streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp != NULL) {
      STREAMIN_FREE(streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp);
    }
    streamInp->streamIn_ICU.ucharMarkedNativeIndexl = 0;
    streamInp->streamIn_ICU.ucharMarkedOffsetl = 0;
    if (streamInp->streamIn_ICU.ucharBufp != NULL) {
      STREAMIN_FREE(streamInp->streamIn_ICU.ucharBufp);
    }
    streamInp->streamIn_ICU.ucharBufSizel = 0;
    streamInp->streamIn_ICU.ucharByteLengthl = 0;

    /* ICU recommends to not close/open utext - so we delay that to the destroy method */
  } else {

    bytesToRemovel = streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi];
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
          STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        } else {
          streamInp->streamIn_ICU.ucharBufp = ucharBufp;
          streamInp->streamIn_ICU.ucharBufSizel -= bytesToRemovel;
          streamInp->streamIn_ICU.ucharByteLengthl -= bytesToRemovel;
          ucharLengthl = streamInp->streamIn_ICU.ucharByteLengthl / sizeof(UChar);
          STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);
          streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
          if (U_FAILURE(uErrorCode)) {
            STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
            rcb = STREAMIN_BOOL_FALSE;
          } else {
            nativeIndexl -= ucharsToRemovel;
            UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, nativeIndexl);
          }
        }
        for (j = 0, i = (bufIndexi + 1); i < streamInp->nByteBufi; ++i, ++j) {
          streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[j] = streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[i] - bytesToRemovel;
        }
        /* We have to realloc, taking care of moving backward */
        /* the informations                                   */
        /* Formally, on realloc error, we can continue */
        byteBuf2UCharByteLengthlp = realloc(streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp, streamInp->nByteBufi * sizeof(int64_t));
        if (byteBuf2UCharByteLengthlp == NULL) {
          STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        } else {
          streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp = byteBuf2UCharByteLengthlp;
        }
      } else {
        /* The full UChar buffer is over */
        STREAMIN_FREE(streamInp->streamIn_ICU.ucharBufp);
        streamInp->streamIn_ICU.ucharBufSizel = 0;
        streamInp->streamIn_ICU.ucharByteLengthl = 0;
        for (j = 0, i = (bufIndexi + 1); i < streamInp->nByteBufi; ++i, ++j) {
          streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[j] = streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[i];
        }
      }
    }
  }


  return rcb;
}

/********************************************/
/* _streamInUtf8_doneBufferb                */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_doneBufferb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    rcb = _streamInUtf8_ICU_doneBufferb(streamInp, bufIndexi);
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
      /* User did a streamInUtf8_newp. The very first time, we auto-detect encoding if needed */
      _streamInUtf8_detectb(streamInp);
    }

    rcb = _streamInUtf8_ICU_readb(streamInp, bufIndexi);

    if (rcb == STREAMIN_BOOL_TRUE) {
      rcb = _streamInUtf8_fromConvertb(streamInp, bufIndexi);
    }
  }

  return rcb;
}

/********************************************/
/* streamInUnicode_doneBufferb              */
/********************************************/
streamInBool_t streamInUnicode_doneBufferb(streamIn_t *streamInp, int indexBufferi) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  size_t wantedIndexi;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  /* Nothing differentiate the doneBufferb method and the non unicode method */
  /* except the test on the utf8b boolean -; */

  STREAMIN_TRACEX("streamInUnicode_doneBufferb(%p, %d)", streamInp, indexBufferi);

  STREAMIN_MANAGE_BUFFERI(streamInp, indexBufferi, wantedIndexi);

  if (streamInp->nByteBufi > 0 && wantedIndexi < streamInp->nByteBufi) {
    return _streamIn_doneBufferb(streamInp, wantedIndexi);
  } else {
    return STREAMIN_BOOL_FALSE;
  }
}

/********************************************/
/* _streamIn_doneBufferb                    */
/********************************************/

/* Take care: this routine will destroy buffers, and the call to utf8 stuff */
/* will rely on streamInp->nByteBufi without modify it */
static C_INLINE streamInBool_t _streamIn_doneBufferb(streamIn_t *streamInp, size_t bufIndexi)
{
  size_t          i, j;
  char          **byteBufpp;
  size_t         *realSizeByteBufip;
  streamInBool_t *managedbp;
  size_t          nByteBufi = streamInp->nByteBufi;
  streamInBool_t  rcb = STREAMIN_BOOL_TRUE;

  /* We want to forget forever buffer at index bufIndexi. */
  /* Any eventual previous buffer will me removed as well  */

  STREAMIN_TRACEX("Destroying buffers [%d..%d]", 0, bufIndexi);

  /* We destroy the buffers */
  for (i = 0; i <= bufIndexi; ++i) {
    if (streamInp->managedbp[i] == STREAMIN_BOOL_FALSE) {
      STREAMIN_FREE(streamInp->byteBufpp[i]);
    } else if (streamInp->streamInOption.bufFreeCallbackp != NULL) {
      (*streamInp->streamInOption.bufFreeCallbackp)(streamInp->streamInOption.bufFreeCallbackDatavp, streamInp->byteBufpp[i]);
      streamInp->byteBufpp[i] = NULL;
    }
  }

  if ((bufIndexi + 1) == nByteBufi) {
    /* And in fact we destroyed everything */
    STREAMIN_FREE(streamInp->byteBufpp);
    STREAMIN_FREE(streamInp->realSizeByteBufip);
    STREAMIN_FREE(streamInp->managedbp);
    nByteBufi = 0;
  }
  else {

    STREAMIN_TRACEX("Moving information of buffers [%d..%d] to [0..%d]", bufIndexi + 1, nByteBufi - 1, nByteBufi - (bufIndexi + 1) - 1);

    /* We have to realloc, taking care of moving backward */
    /* the informations                                   */
    for (j = 0, i = (bufIndexi + 1); i < nByteBufi; ++i, ++j) {
      streamInp->byteBufpp[j] = streamInp->byteBufpp[i];
      streamInp->realSizeByteBufip[j] = streamInp->realSizeByteBufip[i];
      streamInp->managedbp[j] = streamInp->managedbp[i];
    }

    nByteBufi -= (bufIndexi+1);

    /* Formally, on realloc error, we can continue */
    byteBufpp = realloc(streamInp->byteBufpp, nByteBufi * sizeof(char *));
    if (byteBufpp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->byteBufpp = byteBufpp;
    }

    realSizeByteBufip = realloc(streamInp->realSizeByteBufip, nByteBufi * sizeof(void *));
    if (realSizeByteBufip == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->realSizeByteBufip = realSizeByteBufip;
    }

    managedbp = realloc(streamInp->managedbp, nByteBufi * sizeof(streamInBool_t));
    if (managedbp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    } else {
      streamInp->managedbp = managedbp;
    }
  }

  /* Regardless it if failed or not, we have crunched buffers -; */
  rcb = _streamInUtf8_doneBufferb(streamInp, bufIndexi);

  streamInp->nByteBufi = nByteBufi;

  return rcb;
}

/********************************************/
/* _streamInUtf8_ICU_readb                  */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_readb(streamIn_t *streamInp, size_t bufIndexi) {
  UChar          *ucharBufp;
  int64_t        *byteBuf2UCharByteLengthlp;
  int64_t         ucharBufSizel = streamInp->streamIn_ICU.ucharBufSizel;

  /* We are called at the end of _streamIn_readb(): the last buffer has already been read */

  if (bufIndexi == 0) {

    byteBuf2UCharByteLengthlp = malloc(sizeof(int64_t));
    if (byteBuf2UCharByteLengthlp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    ucharBufSizel = sizeof(UChar) * streamInp->realSizeByteBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
    /* Cross the fingers this fits in a size_t */
    ucharBufp = malloc((size_t) ucharBufSizel);
    if (ucharBufp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      /* No need to assign to NULL, this is a local variable and we will return just after */
      free(byteBuf2UCharByteLengthlp);
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    byteBuf2UCharByteLengthlp = realloc(streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp, (bufIndexi + 1) * sizeof(int64_t));
    if (byteBuf2UCharByteLengthlp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    if (ucharBufSizel > 0) {
      /* Cross fingers for no overlap, i.e. the user application should know to release buffers regularly */
      ucharBufSizel += sizeof(UChar) * streamInp->realSizeByteBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      /* Cross fingers this fits in a size_t - thread _streamInUtf8_ICU_fromConvertb() method will take care of reallocating if it is too short */
      ucharBufp = realloc(streamInp->streamIn_ICU.ucharBufp, (size_t) ucharBufSizel);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
    } else {
      /* utf8 buffer can be NULL if we destroyed previous buffer(s) and there was not enough bytes */
      /* from it(them) to give at least one UChar */
      ucharBufSizel = sizeof(UChar) * streamInp->realSizeByteBufip[bufIndexi] * streamInp->streamIn_ICU.ucharBufMulSizei;
      /* Cross fingers this fits in a size_t */
      ucharBufp = malloc((size_t) ucharBufSizel);
      if (ucharBufp == NULL) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
    }

  }

  streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp = byteBuf2UCharByteLengthlp;
  streamInp->streamIn_ICU.ucharBufp = ucharBufp;
  streamInp->streamIn_ICU.ucharBufSizel = ucharBufSizel;

  return STREAMIN_BOOL_TRUE;
}

/********************************************/
/* _streamIn_readb                          */
/********************************************/
static C_INLINE streamInBool_t _streamIn_readb(streamIn_t *streamInp) {
  size_t          nByteBufi;
  size_t          bufIndexi;
  char          **byteBufpp;
  size_t         *realSizeByteBufip;
  streamInBool_t *managedbp;
  char           *byteManagedArrayp = NULL;

  if (streamInp->eofb == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  nByteBufi = streamInp->nByteBufi;

  STREAMIN_TRACEX("Allocating space for buffer No %d", (int) nByteBufi);

  /* Allocate space */
  if (nByteBufi == 0) {

    bufIndexi = nByteBufi++;

    streamInp->byteBufpp = malloc(sizeof(char *));
    if (streamInp->byteBufpp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    streamInp->realSizeByteBufip = malloc(sizeof(size_t));
    if (streamInp->realSizeByteBufip == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    streamInp->managedbp = malloc(sizeof(streamInBool_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

  } else {

    bufIndexi = nByteBufi++;

    byteBufpp = realloc(streamInp->byteBufpp, nByteBufi * sizeof(char *));
    if (byteBufpp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->byteBufpp = byteBufpp;
    }

    realSizeByteBufip = realloc(streamInp->realSizeByteBufip, nByteBufi * sizeof(size_t));
    if (streamInp->realSizeByteBufip == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->realSizeByteBufip = realSizeByteBufip;
    }

    managedbp = realloc(streamInp->managedbp, nByteBufi * sizeof(size_t));
    if (streamInp->managedbp == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    } else {
      streamInp->managedbp = managedbp;
    }

  }

  if (streamInp->streamInOption.allBuffersAreManagedByUserb == STREAMIN_BOOL_TRUE) {
    streamInp->byteBufpp[bufIndexi]  = NULL;
    streamInp->managedbp[bufIndexi] = STREAMIN_BOOL_TRUE;
  } else {
    streamInp->byteBufpp[bufIndexi]  = malloc(streamInp->streamInOption.bufMaxSizei);
    if (streamInp->byteBufpp[bufIndexi] == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }
    streamInp->managedbp[bufIndexi] = STREAMIN_BOOL_FALSE;
  }
  streamInp->realSizeByteBufip[bufIndexi] = 0;

  if (streamInp->streamInOption.readCallbackp != NULL) {
    if ((*streamInp->streamInOption.readCallbackp)(streamInp->streamInOption.readCallbackDatavp, streamInp->streamInOption.bufMaxSizei, &(streamInp->realSizeByteBufip[bufIndexi]), streamInp->byteBufpp[bufIndexi], &byteManagedArrayp) == STREAMIN_BOOL_FALSE) {
      return STREAMIN_BOOL_FALSE;
    }
  }

  if (byteManagedArrayp != NULL) {
    /* User-defined buffer */
    streamInp->managedbp[bufIndexi]  = STREAMIN_BOOL_TRUE;
    if (streamInp->byteBufpp[bufIndexi] != NULL) {
      STREAMIN_FREE(streamInp->byteBufpp[bufIndexi]);
    }
    streamInp->byteBufpp[bufIndexi] = byteManagedArrayp;
  }

  STREAMIN_TRACEX("read callback filled %d bytes in buffer No %d", streamInp->realSizeByteBufip[bufIndexi], bufIndexi);

  if (streamInp->realSizeByteBufip[bufIndexi] <= 0) {
    /* Nothing read */
    STREAMIN_TRACE0("EOF");
    streamInp->eofb = STREAMIN_BOOL_TRUE;
    streamInp->realSizeByteBufip[bufIndexi] = 0;
  }


  streamInp->nByteBufi = bufIndexi + 1;

  if (streamInp->realSizeByteBufip[bufIndexi] <= 0) {
    if (bufIndexi == 0) {
      /* Nothing was read - this could have been done before, but happens only once, at EOF     */
      /* If we are working on the first buffer, we can safely call _streamIn_doneBufferb()     */
      /* otherwise there is a leftover of pointers, we only free what has been allocated inside */
      /* No need to redo a realloc. Next eventuall call will simply realloc on the same size.   */
      _streamIn_doneBufferb(streamInp, bufIndexi);
    } else {
      /* Formally, no need to assign NULL since we will reduce */
      STREAMIN_FREE(streamInp->byteBufpp[bufIndexi]);
      streamInp->nByteBufi--;
      byteBufpp = realloc(streamInp->byteBufpp, streamInp->nByteBufi * sizeof(char *));
      /* We are reducing the array, so formally even in case of error we can continue */
      if (byteBufpp == NULL) {
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_WARNING, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      } else {
        streamInp->byteBufpp = byteBufpp;
      }
    }
    return STREAMIN_BOOL_FALSE;
  }


  return _streamInUtf8_readb(streamInp, bufIndexi);
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

  if (streamInp->nByteBufi > 0) {
    _streamIn_doneBufferb(streamInp, streamInp->nByteBufi - 1);
  }

  _streamInUtf8_destroyv(streamInp);

  /* No need to assign to NULL, we know what we are doing here */
  free(streamInp);
  *streamInpp = NULL;
}

/************************/
/* _streamIn_getBufferb */
/************************/
static C_INLINE streamInBool_t _streamIn_getBufferb(streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp) {
  char          *byteArrayp;
  size_t         bytesInBuffer;
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  STREAMIN_TRACEX("_streamIn_getBufferb(%p, %d, %p, %p, %p)", streamInp, wantedIndexi, indexBufferip, byteArraypp, bytesInBufferp);

  if (wantedIndexi < streamInp->nByteBufi) {
    /* Available */
    byteArrayp = streamInp->byteBufpp[wantedIndexi];
    bytesInBuffer = streamInp->realSizeByteBufip[wantedIndexi];
    rcb = STREAMIN_BOOL_TRUE;
  } else {
    /* Ask for next buffers until we reach wantedIndexi */
    while (streamInp->eofb == STREAMIN_BOOL_FALSE) {
      if (_streamIn_readb(streamInp) == STREAMIN_BOOL_FALSE) {
	break;
      }
      if (wantedIndexi < streamInp->nByteBufi) {
	byteArrayp = streamInp->byteBufpp[wantedIndexi];
	bytesInBuffer = streamInp->realSizeByteBufip[wantedIndexi];
	rcb = STREAMIN_BOOL_TRUE;
	break;
      }
    }
  }

  if (rcb == STREAMIN_BOOL_TRUE) {
    if (indexBufferip != NULL) {
      *indexBufferip = wantedIndexi;
    }
    if (byteArraypp != NULL) {
      *byteArraypp = byteArrayp;
    }
    if (bytesInBufferp != NULL) {
      *bytesInBufferp = bytesInBuffer;
    }
  }

  return rcb;
}

/****************************/
/* _streamInUnicode_getBufferb */
/****************************/
static C_INLINE streamInBool_t _streamInUnicode_getBufferb(streamIn_t *streamInp, size_t wantedIndexi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp) {
  char          *byteArrayp;
  size_t         indexBufferi;
  size_t         bytesInBuffer;
  size_t         lengthInBuffer;

  /* First, make sure this buffer index is available */
  if (_streamIn_getBufferb(streamInp, wantedIndexi, &indexBufferi, NULL, NULL) == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  /* Run the converter */
  if (_streamInUtf8_toConvertb(streamInp, indexBufferi, &byteArrayp, &bytesInBuffer, &lengthInBuffer) == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  if (indexBufferip != NULL) {
    *indexBufferip = wantedIndexi;
  }
  if (byteArraypp != NULL) {
    *byteArraypp = byteArrayp;
  }
  if (bytesInBufferp != NULL) {
    *bytesInBufferp = bytesInBuffer;
  }
  if (lengthInBufferp != NULL) {
    *lengthInBufferp = lengthInBuffer;
  }

  return STREAMIN_BOOL_TRUE;
}

/***********************/
/* streamIn_getBufferb */
/***********************/
streamInBool_t streamIn_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp) {
  size_t wantedIndexi;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_getBufferb(%p, %d, %p, %p, %p)", streamInp, indexBufferi, indexBufferip, byteArraypp, bytesInBufferp);

  STREAMIN_MANAGE_BUFFERI(streamInp, indexBufferi, wantedIndexi);

  return _streamIn_getBufferb(streamInp, wantedIndexi, indexBufferip, byteArraypp, bytesInBufferp);
}

/***************************/
/* streamInUnicode_getBufferb */
/***************************/
streamInBool_t streamInUnicode_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp) {
  size_t wantedIndexi;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamInUnicode_getBufferb(%p, %d, %p, %p, %p, %p)", streamInp, indexBufferi, indexBufferip, byteArraypp, bytesInBufferp, lengthInBufferp);

  STREAMIN_MANAGE_BUFFERI(streamInp, indexBufferi, wantedIndexi);

  return _streamInUnicode_getBufferb(streamInp, wantedIndexi, indexBufferip, byteArraypp, bytesInBufferp, lengthInBufferp);
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

  STREAMIN_MANAGE_BUFFERI(streamInp, indexBufferi, wantedIndexi);

  if (streamInp->nByteBufi > 0 && wantedIndexi < streamInp->nByteBufi) {
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
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Invalid bufMaxSizei at %s:%d", __FILE__, __LINE__);
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
streamInBool_t streamIn_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamIn_nextBufferb(%p, %p, %p, %p)", streamInp, indexBufferip, byteArraypp, bytesInBufferp);

  return _streamIn_getBufferb(streamInp, streamInp->nByteBufi, indexBufferip, byteArraypp, bytesInBufferp);
}

/****************************/
/* streamInUnicode_nextBufferb */
/****************************/
streamInBool_t streamInUnicode_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  STREAMIN_TRACEX("streamInUnicode_nextBufferb(%p, %p, %p, %p %p)", streamInp, indexBufferip, byteArraypp, bytesInBufferp, lengthInBufferp);

  return _streamInUnicode_getBufferb(streamInp, streamInp->nByteBufi, indexBufferip, byteArraypp, bytesInBufferp, lengthInBufferp);
}

/*************************/
/* _streamInUtf8_detectb */
/*************************/
static C_INLINE void _streamInUtf8_detectb(streamIn_t *streamInp) {
  if (_streamInUtf8_ICU_detectb(streamInp) == STREAMIN_BOOL_TRUE) {
    return;
  }

  STREAMIN_LOG0(MARPAXML_LOGLEVEL_INFO, "Charset detection failure, assuming UTF-8");
  streamInp->streamInUtf8Option.fromEncodings = (char *) _streamIn_defaultEncodings;
}

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
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_setText(%p, %p, %ld, %p)", uCharsetDetector, streamInp->byteBufpp[0], (unsigned long) streamInp->realSizeByteBufip[0], &uErrorCode);
  ucsdet_setText(uCharsetDetector, streamInp->byteBufpp[0], streamInp->realSizeByteBufip[0], &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_setText(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_detect(%p, %p)", uCharsetDetector, &uErrorCode);
  uCharsetMatch = ucsdet_detect(uCharsetDetector, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_detect(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (uCharsetMatch == NULL) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_detect() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getName(%p, %p)", uCharsetMatch, &uErrorCode);
  fromEncodings = ucsdet_getName(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_getName(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (fromEncodings == NULL) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_getName() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (strlen(fromEncodings) <= 0) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_getName() returned empty string at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getConfidence(%p, %p)", uCharsetMatch, &uErrorCode);
  confidence = ucsdet_getConfidence(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_getConfidence(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  if (confidence < 10) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucsdet_getConfidence() returned encoding \"%s\" with too low confidence %d < 10 - rejected", fromEncodings, confidence);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ICU returned encoding \"%s\" with confidence %d", fromEncodings, confidence);

 ICU_end:

  if (rcb == STREAMIN_BOOL_TRUE) {
    /* Save the result */
    streamInp->streamInUtf8Option.fromEncodings = malloc(sizeof(char) * (strlen(fromEncodings) + 1));
    if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
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

/*********************************/
/* streamInUnicode_fromEncodings */
/*********************************/
streamInBool_t streamInUnicode_fromEncodings(streamIn_t *streamInp, char **fromEncodingsp) {
  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  if (fromEncodingsp != NULL) {
    *fromEncodingsp = streamInp->streamInUtf8Option.fromEncodings;
  }

  return STREAMIN_BOOL_TRUE;
}

/*******************************/
/* streamInUnicode_toEncodings */
/*******************************/
streamInBool_t streamInUnicode_toEncodings(streamIn_t *streamInp, char **toEncodingsp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  if (toEncodingsp != NULL) {
    *toEncodingsp = streamInp->streamInUtf8Option.toEncodings;
  }

  return STREAMIN_BOOL_TRUE;
}

/**********************/
/* streamInUtf8_nexti */
/**********************/
streamInBool_t streamInUtf8_nexti(streamIn_t *streamInp, signed int *nextip) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  signed int     nexti;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_nexti(streamInp, &nexti);

  if (rcb == STREAMIN_BOOL_FALSE) {
    if (_streamIn_getBufferb(streamInp, streamInp->nByteBufi, NULL, NULL, NULL) == STREAMIN_BOOL_TRUE) {
      return streamInUtf8_nexti(streamInp, nextip);
    }
  }

  if (rcb == STREAMIN_BOOL_TRUE) {
    if (nextip != NULL) {
      *nextip = nexti;
    }
  }

  return rcb;
}

/******************************/
/* _streamInUtf8_fromConvertb */
/******************************/
static C_INLINE streamInBool_t _streamInUtf8_fromConvertb(streamIn_t *streamInp, size_t bufIndexi) {
  return _streamInUtf8_ICU_fromConvertb(streamInp, bufIndexi);
}

/****************************/
/* _streamInUtf8_toConvertb */
/****************************/
static C_INLINE streamInBool_t _streamInUtf8_toConvertb(streamIn_t *streamInp, size_t bufIndexi, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp) {
  return _streamInUtf8_ICU_toConvertb(streamInp, bufIndexi, byteArraypp, bytesInBufferp, lengthInBufferp);
}

/**********************************/
/* _streamInUtf8_ICU_fromConvertb */
/**********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_fromConvertb(streamIn_t *streamInp, size_t bufIndexi) {
  streamInBool_t rcb            = STREAMIN_BOOL_TRUE;
  int64_t        ucharBufSizel  = streamInp->streamIn_ICU.ucharBufSizel;
  UChar         *target         = (UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.ucharByteLengthl);
  UChar         *origTarget     = target;
  const UChar   *targetLimit    = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + ucharBufSizel);
  const char    *source         = streamInp->byteBufpp[bufIndexi];
  const char    *sourceLimit    = streamInp->byteBufpp[bufIndexi] + streamInp->realSizeByteBufip[bufIndexi];
  UBool          flushb         = (streamInp->eofb == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;
  streamInBool_t stopb          = STREAMIN_BOOL_FALSE;
  UErrorCode     uErrorCode     = U_ZERO_ERROR;
  int64_t        ucharLengthl;  /* Number of UChar */
  UChar         *ucharBufp;

  /* For error reporting */
  char          errorBytes[32];
  int8_t        errorLength;
  int           i;

  /* Create "From" converter - we KEEP using the converter even if user, or us, say this is an UTF-8 */
  if (streamInp->streamIn_ICU.uConverterFrom == NULL) {
    UBool fallback = (streamInp->streamInUtf8Option.ICUFromFallback == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;

    STREAMIN_TRACEX("ucnv_open(\"%s\", %p)", streamInp->streamInUtf8Option.fromEncodings, &uErrorCode);
    streamInp->streamIn_ICU.uConverterFrom = ucnv_open(streamInp->streamInUtf8Option.fromEncodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucnv_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    if (streamInp->streamInUtf8Option.ICUFromCallback != STREAMINUTF8OPTION_ICU_DEFAULT) {
      STREAMIN_TRACEX("ucnv_setFromUCallBack(%p, %p, %p, %p, %p, %p)", streamInp->streamIn_ICU.uConverterFrom, streamInp->streamIn_ICU.uConverterFromUCallback, streamInp->streamIn_ICU.uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
      ucnv_setFromUCallBack(streamInp->streamIn_ICU.uConverterFrom, streamInp->streamIn_ICU.uConverterFromUCallback, streamInp->streamIn_ICU.uConverterFromUCallbackCtxp, NULL, NULL, &uErrorCode);
      if (U_FAILURE(uErrorCode)) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucnv_setFromUCallBack(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
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
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
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
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_INFO, "ucnv_toUnicode(): %s: %02x%02x", u_errorName(uErrorCode), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i] >> 4), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i]));
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
      streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi] = streamInp->streamIn_ICU.ucharByteLengthl;
      STREAMIN_TRACEX("streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[%d] = %ld", bufIndexi, (unsigned long) streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi]);

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
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	rcb = STREAMIN_BOOL_FALSE;
      } else {
	UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, nativeIndexl);
      }
    } else {
      /* Instanciate utext */
      STREAMIN_TRACEX("utext_openUChars(%p, %p, %ld, %p)", streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, (unsigned long) ucharLengthl, &uErrorCode);
      streamInp->streamIn_ICU.utextp = utext_openUChars(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharBufp, ucharLengthl, &uErrorCode);
      if (U_FAILURE(uErrorCode)) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "utext_openUChars(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	rcb = STREAMIN_BOOL_FALSE;
      }
    }
  }
  return rcb;
}

/********************************/
/* _streamInUtf8_ICU_toConvertb */
/********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_toConvertb(streamIn_t *streamInp, size_t bufIndexi, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp) {
  streamInBool_t rcb            = STREAMIN_BOOL_TRUE;

  size_t         byteBufSizel;
  char          *target;
  char          *origTarget;
  const char    *targetLimit;
  const UChar   *source;
  const UChar   *sourceLimit;
  UBool          flushb         = (streamInp->eofb == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;
  streamInBool_t stopb          = STREAMIN_BOOL_FALSE;
  UErrorCode     uErrorCode     = U_ZERO_ERROR;

  /* For error reporting */
  char          errorBytes[32];
  int8_t        errorLength;
  int           i;


  if (bufIndexi > 0) {
    source = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi-1]);
  } else {
    source = streamInp->streamIn_ICU.ucharBufp;
  }
  sourceLimit = (const UChar *) (((char *) streamInp->streamIn_ICU.ucharBufp) + streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi]);

  if (streamInp->streamIn_ICU.uConverterTo == NULL) {
    UBool fallback = (streamInp->streamInUtf8Option.ICUToFallback == STREAMIN_BOOL_TRUE) ? TRUE : FALSE;

    STREAMIN_TRACEX("ucnv_open(\"%s\", %p)", streamInp->streamInUtf8Option.toEncodings, &uErrorCode);
    streamInp->streamIn_ICU.uConverterTo = ucnv_open(streamInp->streamInUtf8Option.toEncodings, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucnv_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
      return STREAMIN_BOOL_FALSE;
    }

    if (streamInp->streamInUtf8Option.ICUToCallback != STREAMINUTF8OPTION_ICU_DEFAULT) {
      STREAMIN_TRACEX("ucnv_setToUCallBack(%p, %p, %p, %p, %p, %p)", streamInp->streamIn_ICU.uConverterTo, streamInp->streamIn_ICU.uConverterToUCallback, streamInp->streamIn_ICU.uConverterToUCallbackCtxp, NULL, NULL, &uErrorCode);
      ucnv_setToUCallBack(streamInp->streamIn_ICU.uConverterTo, streamInp->streamIn_ICU.uConverterToUCallback, streamInp->streamIn_ICU.uConverterToUCallbackCtxp, NULL, NULL, &uErrorCode);
      if (U_FAILURE(uErrorCode)) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "ucnv_setToUCallBack(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	return STREAMIN_BOOL_FALSE;
      }
    }

    STREAMIN_TRACEX("ucnv_setFallback(%p, %d)", streamInp->streamIn_ICU.uConverterTo, fallback);
    ucnv_setFallback(streamInp->streamIn_ICU.uConverterTo, fallback);
  }

  byteBufSizel = UCNV_GET_MAX_BYTES_FOR_STRING(streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[bufIndexi], ucnv_getMaxCharSize(streamInp->streamIn_ICU.uConverterTo));
  target = malloc(byteBufSizel);
  if (target == NULL) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return STREAMIN_BOOL_FALSE;
  }
  origTarget = target;
  targetLimit  = target + byteBufSizel;

  do {

    uErrorCode = U_ZERO_ERROR;
    STREAMIN_TRACEX("ucnv_fromUnicode(%p, %p, %p, %p, %p, %p, %d, %p)", streamInp->streamIn_ICU.uConverterTo, &target, targetLimit, &source, sourceLimit, NULL, flushb, &uErrorCode);
    ucnv_fromUnicode(streamInp->streamIn_ICU.uConverterTo, &target, targetLimit, &source, sourceLimit, NULL, flushb, &uErrorCode);

    if (uErrorCode == U_BUFFER_OVERFLOW_ERROR) {
      /* Expand the current target buffer */
      /* Cross fingers this fits in a size_t */
      byteBufSizel *= 2;
      target = realloc(target, byteBufSizel);
      if (target == NULL) {
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
	/* Restore target for the free() */
	target = origTarget;
	break;
      }

      origTarget = target;
      targetLimit  = target + byteBufSizel;

    } else if (U_FAILURE(uErrorCode)) {

      UErrorCode localError = U_ZERO_ERROR;
      errorLength = (int8_t)sizeof(errorBytes);
      STREAMIN_TRACEX("ucnv_getInvalidChars(%p, %p, %p, %p)", streamInp->streamIn_ICU.uConverterTo, errorBytes, &errorLength, &localError);
      ucnv_getInvalidChars(streamInp->streamIn_ICU.uConverterTo, errorBytes, &errorLength, &localError);
      if (U_FAILURE(localError) || errorLength == 0) {
        errorLength = 1;
      }

      for (i = 0; i < errorLength; i++) {
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_INFO, "ucnv_fromUnicode(): %s: %02x%02x", u_errorName(uErrorCode), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i] >> 4), _streaminUtf8_ICU_nibbleToHex((uint8_t)errorBytes[i]));
      }

      rcb = STREAMIN_BOOL_FALSE;
      break;

    } else {

      stopb = STREAMIN_BOOL_TRUE;
    }

  } while (stopb == STREAMIN_BOOL_FALSE);

  if (rcb == STREAMIN_BOOL_TRUE) {
    *byteArraypp = origTarget;
    *bytesInBufferp = target - origTarget;
    /* Calculating the length can be expensive, so we do it only on-demand */
    if (lengthInBufferp != NULL) {
      /* Per def the length cannot exceed the size in bytes, that is limited to a size_t */
      /* so it is ok to typecast to size_t */
      *lengthInBufferp = (size_t) utext_nativeLength(streamInp->streamIn_ICU.utextp);
    }
  } else {
    if (target != NULL) {
      /* No need to assign to NULL, this is a local variable and we will return just after */
      free(target);
    }
  }

  return rcb;
}

/*******************************/
/* streamInUtf8_optionDefaultb */
/*******************************/
streamInBool_t streamInUtf8_optionDefaultb(streamInUtf8Option_t *streamInUtf8Optionp) {
  if (streamInUtf8Optionp == NULL) {
    return STREAMIN_BOOL_FALSE;
  }

  streamInUtf8Optionp->fromEncodings   = NULL;
  streamInUtf8Optionp->toEncodings     = NULL;
  streamInUtf8Optionp->ICUFromCallback = STREAMINUTF8OPTION_ICU_STOP;
  streamInUtf8Optionp->ICUFromFallback = STREAMIN_BOOL_FALSE;
  streamInUtf8Optionp->ICUToCallback   = STREAMINUTF8OPTION_ICU_STOP;
  streamInUtf8Optionp->ICUToFallback   = STREAMIN_BOOL_FALSE;
  streamInUtf8Optionp->userMarkSize    = 0;

  return STREAMIN_BOOL_TRUE;

}

/*****************************/
/* _streamInUtf8_ICU_optionb */
/*****************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInUtf8Optionp != NULL) {
      switch (streamInUtf8Optionp->ICUFromCallback) {
      case STREAMINUTF8OPTION_ICU_DEFAULT:
      case STREAMINUTF8OPTION_ICU_SUBSTITUTE:
      case STREAMINUTF8OPTION_ICU_SKIP:
      case STREAMINUTF8OPTION_ICU_STOP:
      case STREAMINUTF8OPTION_ICU_ESCAPE:
      case STREAMINUTF8OPTION_ICU_ESCAPE_ICU:
      case STREAMINUTF8OPTION_ICU_ESCAPE_JAVA:
      case STREAMINUTF8OPTION_ICU_ESCAPE_C:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML_HEX:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC:
      case STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE:
	break;
      default:
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Invalid ICUFromCallback %d at %s:%d", streamInUtf8Optionp->ICUFromCallback, __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
      }

      switch (streamInUtf8Optionp->ICUToCallback) {
      case STREAMINUTF8OPTION_ICU_DEFAULT:
      case STREAMINUTF8OPTION_ICU_SUBSTITUTE:
      case STREAMINUTF8OPTION_ICU_SKIP:
      case STREAMINUTF8OPTION_ICU_STOP:
      case STREAMINUTF8OPTION_ICU_ESCAPE:
      case STREAMINUTF8OPTION_ICU_ESCAPE_ICU:
      case STREAMINUTF8OPTION_ICU_ESCAPE_JAVA:
      case STREAMINUTF8OPTION_ICU_ESCAPE_C:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML_HEX:
      case STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC:
      case STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE:
	break;
      default:
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Invalid ICUToCallback %d at %s:%d", streamInUtf8Optionp->ICUToCallback, __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
      }
  }

  return rcb;
}

/*************************/
/* _streamInUtf8_optionb */
/*************************/
static C_INLINE streamInBool_t _streamInUtf8_optionb(streamIn_t *streamInp, streamInUtf8Option_t *streamInUtf8Optionp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;
  char          *toEncodings;

  if (streamInUtf8Optionp != NULL) {

    rcb = _streamInUtf8_ICU_optionb(streamInp, streamInUtf8Optionp);

    if (rcb == STREAMIN_BOOL_TRUE) {
      streamInp->streamInUtf8Option = *streamInUtf8Optionp;

      if (streamInUtf8Optionp->fromEncodings != NULL) {
	/* Keep a copy of declared input encoding */
	streamInp->streamInUtf8Option.fromEncodings = malloc(sizeof(char) * (strlen(streamInUtf8Optionp->fromEncodings) + 1));
	if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	  rcb = STREAMIN_BOOL_FALSE;
	} else {
	  strcpy(streamInp->streamInUtf8Option.fromEncodings, streamInUtf8Optionp->fromEncodings);
	}
      }
      toEncodings = streamInUtf8Optionp->toEncodings != NULL ? streamInUtf8Optionp->toEncodings : streamInp->streamInUtf8Option.fromEncodings;
      /* Keep a copy of wanted output encoding, which default to input's encoding */
      if ((toEncodings != NULL) && (toEncodings != _streamIn_defaultEncodings)) {
	streamInp->streamInUtf8Option.toEncodings = malloc(sizeof(char) * (strlen(toEncodings) + 1));
	if (streamInp->streamInUtf8Option.toEncodings == NULL) {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	  rcb = STREAMIN_BOOL_FALSE;
	} else {
	  strcpy(streamInp->streamInUtf8Option.toEncodings, toEncodings);
	}
      } else {
	streamInp->streamInUtf8Option.toEncodings = toEncodings;
      }

      if (streamInUtf8Optionp->userMarkSize > 0) {
        if ((streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl = (int64_t *) malloc(streamInUtf8Optionp->userMarkSize * sizeof(int64_t))) == NULL) {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	  rcb = STREAMIN_BOOL_FALSE;
        } else {
          if ((streamInp->streamIn_ICU.ucharUserMarkedOffsetl = (int64_t *) malloc(streamInUtf8Optionp->userMarkSize * sizeof(int64_t))) == NULL) {
            STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
            rcb = STREAMIN_BOOL_FALSE;
          }
        }
      }
    }
  }

  return rcb;
}

/**************************/
/* _streamInUtf8_destroyv */
/**************************/
static C_INLINE void _streamInUtf8_destroyv(streamIn_t *streamInp) {
  if (streamInp->utf8b == STREAMIN_BOOL_TRUE) {
    if (streamInp->streamInUtf8Option.fromEncodings != NULL) {
      if (streamInp->streamInUtf8Option.fromEncodings != _streamIn_defaultEncodings) {
        STREAMIN_FREE(streamInp->streamInUtf8Option.fromEncodings);
      }
    }
    if (streamInp->streamInUtf8Option.toEncodings != NULL) {
      if (streamInp->streamInUtf8Option.toEncodings != _streamIn_defaultEncodings) {
        STREAMIN_FREE(streamInp->streamInUtf8Option.toEncodings);
      }
    }
    _streamInUtf8_ICU_destroyv(streamInp);
  }
}

/******************************/
/* _streamInUtf8_ICU_destroyv */
/******************************/
static C_INLINE void _streamInUtf8_ICU_destroyv(streamIn_t *streamInp) {
  if (streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp != NULL) {
    STREAMIN_FREE(streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp);
  }
  if (streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl != NULL) {
    STREAMIN_FREE(streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl);
  }
  if (streamInp->streamIn_ICU.ucharUserMarkedOffsetl != NULL) {
    STREAMIN_FREE(streamInp->streamIn_ICU.ucharUserMarkedOffsetl);
  }
  if (streamInp->streamIn_ICU.ucharBufp != NULL) {
    STREAMIN_FREE(streamInp->streamIn_ICU.ucharBufp);
  }
  if (streamInp->streamIn_ICU.utextp != NULL) {
    STREAMIN_TRACEX("utext_close(%p)", streamInp->streamIn_ICU.utextp);
    utext_close(streamInp->streamIn_ICU.utextp);
  }
  if (streamInp->streamIn_ICU.uConverterFrom != NULL) {
    STREAMIN_TRACEX("ucnv_close(%p)", streamInp->streamIn_ICU.uConverterFrom);
    ucnv_close(streamInp->streamIn_ICU.uConverterFrom);
  }
  if (streamInp->streamIn_ICU.uConverterTo != NULL) {
    STREAMIN_TRACEX("ucnv_close(%p)", streamInp->streamIn_ICU.uConverterTo);
    ucnv_close(streamInp->streamIn_ICU.uConverterTo);
  }
#ifdef STREAMIN_SINGLE_TEST_APPLICATION_ONLY
  /* ICU recommendation is to NOT call this. This is done automatically at library unload */
  STREAMIN_TRACE0("u_cleanup()");
  u_cleanup();
#endif
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
streamInBool_t streamInUtf8_currenti(streamIn_t *streamInp, signed int *currentip) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  signed int     currenti;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_currenti(streamInp, &currenti);

  if (rcb == STREAMIN_BOOL_FALSE) {
    if (_streamIn_getBufferb(streamInp, streamInp->nByteBufi, NULL, NULL, NULL) == STREAMIN_BOOL_TRUE) {
      return streamInUtf8_currenti(streamInp, currentip);
    }
  }

  if (rcb == STREAMIN_BOOL_TRUE) {
    if (currentip != NULL) {
      *currentip = currenti;
    }
  }

  return rcb;
}

/******************************/
/* _streamInUtf8_ICU_currenti */
/******************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_currenti(streamIn_t *streamInp, signed int *currentip) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* A trace here would hog the output */
    /* STREAMIN_TRACEX("UTEXT_CURRENT32(%p)", streamInp->streamIn_ICU.utextp); */
    *currentip = UTEXT_CURRENT32(streamInp->streamIn_ICU.utextp);
  }

  return rcb;
}

/***************************/
/* _streamInUtf8_ICU_nexti */
/***************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_nexti(streamIn_t *streamInp, signed int *nextip) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return STREAMIN_BOOL_FALSE;
  } else {
    /* A trace here would hog the output */
    /* STREAMIN_TRACEX("UTEXT_NEXT32(%p)", streamInp->streamIn_ICU.utextp); */
    if ((*nextip = UTEXT_NEXT32(streamInp->streamIn_ICU.utextp)) == U_SENTINEL) {
      rcb = STREAMIN_BOOL_FALSE;
      streamInp->streamIn_ICU.eofb = STREAMIN_BOOL_TRUE;
    }
    STREAMIN_TRACEX("Got UTF-8 0x%lx '%c'%s, native index is now %lld, offset is now %lld",
                    (long) *nextip,
                    (u_isprint(*nextip) == TRUE) ? (char) *nextip : ' ',
                    (u_isprint(*nextip) == TRUE) ? "" : ((*nextip == U_SENTINEL) ? " U_SENTINEL" : " (not printable)"),
                    (long long) UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp),
                    (long long) (UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp) * sizeof(UChar)));
  }

  return rcb;
}

/*********************/
/* streamInUtf8_eofb */
/*********************/
streamInBool_t streamInUtf8_eofb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_eofb(streamInp);

  return rcb;
}

/**************************/
/* _streamInUtf8_ICU_eofb */
/**************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_eofb(streamIn_t *streamInp) {
  return streamInp->streamIn_ICU.eofb;
}

/**********************/
/* streamInUtf8_markb */
/**********************/
streamInBool_t streamInUtf8_markb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_markb(streamInp);

  return rcb;
}

/***************************/
/* _streamInUtf8_ICU_markb */
/***************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_markb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharMarkedNativeIndexl = UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp);
    streamInp->streamIn_ICU.ucharMarkedOffsetl = streamInp->streamIn_ICU.ucharMarkedNativeIndexl * sizeof(UChar);
    STREAMIN_TRACEX("Mark index %lld, offset %lld", (long long) streamInp->streamIn_ICU.ucharMarkedNativeIndexl, (long long) streamInp->streamIn_ICU.ucharMarkedOffsetl);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/**************************/
/* streamInUtf8_userMarkb */
/**************************/
streamInBool_t streamInUtf8_userMarkb(streamIn_t *streamInp, size_t indexl) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_userMarkb(streamInp, indexl);

  return rcb;
}

/*******************************/
/* _streamInUtf8_ICU_userMarkb */
/*******************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_userMarkb(streamIn_t *streamInp, size_t indexl) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl] = UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp);
    streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl] = streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl] * sizeof(UChar);
    STREAMIN_TRACEX("userMark No %lld index %lld, offset %lld", (long long) indexl, (long long) streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl], (long long) streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl]);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/*************************************/
/* streamInUtf8_Utf16InfoFromMarkedb */
/*************************************/
streamInBool_t streamInUtf8_Utf16InfoFromMarkedb(streamIn_t *streamInp, const void **pp, size_t *byteLengthlp, size_t *lengthlp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_Utf16InfoFromMarkedb(streamInp, pp, byteLengthlp, lengthlp);

  return rcb;
}

/******************************************/
/* _streamInUtf8_ICU_Utf16InfoFromMarkedb */
/******************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromMarkedb(streamIn_t *streamInp, const void **pp, size_t *byteLengthlp, size_t *lengthlp) {
  return
    (streamInp->streamIn_ICU.utextp == NULL)
    ?
    STREAMIN_BOOL_FALSE
    :
    _streamInUtf8_ICU_Utf16InfoFromIndexesb(streamInp, pp, byteLengthlp, lengthlp, streamInp->streamIn_ICU.ucharMarkedNativeIndexl, UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp));
}

/*****************************************/
/* streamInUtf8_Utf16InfoFromUserMarkedb */
/*****************************************/
streamInBool_t streamInUtf8_Utf16InfoFromUserMarkedb(streamIn_t *streamInp, size_t indexl, const void **pp, size_t *byteLengthlp, size_t *lengthlp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return rcb;
  }

  rcb = _streamInUtf8_ICU_Utf16InfoFromUserMarkedb(streamInp, indexl, pp, byteLengthlp, lengthlp);

  return rcb;
}

/**********************************************/
/* _streamInUtf8_ICU_Utf16InfoFromUserMarkedb */
/**********************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromUserMarkedb(streamIn_t *streamInp, size_t indexl, const void **pp, size_t *byteLengthlp, size_t *lengthlp) {
  return
    (streamInp->streamIn_ICU.utextp == NULL)
    ?
    STREAMIN_BOOL_FALSE
    :
    _streamInUtf8_ICU_Utf16InfoFromIndexesb(streamInp, pp, byteLengthlp, lengthlp, streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl], UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp));
}

/*******************************************/
/* _streamInUtf8_ICU_Utf16InfoFromIndexesb */
/*******************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_Utf16InfoFromIndexesb(streamIn_t *streamInp, const void **pp, size_t *byteLengthlp, size_t *lengthlp, int64_t index1l, int64_t index2l) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  UChar         *ucharBufp;
  int32_t        srcLength;

  if (streamInp->streamIn_ICU.utextp != NULL) {
    srcLength = (int32_t) (index2l - index1l);
    /* If overflow, index2Verifl will not be equal to index2 */
    if ((index1l + srcLength) != index2l) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "integer overflow at %s:%d", __FILE__, __LINE__);
    } else {
      ucharBufp = streamInp->streamIn_ICU.ucharBufp + index1l;  /* positionl is in units of UChar */

      if (pp != NULL) {
	*pp = (const void *) ucharBufp;
      }
      if (byteLengthlp != NULL) {
	/* No overflow check until I code it */
	*byteLengthlp = (size_t) (srcLength * sizeof(UChar));
      }
      if (lengthlp != NULL) {
	*lengthlp = u_countChar32(ucharBufp, srcLength);
      }
      rcb = STREAMIN_BOOL_TRUE;
    }
  }

  return rcb;
}

/******************************/
/* streamInUtf8_markPreviousb */
/******************************/
streamInBool_t streamInUtf8_markPreviousb(streamIn_t *streamInp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_markPreviousb(streamInp);
}

/***********************************/
/* _streamInUtf8_ICU_markPreviousb */
/***********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_markPreviousb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharMarkedNativeIndexl = utext_getPreviousNativeIndex(streamInp->streamIn_ICU.utextp);
    streamInp->streamIn_ICU.ucharMarkedOffsetl = streamInp->streamIn_ICU.ucharMarkedNativeIndexl * sizeof(UChar);
    STREAMIN_TRACEX("markPrevious index %lld, offset %lld", (long long) streamInp->streamIn_ICU.ucharMarkedNativeIndexl, (long long) streamInp->streamIn_ICU.ucharMarkedOffsetl);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/**********************************/
/* streamInUtf8_userMarkPreviousb */
/**********************************/
streamInBool_t streamInUtf8_userMarkPreviousb(streamIn_t *streamInp, size_t indexl) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_userMarkPreviousb(streamInp, indexl);
}

/***********************************/
/* _streamInUtf8_ICU_userMarkPreviousb */
/***********************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_userMarkPreviousb(streamIn_t *streamInp, size_t indexl) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This give the index in the native format of the text below - we know this is UChar */
    streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl] = utext_getPreviousNativeIndex(streamInp->streamIn_ICU.utextp);
    streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl] = streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl] * sizeof(UChar);
    STREAMIN_TRACEX("userMarkPrevious No %lld index %lld, offset %lld", (long long) indexl, (long long) streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl], (long long) streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl]);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/***********************************/
/* streamInUtf8_currentFromMarkedb */
/***********************************/
streamInBool_t streamInUtf8_currentFromMarkedb(streamIn_t *streamInp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_currentFromMarkedb(streamInp);
}

/****************************************/
/* _streamInUtf8_ICU_currentFromMarkedb */
/****************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromMarkedb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This makes the marked character the current character */
    UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharMarkedNativeIndexl);
    STREAMIN_TRACEX("currentFromMarked index %lld, offset %lld as current",
                    (long long) streamInp->streamIn_ICU.ucharMarkedNativeIndexl,
                    (long long) streamInp->streamIn_ICU.ucharMarkedOffsetl);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/***********************************/
/* streamInUtf8_extractFromMarkedb */
/***********************************/
streamInBool_t streamInUtf8_extractFromMarkedb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_extractFromMarkedb(streamInp, destsp, byteLengthlp, lengthlp);
}

/****************************************/
/* _streamInUtf8_ICU_extractFromMarkedb */
/****************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromMarkedb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp) {

  return
    (streamInp->streamIn_ICU.utextp == NULL)
    ?
    STREAMIN_BOOL_FALSE
    :
    _streamInUtf8_ICU_extractFromIndexesb(streamInp, destsp, byteLengthlp, lengthlp, streamInp->streamIn_ICU.ucharMarkedNativeIndexl, UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp));
}

/***************************************/
/* streamInUtf8_currentFromUserMarkedb */
/***************************************/
streamInBool_t streamInUtf8_currentFromUserMarkedb(streamIn_t *streamInp, size_t indexl) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_currentFromUserMarkedb(streamInp, indexl);
}

/********************************************/
/* _streamInUtf8_ICU_currentFromUserMarkedb */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_currentFromUserMarkedb(streamIn_t *streamInp, size_t indexl) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return rcb;
  } else {
    /* This makes the user-marked character the current character */
    UTEXT_SETNATIVEINDEX(streamInp->streamIn_ICU.utextp, streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl]);
    STREAMIN_TRACEX("currentFromUserMarked No %lld index %lld, offset %lld as current",
                    (long long) indexl,
                    (long long) streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl],
                    (long long) streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl]);
    rcb = STREAMIN_BOOL_TRUE;
  }

  return rcb;
}

/***************************************/
/* streamInUtf8_extractFromUserMarkedb */
/***************************************/
streamInBool_t streamInUtf8_extractFromUserMarkedb(streamIn_t *streamInp, size_t indexl, char **destsp, size_t *byteLengthlp, size_t *lengthlp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_extractFromUserMarkedb(streamInp, indexl, destsp, byteLengthlp, lengthlp);
}

/********************************************/
/* _streamInUtf8_ICU_extractFromUserMarkedb */
/********************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromUserMarkedb(streamIn_t *streamInp, size_t indexl, char **destsp, size_t *byteLengthlp, size_t *lengthlp) {

  return
    (streamInp->streamIn_ICU.utextp == NULL)
    ?
    STREAMIN_BOOL_FALSE
    :
    _streamInUtf8_ICU_extractFromIndexesb(streamInp, destsp, byteLengthlp, lengthlp, streamInp->streamIn_ICU.ucharUserMarkedNativeIndexl[indexl], UTEXT_GETNATIVEINDEX(streamInp->streamIn_ICU.utextp));
}

/*****************************************/
/* _streamInUtf8_ICU_extractFromIndexesb */
/*****************************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_extractFromIndexesb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp, int64_t index1l, int64_t index2l) {
  streamInBool_t rcb = STREAMIN_BOOL_FALSE;
  char          *dests;
  int32_t        destLengthl = 0;
  UChar         *ucharBufp;
  UErrorCode     uErrorCode;
  int32_t        srcLength;

  if (streamInp->streamIn_ICU.utextp != NULL) {
    srcLength = (int32_t) (index2l - index1l);
    /* If overflow, index2Verifl will not be equal to index2 */
    if ((index1l + srcLength) != index2l) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "integer overflow at %s:%d", __FILE__, __LINE__);
    } else {
      ucharBufp = streamInp->streamIn_ICU.ucharBufp + index1l;  /* positionl is in units of UChar */
      /* Per-def our utext is a (UChar *). So there is no need to pass via utext_extract to get UChars. We can use native indexes * sizeof(Uchar) directly */
      /* Pre-figthing */
      uErrorCode = U_ZERO_ERROR;
      u_strToUTF8(NULL, 0, &destLengthl, ucharBufp, srcLength, &uErrorCode);
      if (uErrorCode != U_BUFFER_OVERFLOW_ERROR) {
	if (U_FAILURE(uErrorCode)) {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "u_strToUTF8(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	} else {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "u_strToUTF8(): uErrorCode is %lld != U_BUFFER_OVERFLOW_ERROR at %s:%d", (long long) uErrorCode, __FILE__, __LINE__);
	}
      } else {
	destLengthl++;   /* For the null byte */
	dests = malloc(destLengthl * sizeof(char));
	if (dests == NULL) {
	  STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
	} else {
	  uErrorCode = U_ZERO_ERROR;
	  u_strToUTF8(dests, destLengthl, NULL, ucharBufp, srcLength, &uErrorCode);
	  if (U_FAILURE(uErrorCode)) {
	    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "u_strToUTF8(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
	    free(dests);
	  } else {
            if (byteLengthlp != NULL) {
              *byteLengthlp = (size_t) destLengthl;
            }
            if (lengthlp != NULL) {
              *lengthlp = u_countChar32(ucharBufp, srcLength);
            }
            if (destsp != NULL) {
              *destsp = dests;
            } else {
              free(dests);
            }
	    rcb = STREAMIN_BOOL_TRUE;
	  }
        }
      }
    }
  }

  return rcb;
}

/**********************/
/* streamInUtf8_doneb */
/**********************/
streamInBool_t streamInUtf8_doneb(streamIn_t *streamInp) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_doneb(streamInp);
}

/***************************/
/* _streamInUtf8_ICU_doneb */
/***************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_doneb(streamIn_t *streamInp) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;
  size_t         i;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return STREAMIN_BOOL_FALSE;
  } else {
    /* We search for a byte buffer that maps exactly to ucharMarkedOffsetl */
    /* STREAMIN_TRACEX("Searching for marked offset %ld", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    for (i = 0; i < streamInp->nByteBufi; i++) {
      if (streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[i] == streamInp->streamIn_ICU.ucharMarkedOffsetl) {
	break;
      }
    }
    if (i < streamInp->nByteBufi) {
      /* Got one */
      rcb = _streamIn_doneBufferb(streamInp, i);
    }
  }

  return rcb;
}

/**************************/
/* streamInUtf8_userDoneb */
/**************************/
streamInBool_t streamInUtf8_userDoneb(streamIn_t *streamInp, size_t indexl) {

  if (streamInp == NULL || streamInp->utf8b == STREAMIN_BOOL_FALSE) {
    return STREAMIN_BOOL_FALSE;
  }

  return _streamInUtf8_ICU_userDoneb(streamInp, indexl);
}

/*******************************/
/* _streamInUtf8_ICU_userDoneb */
/*******************************/
static C_INLINE streamInBool_t _streamInUtf8_ICU_userDoneb(streamIn_t *streamInp, size_t indexl) {
  streamInBool_t rcb = STREAMIN_BOOL_TRUE;
  size_t         i;

  if (streamInp->streamIn_ICU.utextp == NULL) {
    return STREAMIN_BOOL_FALSE;
  } else {
    /* We search for a byte buffer that maps exactly to ucharMarkedOffsetl */
    /* STREAMIN_TRACEX("Searching for marked offset %ld", streamInp->streamIn_ICU.ucharMarkedOffsetl); */
    for (i = 0; i < streamInp->nByteBufi; i++) {
      if (streamInp->streamIn_ICU.byteBuf2UCharByteLengthlp[i] == streamInp->streamIn_ICU.ucharUserMarkedOffsetl[indexl]) {
	break;
      }
    }
    if (i < streamInp->nByteBufi) {
      /* Got one */
      rcb = _streamIn_doneBufferb(streamInp, i);
    }
  }

  return rcb;
}

/***************************************/
/* streamInUtf8_newFromFileNamep */
/***************************************/
streamInFromFileName_t *streamInUtf8_newFromFileNamep(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, const char *filename) {
  int fd;

  if (filename == NULL) {
    return NULL;
  }

  fd = STREAMIN_OPEN(filename, O_RDONLY
#ifdef O_BINARY
	    |O_BINARY
#endif
	    );
  if (fd < 0) {
    return NULL;
  }

  return streamInUtf8_newFromFileDescriptorp(streamInOptionp, streamInUtf8Optionp, fd);
}

/**********************************************/
/* streamInUtf8_streamInFromFileName_destroyv */
/**********************************************/
void streamInUtf8_streamInFromFileName_destroyv(streamInFromFileName_t **streamInFromFileNamepp) {
  streamInUtf8_streamInFromFileDescriptor_destroyv(streamInFromFileNamepp);
}

/***************************************/
/* streamInUtf8_newFromFileDescriptorp */
/***************************************/
streamInFromFileDescriptor_t *streamInUtf8_newFromFileDescriptorp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, int fd) {
  streamInUtf8Option_t          streamInUtf8Option;
  streamInOption_t              streamInOption;
  streamInFromFileDescriptor_t *streamInFromFileDescriptorp;

  if (streamInOptionp == NULL) {
    if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInOptionp = &streamInOption;
  }
  if (streamInUtf8Optionp == NULL) {
    if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInUtf8Optionp = &streamInUtf8Option;
  }

  streamInFromFileDescriptorp = malloc(sizeof(streamInFromFileDescriptor_t));
  if (streamInFromFileDescriptorp == NULL) {
    return NULL;
  }
  streamInFromFileDescriptorp->fd = fd;

  /* We explicitely overwrite the read callback, unless user already provided one */
  if (streamInOptionp->readCallbackp == NULL) {
    streamInOptionp->readCallbackp = &_streamIn_readFromFileDescriptorCallback;
    streamInOptionp->readCallbackDatavp = streamInFromFileDescriptorp;
  }

  streamInFromFileDescriptorp->streamInp = streamInUtf8_newp(streamInOptionp, streamInUtf8Optionp);
  if (streamInFromFileDescriptorp->streamInp == NULL) {
    free(streamInFromFileDescriptorp);
    return NULL;
  }

  return streamInFromFileDescriptorp;
}

/********************************************/
/* _streamIn_readFromFileDescriptorCallback */
/********************************************/
static C_INLINE streamInBool_t _streamIn_readFromFileDescriptorCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  streamInFromFileDescriptor_t *streamInFromFileDescriptorp = (streamInFromFileDescriptor_t *) datavp;
  streamIn_t                   *streamInp = streamInFromFileDescriptorp->streamInp;
  int                           n;
  streamInBool_t                rcb = STREAMIN_BOOL_TRUE;

  STREAMIN_TRACEX("%s(%d, %p, %lld)", STREAMIN_READ_STRING, streamInFromFileDescriptorp->fd, byteArrayp, (long long) wantedBytesi);
  n = STREAMIN_READ(streamInFromFileDescriptorp->fd, byteArrayp, wantedBytesi);
  if (n <= 0) {
    if (n < 0) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "read from file descriptor %d: %s at %s:%d", streamInFromFileDescriptorp->fd, strerror(errno), __FILE__, __LINE__);
      rcb = STREAMIN_BOOL_FALSE;
    }
    n = 0;
  }

  *gotBytesip = n;

  return rcb;
}

/****************************************************/
/* streamInUtf8_streamInFromFileDescriptor_destroyv */
/****************************************************/
void streamInUtf8_streamInFromFileDescriptor_destroyv(streamInFromFileDescriptor_t **streamInFromFileDescriptorpp) {
  streamInFromFileDescriptor_t *streamInFromFileDescriptorp;

  if (streamInFromFileDescriptorpp != NULL) {
    streamInFromFileDescriptorp = *streamInFromFileDescriptorpp;
    if (streamInFromFileDescriptorp != NULL) {
      streamIn_destroyv(&(streamInFromFileDescriptorp->streamInp));
      free(streamInFromFileDescriptorp);
      *streamInFromFileDescriptorpp = NULL;
    }
  }
}

/*******************************/
/* streamInUtf8_newFromBufferp */
/*******************************/
streamInFromBuffer_t *streamInUtf8_newFromBufferp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, const char *bufp, size_t bufferByteLengthl) {
  streamInUtf8Option_t  streamInUtf8Option;
  streamInOption_t      streamInOption;
  streamInFromBuffer_t *streamInFromBufferp;

  if (streamInOptionp == NULL) {
    if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInOptionp = &streamInOption;
  }
  if (streamInUtf8Optionp == NULL) {
    if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInUtf8Optionp = &streamInUtf8Option;
  }

  streamInFromBufferp = malloc(sizeof(streamInFromBuffer_t));
  if (streamInFromBufferp == NULL) {
    return NULL;
  }
  streamInFromBufferp->bufp = bufp;
  streamInFromBufferp->bufferByteLengthl = bufferByteLengthl;
  streamInFromBufferp->firstb = STREAMIN_BOOL_TRUE;

  /* We explicitely overwrite the read callback, unless user already provided one */
  if (streamInOptionp->readCallbackp == NULL) {
    streamInOptionp->readCallbackp = &_streamIn_readFromBufferCallback;
    streamInOptionp->readCallbackDatavp = streamInFromBufferp;
  }

  streamInFromBufferp->streamInp = streamInUtf8_newp(streamInOptionp, streamInUtf8Optionp);
  if (streamInFromBufferp->streamInp == NULL) {
    free(streamInFromBufferp);
    return NULL;
  }

  return streamInFromBufferp;
}

/************************************/
/* _streamIn_readFromBufferCallback */
/************************************/
static C_INLINE streamInBool_t _streamIn_readFromBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  streamInFromBuffer_t *streamInFromBufferp = (streamInFromBuffer_t *) datavp;

  if (streamInFromBufferp->firstb == STREAMIN_BOOL_TRUE) {
    *gotBytesip = streamInFromBufferp->bufferByteLengthl;
    *charManagedArrayp = (char*) streamInFromBufferp->bufp;
    streamInFromBufferp->firstb = STREAMIN_BOOL_FALSE;
  } else {
    *gotBytesip = 0;
  }

  return STREAMIN_BOOL_TRUE;
}

/********************************************/
/* streamInUtf8_streamInFromBuffer_destroyv */
/********************************************/
void streamInUtf8_streamInFromBuffer_destroyv(streamInFromBuffer_t **streamInFromBufferpp) {
  streamInFromBuffer_t *streamInFromBufferp;

  if (streamInFromBufferpp != NULL) {
    streamInFromBufferp = *streamInFromBufferpp;
    if (streamInFromBufferp != NULL) {
      streamIn_destroyv(&(streamInFromBufferp->streamInp));
      free(streamInFromBufferp);
      *streamInFromBufferpp = NULL;
    }
  }
}

/*****************************/
/* streamInUtf8_newFromFILEp */
/*****************************/
streamInFromFILE_t *streamInUtf8_newFromFILEp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, FILE *fp) {
  streamInUtf8Option_t  streamInUtf8Option;
  streamInOption_t      streamInOption;
  streamInFromFILE_t   *streamInFromFILEp;

  if (streamInOptionp == NULL) {
    if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInOptionp = &streamInOption;
  }
  if (streamInUtf8Optionp == NULL) {
    if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInUtf8Optionp = &streamInUtf8Option;
  }

  streamInFromFILEp = malloc(sizeof(streamInFromFILE_t));
  if (streamInFromFILEp == NULL) {
    return NULL;
  }
  streamInFromFILEp->fp = fp;

  /* We explicitely overwrite the read callback, unless user already provided one */
  if (streamInOptionp->readCallbackp == NULL) {
    streamInOptionp->readCallbackp = &_streamIn_readFromFILECallback;
    streamInOptionp->readCallbackDatavp = streamInFromFILEp;
  }

  streamInFromFILEp->streamInp = streamInUtf8_newp(streamInOptionp, streamInUtf8Optionp);
  if (streamInFromFILEp->streamInp == NULL) {
    free(streamInFromFILEp);
    return NULL;
  }

  return streamInFromFILEp;
}

/********************************************/
/* _streamIn_readFromFILECallback */
/********************************************/
static C_INLINE streamInBool_t _streamIn_readFromFILECallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  streamInFromFILE_t *streamInFromFILEp = (streamInFromFILE_t *) datavp;
  streamIn_t         *streamInp = streamInFromFILEp->streamInp;
  size_t              n;
  streamInBool_t      rcb = STREAMIN_BOOL_TRUE;

  STREAMIN_TRACEX("fread(%p, %lld, 1, %p)", byteArrayp, (long long) wantedBytesi, streamInFromFILEp->fp);
  n = fread(byteArrayp, wantedBytesi, 1, streamInFromFILEp->fp);
  if (n <= 0) {
    STREAMIN_TRACEX("ferror(%p)", streamInFromFILEp->fp);
    if (ferror(streamInFromFILEp->fp) != 0) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "read from FILE %p: %s at %s:%d", streamInFromFILEp->fp, strerror(errno), __FILE__, __LINE__);
      rcb = STREAMIN_BOOL_FALSE;
    } else {
      STREAMIN_TRACEX("feof(%p)", streamInFromFILEp->fp);
      if (feof(streamInFromFILEp->fp) == 0) {
	STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "read from FILE %p: Got %lld bytes but neither feof() nor ferror() are setted at %s:%d", streamInFromFILEp->fp, (long long) n, __FILE__, __LINE__);
	rcb = STREAMIN_BOOL_FALSE;
      }
    }
    n = 0;
  }

  *gotBytesip = n;

  return rcb;
}

/******************************************/
/* streamInUtf8_streamInFromFILE_destroyv */
/******************************************/
void streamInUtf8_streamInFromFILE_destroyv(streamInFromFILE_t **streamInFromFILEpp) {
  streamInFromFILE_t *streamInFromFILEp;

  if (streamInFromFILEpp != NULL) {
    streamInFromFILEp = *streamInFromFILEpp;
    if (streamInFromFILEp != NULL) {
      streamIn_destroyv(&(streamInFromFILEp->streamInp));
      free(streamInFromFILEp);
      *streamInFromFILEpp = NULL;
    }
  }
}

/***************************************/
/* streamInUtf8_newFromSocketp */
/***************************************/
streamInFromSocket_t *streamInUtf8_newFromSocketp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp,
                                                  int fd, int timeoutInMilliseconds,
                                                  streamIn_SocketGetBlockingMode_t socketGetBlockingModeCallbackp, void *socketGetBlockingModeDatavp,
                                                  streamIn_SocketSetBlockingMode_t socketSetBlockingModeCallbackp, void *socketSetBlockingModeDatavp,
                                                  streamIn_SocketErr_t             socketErrCallbackp,             void *socketErrDatavp
                                                  ) {
  streamInUtf8Option_t  streamInUtf8Option;
  streamInOption_t      streamInOption;
  streamInFromSocket_t *streamInFromSocketp;

  if (socketGetBlockingModeCallbackp == NULL || socketSetBlockingModeCallbackp == NULL) {
    return NULL;
  }

  if (streamInOptionp == NULL) {
    if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInOptionp = &streamInOption;
  }
  if (streamInUtf8Optionp == NULL) {
    if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
      return NULL;
    }
    streamInUtf8Optionp = &streamInUtf8Option;
  }

  streamInFromSocketp = malloc(sizeof(streamInFromSocket_t));
  if (streamInFromSocketp == NULL) {
    return NULL;
  }
  streamInFromSocketp->fd                             = fd;
  streamInFromSocketp->timeoutInMilliseconds          = timeoutInMilliseconds;
  streamInFromSocketp->socketGetBlockingModeCallbackp = socketGetBlockingModeCallbackp;
  streamInFromSocketp->socketGetBlockingModeDatavp    = socketGetBlockingModeDatavp;
  streamInFromSocketp->socketSetBlockingModeCallbackp = socketSetBlockingModeCallbackp;
  streamInFromSocketp->socketSetBlockingModeDatavp    = socketSetBlockingModeDatavp;
  streamInFromSocketp->socketErrCallbackp             = socketErrCallbackp;
  streamInFromSocketp->socketErrDatavp                = socketErrDatavp;

  /* We explicitely overwrite the read callback, unless user already provided one */
  if (streamInOptionp->readCallbackp == NULL) {
    streamInOptionp->readCallbackp = &_streamIn_readFromSocketCallback;
    streamInOptionp->readCallbackDatavp = streamInFromSocketp;
  }

  streamInFromSocketp->streamInp = streamInUtf8_newp(streamInOptionp, streamInUtf8Optionp);
  if (streamInFromSocketp->streamInp == NULL) {
    free(streamInFromSocketp);
    return NULL;
  }

  return streamInFromSocketp;
}

/************************************/
/* _streamIn_readFromSocketCallback */
/************************************/
/* Loosely based on http://developerweb.net/viewtopic.php?id=2933 */
static C_INLINE streamInBool_t _streamIn_readFromSocketCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  streamInFromSocket_t         *streamInFromSocketp = (streamInFromSocket_t *) datavp;
  streamIn_t                   *streamInp = streamInFromSocketp->streamInp;
  streamInBool_t                rcb = STREAMIN_BOOL_TRUE;
  fd_set                        readset;
  streamInBool_t                blockingModeb;
  struct timeval                tv;
#ifdef _WIN32
  int                           result;
#else
  ssize_t                       result;
#endif

  /* Initialize the set */
  FD_ZERO(&readset);
  FD_SET(streamInFromSocketp->fd, &readset);
   
  if (streamInFromSocketp->timeoutInMilliseconds > 0) {
    /* Initialize time out struct */
    tv.tv_sec = 0;
    tv.tv_usec = streamInFromSocketp->timeoutInMilliseconds * 1000;
    STREAMIN_TRACEX("select(%d, %p, NULL, NULL, %p)", streamInFromSocketp->fd + 1, &readset, &tv);
    result = select(streamInFromSocketp->fd + 1, &readset, NULL, NULL, &tv);
  } else {
    STREAMIN_TRACEX("select(%d, %p, NULL, NULL, NULL)", streamInFromSocketp->fd + 1, &readset);
    result = select(streamInFromSocketp->fd + 1, &readset, NULL, NULL, NULL);
  }

  /* Check status */
  if (result < 0) {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "select error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
    if (streamInFromSocketp->socketErrCallbackp != NULL) {
      streamInFromSocketp->socketErrCallbackp(streamInFromSocketp->socketErrDatavp, streamInFromSocketp->fd);
    }
    rcb = STREAMIN_BOOL_FALSE;
  } else if (result > 0) {
    if (! FD_ISSET(streamInFromSocketp->fd, &readset)) {
      STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "FD_ISSET error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
      if (streamInFromSocketp->socketErrCallbackp != NULL) {
        streamInFromSocketp->socketErrCallbackp(streamInFromSocketp->socketErrDatavp, streamInFromSocketp->fd);
      }
      rcb = STREAMIN_BOOL_FALSE;
    } else {
      /* Get non-blocking mode */
      if (streamInFromSocketp->socketGetBlockingModeCallbackp(streamInFromSocketp->socketGetBlockingModeDatavp, streamInFromSocketp->fd, &blockingModeb) == STREAMIN_BOOL_FALSE) {
        STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Getting blocking mode error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
        rcb = STREAMIN_BOOL_FALSE;
      } else {
        /* Set eventually non-blocking mode */
        if ((blockingModeb == STREAMIN_BOOL_TRUE) && streamInFromSocketp->socketSetBlockingModeCallbackp(streamInFromSocketp->socketSetBlockingModeDatavp, streamInFromSocketp->fd, STREAMIN_BOOL_FALSE) == STREAMIN_BOOL_FALSE) {
          STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Setting non-blocking mode error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
          rcb = STREAMIN_BOOL_FALSE;
        } else {
          /* Receive */
          STREAMIN_TRACEX("recv(%d, %p, %lld, 0)", streamInFromSocketp->fd, byteArrayp, (long long) wantedBytesi, 0);
          result = recv(streamInFromSocketp->fd, byteArrayp, wantedBytesi, 0);
          /* Always restore eventually blocking mode */
          if ((blockingModeb == STREAMIN_BOOL_TRUE) && streamInFromSocketp->socketSetBlockingModeCallbackp(streamInFromSocketp->socketSetBlockingModeDatavp, streamInFromSocketp->fd, STREAMIN_BOOL_TRUE) == STREAMIN_BOOL_FALSE) {
            STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "Restoring blocking mode error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
            rcb = STREAMIN_BOOL_FALSE;
          } else {
            if (result < 0) {
              STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "recv error for file descriptor %d: %s at %s:%d", streamInFromSocketp->fd, __FILE__, __LINE__);
              if (streamInFromSocketp->socketErrCallbackp != NULL) {
                streamInFromSocketp->socketErrCallbackp(streamInFromSocketp->socketErrDatavp, streamInFromSocketp->fd);
              }
              rcb = STREAMIN_BOOL_FALSE;
            } else {
              *gotBytesip = result;
            }
          }
        }
      }
    }
  } else {
    STREAMIN_LOGX(MARPAXML_LOGLEVEL_ERROR, "select timeout after %lld milliseconds from file descriptor %d at %s:%d", (long long) streamInFromSocketp->timeoutInMilliseconds, streamInFromSocketp->fd, __FILE__, __LINE__);
    if (streamInFromSocketp->socketErrCallbackp != NULL) {
      streamInFromSocketp->socketErrCallbackp(streamInFromSocketp->socketErrDatavp, streamInFromSocketp->fd);
    }
    rcb = STREAMIN_BOOL_FALSE;
  }

  return rcb;
}

/********************************************/
/* streamInUtf8_streamInFromSocket_destroyv */
/********************************************/
void streamInUtf8_streamInFromSocket_destroyv(streamInFromSocket_t **streamInFromSocketpp) {
  streamInFromSocket_t *streamInFromSocketp;

  if (streamInFromSocketpp != NULL) {
    streamInFromSocketp = *streamInFromSocketpp;
    if (streamInFromSocketp != NULL) {
      streamIn_destroyv(&(streamInFromSocketp->streamInp));
      free(streamInFromSocketp);
      *streamInFromSocketpp = NULL;
    }
  }
}

