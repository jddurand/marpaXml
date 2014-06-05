#ifndef MARPAXML_SAX_ATTRIBUTELIST_H
#define MARPAXML_SAX_ATTRIBUTELIST_H

#include "marpaXml/String.h"

typedef struct marpaXml_SAX_AttributeList {
  int                (*getLength)();
  marpaXml_String_t *(*getName)(int i);

  marpaXml_String_t *(*getType_byPosition)(int i);
  marpaXml_String_t *(*getValue_byPosition)(int i);

  marpaXml_String_t *(*getType_byName)(marpaXml_String_t *name);
  marpaXml_String_t *(*getValue_byName)(marpaXml_String_t *name);
} *marpaXml_SAX_AttributeList_t;

marpaXml_SAX_AttributeList_t *marpaXml_SAX_AttributeList_new();
void                          marpaXml_SAX_AttributeList_destroy(marpaXml_SAX_AttributeList_t *this);

#endif /* MARPAXML_SAX_ATTRIBUTELIST_H */
