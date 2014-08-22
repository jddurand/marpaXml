#ifndef MARPAXML_API_DOM_NAMELIST_H
#define MARPAXML_API_DOM_NAMELIST_H

#include "marpaXml/cplus.h"

SUBCLASS(NameList, Object)
  VTABLE(NameList, Object)
METHODS
  boolean contains(String str);
  boolean containsNS(String namespaceURI, String name);
  int     getLength();
  String  getName(int index);
  String  getNamespaceURI(int index);
END_CLASS

#endif /* MARPAXML_API_DOM_NAMELIST_H */
