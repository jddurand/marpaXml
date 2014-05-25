#ifndef MARPAXML_SAX_LOCATOR_H
#define MARPAXML_SAX_LOCATOR_H

typedef struct marpaXml_SAX_Locator {
  marpaXml_String_t *(*getPublicId)();
  marpaXml_String_t *(*getSystemId)();
  int                (*getLineNumber)();
  int                (*getColumnNumber)();
} *marpaXml_SAX_Locator_t;

marpaXml_SAX_Locator_t *marpaXml_SAX_Locator_new();
void                    marpaXml_SAX_Locator_destroy(marpaXml_SAX_Locator_t *this);

#endif /* MARPAXML_SAX_LOCATOR_H */
