/*
 * Copyright (c) 2004 World Wide Web Consortium,
 *
 * (Massachusetts Institute of Technology, European Research Consortium for
 * Informatics and Mathematics, Keio University). All Rights Reserved. This
 * work is distributed under the W3C(r) Software License [1] in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */

/* File: http://www.w3.org/TR/2004/REC-DOM-Level-3-Core-20040407/dom.idl */

/* We are NOT going to build a generic object-oriented system in C using
   a vtable, derived and parent pointers and so on. The DOM structure is
   fixed,  and we know in advance who derive from what. For instance:

   Parent           Child
   ------           -----
   Node          -> CharacterData 
   Node          -> Attr
   Node          -> Element
   CharacterData -> Text
   CharacterData -> Comment
   Text          -> CDATASection
   Node          -> DocumentType
   Node          -> Notation
   Node          -> Entity
   Node          -> EntityReference
   Node          -> ProcessingInstruction
   Node          -> DocumentFragment
   Node          -> Document
   
   I.e. we see that there is NO recursion in the model, that we rewrite like this:

   Parent           Child                     Child2           Child3
   ------           -----                     ------           ------
   Node          -> CharacterData          -> Text          -> CDATASection
   Node          -> CharacterData          -> Comment
   Node          -> Attr
   Node          -> Element
   Node          -> DocumentType
   Node          -> Notation
   Node          -> Entity
   Node          -> EntityReference
   Node          -> ProcessingInstruction
   Node          -> DocumentFragment
   Node          -> Document

   Just a remark, the "parent" of everything is Node (it returns other types like
   DOMImplementation).

   This mean that we can duplicate the methods/accessors prototypes of Node, CharacterData and Text
   to provide direct methods within every structures of CharacterData, Attr, Element, DocumentType,
   Notation, Entity, EntityReference, ProcessingInstruction, DocumentFragement, Document, Text,
   Comment and CDATASection.

   The implementation will of course have a hiden pointer to the parent.

   We are NOT going to play with setjmp/longjmp, win32 TLS, etc... EVERY function that can raise
   an exception will fill the exception code if needed. This mean that the application on top
   on this API will always have to: reset explicitely the exception code before calling
   an API that can set it; and check the exception code at return.

   If the exception code is setted, meaning of the return value is undefined, although it will
   be usually meaningful WHEN POSSIBLE.

   If exception code is == 0, no error.
   If exception code is  > 0, this is a DOM error code.
   If exception code is  < 0, this is a -errno error code.

   About DOMString, this API is explicitely using UTF-8, both in input and in output. Any attempt
   to use another encoding will result into unpredictable and definitely unreliable result.

   Up to the caller to convert DOMString to another encoding.
   Up to the caller to make sure input is in that particular encoding.
*/


#ifndef MARPAXML_DOM_H
#define MARPAXML_DOM_H

#define MARPAXML_DOM_TYPE(type)         marpaXml_DOM_ ## type ## _t
#define MARPAXML_DOM_STRUCT(type)       struct marpaXml_DOM_ ## type

#define MARPAXML_DOM_OBJECT_DECLARATION(type)				\
  typedef struct marpaXml_DOM_ ## type *marpaXml_DOM_ ## type ## _t;	\
  marpaXml_DOM_ ## type ## _t marpaXml_DOM_ ## type ## _new();		\
  void marpaXml_DOM_ ## type ## _destroy()

typedef enum {
  DOM_FALSE = 0,
  DOM_TRUE = 1
} MARPAXML_DOM_TYPE(boolean);

typedef unsigned char                  *MARPAXML_DOM_TYPE(DOMString);    /* We use UTF-8 */
typedef unsigned long long              MARPAXML_DOM_TYPE(DOMTimeStamp);
typedef void                           *MARPAXML_DOM_TYPE(DOMUserData);
typedef void                           *MARPAXML_DOM_TYPE(DOMObject);

