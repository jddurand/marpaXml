#ifndef MARPAXML_API_DOM_ELEMENT_H
#define MARPAXML_API_DOM_ELEMENT_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Element, Node)
  VTABLE(Element, Node)
METHODS
  String   getAttribute(String name);
  Attr     getAttributeNode(String name);
  Attr     getAttributeNodeNS(String namespaceURI, String localName);
  String   getAttributeNS(String namespaceURI, String localName);
  NodeList getElementsByTagName(String name);
  NodeList getElementsByTagNameNS(String namespaceURI, String localName);
  TypeInfo getSchemaTypeInfo();
  String   getTagName();
  boolean  hasAttribute(String name);
  boolean  hasAttributeNS(String namespaceURI, String localName);
  void     removeAttribute(String name);
  Attr     removeAttributeNode(Attr oldAttr);
  void     removeAttributeNS(String namespaceURI, String localName);
  void     setAttribute(String name, String value);
  Attr     setAttributeNode(Attr newAttr);
  Attr     setAttributeNodeNS(Attr newAttr);
  void     setAttributeNS(String namespaceURI, String qualifiedName, String value);
  void     setIdAttribute(String name, boolean isId);
  void     setIdAttributeNode(Attr idAttr, boolean isId);
  void     setIdAttributeNS(String namespaceURI, String localName, boolean isId);
END_CLASS

#endif /* MARPAXML_API_DOM_ELEMENT_H */
