#ifndef MARPAXML_API_DOM_ENTITY_H
#define MARPAXML_API_DOM_ENTITY_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Entity, Node)
  void *ctx;
VTABLE(Entity, Node)
  String *(*getInputEncoding)(Entity *me);
  String *(*getNotationName)(Entity *me);
  String *(*getPublicId)(Entity *me);
  String *(*getSystemId)(Entity *me);
  String *(*getXmlEncoding)(Entity *me);
  String *(*getXmlVersion)(Entity *me);
METHODS
  Entity *Entity_new();
  void    Entity_free(Entity *me);
END_CLASS

#endif /* MARPAXML_API_DOM_ENTITY_H */
