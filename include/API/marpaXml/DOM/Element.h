#ifndef MARPAXML_API_DOM_ELEMENT_H
#define MARPAXML_API_DOM_ELEMENT_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Element, Node)
  void *ctx;
VTABLE(Element, Node)
  String   *(*getAttribute)(Element *me, String *name);
  Attr     *(*getAttributeNode)(Element *me, String *name);
  Attr     *(*getAttributeNodeNS)(Element *me, String *namespaceURI, String *localName);
  String   *(*getAttributeNS)(Element *me, String *namespaceURI, String *localName);
  NodeList *(*getElementsByTagName)(Element *me, String *name);
  NodeList *(*getElementsByTagNameNS)(Element *me, String *namespaceURI, String *localName);
  TypeInfo *(*getSchemaTypeInfo)(Element *me);
  String   *(*getTagName)(Element *me);
  boolean   (*hasAttribute)(Element *me, String *name);
  boolean   (*hasAttributeNS)(Element *me, String *namespaceURI, String *localName);
  void      (*removeAttribute)(Element *me, String *name);
  Attr     *(*removeAttributeNode)(Element *me, Attr *oldAttr);
  void      (*removeAttributeNS)(Element *me, String *namespaceURI, String *localName);
  void      (*setAttribute)(Element *me, String *name, String *value);
  Attr     *(*setAttributeNode)(Element *me, Attr *newAttr);
  Attr     *(*setAttributeNodeNS)(Element *me, Attr *newAttr);
  void      (*setAttributeNS)(Element *me, String *namespaceURI, String *qualifiedName, String *value);
  void      (*setIdAttribute)(Element *me, String *name, boolean isId);
  void      (*setIdAttributeNode)(Element *me, Attr *idAttr, boolean isId);
  void      (*setIdAttributeNS)(Element *me, String *namespaceURI, String *localName, boolean isId);
METHODS
  Element *Element_new();
  void     Element_free(Element *me);
END_CLASS

#endif /* MARPAXML_API_DOM_ELEMENT_H */
