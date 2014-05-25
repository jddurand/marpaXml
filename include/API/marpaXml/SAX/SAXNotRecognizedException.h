#ifndef MARPAXML_SAX_SAXNOTRECOGNIZEDEXCEPTION_H
#define MARPAXML_SAX_SAXNOTRECOGNIZEDEXCEPTION_H

#include "marpaXml/String.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_SAXNotRecognizedException *marpaXml_SAX_SAXNotRecognizedException_t;

marpaXml_SAX_SAXNotRecognizedException_t *marpaXml_SAX_SAXNotRecognizedException_new();
marpaXml_SAX_SAXNotRecognizedException_t *marpaXml_SAX_SAXNotRecognizedException_new_byMessage(marpaXml_String_t *message);
void                                      marpaXml_SAX_SAXNotRecognizedException_destroy(marpaXml_SAX_SAXNotRecognizedException_t *this);

#endif /* MARPAXML_SAX_SAXNOTRECOGNIZEDEXCEPTION_H */
