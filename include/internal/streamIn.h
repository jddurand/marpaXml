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
/*                                                                                      */
/* It is assumed that an int is at least 32bits                                         */
/****************************************************************************************/

#include <stdio.h>
#include <stddef.h>               /*  size_t definition */
#include "config.h"
#include "API/marpaXml/log.h"

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

/*************************
   Callback types
 *************************/
/* Free the content of a managed buffer */
typedef streamInBool_t (*streamInBufFreeCallback_t)(void *datavp, char *charManagedArrayp);

/* Read data */
/* If user application is filling *charManagedArraypp then it is highly recommended to set bufFreeCallbackp if this is an allocated area: */
/* This will be a buffer that the user declares that it can manage himself. In such a case streamIn will call bufFreeCallbackp */
/* IF the streamInOption.allBuffersAreManagedByUserb is STREAMIN_BOOL_TRUE, then byteArrayp will be NULLP, leaving only the only to use a managed buffer */
/* IF the streamInOption.allBuffersAreManagedByUserb is STREAMIN_BOOL_FALSE, this library will always pre-allocate size in byteArrayp */
typedef streamInBool_t (*streamInReadCallback_t)  (void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **byteManagedArraypp);

/*************************
   Options
 *************************/
typedef struct streamInOption {
  size_t                       bufMaxSizei;                   /* Defaut:  1M. Optional.                       */
  streamInBool_t               allBuffersAreManagedByUserb;   /* Default: STREAMIN_BOOL_FALSE                 */
  marpaXmlLogLevel_t           logLevelWantedi;               /* Default: MARPAXML_LOGLEVEL_WARNING           */
  marpaXmlLogCallback_t        logCallbackp;                  /* Default: marpaXmlLog_defaultLogCallback()    */
  void                        *logCallbackDatavp;             /* Default: NULL                                */
  streamInReadCallback_t       readCallbackp;                 /* Default: NULL.                               */
  void                        *readCallbackDatavp;            /* Default: NULL.                               */
  streamInBufFreeCallback_t    bufFreeCallbackp;              /* Default: NULL.                               */
  void                        *bufFreeCallbackDatavp;         /* Default: NULL.                               */
} streamInOption_t;

typedef enum streamInUtf8Option_ICU {
  STREAMINUTF8OPTION_ICU_DEFAULT,
  STREAMINUTF8OPTION_ICU_SUBSTITUTE,
  STREAMINUTF8OPTION_ICU_SKIP,
  STREAMINUTF8OPTION_ICU_STOP,
  STREAMINUTF8OPTION_ICU_ESCAPE,
  STREAMINUTF8OPTION_ICU_ESCAPE_ICU,
  STREAMINUTF8OPTION_ICU_ESCAPE_JAVA,
  STREAMINUTF8OPTION_ICU_ESCAPE_C,
  STREAMINUTF8OPTION_ICU_ESCAPE_XML,
  STREAMINUTF8OPTION_ICU_ESCAPE_XML_HEX,
  STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC,
  STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE
} streamInUtf8Option_ICU_t;

typedef struct streamInUtf8Option {
  char                            *fromEncodings;     /* Input encoding.       Default: NULL */
  char                            *toEncodings;       /* Output encoding.      Default: NULL */
  streamInUtf8Option_ICU_t         ICUFromCallback;   /* Input -> Unicode.     Default: STREAMINUTF8OPTION_ICU_DEFAULT */
  streamInBool_t                   ICUFromFallback;   /* Input fallback ?      Default: STREAMIN_BOOL_FALSE */
  streamInUtf8Option_ICU_t         ICUToCallback;     /* Unicode -> Output.    Default: STREAMINUTF8OPTION_ICU_DEFAULT */
  streamInBool_t                   ICUToFallback;     /* Output fallback ?     Default: STREAMIN_BOOL_FALSE */
} streamInUtf8Option_t;

typedef struct streamInFromFileDescriptor {
  int            fd;
  streamIn_t    *streamInp;
} streamInFromFileDescriptor_t;
typedef streamInFromFileDescriptor_t streamInFromFileName_t;

typedef struct streamInFromFILE {
  FILE          *fp;
  streamIn_t    *streamInp;
} streamInFromFILE_t;

typedef struct streamInFromSocket {
  int            fd;
  int            timeoutInMilliseconds;
  streamIn_t    *streamInp;
} streamInFromSocket_t;

typedef struct streamInFromBuffer {
  const char    *bufp;
  size_t         bufferByteLengthl;
  streamIn_t    *streamInp;
  streamInBool_t firstb;
} streamInFromBuffer_t;

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
streamInBool_t streamIn_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp);
/* streamIn_doneBufferb: special case with negative values: -1 means last buffer, -2 means buffer before last buffer and so on */
streamInBool_t streamIn_doneBufferb(streamIn_t *streamInp, int indexBufferi);
streamInBool_t streamIn_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp);


