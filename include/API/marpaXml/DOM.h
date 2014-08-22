#ifndef MARPAXML_API_DOM_H
#define MARPAXML_API_DOM_H

#include <sys/types.h>
#include "marpaXml/log.h"
#include "cplus.h"

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

/*
  Notes:
  - Our model is 100% live
    => Modifying a DOM object from one thread will be visible from another thread, whatever
       the type of the object

  - Our API is expecting null terminated UTF-8 strings. NOTHING ELSE.
    => Your application will have to know how to translate to/from UTF-8 to your preferred encoding.
       Please note that this is UTF8 as per ICU, not Java's modified UTF8.

  - SQLite is compiled with explicit ICU support here, which means:
    => REGEXP operator is using ICU
    => upper() and lower() are using ICU
    => collation is using ICU
    => LIKE operator becomes CASE-INDEPENDANT matching (but won't use any index)

  Since collation requires a locale, this is why marpaXml_DOM_init() has a locale parameter: char *locale.
  In addition to collation, there is collation "strength". So marpaXml_DOM_init() also has another
  parameter: int collStrength (inspired by https://gist.github.com/mytskine/5028755). Our collstrength
  parameter should be exactly one of ICU's ucol_setStrength()'s strength argument, i.e.:
   1     for primary
   2     for secondary
   3     for tertiary
   4     for quaternary
  15     for identical
  -1     for default

  In contrary to SQLite's default ICU load collation implementation, it is legal to give NULL for the locale:
  ICU's ucol_open() behaviour applies, i.e. 'if NULL is passed for the locale, the default locale collation
  rules will be used. If empty string ("") or "root" are passed, the root collator will be returned'.

  - We follow Java convention for the attributes getter and setters method names.

  - We are NOT gonna play with C object-oriented hacks: the DOM model inheritance is simple, we
    can duplicate the prototypes with carefully writen macros (which means internally a delegation),
    and every method that can return an  exception will have an explicit DOMException parameter and will return a false value (0)
    and/or a NOEXCEPTION in the DOMException parameter, provided it is not NULL in the stack.
    This choice is because, yes I know that we can do 80% of objects in pure ANSI-C. This is ok for
    a general framework. Here we have a concrete and fixed framework, as we as a fixed implementation: this is
    why we can use unsigned long long for object references instead of a malloc, which means the super
    ability of this library to NOT care about object destructions: there is no notion of new()/destroy(), and this
    sounds very much more like C++ and Java rather than having to play with OO simulation, with which the
    programmer will HAVE to take care of free() all over the place.

  - We unsigned long long int instead of unsigned long
*/

/**************************************************************************/
/*                              Constants                                 */
/**************************************************************************/

typedef enum marpaXml_DOMBoolean {
  MARPAXML_DOMBOOLEAN_FALSE = 0,
  MARPAXML_DOMBOOLEAN_TRUE = 1
} marpaXml_DOMBoolean_t;

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
marpaXml_DOMBoolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp);
/*
  Must be called once only, typically at program exit or library unload, one call at at time: this routine is not thread-safe.
  All in all, simply do not call it - the memory leaks are small. On failure, using DOMError is not supported.
*/
marpaXml_DOMBoolean_t marpaXml_DOM_release(void);

/* Some applications will say (char*), others (unsigned char*). This is not
   important because we know we talk about UTF-8 strings. So we say (void *). */

/* All the List interfaces requires a destroy call to prevent space and memory leaks, not the others */
typedef void                   *marpaXml_DOMString_t;
typedef void                   *marpaXml_DOMUserData_t;
typedef unsigned long long int  marpaXml_DOMImplementation_t;
typedef unsigned long long int  marpaXml_DocumentType_t;
typedef unsigned long long int  marpaXml_Document_t;
typedef void                   *marpaXml_NodeList_t;
typedef unsigned long long int  marpaXml_NamedNodeMap_t;
typedef unsigned long long int  marpaXml_UserDataHandler_t;
typedef unsigned long long int  marpaXml_Element_t;
typedef unsigned long long int  marpaXml_TypeInfo_t;
typedef unsigned long long int  marpaXml_DOMLocator_t;
typedef unsigned long long int  marpaXml_DOMException_t;
typedef void                   *marpaXml_DOMStringList_t;
typedef void                   *marpaXml_NameList_t;
typedef void                   *marpaXml_DOMImplementationList_t;
typedef unsigned long long int  marpaXml_DOMImplementationSource_t;
typedef unsigned long long int  marpaXml_Node_t;
typedef unsigned long long int  marpaXml_Attr_t;
typedef unsigned long long int  marpaXml_Text_t;
typedef unsigned long long int  marpaXml_Comment_t;
typedef unsigned long long int  marpaXml_DOMConfiguration_t;
typedef unsigned long long int  marpaXml_CDATASection_t;
typedef unsigned long long int  marpaXml_Notation_t;
typedef unsigned long long int  marpaXml_Entity_t;
typedef unsigned long long int  marpaXml_EntityReference_t;
typedef unsigned long long int  marpaXml_ProcessingInstruction_t;
typedef unsigned long long int  marpaXml_DocumentFragment_t;

