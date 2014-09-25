#ifndef MARPAXML_STRING_H
#define MARPAXML_STRING_H

#include <stddef.h>

#include "marpaXml/boolean.h"
#include "marpaXml/log.h"

/* Please refer to ICU documentation for the different meanings */
typedef enum marpaXml_String_Option_ICU {
  MARPAXML_STRING_OPTION_ICU_DEFAULT,
  MARPAXML_STRING_OPTION_ICU_SUBSTITUTE,
  MARPAXML_STRING_OPTION_ICU_SKIP,
  MARPAXML_STRING_OPTION_ICU_STOP,
  MARPAXML_STRING_OPTION_ICU_ESCAPE,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_ICU,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_JAVA,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_C,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_XML,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_XML_HEX,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_XML_DEC,
  MARPAXML_STRING_OPTION_ICU_ESCAPE_UNICODE
} marpaXml_String_Option_ICU_t;

typedef struct marpaXml_String_ConvertOption {
  marpaXml_String_Option_ICU_t marpaXml_String_Option_ICU;
  marpaXml_boolean_t           fallback;
} marpaXml_String_ConvertOption_t;

typedef struct marpaXml_String_Option {
  marpaXml_String_Option_ICU_t marpaXml_String_Option_ICU;
  marpaXml_boolean_t           fallback;
  marpaXmlLog_Option_t         logOption;
} marpaXml_String_Option_t;

typedef struct marpaXml_String marpaXml_String_t;

/* Constructors */
marpaXml_String_t  *marpaXml_String_new(marpaXml_String_Option_t *optionp);       /* Creates an empty string */
marpaXml_String_t  *marpaXml_String_newFromUTF8(char *utf8, marpaXml_String_Option_t *optionp);  /* Assumes a maybe valid UTF-8 null terminated string */
marpaXml_String_t  *marpaXml_String_newFromUTF8AndByteLength(char *utf8, size_t byteLength, marpaXml_String_Option_t *optionp); /* May not end with a null byte */
marpaXml_String_t  *marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t *optionp); /* Ditto with charset's null */
marpaXml_String_t  *marpaXml_String_newFromValidUTF8(char *utf8, size_t byteLength, size_t length, marpaXml_String_Option_t *optionp); /* Assumes a VALID UTF-8, not necessarly null terminated. quickest but unsafe call. Caller have to be 100% sure. byteLength must be > 0. Size will be computed it argument length is <= 0. */

/* Methods */
char               *marpaXml_String_getUtf8(marpaXml_String_t *thisp);               /* Always a null terminated UTF-8 string */
size_t              marpaXml_String_getUtf8ByteLength(marpaXml_String_t *thisp);     /* Number of bytes, including null byte */
size_t              marpaXml_String_getLength(marpaXml_String_t *thisp);             /* Number of characters (minus eventual null byte) */
marpaXml_boolean_t  marpaXml_String_getNullByteAddedb(marpaXml_String_t *thisp);     /* if marpaXml_true, a null byte has been added in internal representation */
/* ... Convert to any charset: user will have to free it. If input did NOT have a null character at the end, neither will the output */
char               *marpaXml_String_encode(marpaXml_String_t *thisp, size_t *byteLengthp, size_t *lengthp, char *charset, marpaXml_String_Option_t *optionp);

/* Tools */
marpaXml_String_t  *marpaXml_String_clone(marpaXml_String_t *stringp);                     /* clone */
marpaXml_String_t  *marpaXml_String_cat(marpaXml_String_t *dstp, marpaXml_String_t *srcp); /* cat */

/* Destructor */
void                marpaXml_String_free(marpaXml_String_t **thispp);

#endif /* MARPAXML_STRING_H */