/************************************************************************************************************************************
   UTF-8 oriented methods : all boolean methods will return STREAMIN_BOOL_FALSE is the called constructor was not streamInUtf8_newp()
*************************************************************************************************************************************/
streamIn_t    *streamInUtf8_newp              (streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp);
streamInBool_t streamInUtf8_optionDefaultb    (streamInUtf8Option_t *streamInUtf8Optionp);
/* Options at the utf8 level cannot be changed after streamInUtf8_newp() */
streamInBool_t streamInUtf8_currenti          (streamIn_t *streamInp, signed int *currentip);                           /* Get current utf8 */
streamInBool_t streamInUtf8_nexti             (streamIn_t *streamInp, signed int *nextip);                              /* Get next utf8. Moves current by one.  */
streamInBool_t streamInUtf8_markb             (streamIn_t *streamInp);                                                  /* Mark current utf8 */
streamInBool_t streamInUtf8_markPreviousb     (streamIn_t *streamInp);                                                  /* Mark previous utf8 */
streamInBool_t streamInUtf8_doneb             (streamIn_t *streamInp);                                                  /* Say marked utf8 is done */
/* Behaviour is undefined if you use streamInUtf8_doneb() between calls to mark and markToCurrent. Let's say it will very likely crash */
streamInBool_t streamInUtf8_currentFromMarkedb(streamIn_t *streamInp);                                                  /* Set marked utf8 as current */
/* extract an UTF-8 string from marked position. All parameters but streamInp can be NULL. If destsp is non-NULL, *destsp string is guaranteed to be NULL terminated */
/* If destsp is non-NULL and output is ok, caller is responsible to call free() on *destsp */
streamInBool_t streamInUtf8_extractFromMarkedb(streamIn_t *streamInp, char **destsp, size_t *byteLengthlp, size_t *lengthlp);

/* These methods are the only way to get output using another encoding but the original. The caller WILL HAVE TO CALL free(byteArrayp) himself. */
/* It is very important to remember that, here, buffer indexes in output map EXACTLY buffer indexes in input. */
/* Therefore it can very well be a read buffer is not entirely encoded. */
/* In the extreme case, it could be that a method like streamInUnicode_nextBufferb return STREAMIN_BOOL_TRUE but with ZERO in number of bytes of number of characters */
streamInBool_t streamInUnicode_fromEncodings  (streamIn_t *streamInp, char **fromEncodingsp);                           /* Get input encoding */
streamInBool_t streamInUnicode_toEncodings    (streamIn_t *streamInp, char **toEncodingsp);                             /* Get output encoding */
streamInBool_t streamInUnicode_nextBufferb    (streamIn_t *streamInp, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp);
/* Take care: *lengthInBufferp is the NATIVE length, i.e. the null character, if any, is counted. This is not strlen. */
streamInBool_t streamInUnicode_getBufferb     (streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **byteArraypp, size_t *bytesInBufferp, size_t *lengthInBufferp);
streamInBool_t streamInUnicode_doneBufferb    (streamIn_t *streamInp, int indexBufferi);

/************************************************************************************************************************************
   Generic helpers
   In all these helpers, readCallback is overwriten to a default version, unless user already
   putted another function pointer.
   I personnaly had a use only of UTF8 stuff, look to the source and you will see how it is easy
   to do it with buffer-oriented methods.
*************************************************************************************************************************************/
streamInFromFileDescriptor_t *streamInUtf8_newFromFileDescriptorp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, int fd);
void                          streamInUtf8_streamInFromFileDescriptor_destroyv(streamInFromFileDescriptor_t **streamInFromFileDescriptorpp);

streamInFromFileName_t       *streamInUtf8_newFromFileNamep(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, const char *filename);
void                          streamInUtf8_streamInFromFileName_destroyv(streamInFromFileName_t **streamInFromFileNamepp);

streamInFromFILE_t           *streamInUtf8_newFromFILEp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, FILE *fp);
void                          streamInUtf8_streamInFromFILE_destroyv(streamInFromFILE_t **streamInFromFILEpp);

streamInFromBuffer_t         *streamInUtf8_newFromBufferp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, const char *bufp, size_t bufferByteLengthl);
void                          streamInUtf8_streamInFromBuffer_destroyv(streamInFromBuffer_t **streamInFromBufferpp);

/* give a negative value for timeoutInMilliseconds to have no timeout */
streamInFromSocket_t         *streamInUtf8_newFromSocketp(streamInOption_t *streamInOptionp, streamInUtf8Option_t *streamInUtf8Optionp, int fd, int timeoutInMilliseconds);
void                          streamInUtf8_streamInFromSocket_destroyv(streamInFromSocket_t **streamInFromSocketpp);

#endif /* MARPAXML_INTERNAL_STREAMIN_H */
