#ifndef MARPAXML_API_DOM_DOCUMENT_H
#define MARPAXML_API_DOM_DOCUMENT_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Document, Node)
  VTABLE(Document, Node)
METHODS
  Node                  adoptNode(Node source);
  Attr                  createAttribute(String name);
  Attr                  createAttributeNS(String namespaceURI, String qualifiedName);
  CDATASection          createCDATASection(String data);
  Comment               createComment(String data);
  DocumentFragment      createDocumentFragment(void);
  Element               createElement(String tagName);
  Element               createElementNS(String namespaceURI, String qualifiedName);
  EntityReference       createEntityReference(String name);
  ProcessingInstruction createProcessingInstruction(String target, String data);
  Text                  createTextNode(String data);
  DocumentType          getDoctype(void);
  Element               getDocumentElement(void);
  String                getDocumentURI(void);
  DOMConfiguration      getDomConfig(void);
  Element               getElementById(String elementId);
  NodeList              getElementsByTagName(String tagname);
  NodeList              getElementsByTagNameNS(String namespaceURI, String localName);
  DOMImplementation     getImplementation(void);
  String                getInputEncoding(void);
  boolean               getStrictErrorChecking(void);
  String                getXmlEncoding(void);
  boolean               getXmlStandalone(void);
  String                getXmlVersion(void);
  Node                  importNode(Node importedNode, boolean deep);
  void                  normalizeDocument(void);
  Node                  renameNode(Node n, String namespaceURI, String qualifiedName);
  void                  setDocumentURI(String documentURI);
  void                  setStrictErrorChecking(boolean strictErrorChecking);
  void                  setXmlStandalone(boolean xmlStandalone);
  void                  setXmlVersion(String xmlVersion);
END_CLASS

#endif /* MARPAXML_API_DOM_DOCUMENT_H */
