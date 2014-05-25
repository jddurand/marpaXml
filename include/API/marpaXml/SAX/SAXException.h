#ifndef MARPAXML_SAX_SAXEXCEPTION_H
#define MARPAXML_SAX_SAXEXCEPTION_H

#include "marpaXml/String.h"
#include "marpaXml/Exception.h"

typedef struct marpaXml_SAX_SAXException {
  marpaXml_String_t    *(*getMessage)();
  marpaXml_Exception_t *(*getException)();
  marpaXml_String_t    *(*toString)();
} *marpaXml_SAX_SAXException_t;

marpaXml_SAX_SAXException_t *marpaXml_SAX_SAXException_new();
marpaXml_SAX_SAXException_t *marpaXml_SAX_SAXException_new_byMessage(marpaXml_String_t *message);
marpaXml_SAX_SAXException_t *marpaXml_SAX_SAXException_new_byException(marpaXml_Exception_t *exception);
marpaXml_SAX_SAXException_t *marpaXml_SAX_SAXException_new_byMessage_byException(marpaXml_String_t *message, marpaXml_Exception_t *exception);
void                         marpaXml_SAX_SAXException_destroy(marpaXml_SAX_SAXException_t *this);

#endif /* MARPAXML_SAX_SAXEXCEPTION_H */
