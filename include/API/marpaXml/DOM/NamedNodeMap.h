#ifndef MARPAXML_API_DOM_NAMEDNODEMAP_H
#define MARPAXML_API_DOM_NAMEDNODEMAP_H

#include "marpaXml/cplus.h"

SUBCLASS(NamedNodeMap, Object)
  VTABLE(NamedNodeMap, Object)
METHODS
  int  getLength();
  Node getNamedItem(String name);
  Node getNamedItemNS(String namespaceURI, String localName);
  Node item(int index);
  Node removeNamedItem(String name);
  Node removeNamedItemNS(String namespaceURI, String localName);
  Node setNamedItem(Node arg);
  Node setNamedItemNS(Node arg)
END_CLASS

#endif /* MARPAXML_API_DOM_NAMEDNODEMAP_H */
