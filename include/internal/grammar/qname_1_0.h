#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H

#include <stddef.h>

#include "internal/marpaWrapper.h"

typedef struct qname_1_0 qname_1_0_t;

qname_1_0_t *qname_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp);
void       qname_1_0_destroyv(qname_1_0_t **qname_1_0pp);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_0_H */
