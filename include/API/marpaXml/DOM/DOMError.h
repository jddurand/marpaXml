#ifndef MARPAXML_API_DOM_DOMERROR_H
#define MARPAXML_API_DOM_DOMERROR_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMError, Object)
  VTABLE(DOMError, Object)
  short SEVERITY_ERROR;
  short SEVERITY_FATAL_ERROR;
  short SEVERITY_WARNING;
METHODS
  DOMLocator getLocation();
  String     getMessage();
  Object     getRelatedData();
  Object     getRelatedException();
  short      getSeverity();
  String     getType();
END_CLASS

#endif /* MARPAXML_API_DOM_DOMERROR_H */
