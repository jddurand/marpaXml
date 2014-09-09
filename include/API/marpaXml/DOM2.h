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


/*
  0. All DOM objects are prefixed with marpaXml_DOM
  1. new methods returns a non-NULL pointer on success, NULL on failure. Others, inclusing "free" methods, return a marpaXml_boolean_t
  2. get methods always require the last parameter (pointer to the output) to not be NULL.
  3. free methods always use a pointer to pointer that must be non NULL, to make sure its content NULL at return and if success
  4. methods that can generate an exception have a last parameter: marpaXml_DOMException_t **exceptionpp

  So the usage is always:

  if ((thisp = xxx_new(...))    == NULL)           { ... failure ... }
  if (xxx_setYyy(thisp, value)  == marpaXml_false) { ... failure ... }
  if (xxx_getYyy(thisp, &value) == marpaXml_false) { ... failure ... }
  if (xxx_method(thisp, ...)    == marpaXml_false) { ... failure ... }
  if (xxx_free(&thisp)          == marpaXml_false) { ... failure ... }

  The only exceptions are the marpaXml_DOM_init(), marpaXml_DOM_done() and marpaXml_DOM_release(), that
  are not part of the IDL.

  I could have played with cplus, ooc, etc... but I did not feed I would have gained so much
  by abstracting and making code less readable, just to have the OO pattern in here.

*/

#include "marpaXml/boolean.h"
#include "marpaXml/String.h"
#include "marpaXml/log.h"

/*************************
   Options
 *************************/
typedef struct marpaXml_DOM_Option {
  const char                  *dbFilename;                    /* Default: ":memory:"                          */
  const char                  *locale;                        /* Default: NULL                                */
  int                          collStrength;                  /* Default: -1                                  */
  marpaXmlLog_Option_t         logOption;
} marpaXml_DOM_Option_t;

/*
  Can be called several times, but one is enough. Defaults will apply ONLY if parameter is NULL.
  This routine is thread-safe.
  If not called explicitely, it is guaranteed that all other methods will do it with a NULL parameter.
*/
marpaXml_boolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *optionp);
/*
  Must be called when parsing is finished to free persistent data, leaving outside of DOM objects
*/
marpaXml_boolean_t marpaXml_DOM_done(void);
/*
  Must be called once only, typically at program exit or library unload.
  This routine is not thread-safe.
  All in all, simply do not call it - the memory leaks are small if you call marpaXml_DOM_done().
*/
marpaXml_boolean_t marpaXml_DOM_release(void);

/* Types */
typedef void                                      marpaXml_DOMUserData_t;
typedef void                                      marpaXml_DOMObject_t;
typedef struct marpaXml_DOMException              marpaXml_DOMException_t;
typedef struct marpaXml_DOMError                  marpaXml_DOMError_t;
typedef struct marpaXml_DOMStringList             marpaXml_DOMStringList_t;
typedef struct marpaXml_NameList                  marpaXml_NameList_t;
typedef struct marpaXml_DOMImplementationList     marpaXml_DOMImplementationList_t;
typedef struct marpaXml_DOMImplementationSource   marpaXml_DOMImplementationSource_t;
typedef struct marpaXml_DOMImplementation         marpaXml_DOMImplementation_t;
typedef struct marpaXml_Node                      marpaXml_Node_t;
typedef struct marpaXml_NodeList                  marpaXml_NodeList_t;
typedef struct marpaXml_NamedNodeMap              marpaXml_NamedNodeMap_t;
typedef struct marpaXml_CharacterData             marpaXml_CharacterData_t;
typedef struct marpaXml_Attr                      marpaXml_Attr_t;
typedef struct marpaXml_Element                   marpaXml_Element_t;
typedef struct marpaXml_Text                      marpaXml_Text_t;
typedef struct marpaXml_Comment                   marpaXml_Comment_t;
typedef struct marpaXml_TypeInfo                  marpaXml_TypeInfo_t;
typedef struct marpaXml_UserDataHandler           marpaXml_UserDataHandler_t;
typedef struct marpaXml_DOMErrorHandler           marpaXml_DOMErrorHandler_t;
typedef struct marpaXml_DOMLocator                marpaXml_DOMLocator_t;
typedef struct marpaXml_DOMConfiguration          marpaXml_DOMConfiguration_t;
typedef struct marpaXml_CDATASection              marpaXml_CDATASection_t;
typedef struct marpaXml_DocumentType              marpaXml_DocumentType_t;
typedef struct marpaXml_Notation                  marpaXml_Notation_t;
typedef struct marpaXml_Entity                    marpaXml_Entity_t;
typedef struct marpaXml_EntityReference           marpaXml_EntityReference_t;
typedef struct marpaXml_ProcessingInstruction     marpaXml_ProcessingInstruction_t;
typedef struct marpaXml_DocumentFragment          marpaXml_DocumentFragment_t;
typedef struct marpaXml_Document                  marpaXml_Document_t;

marpaXml_DOMException_t *marpaXml_DOMException_new       (short code, marpaXml_String_t *messagep);
marpaXml_boolean_t       marpaXml_DOMException_getCode   (marpaXml_DOMException_t *thisp, unsigned short *codep);
marpaXml_boolean_t       marpaXml_DOMException_setCode   (marpaXml_DOMException_t *thisp, unsigned short code);
marpaXml_boolean_t       marpaXml_DOMException_getMessage(marpaXml_DOMException_t *thisp, marpaXml_String_t **messagepp);
marpaXml_boolean_t       marpaXml_DOMException_setMessage(marpaXml_DOMException_t *thisp, marpaXml_String_t *messagep);
marpaXml_boolean_t       marpaXml_DOMException_free      (marpaXml_DOMException_t **thispp);

