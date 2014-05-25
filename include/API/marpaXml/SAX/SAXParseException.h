#ifndef MARPAXML_SAX_SAXPARSEEXCEPTION_H
#define MARPAXML_SAX_SAXPARSEEXCEPTION_H

#include "marpaXml/String.h"
#include "marpaXml/Exception.h"
#include "marpaXml/SAX/Locator.h"

typedef struct marpaXml_SAX_SAXParseException {
  marpaXml_String_t *(*getPublicId)();
  marpaXml_String_t *(*getsystemId)();
  int                (*getLineNumber)();
  int                (*getColumnNumber)();
} *marpaXml_SAX_SAXParseException_t;

marpaXml_SAX_SAXParseException_t *marpaXml_SAX_SAXParseException_new();
marpaXml_SAX_SAXParseException_t *marpaXml_SAX_SAXParseException_new_byMessage_byLocator(marpaXml_String_t *message, marpaXml_SAX_Locator_t *locator);
marpaXml_SAX_SAXParseException_t *marpaXml_SAX_SAXParseException_new_byMessage_byLocator_byException(marpaXml_String_t *message, marpaXml_SAX_Locator_t *locator, marpaXml_Exception_t *e);
marpaXml_SAX_SAXParseException_t *marpaXml_SAX_SAXParseException_new_byMessage_byPublicId_bySystemId_byLineNumber_byColumnNumber(marpaXml_String_t *message, marpaXml_String_t *publicId, marpaXml_String_t *systemId, int lineNumber, int columnNumber);
marpaXml_SAX_SAXParseException_t *marpaXml_SAX_SAXParseException_new_byMessage_byPublicId_bySystemId_byLineNumber_byColumnNumber_byException(marpaXml_String_t *message, marpaXml_String_t *publicId, marpaXml_String_t *systemId, int lineNumber, int columnNumber, marpaXml_Exception_t *e);
void                              marpaXml_SAX_SAXParseException_destroy(marpaXml_SAX_SAXParseException_t *this);

#endif /* MARPAXML_SAX_SAXPARSEEXCEPTION_H */
