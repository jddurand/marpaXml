#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H

#include <stddef.h>

#include "internal/marpaWrapper.h"
#include "internal/streamIn.h"
#include "API/marpaXml/log.h"

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

#define XML_COMMON_LAST_UTF8_TRACKSIZE 20
typedef struct xml_common_work {
  unsigned long long linel;
  unsigned long long columnl;
  unsigned long long deltaLinel;
  unsigned long long deltaColumnl;
  signed int         lastUtf8[XML_COMMON_LAST_UTF8_TRACKSIZE];
} xml_common_work_t;

typedef marpaWrapperBool_t (*xml_common_isLexemeb_t)(void *marpaWrapperSymbolOptionDatavp, size_t *sizelp);

marpaWrapperBool_t xml_common_isLexemeb(xml_common_work_t *xml_common_workp, xml_common_isLexemeb_t xml_common_isLexemebp, void *marpaWrapperSymbolOptionDatavp, size_t *sizelp);
marpaWrapperBool_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp);
marpaWrapperBool_t xml_common_lexemeValueb(xml_common_work_t *xml_common_workp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, int *lexemeValueip, int *lexemeLengthip);
marpaWrapperBool_t xml_common_readerb(xml_common_work_t *xml_common_workp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, signed int *currentip, marpaWrapperBool_t *endOfInputbp);

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H */

