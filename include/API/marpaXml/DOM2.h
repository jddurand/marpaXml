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

#ifndef MARPAXML_DOM_H
#define MARPAXML_DOM_H

/* About this file:
   - Object Oriented Programming is a design pattern. Nothing prevent to do full OO in C.
     I use the cplus.h macros. By far this is the more portable implementation as I know.
   - Exceptions is an implementation on top of native OO languages. I am not gonne play
     with raise() and so on, this triggers also the problem of thread-specific storage.
     By far, the simplest and totally portable implementation is to provide an explicit
     exception parameter on all methods that are designed to raise one.

     The caller is expected to check the output of new() methods, and error, if any,
     will be in strerror(errno).

     As usual with C (alike most other languages) a misuse of pointers give undefined
     behaviour - usually SIGSEGV -;
*/

#include "marpaXml/cplus.h"
#include "marpaXml/boolean.h"
#include "marpaXml/String.h"
#include "marpaXml/log.h"

/*************************
   Options
 *************************/
typedef struct marpaXml_DOM_Option {
  marpaXmlLogLevel_t           logLevelWantedi;               /* Default: MARPAXML_LOGLEVEL_WARNING           */
  marpaXmlLogCallback_t        logCallbackp;                  /* Default: marpaXmlLog_defaultLogCallback()    */
  void                        *logCallbackDatavp;             /* Default: NULL                                */
  const char                  *dbFilename;                    /* Default: ":memory:"                          */
  const char                  *locale;                        /* Default: NULL                                */
  int                          collStrength;                  /* Default: -1                                  */
} marpaXml_DOM_Option_t;

/*
  Can be called several times, but one is enough. Defaults will apply ONLY if parameter is NULL
*/
marpaXml_boolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp);
/*
  Must be called once only, typically at program exit or library unload, one call at at time: this routine is not thread-safe.
  All in all, simply do not call it - the memory leaks are small. On failure, using DOMError is not supported.
*/
marpaXml_boolean_t marpaXml_DOM_release(void);

typedef marpaXml_String_t marpaXml_DOMString_t;
typedef unsigned long long marpaXml_DOMTimeStamp_t;
typedef void *marpaXml_DOMUserData_t;
typedef Object marpaXml_DOMObject_t;

CLASS_TYPEDEF(marpaXml_DOMImplementation);
CLASS_TYPEDEF(marpaXml_DocumentType);
CLASS_TYPEDEF(marpaXml_Document);
CLASS_TYPEDEF(marpaXml_NodeList);
CLASS_TYPEDEF(marpaXml_NamedNodeMap);
CLASS_TYPEDEF(marpaXml_UserDataHandler);
CLASS_TYPEDEF(marpaXml_Element);
CLASS_TYPEDEF(marpaXml_TypeInfo);
CLASS_TYPEDEF(marpaXml_DOMLocator);

SUBCLASS(marpaXml_DOMException, Object)
  unsigned short       _code;
  marpaXml_DOMString_t _message;
VTABLE(marpaXml_DOMException, Object)
  marpaXml_DOMException_t (*new)(short code, marpaXml_DOMString_t message);
  unsigned short          (*getCode)(marpaXml_DOMException_t this);
  unsigned short          (*setCode)(marpaXml_DOMException_t this, unsigned short code);
  marpaXml_String_t       (*getmessage)(marpaXml_DOMException_t this);
  marpaXml_String_t       (*setmessage)(marpaXml_DOMException_t this, marpaXml_DOMString_t message);
  void                    (*free)(marpaXml_DOMException_t this);
METHODS
END_CLASS

/* ExceptionCode */
const unsigned short      MARPAXML_INDEX_SIZE_ERR                 = 1;
const unsigned short      MARPAXML_DOMSTRING_SIZE_ERR             = 2;
const unsigned short      MARPAXML_HIERARCHY_REQUEST_ERR          = 3;
const unsigned short      MARPAXML_WRONG_DOCUMENT_ERR             = 4;
const unsigned short      MARPAXML_INVALID_CHARACTER_ERR          = 5;
const unsigned short      MARPAXML_NO_DATA_ALLOWED_ERR            = 6;
const unsigned short      MARPAXML_NO_MODIFICATION_ALLOWED_ERR    = 7;
const unsigned short      MARPAXML_NOT_FOUND_ERR                  = 8;
const unsigned short      MARPAXML_NOT_SUPPORTED_ERR              = 9;
const unsigned short      MARPAXML_INUSE_ATTRIBUTE_ERR            = 10;
/* Introduced in DOM Level 2: */
const unsigned short      MARPAXML_INVALID_STATE_ERR              = 11;
/* Introduced in DOM Level 2: */
const unsigned short      MARPAXML_SYNTAX_ERR                     = 12;
/* Introduced in DOM Level 2: */
const unsigned short      MARPAXML_INVALID_MODIFICATION_ERR       = 13;
/* Introduced in DOM Level 2: */
const unsigned short      MARPAXML_NAMESPACE_ERR                  = 14;
/* Introduced in DOM Level 2: */
const unsigned short      MARPAXML_INVALID_ACCESS_ERR             = 15;
/* Introduced in DOM Level 3: */
const unsigned short      MARPAXML_VALIDATION_ERR                 = 16;
/* Introduced in DOM Level 3: */
const unsigned short      MARPAXML_TYPE_MISMATCH_ERR              = 17;

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMStringList_Context *marpaXml_DOMStringList_Context_t;
SUBCLASS(marpaXml_DOMStringList, Object)
  marpaXml_DOMStringList_Context_t _context;
