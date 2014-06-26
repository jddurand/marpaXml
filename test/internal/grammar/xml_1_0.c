#include <stdio.h>
#include "grammar/xml_common.h"
#include "grammar/xml_1_0.h"

int main(int argc, char **argv) {
  xml_1_0_t *xml_1_0p;
  marpaWrapperOption_t       marpaWrapperOption;
  xml_common_option_t        xml_common_option;

  marpaWrapper_optionDefaultb(&marpaWrapperOption);
  marpaWrapperOption.logLevelWantedi     = MARPAWRAPPER_LOGLEVEL_WARNING;

  xml_common_optionDefaultb(&xml_common_option);

  xml_common_option.xml_common_topi = XML_COMMON_TOP_DOCUMENT;
  xml_1_0p = xml_1_0_newp(&marpaWrapperOption, &xml_common_option);
  if (xml_1_0p != NULL) {
    fprintf(stderr, "XML_1_0 document grammar creation OK\n");
    xml_1_0_destroyv(&xml_1_0p);
  } else {
    fprintf(stderr, "XML_1_0 document grammar creation KO\n");
  }
  xml_1_0_destroyv(&xml_1_0p);

  xml_common_option.xml_common_topi = XML_COMMON_TOP_EXTPARSEDENT;
  xml_1_0p = xml_1_0_newp(&marpaWrapperOption, &xml_common_option);
  if (xml_1_0p != NULL) {
    fprintf(stderr, "XML_1_0 extParsedEnt grammar creation OK\n");
    xml_1_0_destroyv(&xml_1_0p);
  } else {
    fprintf(stderr, "XML_1_0 extParsedEnt grammar creation KO\n");
  }
  xml_1_0_destroyv(&xml_1_0p);

  xml_common_option.xml_common_topi = XML_COMMON_TOP_EXTSUBSET;
  xml_1_0p = xml_1_0_newp(&marpaWrapperOption, &xml_common_option);
  if (xml_1_0p != NULL) {
    fprintf(stderr, "XML_1_0 extSubset grammar creation OK\n");
    xml_1_0_destroyv(&xml_1_0p);
  } else {
    fprintf(stderr, "XML_1_0 extSubset grammar creation KO\n");
  }
  xml_1_0_destroyv(&xml_1_0p);

  return 0;
}