MARPAXML_DOM_OBJECT_DECLARATION(DOMImplementation);
MARPAXML_DOM_OBJECT_DECLARATION(DocumentType);
MARPAXML_DOM_OBJECT_DECLARATION(Document);
MARPAXML_DOM_OBJECT_DECLARATION(NodeList);
MARPAXML_DOM_OBJECT_DECLARATION(NamedNodeMap);
MARPAXML_DOM_OBJECT_DECLARATION(UserDataHandler);
MARPAXML_DOM_OBJECT_DECLARATION(Element);
MARPAXML_DOM_OBJECT_DECLARATION(TypeInfo);
MARPAXML_DOM_OBJECT_DECLARATION(DOMLocator);
MARPAXML_DOM_OBJECT_DECLARATION(DOMException);
MARPAXML_DOM_OBJECT_DECLARATION(DOMStringList);
MARPAXML_DOM_OBJECT_DECLARATION(NameList);
MARPAXML_DOM_OBJECT_DECLARATION(DOMImplementationList);
MARPAXML_DOM_OBJECT_DECLARATION(DOMImplementationSource);
MARPAXML_DOM_OBJECT_DECLARATION(Node);
MARPAXML_DOM_OBJECT_DECLARATION(Attr);
MARPAXML_DOM_OBJECT_DECLARATION(Text);
MARPAXML_DOM_OBJECT_DECLARATION(Comment);
MARPAXML_DOM_OBJECT_DECLARATION(DOMError);
MARPAXML_DOM_OBJECT_DECLARATION(DOMErrorHandler);
MARPAXML_DOM_OBJECT_DECLARATION(DOMConfiguration);
MARPAXML_DOM_OBJECT_DECLARATION(CDATASection);
MARPAXML_DOM_OBJECT_DECLARATION(Notation);
MARPAXML_DOM_OBJECT_DECLARATION(Entity);
MARPAXML_DOM_OBJECT_DECLARATION(EntityReference);
MARPAXML_DOM_OBJECT_DECLARATION(ProcessingInstruction);
MARPAXML_DOM_OBJECT_DECLARATION(DocumentFragment);

struct DOMException {
  unsigned short  code;
};

enum {
  /* ExceptionCode */
  INDEX_SIZE_ERR                 =  1,
  DOMSTRING_SIZE_ERR             =  2,
  HIERARCHY_REQUEST_ERR          =  3,
  WRONG_DOCUMENT_ERR             =  4,
  INVALID_CHARACTER_ERR          =  5,
  NO_DATA_ALLOWED_ERR            =  6,
  NO_MODIFICATION_ALLOWED_ERR    =  7,
  NOT_FOUND_ERR                  =  8,
  NOT_SUPPORTED_ERR              =  9,
  INUSE_ATTRIBUTE_ERR            = 10,
  INVALID_STATE_ERR              = 11, /* Introduced in DOM Level 2: */
  SYNTAX_ERR                     = 12, /* Introduced in DOM Level 2: */
  INVALID_MODIFICATION_ERR       = 13, /* Introduced in DOM Level 2: */
  NAMESPACE_ERR                  = 14, /* Introduced in DOM Level 2: */
  INVALID_ACCESS_ERR             = 15, /* Introduced in DOM Level 2: */
  VALIDATION_ERR                 = 16, /* Introduced in DOM Level 3: */
  TYPE_MISMATCH_ERR              = 17, /* Introduced in DOM Level 3: */

  /* NodeType */
  ELEMENT_NODE                   =  1,
  ATTRIBUTE_NODE                 =  2,
  TEXT_NODE                      =  3,
  CDATA_SECTION_NODE             =  4,
  ENTITY_REFERENCE_NODE          =  5,
  ENTITY_NODE                    =  6,
  PROCESSING_INSTRUCTION_NODE    =  7,
  COMMENT_NODE                   =  8,
  DOCUMENT_NODE                  =  9,
  DOCUMENT_TYPE_NODE             = 10,
  DOCUMENT_FRAGMENT_NODE         = 11,
  NOTATION_NODE                  = 12,

