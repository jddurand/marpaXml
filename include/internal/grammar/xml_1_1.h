#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H

#include <stddef.h>

#include "internal/grammar/xml_common.h"
#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct xml_1_1 xml_1_1_t;

xml_1_1_t          *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp, xml_common_option_t *xml_common_optionp);
marpaWrapperBool_t  xml_1_1_recognizeb(xml_1_1_t *xml_1_1p, streamIn_t *streamInp);
void                xml_1_1_destroyv(xml_1_1_t **xml_1_1pp);

/* Callbacks */
marpaWrapperBool_t  xml_1_1_symbolToStringb(void *marpaWrapperSymbolOptionDatavp, const char **symbolsp);
marpaWrapperBool_t  xml_1_1_ruleToStringb(void *marpaWrapperRuleOptionDatavp, const char **rulesp);
marpaWrapperBool_t  xml_1_1_isLexemeb(void *marpaWrapperSymbolOptionDatavp, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
marpaWrapperBool_t  xml_1_1_lexemeValueb(void *marpaWrapperSymbolOptionDatavp, streamIn_t *streamInp, int *lexemeValueip);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H */
