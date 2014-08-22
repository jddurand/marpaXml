#ifndef MARPAXML_API_DOM_ENTITYREFERENCE_H
#define MARPAXML_API_DOM_ENTITYREFERENCE_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(EntityReference, Node)
  void *ctx;
VTABLE(EntityReference, Node)
METHODS
  EntityReference *EntityReference_new();
  void             EntityReference_free(EntityReference *me);
END_CLASS

#endif /* MARPAXML_API_DOM_ENTITYREFERENCE_H */
