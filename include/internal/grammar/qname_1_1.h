#ifndef MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H
#define MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"

typedef struct qname_1_1 qname_1_1_t;

qname_1_1_t        *qname_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t  qname_1_1_recognizeb(qname_1_1_t *qname_1_1p, streamIn_t *streamInp);
void                qname_1_1_destroyv(qname_1_1_t **qname_1_1pp);

/* Needed for streamInUtf8_newp */
marpaWrapperBool_t  qname_1_1_nbTerminalsb(qname_1_1_t *qname_1_1p, size_t *nbTerminalslp);

#endif /* MARPAQNAME_INTERNAL_GRAMMAR_QNAME_1_1_H */