typedef enum marpaXml_DOM_ObjectType {
  MARPAXML_DOM_OBJECTTYPE_NONE = 0,
  MARPAXML_DOM_OBJECTTYPE_DOMIMPLEMENTATION,
  MARPAXML_DOM_OBJECTTYPE_DOCUMENTTYPE,
  MARPAXML_DOM_OBJECTTYPE_DOCUMENT,
  MARPAXML_DOM_OBJECTTYPE_NODELIST,
  MARPAXML_DOM_OBJECTTYPE_NAMEDNODEMAP,
  MARPAXML_DOM_OBJECTTYPE_USERDATAHANDLER,
  MARPAXML_DOM_OBJECTTYPE_ELEMENT,
  MARPAXML_DOM_OBJECTTYPE_TYPEINFO,
  MARPAXML_DOM_OBJECTTYPE_DOMLOCATOR,
  MARPAXML_DOM_OBJECTTYPE_DOMEXCEPTION,
  MARPAXML_DOM_OBJECTTYPE_DOMSTRINGLIST,
  MARPAXML_DOM_OBJECTTYPE_NAMELIST,
  MARPAXML_DOM_OBJECTTYPE_DOMIMPLEMENTATIONLIST,
  MARPAXML_DOM_OBJECTTYPE_DOMIMPLEMENTATIONSOURCE,
  MARPAXML_DOM_OBJECTTYPE_NODE,
  MARPAXML_DOM_OBJECTTYPE_ATTR,
  MARPAXML_DOM_OBJECTTYPE_TEXT,
  MARPAXML_DOM_OBJECTTYPE_COMMENT,
  MARPAXML_DOM_OBJECTTYPE_DOMCONFIGURATION,
  MARPAXML_DOM_OBJECTTYPE_CDATASECTION,
  MARPAXML_DOM_OBJECTTYPE_NOTATION,
  MARPAXML_DOM_OBJECTTYPE_ENTITY,
  MARPAXML_DOM_OBJECTTYPE_ENTITYREFERENCE,
  MARPAXML_DOM_OBJECTTYPE_PROCESSINGINSTRUCTION,
  MARPAXML_DOM_OBJECTTYPE_DOCUMENTFRAGMENT,
} marpaXml_DOM_ObjectType_t;

typedef enum marpaXml_DOM_ExceptionCode {
  MARPAXML_DOM_EXCEPTION_NONE              =  0,
  /* ExceptionCode */
  MARPAXML_DOM_INDEX_SIZE_ERR              =  1,
  MARPAXML_DOM_DOMSTRING_SIZE_ERR          =  2,
  MARPAXML_DOM_HIERARCHY_REQUEST_ERR       =  3,
  MARPAXML_DOM_WRONG_DOCUMENT_ERR          =  4,
  MARPAXML_DOM_INVALID_CHARACTER_ERR       =  5,
  MARPAXML_DOM_NO_DATA_ALLOWED_ERR         =  6,
  MARPAXML_DOM_NO_MODIFICATION_ALLOWED_ERR =  7,
  MARPAXML_DOM_NOT_FOUND_ERR               =  8,
  MARPAXML_DOM_NOT_SUPPORTED_ERR           =  9,
  MARPAXML_DOM_INUSE_ATTRIBUTE_ERR         = 10,
  MARPAXML_DOM_INVALID_STATE_ERR           = 11, /* Introduced in DOM Level 2: */
  MARPAXML_DOM_SYNTAX_ERR                  = 12, /* Introduced in DOM Level 2: */
  MARPAXML_DOM_INVALID_MODIFICATION_ERR    = 13, /* Introduced in DOM Level 2: */
  MARPAXML_DOM_NAMESPACE_ERR               = 14, /* Introduced in DOM Level 2: */
  MARPAXML_DOM_INVALID_ACCESS_ERR          = 15, /* Introduced in DOM Level 2: */
  MARPAXML_DOM_VALIDATION_ERR              = 16, /* Introduced in DOM Level 3: */
  MARPAXML_DOM_TYPE_MISMATCH_ERR           = 17, /* Introduced in DOM Level 3: */
} marpaXml_DOM_ExceptionCode_t;

typedef enum marpaXml_DOM_NodeType {
  /* NodeType */
  MARPAXML_DOM_ELEMENT_NODE                =  1,
  MARPAXML_DOM_ATTRIBUTE_NODE              =  2,
  MARPAXML_DOM_TEXT_NODE                   =  3,
  MARPAXML_DOM_CDATA_SECTION_NODE          =  4,
  MARPAXML_DOM_ENTITY_REFERENCE_NODE       =  5,
  MARPAXML_DOM_ENTITY_NODE                 =  6,
  MARPAXML_DOM_PROCESSING_INSTRUCTION_NODE =  7,
  MARPAXML_DOM_COMMENT_NODE                =  8,
  MARPAXML_DOM_DOCUMENT_NODE               =  9,
  MARPAXML_DOM_DOCUMENT_TYPE_NODE          = 10,
  MARPAXML_DOM_DOCUMENT_FRAGMENT_NODE      = 11,
  MARPAXML_DOM_NOTATION_NODE               = 12,
} marpaXml_DOM_NodeType_t;

