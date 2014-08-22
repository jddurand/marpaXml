#ifndef MARPAXML_API_DOM_NAMELIST_H
#define MARPAXML_API_DOM_NAMELIST_H

#include "marpaXml/cplus.h"

SUBCLASS(NameList, Object)
  void *ctx;
VTABLE(NameList, Object)
  boolean  (*contains)(NameList *me, String *str);
  boolean  (*containsNS)(NameList *me, String *namespaceURI, String *name);
  int      (*getLength)(NameList *me);
  String  *(*getName)(NameList *me, int index);
  String  *(*getNamespaceURI)(NameList *me, int index);
METHODS
  NameList *NameList_new();
  void      NameList_free(NameList *me);
END_CLASS

#endif /* MARPAXML_API_DOM_NAMELIST_H */
