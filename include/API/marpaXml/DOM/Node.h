#ifndef MARPAXML_API_DOM_NODE_H
#define MARPAXML_API_DOM_NODE_H

#include "marpaXml/_types.h"
#include "marpaXml/cplus.h"

SUBCLASS(Node, Object)
  void *ctx;
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
VTABLE(Node, Object)
  Node 	       *(*appendChild)(Node *me, Node *newChild);
  Node 	       *(*cloneNode)(Node *me, boolean deep);
  short         (*compareDocumentPosition)(Node *me, Node *other);
  NamedNodeMap *(*getAttributes)(Node *me);
  String       *(*getBaseURI)(Node *me);
  NodeList     *(*getChildNodes)(Node *me);
  Object       *(*getFeature)(Node *me, String *feature, String *version);
  Node         *(*getFirstChild)(Node *me);
  Node         *(*getLastChild)(Node *me);
  String       *(*getLocalName)(Node *me);
  String       *(*getNamespaceURI)(Node *me);
  Node         *(*getNextSibling)(Node *me);
  String       *(*getNodeName)(Node *me);
  short         (*getNodeType)(Node *me);
  String       *(*getNodeValue)(Node *me);
  Document     *(*getOwnerDocument)(Node *me);
  Node         *(*getParentNode)(Node *me);
  String       *(*getPrefix)(Node *me);
  Node         *(*getPreviousSibling)(Node *me);
  String       *(*getTextContent)(Node *me);
  Object       *(*getUserData)(Node *me, String *key);
  boolean       (*hasAttributes)(Node *me);
  boolean       (*hasChildNodes)(Node *me);
  Node         *(*insertBefore)(Node *me, Node *newChild, Node *refChild);
  boolean       (*isDefaultNamespace)(Node *me, String *namespaceURI);
  boolean       (*isEqualNode)(Node *me, Node *arg);
  boolean       (*isSameNode)(Node *me, Node *other);
  boolean       (*isSupported)(Node *me, String *feature, String *version);
  String       *(*lookupNamespaceURI)(Node *me, String *prefix);
  String       *(*lookupPrefix)(Node *me, String *namespaceURI);
  void          (*normalize)(Node *me);
  Node         *(*removeChild)(Node *me, Node *oldChild);
  Node         *(*replaceChild)(Node *me, Node *newChild, Node *oldChild);
  void          (*setNodeValue)(Node *me, String *nodeValue);
  void          (*setPrefix)(Node *me, String *prefix);
  void          (*setTextContent)(Node *me, String *textContent);
  Object       *(*setUserData)(Node *me, String *key, Object *data, UserDataHandler *handler);
METHODS
  Node *(*Node_new)();
  void  Node_free(Node *me);
END_CLASS

#endif /* MARPAXML_API_DOM_NODE_H */
