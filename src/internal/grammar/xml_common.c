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
  char   *dests;
  size_t byteLengthl;
  /* Our caller must have guaranteed that:
     - marker in streamInp is at where the lexeme is starting
     - current position in streamInp is where the lexeme is ending
     - lengthl, if > 0, is the correct number of characters within this range
  */
  if (streamInUtf8_extractFromMarkedb(streamInp, &dests, &byteLengthl, (lengthl <= 0) ? &lengthl : NULL) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* We use SQLite to store strings. Internal storage is optimized so that equivalent strings are not stored twice, via an internal relational table */
  return MARPAWRAPPER_BOOL_TRUE;
}

