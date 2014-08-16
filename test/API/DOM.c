#include <stdio.h>
#include "API/marpaXml/DOM.h"
#include "API/marpaXml/log.h"
#include <unicode/ustring.h>

int main(int argc, char **argv) {
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_TRACE, marpaXmlLog_defaultLogCallback(), NULL, ":memory:", NULL, -1};

  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stderr, "marpaXml_DOM_init() failure, %s\n", (char *) marpaXml_DOMError_getMessage());
    return 1;
  }

  /* feature is case insensitive */
  /* version as well, but this is not relevant, since version in the data is 1.0, 2.0, 3.0, etc... */
  if (marpaXml_DOMImplementation_hasFeature((char *) "CoRe", NULL) == MARPAXML_DOMBOOLEAN_TRUE) {
    fprintf(stdout, "marpaXml_DOMImplementation_hasFeature(\"%s\", NULL): OK\n", "CoRe");
  } else {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature(\"%s\", NULL): KO\n", "CoRe");
    return 1;
  }

  return 0;
}
