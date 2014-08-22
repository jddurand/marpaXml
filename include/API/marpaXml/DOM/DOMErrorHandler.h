#ifndef MARPAXML_API_DOM_DOMERRORHANDLER_H
#define MARPAXML_API_DOM_DOMERRORHANDLER_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMErrorHandler, Object)
  VTABLE(DOMErrorHandler, Object)
METHODS
  boolean 	handleError(DOMError error);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMERRORHANDLER_H */
