#include <stdlib.h>
#include "internal/log.h"

int main(int argc, char **argv) {
  marpaXmlLog_t *marpaXmlLogp = NULL;

  MARPAXML_INFO0("Trace before marpaXmlLog_newp\n");
  MARPAXML_INFOX("Trace before marpaXmlLog_newp with an argument that should read \"this argument\": %s\n", "this argument");

  marpaXmlLogp = marpaXmlLog_newp(NULL, NULL, MARPAXML_LOGLEVEL_WARNING);

  MARPAXML_INFO0("This trace must be hiden\n");
  MARPAXML_WARNING0("This trace must be visible\n");

  marpaXmlLog_freev(&marpaXmlLogp);

  return 0;
}
