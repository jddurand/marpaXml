#ifndef MARPAXML_API_DOM_NODE_H
#define MARPAXML_API_DOM_NODE_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(marpaXml_DOM_Node, Object)
  VTABLE(marpaXml_DOM_Node, Object)
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
  marpaXml_DOM_Node 	appendChild(marpaXml_DOM_Node newChild);
  marpaXml_DOME_Node 	cloneNode(marpaXml_Boolean deep);
  short                 compareDocumentPosition(Node other);
Compares the reference node, i.e.
NamedNodeMap 	getAttributes()
A NamedNodeMap containing the attributes of this node (if it is an Element) or null otherwise.
String 	getBaseURI()
The absolute base URI of this node or null if the implementation wasn't able to obtain an absolute URI.
NodeList 	getChildNodes()
A NodeList that contains all children of this node.
Object 	getFeature(String feature, String version)
This method returns a specialized object which implements the specialized APIs of the specified feature and version, as specified in .
Node 	getFirstChild()
The first child of this node.
Node 	getLastChild()
The last child of this node.
String 	getLocalName()
Returns the local part of the qualified name of this node.
String 	getNamespaceURI()
The namespace URI of this node, or null if it is unspecified (see ).
Node 	getNextSibling()
The node immediately following this node.
String 	getNodeName()
The name of this node, depending on its type; see the table above.
short 	getNodeType()
A code representing the type of the underlying object, as defined above.
String 	getNodeValue()
The value of this node, depending on its type; see the table above.
Document 	getOwnerDocument()
The Document object associated with this node.
Node 	getParentNode()
The parent of this node.
String 	getPrefix()
The namespace prefix of this node, or null if it is unspecified.
Node 	getPreviousSibling()
The node immediately preceding this node.
String 	getTextContent()
This attribute returns the text content of this node and its descendants.
Object 	getUserData(String key)
Retrieves the object associated to a key on a this node.
boolean 	hasAttributes()
Returns whether this node (if it is an element) has any attributes.
boolean 	hasChildNodes()
Returns whether this node has any children.
Node 	insertBefore(Node newChild, Node refChild)
Inserts the node newChild before the existing child node refChild.
boolean 	isDefaultNamespace(String namespaceURI)
This method checks if the specified namespaceURI is the default namespace or not.
boolean 	isEqualNode(Node arg)
Tests whether two nodes are equal.
boolean 	isSameNode(Node other)
Returns whether this node is the same node as the given one.
boolean 	isSupported(String feature, String version)
Tests whether the DOM implementation implements a specific feature and that feature is supported by this node, as specified in .
String 	lookupNamespaceURI(String prefix)
Look up the namespace URI associated to the given prefix, starting from this node.
String 	lookupPrefix(String namespaceURI)
Look up the prefix associated to the given namespace URI, starting from this node.
void 	normalize()
Puts all Text nodes in the full depth of the sub-tree underneath this Node, including attribute nodes, into a "normal" form where only structure (e.g., elements, comments, processing instructions, CDATA sections, and entity references) separates Text nodes, i.e., there are neither adjacent Text nodes nor empty Text nodes.
Node 	removeChild(Node oldChild)
Removes the child node indicated by oldChild from the list of children, and returns it.
Node 	replaceChild(Node newChild, Node oldChild)
Replaces the child node oldChild with newChild in the list of children, and returns the oldChild node.
void 	setNodeValue(String nodeValue)
The value of this node, depending on its type; see the table above.
void 	setPrefix(String prefix)
The namespace prefix of this node, or null if it is unspecified.
void 	setTextContent(String textContent)
This attribute returns the text content of this node and its descendants.
Object 	setUserData(String key, Object data, UserDataHandler handler)
Associate an object to a key on this node.
END_CLASS

#endif /* MARPAXML_API_DOM_NODE_H */
