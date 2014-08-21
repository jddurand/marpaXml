#ifndef MARPAXML_API_DOM_ATTR_H
#define MARPAXML_API_DOM_ATTR_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(marpaXml_DOM_Attr, marpaXml_DOM_Node)
  VTABLE(marpaXml_DOM_Attr, marpaXml_DOM_Node)
METHODS
  marpaXml_DOM_String   getName();
  marpaXml_DOM_Element  getOwnerElement();
  marpaXml_DOM_TypeInfo getSchemaTypeInfo();
  marpaXml_Boolean      getSpecified();
  marpaXml_DOM_String   getValue();
  marpaXml_Boolean      isId();
  void 	                setValue(marpaXml_DOM_String value);
END_CLASS

#endif /* MARPAXML_API_DOM_ATTR_H */