typedef enum marpaXml_DOM_DocumentPosition {
  /* DocumentPosition */
  MARPAXML_DOM_DOCUMENT_POSITION_DISCONNECTED = 0x01,
  MARPAXML_DOM_DOCUMENT_POSITION_PRECEDING    = 0x02,
  MARPAXML_DOM_DOCUMENT_POSITION_FOLLOWING    = 0x04,
  MARPAXML_DOM_DOCUMENT_POSITION_CONTAINS     = 0x08,
  MARPAXML_DOM_DOCUMENT_POSITION_CONTAINED_BY = 0x10,
  MARPAXML_DOM_DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20,
} marpaXml_DOM_DocumentPosition_t;

typedef enum marpaXml_DOM_DerivationMethods {
  /* DerivationMethods */
  MARPAXML_DOM_DERIVATION_RESTRICTION  = 0x00000001,
  MARPAXML_DOM_DERIVATION_EXTENSION    = 0x00000002,
  MARPAXML_DOM_DERIVATION_UNION        = 0x00000004,
  MARPAXML_DOM_DERIVATION_LIST         = 0x00000008,
} marpaXml_DOM_DerivationMethods_t;

typedef enum marpaXml_DOM_OperationType {
  /* OperationType */
  MARPAXML_DOM_NODE_CLONED   = 1,
  MARPAXML_DOM_NODE_IMPORTED = 2,
  MARPAXML_DOM_NODE_DELETED  = 3,
  MARPAXML_DOM_NODE_RENAMED  = 4,
  MARPAXML_DOM_NODE_ADOPTED  = 5,
} marpaXml_DOM_OperationType_t;

typedef enum marpaXml_DOM_ErrorSeverity {
  MARPAXML_DOM_SEVERITY_NONE        = 0,
  /* ErrorSeverity */
  MARPAXML_DOM_SEVERITY_WARNING     = 1,
  MARPAXML_DOM_SEVERITY_ERROR       = 2,
  MARPAXML_DOM_SEVERITY_FATAL_ERROR = 3
} marpaXml_DOM_ErrorSeverity_t;

typedef struct marpaXml_DOMError {
  marpaXml_DOM_ErrorSeverity_t severity;
  marpaXml_DOMString_t         message;
  marpaXml_DOMString_t         type;
  /* marpaXml_DOMObject_t         relatedException; */ /* NOT IMPLEMENTED */
  /* marpaXml_DOMObject_t         relatedData; */ /* NOT IMPLEMENTED */
  marpaXml_DOMLocator_t        location;
} marpaXml_DOMError_t;
extern marpaXml_DOMError_t marpaXml_DOMError;

/*************************************/
/*        DOMStringList              */
/*************************************/
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t   marpaXml_DOMStringList_item(marpaXml_DOMStringList_t DOMstringList, unsigned long long int index);
unsigned long long int marpaXml_DOMStringList_getLength(marpaXml_DOMStringList_t DOMstringList);
marpaXml_DOMBoolean_t  marpaXml_DOMStringList_contains(marpaXml_DOMStringList_t DOMstringList, marpaXml_DOMString_t str);
marpaXml_DOMBoolean_t  marpaXml_DOMStringList_free(marpaXml_DOMStringList_t DOMstringList);

/*************************************/
/*           NameList                */
/*************************************/
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t   marpaXml_NameList_getName(unsigned long long int index);
marpaXml_DOMString_t   marpaXml_NameList_getNamespaceURI(unsigned long long int index);
unsigned long long int marpaXml_NameList_getLength(void);
marpaXml_DOMBoolean_t  marpaXml_NameList_contains(marpaXml_DOMString_t str);
marpaXml_DOMBoolean_t  marpaXml_NameList_containsNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t name);
marpaXml_DOMBoolean_t  marpaXml_NameList_free(marpaXml_NameList_t marpaXml_NameList);

/*************************************/
/*     DOMImplementationList         */
/*************************************/
/* Introduced in DOM Level 3: */
marpaXml_DOMImplementation_t marpaXml_DOMImplementationList_item(marpaXml_DOMImplementationList_t DOMImplementationList, unsigned long long int index);
unsigned long long int       marpaXml_DOMImplementationList_getLength(marpaXml_DOMImplementationList_t DOMImplementationList);
marpaXml_DOMBoolean_t        marpaXml_DOMImplementationList_free(marpaXml_DOMImplementationList_t marpaXml_DOMImplementationList);

/*************************************/
/*    DOMImplementationSource        */
/*************************************/
/* Introduced in DOM Level 3: */
marpaXml_DOMImplementation_t     marpaXml_DOMImplementationSource_getDOMImplementation(marpaXml_DOMString_t features);
marpaXml_DOMImplementationList_t marpaXml_DOMImplementationSource_getDOMImplementationList(marpaXml_DOMString_t features);

