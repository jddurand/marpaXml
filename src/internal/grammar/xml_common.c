#include "internal/grammar/xml_common.h"

/***************************/
/* xml_common_optionDefaultb
/***************************/
marpaWrapperBool_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp) {

  if (xml_common_optionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  xml_common_optionp->xml_common_topi = XML_COMMON_TOP_DOCUMENT;
  xml_common_optionp->encodings       = NULL;

  return MARPAWRAPPER_BOOL_TRUE;
}

