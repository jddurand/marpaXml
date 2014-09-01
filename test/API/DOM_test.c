#include <stdio.h>
#include <string.h>

#include "API/marpaXml/DOM2.h"
#include "API/marpaXml/log.h"

int main(int argc, char **argv) {
    marpaXml_String_t        *messagep;
    marpaXml_String_t        *message2p;
    marpaXml_String_t        *containsp, *contains2p;
    marpaXml_DOMException_t  *exceptionp;
    marpaXml_DOMStringList_t *DOMStringList1p, *DOMStringList2p, *DOMStringList3p;
    marpaXml_String_t        *string;
    unsigned short            unsignedShort;
    marpaXml_boolean_t        rcb;

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
  message2p = marpaXml_String_newFromUTF8((char *) "My New Message", NULL);
  containsp = marpaXml_String_newFromUTF8((char *) "Test for DOMStringList_contains", NULL);
  contains2p = marpaXml_String_newFromUTF8((char *) "Another test for DOMStringList_contains", NULL);

  if (marpaXml_DOMException_new(0, messagep) != NULL) {
    fprintf(stderr, "marpaXml_DOMException_new success with invalid code 0\n");
    return 1;
  }

  exceptionp = marpaXml_DOMException_new(2, messagep);
  if (exceptionp == NULL) {
    fprintf(stderr, "marpaXml_DOMException_new failure\n");
    return 1;
  }

  /* marpaXml_DOMException_getCode */
  if (marpaXml_DOMException_getCode(exceptionp, &unsignedShort) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getCode failure\n");
    return 1;
  }
  if (unsignedShort != 2) {
    fprintf(stderr, "marpaXml_DOMException_getCode returns %d != 2\n", (int) unsignedShort);
    return 1;
  }

  /* marpaXml_DOMException_setCode */
  if (marpaXml_DOMException_setCode(exceptionp, 0) == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMException_setCode success with value 0\n");
    return 1;
  }
  if (marpaXml_DOMException_setCode(exceptionp, 3) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_setCode failure\n");
    return 1;
  }
  if (marpaXml_DOMException_getCode(exceptionp, &unsignedShort) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getCode failure\n");
    return 1;
  }
  if (unsignedShort != 3) {
    fprintf(stderr, "marpaXml_DOMException_getCode returns %d != 3\n", (int) unsignedShort);
    return 1;
  }

  /* marpaXml_DOMException_getMessage */
  if (marpaXml_DOMException_getMessage(exceptionp, &string) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getMessage failure\n");
    return 1;
  }
  if (strcmp(marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(messagep)) != 0) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns \"%s\" ne \"%s\"\n", marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(messagep));
    return 1;
  }
  marpaXml_String_free(&string);

  /* marpaXml_DOMException_setMessage */
  if (marpaXml_DOMException_setMessage(exceptionp, message2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_setMessage failure\n");
    return 1;
  }
  if (marpaXml_DOMException_getMessage(exceptionp, &string) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getMessage failure\n");
    return 1;
  }
  if (strcmp(marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message2p)) != 0) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns \"%s\" ne \"%s\"\n", marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message2p));
    return 1;
  }
  if (marpaXml_DOMException_free(&exceptionp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_free failure\n");
    return 1;
  }

  /*************************************/
  /*            DOMStringList          */
  /*************************************/
  /* The reel test is to interleave creations and destructions */
  DOMStringList1p = marpaXml_DOMStringList_new();
  if (DOMStringList1p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure\n");
    return 1;
  }
  DOMStringList2p = marpaXml_DOMStringList_new();
  if (DOMStringList2p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure\n");
    return 1;
  }
  if (marpaXml_DOMStringList_free(&DOMStringList1p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure\n");
    return 1;
  }
  DOMStringList3p = marpaXml_DOMStringList_new();
  if (DOMStringList3p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure\n");
    return 1;
  }
  marpaXml_DOMStringList_contains(DOMStringList3p, containsp, &rcb);
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMStringList_contains says it contains \"%s\"\n", marpaXml_String_getUtf8(containsp));
    return 1;
  }
  /* TODO: prepared statement optimization */
  marpaXml_DOMStringList_contains(DOMStringList3p, contains2p, &rcb);
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMStringList_contains says it contains \"%s\"\n", marpaXml_String_getUtf8(containsp));
    return 1;
  }

  if (marpaXml_DOMStringList_free(&DOMStringList2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure\n");
    return 1;
  }
  if (marpaXml_DOMStringList_free(&DOMStringList3p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure\n");
    return 1;
  }

  /*************************************/
  /*                End                */
  /*************************************/
  if (marpaXml_DOM_release() == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_release() failure\n");
    return 1;
  }

  marpaXml_String_free(&string);
  marpaXml_String_free(&messagep);
  marpaXml_String_free(&message2p);
  marpaXml_String_free(&containsp);

  fprintf(stderr, "All tests returned OK\n");
  return 0;
}
