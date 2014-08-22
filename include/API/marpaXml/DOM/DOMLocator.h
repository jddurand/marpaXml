#ifndef MARPAXML_API_DOM_DOMLOCATOR_H
#define MARPAXML_API_DOM_DOMLOCATOR_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMLocator, Object)
  void *ctx;
VTABLE(DOMLocator, Object)
  int     (*getByteOffset)(DOMLocator *me);
  int     (*getColumnNumber)(DOMLocator *me);
  int     (*getLineNumber)(DOMLocator *me);
  Node   *(*getRelatedNode)(DOMLocator *me);
  String *(*getUri)(DOMLocator *me);
  int     (*getUtf16Offset)(DOMLocator *me);
METHODS
  DOMLocator *DOMLocator_new();
  void        DOMLocator_free(DOMLocator *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMLOCATOR_H */
