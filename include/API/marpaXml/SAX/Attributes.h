#ifndef MARPAXML_SAX_ATTRIBUTES_H
#define MARPAXML_SAX_ATTRIBUTES_H

#include "marpaXml/String.h"

typedef struct marpaXml_SAX_Attributes {
  int               (*getLength)();
  marpaXml_String_t (*getURI)(int index);
  marpaXml_String_t (*getLocalName)(int index);
  marpaXml_String_t (*getQName)(int index);
  marpaXml_String_t (*getType)(int index);
  marpaXml_String_t (*getValue)(int index);

  int               (*getIndex_byNamespace)(marpaXml_String_t *uri, marpaXml_String_t *localName);
  int               (*getIndex_byQName)    (marpaXml_String_t *qName);

  marpaXml_String_t (*getType_byNamespace)(marpaXml_String_t *uri, marpaXml_String_t *localName);
  marpaXml_String_t (*getType_byQName)    (marpaXml_String_t *qName);

  marpaXml_String_t (*getValue_byNamespace)(marpaXml_String_t *uri, marpaXml_String_t *localName);
  marpaXml_String_t (*getValue_byQName)    (marpaXml_String_t *qName);
} *marpaXml_SAX_Attributes_t;

marpaXml_SAX_Attributes_t *marpaXml_SAX_Attributes_new();
void                       marpaXml_SAX_Attributes_destroy(marpaXml_SAX_Attributes_t *this);

#endif /* MARPAXML_SAX_ATTRIBUTES_H */