/*************************************/
/*       DOMImplementation           */
/*************************************/
marpaXml_DOMBoolean_t   marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
/* Introduced in DOM Level 2: */
marpaXml_DocumentType_t marpaXml_DOMImplementation_createDocumentType(marpaXml_DOMString_t qualifiedName, marpaXml_DOMString_t publicId, marpaXml_DOMString_t systemId, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException):  INVALID_CHARACTER_ERR, NAMESPACE_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Document_t     marpaXml_DOMImplementation_createDocument(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DocumentType_t doctype, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NAMESPACE_ERR, WRONG_DOCUMENT_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 3: NOT IMPLEMENTED */
/* marpaXml_DOMObject_t    marpaXml_DOMImplementation_getFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version); */

/*************************************/
/*                Node               */
/*************************************/
#define MARPAXML_NODE_DECLARATIONS(objectType)			    \
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getNodeName(void);	\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getNodeValue(marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): DOMSTRING_SIZE_ERR */ \
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _setNodeValue(marpaXml_DOMString_t nodeName, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR: */ \
  unsigned short          marpaXml_ ## objectType ## _getNodeType(void);	\
  marpaXml_Node_t         marpaXml_ ## objectType ## _getParentNode(void);	\
  marpaXml_NodeList_t     marpaXml_ ## objectType ## _getChildNodes(void);	\
  marpaXml_Node_t         marpaXml_ ## objectType ## _getFirstChild(void);	\
  marpaXml_Node_t         marpaXml_ ## objectType ## _getLastChild(void);	\
  marpaXml_Node_t         marpaXml_ ## objectType ## _getPreviousSibling(void); \
  marpaXml_Node_t         marpaXml_ ## objectType ## _getNextSibling(void);	\
  marpaXml_NamedNodeMap_t marpaXml_ ## objectType ## _getAttributes(void);	\
  /* Modified in DOM Level 2: */					\
  marpaXml_Document_t     marpaXml_ ## objectType ## _getOwnerDocument(void); \
  /* Modified in DOM Level 3: */					\
  marpaXml_Node_t         marpaXml_ ## objectType ## _insertBefore(marpaXml_Node_t newChild, marpaXml_Node_t refChild, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): HIERARCHY_REQUEST_ERR, WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR, NOT_SUPPORTED_ERR */ \
  /* Modified in DOM Level 3: */					\
  marpaXml_Node_t         marpaXml_ ## objectType ## _replaceChild(marpaXml_Node_t newChild, marpaXml_Node_t oldChild, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): HIERARCHY_REQUEST_ERR, WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR, NOT_SUPPORTED_ERR */ \
  /* Modified in DOM Level 3: */					\
  marpaXml_Node_t         marpaXml_ ## objectType ## _removeChild(marpaXml_Node_t oldChild, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR, NOT_SUPPORTED_ERR */ \
  /* Modified in DOM Level 3: */					\
  marpaXml_Node_t         marpaXml_ ## objectType ## _appendChild(marpaXml_Node_t newChild, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): HIERARCHY_REQUEST_ERR, WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, NOT_SUPPORTED_ERR */ \
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _hasChildNodes(void);	\
  marpaXml_Node_t         marpaXml_ ## objectType ## _cloneNode(marpaXml_DOMBoolean_t deep); \
  /* Modified in DOM Level 3: */					\
  void                    marpaXml_ ## objectType ## _normalize(void);	\
  /* Introduced in DOM Level 2: */					\
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _isSupported(marpaXml_DOMString_t feature, marpaXml_DOMString_t version); \
  /* Introduced in DOM Level 2: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getNamespaceURI(void); \
  /* Introduced in DOM Level 2: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getPrefix(void);	\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _setPrefix(marpaXml_DOMString_t prefix, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): INVALID_CHARACTER_ERR, NO_MODIFICATION_ALLOWED_ERR, NAMESPACE_ERR */ \
  /* Introduced in DOM Level 2: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getLocalName(void);	\
  /* Introduced in DOM Level 2: */					\
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _hasAttributes(void);	\
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getBaseURI(void);	\
  /* Introduced in DOM Level 3: */					\
  unsigned short          marpaXml_ ## objectType ## _compareDocumentPosition(marpaXml_Node_t other, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): NOT_SUPPORTED_ERR */ \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _getTextContent(marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): DOMSTRING_SIZE_ERR */ \
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _setTextContent(marpaXml_DOMString_t textContent, marpaXml_DOMException_t *DOMExceptionp);  /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */ \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _isSameNode(marpaXml_Node_t other); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _lookupPrefix(marpaXml_DOMString_t namespaceURI); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _isDefaultNamespace(marpaXml_DOMString_t namespaceURI); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMString_t    marpaXml_ ## objectType ## _lookupNamespaceURI(marpaXml_DOMString_t prefix); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMBoolean_t   marpaXml_ ## objectType ## _isEqualNode(marpaXml_Node_t arg); \
  /* Introduced in DOM Level 3: */					\
  /* marpaXml_DOMObject_t    marpaXml_ ## objectType ## _getFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version); */ /* NOT IMPLEMENTED */ \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMUserData_t  marpaXml_ ## objectType ## _setUserData(marpaXml_DOMString_t key, marpaXml_DOMUserData_t data, marpaXml_UserDataHandler_t handler); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMUserData_t  marpaXml_ ## objectType ## _getUserData(marpaXml_DOMString_t key);

MARPAXML_NODE_DECLARATIONS(Node)

/*************************************/
/*             NodeList              */
/*************************************/
marpaXml_Node_t        marpaXml_NodeList_item(unsigned long long int index);
unsigned long long int marpaXml_NodeList_getLength(void);
marpaXml_DOMBoolean_t  marpaXml_NodeList_free(marpaXml_NodeList_t marpaXml_NodeList);

/*************************************/
/*           NamedNodeMap            */
/*************************************/
marpaXml_Node_t        marpaXml_NamedNodeMap_getNamedItem(marpaXml_DOMString_t name);
marpaXml_Node_t        marpaXml_NamedNodeMap_setNamedItem(marpaXml_Node_t arg, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, INUSE_ATTRIBUTE_ERR, HIERARCHY_REQUEST_ERR */
marpaXml_Node_t        marpaXml_NamedNodeMap_removeNamedItem(marpaXml_DOMString_t name, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_FOUND_ERR, NO_MODIFICATION_ALLOWED_ERR */
marpaXml_Node_t        marpaXml_NamedNodeMap_item(unsigned long long int index);
unsigned long long int marpaXml_NamedNodeMap_length(void);
/* Introduced in DOM Level 2: */
marpaXml_Node_t        marpaXml_NamedNodeMap_getNamedItemNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Node_t        marpaXml_NamedNodeMap_setNamedItemNS(marpaXml_Node_t arg, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, INUSE_ATTRIBUTE_ERR, HIERARCHY_REQUEST_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Node_t        marpaXml_NamedNodeMap_removeNamedItemNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_FOUND_ERR, NO_MODIFICATION_ALLOWED_ERR, NOT_SUPPORTED_ERR */

/*************************************/
/*          CharacterData            */
/*************************************/
#define MARPAXML_CHARACTERDATA_DECLARATIONS(objectType)				\
  MARPAXML_NODE_DECLARATIONS(objectType)				\
  marpaXml_DOMString_t   marpaXml_ ## objectType ## _getData(marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): DOMSTRING_SIZE_ERR */ \
  marpaXml_DOMString_t   marpaXml_ ## objectType ## _setData(marpaXml_DOMString_t data, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */ \
  unsigned long long int marpaXml_ ## objectType ## _getLength(void);	\
  marpaXml_DOMString_t   marpaXml_ ## objectType ## _substringData(unsigned long offset, unsigned long count, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INDEX_SIZE_ERR, DOMSTRING_SIZE_ERR */ \
  void                   marpaXml_ ## objectType ## _appendData(marpaXml_DOMString_t arg, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */ \
  void                   marpaXml_ ## objectType ## _insertData(unsigned long offset, marpaXml_DOMString_t arg, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INDEX_SIZE_ERR, NO_MODIFICATION_ALLOWED_ERR */ \
  void                   marpaXml_ ## objectType ## _deleteData(unsigned long offset, unsigned long count, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INDEX_SIZE_ERR, NO_MODIFICATION_ALLOWED_ERR */ \
  void                   marpaXml_ ## objectType ## _replaceData(unsigned long offset, unsigned long count, marpaXml_DOMString_t arg, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INDEX_SIZE_ERR, NO_MODIFICATION_ALLOWED_ERR */ \

MARPAXML_CHARACTERDATA_DECLARATIONS(CharacterData)

/*************************************/
/*               Attr                */
/*************************************/
MARPAXML_NODE_DECLARATIONS(Attr)
marpaXml_DOMString_t  marpaXml_Attr_getName(void);
marpaXml_DOMBoolean_t marpaXml_Attr_getSpecified(void);
marpaXml_DOMString_t  marpaXml_Attr_getValue(void);
marpaXml_DOMString_t  marpaXml_Attr_setValue(marpaXml_DOMString_t value, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Element_t    marpaXml_Attr_getOwnerElement(void);
/* Introduced in DOM Level 3: */
marpaXml_TypeInfo_t   marpaXml_Attr_getSchemaTypeInfo(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMBoolean_t marpaXml_Attr_isId(void);

/*************************************/
/*             Element               */
/*************************************/
MARPAXML_NODE_DECLARATIONS(Element)
marpaXml_DOMString_t  marpaXml_Element_getTagName(void);
marpaXml_DOMString_t  marpaXml_Element_getAttribute(marpaXml_DOMString_t name);
void                  marpaXml_Element_setAttribute(marpaXml_DOMString_t name, marpaXml_DOMString_t value, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NO_MODIFICATION_ALLOWED_ERR */
void                  marpaXml_Element_removeAttribute(marpaXml_DOMString_t name, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */
marpaXml_Attr_t       marpaXml_Element_getAttributeNode(marpaXml_DOMString_t name);
marpaXml_Attr_t       marpaXml_Element_setAttributeNode(marpaXml_Attr_t newAttr, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, INUSE_ATTRIBUTE_ERR */
marpaXml_Attr_t       marpaXml_Element_removeAttributeNode(marpaXml_Attr_t oldAttr, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR */
marpaXml_NodeList_t   marpaXml_Element_getElementsByTagName(marpaXml_DOMString_t name);
/* Introduced in DOM Level 2: */
marpaXml_DOMString_t  marpaXml_Element_getAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
void                  marpaXml_Element_setAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMString_t value, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NO_MODIFICATION_ALLOWED_ERR, NAMESPACE_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
void                  marpaXml_Element_removeAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Attr_t       marpaXml_Element_getAttributeNodeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Attr_t       marpaXml_Element_setAttributeNodeNS(marpaXml_Attr_t newAttr, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): WRONG_DOCUMENT_ERR, NO_MODIFICATION_ALLOWED_ERR, INUSE_ATTRIBUTE_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_NodeList_t   marpaXml_Element_getElementsByTagNameNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_DOMBoolean_t marpaXml_Element_hasAttribute(marpaXml_DOMString_t name);
/* Introduced in DOM Level 2: */
marpaXml_DOMBoolean_t marpaXml_Element_hasAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 3: */
marpaXml_TypeInfo_t   marpaXml_Element_getSchemaTypeInfo(void);
/* Introduced in DOM Level 3: */
void                  marpaXml_Element_setIdAttribute(marpaXml_DOMString_t name, marpaXml_DOMBoolean_t isId, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR */
/* Introduced in DOM Level 3: */
void                  marpaXml_Element_setIdAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName, marpaXml_DOMBoolean_t isId, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR */
/* Introduced in DOM Level 3: */
void                  marpaXml_Element_setIdAttributeNode(marpaXml_Attr_t idAttr, marpaXml_DOMBoolean_t isId, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR, NOT_FOUND_ERR */

/*************************************/
/*              Text                 */
/*************************************/
#define MARPAXML_TEXT_DECLARATIONS(objectType)				\
  MARPAXML_CHARACTERDATA_DECLARATIONS(objectType) 			\
  marpaXml_Text_t      marpaXml_Text_splitText(unsigned long long int offset, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INDEX_SIZE_ERR, NO_MODIFICATION_ALLOWED_ERR */ \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMBoolean_t marpaXml_Text_isElementContentWhitespace_get(void); \
  /* Introduced in DOM Level 3: */					\
  marpaXml_DOMString_t  marpaXml_Text_getWoleText(void);		\
  /* Introduced in DOM Level 3: */					\
  marpaXml_Text_t       marpaXml_Text_replaceWholeText(marpaXml_DOMString_t content, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */

MARPAXML_TEXT_DECLARATIONS(Text)

/*************************************/
/*            Comment                */
/*************************************/
MARPAXML_CHARACTERDATA_DECLARATIONS(Comment)

/* Introduced in DOM Level 3: */
/*************************************/
/*            TypeInfo               */
/*************************************/
marpaXml_DOMString_t  marpaXml_TypeInfo_getTypeName(void);
marpaXml_DOMString_t  marpaXml_TypeInfo_getTypeNamespace(void);
marpaXml_DOMBoolean_t marpaXml_TypeInfo_isDerivedFrom(marpaXml_DOMString_t typeNamespaceArg, marpaXml_DOMString_t typeNameArg, unsigned long derivationMethod);

/* Introduced in DOM Level 3: */
/*************************************/
/*         UserDataHandler           */
/*************************************/
void marpaXml_UserDataHandler_handle(unsigned short operation, marpaXml_DOMString_t key, marpaXml_DOMUserData_t data, marpaXml_Node_t src, marpaXml_Node_t dst);

/* Introduced in DOM Level 3: */
/*************************************/
/*             DOMError              */
/*************************************/
unsigned short        marpaXml_DOMError_getSeverity(void);
marpaXml_DOMString_t  marpaXml_DOMError_getMessage(void);
marpaXml_DOMString_t  marpaXml_DOMError_getType(void);
/* marpaXml_DOMObject_t  marpaXml_DOMError_getRelatedException(void); */ /* NOT IMPLEMENTED */
/* marpaXml_DOMObject_t  marpaXml_DOMError_getRelatedData(void); */ /* NOT IMPLEMENTED */
marpaXml_DOMLocator_t marpaXml_DOMError_getLocation(void);

/* Introduced in DOM Level 3: */
/*************************************/
/*         DOMErrorHandler           */
/*************************************/
marpaXml_DOMBoolean_t marpaXml_DOMErrorHandler_handleError(marpaXml_DOMError_t error);

/* Introduced in DOM Level 3: */
/*************************************/
/*            DOMLocator             */
/*************************************/
signed long long int marpaXml_DOMLocator_getLineNumber(void);
signed long long int marpaXml_DOMLocator_getColumnNumber(void);
signed long long int marpaXml_DOMLocator_getByteOffset(void);
signed long long int marpaXml_DOMLocator_getUtf16Offset(void);
marpaXml_Node_t      marpaXml_DOMLocator_getRelatedNode(void);
marpaXml_DOMString_t marpaXml_DOMLocator_getUri(void);

/* Introduced in DOM Level 3: */
/*************************************/
/*         DOMConfiguration          */
/*************************************/
void                     marpaXml_DOMConfiguration_setParameter(marpaXml_DOMString_t name, marpaXml_DOMUserData_t value, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_FOUND_ERR, NOT_SUPPORTED_ERR, TYPE_MISMATCH_ERR */
marpaXml_DOMUserData_t   marpaXml_DOMConfiguration_getParameter(marpaXml_DOMString_t name, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_FOUND_ERR */
marpaXml_DOMBoolean_t    marpaXml_DOMConfiguration_canSetParameter(marpaXml_DOMString_t name, marpaXml_DOMUserData_t value);
marpaXml_DOMStringList_t marpaXml_DOMConfiguration_getParameterNames(void);

/*************************************/
/*           CDATASection            */
/*************************************/
MARPAXML_TEXT_DECLARATIONS(CDATASection)

/*************************************/
/*           DocumentType            */
/*************************************/
MARPAXML_NODE_DECLARATIONS(DocumentType)
marpaXml_DOMString_t    marpaXml_DocumentType_getName(void);
marpaXml_NamedNodeMap_t marpaXml_DocumentType_getEntities(void);
marpaXml_NamedNodeMap_t marpaXml_DocumentType_getNotations(void);
/* Introduced in DOM Level 2: */
marpaXml_DOMString_t    marpaXml_DocumentType_getPublicId(void);
/* Introduced in DOM Level 2: */
marpaXml_DOMString_t    marpaXml_DocumentType_getSystemId(void);
/* Introduced in DOM Level 2: */
marpaXml_DOMString_t    marpaXml_DocumentType_getInternalSubset(void);

/*************************************/
/*             Notation              */
/*************************************/
MARPAXML_NODE_DECLARATIONS(Notation)
marpaXml_DOMString_t marpaXml_Notation_getPublicId(void);
marpaXml_DOMString_t marpaXml_Notation_getSystemId(void);

/*************************************/
/*              Entity               */
/*************************************/
MARPAXML_NODE_DECLARATIONS(Entity)
marpaXml_DOMString_t marpaXml_Entity_getPublicId(void);
marpaXml_DOMString_t marpaXml_Entity_getSystemId(void);
marpaXml_DOMString_t marpaXml_Entity_getNotationName(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t marpaXml_Entity_getInputEncoding(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t marpaXml_Entity_getXmlEncoding(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t marpaXml_Entity_getXmlVersion(void);

/*************************************/
/*          EntityReference          */
/*************************************/
MARPAXML_NODE_DECLARATIONS(EntityReference)

/*************************************/
/*       ProcessingInstruction       */
/*************************************/
MARPAXML_NODE_DECLARATIONS(ProcessingInstruction)
marpaXml_DOMString_t marpaXml_ProcessingInstruction_getTarget(void);
marpaXml_DOMString_t marpaXml_ProcessingInstruction_getData(void);
marpaXml_DOMString_t marpaXml_ProcessingInstruction_setData(marpaXml_DOMString_t data, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NO_MODIFICATION_ALLOWED_ERR */

/*************************************/
/*         DocumentFragment          */
/*************************************/
MARPAXML_NODE_DECLARATIONS(DocumentFragment)

/*************************************/
/*            Document               */
/*************************************/
MARPAXML_NODE_DECLARATIONS(Document)
/* Modified in DOM Level 3: */
marpaXml_DocumentType_t          marpaXml_Document_getDoctype(void);
marpaXml_DOMImplementation_t     marpaXml_Document_getImplementation(void);
marpaXml_Element_t               marpaXml_Document_getDocumentElement(void);
marpaXml_Element_t               marpaXml_Document_createElement(marpaXml_DOMString_t tagName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR */
marpaXml_DocumentFragment_t      marpaXml_Document_createDocumentFragment(void);
marpaXml_Text_t                  marpaXml_Document_createTextNode(marpaXml_DOMString_t data);
marpaXml_Comment_t               marpaXml_Document_createComment(marpaXml_DOMString_t data);
marpaXml_CDATASection_t          marpaXml_Document_createCDATASection(marpaXml_DOMString_t data, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
marpaXml_ProcessingInstruction_t marpaXml_Document_createProcessingInstruction(marpaXml_DOMString_t target, marpaXml_DOMString_t data, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NOT_SUPPORTED_ERR */
marpaXml_Attr_t                  marpaXml_Document_createAttribute(marpaXml_DOMString_t name, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR */
marpaXml_EntityReference_t       marpaXml_Document_createEntityReference(marpaXml_DOMString_t name, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NOT_SUPPORTED_ERR */
marpaXml_NodeList_t              marpaXml_Document_getElementsByTagName(marpaXml_DOMString_t tagname);
/* Introduced in DOM Level 2: */
marpaXml_Node_t                  marpaXml_Document_importNode(marpaXml_Node_t importedNode, marpaXml_DOMBoolean_t deep, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR, INVALID_CHARACTER_ERR */
/* Introduced in DOM Level 2: */
marpaXml_Element_t               marpaXml_Document_createElementNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NAMESPACE_ERR, NOT_SUPPORTED_ER */
/* Introduced in DOM Level 2: */
marpaXml_Attr_t                  marpaXml_Document_createAttributeNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): INVALID_CHARACTER_ERR, NAMESPACE_ERR, NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 2: */
marpaXml_NodeList_t              marpaXml_Document_getElementsByTagNameNS(marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t localName);
/* Introduced in DOM Level 2: */
marpaXml_Element_t               marpaXml_Document_getElementById(marpaXml_DOMString_t elementId);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t             marpaXml_Document_getInputEncoding(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t             marpaXml_Document_getXmlEncoding(void);
/* Introduced in DOM Level 3: */
marpaXml_DOMBoolean_t            marpaXml_Document_getXmlStandalone(void);
marpaXml_DOMBoolean_t            marpaXml_Document_setXmlStandalone(marpaXml_DOMBoolean_t xmlStandalone, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t             marpaXml_Document_getXmlVersion(void);
marpaXml_DOMString_t             marpaXml_Document_setXmlVersion(marpaXml_DOMString_t xmlVersion, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR */
/* Introduced in DOM Level 3: */
marpaXml_DOMBoolean_t            marpaXml_Document_getStrictErrorChecking(void);
marpaXml_DOMBoolean_t            marpaXml_Document_setStrictErrorChecking(marpaXml_DOMBoolean_t strictErrorChecking);
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t             marpaXml_Document_getDocumentURI(void);
marpaXml_DOMString_t             marpaXml_Document_setDocumentURI(marpaXml_DOMString_t documentURI);
/* Introduced in DOM Level 3: */
marpaXml_Node_t                  marpaXml_Document_adoptNode(marpaXml_Node_t source, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR, NO_MODIFICATION_ALLOWED_ERR */
/* Introduced in DOM Level 3: */
marpaXml_DOMConfiguration_t      marpaXml_Document_getDomConfig(void);
/* Introduced in DOM Level 3: */
void                             marpaXml_Document_normalizeDocument(void);
/* Introduced in DOM Level 3: */
marpaXml_Node_t                  marpaXml_Document_renameNode(marpaXml_Node_t n, marpaXml_DOMString_t namespaceURI, marpaXml_DOMString_t qualifiedName, marpaXml_DOMException_t *DOMExceptionp); /* raises(DOMException): NOT_SUPPORTED_ERR, INVALID_CHARACTER_ERR, WRONG_DOCUMENT_ERR, NAMESPACE_ERR */

/* Prelease basic types used in the DOM idl */
#include "marpaXml/_types.h"

/* All classes inherit from dom, that is an object which is holding a context: */
SUBCLASS(DOM, Object)
  void *ctx;
VTABLE(DOM, Object)
  void *(*getCtx)();
  void *(*setCtx)(void *ctx);
METHODS
  DOM *DOM_new();
  void DOM_free(DOM *me);
END_CLASS

/* ----------------------------------------------------------------------------------- */
/* We are following exactly the declaration sequences in official DOM Level 3 Code IDL */
/* ----------------------------------------------------------------------------------- */
/* We FIX DOMString to be a NULL-byte terminated UTF-8 */
typedef unsigned char DOMString[];
/* Unused, but we declare it anyway */
typedef unsigned long long DOMTimeStamp;
/* Others */
typedef void *DOMUserData;
typedef Object DOMObject;
/* Forward declarations */
FORWARD_CLASS(DOMImplementation);
FORWARD_CLASS(DocumentType);
FORWARD_CLASS(Document);
FORWARD_CLASS(NodeList);
FORWARD_CLASS(NamedNodeMap);
FORWARD_CLASS(UserDataHandler);
FORWARD_CLASS(Element);
FORWARD_CLASS(TypeInfo);
FORWARD_CLASS(DOMLocator);

#include "DOM/DOMException.h"
#include "DOM/DOMStringList.h"
#include "DOM/NameList.h"
#include "DOM/DOMImplementationList.h"
#include "DOM/DOMImplementationSource.h"
#include "DOM/DOMImplementation.h"
#include "DOM/Node.h"
#include "DOM/NodeList.h"
#include "DOM/NamedNodeMap.h"
#include "DOM/CharacterData.h"
#include "DOM/Attr.h"
#include "DOM/Element.h"
#include "DOM/Text.h"
#include "DOM/Comment.h"
#include "DOM/TypeInfo.h"
#include "DOM/UserDataHandler.h"
#include "DOM/DOMError.h"
#include "DOM/DOMErrorHandler.h"
#include "DOM/DOMLocator.h"
#include "DOM/DOMConfiguration.h"
#include "DOM/CDATASection.h"
#include "DOM/DocumentType.h"
#include "DOM/Notation.h"
#include "DOM/Entity.h"
#include "DOM/EntityReference.h"
#include "DOM/ProcessingInstruction.h"
#include "DOM/DocumentFragment.h"
#include "DOM/Document.h"

#endif /* MARPAXML_API_DOM_H_ */
