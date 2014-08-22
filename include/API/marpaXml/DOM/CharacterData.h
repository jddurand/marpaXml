#ifndef MARPAXML_API_DOM_CHARACTERDATA_H
#define MARPAXML_API_DOM_CHARACTERDATA_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(CharacterData, Node)
  void *ctx;
VTABLE(CharacterData, Node)
  void           (*appendData)(CharacterData *me, String *arg);
  void           (*deleteData)(CharacterData *me, int offset, int count);
  String        *(*getData)(CharacterData *me);
  int            (*getLength)(CharacterData *me);
  void           (*insertData)(CharacterData *me, int offset, String *arg);
  void           (*replaceData)(CharacterData *me, int offset, int count, String *arg);
  void           (*setData)(CharacterData *me, String *data);
  String        *(*substringData)(CharacterData *me, int offset, int count);
METHODS
  CharacterData *CharacterData_new();
  void           CharacterData_free(CharacterData *me);
END_CLASS

#endif /* MARPAXML_API_DOM_CHARACTERDATA_H */
