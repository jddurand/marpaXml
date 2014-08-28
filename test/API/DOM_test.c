#include <stdio.h>
#include "API/marpaXml/DOM2.h"
#include "API/marpaXml/log.h"
#include <unicode/ustring.h>

int main(int argc, char **argv) {
    marpaXml_String_t       *messagep;
    marpaXml_DOMException_t *exceptionp;
    marpaXml_String_t       *string;
    unsigned short           unsignedShort;

#ifdef _WIN32
    marpaXml_DOM_Option_t marpaXml_DOM_Option = {"C:\\Windows\\Temp\\test.sqlite", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_TRACE} };
#else
    marpaXml_DOM_Option_t marpaXml_DOM_Option = {"/tmp/test.sqlite", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_TRACE } };
#endif

  /*************************************/
  /*                Init               */
  /*************************************/
  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_init() failure\n");
    return 1;
  }

  /*************************************/
  /*            DOMException           */
  /*************************************/
  messagep = marpaXml_String_newFromUTF8((char *) "My Message", NULL);
  exceptionp = marpaXml_DOMException_new(2, messagep);
  /*
  if ((unsignedShort = marpaXml_DOMException_getCode(exceptionp)) != 2) {
    fprintf(stderr, "marpaXml_DOMException_getCode returns %d != 2\n", (int) unsignedShort);
    return 1;
  }
  */
  if ((string = marpaXml_DOMException_getMessage(exceptionp)) == NULL) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns NULL\n");
    return 1;
  }
  if (strcmp(marpaXml_String_getUtf8(string), "My Message") != 0) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns \"%s\" ne \"My Message\"\n", marpaXml_String_getUtf8(string));
    return 1;
  }

  marpaXml_String_free(&messagep);
  marpaXml_DOMException_free(&exceptionp);

  /*************************************/
  /*                End                */
  /*************************************/
  if (marpaXml_DOM_release() == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_release() failure\n");
    return 1;
  }

  fprintf(stderr, "All tests returned OK\n");
  return 0;
}
