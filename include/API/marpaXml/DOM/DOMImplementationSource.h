#ifndef MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H
#define MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMImplementationSource, Object)
  VTABLE(DOMImplementationSource, Object)
METHODS
  DOMImplementation     getDOMImplementation(String features);
  DOMImplementationList getDOMImplementationList(String features);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H */
