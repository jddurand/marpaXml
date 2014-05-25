#ifndef MARPAXML_SAX_ERRORHANDLER_H
#define MARPAXML_SAX_ERRORHANDLER_H

#include "marpaXml/SAX/SAXParseException.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_ErrorHandler {
  void (*warning)(marpaXml_SAX_SAXParseException_t *exception, marpaXml_SAX_SAXException_t *SAXException);
  void (*error)(marpaXml_SAX_SAXParseException_t exception, marpaXml_SAX_SAXException_t *SAXException);
  void (*fatalError)(marpaXml_SAX_SAXParseException_t exception, marpaXml_SAX_SAXException_t *SAXException);
} *marpaXml_SAX_ErrorHandler_t;

marpaXml_SAX_ErrorHandler_t *marpaXml_SAX_ErrorHandler_new();
void                         marpaXml_SAX_ErrorHandler_destroy(marpaXml_SAX_ErrorHandler_t *this);

#endif /* MARPAXML_SAX_ERRORHANDLER_H */