  /* DocumentPosition */
  DOCUMENT_POSITION_DISCONNECTED = 0x01,
  DOCUMENT_POSITION_PRECEDING    = 0x02,
  DOCUMENT_POSITION_FOLLOWING    = 0x04,
  DOCUMENT_POSITION_CONTAINS     = 0x08,
  DOCUMENT_POSITION_CONTAINED_BY = 0x10,
  DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20,

  /* DerivationMethods */
  DERIVATION_RESTRICTION         = 0x00000001,
  DERIVATION_EXTENSION           = 0x00000002,
  DERIVATION_UNION               = 0x00000004,
  DERIVATION_LIST                = 0x00000008,

  /* OperationType */
  NODE_CLONED                    = 1,
  NODE_IMPORTED                  = 2,
  NODE_DELETED                   = 3,
  NODE_RENAMED                   = 4,
  NODE_ADOPTED                   = 5,

  /* ErrorSeverity */
  SEVERITY_WARNING               = 1,
  SEVERITY_ERROR                 = 2,
  SEVERITY_FATAL_ERROR           = 3

};


/* Introduced in DOM Level 3: */
struct DOMStringList {
  MARPAXML_DOM_TYPE(DOMString)            (*item)(unsigned long index);
  unsigned long                           (*length_get)();
  MARPAXML_DOM_TYPE(boolean)              (*contains)(MARPAXML_DOM_TYPE(DOMString) str);
};

/* Introduced in DOM Level 3: */
struct NameList {
  MARPAXML_DOM_TYPE(DOMString)            (*getName)(unsigned long index);
  MARPAXML_DOM_TYPE(DOMString)            (*getNamespaceURI)(unsigned long index);
  unsigned long                           (*length_get)();
  MARPAXML_DOM_TYPE(boolean)              (*contains)(MARPAXML_DOM_TYPE(DOMString) str);
  MARPAXML_DOM_TYPE(boolean)              (*containsNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) name);
};

/* Introduced in DOM Level 3: */
struct DOMImplementationList {
  MARPAXML_DOM_TYPE(DOMImplementation)    (*item)(unsigned long index);
  unsigned long   length;
};

/* Introduced in DOM Level 3: */
struct DOMImplementationSource {
  MARPAXML_DOM_TYPE(DOMImplementation)     (*getDOMImplementation)(MARPAXML_DOM_TYPE(DOMString) features);
  MARPAXML_DOM_TYPE(DOMImplementationList) (*getDOMImplementationList)(MARPAXML_DOM_TYPE(DOMString) features);
};

struct DOMImplementation {
  MARPAXML_DOM_TYPE(boolean)               (*hasFeature)(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version);
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(DocumentType)          (*createDocumentType)(MARPAXML_DOM_TYPE(DOMString) qualifiedName, MARPAXML_DOM_TYPE(DOMString) publicId, MARPAXML_DOM_TYPE(DOMString) systemId); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Document)              (*createDocument)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) qualifiedName, MARPAXML_DOM_TYPE(DocumentType) doctype); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMObject)             (*getFeature)(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version);
};

