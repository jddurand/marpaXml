#include <stdio.h>
#include "API/marpaXml/DOM.h"
#include <unicode/ustring.h>

U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_CORE, "Core", 4);
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_XML, "XML", 3);
U_STRING_DECL(DOMStringUnknown, "Unknown", 7);

int main(int argc, char **argv) {
  U_STRING_INIT(                 MARPAXML_DOM_STRINGLITERAL_CORE, "Core", 4);
  U_STRING_INIT(                 MARPAXML_DOM_STRINGLITERAL_XML, "XML", 3);
  U_STRING_INIT(                 DOMStringUnknown, "Unknown", 7);
  MARPAXML_DOM_STRUCT(DOMString) DOMString;

  MARPAXML_DOM_TYPE(DOMImplementation) DOMImplementationp = MARPAXML_DOM_NEW(DOMImplementation)();

  DOMString.s = (unsigned short *) MARPAXML_DOM_STRINGLITERAL_CORE;
  DOMString.length = 4;
  fprintf(stderr, "DOMImplementationp->hasFeature(\"Core\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_TRUE ? "OK" : "KO");

  DOMString.s = (unsigned short *) MARPAXML_DOM_STRINGLITERAL_XML;
  DOMString.length = 3;
  fprintf(stderr, "DOMImplementationp->hasFeature(\"XML\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_TRUE ? "OK" : "KO");

  DOMString.s = (unsigned short *) DOMStringUnknown;
  DOMString.length = 7;
  fprintf(stderr, "DOMImplementationp->hasFeature(\"Unknown\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_FALSE ? "OK" : "KO");

  MARPAXML_DOM_FREE(DOMImplementation)(DOMImplementationp);

  return 0;
}
