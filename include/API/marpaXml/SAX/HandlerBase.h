#ifndef MARPAXML_SAX_HANDLERBASE_H
#define MARPAXML_SAX_HANDLERBASE_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/SAXException.h"
#include "marpaXml/SAX/SAXParseException.h"
#include "marpaXml/SAX/Locator.h"

typedef struct marpaXml_SAX_HandlerBase {
  marpaXml_SAX_InputSource_t *(*resolveEntity)(marpaXml_String_t *publicId, marpaXml_String_t *systemId, marpaXml_SAX_SAXException_t *SAXException);
  void (*notationDecl)(marpaXml_String_t *name, marpaXml_String_t *publicId, marpaXml_String_t *systemId);
  void (*unparsedEntityDecl)(marpaXml_String_t *name, marpaXml_String_t *publicId, marpaXml_String_t *systemId, marpaXml_String_t *notationName);
  void (*setDocumentLocator)(marpaXml_SAX_Locator_t *locator);
  void (*startDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*endDocument)(marpaXml_SAX_SAXException_t *SAXException);
  void (*startElement)(marpaXml_String_t *name, marpaXml_SAX_AttributeList_t *attributes, marpaXml_SAX_SAXException_t *SAXException);
  void (*endElement)(marpaXml_String_t *name, marpaXml_SAX_SAXException_t *SAXException);
  void (*characters)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*ignorableWhitespace)(char *ch, int start, int length, marpaXml_SAX_SAXException_t *SAXException);
  void (*processingInstruction)(marpaXml_String_t *target, marpaXml_String_t *data, marpaXml_SAX_SAXException_t *SAXException);
  void (*warning)(marpaXml_SAX_SAXParseException_t *e, marpaXml_SAX_SAXException_t *SAXException);
  void (*error)(marpaXml_SAX_SAXParseException_t *e, marpaXml_SAX_SAXException_t *SAXException);
  void (*fatalError)(marpaXml_SAX_SAXParseException_t *e, marpaXml_SAX_SAXException_t *SAXException);
} *marpaXml_SAX_HandlerBase_t;

marpaXml_SAX_HandlerBase_t *marpaXml_SAX_HandlerBase_new();
void                        marpaXml_SAX_HandlerBase_destroy(marpaXml_SAX_HandlerBase_t *this);

#endif /* MARPAXML_SAX_HANDLERBASE_H */
