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
marpaWrapperBool_t  xml_1_0_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
marpaWrapperBool_t  xml_1_0_lexemeValueb(void *lexemeValuebCallbackDatavp, streamIn_t *streamInp, size_t lengthl, int *lexemeValueip);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_0_H */
