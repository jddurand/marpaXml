#ifndef MARPAXML_API_DOM_NAMEDNODEMAP_H
#define MARPAXML_API_DOM_NAMEDNODEMAP_H

#include "marpaXml/cplus.h"

SUBCLASS(NamedNodeMap, Object)
  void *ctx;
VTABLE(NamedNodeMap, Object)
  int   (*getLength)(NamedNodeMap *me);
  Node *(*getNamedItem)(NamedNodeMap *me, String *name);
  Node *(*getNamedItemNS)(NamedNodeMap *me, String *namespaceURI, String *localName);
  Node *(*item)(NamedNodeMap *me, int index);
  Node *(*removeNamedItem)(NamedNodeMap *me, String *name);
  Node *(*removeNamedItemNS)(NamedNodeMap *me, String *namespaceURI, String *localName);
  Node *(*setNamedItem)(NamedNodeMap *me, Node *arg);
  Node *(*setNamedItemNS)(NamedNodeMap *me, Node *arg);
METHODS
  NamedNodeMap *NamedNodeMap_new();
  void          NamedNodeMap_free(NamedNodeMap *me);
END_CLASS

#endif /* MARPAXML_API_DOM_NAMEDNODEMAP_H */
