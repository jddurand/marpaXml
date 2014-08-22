#ifndef MARPAXML_API_DOM_DOCUMENTTYPE_H
#define MARPAXML_API_DOM_DOCUMENTTYPE_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(DocumentType, Node)
  void *ctx;
VTABLE(DocumentType, Node)
  NamedNodeMap *(*getEntities)(DocumentType *me);
  String       *(*getInternalSubset)(DocumentType *me);
  String       *(*getName)(DocumentType *me);
  NamedNodeMap *(*getNotations)(DocumentType *me);
  String       *(*getPublicId)(DocumentType *me);
  String       *(*getSystemId)(DocumentType *me);
METHODS
  DocumentType *DocumentType_new();
  void          DocumentType_free(DocumentType *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOCUMENTTYPE_H */
