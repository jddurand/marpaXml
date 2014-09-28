#include <stdio.h>

#include "internal/grammar/xml_common.h"
#include "internal/grammar/xml_1_0.h"
#include "API/marpaXml/DOM2.h"

int main(int argc, char **argv) {
  xml_1_0_t *xml_1_0p;
  marpaWrapperOption_t       marpaWrapperOption;
  xml_common_option_t        xml_common_option;
#ifdef _WIN32
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {"C:\\Windows\\Temp\\test.sqlite", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_TRACE} };
#else
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {"/tmp/test.sqlite", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_TRACE } };
#endif

  marpaXml_DOM_init(&marpaXml_DOM_Option);

  marpaWrapper_optionDefaultb(&marpaWrapperOption);
  marpaWrapperOption.logLevelWantedi     = MARPAXML_LOGLEVEL_TRACE;

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

  if (argc > 1) {
    streamInOption_t streamInOption;
    streamInUtf8Option_t streamInUtf8Option;
    streamInFromFileName_t *streamInFromFileNamep;

    streamIn_optionDefaultb(&streamInOption);
    streamInUtf8_optionDefaultb(&streamInUtf8Option);

    streamInOption.logLevelWantedi = MARPAXML_LOGLEVEL_TRACE;
    streamInFromFileNamep = streamInUtf8_newFromFileNamep(&streamInOption, &streamInUtf8Option, (const char *) argv[1]);

    marpaWrapper_optionDefaultb(&marpaWrapperOption);
    marpaWrapperOption.logLevelWantedi     = MARPAXML_LOGLEVEL_TRACE;

    xml_common_optionDefaultb(&xml_common_option);

    xml_common_option.xml_common_topi = XML_COMMON_TOP_DOCUMENT;
    xml_1_0p = xml_1_0_newp(&marpaWrapperOption, &xml_common_option);

    xml_1_0_recognizeb(xml_1_0p, streamInFromFileNamep->streamInp);
    xml_1_0_destroyv(&xml_1_0p);
    streamInUtf8_streamInFromFileName_destroyv(&streamInFromFileNamep);
  }

  marpaXml_DOM_release();

  return 0;
}
