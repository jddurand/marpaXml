#ifndef MARPAXML_SAX_CONTENTHANDLER_H
#define MARPAXML_SAX_CONTENTHANDLER_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/Locator.h"
#include "marpaXml/SAX/Attributes.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_ContentHandler {
  void (*setDocumentLocator)(marpaXml_SAX_Locator_t *locator); 
  void (*startDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*endDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*startPrefixMapping)(marpaXml_String_t *prefix, marpaXml_String_t *uri, marpaXml_SAX_SAXException_t *SAXException);
  void (*endPrefixMapping)(marpaXml_String_t *prefix, marpaXml_SAX_SAXException_t *SAXException);
  void (*startElement)(marpaXml_String_t *uri, marpaXml_String_t *localName, marpaXml_String_t *qName, marpaXml_SAX_Attributes_t *atts, marpaXml_SAX_SAXException_t *SAXException);
  void (*endElement)(marpaXml_String_t *uri, marpaXml_String_t *localName, marpaXml_String_t *qName, marpaXml_SAX_SAXException_t *SAXException);
  void (*characters)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*ignorableWhitespace)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*processingInstruction)(marpaXml_String_t *target, marpaXml_String_t *data, marpaXml_SAX_SAXException_t *SAXException);
  void (*skippedEntity)(marpaXml_String_t name, marpaXml_SAX_SAXException_t *SAXException);
} *marpaXml_SAX_ContentHandler_t;

marpaXml_SAX_ContentHandler_t *marpaXml_SAX_ContentHandler_new();
void                           marpaXml_SAX_ContentHandler_destroy(marpaXml_SAX_ContentHandler_t *this);

#endif /* MARPAXML_SAX_CONTENTHANDLER_H */
