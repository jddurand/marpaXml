#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct qname_1_0 qname_1_0_t;

qname_1_0_t        *qname_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t  qname_1_0_recognizeb(qname_1_0_t *qname_1_0p, streamIn_t *streamInp);
void                qname_1_0_destroyv(qname_1_0_t **qname_1_0pp);

/* Callbacks */
marpaWrapperBool_t  qname_1_0_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
marpaWrapperBool_t  qname_1_0_lexemeValueb(void *lexemeValuebCallbackDatavp, streamIn_t *streamInp, size_t lengthl, int *lexemeValueip);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H */
