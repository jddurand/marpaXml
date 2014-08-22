#ifndef MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H
#define MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMImplementationList, Object)
  void *ctx;
VTABLE(DOMImplementationList, Object)
  int                (*getLength)(DOMImplementationList *me);
  DOMImplementation *(*item)(DOMImplementationList *me, int index);
METHODS
  DOMImplementationList *DOMImplementationList_new();
  void                   DOMImplementationList_free(DOMImplementationList *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H */
