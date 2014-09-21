#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H

#include <stddef.h>

#include "internal/grammar/xml_common.h"
#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct xml_1_1 xml_1_1_t;

xml_1_1_t          *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
marpaWrapperBool_t  xml_1_1_getMarpaWrapperpb(xml_1_1_t *xml_1_1p, marpaWrapper_t **marpaWrapperpp);
marpaWrapperBool_t  xml_1_1_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
void                xml_1_1_destroyv(xml_1_1_t **xml_1_1pp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H */
