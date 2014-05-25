#ifndef MARPAXML_SAX_DTDHANDLER_H
#define MARPAXML_SAX_DTDHANDLER_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_DTDHandler {
  void (*notationDecl)(marpaXml_String_t *name, marpaXml_String_t *publicId, marpaXml_String_t *systemId, marpaXml_SAX_SAXException_t *SAXException);
  void (*unparsedEntityDecl)(marpaXml_String_t *name, marpaXml_String_t *publicId, marpaXml_String_t *systemId, marpaXml_String_t *notationName, marpaXml_SAX_SAXException_t *SAXException);
} *marpaXml_SAX_DTDHandler_t;

marpaXml_SAX_DTDHandler_t *marpaXml_SAX_DTDHandler_new();
void                       marpaXml_SAX_DTDHandler_destroy(marpaXml_SAX_DTDHandler_t *this);

#endif /* MARPAXML_SAX_DTDHANDLER_H */