/* ExceptionCode */
#define MARPAXML_INDEX_SIZE_ERR                 1;
#define MARPAXML_DOMSTRING_SIZE_ERR             2;
#define MARPAXML_HIERARCHY_REQUEST_ERR          3;
#define MARPAXML_WRONG_DOCUMENT_ERR             4;
#define MARPAXML_INVALID_CHARACTER_ERR          5;
#define MARPAXML_NO_DATA_ALLOWED_ERR            6;
#define MARPAXML_NO_MODIFICATION_ALLOWED_ERR    7;
#define MARPAXML_NOT_FOUND_ERR                  8;
#define MARPAXML_NOT_SUPPORTED_ERR              9;
#define MARPAXML_INUSE_ATTRIBUTE_ERR            10;
#define MARPAXML_INVALID_STATE_ERR              11;
#define MARPAXML_SYNTAX_ERR                     12;
#define MARPAXML_INVALID_MODIFICATION_ERR       13;
#define MARPAXML_NAMESPACE_ERR                  14;
#define MARPAXML_INVALID_ACCESS_ERR             15;
#define MARPAXML_VALIDATION_ERR                 16;
#define MARPAXML_TYPE_MISMATCH_ERR              17;

marpaXml_DOMStringList_t           *marpaXml_DOMStringList_new(void);
marpaXml_boolean_t                  marpaXml_DOMStringList_item(marpaXml_DOMStringList_t *thisp, unsigned long index, marpaXml_String_t **itempp);
marpaXml_boolean_t                  marpaXml_DOMStringList_getLength(marpaXml_DOMStringList_t *thisp,  unsigned long *lengthp);
marpaXml_boolean_t                  marpaXml_DOMStringList_contains(marpaXml_DOMStringList_t *thisp, marpaXml_String_t *strp, marpaXml_boolean_t *containsp);
marpaXml_boolean_t                  marpaXml_DOMStringList_free(marpaXml_DOMStringList_t **thisp);

marpaXml_NameList_t                *marpaXml_NameList_new(void);
marpaXml_boolean_t                  marpaXml_NameList_getName(marpaXml_NameList_t *thisp, unsigned long index, marpaXml_String_t **namepp);
marpaXml_boolean_t                  marpaXml_NameList_getNamespaceURI(marpaXml_NameList_t *thisp, unsigned long index, marpaXml_String_t **namespaceURIpp);
marpaXml_boolean_t                  marpaXml_NameList_getLength(marpaXml_NameList_t *thisp, unsigned long *lengthp);
marpaXml_boolean_t                  marpaXml_NameList_contains(marpaXml_NameList_t *thisp, marpaXml_String_t *strp, marpaXml_boolean_t *containsp);
marpaXml_boolean_t                  marpaXml_NameList_containsNS(marpaXml_NameList_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *namep, marpaXml_boolean_t *containsNSp);
marpaXml_boolean_t                  marpaXml_NameList_free(marpaXml_NameList_t **thispp);

marpaXml_DOMImplementationList_t   *marpaXml_DOMImplementationList_new(void);
marpaXml_boolean_t                  marpaXml_DOMImplementationList_item(marpaXml_DOMImplementationList_t *thisp, unsigned long index, marpaXml_DOMImplementation_t **itempp);
marpaXml_boolean_t                  marpaXml_DOMImplementationList_getLength(marpaXml_DOMImplementationList_t *thisp, unsigned long *lengthp);
marpaXml_boolean_t                  marpaXml_DOMImplementationList_free(marpaXml_DOMImplementationList_t **thispp);

marpaXml_DOMImplementationSource_t *marpaXml_DOMImplementationSource_new(void);
marpaXml_boolean_t                  marpaXml_DOMImplementationSource_getDOMImplementation(marpaXml_DOMImplementationSource_t *thisp, marpaXml_String_t *featuresp, marpaXml_DOMImplementation_t **DOMImplementationpp);
marpaXml_boolean_t                  marpaXml_DOMImplementationSource_getDOMImplementationList(marpaXml_DOMImplementationSource_t *thisp, marpaXml_String_t *featuresp, marpaXml_DOMImplementationList_t **DOMImplementationListpp);
marpaXml_boolean_t                  marpaXml_DOMImplementationSource_free(marpaXml_DOMImplementationSource_t **thispp);

marpaXml_DOMImplementation_t       *marpaXml_DOMImplementation_new(void);
marpaXml_boolean_t                  marpaXml_DOMImplementation_hasFeature(marpaXml_DOMImplementation_t *thisp, marpaXml_String_t *featurep, marpaXml_String_t *versionp, marpaXml_boolean_t *hasFeaturep);
marpaXml_boolean_t                  marpaXml_DOMImplementation_createDocumentType(marpaXml_DOMImplementation_t *thisp, marpaXml_String_t *qualifiedNamep, marpaXml_String_t *publicIdp, marpaXml_String_t *systemIdp, marpaXml_DocumentType_t **documentTypepp, marpaXml_DOMException_t **exceptionpp);
marpaXml_boolean_t                 *marpaXml_DOMImplementation_createDocument(marpaXml_DOMImplementation_t *thisp, marpaXml_String_t *namespaceURIp,  marpaXml_String_t *qualifiedNamep, marpaXml_DocumentType_t *doctypep, marpaXml_Document_t **documentpp, marpaXml_DOMException_t **exceptionpp);
marpaXml_boolean_t                 *marpaXml_DOMImplementation_getFeature(marpaXml_DOMImplementation_t *thisp, marpaXml_String_t *featurep, marpaXml_String_t *versionp, marpaXml_DOMObject_t **featurepp);
marpaXml_boolean_t                  marpaXml_DOMImplementation_free(marpaXml_DOMImplementation_t **thispp);

