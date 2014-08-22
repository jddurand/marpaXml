#ifndef MARPAXML_API_DOM_DOCUMENTFRAGMENT_H
#define MARPAXML_API_DOM_DOCUMENTFRAGMENT_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(DocumentFragment, Node)
  void *ctx;
VTABLE(DocumentFragment, Node)
METHODS
  DocumentFragment *DocumentFragment_new();
  void              DocumentFragment_free(DocumentFragment *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOCUMENTFRAGMENT_H */
