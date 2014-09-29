#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct qname_1_1 qname_1_1_t;

qname_1_1_t        *qname_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t  qname_1_1_recognizeb(qname_1_1_t *qname_1_1p, streamIn_t *streamInp);
void                qname_1_1_destroyv(qname_1_1_t **qname_1_1pp);

/* Callbacks */
marpaWrapperBool_t  qname_1_1_ruleToStringb(marpaWrapperRule_t *marpaWrapperRulep, const char **rulesp);
marpaWrapperBool_t  qname_1_1_symbolToStringb(marpaWrapperSymbol_t *marpaWrapperSymbolp, const char **symbolsp);
marpaWrapperBool_t  qname_1_1_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
marpaWrapperBool_t  qname_1_1_lexemeValueb(void *lexemeValuebCallbackDatavp, streamIn_t *streamInp, size_t lengthl, int *lexemeValueip);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H */
