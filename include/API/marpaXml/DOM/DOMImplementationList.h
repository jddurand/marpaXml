#ifndef MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H
#define MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMImplementationList, Object)
  VTABLE(DOMImplementationList, Object)
METHODS
  int               getLength();
  DOMImplementation item(int index);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMIMPLEMENTATIONLIST_H */
