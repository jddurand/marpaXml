#include <stdio.h>
#include "internal/grammar/xml_1_1.h"

int main(int argc, char **argv) {
  xml_1_1_t *xml_1_1p;
  marpaWrapperOption_t       marpaWrapperOption;

  marpaWrapper_optionDefaultb(&marpaWrapperOption);
  marpaWrapperOption.logLevelWantedi     = MARPAWRAPPER_LOGLEVEL_TRACE;

  xml_1_1p = xml_1_1_newp(&marpaWrapperOption);
  if (xml_1_1p != NULL) {
    fprintf(stderr, "Grammar OK\n");
    xml_1_1_destroyv(&xml_1_1p);
  } else {
    fprintf(stderr, "Grammar KO\n");
  }

  return 0;
}
