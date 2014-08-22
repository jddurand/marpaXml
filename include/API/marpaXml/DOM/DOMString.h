#ifndef MARPAXML_API_DOM_DOMSTRING_H
#define MARPAXML_API_DOM_DOMSTRING_H

#include "cplus.h"
#include "Array.h"

SUBCLASS(DOMString, Array)
  char          *charset;
VTABLE(DOMString, Array)
  DOMString *(*convert)(char *newCharset);
METHODS
  DOMString *DOMString_new();
  DOMString *DOMString_new2(void *buf, size_t length, size_t unitSize);
  DOMString *DOMString_new3(void *buf, size_t length, size_t unitSize, char *charset);
  void       DOMString_free(DOMString *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMSTRING_H */
