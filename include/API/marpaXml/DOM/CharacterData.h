#ifndef MARPAXML_API_DOM_CHARACTERDATA_H
#define MARPAXML_API_DOM_CHARACTERDATA_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(CharacterData, Node)
  VTABLE(CharacterData, Node)
METHODS
  void   appendData(String arg);
  void   deleteData(int offset, int count);
  String getData();
  int    getLength();
  void   insertData(int offset, String arg);
  void   replaceData(int offset, int count, String arg);
  void   setData(String data);
  String substringData(int offset, int count);
END_CLASS

#endif /* MARPAXML_API_DOM_CHARACTERDATA_H */
