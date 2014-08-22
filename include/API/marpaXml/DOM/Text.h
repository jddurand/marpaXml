#ifndef MARPAXML_API_DOM_TEXT_H
#define MARPAXML_API_DOM_TEXT_H

#include "marpaXml/DOM/CharacterData.h"

SUBCLASS(Text, CharacterData)
  VTABLE(Text, CharacterData)
METHODS
  String  getWholeText();
  boolean isElementContentWhitespace();
  Text    replaceWholeText(String content);
  Text    splitText(int offset);
END_CLASS

#endif /* MARPAXML_API_DOM_TEXT_H */
