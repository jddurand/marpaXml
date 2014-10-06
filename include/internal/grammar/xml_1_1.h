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

/* Needed for streamInUtf8_newp */
marpaWrapperBool_t  xml_1_1_nbTerminalsb(xml_1_1_t *xml_1_1p, size_t *nbTerminalslp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_1_1_H */
