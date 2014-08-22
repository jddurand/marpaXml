#ifndef MARPAXML_API_DOM_DOMCONFIGURATION_H
#define MARPAXML_API_DOM_DOMCONFIGURATION_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMConfiguration, Object)
  void *ctx;
VTABLE(DOMConfiguration, Object)
  boolean        (*canSetParameter)(DOMConfiguration *me, String *name, Object *value);
  Object        *(*getParameter)(DOMConfiguration *me, String *name);
  DOMStringList *(*getParameterNames)(DOMConfiguration *me);
  void           (*setParameter)(DOMConfiguration *me, String *name, Object *value);
METHODS
  DOMConfiguration *DOMConfiguration_new();
  void              DOMConfiguration_free(DOMConfiguration *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMCONFIGURATION_H */
