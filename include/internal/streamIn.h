#ifndef MARPAXML_INTERNAL_STREAMIN_H
#define MARPAXML_INTERNAL_STREAMIN_H

/*                                                                                  */
/* This library will automatically handle buffers of **bytes**. Up to the user      */
/* application to know how many bytes he want, and their meaning                    */
/*                                                                                  */
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

/*************************
   Byte-oriented methods
 *************************/
streamIn_t    *streamIn_newp          (streamInOption_t *streamInOptionp);

streamInBool_t streamIn_optionDefaultb(streamInOption_t *streamInOptionp);
streamInBool_t streamIn_optionb       (streamIn_t *streamInp, streamInOption_t *streamInOptionp);

/* As a special case, -1 means last buffer, -2 means buffer before last buffer and so on */
streamInBool_t streamIn_getBufferb(streamIn_t *streamInp, int indexBufferi, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);
streamInBool_t streamIn_doneBufferb(streamIn_t *streamInp, int indexBufferi);
streamInBool_t streamIn_nextBufferb(streamIn_t *streamInp, size_t *indexBufferip, char **charArraypp, size_t *bytesInBufferp);

void           streamIn_destroyv(streamIn_t **streamInpp);

/*************************
   Char-oriented methods : will always return UTF-8, i.e. an unsigned int
 *************************/
streamIn_t    *streamInChar_newp    (streamInOption_t *streamInOptionp, char *encodings); /* With encoding hint. Otherwise will autodectect */
streamInBool_t streamInChar_mark32  (streamIn_t *streamInp);                    /* Start iterator at current char */
streamInBool_t streamInChar_next32  (streamIn_t *streamInp, unsigned int *ip);  /* Get next char  */
streamInBool_t streamInChar_rewind32(streamIn_t *streamInp);                    /* Go back to mark32 */

#endif /* MARPAXML_INTERNAL_STREAMIN_H */
