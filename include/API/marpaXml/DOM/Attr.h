#ifndef MARPAXML_API_DOM_ATTR_H
#define MARPAXML_API_DOM_ATTR_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Attr, Node)
  VTABLE(Attr, Node)
METHODS
  String   getName();
  Element  getOwnerElement();
  TypeInfo getSchemaTypeInfo();
  boolean  getSpecified();
  String   getValue();
  boolean  isId();
  void 	   setValue(String value);
END_CLASS

#endif /* MARPAXML_API_DOM_ATTR_H */
