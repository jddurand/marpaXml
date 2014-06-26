#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H

#include <stddef.h>
#include "marpaWrapper.h"

/* There are always three top-level grammars: document, extParsedEnt and extSubset */
typedef enum xml_common_top {
  XML_COMMON_TOP_DOCUMENT,
  XML_COMMON_TOP_EXTPARSEDENT,
  XML_COMMON_TOP_EXTSUBSET,
} xml_common_top_t;

/* All XML sources may be, or use, a DTD. A DTD can be: */
/* - internal (intSubset)                               */
/* - external (ExternalID's value must match extSubset) */
/* - parsed (extParsedEnt)                              */
typedef enum xml_common_dtdType {
  XML_COMMON_DTDTYPE_INTERNAL,
  XML_COMMON_DTDTYPE_EXTERNAL,
  XML_COMMON_DTDTYPE_PARSED,
} xml_common_dtdType_t;

/* We define structures that correspond to the DTD hierarchy, i.e.: */

typedef struct xml_common_option {
  xml_common_top_t xml_common_topi;
  char            *encodings;
} xml_common_option_t;

marpaWrapperBool_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H */

