#ifndef MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H
#define MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMImplementationSource, Object)
  void *ctx;
VTABLE(DOMImplementationSource, Object)
  DOMImplementation     *(*getDOMImplementation)(DOMImplementationSource *me, String *features);
  DOMImplementationList *(*getDOMImplementationList)(DOMImplementationSource *me, String *features);
METHODS
  DOMImplementationSource *DOMImplementationSource_new();
  void                     DOMImplementationSource_free(DOMImplementationSource *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMIMPLEMENTATIONSOURCE_H */
