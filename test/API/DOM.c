#include <stdio.h>
#include "API/marpaXml/DOM.h"
#include "API/marpaXml/log.h"
#include <unicode/ustring.h>

int main(int argc, char **argv) {
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_TRACE, marpaXmlLog_defaultLogCallback(), NULL, "/tmp/test.sqlite", NULL, -1};

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
  if (marpaXml_DOMImplementation_hasFeature((char *) "CoRe2", NULL) == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stdout, "marpaXml_DOMImplementation_hasFeature(\"%s\", NULL): OK\n", "CoRe2");
  } else {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature(\"%s\", NULL): KO\n", "CoRe2");
    return 1;
  }
  if (marpaXml_DOMImplementation_hasFeature((char *) "CoRe", (char *) "2.0") == MARPAXML_DOMBOOLEAN_TRUE) {
    fprintf(stdout, "marpaXml_DOMImplementation_hasFeature(\"%s\", \"%s\"): OK\n", "CoRe", "2.0");
  } else {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature(\"%s\", \"%s\"): KO\n", "CoRe", "2.0");
    return 1;
  }

  if (marpaXml_DOM_release() == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stderr, "marpaXml_DOM_release() failure, %s\n", (char *) marpaXml_DOMError_getMessage());
    return 1;
  }

  return 0;
}