#define MARPAXML_NODE_DECLARATIONS 					\
  MARPAXML_DOM_TYPE(DOMString)             (*nodeName_get)();					\
  MARPAXML_DOM_TYPE(DOMString)             (*nodeValue_set)(MARPAXML_DOM_TYPE(DOMString) nodeName);  /* raises(DOMException) */ \
  MARPAXML_DOM_TYPE(DOMString)             (*nodeValue_get)();  /* raises(DOMException) */	\
  unsigned short                           (*nodeType_get)();					\
  MARPAXML_DOM_TYPE(Node)                  (*parentNode_get)();					\
  MARPAXML_DOM_TYPE(NodeList)              (*childNodes_get)();					\
  MARPAXML_DOM_TYPE(Node)                  (*firstChild_get)();					\
  MARPAXML_DOM_TYPE(Node)                  (*lastChild_get)();					\
  MARPAXML_DOM_TYPE(Node)                  (*previousSibling_get)();				\
  MARPAXML_DOM_TYPE(Node)                  (*nextSibling_get)();					\
  MARPAXML_DOM_TYPE(NamedNodeMap)          (*attributes_get)();					\
  /* Modified in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(Document)              (*ownerDocument_get)();				\
  /* Modified in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(Node)                  (*insertBefore)(MARPAXML_DOM_TYPE(Node) newChild, MARPAXML_DOM_TYPE(Node) refChild);  /* raises(DOMException) */ \
  /* Modified in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(Node)                  (*replaceChild)(MARPAXML_DOM_TYPE(Node) newChild, MARPAXML_DOM_TYPE(Node) oldChild);  /* raises(DOMException) */ \
  /* Modified in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(Node)                  (*removeChild)(MARPAXML_DOM_TYPE(Node) oldChild);  /* raises(DOMException) */	\
  /* Modified in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(Node)                  (*appendChild)(MARPAXML_DOM_TYPE(Node) newChild);  /* raises(DOMException) */	\
  MARPAXML_DOM_TYPE(boolean)               (*hasChildNodes)();					\
  MARPAXML_DOM_TYPE(Node)                  (*cloneNode)(MARPAXML_DOM_TYPE(boolean) deep);			\
  /* Modified in DOM Level 3: */					\
  void                                     (*normalize)();					\
  /* Introduced in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(boolean)               (*isSupported)(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version); \
  /* Introduced in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*namespaceURI_get)();				\
  /* Introduced in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*prefix_get)();					\
  MARPAXML_DOM_TYPE(DOMString)             (*prefix_set)(MARPAXML_DOM_TYPE(DOMString) prefix);  /* raises(DOMException) on setting */ \
  /* Introduced in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*localName_get)();					\
  /* Introduced in DOM Level 2: */					\
  MARPAXML_DOM_TYPE(boolean)               (*hasAttributes)();					\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*baseURI_get)();					\
  /* Introduced in DOM Level 3: */					\
  unsigned short                           (*compareDocumentPosition)(MARPAXML_DOM_TYPE(Node) other);  /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*textContent_get)();  /* raises(DOMException) */	\
  MARPAXML_DOM_TYPE(DOMString)             (*textContent_set)(MARPAXML_DOM_TYPE(DOMString) textContent);  /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(boolean)               (*isSameNode)(MARPAXML_DOM_TYPE(Node) other);			\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*lookupPrefix)(MARPAXML_DOM_TYPE(DOMString) namespaceURI);		\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(boolean)               (*isDefaultNamespace)(MARPAXML_DOM_TYPE(DOMString) namespaceURI);	\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*lookupNamespaceURI)(MARPAXML_DOM_TYPE(DOMString) prefix);		\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(boolean)               (*isEqualNode)(MARPAXML_DOM_TYPE(Node) arg);			\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMObject)             (*getFeature)(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version); \
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMUserData)           (*setUserData)(MARPAXML_DOM_TYPE(DOMString) key, MARPAXML_DOM_TYPE(DOMUserData) data, MARPAXML_DOM_TYPE(UserDataHandler) handler); \
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMUserData)           (*getUserData)(MARPAXML_DOM_TYPE(DOMString) key);

struct Node {
  MARPAXML_NODE_DECLARATIONS;
};

struct NodeList {
  MARPAXML_DOM_TYPE(Node)                  (*item)(unsigned long index);
  unsigned long                            (*length_get)();
};

