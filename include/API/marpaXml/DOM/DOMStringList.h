#ifndef MARPAXML_API_DOM_DOMSTRINGLIST_H
#define MARPAXML_API_DOM_DOMSTRINGLIST_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMStringList, Object)
  VTABLE(DOMStringList, Object)
METHODS
  boolean contains(String str);
  int     getLength(void);
  String  item(int index);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMSTRINGLIST_H */
