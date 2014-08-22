#ifndef MARPAXML_API_DOM_DOMIMPLEMENTATION_H
#define MARPAXML_API_DOM_DOMIMPLEMENTATION_H

#include "marpaXml/cplus.h"

SUBCLASS(DOMImplementation, Object)
  VTABLE(DOMImplementation, Object)
METHODS
  Document     createDocument(String namespaceURI, String qualifiedName, DocumentType doctype);
  DocumentType createDocumentType(String qualifiedName, String publicId, String systemId);
  Object       getFeature(String feature, String version);
  boolean      hasFeature(String feature, String version);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMIMPLEMENTATION_H */
