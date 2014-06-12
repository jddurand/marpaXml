#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H

#include <stddef.h>
#include "internal/grammar/xml_common.h"
#include "internal/marpaWrapper.h"

typedef struct xml_1_0 xml_1_0_t;

xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_commonOption_t *xml_commonOptionp);
void       xml_1_0_destroyv(xml_1_0_t **xml_1_0pp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H */
