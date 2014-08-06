#include <stdio.h>
#include "API/marpaXml/DOM.h"
#include "internal/DOMStringLiterals.hpp"
#include <unicode/ustring.h>

int main(int argc, char **argv) {
  MARPAXML_DOM_STRUCT(DOMString)       DOMString;
  U_STRING_DECL(DOMStringUnknown, "Unknown", 7);

  MARPAXML_DOM_TYPE(DOMImplementation) DOMImplementationp = MARPAXML_DOM_NEW(DOMImplementation)();

  DOMString.s = (UChar *) marpaXml_DOMStringLiteral_buffer(MARPAXML_DOM_STRINGLITERAL_CORE);
  DOMString.length = marpaXml_DOMStringLiteral_length(MARPAXML_DOM_STRINGLITERAL_CORE);
  fprintf(stderr, "DOMImplementationp->hasFeature(\"Core\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_TRUE ? "OK" : "KO");

  DOMString.s = (UChar *) marpaXml_DOMStringLiteral_buffer(MARPAXML_DOM_STRINGLITERAL_XML);
  DOMString.length = marpaXml_DOMStringLiteral_length(MARPAXML_DOM_STRINGLITERAL_XML);
  fprintf(stderr, "DOMImplementationp->hasFeature(\"XML\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_TRUE ? "OK" : "KO");

  U_STRING_INIT(DOMStringUnknown, "Unknown", 7);
  DOMString.s = DOMStringUnknown;
  DOMString.length = u_strlen(DOMStringUnknown);
  fprintf(stderr, "DOMImplementationp->hasFeature(\"Unknown\", NULL): %s\n", DOMImplementationp->hasFeature(&DOMString, NULL) == MARPAXML_DOM_FALSE ? "OK" : "KO");

  MARPAXML_DOM_FREE(DOMImplementation)(DOMImplementationp);

  return 0;
}
