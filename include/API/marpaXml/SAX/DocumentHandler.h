#ifndef MARPAXML_SAX_DOCUMENTHANDLER_H
#define MARPAXML_SAX_DOCUMENTHANDLER_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/Locator.h"
#include "marpaXml/SAX/AttributeList.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_DocumentHandler {
  void (*setDocumentLocator)(marpaXml_SAX_Locator_t *locator); 
  void (*startDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*endDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*startElement)(marpaXml_String_t *name, marpaXml_SAX_AttributeList_t *atts, marpaXml_SAX_SAXException_t *SAXException);
  void (*endElement)(marpaXml_String_t *name, marpaXml_SAX_SAXException_t *SAXException);
  void (*characters)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*ignorableWhitespace)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*processingInstruction)(marpaXml_String_t *target, marpaXml_String_t *data, marpaXml_SAX_SAXException_t *SAXException);
} *marpaXml_SAX_DocumentHandler_t;

marpaXml_SAX_DocumentHandler_t *marpaXml_SAX_DocumentHandler_new();
void                            marpaXml_SAX_DocumentHandler_destroy(marpaXml_SAX_DocumentHandler_t *this);

#endif /* MARPAXML_SAX_DOCUMENTHANDLER_H */
