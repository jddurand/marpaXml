#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H

#include <stddef.h>
#include "internal/marpaWrapper.h"

typedef struct xml_1_1 {
  marpaWrapper_t        *marpaWrapperp;
  marpaWrapperSymbol_t **marpaWrapperSymbolArrayp;
  size_t                 marpaWrapperSymbolArrayLengthi;
  marpaWrapperRule_t   **marpaWrapperRuleArrayp;
  size_t                 marpaWrapperRuleArrayLengthi;
} xml_1_1_t;

xml_1_1_t *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp);
void       xml_1_1_destroyv(xml_1_1_t **xml_1_1pp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H */
