#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct qname_1_1 qname_1_1_t;

qname_1_1_t        *qname_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t  qname_1_1_getMarpaWrapperpb(qname_1_1_t *qname_1_1p, marpaWrapper_t **marpaWrapperpp);
marpaWrapperBool_t  qname_1_1_isLexemeb(void *p, signed int currenti, streamIn_t *streamInp, size_t *sizelp);
marpaWrapperBool_t  qname_1_1_lexemeValuei(void *p, streamIn_t *streamInp, size_t sizel, int *valueip);
void                qname_1_1_destroyv(qname_1_1_t **qname_1_1pp);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H */