struct NamedNodeMap {
  MARPAXML_DOM_TYPE(Node)                  (*getNamedItem)(MARPAXML_DOM_TYPE(DOMString) name);
  MARPAXML_DOM_TYPE(Node)                  (*setNamedItem)(MARPAXML_DOM_TYPE(Node) arg); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(Node)                  (*removeNamedItem)(MARPAXML_DOM_TYPE(DOMString) name); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(Node)                  (*item)(unsigned long index);
  unsigned long                            (*length)();
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Node)                  (*getNamedItemNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Node)                  (*setNamedItemNS)(MARPAXML_DOM_TYPE(Node) arg); /* raises(DOMException) */
    /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Node)                  (*removeNamedItemNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
};

#define MARPAXML_CHARACTERDATA_DECLARATIONS \
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */		\
  MARPAXML_DOM_TYPE(DOMString)             (*data_get)(); /* raises(DOMException) */		\
  MARPAXML_DOM_TYPE(DOMString)             (*data_set)(MARPAXML_DOM_TYPE(DOMString) data); /* raises(DOMException) */ \
  unsigned long                            (*length_get)();					\
  MARPAXML_DOM_TYPE(DOMString)             (*substringData)(unsigned long offset, unsigned long count); /* raises(DOMException) */ \
  void                                     (*appendData)(MARPAXML_DOM_TYPE(DOMString) arg); /* raises(DOMException) */	\
  void                                     (*insertData)(unsigned long offset, MARPAXML_DOM_TYPE(DOMString) arg); /* raises(DOMException) */ \
  void                                     (*deleteData)(unsigned long offset, unsigned long count); /* raises(DOMException) */ \
  void                                     (*replaceData)(unsigned long offset, unsigned long count, MARPAXML_DOM_TYPE(DOMString) arg); /* raises(DOMException) */ \

struct CharacterData {
  MARPAXML_CHARACTERDATA_DECLARATIONS;
};

struct Attr {
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*name_get)();
  MARPAXML_DOM_TYPE(boolean)               (*specified_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*value_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*value_set)(MARPAXML_DOM_TYPE(DOMString) value); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Element)               (*ownerElement_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(TypeInfo)              (*schemaTypeInfo_get)();
    /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(boolean)               (*isId_get)();
};

