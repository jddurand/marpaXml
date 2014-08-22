#ifndef MARPAXML_API_DOM_DOCUMENT_H
#define MARPAXML_API_DOM_DOCUMENT_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(Document, Node)
  void *ctx;
VTABLE(Document, Node)
  Node                  *(*adoptNode)(Document *me, Node *source);
  Attr                  *(*createAttribute)(Document *me, String *name);
  Attr                  *(*createAttributeNS)(Document *me, String *namespaceURI, String *qualifiedName);
  CDATASection          *(*createCDATASection)(Document *me, String *data);
  Comment               *(*createComment)(Document *me, String *data);
  DocumentFragment      *(*createDocumentFragment)(Document *me);
  Element               *(*createElement)(Document *me, String *tagName);
  Element               *(*createElementNS)(Document *me, String *namespaceURI, String *qualifiedName);
  EntityReference       *(*createEntityReference)(Document *me, String *name);
  ProcessingInstruction *(*createProcessingInstruction)(Document *me, String *target, String *data);
  Text                  *(*createTextNode)(Document *me, String *data);
  DocumentType          *(*getDoctype)(Document *me);
  Element               *(*getDocumentElement)(Document *me);
  String                *(*getDocumentURI)(Document *me);
  DOMConfiguration      *(*getDomConfig)(Document *me);
  Element               *(*getElementById)(Document *me, String *elementId);
  NodeList              *(*getElementsByTagName)(Document *me, String *tagname);
  NodeList              *(*getElementsByTagNameNS)(Document *me, String *namespaceURI, String *localName);
  DOMImplementation     *(*getImplementation)(Document *me);
  String                *(*getInputEncoding)(Document *me);
  boolean                (*getStrictErrorChecking)(Document *me);
  String                *(*getXmlEncoding)(Document *me);
  boolean                (*getXmlStandalone)(Document *me);
  String                *(*getXmlVersion)(Document *me);
  Node                  *(*importNode)(Document *me, Node *importedNode, boolean deep);
  void                   (*normalizeDocument)(Document *me);
  Node                  *(*renameNode)(Document *me, Node *n, String *namespaceURI, String *qualifiedName);
  void                   (*setDocumentURI)(Document *me, String *documentURI);
  void                   (*setStrictErrorChecking)(Document *me, boolean *strictErrorChecking);
  void                   (*setXmlStandalone)(Document *me, boolean xmlStandalone);
  void                   (*setXmlVersion)(Document *me, String *xmlVersion);
METHODS
  Document *Document_new();
  void     Document_free(Document *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOCUMENT_H */
