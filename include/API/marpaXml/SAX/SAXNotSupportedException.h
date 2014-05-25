#ifndef MARPAXML_SAX_SAXNOTSUPPORTEDEXCEPTION_H
#define MARPAXML_SAX_SAXNOTSUPPORTEDEXCEPTION_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_SAXNotSupportedException *marpaXml_SAX_SAXNotSupportedException_t;

marpaXml_SAX_SAXNotSupportedException_t *marpaXml_SAX_SAXNotSupportedException_new();
marpaXml_SAX_SAXNotSupportedException_t *marpaXml_SAX_SAXNotSupportedException_new_byMessage(marpaXml_String_t *message);
void                                     marpaXml_SAX_SAXNotSupportedException_destroy(marpaXml_SAX_SAXNotSupportedException_t *this);

#endif /* MARPAXML_SAX_SAXNOTSUPPORTEDEXCEPTION_H */
