#ifndef MARPAXML_API_DOM_DOMERRORHANDLER_H
#define MARPAXML_API_DOM_DOMERRORHANDLER_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMErrorHandler, Object)
  void *ctx;
VTABLE(DOMErrorHandler, Object)
  boolean (*handleError)(DOMErrorHandler *me, DOMError *error);
METHODS
  DOMErrorHandler *DOMErrorHandler_new();
  void             DOMErrorHandler_free(DOMErrorHandler *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMERRORHANDLER_H */
