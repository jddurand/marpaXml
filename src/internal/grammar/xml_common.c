#include "internal/grammar/xml_common.h"

/*****************************/
/* xml_common_optionDefaultb */
/*****************************/
marpaWrapperBool_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp) {

  if (xml_common_optionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  xml_common_optionp->xml_common_topi = XML_COMMON_TOP_DOCUMENT;
  xml_common_optionp->encodings       = NULL;

  return MARPAWRAPPER_BOOL_TRUE;
}

/*****************************/
/* xml_common_lexemeValueb */
/*****************************/
marpaWrapperBool_t xml_common_lexemeValueb(void *lexemeValuebCallbackDatavp, streamIn_t *streamInp, size_t lengthl, int *lexemeValueip) {
  /* We use SQLite for store strings. Internal storage is optimized so that equivalent strings are not stored twice, via an internal relational table */
}

