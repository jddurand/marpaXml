#ifndef MARPAXML_API_DOM_TYPEINFO_H
#define MARPAXML_API_DOM_TYPEINFO_H

#include "marpaXml/cplus.h"

SUBCLASS(TypeInfo, Object)
  void          *ctx;
  unsigned long  DERIVATION_RESTRICTION;
  unsigned long  DERIVATION_EXTENSION;
  unsigned long  DERIVATION_UNION;
  unsigned long  DERIVATION_LIST;
VTABLE(TypeInfo, Object)
  String  *(*getTypeName)(TypeInfo *me);
  String  *(*getTypeNamespace)(TypeInfo *me);
  boolean  (*isDerivedFrom)(TypeInfo *me, String *typeNamespaceArg, String *typeNameArg, int derivationMethod);
METHODS
  TypeInfo *TypeInfo_new();
  void      TypeInfo_free(TypeInfo *me);
END_CLASS

#endif /* MARPAXML_API_DOM_TYPEINFO_H */
