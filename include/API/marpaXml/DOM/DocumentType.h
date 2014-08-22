#ifndef MARPAXML_API_DOM_DOCUMENTTYPE_H
#define MARPAXML_API_DOM_DOCUMENTTYPE_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(DocumentType, Node)
  VTABLE(DocumentType, Node)
METHODS
  NamedNodeMap getEntities();
  String       getInternalSubset();
  String       getName();
  NamedNodeMap getNotations();
  String       getPublicId();
  String       getSystemId();
END_CLASS

#endif /* MARPAXML_API_DOM_DOCUMENTTYPE_H */