VTABLE(marpaXml_DOMStringList, Object)
  marpaXml_DOMString_t          (*item)(marpaXml_DOMString_t this, unsigned long index);
  unsigned long                 (*getLength)(marpaXml_DOMString_t this);
  marpaXml_boolean_t            (*contains)(marpaXml_DOMString_t this, marpaXml_DOMString_t str);
METHODS
  marpaXml_DOMStringList_t        marpaXml_DOMStringList_new();
  void                            marpaXml_DOMStringList_free(marpaXml_DOMString_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_NameList_Context *marpaXml_NameList_Context_t;
SUBCLASS(marpaXml_NameList, Object)
  marpaXml_NameList_Context_t _context;
VTABLE(marpaXml_NameList, Object)
  marpaXml_DOMString_t          (*getName)(marpaXml_NameList_t this, unsigned long index);
  marpaXml_DOMString_t          (*getNamespaceURI)(marpaXml_NameList_t this, unsigned long index);
  unsigned long                 (*getLength)(marpaXml_NameList_t this);
  marpaXml_boolean_t            (*contains)(marpaXml_NameList_t this, marpaXml_DOMString_t str);
  marpaXml_boolean_t            (*containsNS)(marpaXml_NameList_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t name);
METHODS
  marpaXml_NameList_t             marpaXml_NameList_new();
  void                            marpaXml_NameList_free(marpaXml_NameList_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMImplementationList_Context *marpaXml_DOMImplementationList_Context_t;
SUBCLASS(marpaXml_DOMImplementationList, Object)
  marpaXml_DOMImplementationList_Context_t _context;
VTABLE(marpaXml_DOMImplementationList, Object)
  marpaXml_DOMImplementation_t   (*item)(marpaXml_DOMImplementationList_t this, unsigned long index);
  unsigned long                  (*getLength)(marpaXml_DOMImplementationList_t this);
METHODS
  marpaXml_DOMImplementationList_t marpaXml_DOMImplementationList_new();
  void                             marpaXml_DOMImplementationList_free(marpaXml_DOMImplementationList_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMImplementationSource_Context *marpaXml_DOMImplementationSource_Context_t;
SUBCLASS(marpaXml_DOMImplementationSource, Object)
  marpaXml_DOMImplementationSource_Context_t _context;
VTABLE(marpaXml_DOMImplementationSource, Object)
  marpaXml_DOMImplementation_t     (*getDOMImplementation)(marpaXml_DOMImplementationSource_t this, marpaXml_DOMString_t features);
  marpaXml_DOMImplementationList_t (*getDOMImplementationList)(marpaXml_DOMImplementationSource_t this, marpaXml_DOMString_t features);
METHODS
  marpaXml_DOMImplementationSource_t marpaXml_DOMImplementationSource_new();
  void                               marpaXml_DOMImplementationSource_free(marpaXml_DOMImplementationSource_t this);
END_CLASS

typedef struct marpaXml_DOMImplementation_Context *marpaXml_DOMImplementation_Context_t;
SUBCLASS(marpaXml_DOMImplementation, Object)
  marpaXml_DOMImplementation_Context_t _context;
VTABLE(marpaXml_DOMImplementation, Object)
  marpaXml_boolean_t            (*hasFeature)(marpaXml_DOMImplementation_t this, marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
  /* Introduced in DOM Level 2: */
  marpaXml_DocumentType_t       (*createDocumentType)(marpaXml_DOMImplementation_t this, marpaXml_DOMString_t qualifiedName, marpaXml_DOMString_t publicId, marpaXml_DOMString_t systemId, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Document_t           (*createDocument)(marpaXml_DOMImplementation_t this, marpaXml_DOMString_t namespaceURI,  marpaXml_DOMString_t qualifiedName, marpaXml_DocumentType_t doctype, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMObject_t          (*getFeature)(marpaXml_DOMImplementation_t this, marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
METHODS
  marpaXml_DOMImplementation_t    marpaXml_DOMImplementation_new();
  void                            marpaXml_DOMImplementation_free(marpaXml_DOMImplementation_t this);
END_CLASS

/* NodeType */
const unsigned short      MARPAXML_ELEMENT_NODE                   = 1;
const unsigned short      MARPAXML_ATTRIBUTE_NODE                 = 2;
const unsigned short      MARPAXML_TEXT_NODE                      = 3;
const unsigned short      MARPAXML_CDATA_SECTION_NODE             = 4;
const unsigned short      MARPAXML_ENTITY_REFERENCE_NODE          = 5;
const unsigned short      MARPAXML_ENTITY_NODE                    = 6;
const unsigned short      MARPAXML_PROCESSING_INSTRUCTION_NODE    = 7;
const unsigned short      MARPAXML_COMMENT_NODE                   = 8;
const unsigned short      MARPAXML_DOCUMENT_NODE                  = 9;
const unsigned short      MARPAXML_DOCUMENT_TYPE_NODE             = 10;
const unsigned short      MARPAXML_DOCUMENT_FRAGMENT_NODE         = 11;
const unsigned short      MARPAXML_NOTATION_NODE                  = 12;

/* DocumentPosition */
const unsigned short      MARPAXML_DOCUMENT_POSITION_DISCONNECTED = 0x01;
const unsigned short      MARPAXML_DOCUMENT_POSITION_PRECEDING    = 0x02;
const unsigned short      MARPAXML_DOCUMENT_POSITION_FOLLOWING    = 0x04;
const unsigned short      MARPAXML_DOCUMENT_POSITION_CONTAINS     = 0x08;
const unsigned short      MARPAXML_DOCUMENT_POSITION_CONTAINED_BY = 0x10;
const unsigned short      MARPAXML_DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20;

typedef struct marpaXml_Node_Context *marpaXml_Node_Context_t;
SUBCLASS(marpaXml_Node, Object)
  marpaXml_Node_Context_t _context;
VTABLE(marpaXml_Node, Object)
  marpaXml_DOMString_t       (*getNodeName)(marpaXml_Node_t this);
  marpaXml_DOMString_t       (*getNodeValue)(marpaXml_Node_t this, marpaXml_DOMException_t exception);
  marpaXml_DOMString_t       (*setNodeValue)(marpaXml_Node_t this, marpaXml_DOMString_t nodeValue, marpaXml_DOMException_t exception);
  unsigned short             (*getNodeType)(marpaXml_Node_t this);
  marpaXml_Node_t            (*getParentNode)(marpaXml_Node_t this);
  marpaXml_NodeList_t        (*getChildNodes)(marpaXml_Node_t this);
  marpaXml_Node_t            (*getFirstChild)(marpaXml_Node_t this);
  marpaXml_Node_t            (*getLastChild)(marpaXml_Node_t this);
  marpaXml_Node_t            (*previousSibling)(marpaXml_Node_t this);
  marpaXml_Node_t            (*nextSibling)(marpaXml_Node_t this);
  marpaXml_NamedNodeMap_t    (*attributes)(marpaXml_Node_t this);
  /* Modified in DOM Level 2: */
  marpaXml_Document_t        (*ownerDocument)(marpaXml_Node_t this);
  /* Modified in DOM Level 3: */
  marpaXml_Node_t            (*insertBefore)(marpaXml_Node_t this, marpaXml_Node_t newChild, marpaXml_Node_t refChild, marpaXml_DOMException_t exception);
  /* Modified in DOM Level 3: */
  marpaXml_Node_t            (*replaceChild)(marpaXml_Node_t this, marpaXml_Node_t newChild, marpaXml_Node_t oldChild, marpaXml_DOMException_t exception);
  /* Modified in DOM Level 3: */
  marpaXml_Node_t            (*removeChild)(marpaXml_Node_t this, marpaXml_Node_t oldChild, marpaXml_DOMException_t exception);
  /* Modified in DOM Level 3: */
  marpaXml_Node_t            (*appendChild)(marpaXml_Node_t this, marpaXml_Node_t newChild, marpaXml_DOMException_t exception);
  marpaXml_boolean_t         (*hasChildNodes)(marpaXml_Node_t this);
  marpaXml_Node_t            (*cloneNode)(marpaXml_Node_t this, marpaXml_boolean_t deep);
  /* Modified in DOM Level 3: */
  void                       (*normalize)(marpaXml_Node_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_boolean_t         (*isSupported)(marpaXml_Node_t this, marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t       (*getNamespaceURI)(marpaXml_Node_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t       (*getPrefix)(marpaXml_Node_t this);
  marpaXml_DOMString_t       (*setPrefix)(marpaXml_Node_t this, marpaXml_DOMString_t prefix, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t       (*getLocalName)(marpaXml_Node_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_boolean_t         (*hasAttributes)(marpaXml_Node_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*getBaseURI)(marpaXml_Node_t this);

  /* Introduced in DOM Level 3: */
  unsigned short             (*compareDocumentPosition)(marpaXml_Node_t this, marpaXml_Node_t other, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*getTextContent)(marpaXml_Node_t this, marpaXml_DOMException_t exception);
  marpaXml_DOMString_t       (*setTextContent)(marpaXml_Node_t this, marpaXml_DOMString_t textContent, marpaXml_DOMException_t exception);

  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t         (*isSameNode)(marpaXml_Node_t this, marpaXml_Node_t other);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*lookupPrefix)(marpaXml_Node_t this, marpaXml_DOMString_t namespaceURI);
  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t         (*isDefaultNamespace)(marpaXml_Node_t this, marpaXml_DOMString_t namespaceURI);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*lookupNamespaceURI)(marpaXml_Node_t this, marpaXml_DOMString_t prefix);
  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t         (*isEqualNode)(marpaXml_Node_t this, marpaXml_Node_t arg);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMObject_t       (*getFeature)(marpaXml_Node_t this, marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMUserData_t     (*setUserData)(marpaXml_Node_t this, marpaXml_DOMString_t key, marpaXml_DOMUserData_t data, marpaXml_UserDataHandler_t handler);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMUserData_t     (*getUserData)(marpaXml_Node_t this, marpaXml_DOMString_t key);
METHODS
  marpaXml_Node_t              marpaXml_Node_new();
  void                         marpaXml_Node_free(marpaXml_Node_t this);
END_CLASS

typedef struct marpaXml_NodeList_Context *marpaXml_NodeList_Context_t;
SUBCLASS(marpaXml_NodeList, Object)
  marpaXml_NodeList_Context_t _context;
VTABLE(marpaXml_NodeList, Object)
  marpaXml_Node_t   (*item)(marpaXml_NodeList_t this, unsigned long index);
  unsigned long     (*getLength)(marpaXml_NodeList_t this);
METHODS
  marpaXml_NodeList_t marpaXml_NodeList_new();
  void                marpaXml_NodeList_free(marpaXml_NodeList_t this);
END_CLASS

typedef struct marpaXml_NamedNodeMap_Context *marpaXml_NamedNodeMap_Context_t;
SUBCLASS(marpaXml_NamedNodeMap, Object)
  marpaXml_NamedNodeMap_Context_t _context;
VTABLE(marpaXml_NamedNodeMap, Object)
  marpaXml_Node_t               (*getNamedItem)(marpaXml_NamedNodeMap_t this, marpaXml_DOMString_t name);
  marpaXml_Node_t               (*setNamedItem)(marpaXml_NamedNodeMap_t this, marpaXml_Node_t arg, marpaXml_DOMException_t exception);
  marpaXml_Node_t               (*removeNamedItem)(marpaXml_NamedNodeMap_t this, marpaXml_DOMString_t name, marpaXml_DOMException_t exception);
  marpaXml_Node_t               (*item)(marpaXml_NamedNodeMap_t this, unsigned long index);
  unsigned long                 (*getLength)(marpaXml_NamedNodeMap_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_Node_t               (*getNamedItemNS)(marpaXml_NamedNodeMap_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Node_t               (*setNamedItemNS)(marpaXml_NamedNodeMap_t this, marpaXml_Node_t arg, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Node_t               (*removeNamedItemNS)(marpaXml_NamedNodeMap_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
METHODS
  marpaXml_NamedNodeMap_t         marpaXml_NamedNodeMap_new();
  void                            marpaXml_NamedNodeMap_free(marpaXml_NamedNodeMap_t this);
END_CLASS

typedef struct marpaXml_CharacterData_Context *marpaXml_CharacterData_Context_t;
SUBCLASS(marpaXml_CharacterData, marpaXml_Node)
  marpaXml_CharacterData_Context_t _context;
VTABLE(marpaXml_CharacterData, marpaXml_Node)
  marpaXml_DOMString_t       (*getData)(marpaXml_CharacterData_t this, marpaXml_DOMException_t exception);
  marpaXml_DOMString_t       (*setData)(marpaXml_CharacterData_t this, marpaXml_DOMString_t data, marpaXml_DOMException_t exception);
  unsigned long              (*getLength)(marpaXml_CharacterData_t this);
  marpaXml_DOMString_t       (*substringData)(marpaXml_CharacterData_t this, unsigned long offset, unsigned long count, marpaXml_DOMException_t exception);
  void                       (*appendData)(marpaXml_CharacterData_t this, marpaXml_DOMString_t arg, marpaXml_DOMException_t exception);
  void                       (*insertData)(marpaXml_CharacterData_t this, unsigned long offset, marpaXml_DOMString_t arg, marpaXml_DOMException_t exception);
  void                       (*deleteData)(marpaXml_CharacterData_t this, unsigned long offset, unsigned long count, marpaXml_DOMException_t exception);
  void                       (*replaceData)(marpaXml_CharacterData_t this, unsigned long offset, unsigned long count, marpaXml_DOMString_t arg, marpaXml_DOMException_t exception);
METHODS
  marpaXml_CharacterData_t     marpaXml_CharacterData_new();
  void                         marpaXml_CharacterData_free(marpaXml_CharacterData_t this);
END_CLASS

typedef struct marpaXml_Attr_Context *marpaXml_Attr_Context_t;
SUBCLASS(marpaXml_Attr, marpaXml_Node)
  marpaXml_Attr_Context_t _context;
VTABLE(marpaXml_Attr, marpaXml_Node)
  marpaXml_DOMString_t       (*getName)(marpaXml_Attr_t this);
  marpaXml_boolean_t         (*getSpecified)(marpaXml_Attr_t this);
  marpaXml_DOMString_t       (*getValue)(marpaXml_Attr_t this);
  marpaXml_DOMString_t       (*setValue)(marpaXml_Attr_t this, marpaXml_DOMString_t value, marpaXml_DOMException_t exception);

  /* Introduced in DOM Level 2 */
  marpaXml_Element_t         (*getOwnerElement)(marpaXml_Attr_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_TypeInfo_t        (*getSchemaTypeInfo)(marpaXml_Attr_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t         (*getIsId)(marpaXml_Attr_t this);
METHODS
  marpaXml_Attr_t              marpaXml_Attr_new();
  void                         marpaXml_Attr_free(marpaXml_Attr_t this);
END_CLASS

typedef struct marpaXml_Element_Context *marpaXml_Element_Context_t;
SUBCLASS(marpaXml_Element, marpaXml_Node)
  marpaXml_Element_Context_t _context;
VTABLE(marpaXml_Element, marpaXml_Node)
  marpaXml_DOMString_t       (*getTagName)(marpaXml_Element_t this);
  marpaXml_DOMString_t       (*getAttribute)(marpaXml_Element_t this, marpaXml_DOMString_t name);
  void                       (*setAttribute)(marpaXml_Element_t this, marpaXml_DOMString_t name, marpaXml_DOMString_t value, marpaXml_DOMException_t exception);
  void                       (*removeAttribute)(marpaXml_Element_t this, marpaXml_DOMString_t name, marpaXml_DOMException_t exception);
  marpaXml_Attr_t            (*getAttributeNode)(marpaXml_Element_t this, marpaXml_DOMString_t name);
  marpaXml_Attr_t            (*setAttributeNode)(marpaXml_Element_t this, marpaXml_Attr_t newAttr, marpaXml_DOMException_t exception);
  marpaXml_Attr_t            (*removeAttributeNode)(marpaXml_Element_t this, marpaXml_Attr_t oldAttr, marpaXml_DOMException_t exception);
  marpaXml_NodeList_t        (*getElementsByTagName)(marpaXml_Element_t this, marpaXml_DOMString_t name);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t       (*getAttributeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  void                       (*setAttributeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMString_t value, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  void                       (*removeAttributeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Attr_t            (*getAttributeNodeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Attr_t            (*setAttributeNodeNS)(marpaXml_Element_t this, marpaXml_Attr_t newAttr, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_NodeList_t        (*getElementsByTagNameNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_boolean_t         (*hasAttribute)(marpaXml_Element_t this, marpaXml_DOMString_t name);
  /* Introduced in DOM Level 2: */
  marpaXml_boolean_t         (*hasAttributeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  marpaXml_TypeInfo_t        (*getSchemaTypeInfo)(marpaXml_Element_t this);
  /* Introduced in DOM Level 3: */
  void                       (*setIdAttribute)(marpaXml_Element_t this, marpaXml_DOMString_t name, marpaXml_boolean_t isId, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  void                       (*setIdAttributeNS)(marpaXml_Element_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_boolean_t isId, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  void                       (*setIdAttributeNode)(marpaXml_Element_t this, marpaXml_Attr_t idAttr, marpaXml_boolean_t isId, marpaXml_DOMException_t exception);
METHODS
  marpaXml_Element_t           marpaXml_Element_new();
  void                         marpaXml_Element_free(marpaXml_Element_t this);
END_CLASS

typedef struct marpaXml_Text_Context *marpaXml_Text_Context_t;
SUBCLASS(marpaXml_Text, marpaXml_CharacterData)
  marpaXml_Text_Context_t _context;
VTABLE(marpaXml_Text, marpaXml_CharacterData)
  marpaXml_Text_t         (*splitText)(marpaXml_Text_t this, unsigned long offset, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t      (*getIsElementContentWhitespace)(marpaXml_Text_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t    (*getWholeText)(marpaXml_Text_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_Text_t         (*replaceWholeText)(marpaXml_Text_t this, marpaXml_DOMString_t content, marpaXml_DOMException_t exception);
METHODS
  marpaXml_Text_t           marpaXml_Text_new();
  void                      marpaXml_Text_free(marpaXml_Text_t this);
END_CLASS

typedef struct marpaXml_Comment_Context *marpaXml_Comment_Context_t;
SUBCLASS(marpaXml_Comment, marpaXml_CharacterData)
  marpaXml_Comment_Context_t _context;
VTABLE(marpaXml_Comment, marpaXml_CharacterData)
METHODS
  marpaXml_Comment_t        marpaXml_Comment_new();
  void                      marpaXml_Comment_free(marpaXml_Comment_t this);
END_CLASS

/* DerivationMethods */
const unsigned long       MARPAXML_DERIVATION_RESTRICTION         = 0x00000001;
const unsigned long       MARPAXML_DERIVATION_EXTENSION           = 0x00000002;
const unsigned long       MARPAXML_DERIVATION_UNION               = 0x00000004;
const unsigned long       MARPAXML_DERIVATION_LIST                = 0x00000008;

/* Introduced in DOM Level 3: */
typedef struct marpaXml_TypeInfo_Context *marpaXml_TypeInfo_Context_t;
SUBCLASS(marpaXml_TypeInfo, Object)
  marpaXml_TypeInfo_Context_t _context;
VTABLE(marpaXml_TypeInfo, Object)
  marpaXml_DOMString_t       (*getTypeName)(marpaXml_TypeInfo_t this);
  marpaXml_DOMString_t       (*getTypeNamespace)(marpaXml_TypeInfo_t this);
  marpaXml_boolean_t         (*isDerivedFrom)(marpaXml_TypeInfo_t this, marpaXml_DOMString_t typeNamespaceArg, marpaXml_DOMString_t typeNameArg, unsigned long derivationMethod);
METHODS
  marpaXml_TypeInfo_t          marpaXml_TypeInfo_new();
  void                         marpaXml_TypeInfo_free(marpaXml_TypeInfo_t this);
END_CLASS

/* OperationType */
const unsigned short      MARPAXML_NODE_CLONED                    = 1;
const unsigned short      MARPAXML_NODE_IMPORTED                  = 2;
const unsigned short      MARPAXML_NODE_DELETED                   = 3;
const unsigned short      MARPAXML_NODE_RENAMED                   = 4;
const unsigned short      MARPAXML_NODE_ADOPTED                   = 5;

/* Introduced in DOM Level 3: */
typedef struct marpaXml_UserDataHandler_Context *marpaXml_UserDataHandler_Context_t;
SUBCLASS(marpaXml_UserDataHandler, Object)
  marpaXml_UserDataHandler_Context_t _context;
VTABLE(marpaXml_UserDataHandler, Object)
  void                      (*handle)(unsigned short operation, marpaXml_DOMString_t key, marpaXml_DOMUserData_t data, marpaXml_Node_t src, marpaXml_Node_t dst);
METHODS
  marpaXml_UserDataHandler_t  marpaXml_UserDataHandler_new();
  void                        marpaXml_UserDataHandler_free(marpaXml_UserDataHandler_t this);
END_CLASS

/* ErrorSeverity */
const unsigned short      MARPAXML_SEVERITY_WARNING               = 1;
const unsigned short      MARPAXML_SEVERITY_ERROR                 = 2;
const unsigned short      MARPAXML_SEVERITY_FATAL_ERROR           = 3;

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMError_Context *marpaXml_DOMError_Context_t;
SUBCLASS(marpaXml_DOMError, Object)
  marpaXml_DOMError_Context_t _context;
VTABLE(marpaXml_DOMError, Object)
  unsigned short        (*getSeverity)(marpaXml_DOMError_t this);
  marpaXml_DOMString_t  (*getMessage)(marpaXml_DOMError_t this);
  marpaXml_DOMString_t  (*getType)(marpaXml_DOMError_t this);
  marpaXml_DOMObject_t  (*getRelatedException)(marpaXml_DOMError_t this);
  marpaXml_DOMObject_t  (*getRelatedData)(marpaXml_DOMError_t this);
  marpaXml_DOMLocator_t (*getLocation)(marpaXml_DOMError_t this);
METHODS
  marpaXml_DOMError_t     marpaXml_DOMError_new();
  void                    marpaXml_DOMError_free(marpaXml_DOMError_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMErrorHandler_Context *marpaXml_DOMErrorHandler_Context_t;
SUBCLASS(marpaXml_DOMErrorHandler, Object)
  marpaXml_DOMErrorHandler_Context_t _context;
VTABLE(marpaXml_DOMErrorHandler, Object)
  marpaXml_boolean_t       (*handleError)(marpaXml_DOMErrorHandler_t this, marpaXml_DOMError_t error);
METHODS
  marpaXml_DOMErrorHandler_t marpaXml_DOMErrorHandler_new();
  void                       marpaXml_DOMErrorHandler_free(marpaXml_DOMErrorHandler_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMLocator_Context *marpaXml_DOMLocator_Context_t;
SUBCLASS(marpaXml_DOMLocator, Object)
  marpaXml_DOMLocator_Context_t _context;
VTABLE(marpaXml_DOMLocator, Object)
  long                 (*getLineNumber)(marpaXml_DOMLocator_t this);
  long                 (*getColumnNumber)(marpaXml_DOMLocator_t this);
  long                 (*getByteOffset)(marpaXml_DOMLocator_t this);
  long                 (*getUtf16Offset)(marpaXml_DOMLocator_t this);
  marpaXml_Node_t      (*getRelatedNode)(marpaXml_DOMLocator_t this);
  marpaXml_DOMString_t (*getUri)(marpaXml_DOMLocator_t this);
METHODS
  marpaXml_DOMLocator_t  marpaXml_DOMLocator_new();
  void                   marpaXml_DOMLocator_free(marpaXml_DOMLocator_t this);
END_CLASS

/* Introduced in DOM Level 3: */
typedef struct marpaXml_DOMConfiguration_Context *marpaXml_DOMConfiguration_Context_t;
SUBCLASS(marpaXml_DOMConfiguration, Object)
  marpaXml_DOMConfiguration_Context_t _context;
VTABLE(marpaXml_DOMConfiguration, Object)
  void                      (*setParameter)(marpaXml_DOMConfiguration_t this, marpaXml_DOMString_t name, marpaXml_DOMUserData_t value, marpaXml_DOMException_t exception);
  marpaXml_DOMUserData_t    (*getParameter)(marpaXml_DOMConfiguration_t this, marpaXml_DOMString_t name, marpaXml_DOMException_t exception);
  marpaXml_boolean_t        (*canSetParameter)(marpaXml_DOMConfiguration_t this, marpaXml_DOMString_t name, marpaXml_DOMUserData_t value);
  marpaXml_DOMStringList_t  (*getParameterNames)(marpaXml_DOMConfiguration_t this);
METHODS
  marpaXml_DOMConfiguration_t marpaXml_DOMConfiguration_new();
  void                        marpaXml_DOMConfiguration_free(marpaXml_DOMConfiguration_t this);
END_CLASS

typedef struct marpaXml_CDATASection_Context *marpaXml_CDATASection_Context_t;
SUBCLASS(marpaXml_CDATASection, marpaXml_Text)
  marpaXml_CDATASection_Context_t _context;
VTABLE(marpaXml_CDATASection, marpaXml_Text)
METHODS
  marpaXml_CDATASection_t marpaXml_CDATASection_new();
  void                    marpaXml_CDATASection_free(marpaXml_CDATASection_t this);
END_CLASS

typedef struct marpaXml_DocumentType_Context *marpaXml_DocumentType_Context_t;
SUBCLASS(marpaXml_DocumentType, marpaXml_Node)
  marpaXml_DocumentType_Context_t _context;
VTABLE(marpaXml_DocumentType, marpaXml_Node)
  marpaXml_DOMString_t    (*getName)(marpaXml_DocumentType_t this);
  marpaXml_NamedNodeMap_t (*getEntities)(marpaXml_DocumentType_t this);
  marpaXml_NamedNodeMap_t (*getNotations)(marpaXml_DocumentType_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t    (*getPublicId)(marpaXml_DocumentType_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t    (*getSystemId)(marpaXml_DocumentType_t this);
  /* Introduced in DOM Level 2: */
  marpaXml_DOMString_t    (*getInternalSubset)(marpaXml_DocumentType_t this);
METHODS
  marpaXml_DocumentType_t   marpaXml_DocumentType_new();
  void                      marpaXml_DocumentType_free(marpaXml_DocumentType_t this);
END_CLASS

typedef struct marpaXml_Notation_Context *marpaXml_Notation_Context_t;
SUBCLASS(marpaXml_Notation, marpaXml_Node)
  marpaXml_Notation_Context_t _context;
VTABLE(marpaXml_Notation, marpaXml_Node)
  marpaXml_DOMString_t (*getPublicId)(marpaXml_Notation_t this);
  marpaXml_DOMString_t (*getSystemId)(marpaXml_Notation_t this);
METHODS
  marpaXml_Notation_t     marpaXml_Notation_new();
  void                    marpaXml_Notation_free(marpaXml_Notation_t this);
END_CLASS

typedef struct marpaXml_Entity_Context *marpaXml_Entity_Context_t;
SUBCLASS(marpaXml_Entity, marpaXml_Node)
  marpaXml_Entity_Context_t _context;
VTABLE(marpaXml_Entity, marpaXml_Node)
  marpaXml_DOMString_t       (*getPublicId)(marpaXml_Entity_t this);
  marpaXml_DOMString_t       (*getSystemId)(marpaXml_Entity_t this);
  marpaXml_DOMString_t       (*getNotationName)(marpaXml_Entity_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*getInputEncoding)(marpaXml_Entity_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*getXmlEncoding)(marpaXml_Entity_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t       (*getXmlVersion)(marpaXml_Entity_t this);
METHODS
  marpaXml_Entity_t            marpaXml_Entity_new();
  void                         marpaXml_Entity_free(marpaXml_Entity_t this);
END_CLASS

typedef struct marpaXml_EntityReference_Context *marpaXml_EntityReference_Context_t;
SUBCLASS(marpaXml_EntityReference, marpaXml_Node)
  marpaXml_EntityReference_Context_t _context;
VTABLE(marpaXml_EntityReference, marpaXml_Node)
METHODS
  marpaXml_EntityReference_t   marpaXml_EntityReference_new();
  void                         marpaXml_EntityReference_free(marpaXml_EntityReference_t this);
END_CLASS

typedef struct marpaXml_ProcessingInstruction_Context *marpaXml_ProcessingInstruction_Context_t;
SUBCLASS(marpaXml_ProcessingInstruction, marpaXml_Node)
  marpaXml_ProcessingInstruction_Context_t _context;
VTABLE(marpaXml_ProcessingInstruction, marpaXml_Node)
  marpaXml_DOMString_t             (*getTarget)(marpaXml_ProcessingInstruction_t this);
  marpaXml_DOMString_t             (*getData)(marpaXml_ProcessingInstruction_t this);
  marpaXml_DOMString_t             (*setData)(marpaXml_ProcessingInstruction_t this, marpaXml_DOMString_t data, marpaXml_DOMException_t exception);
METHODS
  marpaXml_ProcessingInstruction_t   marpaXml_ProcessingInstruction_new();
  void                               marpaXml_ProcessingInstruction_free(marpaXml_ProcessingInstruction_t this);
END_CLASS

typedef struct marpaXml_DocumentFragment_Context *marpaXml_DocumentFragment_Context_t;
SUBCLASS(marpaXml_DocumentFragment, marpaXml_Node)
  marpaXml_DocumentFragment_Context_t _context;
VTABLE(marpaXml_DocumentFragment, marpaXml_Node)
METHODS
  marpaXml_DocumentFragment_t   marpaXml_DocumentFragment_new();
  void                          marpaXml_DocumentFragment_free(marpaXml_DocumentFragment_t this);
END_CLASS

typedef struct marpaXml_Document_Context *marpaXml_Document_Context_t;
SUBCLASS(marpaXml_Document, marpaXml_Node)
  marpaXml_Document_Context_t _context;
VTABLE(marpaXml_Document, marpaXml_Node)
  /* Modified in DOM Level 3: */
  marpaXml_DocumentType_t          (*getDoctype)(marpaXml_Document_t this);
  marpaXml_DOMImplementation_t     (*getImplementation)(marpaXml_Document_t this);
  marpaXml_Element_t               (*getDocumentElement)(marpaXml_Document_t this);
  marpaXml_Element_t               (*createElement)(marpaXml_Document_t this, marpaXml_DOMString_t tagName, marpaXml_DOMException_t exception);
  marpaXml_DocumentFragment_t      (*createDocumentFragment)(marpaXml_Document_t this);
  marpaXml_Text_t                  (*createTextNode)(marpaXml_Document_t this, marpaXml_DOMString_t data);
  marpaXml_Comment_t               (*createComment)(marpaXml_Document_t this, marpaXml_DOMString_t data);
  marpaXml_CDATASection_t          (*createCDATASection)(marpaXml_Document_t this, marpaXml_DOMString_t data, marpaXml_DOMException_t exception);
  marpaXml_ProcessingInstruction_t (*createProcessingInstruction)(marpaXml_Document_t this, marpaXml_DOMString_t target, marpaXml_DOMString_t data, marpaXml_DOMException_t exception);
  marpaXml_Attr_t                  (*createAttribute)(marpaXml_Document_t this, marpaXml_DOMString_t name, marpaXml_DOMException_t exception);
  marpaXml_EntityReference_t       (*createEntityReference)(marpaXml_Document_t this, marpaXml_DOMString_t name, marpaXml_DOMException_t exception);
  marpaXml_NodeList_t              (*getElementsByTagName)(marpaXml_Document_t this, marpaXml_DOMString_t tagname);
  /* Introduced in DOM Level 2: */
  marpaXml_Node_t                  (*importNode)(marpaXml_Document_t this, marpaXml_Node_t importedNode, marpaXml_boolean_t deep, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Element_t               (*createElementNS)(marpaXml_Document_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_Attr_t                  (*createAttributeNS)(marpaXml_Document_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t exception);
  /* Introduced in DOM Level 2: */
  marpaXml_NodeList_t              (*getElementsByTagNameNS)(marpaXml_Document_t this, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName);
  /* Introduced in DOM Level 2: */
  marpaXml_Element_t               (*getElementById)(marpaXml_Document_t this, marpaXml_DOMString_t elementId);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t             (*getInputEncoding)(marpaXml_Document_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t             (*getXmlEncoding)(marpaXml_Document_t this);
  /* Introduced in DOM Level 3: */
  marpaXml_boolean_t               (*getXmlStandalone)(marpaXml_Document_t this);
  marpaXml_boolean_t               (*setXmlStandalone)(marpaXml_Document_t this, marpaXml_boolean_t xmlStandalone, marpaXml_DOMException_t exception);

  /* Introduced in DOM Level 3: */
  marpaXml_DOMString_t             (*getXmlVersion)(marpaXml_Document_t this);
  marpaXml_DOMString_t             (*setXmlVersion)(marpaXml_Document_t this, marpaXml_DOMString_t xmlVersion, marpaXml_DOMException_t exception);

  // Introduced in DOM Level 3:
  marpaXml_boolean_t               (*getStrictErrorChecking)(marpaXml_Document_t this);
  marpaXml_boolean_t               (*setStrictErrorChecking)(marpaXml_Document_t this, marpaXml_boolean_t strictErrorChecking);
  // Introduced in DOM Level 3:
  marpaXml_DOMString_t             (*getDocumentURI)(marpaXml_Document_t this);
  marpaXml_DOMString_t             (*setDocumentURI)(marpaXml_Document_t this, marpaXml_DOMString_t documentURI);
  // Introduced in DOM Level 3:
  marpaXml_Node_t                  (*adoptNode)(marpaXml_Document_t this, marpaXml_Node_t source, marpaXml_DOMException_t exception);
  // Introduced in DOM Level 3:
  marpaXml_DOMConfiguration_t      (*getDomConfig)(marpaXml_Document_t this);
  // Introduced in DOM Level 3:
  void                             (*normalizeDocument)(marpaXml_Document_t this);
  // Introduced in DOM Level 3:
  marpaXml_Node_t                  (*renameNode)(marpaXml_Document_t this, marpaXml_Node_t n, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t exception);
METHODS
  marpaXml_Document_t                marpaXml_Document_new();
  void                               marpaXml_Document_free(marpaXml_Document_t this);
END_CLASS

#endif /* MARPAXML_DOM_H_ */
