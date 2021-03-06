#include <stdio.h>
#include <string.h>

#include "API/marpaXml/DOM2.h"
#include "API/marpaXml/log.h"

int main(int argc, char **argv) {
    marpaXml_String_t        *message1p = NULL, *message2p = NULL;
    marpaXml_String_t        *contains1p = NULL, *contains2p = NULL;
    marpaXml_String_t        *feature1p = NULL, *version1p = NULL;
    marpaXml_String_t        *feature2p = NULL, *version2p = NULL;
    marpaXml_String_t        *feature3p = NULL, *version3p = NULL;
    marpaXml_String_t        *features1p = NULL, *features2p = NULL;
    marpaXml_DOMException_t  *exceptionp;
    marpaXml_DOMStringList_t *DOMStringList1p = NULL, *DOMStringList2p = NULL, *DOMStringList3p = NULL;
    marpaXml_NameList_t      *NameList1p = NULL, *NameList2p = NULL, *NameList3p = NULL;
    marpaXml_DOMImplementationList_t *DOMImplementationListp = NULL;
    marpaXml_Node_t          *nodep = NULL;
    marpaXml_String_t        *string = NULL;
    unsigned short            unsignedShort;
    marpaXml_boolean_t        rcb;
    unsigned long             rcl;
    marpaXml_String_t        *rcString = NULL;
    marpaXml_DOMImplementation_t *DOMImplementationp = NULL, *DOMImplementation2p = NULL;
    marpaXml_DOMImplementationSource_t *DOMImplementationSourcep = NULL;

#ifdef _WIN32
    marpaXml_DOM_Option_t marpaXml_DOM_Option = {"C:\\Windows\\Temp\\test.sqlite", NULL, -1, NULL};
#else
    marpaXml_DOM_Option_t marpaXml_DOM_Option = {"/tmp/test.sqlite", NULL, -1, NULL};
#endif

  message1p = marpaXml_String_newFromUTF8((char *) "My Message", NULL);
  message2p = marpaXml_String_newFromUTF8((char *) "My New Message", NULL);
  feature1p = marpaXml_String_newFromUTF8((char *) "CoRe", NULL);
  version1p = marpaXml_String_newFromUTF8((char *) "3.0", NULL);
  feature2p = marpaXml_String_newFromUTF8((char *) "XMl", NULL);
  version2p = marpaXml_String_newFromUTF8((char *) "3.0", NULL);
  feature3p = marpaXml_String_newFromUTF8((char *) "Bump", NULL);
  version3p = marpaXml_String_newFromUTF8((char *) "xxx", NULL);
  contains1p = marpaXml_String_newFromUTF8((char *) "String for contains(1)", NULL);
  contains2p = marpaXml_String_newFromUTF8((char *) "String for contains(2)", NULL);
  features1p = marpaXml_String_newFromUTF8((char *) "XML 3.0 Traversal +Events 2.0", NULL);
  features2p = marpaXml_String_newFromUTF8((char *) "XML 3.0 COre", NULL);

  /*************************************/
  /*                Init               */
  /*************************************/
  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_init() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /*************************************/
  /*            DOMException           */
  /*************************************/

  if (marpaXml_DOMException_new(0, message1p) != NULL) {
    fprintf(stderr, "marpaXml_DOMException_new success with invalid code 0 at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  exceptionp = marpaXml_DOMException_new(2, message1p);
  if (exceptionp == NULL) {
    fprintf(stderr, "marpaXml_DOMException_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /* marpaXml_DOMException_getCode */
  if (marpaXml_DOMException_getCode(exceptionp, &unsignedShort) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getCode failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (unsignedShort != 2) {
    fprintf(stderr, "marpaXml_DOMException_getCode returns %d != 2 at %s:%d\n", (int) unsignedShort, __FILE__, __LINE__);
    return 1;
  }

  /* marpaXml_DOMException_setCode */
  if (marpaXml_DOMException_setCode(exceptionp, 0) == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMException_setCode success with value 0 at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMException_setCode(exceptionp, 3) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_setCode failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMException_getCode(exceptionp, &unsignedShort) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getCode failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (unsignedShort != 3) {
    fprintf(stderr, "marpaXml_DOMException_getCode returns %d != 3 at %s:%d\n", (int) unsignedShort, __FILE__, __LINE__);
    return 1;
  }

  /* marpaXml_DOMException_getMessage */
  if (marpaXml_DOMException_getMessage(exceptionp, &string) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getMessage failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (strcmp(marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message1p)) != 0) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns \"%s\" ne \"%s\" at %s:%d\n", marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message1p), __FILE__, __LINE__);
    return 1;
  }
  marpaXml_String_free(&string);

  /* marpaXml_DOMException_setMessage */
  if (marpaXml_DOMException_setMessage(exceptionp, message2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_setMessage failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMException_getMessage(exceptionp, &string) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_getMessage failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (strcmp(marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message2p)) != 0) {
    fprintf(stderr, "marpaXml_DOMException_getMessage returns \"%s\" ne \"%s\" at %s:%d\n", marpaXml_String_getUtf8(string), marpaXml_String_getUtf8(message2p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMException_free(&exceptionp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMException_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /*************************************/
  /*            DOMStringList          */
  /*************************************/
  /* The reel test is to interleave creations and destructions */
  DOMStringList1p = marpaXml_DOMStringList_new();
  if (DOMStringList1p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  DOMStringList2p = marpaXml_DOMStringList_new();
  if (DOMStringList2p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_free(&DOMStringList1p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  DOMStringList3p = marpaXml_DOMStringList_new();
  if (DOMStringList3p == NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_contains(DOMStringList3p, contains1p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_contains failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMStringList_contains says it contains \"%s\" at %s:%d\n", marpaXml_String_getUtf8(contains1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_getLength(DOMStringList3p, &rcl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_getLength failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcl != 0) {
    fprintf(stderr, "marpaXml_DOMStringList_getLength returned %ld at %s:%d\n", (long) rcl, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_item(DOMStringList3p, 0, &rcString) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_item failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcString != NULL) {
    fprintf(stderr, "marpaXml_DOMStringList_item returned \"%p\" at %s:%d\n", (void *) rcString, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_contains(DOMStringList3p, contains2p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_contains failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMStringList_contains says it contains \"%s\" at %s:%d\n", marpaXml_String_getUtf8(contains1p), __FILE__, __LINE__);
    return 1;
  }

  if (marpaXml_DOMStringList_free(&DOMStringList2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMStringList_free(&DOMStringList3p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMStringList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /*************************************/
  /*               NameList            */
  /*************************************/
  /* The reel test is to interleave creations and destructions */
  NameList1p = marpaXml_NameList_new();
  if (NameList1p == NULL) {
    fprintf(stderr, "marpaXml_NameList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  NameList2p = marpaXml_NameList_new();
  if (NameList2p == NULL) {
    fprintf(stderr, "marpaXml_NameList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_free(&NameList1p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  NameList3p = marpaXml_NameList_new();
  if (NameList3p == NULL) {
    fprintf(stderr, "marpaXml_NameList_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_contains(NameList3p, contains1p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_contains failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_NameList_contains says it contains \"%s\" at %s:%d\n", marpaXml_String_getUtf8(contains1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_getLength(NameList3p, &rcl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_getLength failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcl != 0) {
    fprintf(stderr, "marpaXml_NameList_getLength returned %ld at %s:%d\n", (long) rcl, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_contains(NameList3p, contains1p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_contains failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_NameList_contains says it contains \"%s\" at %s:%d\n", marpaXml_String_getUtf8(contains1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_contains(NameList3p, contains2p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_contains failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_NameList_contains says it contains \"%s\" at %s:%d\n", marpaXml_String_getUtf8(contains1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_containsNS(NameList3p, contains1p, contains2p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_containsNS failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb == marpaXml_true) {
    fprintf(stderr, "marpaXml_NameList_containsNS says it contains {\"%s\", \"%s\"} at %s:%d\n", marpaXml_String_getUtf8(contains1p), marpaXml_String_getUtf8(contains2p), __FILE__, __LINE__);
    return 1;
  }

  if (marpaXml_NameList_free(&NameList2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_NameList_free(&NameList3p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_NameList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /*******************************************************/
  /*      DOMImplementationSource/DOMImplementation      */
  /*******************************************************/
  ;
  if ((DOMImplementationSourcep = marpaXml_DOMImplementationSource_new()) == NULL) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationSource_getDOMImplementation(DOMImplementationSourcep, features1p, &DOMImplementationp) == marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_getDOMImplementation failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationSource_getDOMImplementationList(DOMImplementationSourcep, features1p, &DOMImplementationListp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_getDOMImplementation failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_getLength(DOMImplementationListp, &rcl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_getLength failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcl != 0) {
    fprintf(stderr, "marpaXml_DOMImplementationList_getLength returned %ld at %s:%d\n", (long) rcl, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_free(&DOMImplementationListp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationSource_getDOMImplementation(DOMImplementationSourcep, features2p, &DOMImplementationp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_getDOMImplementation failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationSource_getDOMImplementationList(DOMImplementationSourcep, features2p, &DOMImplementationListp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_getDOMImplementation failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_getLength(DOMImplementationListp, &rcl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_getLength failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcl == 0) {
    fprintf(stderr, "marpaXml_DOMImplementationList_getLength returned %ld at %s:%d\n", (long) rcl, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_item(DOMImplementationListp, 999999, &DOMImplementation2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_item failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (DOMImplementation2p != NULL) {
    fprintf(stderr, "marpaXml_DOMImplementationList_item returned %p at %s:%d\n", (void *) DOMImplementation2p, __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_item(DOMImplementationListp, 0, &DOMImplementation2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_item failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (DOMImplementation2p == NULL) {
    fprintf(stderr, "marpaXml_DOMImplementationList_item returned NULL at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_free(&DOMImplementation2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationList_free(&DOMImplementationListp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationList_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_hasFeature(DOMImplementationp, feature1p, version1p, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb != marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature returned marpaXml_false for feature \"%s\" and version \"%s\" at %s:%d\n", marpaXml_String_getUtf8(feature1p), marpaXml_String_getUtf8(version1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_hasFeature(DOMImplementationp, feature1p, NULL, &rcb) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (rcb != marpaXml_true) {
    fprintf(stderr, "marpaXml_DOMImplementation_hasFeature returned marpaXml_false for feature \"%s\" at %s:%d\n", marpaXml_String_getUtf8(feature1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_getFeature(DOMImplementationp, feature1p, NULL, (marpaXml_DOMObject_t **) &DOMImplementation2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_getFeature failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (DOMImplementation2p == NULL) {
    fprintf(stderr, "marpaXml_DOMImplementation_getFeature returned a NULL DOMImplementation for feature \"%s\" at %s:%d\n", marpaXml_String_getUtf8(feature1p), __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_free(&DOMImplementation2p) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementation_free(&DOMImplementationp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementation_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_DOMImplementationSource_free(&DOMImplementationSourcep) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOMImplementationSource_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  /*************************************/
  /*                 Node              */
  /*************************************/
  /*
  nodep = marpaXml_Node_new();
  if (nodep == NULL) {
    fprintf(stderr, "marpaXml_Node_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (marpaXml_Node_free(&nodep) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Node_free failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  */

  /*************************************/
  /*                End                */
  /*************************************/
  if (marpaXml_DOM_release() == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_release() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  if (string != NULL) {
    marpaXml_String_free(&string);
  }
  marpaXml_String_free(&message1p);
  marpaXml_String_free(&message2p);
  marpaXml_String_free(&contains1p);
  marpaXml_String_free(&contains2p);
  marpaXml_String_free(&feature1p);
  marpaXml_String_free(&feature2p);
  marpaXml_String_free(&feature3p);
  marpaXml_String_free(&version1p);
  marpaXml_String_free(&version2p);
  marpaXml_String_free(&version3p);
  marpaXml_String_free(&features1p);
  marpaXml_String_free(&features2p);

  fprintf(stderr, "All tests returned OK\n");
  return 0;
}
