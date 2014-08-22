#ifndef MARPAXML_API_DOM_NODELIST_H
#define MARPAXML_API_DOM_NODELIST_H

#include "marpaXml/cplus.h"

SUBCLASS(NodeList, Object)
  void *ctx;
VTABLE(NodeList, Object)
  int   (*getLength)(NodeList *me);
  Node *(*item)(NodeList *me, int index);
METHODS
  NodeList *NodeList_new();
  void      NodeList_free(NodeList *me);
END_CLASS

#endif /* MARPAXML_API_DOM_NODELIST_H */
