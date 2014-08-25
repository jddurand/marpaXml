#ifndef MARPAXML_STRING_H
#define MARPAXML_STRING_H

#include <stddef.h>

#include "marpaXml/cplus.h"
#include "marpaXml/boolean.h"
#include "API/marpaXml/log.h"

CLASS_TYPEDEF(marpaXml_String);

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

typedef struct marpaXml_String_Option {
  marpaXml_String_Option_ICU_t marpaXml_String_Option_ICU;
  marpaXml_boolean_t           fallback;
  marpaXmlLogLevel_t           logLevelWantedi;
  marpaXmlLogCallback_t        logCallbackp;
  void                        *logCallbackDatavp;
} *marpaXml_String_Option_t;

typedef struct marpaXml_String_Context *marpaXml_String_Context_t;

CLASS(marpaXml_String)
  marpaXml_String_Context_t   _context;
METHODS
  marpaXml_String_t           marpaXml_String_new(marpaXml_String_Option_t option);       /* Creates an empty string */
  marpaXml_String_t           marpaXml_String_newFromUTF8(char *utf8, marpaXml_String_Option_t option);  /* Assumes a VALID UTF-8 null terminated string */
  marpaXml_String_t           marpaXml_String_newFromUTF8AndByteLength(char *utf8, size_t byteLength, marpaXml_String_Option_t option); /* Ditto */
  marpaXml_String_t           marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t option);
  char                       *marpaXml_String_getUtf8(marpaXml_String_t this);
  size_t                      marpaXml_String_getByteLength(marpaXml_String_t this);
  size_t                      marpaXml_String_getLength(marpaXml_String_t this);
  char                       *marpaXml_String_encode(marpaXml_String_t this, size_t *byteLengthp, size_t *lengthp, char *charset, marpaXml_String_Option_t option);  /* Convert to any charset: user will have to free it */
  void                        marpaXml_String_free(marpaXml_String_t *thisp);
END_CLASS

#endif /* MARPAXML_STRING_H */
