#ifndef MARPAXML_API_DOM_ENTITY_H
#define MARPAXML_API_DOM_ENTITY_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Entity, Node)
  VTABLE(Entity, Node)
METHODS
  String getInputEncoding();
  String getNotationName();
  String getPublicId();
  String getSystemId();
  String getXmlEncoding();
  String getXmlVersion();
END_CLASS

#endif /* MARPAXML_API_DOM_ENTITY_H */
