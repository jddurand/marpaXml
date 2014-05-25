#ifndef MARPAXML_SAX_INPUTSOURCE_H
#define MARPAXML_SAX_INPUTSOURCE_H

#include "marpaXml/String.h"
#include "marpaXml/InputStream.h"
#include "marpaXml/Reader.h"

typedef struct marpaXml_SAX_InputSource {
  void                    (*setPublicId)(marpaXml_String_t *publicId);
  marpaXml_String_t      *(*getPublicId)();
  void                    (*setSystemId)(marpaXml_String_t *systemId);
  marpaXml_String_t      *(*getSystemId)();
  void                    (*setByteStream)(marpaXml_InputStream_t *byteStream);
  marpaXml_InputStream_t *(*getByteStream)();
  void                    (*setEncoding)(marpaXml_String_t *encoding);
  marpaXml_String_t      *(*getEncoding)();
  void                    (*setCharacterStream)(marpaXml_Reader_t *characterStream);
  marpaXml_Reader_t      *(*getCharacterStream)();
} *marpaXml_SAX_InputSource_t;

marpaXml_SAX_InputSource_t *marpaXml_SAX_InputSource_new();
marpaXml_SAX_InputSource_t *marpaXml_SAX_InputSource_new_SystemId(marpaXml_String_t *systemId);
marpaXml_SAX_InputSource_t *marpaXml_SAX_InputSource_new_inputStream(marpaXml_InputStream_t *byteStream);
marpaXml_SAX_InputSource_t *marpaXml_SAX_InputSource_new_reader(marpaXml_Reader_t *characterStream);
void                        marpaXml_SAX_InputSource_destroy(marpaXml_SAX_InputSource_t *this);

#endif /* MARPAXML_SAX_INPUTSOURCE_H */
