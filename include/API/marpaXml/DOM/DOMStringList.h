#ifndef MARPAXML_API_DOM_DOMSTRINGLIST_H
#define MARPAXML_API_DOM_DOMSTRINGLIST_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMStringList, Object)
  void *ctx;
VTABLE(DOMStringList, Object)
  boolean  (*contains)(DOMStringList *me, String *str);
  int      (*getLength)(DOMStringList *me);
  String  *(*item)(DOMStringList *me, int index);
METHODS
  DOMStringList *DOMStringList_new();
  void           DOMStringList_free(DOMStringList *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMSTRINGLIST_H */
