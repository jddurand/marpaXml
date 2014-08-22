#ifndef MARPAXML_API_DOM_NOTATION_H
#define MARPAXML_API_DOM_NOTATION_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Notation, Node)
  VTABLE(Notation, Node)
METHODS
  String getPublicId();
  String getSystemId();
END_CLASS

#endif /* MARPAXML_API_DOM_NOTATION_H */
