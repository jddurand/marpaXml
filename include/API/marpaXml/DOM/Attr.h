#ifndef MARPAXML_API_DOM_ATTR_H
#define MARPAXML_API_DOM_ATTR_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Attr, Node)
  void *ctx;
VTABLE(Attr, Node)
  String   *(*getName)(Attr *me);
  Element  *(*getOwnerElement)(Attr *me);
  TypeInfo *(*getSchemaTypeInfo)(Attr *me);
  boolean   (*getSpecified)(Attr *me);
  String   *(*getValue)(Attr *me);
  boolean   (*isId)(Attr *me);
  void      (*setValue)(Attr *me, String *value);
METHODS
  Attr     *Attr_new();
  void      Attr_free(Attr *me);
END_CLASS

#endif /* MARPAXML_API_DOM_ATTR_H */
