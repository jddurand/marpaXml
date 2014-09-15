#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H

#include <stddef.h>

#include "internal/marpaWrapper.h"

typedef struct qname_1_1 qname_1_1_t;

qname_1_1_t *qname_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp);
void       qname_1_1_destroyv(qname_1_1_t **qname_1_1pp);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H */
