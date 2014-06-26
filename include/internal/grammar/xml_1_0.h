#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H

#include <stddef.h>
#include "grammar/xml_common.h"
#include "marpaWrapper.h"

typedef struct xml_1_0 xml_1_0_t;

xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
void       xml_1_0_destroyv(xml_1_0_t **xml_1_0pp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H */
