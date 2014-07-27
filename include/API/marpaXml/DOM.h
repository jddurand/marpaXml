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

typedef enum {
  DOM_FALSE = 0,
  DOM_TRUE = 1
} DOMTypeBoolean_t;

typedef unsigned char                  *DOMString_t;    /* We use UTF-8 */
typedef unsigned long long              DOMTimeStamp_t;
typedef void                           *DOMUserData_t;
typedef void                           *DOMObject_t;
#define MARPAXML_DOM_OBJECT_DECLARATION(type)			\
  typedef struct type *type ## _t;				\
  type ## _t type ## _new();					\
  void type ## _destroy()

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
  DOMString_t        (*item)(unsigned long index);
  unsigned long      (*length_get)();
  DOMTypeBoolean_t   (*contains)(DOMString_t str);
};

/* Introduced in DOM Level 3: */
struct NameList {
  DOMString_t        (*getName)(unsigned long index);
  DOMString_t        (*getNamespaceURI)(unsigned long index);
  unsigned long      (*length_get)();
  DOMTypeBoolean_t   (*contains)(DOMString_t str);
  DOMTypeBoolean_t   (*containsNS)(DOMString_t namespaceURI, DOMString_t name);
};

/* Introduced in DOM Level 3: */
struct DOMImplementationList {
  DOMImplementation_t  (*item)(unsigned long index);
  unsigned long   length;
};

/* Introduced in DOM Level 3: */
struct DOMImplementationSource {
  DOMImplementation_t  (*getDOMImplementation)(DOMString_t features);
  DOMImplementationList_t (*getDOMImplementationList)(DOMString_t features);
};

struct DOMImplementation {
  DOMTypeBoolean_t     (*hasFeature)(DOMString_t feature, DOMString_t version);
  /* Introduced in DOM Level 2: */
  DocumentType_t       (*createDocumentType)(DOMString_t qualifiedName, DOMString_t publicId, DOMString_t systemId); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Document_t           (*createDocument)(DOMString_t namespaceURI, DOMString_t qualifiedName, DocumentType_t doctype); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  DOMObject_t          (*getFeature)(DOMString_t feature, DOMString_t version);
};

#define MARPAXML_NODE_DECLARATIONS 					\
  DOMString_t     (*nodeName_get)();					\
  DOMString_t     (*nodeValue_set)(DOMString_t nodeName);  /* raises(DOMException) */ \
  DOMString_t     (*nodeValue_get)();  /* raises(DOMException) */	\
  unsigned short  (*nodeType_get)();					\
  Node_t          (*parentNode_get)();					\
  NodeList_t      (*childNodes_get)();					\
  Node_t          (*firstChild_get)();					\
  Node_t          (*lastChild_get)();					\
  Node_t          (*previousSibling_get)();				\
  Node_t          (*nextSibling_get)();					\
  NamedNodeMap_t  (*attributes_get)();					\
  /* Modified in DOM Level 2: */					\
  Document_t      (*ownerDocument_get)();				\
  /* Modified in DOM Level 3: */					\
  Node_t           (*insertBefore)(Node_t newChild, Node_t refChild);  /* raises(DOMException) */ \
  /* Modified in DOM Level 3: */					\
  Node_t           (*replaceChild)(Node_t newChild, Node_t oldChild);  /* raises(DOMException) */ \
  /* Modified in DOM Level 3: */					\
  Node_t           (*removeChild)(Node_t oldChild);  /* raises(DOMException) */	\
  /* Modified in DOM Level 3: */					\
  Node_t           (*appendChild)(Node_t newChild);  /* raises(DOMException) */	\
  DOMTypeBoolean_t (*hasChildNodes)();					\
  Node_t           (*cloneNode)(DOMTypeBoolean_t deep);			\
  /* Modified in DOM Level 3: */					\
  void             (*normalize)();					\
  /* Introduced in DOM Level 2: */					\
  DOMTypeBoolean_t (*isSupported)(DOMString_t feature, DOMString_t version); \
  /* Introduced in DOM Level 2: */					\
  DOMString_t     (*namespaceURI_get)();				\
  /* Introduced in DOM Level 2: */					\
  DOMString_t     (*prefix_get)();					\
  DOMString_t     (*prefix_set)(DOMString_t prefix);  /* raises(DOMException) on setting */ \
  /* Introduced in DOM Level 2: */					\
  DOMString_t     (*localName_get)();					\
  /* Introduced in DOM Level 2: */					\
  DOMTypeBoolean_t (*hasAttributes)();					\
  /* Introduced in DOM Level 3: */					\
  DOMString_t      (*baseURI_get)();					\
  /* Introduced in DOM Level 3: */					\
  unsigned short   (*compareDocumentPosition)(Node_t other);  /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  DOMString_t     (*textContent_get)();  /* raises(DOMException) */	\
  DOMString_t     (*textContent_set)(DOMString_t textContent);  /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  DOMTypeBoolean_t   (*isSameNode)(Node_t other);			\
  /* Introduced in DOM Level 3: */					\
  DOMString_t        (*lookupPrefix)(DOMString_t namespaceURI);		\
  /* Introduced in DOM Level 3: */					\
  DOMTypeBoolean_t   (*isDefaultNamespace)(DOMString_t namespaceURI);	\
  /* Introduced in DOM Level 3: */					\
  DOMString_t        (*lookupNamespaceURI)(DOMString_t prefix);		\
  /* Introduced in DOM Level 3: */					\
  DOMTypeBoolean_t   (*isEqualNode)(Node_t arg);			\
  /* Introduced in DOM Level 3: */					\
  DOMObject_t        (*getFeature)(DOMString_t feature, DOMString_t version); \
  /* Introduced in DOM Level 3: */					\
  DOMUserData_t      (*setUserData)(DOMString_t key, DOMUserData_t data, UserDataHandler_t handler); \
  /* Introduced in DOM Level 3: */					\
  DOMUserData_t      (*getUserData)(DOMString_t key);

