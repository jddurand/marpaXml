#ifndef MARPAXML_API_DOM_TEXT_H
#define MARPAXML_API_DOM_TEXT_H

#include "marpaXml/DOM/CharacterData.h"

SUBCLASS(Text, CharacterData)
  void *ctx;
VTABLE(Text, CharacterData)
  String  *(*getWholeText)(Text *me);
  boolean  (*isElementContentWhitespace)(Text *me);
  Text    *(*replaceWholeText)(Text *me, String *content);
  Text    *(*splitText)(Text *me, int offset);
METHODS
  Text *Text_new();
  void  Text_free(Text *me);
END_CLASS

#endif /* MARPAXML_API_DOM_TEXT_H */
