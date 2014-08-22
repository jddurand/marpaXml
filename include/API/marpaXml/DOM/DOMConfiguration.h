#ifndef MARPAXML_API_DOM_DOMCONFIGURATION_H
#define MARPAXML_API_DOM_DOMCONFIGURATION_H

#include "marpaXml/cplus.h"

CLASS(DOMConfiguration)
  VTABLE(DOMConfiguration, Object)
METHODS
  boolean       canSetParameter(String name, Object value);
  Object        getParameter(String name);
  DOMStringList getParameterNames();
  void          setParameter(String name, Object value);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMCONFIGURATION_H */