struct Node {
  MARPAXML_NODE_DECLARATIONS;
};

struct NodeList {
  Node_t             (*item)(unsigned long index);
  unsigned long      (*length_get)();
};

struct NamedNodeMap {
  Node_t             (*getNamedItem)(DOMString_t name);
  Node_t             (*setNamedItem)(Node_t arg); /* raises(DOMException) */
  Node_t             (*removeNamedItem)(DOMString_t name); /* raises(DOMException) */
  Node_t             (*item)(unsigned long index);
  unsigned long      (*length)();
  /* Introduced in DOM Level 2: */
  Node_t             (*getNamedItemNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Node_t             (*setNamedItemNS)(Node_t arg); /* raises(DOMException) */
    /* Introduced in DOM Level 2: */
  Node_t             (*removeNamedItemNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
};

#define MARPAXML_CHARACTERDATA_DECLARATIONS \
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */		\
  DOMString_t        (*data_get)(); /* raises(DOMException) */		\
  DOMString_t        (*data_set)(DOMString_t data); /* raises(DOMException) */ \
  unsigned long      (*length_get)();					\
  DOMString_t        (*substringData)(unsigned long offset, unsigned long count); /* raises(DOMException) */ \
  void               (*appendData)(DOMString_t arg); /* raises(DOMException) */	\
  void               (*insertData)(unsigned long offset, DOMString_t arg); /* raises(DOMException) */ \
  void               (*deleteData)(unsigned long offset, unsigned long count); /* raises(DOMException) */ \
  void               (*replaceData)(unsigned long offset, unsigned long count, DOMString_t arg); /* raises(DOMException) */ \

struct CharacterData {
  MARPAXML_CHARACTERDATA_DECLARATIONS;
};

struct Attr {
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */
  DOMString_t       (*name_get)();
  DOMTypeBoolean_t  (*specified_get)();
  DOMString_t       (*value_get)();
  DOMString_t       (*value_set)(DOMString_t value); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Element_t         (*ownerElement_get)();
  /* Introduced in DOM Level 3: */
  TypeInfo_t        (*schemaTypeInfo_get)();
    /* Introduced in DOM Level 3: */
  DOMTypeBoolean_t  (*isId_get)();
};

struct Element {
  MARPAXML_NODE_DECLARATIONS;	 /* derived from Node */
  DOMString_t       (*tagName_get)();
  DOMString_t       (*getAttribute)(DOMString_t name);
  void              (*setAttribute)(DOMString_t name, DOMString_t value); /* raises(DOMException) */
  void              (*removeAttribute)(DOMString_t name); /* raises(DOMException) */
  Attr_t            (*getAttributeNode)(DOMString_t name);
  Attr_t            (*setAttributeNode)(Attr_t newAttr); /* raises(DOMException) */
  Attr_t            (*removeAttributeNode)(Attr_t oldAttr); /* raises(DOMException) */
  NodeList_t        (*getElementsByTagName)(DOMString_t name);
  /* Introduced in DOM Level 2: */
  DOMString_t       (*getAttributeNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  void              (*setAttributeNS)(DOMString_t namespaceURI, DOMString_t qualifiedName, DOMString_t value); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  void              (*removeAttributeNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Attr_t            (*getAttributeNodeNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Attr_t            (*setAttributeNodeNS)(Attr_t newAttr); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  NodeList_t        (*getElementsByTagNameNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  DOMTypeBoolean_t  (*hasAttribute)(DOMString_t name);
  /* Introduced in DOM Level 2: */
  DOMTypeBoolean_t  (*hasAttributeNS)(DOMString_t namespaceURI, DOMString_t localName); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  TypeInfo_t        (*schemaTypeInfo_get)();
  /* Introduced in DOM Level 3: */
  void              (*setIdAttribute)(DOMString_t name, DOMTypeBoolean_t isId); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  void              (*setIdAttributeNS)(DOMString_t namespaceURI, DOMString_t localName, DOMTypeBoolean_t isId); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  void              (*setIdAttributeNode)(Attr_t idAttr, DOMTypeBoolean_t isId); /* raises(DOMException) */
};

#define MARPAXML_TEXT_DECLARATIONS \
  MARPAXML_CHARACTERDATA_DECLARATIONS;	 /* derived from CharacterData */ \
  Text_t            (*splitText)(unsigned long offset); /* raises(DOMException) */ \
  /* Introduced in DOM Level 3: */					\
  DOMTypeBoolean_t  (*isElementContentWhitespace_get)();		\
  /* Introduced in DOM Level 3: */					\
  DOMString_t       (*wholeText_get)();					\
  /* Introduced in DOM Level 3: */					\
  Text_t            (*replaceWholeText)(DOMString_t content); /* raises(DOMException) */ \

struct Text {
  MARPAXML_TEXT_DECLARATIONS;
};

struct Comment {
  MARPAXML_CHARACTERDATA_DECLARATIONS;	 /* derived from CharacterData */
};

/* Introduced in DOM Level 3: */
struct TypeInfo {
  DOMString_t      (*typeName_get)();
  DOMString_t      (*typeNamespace_get)();
  DOMTypeBoolean_t (*isDerivedFrom)(DOMString_t typeNamespaceArg, DOMString_t typeNameArg, unsigned long derivationMethod);
};

/* Introduced in DOM Level 3: */
struct UserDataHandler {
  void             (*handle)(unsigned short operation, DOMString_t key, DOMUserData_t data, Node_t src, Node_t dst);
};

/* Introduced in DOM Level 3: */
struct DOMError {
  unsigned short  (*severity_get)();
  DOMString_t     (*message_get)();
  DOMString_t     (*type_get)();
  DOMObject_t     (*relatedException_get)();
  DOMObject_t     (*relatedData_get)();
  DOMLocator_t    (*location_get)();
};

/* Introduced in DOM Level 3: */
struct DOMErrorHandler {
  DOMTypeBoolean_t (*handleError)(DOMError_t error);
};

/* Introduced in DOM Level 3: */
struct DOMLocator {
  long            (*lineNumber_get)();
  long            (*columnNumber_get)();
  long            (*byteOffset_get)();
  long            (*utf16Offset_get)();
  Node_t          (*relatedNode_get)();
  DOMString_t     (*uri_get)();
};

/* Introduced in DOM Level 3: */
struct DOMConfiguration {
  void             (*setParameter)(DOMString_t name, DOMUserData_t value); /* raises(DOMException) */
  DOMUserData_t    (*getParameter)(DOMString_t name); /* raises(DOMException) */
  DOMTypeBoolean_t (*canSetParameter)(DOMString_t name, DOMUserData_t value);
  DOMStringList_t  (*parameterNames_get)();
};

struct CDATASection {
  MARPAXML_TEXT_DECLARATIONS;	 /* derived from Text */
};

struct DocumentType {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  DOMString_t      (*name_get)();
  NamedNodeMap_t   (*entities_get)();
  NamedNodeMap_t   (*notations_get)();
  /* Introduced in DOM Level 2: */
  DOMString_t      (*publicId_get)();
  /* Introduced in DOM Level 2: */
  DOMString_t      (*systemId_get)();
  /* Introduced in DOM Level 2: */
  DOMString_t      (*internalSubset_get)();
};

struct Notation {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  DOMString_t      (*publicId_get)();
  DOMString_t      (*systemId_get)();
};

struct Entity {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  DOMString_t      (*publicId_get)();
  DOMString_t      (*systemId_get)();
  DOMString_t      (*notationName_get)();
  /* Introduced in DOM Level 3: */
  DOMString_t      (*inputEncoding_get)();
  /* Introduced in DOM Level 3: */
  DOMString_t      (*xmlEncoding_get)();
  /* Introduced in DOM Level 3: */
  DOMString_t      (*xmlVersion_get)();
};

struct EntityReference {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
};

struct ProcessingInstruction {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  DOMString_t      (*target_get)();
  DOMString_t      (*data_get)();
  DOMString_t      (*data_set)(DOMString_t data); /* raises(DOMException) */
};

struct DocumentFragment {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
};

struct Document {
  MARPAXML_NODE_DECLARATIONS; 	 /* derived from Node */
  /* Modified in DOM Level 3: */
  DocumentType_t          (*doctype_get)();
  DOMImplementation_t     (*implementation_get)();
  Element_t               (*documentElement_get)();
  Element_t               (*createElement)(DOMString_t tagName); /* raises(DOMException) */
  DocumentFragment_t      (*createDocumentFragment)();
  Text_t                  (*createTextNode)(DOMString_t data);
  Comment_t               (*createComment)(DOMString_t data);
  CDATASection_t          (*createCDATASection)(DOMString_t data); /* raises(DOMException) */
  ProcessingInstruction_t (*createProcessingInstruction)(DOMString_t target, DOMString_t data); /* raises(DOMException) */
  Attr_t                  (*createAttribute)(DOMString_t name); /* raises(DOMException) */
  EntityReference_t       (*createEntityReference)(DOMString_t name); /* raises(DOMException) */
  NodeList_t              (*getElementsByTagName)(DOMString_t tagname);
  /* Introduced in DOM Level 2: */
  Node_t                  (*importNode)(Node_t importedNode, DOMTypeBoolean_t deep); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Element_t               (*createElementNS)(DOMString_t namespaceURI, DOMString_t qualifiedName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  Attr_t                  (*createAttributeNS)(DOMString_t namespaceURI, DOMString_t qualifiedName); /* raises(DOMException) */
  /* Introduced in DOM Level 2: */
  NodeList_t              (*getElementsByTagNameNS)(DOMString_t namespaceURI, DOMString_t localName);
  /* Introduced in DOM Level 2: */
  Element_t               (*getElementById)(DOMString_t elementId);
  /* Introduced in DOM Level 3: */
  DOMString_t             (*inputEncoding_get)();
  /* Introduced in DOM Level 3: */
  DOMString_t             (*xmlEncoding_get)();
  /* Introduced in DOM Level 3: */
  DOMTypeBoolean_t        (*xmlStandalone_get)();
  DOMTypeBoolean_t        (*xmlStandalone_set)(DOMTypeBoolean_t xmlStandalone); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  DOMString_t             (*xmlVersion_get)();
  DOMString_t             (*xmlVersion_set)(DOMString_t xmlVersion); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  DOMTypeBoolean_t        (*strictErrorChecking_get)();
  DOMTypeBoolean_t        (*strictErrorChecking_set)(DOMTypeBoolean_t strictErrorChecking);
  /* Introduced in DOM Level 3: */
  DOMString_t             (*documentURI_get)();
  DOMString_t             (*documentURI_set)(DOMString_t documentURI);
  /* Introduced in DOM Level 3: */
  Node_t                  (*adoptNode)(Node_t source); /* raises(DOMException) */
  /* Introduced in DOM Level 3: */
  DOMConfiguration_t      (*domConfig_get)();
  /* Introduced in DOM Level 3: */
  void                    (*normalizeDocument)();
  /* Introduced in DOM Level 3: */
  Node_t                  (*renameNode)(Node_t n, DOMString_t namespaceURI, DOMString_t qualifiedName); /* raises(DOMException) */
};

#endif /* MARPAXML_DOM_H_ */
