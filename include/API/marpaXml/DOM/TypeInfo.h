#ifndef MARPAXML_API_DOM_TYPEINFO_H
#define MARPAXML_API_DOM_TYPEINFO_H

#include "marpaXml/cplus.h"

SUBCLASS(TypeInfo, Object)
  VTABLE(TypeInfo, Object)
  int DERIVATION_EXTENSION;
  int DERIVATION_LIST;
  int DERIVATION_RESTRICTION;
  int DERIVATION_UNION;
METHODS
  String  getTypeName();
  String  getTypeNamespace();
  boolean isDerivedFrom(String typeNamespaceArg, String typeNameArg, int derivationMethod);
END_CLASS

#endif /* MARPAXML_API_DOM_TYPEINFO_H */
