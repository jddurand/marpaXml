#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct qname_1_0 qname_1_0_t;

qname_1_0_t        *qname_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t  qname_1_0_recognizeb(qname_1_0_t *qname_1_0p, streamIn_t *streamInp);
void                qname_1_0_destroyv(qname_1_0_t **qname_1_0pp);

/* Needed for streamInUtf8_newp */

/* Callbacks */
marpaWrapperBool_t  qname_1_0_symbolToCharsb(void *marpaWrapperSymbolOptionDatavp, const char **symbolsp);
marpaWrapperBool_t  qname_1_0_ruleToCharsb(void *marpaWrapperRuleOptionDatavp, const char **rulesp);
marpaWrapperBool_t  qname_1_0_isLexemeb(void *marpaWrapperSymbolOptionDatavp, size_t *lengthlp);
marpaWrapperBool_t  qname_1_0_lexemeValueb(void *marpaWrapperSymbolOptionDatavp,  int *lexemeValueip, int *lexemeLengthip);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H */