/* NodeType */
#define MARPAXML_ELEMENT_NODE                   1;
#define MARPAXML_ATTRIBUTE_NODE                 2;
#define MARPAXML_TEXT_NODE                      3;
#define MARPAXML_CDATA_SECTION_NODE             4;
#define MARPAXML_ENTITY_REFERENCE_NODE          5;
#define MARPAXML_ENTITY_NODE                    6;
#define MARPAXML_PROCESSING_INSTRUCTION_NODE    7;
#define MARPAXML_COMMENT_NODE                   8;
#define MARPAXML_DOCUMENT_NODE                  9;
#define MARPAXML_DOCUMENT_TYPE_NODE             10;
#define MARPAXML_DOCUMENT_FRAGMENT_NODE         11;
#define MARPAXML_NOTATION_NODE                  12;

/* DocumentPosition */
#define MARPAXML_DOCUMENT_POSITION_DISCONNECTED = 0x01;
#define MARPAXML_DOCUMENT_POSITION_PRECEDING    = 0x02;
#define MARPAXML_DOCUMENT_POSITION_FOLLOWING    = 0x04;
#define MARPAXML_DOCUMENT_POSITION_CONTAINS     = 0x08;
#define MARPAXML_DOCUMENT_POSITION_CONTAINED_BY = 0x10;
#define MARPAXML_DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20;

/* Herited methods: we use a #define */
marpaXml_Node_t    *marpaXml_Node_new(void);
#define MARPAXML_NODE_METHODS(class) \
  marpaXml_boolean_t  marpaXml_##class##_getNodeName(marpaXml_##class##_t *thisp, marpaXml_String_t **nodeNamepp); \
  marpaXml_boolean_t  marpaXml_##class##_getNodeValue(marpaXml_##class##_t *thisp, marpaXml_String_t **nodeValuepp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_setNodeValue(marpaXml_##class##_t *thisp, marpaXml_String_t *nodeValuep, marpaXml_DOMException_t *exceptionp);	\
  marpaXml_boolean_t  marpaXml_##class##_getNodeType(marpaXml_##class##_t *thisp, unsigned short **nodeTypepp);	\
  marpaXml_boolean_t  marpaXml_##class##_getParentNode(marpaXml_##class##_t *thisp, marpaXml_Node_t **parendNodepp); \
  marpaXml_boolean_t  marpaXml_##class##_getChildNodes(marpaXml_##class##_t *thisp, marpaXml_NodeList_t **childNodespp); \
  marpaXml_boolean_t  marpaXml_##class##_getFirstChild(marpaXml_##class##_t *thisp, marpaXml_Node_t **firstChildpp); \
  marpaXml_boolean_t  marpaXml_##class##_getLastChild(marpaXml_##class##_t *thisp, marpaXml_Node_t **lastChildpp); \
  marpaXml_boolean_t  marpaXml_##class##_previousSibling(marpaXml_##class##_t *thisp, marpaXml_Node_t **previousSiblingpp); \
  marpaXml_boolean_t  marpaXml_##class##_nextSibling(marpaXml_##class##_t *thisp, marpaXml_Node_t **nextSibblingpp); \
  marpaXml_boolean_t  marpaXml_##class##_attributes(marpaXml_##class##_t *thisp, marpaXml_NamedNodeMap_t **attributespp); \
  marpaXml_boolean_t  marpaXml_##class##_ownerDocument(marpaXml_##class##_t *thisp, marpaXml_Document_t **ownerDocumentpp); \
  marpaXml_boolean_t  marpaXml_##class##_insertBefore(marpaXml_##class##_t *thisp, marpaXml_Node_t *newChildp, marpaXml_Node_t *refChildp, marpaXml_Node_t **insertBeforepp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_replaceChild(marpaXml_##class##_t *thisp, marpaXml_Node_t *newChildp, marpaXml_Node_t *oldChildp, marpaXml_Node_t **replaceChildpp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_removeChild(marpaXml_##class##_t *thisp, marpaXml_Node_t *oldChildp, marpaXml_Node_t **removeChildpp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_appendChild(marpaXml_##class##_t *thisp, marpaXml_Node_t *newChildp, marpaXml_Node_t **appendChildpp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_hasChildNodes(marpaXml_##class##_t *thisp, marpaXml_boolean_t **hasChildNodespp); \
  marpaXml_boolean_t  marpaXml_##class##_cloneNode(marpaXml_##class##_t *thisp, marpaXml_boolean_t deep, marpaXml_Node_t *nodepp); \
  marpaXml_boolean_t  marpaXml_##class##_normalize(marpaXml_##class##_t *thisp); \
  marpaXml_boolean_t  marpaXml_##class##_isSupported(marpaXml_##class##_t *thisp, marpaXml_String_t *featurep, marpaXml_String_t *versionp, marpaXml_boolean_t **isSupportedpp); \
  marpaXml_boolean_t  marpaXml_##class##_getNamespaceURI(marpaXml_##class##_t *thisp, marpaXml_String_t **namespaceURIpp); \
  marpaXml_boolean_t  marpaXml_##class##_getPrefix(marpaXml_##class##_t *thisp, marpaXml_String_t **prefixpp); \
  marpaXml_boolean_t  marpaXml_##class##_setPrefix(marpaXml_##class##_t *thisp, marpaXml_String_t *prefixp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_getLocalName(marpaXml_##class##_t *thisp, marpaXml_String_t *localNamepp); \
  marpaXml_boolean_t  marpaXml_##class##_hasAttributes(marpaXml_##class##_t *thisp, marpaXml_boolean_t **hasAttributespp); \
  marpaXml_boolean_t  marpaXml_##class##_getBaseURI(marpaXml_##class##_t *thisp, marpaXml_String_t **baseURIpp); \
  marpaXml_boolean_t  marpaXml_##class##_compareDocumentPosition(marpaXml_##class##_t *thisp, marpaXml_Node_t *otherp, unsigned short *comparep, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_getTextContent(marpaXml_##class##_t *thisp, marpaXml_String_t **textContentpp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_setTextContent(marpaXml_##class##_t *thisp, marpaXml_String_t *textContentp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t  marpaXml_##class##_isSameNode(marpaXml_##class##_t *thisp, marpaXml_Node_t *otherp, marpaXml_boolean_t *isSameNodep); \
  marpaXml_boolean_t  marpaXml_##class##_lookupPrefix(marpaXml_##class##_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t **lookupPrefixpp); \
  marpaXml_boolean_t  marpaXml_##class##_isDefaultNamespace(marpaXml_##class##_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_boolean_t *isDefaultNamespacep); \
  marpaXml_boolean_t  marpaXml_##class##_lookupNamespaceURI(marpaXml_##class##_t *thisp, marpaXml_String_t *prefixp, marpaXml_String_t **namespaceURIpp); \
  marpaXml_boolean_t  marpaXml_##class##_isEqualNode(marpaXml_##class##_t *thisp, marpaXml_Node_t *argp, marpaXml_boolean_t *equalp); \
  marpaXml_boolean_t  marpaXml_##class##_getFeature(marpaXml_##class##_t *thisp, marpaXml_String_t *featurep, marpaXml_String_t *versionp, marpaXml_DOMObject_t **featurepp); \
  marpaXml_boolean_t  marpaXml_##class##_setUserData(marpaXml_##class##_t *thisp, marpaXml_String_t *keyp, marpaXml_DOMUserData_t *userDatap, marpaXml_UserDataHandler_t *handlerp); \
  marpaXml_boolean_t  marpaXml_##class##_getUserData(marpaXml_##class##_t *thisp, marpaXml_String_t *keyp, marpaXml_DOMUserData_t **userDatapp);