struct Element {
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*tagName_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*getAttribute)(MARPAXML_DOM_TYPE(DOMString) name);
  void                                     (*setAttribute)(MARPAXML_DOM_TYPE(DOMString) name, MARPAXML_DOM_TYPE(DOMString) value); /* raises(DOMException) */
  void                                     (*removeAttribute)(MARPAXML_DOM_TYPE(DOMString) name); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(Attr)                  (*getAttributeNode)(MARPAXML_DOM_TYPE(DOMString) name);
  MARPAXML_DOM_TYPE(Attr)                  (*setAttributeNode)(MARPAXML_DOM_TYPE(Attr) newAttr); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(Attr)                  (*removeAttributeNode)(MARPAXML_DOM_TYPE(Attr) oldAttr); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(NodeList)              (*getElementsByTagName)(MARPAXML_DOM_TYPE(DOMString) name);
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(DOMString)             (*getAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  void                                     (*setAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) qualifiedName, MARPAXML_DOM_TYPE(DOMString) value); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  void                                     (*removeAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Attr)                  (*getAttributeNodeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Attr)                  (*setAttributeNodeNS)(MARPAXML_DOM_TYPE(Attr) newAttr); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(NodeList)              (*getElementsByTagNameNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(boolean)               (*hasAttribute)(MARPAXML_DOM_TYPE(DOMString) name);
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(boolean)               (*hasAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(TypeInfo)              (*schemaTypeInfo_get)();
  /* Introduced in DOM Level 3: */
  void                                     (*setIdAttribute)(MARPAXML_DOM_TYPE(DOMString) name, MARPAXML_DOM_TYPE(boolean) isId); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  void                                     (*setIdAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName, MARPAXML_DOM_TYPE(boolean) isId); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  void                                     (*setIdAttributeNode)(MARPAXML_DOM_TYPE(Attr) idAttr, MARPAXML_DOM_TYPE(boolean) isId); /* raises(DOMException) */
};

#define MARPAXML_TEXT_DECLARATIONS \
  MARPAXML_CHARACTERDATA_DECLARATIONS;	 /* derived from CharacterData */ \
  MARPAXML_DOM_TYPE(Text)                  (*splitText)(unsigned long offset); /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(boolean)               (*isElementContentWhitespace_get)();		\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(DOMString)             (*wholeText_get)();					\
  /* Introduced in DOM Level 3: */					\
  MARPAXML_DOM_TYPE(Text)                  (*replaceWholeText)(MARPAXML_DOM_TYPE(DOMString) content); /* raises(DOMException) */ \

struct Text {
  MARPAXML_TEXT_DECLARATIONS;
};

struct Comment {
  MARPAXML_CHARACTERDATA_DECLARATIONS;	 /* derived from CharacterData */
};

/* Introduced in DOM Level 3: */
struct TypeInfo {
  MARPAXML_DOM_TYPE(DOMString)             (*typeName_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*typeNamespace_get)();
  MARPAXML_DOM_TYPE(boolean)               (*isDerivedFrom)(MARPAXML_DOM_TYPE(DOMString) typeNamespaceArg, MARPAXML_DOM_TYPE(DOMString) typeNameArg, unsigned long derivationMethod);
};

/* Introduced in DOM Level 3: */
struct UserDataHandler {
  void                                     (*handle)(unsigned short operation, MARPAXML_DOM_TYPE(DOMString) key, MARPAXML_DOM_TYPE(DOMUserData) data, MARPAXML_DOM_TYPE(Node) src, MARPAXML_DOM_TYPE(Node) dst);
};

/* Introduced in DOM Level 3: */
struct DOMError {
  unsigned short                           (*severity_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*message_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*type_get)();
  MARPAXML_DOM_TYPE(DOMObject)             (*relatedException_get)();
  MARPAXML_DOM_TYPE(DOMObject)             (*relatedData_get)();
  MARPAXML_DOM_TYPE(DOMLocator)            (*location_get)();
};

/* Introduced in DOM Level 3: */
struct DOMErrorHandler {
  MARPAXML_DOM_TYPE(boolean)               (*handleError)(MARPAXML_DOM_TYPE(DOMError) error);
};

/* Introduced in DOM Level 3: */
struct DOMLocator {
  long                                     (*lineNumber_get)();
  long                                     (*columnNumber_get)();
  long                                     (*byteOffset_get)();
  long                                     (*utf16Offset_get)();
  MARPAXML_DOM_TYPE(Node)                  (*relatedNode_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*uri_get)();
};

/* Introduced in DOM Level 3: */
struct DOMConfiguration {
  void                                     (*setParameter)(MARPAXML_DOM_TYPE(DOMString) name, MARPAXML_DOM_TYPE(DOMUserData) value); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(DOMUserData)           (*getParameter)(MARPAXML_DOM_TYPE(DOMString) name); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(boolean)               (*canSetParameter)(MARPAXML_DOM_TYPE(DOMString) name, MARPAXML_DOM_TYPE(DOMUserData) value);
  MARPAXML_DOM_TYPE(DOMStringList)         (*parameterNames_get)();
};

struct CDATASection {
  MARPAXML_TEXT_DECLARATIONS;	 /* derived from Text */
};

struct DocumentType {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*name_get)();
  MARPAXML_DOM_TYPE(NamedNodeMap)          (*entities_get)();
  MARPAXML_DOM_TYPE(NamedNodeMap)          (*notations_get)();
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(DOMString)             (*publicId_get)();
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(DOMString)             (*systemId_get)();
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(DOMString)             (*internalSubset_get)();
};

