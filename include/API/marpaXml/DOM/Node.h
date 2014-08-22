#ifndef MARPAXML_API_DOM_NODE_H
#define MARPAXML_API_DOM_NODE_H

#include "marpaXml/cplus.h"

SUBCLASS(Node, Object)
  VTABLE(Node, Object)
  short ATTRIBUTE_NODE;
  short CDATA_SECTION_NODE;
  short COMMENT_NODE;
  short DOCUMENT_FRAGMENT_NODE;
  short DOCUMENT_NODE;
  short DOCUMENT_POSITION_CONTAINED_BY;
  short DOCUMENT_POSITION_CONTAINS;
  short DOCUMENT_POSITION_DISCONNECTED;
  short DOCUMENT_POSITION_FOLLOWING;
  short DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC;
  short DOCUMENT_POSITION_PRECEDING;
  short DOCUMENT_TYPE_NODE;
  short ELEMENT_NODE;
  short ENTITY_NODE;
  short ENTITY_REFERENCE_NODE;
  short NOTATION_NODE;
  short PROCESSING_INSTRUCTION_NODE;
  short TEXT_NODE;
METHODS
  Node 	       appendChild(Node newChild);
  Node 	       cloneNode(boolean deep);
  short        compareDocumentPosition(Node other);
  NamedNodeMap getAttributes(void);
  String       getBaseURI(void);
  NodeList     getChildNodes(void);
  Object       getFeature(String feature, String version);
  Node         getFirstChild(void);
  Node         getLastChild(void);
  String       getLocalName(void);
  String       getNamespaceURI(void);
  Node         getNextSibling(void);
  String       getNodeName(void);
  short        getNodeType(void);
  String       getNodeValue(void);
  Document     getOwnerDocument(void);
  Node         getParentNode(void);
  String       getPrefix(void);
  Node         getPreviousSibling(void);
  String       getTextContent(void);
  Object       getUserData(String key);
  boolean      hasAttributes(void);
  boolean      hasChildNodes(void);
  Node         insertBefore(Node newChild, Node refChild);
  boolean      isDefaultNamespace(String namespaceURI);
  boolean      isEqualNode(Node arg);
  boolean      isSameNode(Node other);
  boolean      isSupported(String feature, String version);
  String       lookupNamespaceURI(String prefix);
  String       lookupPrefix(String namespaceURI);
  void         normalize();
  Node         removeChild(Node oldChild);
  Node         replaceChild(Node newChild, Node oldChild);
  void         setNodeValue(String nodeValue);
  void         setPrefix(String prefix);
  void         setTextContent(String textContent);
  Object       setUserData(String key, Object data, UserDataHandler handler);
END_CLASS

#endif /* MARPAXML_API_DOM_NODE_H */