MARPAXML_NODE_METHODS(Node)
marpaXml_boolean_t  marpaXml_Node_free(marpaXml_Node_t **thispp);

marpaXml_NodeList_t *marpaXml_NodeList_new(void);
marpaXml_boolean_t   marpaXml_NodeList_item(marpaXml_NodeList_t *thisp, unsigned long index, marpaXml_Node_t **nodepp);
marpaXml_boolean_t   marpaXml_NodeList_getLength(marpaXml_NodeList_t *thisp, unsigned long *lengthp);
marpaXml_boolean_t   marpaXml_NodeList_free(marpaXml_NodeList_t **thispp);

marpaXml_NamedNodeMap_t *marpaXml_NamedNodeMap_new(void);
marpaXml_boolean_t       marpaXml_NamedNodeMap_getNamedItem(marpaXml_NamedNodeMap_t *thisp, marpaXml_String_t *namep, marpaXml_Node_t **namedItempp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_setNamedItem(marpaXml_NamedNodeMap_t *thisp, marpaXml_Node_t *namedItemp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_removeNamedItem(marpaXml_NamedNodeMap_t *thisp, marpaXml_String_t *namep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_item(marpaXml_NamedNodeMap_t *thisp, unsigned long index, marpaXml_Node_t **itempp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_getLength(marpaXml_NamedNodeMap_t *thisp, unsigned long **lengthp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_getNamedItemNS(marpaXml_NamedNodeMap_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_Node_t **namedItemNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_setNamedItemNS(marpaXml_NamedNodeMap_t *thisp, marpaXml_Node_t *namedItemNSp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_removeNamedItemNS(marpaXml_NamedNodeMap_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_Node_t **namedItemNSp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t       marpaXml_NamedNodeMap_free(marpaXml_NamedNodeMap_t **thispp);

marpaXml_CharacterData_t *marpaXml_CharacterData_new(void);
#define MARPAXML_CHARACTERDATA_METHODS(class)				\
  MARPAXML_NODE_METHODS(class)						\
  marpaXml_boolean_t        marpaXml_##class##_getData(marpaXml_##class##_t *thisp, marpaXml_String_t **datapp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_setData(marpaXml_##class##_t *thisp, marpaXml_String_t *datap, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_getLength(marpaXml_##class##_t *thisp, unsigned long *lengthp); \
  marpaXml_boolean_t        marpaXml_##class##_substringData(marpaXml_##class##_t *thisp, unsigned long offset, unsigned long count, marpaXml_String_t **substringDatapp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_appendData(marpaXml_##class##_t *thisp, marpaXml_String_t *datap, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_insertData(marpaXml_##class##_t *thisp, unsigned long offset, marpaXml_String_t *datap, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_deleteData(marpaXml_##class##_t *thisp, unsigned long offset, unsigned long count, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t        marpaXml_##class##_replaceData(marpaXml_##class##_t this, unsigned long offset, unsigned long count, marpaXml_String_t *datap, marpaXml_DOMException_t *exceptionp);
MARPAXML_CHARACTERDATA_METHODS(CharacterData)
marpaXml_boolean_t        marpaXml_CharacterData_free(marpaXml_CharacterData_t **thispp);

marpaXml_Attr_t    *marpaXml_Attr_new(void);
MARPAXML_NODE_METHODS(Attr)
marpaXml_boolean_t  marpaXml_Attr_getName(marpaXml_Attr_t *thisp, marpaXml_String_t **namepp);
marpaXml_boolean_t  marpaXml_Attr_getSpecified(marpaXml_Attr_t *thisp, marpaXml_boolean_t *specifiedp);
marpaXml_boolean_t  marpaXml_Attr_getValue(marpaXml_Attr_t *thisp, marpaXml_String_t *valuepp);
marpaXml_boolean_t  marpaXml_Attr_setValue(marpaXml_Attr_t *thisp, marpaXml_String_t *valuep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Attr_getOwnerElement(marpaXml_Attr_t *thisp, marpaXml_Element_t **ownerElementpp);
marpaXml_boolean_t  marpaXml_Attr_getSchemaTypeInfo(marpaXml_Attr_t *thisp, marpaXml_TypeInfo_t **schemaTypeInfopp);
marpaXml_boolean_t  marpaXml_Attr_getIsId(marpaXml_Attr_t *thisp, marpaXml_boolean_t *isIdp);
marpaXml_boolean_t  marpaXml_Attr_free(marpaXml_Attr_t **thispp);

marpaXml_Element_t *marpaXml_Element_new(void);
MARPAXML_NODE_METHODS(Element)
marpaXml_boolean_t  marpaXml_Element_getTagName(marpaXml_Element_t *thisp, marpaXml_String_t **tagNamepp);
marpaXml_boolean_t  marpaXml_Element_getAttribute(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_String_t **attributepp);
marpaXml_boolean_t  marpaXml_Element_setAttribute(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_String_t *valuep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_removeAttribute(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_getAttributeNode(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_Attr_t **attributeNodepp);
marpaXml_boolean_t  marpaXml_Element_setAttributeNode(marpaXml_Element_t *thisp, marpaXml_Attr_t *attributeNodep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_removeAttributeNode(marpaXml_Element_t *thisp, marpaXml_Attr_t *oldAttrp, marpaXml_Attr_t **attributepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_getElementsByTagName(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_NodeList_t **elementsByTagNamepp);
marpaXml_boolean_t  marpaXml_Element_getAttributeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_String_t **attributeNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_setAttributeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *qualifiedNamep, marpaXml_String_t *valuep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_removeAttributeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_getAttributeNodeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_Attr_t **attributeNodeNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_setAttributeNodeNS(marpaXml_Element_t *thisp, marpaXml_Attr_t *newAttrp, marpaXml_Attr_t **attributeNodeNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_getElementsByTagNameNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_NodeList_t **elementsByTagNameNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_hasAttribute(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_boolean_t *hasp);
marpaXml_boolean_t  marpaXml_Element_hasAttributeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_boolean_t *hasNSp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_getSchemaTypeInfo(struct marpaXml_Element *thisp, marpaXml_TypeInfo_t **schemaTypeInfopp);
marpaXml_boolean_t  marpaXml_Element_setIdAttribute(marpaXml_Element_t *thisp, marpaXml_String_t *namep, marpaXml_boolean_t isId, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_setIdAttributeNS(marpaXml_Element_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *localNamep, marpaXml_boolean_t isId, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_setIdAttributeNode(marpaXml_Element_t *thisp, marpaXml_Attr_t *idAttrp, marpaXml_boolean_t isId, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t  marpaXml_Element_free(marpaXml_Element_t **thispp);

marpaXml_Text_t   *marpaXml_Text_new(void);
#define MARPAXML_TEXT_METHODS(class) \
  MARPAXML_CHARACTERDATA_METHODS(class)					\
  marpaXml_boolean_t marpaXml_##class##_splitText(marpaXml_##class##_t *thisp, unsigned long offset, marpaXml_Text_t **textpp, marpaXml_DOMException_t *exceptionp); \
  marpaXml_boolean_t marpaXml_##class##_getIsElementContentWhitespace(marpaXml_##class##_t *thisp, marpaXml_boolean_t *isElementContentWhitespacep); \
  marpaXml_boolean_t marpaXml_##class##_getWholeText(marpaXml_##class##_t *thisp, marpaXml_String_t **wholeTextpp); \
  marpaXml_boolean_t marpaXml_##class##_replaceWholeText(marpaXml_##class##_t *thisp, marpaXml_String_t *contentp, marpaXml_Text_t *wholeTextpp, marpaXml_DOMException_t *exceptionp);
MARPAXML_TEXT_METHODS(Text)
marpaXml_boolean_t marpaXml_Text_free(marpaXml_Text_t **thispp);

marpaXml_Comment_t *marpaXml_Comment_new(void);
MARPAXML_CHARACTERDATA_METHODS(Comment)
marpaXml_boolean_t  marpaXml_Comment_free(marpaXml_Comment_t **thispp);

/* DerivationMethods */
#define MARPAXML_DERIVATION_RESTRICTION         0x00000001;
#define MARPAXML_DERIVATION_EXTENSION           0x00000002;
#define MARPAXML_DERIVATION_UNION               0x00000004;
#define MARPAXML_DERIVATION_LIST                0x00000008;

marpaXml_TypeInfo_t *marpaXml_TypeInfo_new(void);
marpaXml_boolean_t   marpaXml_TypeInfo_getTypeName(marpaXml_TypeInfo_t *thisp, marpaXml_String_t **typeNamepp);
marpaXml_boolean_t   marpaXml_TypeInfo_getTypeNamespace(marpaXml_TypeInfo_t *thisp, marpaXml_String_t **typeNamespacepp);
marpaXml_boolean_t   marpaXml_TypeInfo_isDerivedFrom(marpaXml_TypeInfo_t *thisp, marpaXml_String_t *typeNamespaceArgp, marpaXml_String_t *typeNameArgp, unsigned long derivationMethod, marpaXml_boolean_t *isDerivedFromp);
marpaXml_boolean_t   marpaXml_TypeInfo_free(marpaXml_TypeInfo_t **thispp);

/* OperationType */
#define MARPAXML_NODE_CLONED                    1;
#define MARPAXML_NODE_IMPORTED                  2;
#define MARPAXML_NODE_DELETED                   3;
#define MARPAXML_NODE_RENAMED                   4;
#define MARPAXML_NODE_ADOPTED                   5;

marpaXml_UserDataHandler_t  *marpaXml_UserDataHandler_new(void);
marpaXml_boolean_t           marpaXml_UserDataHandler_handle(unsigned short operation, marpaXml_String_t *keyp, marpaXml_DOMUserData_t *datap, marpaXml_Node_t *srcp, marpaXml_Node_t *dstp);
marpaXml_boolean_t           marpaXml_UserDataHandler_free(marpaXml_UserDataHandler_t **thispp);

/* ErrorSeverity */
#define MARPAXML_SEVERITY_NONE                  0;
#define MARPAXML_SEVERITY_WARNING               1;
#define MARPAXML_SEVERITY_ERROR                 2;
#define MARPAXML_SEVERITY_FATAL_ERROR           3;

marpaXml_DOMError_t        *marpaXml_DOMError_new(void);
marpaXml_boolean_t          marpaXml_DOMError_getSeverity(marpaXml_DOMError_t *thisp, unsigned short *severityp);
marpaXml_boolean_t          marpaXml_DOMError_setSeverity(marpaXml_DOMError_t *thisp, unsigned short severity);
marpaXml_boolean_t          marpaXml_DOMError_getMessage(marpaXml_DOMError_t *thisp, marpaXml_String_t **messagepp);
marpaXml_boolean_t          marpaXml_DOMError_setMessage(marpaXml_DOMError_t *thisp, marpaXml_String_t *messagep);
marpaXml_boolean_t          marpaXml_DOMError_getType(marpaXml_DOMError_t *thisp, marpaXml_String_t **typepp);
marpaXml_boolean_t          marpaXml_DOMError_setType(marpaXml_DOMError_t *thisp, marpaXml_String_t *typep);
marpaXml_boolean_t          marpaXml_DOMError_getRelatedException(marpaXml_DOMError_t *thisp, marpaXml_DOMObject_t **objectpp);
marpaXml_boolean_t          marpaXml_DOMError_setRelatedException(marpaXml_DOMError_t *thisp, marpaXml_DOMObject_t *objectp);
marpaXml_boolean_t          marpaXml_DOMError_getRelatedData(marpaXml_DOMError_t *thisp, marpaXml_DOMObject_t **relatedDatapp);
marpaXml_boolean_t          marpaXml_DOMError_setRelatedData(marpaXml_DOMError_t *thisp, marpaXml_DOMObject_t *relatedDatap);
marpaXml_boolean_t          marpaXml_DOMError_getLocation(marpaXml_DOMError_t *thisp, marpaXml_DOMLocator_t **locationpp);
marpaXml_boolean_t          marpaXml_DOMError_setLocation(marpaXml_DOMError_t *thisp, marpaXml_DOMLocator_t *locationp);
marpaXml_boolean_t          marpaXml_DOMError_free(marpaXml_DOMError_t **thispp);

marpaXml_DOMErrorHandler_t *marpaXml_DOMErrorHandler_new(void);
marpaXml_boolean_t          marpaXml_DOMErrorHandler_handleError(marpaXml_DOMErrorHandler_t *thisp, marpaXml_DOMError_t *errorp, marpaXml_boolean_t *handleErrorp);
marpaXml_boolean_t          marpaXml_DOMErrorHandler_free(marpaXml_DOMErrorHandler_t **thispp);

marpaXml_DOMLocator_t *marpaXml_DOMLocator_new(void);
marpaXml_boolean_t     marpaXml_DOMLocator_getLineNumber(marpaXml_DOMLocator_t *thisp, long *lineNumberp);
marpaXml_boolean_t     marpaXml_DOMLocator_getColumnNumber(marpaXml_DOMLocator_t *thisp, long *columnNumberp);
marpaXml_boolean_t     marpaXml_DOMLocator_getByteOffset(marpaXml_DOMLocator_t *thisp, long *byteOffsetp);
marpaXml_boolean_t     marpaXml_DOMLocator_getUtf16Offset(marpaXml_DOMLocator_t *thisp, long *utf16Offsetp);
marpaXml_boolean_t     marpaXml_DOMLocator_getRelatedNode(marpaXml_DOMLocator_t *thisp, marpaXml_Node_t **relatedNodepp);
marpaXml_boolean_t     marpaXml_DOMLocator_getUri(marpaXml_DOMLocator_t *thisp, marpaXml_String_t **uripp);
marpaXml_boolean_t     marpaXml_DOMLocator_free(marpaXml_DOMLocator_t **thispp);

marpaXml_DOMConfiguration_t *marpaXml_DOMConfiguration_new(void);
marpaXml_boolean_t           marpaXml_DOMConfiguration_setParameter(marpaXml_DOMConfiguration_t *thisp, marpaXml_String_t *namep, marpaXml_DOMUserData_t *valuep, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t           marpaXml_DOMConfiguration_getParameter(marpaXml_DOMConfiguration_t *thisp, marpaXml_String_t *namep, marpaXml_DOMUserData_t **userDatapp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t           marpaXml_DOMConfiguration_canSetParameter(marpaXml_DOMConfiguration_t *thisp, marpaXml_String_t *namep, marpaXml_boolean_t *canSetParameterp, marpaXml_DOMUserData_t *valuep);
marpaXml_boolean_t           marpaXml_DOMConfiguration_getParameterNames(marpaXml_DOMConfiguration_t *thisp, marpaXml_DOMStringList_t **parameterNamespp);
marpaXml_boolean_t           marpaXml_DOMConfiguration_free(marpaXml_DOMConfiguration_t **thispp);

marpaXml_CDATASection_t *marpaXml_CDATASection_new(void);
MARPAXML_TEXT_METHODS(CDATASection)
marpaXml_boolean_t       marpaXml_CDATASection_free(marpaXml_CDATASection_t **thispp);

marpaXml_DocumentType_t *marpaXml_DocumentType_new(void);
MARPAXML_NODE_METHODS(DocumentType)
marpaXml_boolean_t       marpaXml_DocumentType_getName(marpaXml_DocumentType_t *thisp, marpaXml_String_t **namepp);
marpaXml_boolean_t       marpaXml_DocumentType_getEntities(marpaXml_DocumentType_t *thisp, marpaXml_NamedNodeMap_t **entitiespp);
marpaXml_boolean_t       marpaXml_DocumentType_getNotations(marpaXml_DocumentType_t *thisp, marpaXml_NamedNodeMap_t **notationspp);
marpaXml_boolean_t       marpaXml_DocumentType_getPublicId(marpaXml_DocumentType_t *thisp, marpaXml_String_t **publicIdpp);
marpaXml_boolean_t       marpaXml_DocumentType_getSystemId(marpaXml_DocumentType_t *thisp, marpaXml_String_t **systemIdpp);
marpaXml_boolean_t       marpaXml_DocumentType_getInternalSubset(marpaXml_DocumentType_t *thisp, marpaXml_String_t **internalSubsetpp);
marpaXml_boolean_t       marpaXml_DocumentType_marpaXml_DocumentType_free(marpaXml_DocumentType_t **thispp);

marpaXml_Notation_t *marpaXml_Notation_new(void);
MARPAXML_NODE_METHODS(Notation)
marpaXml_boolean_t   marpaXml_Notation_getPublicId(marpaXml_Notation_t *thisp, marpaXml_String_t **publicIdpp);
marpaXml_boolean_t   marpaXml_Notation_getSystemId(marpaXml_Notation_t *thisp, marpaXml_String_t **systemIdpp);
marpaXml_boolean_t   marpaXml_Notation_free(marpaXml_Notation_t **thispp);

marpaXml_Entity_t  *marpaXml_Entity_new(void);
MARPAXML_NODE_METHODS(Entity)
marpaXml_boolean_t  marpaXml_Entity_getPublicId(marpaXml_Entity_t *thisp, marpaXml_String_t **publicIdpp);
marpaXml_boolean_t  marpaXml_Entity_getSystemId(marpaXml_Entity_t *thisp, marpaXml_String_t **systemIdpp);
marpaXml_boolean_t  marpaXml_Entity_getNotationName(marpaXml_Entity_t *thisp, marpaXml_String_t **notationNamepp);
marpaXml_boolean_t  marpaXml_Entity_getInputEncoding(marpaXml_Entity_t *thisp, marpaXml_String_t **inputEncodingpp);
marpaXml_boolean_t  marpaXml_Entity_getXmlEncoding(marpaXml_Entity_t *thisp, marpaXml_String_t **xmlEncodingpp);
marpaXml_boolean_t  marpaXml_Entity_getXmlVersion(marpaXml_Entity_t *thisp, marpaXml_String_t **xmlVersionpp);
marpaXml_boolean_t  marpaXml_Entity_free(marpaXml_Entity_t **thispp);

marpaXml_EntityReference_t *marpaXml_EntityReference_new(void);
MARPAXML_NODE_METHODS(EntityReference)
marpaXml_boolean_t          marpaXml_EntityReference_free(marpaXml_EntityReference_t **thispp);

marpaXml_ProcessingInstruction_t *marpaXml_ProcessingInstruction_new(void);
MARPAXML_NODE_METHODS(ProcessingInstruction)
marpaXml_boolean_t                marpaXml_ProcessingInstruction_getTarget(marpaXml_ProcessingInstruction_t *thisp, marpaXml_String_t **targetpp);
marpaXml_boolean_t                marpaXml_ProcessingInstruction_getData(marpaXml_ProcessingInstruction_t *thisp, marpaXml_String_t **datapp);
marpaXml_boolean_t                marpaXml_ProcessingInstruction_setData(marpaXml_ProcessingInstruction_t *thisp, marpaXml_String_t *datap, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t                marpaXml_ProcessingInstruction_free(marpaXml_ProcessingInstruction_t **thispp);

marpaXml_DocumentFragment_t *marpaXml_DocumentFragment_new(void);
MARPAXML_NODE_METHODS(DocumentFragment)
marpaXml_boolean_t           marpaXml_DocumentFragment_free(marpaXml_DocumentFragment_t **thispp);

marpaXml_Document_t *marpaXml_Document_new(void);
MARPAXML_NODE_METHODS(Document)
marpaXml_boolean_t   marpaXml_Document_getDoctype(marpaXml_Document_t *thisp, marpaXml_DocumentType_t **doctypepp);
marpaXml_boolean_t   marpaXml_Document_getImplementation(marpaXml_Document_t *thisp, marpaXml_DOMImplementation_t **implementationpp);
marpaXml_boolean_t   marpaXml_Document_getDocumentElement(marpaXml_Document_t *thisp, marpaXml_Element_t **elementpp);
marpaXml_boolean_t   marpaXml_Document_createElement(marpaXml_Document_t *thisp, marpaXml_String_t *tagNamep, marpaXml_Element_t **elementpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createDocumentFragment(marpaXml_Document_t *thisp, marpaXml_DocumentFragment_t **documentFragmentpp);
marpaXml_boolean_t   marpaXml_Document_createTextNode(marpaXml_Document_t *thisp, marpaXml_String_t *datap, marpaXml_Text_t **textNodepp);
marpaXml_boolean_t   marpaXml_Document_createComment(marpaXml_Document_t *thisp, marpaXml_String_t *datap, marpaXml_Comment_t **commentpp);
marpaXml_boolean_t   marpaXml_Document_createCDATASection(marpaXml_Document_t *thisp, marpaXml_String_t *datap, marpaXml_CDATASection_t **CDATASectionpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createProcessingInstruction(marpaXml_Document_t *thisp, marpaXml_String_t *targetp, marpaXml_String_t *datap, marpaXml_ProcessingInstruction_t **processingInstructionpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createAttribute(marpaXml_Document_t *thisp, marpaXml_String_t *namep, marpaXml_Attr_t **attributepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createEntityReference(marpaXml_Document_t *thisp, marpaXml_String_t *namep, marpaXml_EntityReference_t **entityReferencepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_getElementsByTagName(marpaXml_Document_t *thisp, marpaXml_String_t *tagnamep, marpaXml_NodeList_t **elementsByTagNamepp);
marpaXml_boolean_t   marpaXml_Document_importNode(marpaXml_Document_t *thisp, marpaXml_Node_t *importedNodep, marpaXml_boolean_t deep, marpaXml_Node_t **nodepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createElementNS(marpaXml_Document_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *qualifiedNamep, marpaXml_Element_t **elementNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_createAttributeNS(marpaXml_Document_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_String_t *qualifiedNamep, marpaXml_Attr_t **attributeNSpp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_getElementsByTagNameNS(marpaXml_Document_t *thisp, marpaXml_String_t *namespaceURIp, marpaXml_NodeList_t **elementsByTagNameNSpp, marpaXml_String_t *localNamep);
marpaXml_boolean_t   marpaXml_Document_getElementById(marpaXml_Document_t *thisp, marpaXml_String_t *elementIdp, marpaXml_Element_t **elementByIdpp);
marpaXml_boolean_t   marpaXml_Document_getInputEncoding(marpaXml_Document_t *thisp, marpaXml_String_t **inputEncodingpp);
marpaXml_boolean_t   marpaXml_Document_getXmlEncoding(marpaXml_Document_t *thisp, marpaXml_String_t *xmlEncodingpp);
marpaXml_boolean_t   marpaXml_Document_getXmlStandalone(marpaXml_Document_t *thisp, marpaXml_boolean_t *xmlStandalonep);
marpaXml_boolean_t   marpaXml_Document_setXmlStandalone(marpaXml_Document_t *thisp, marpaXml_boolean_t xmlStandalone, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_getXmlVersion(marpaXml_Document_t *thisp, marpaXml_String_t **xmlVersionpp);
marpaXml_boolean_t   marpaXml_Document_setXmlVersion(marpaXml_Document_t *thisp, marpaXml_String_t *xmlVersionp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_getStrictErrorChecking(marpaXml_Document_t *thisp, marpaXml_boolean_t *strictErrorCheckingp);
marpaXml_boolean_t   marpaXml_Document_setStrictErrorChecking(marpaXml_Document_t *thisp, marpaXml_boolean_t strictErrorChecking);
marpaXml_boolean_t   marpaXml_Document_getDocumentURI(marpaXml_Document_t *thisp, marpaXml_String_t **documentURIpp);
marpaXml_boolean_t   marpaXml_Document_setDocumentURI(marpaXml_Document_t *thisp, marpaXml_String_t *documentURIp);
marpaXml_boolean_t   marpaXml_Document_adoptNode(marpaXml_Document_t *thisp, marpaXml_Node_t *sourcep, marpaXml_Node_t **nodepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_getDomConfig(marpaXml_Document_t *thisp, marpaXml_DOMConfiguration_t **DOMConfigurationpp);
marpaXml_boolean_t   marpaXml_Document_normalizeDocument(marpaXml_Document_t *thisp);
marpaXml_boolean_t   marpaXml_Document_renameNode(marpaXml_Document_t *thisp, marpaXml_Node_t *np, marpaXml_String_t *namespaceURIp, marpaXml_String_t *qualifiedNamep, marpaXml_Node_t **nodepp, marpaXml_DOMException_t *exceptionp);
marpaXml_boolean_t   marpaXml_Document_free(marpaXml_Document_t *thisp);

#endif /* MARPAXML_DOM_H_ */
