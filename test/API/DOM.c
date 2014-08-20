#include <stdio.h>
#include "API/marpaXml/DOM.h"
#include "API/marpaXml/log.h"
#include <unicode/ustring.h>

int main(int argc, char **argv) {
#ifdef _WIN32
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_TRACE, marpaXmlLog_defaultLogCallback(), NULL, "C:\\Windows\\Temp\\test.sqlite", NULL, -1};
#else
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_TRACE, marpaXmlLog_defaultLogCallback(), NULL, "/tmp/test.sqlite", NULL, -1};
#endif

  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stderr, "marpaXml_DOM_init() failure, %s\n", (char *) marpaXml_DOMError_getMessage());
    return 1;
  }

  /*************************************/
  /*       DOMImplementation           */
  /*************************************/
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

  /*************************************/
  /*        DOMStringList              */
  /*************************************/
  if (marpaXml_DOMStringList_getLength() == 0) {
    fprintf(stdout, "marpaXml_DOMStringList_getLength(): OK\n");
  } else {
    fprintf(stdout, "marpaXml_DOMStringList_getLength(): KO\n");
    return 1;
  }

  if (marpaXml_DOMStringList_item(0) == NULL) {
    fprintf(stdout, "marpaXml_DOMStringList_item(0): OK\n");
  } else {
    fprintf(stdout, "marpaXml_DOMStringList_item(0): KO\n");
    return 1;
  }

  if (marpaXml_DOMStringList_contains((char *)"Nothing yet") == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stdout, "marpaXml_DOMStringList_contains(\"%s\"): OK\n", "Nothing yet");
  } else {
    fprintf(stdout, "marpaXml_DOMStringList_contains(\"%s\"): KO\n", "Nothing yet");
    return 1;
  }

  if (marpaXml_DOM_release() == MARPAXML_DOMBOOLEAN_FALSE) {
    fprintf(stderr, "marpaXml_DOM_release() failure, %s\n", (char *) marpaXml_DOMError_getMessage());
    return 1;
  }

  fprintf(stderr, "All tests returned OK\n");
  return 0;
}
