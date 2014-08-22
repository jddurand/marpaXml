#ifndef MARPAXML_API_DOM_COMMENT_H
#define MARPAXML_API_DOM_COMMENT_H

#include "marpaXml/DOM/CharacterData.h"

SUBCLASS(Comment, CharacterData)
  void *ctx;
VTABLE(Comment, CharacterData)
METHODS
  Comment *Comment_new();
  void     Comment_free(Comment *me);
END_CLASS

#endif /* MARPAXML_API_DOM_COMMENT_H */
