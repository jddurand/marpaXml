#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H

#include <stddef.h>

#include "internal/grammar/xml_common.h"
#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct xml_1_0 xml_1_0_t;

xml_1_0_t          *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
marpaWrapperBool_t  xml_1_0_recognizeb(xml_1_0_t *xml_1_0p, streamIn_t *streamInp);
void                xml_1_0_destroyv(xml_1_0_t **xml_1_0pp);

/* Callbacks */
marpaWrapperBool_t  xml_1_0_symbolToStringb(void *marpaWrapperSymbolOptionDatavp, const char **symbolsp);
marpaWrapperBool_t  xml_1_0_ruleToStringb(void *marpaWrapperRuleOptionDatavp, const char **rulesp);
marpaWrapperBool_t  xml_1_0_isLexemeb(void *marpaWrapperSymbolOptionDatavp, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
marpaWrapperBool_t  xml_1_0_lexemeValueb(void *marpaWrapperSymbolOptionDatavp, streamIn_t *streamInp, int *lexemeValueip, int *lexemeLengthip);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H */