struct Notation {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*publicId_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*systemId_get)();
};

struct Entity {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*publicId_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*systemId_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*notationName_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*inputEncoding_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*xmlEncoding_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*xmlVersion_get)();
};

struct EntityReference {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
};

struct ProcessingInstruction {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  MARPAXML_DOM_TYPE(DOMString)             (*target_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*data_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*data_set)(MARPAXML_DOM_TYPE(DOMString) data); /* raises(DOMException) */
};

struct DocumentFragment {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
};

struct Document {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  /* Modified in DOM Level 3: */
  MARPAXML_DOM_TYPE(DocumentType)          (*doctype_get)();
  MARPAXML_DOM_TYPE(DOMImplementation)     (*implementation_get)();
  MARPAXML_DOM_TYPE(Element)               (*documentElement_get)();
  MARPAXML_DOM_TYPE(Element)               (*createElement)(MARPAXML_DOM_TYPE(DOMString) tagName); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(DocumentFragment)      (*createDocumentFragment)();
  MARPAXML_DOM_TYPE(Text)                  (*createTextNode)(MARPAXML_DOM_TYPE(DOMString) data);
  MARPAXML_DOM_TYPE(Comment)               (*createComment)(MARPAXML_DOM_TYPE(DOMString) data);
  MARPAXML_DOM_TYPE(CDATASection)          (*createCDATASection)(MARPAXML_DOM_TYPE(DOMString) data); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(ProcessingInstruction) (*createProcessingInstruction)(MARPAXML_DOM_TYPE(DOMString) target, MARPAXML_DOM_TYPE(DOMString) data); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(Attr)                  (*createAttribute)(MARPAXML_DOM_TYPE(DOMString) name); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(EntityReference)       (*createEntityReference)(MARPAXML_DOM_TYPE(DOMString) name); /* raises(DOMException) */
  MARPAXML_DOM_TYPE(NodeList)              (*getElementsByTagName)(MARPAXML_DOM_TYPE(DOMString) tagname);
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Node)                  (*importNode)(MARPAXML_DOM_TYPE(Node) importedNode, MARPAXML_DOM_TYPE(boolean) deep); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Element)               (*createElementNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) qualifiedName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Attr)                  (*createAttributeNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) qualifiedName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(NodeList)              (*getElementsByTagNameNS)(MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) localName);
  /* Introduced in DOM Level 2: */
  MARPAXML_DOM_TYPE(Element)               (*getElementById)(MARPAXML_DOM_TYPE(DOMString) elementId);
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*inputEncoding_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*xmlEncoding_get)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(boolean)               (*xmlStandalone_get)();
  MARPAXML_DOM_TYPE(boolean)               (*xmlStandalone_set)(MARPAXML_DOM_TYPE(boolean) xmlStandalone); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*xmlVersion_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*xmlVersion_set)(MARPAXML_DOM_TYPE(DOMString) xmlVersion); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(boolean)               (*strictErrorChecking_get)();
  MARPAXML_DOM_TYPE(boolean)               (*strictErrorChecking_set)(MARPAXML_DOM_TYPE(boolean) strictErrorChecking);
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMString)             (*documentURI_get)();
  MARPAXML_DOM_TYPE(DOMString)             (*documentURI_set)(MARPAXML_DOM_TYPE(DOMString) documentURI);
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(Node)                  (*adoptNode)(MARPAXML_DOM_TYPE(Node) source); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(DOMConfiguration)      (*domConfig_get)();
  /* Introduced in DOM Level 3: */
  void                                     (*normalizeDocument)();
  /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE(Node)                  (*renameNode)(MARPAXML_DOM_TYPE(Node) n, MARPAXML_DOM_TYPE(DOMString) namespaceURI, MARPAXML_DOM_TYPE(DOMString) qualifiedName); /* raises(DOMException) */
};

#endif /* MARPAXML_DOM_H_ */
