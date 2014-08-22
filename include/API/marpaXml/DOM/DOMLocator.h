#ifndef MARPAXML_API_DOM_DOMLOCATOR_H
#define MARPAXML_API_DOM_DOMLOCATOR_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMLocator, Object)
  VTABLE(DOMLocator, Object)
METHODS
  int    getByteOffset(void);
  int    getColumnNumber(void);
  int    getLineNumber(void);
  Node   getRelatedNode(void);
  String getUri(void);
  int    getUtf16Offset(void);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMLOCATOR_H */
