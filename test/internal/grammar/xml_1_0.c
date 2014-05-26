#include <stdio.h>
#include "internal/grammar/xml_1_0.h"

int main(int argc, char **argv) {
  xml_1_0_t *xml_1_0p;
  marpaWrapperOption_t       marpaWrapperOption;

  marpaWrapper_optionDefaultb(&marpaWrapperOption);
  marpaWrapperOption.logLevelWantedi     = MARPAWRAPPER_LOGLEVEL_TRACE;

  xml_1_0p = xml_1_0_newp(&marpaWrapperOption);
  if (xml_1_0p != NULL) {
    fprintf(stderr, "Grammar OK\n");
    xml_1_0_destroyv(&xml_1_0p);
  } else {
    fprintf(stderr, "Grammar KO\n");
  }

  return 0;
}
