#ifndef MARPAXML_API_DOM_DOMERROR_H
#define MARPAXML_API_DOM_DOMERROR_H

#include "marpaXml/cplus.h"


SUBCLASS(DOMError, Object)
  void *ctx;
  unsigned short      SEVERITY_WARNING;
  unsigned short      SEVERITY_ERROR;
  unsigned short      SEVERITY_FATAL_ERROR;
VTABLE(DOMError, Object)
  DOMLocator *(*getLocation)(DOMError *me);
  String     *(*getMessage)(DOMError *me);
  Object     *(*getRelatedData)(DOMError *me);
  Object     *(*getRelatedException)(DOMError *me);
  short       (*getSeverity)(DOMError *me);
  String     *(*getType)(DOMError *me);
METHODS
  DOMError *DOMError_new();
  void      DOMError_free(DOMError *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMERROR_H */
