#ifndef MARPAXML_API_DOM_NOTATION_H
#define MARPAXML_API_DOM_NOTATION_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Notation, Node)
  void *ctx;
VTABLE(Notation, Node)
  String *(*getPublicId)(Notation *me);
  String *(*getSystemId)(Notation *me);
METHODS
  Notation *Notation_new();
  void      Notation_free(Notation *me);
END_CLASS

#endif /* MARPAXML_API_DOM_NOTATION_H */
