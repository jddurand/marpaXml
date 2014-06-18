#ifndef MARPAXML_INTERNAL_STREAMIN_H
#define MARPAXML_INTERNAL_STREAMIN_H


/****************************************************************************************/
/* This library will automatically handle buffers of **bytes**. Up to the user          */
/* application to know how many bytes he want, and their meaning                        */
/* It works in two different ways, exclusive each other: byte or UTF8.                  */
/* If you start with byte level, i.e. streamIn_newp(), only byte methods will work.     */
/* If you start with utf8 level, i.e. streamInUtf8_newp(), only utf8 methods will work. */
/* The only exceptions are:                                                             */
/* - streamIn_optionDefaultb()                                                          */
/* - streamIn_optionb()                                                                 */
/* - streamIn_destroyv()                                                                */
/****************************************************************************************/

#include "internal/config.h"
#include <stddef.h>               /*  size_t definition */

/*************************
   Opaque object pointer
 *************************/
typedef struct streamIn streamIn_t;

/*************************
   Macros/Enums
 *************************/
typedef enum streamInBool {
  STREAMIN_BOOL_FALSE =  0,
  STREAMIN_BOOL_TRUE  =  1
} streamInBool_t;

typedef enum streamInLogLevel {
  STREAMIN_LOGLEVEL_TRACE = 0,
  STREAMIN_LOGLEVEL_DEBUG,
  STREAMIN_LOGLEVEL_INFO,
  STREAMIN_LOGLEVEL_NOTICE,
  STREAMIN_LOGLEVEL_WARNING,
  STREAMIN_LOGLEVEL_ERROR,
  STREAMIN_LOGLEVEL_CRITICAL,
  STREAMIN_LOGLEVEL_ALERT,
  STREAMIN_LOGLEVEL_EMERGENCY
} streamInLogLevel_t;

/*************************
   Callback types
 *************************/
typedef void           (*streamInLogCallback_t)(void *datavp, streamIn_t *streamInp, streamInLogLevel_t logLeveli, const char *msgs);

/* Free the content of a managed buffer */
typedef streamInBool_t (*streamInBufFreeCallback_t)(void *datavp, char *charManagedArrayp);

/* Read data */
/* If user application is filling *charManagedArraypp then it is highly recommended to set bufFreeCallbackp if this is an allocated area */
typedef streamInBool_t (*streamInReadCallback_t)  (void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *charArrayp, char **charManagedArraypp);

/*************************
   Options
 *************************/
typedef struct streamInOption {
  size_t                       bufMaxSizei;                   /* Defaut:  1M. Optional.                       */
  streamInLogLevel_t           logLevelWantedi;               /* Default: STREAMIN_LOGLEVEL_WARNING           */
  streamInLogCallback_t        logCallbackp;                  /* Default: Internal routine logging to STDERR. */
  void                        *logCallbackUserDatap;          /* Default: NULL. Optional.                     */
  streamInReadCallback_t       readCallbackp;                 /* Default: NULL. Can Must be non-NULL.         */
  void                        *readCallbackUserDatap;         /* Default: NULL.                               */
  streamInBufFreeCallback_t    bufFreeCallbackp;              /* Default: NULL.                               */
  void                        *bufFreeCallbackUserDatap;      /* Default: NULL.                               */
} streamInOption_t;

typedef enum streamInUtf8Option_Converter {
  /* Note this will FAIL to compile if neither ICU nor ICONV is available. We are not */
  /* gonna check this case because we require that at least one of them is seen when */
  /* compiling. */
#ifdef HAVE_ICU
   STREAMINUTF8OPTION_CONVERTER_ICU, 
#endif
#ifdef HAVE_ICONV
   STREAMINUTF8OPTION_CONVERTER_ICONV, 
#endif
} streamInUtf8Option_Converter_t;

#ifdef HAVE_ICU
typedef enum streamInUtf8Option_ICUCallback {
  STREAMINUTF8OPTION_ICUCALLBACK_SUBSTITUTE,
  STREAMINUTF8OPTION_ICUCALLBACK_SKIP,
  STREAMINUTF8OPTION_ICUCALLBACK_STOP,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_ICU,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_JAVA,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_C,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_HEX,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_XML_DEC,
  STREAMINUTF8OPTION_ICUCALLBACK_ESCAPE_UNICODE
} streamInUtf8Option_ICUCallback_t;
#endif

typedef struct streamInUtf8Option {
  char                            *fromEncodings;     /* Input encoding.       Default: NULL */
  char                            *toEncodings;       /* Output encoding.      Default: NULL */
  streamInUtf8Option_Converter_t   converteri;        /* Prefered converter.   Default: ICU if available, else ICONV */
#ifdef HAVE_ICU
  streamInUtf8Option_ICUCallback_t ICUFromCallback;   /* From-Callback method. Default: STREAMINUTF8OPTION_ICUCALLBACK_STOP */
  streamInBool_t                   ICUFromFallback;   /* From-fallback.        Default: STREAMIN_BOOL_FALSE */
  streamInUtf8Option_ICUCallback_t ICUToCallback;     /* To-Callback method.   Default: STREAMINUTF8OPTION_ICUCALLBACK_STOP */
  streamInBool_t                   ICUToFallback;     /* To-fallback.          Default: STREAMIN_BOOL_FALSE */
#endif
} streamInUtf8Option_t;

/******************************************
   Common to byte and char oriented methods
*******************************************/
streamInBool_t streamIn_optionDefaultb(streamInOption_t *streamInOptionp);
streamInBool_t streamIn_optionb       (streamIn_t *streamInp, streamInOption_t *streamInOptionp);
void           streamIn_destroyv(streamIn_t **streamInpp);

/*************************
   Byte-oriented methods
 *************************/
streamIn_t    *streamIn_newp          (streamInOption_t *streamInOptionp);
/* streamIn_getBufferb: special case with negative values: -1 means last buffer, -2 means buffer before last buffer and so on */
streamInBool_t streamIn_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);
/* streamIn_doneBufferb: special case with negative values: -1 means last buffer, -2 means buffer before last buffer and so on */
streamInBool_t streamIn_doneBufferb(streamIn_t *streamInp, int indexBufferi);
streamInBool_t streamIn_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);


/************************************************************************************************************************************
   UTF-8 oriented methods : all boolean methods will return STREAMIN_BOOL_FALSE is the called constructor was not streamInUtf8_newp()
*************************************************************************************************************************************/
streamIn_t    *streamInUtf8_newp          (streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp);
streamInBool_t streamInUtf8_optionDefaultb(streamInUtf8Option_t *streamInUtf8Optionp);
/* Options at the utf8 level cannot be changed after streamInUtf8_newp() */
streamInBool_t streamInUtf8_fromEncodings (streamIn_t *streamInp, char **fromEncodingsp);                           /* Get input encoding */
streamInBool_t streamInUtf8_toEncodings   (streamIn_t *streamInp, char **toEncodingsp);                             /* Get output encoding */
signed int     streamInUtf8_currenti      (streamIn_t *streamInp);                                                  /* Get current utf8. -1 means EOF.  */
signed int     streamInUtf8_nexti         (streamIn_t *streamInp);                                                  /* Get next utf8. Moves current by one. -1 means EOF.  */
streamInBool_t streamInUtf8_markb         (streamIn_t *streamInp);                                                  /* Mark current utf8 */
streamInBool_t streamInUtf8_doneMarkedb   (streamIn_t *streamInp);                                                  /* Say marked utf8 is done */

#endif /* MARPAXML_INTERNAL_STREAMIN_H */
