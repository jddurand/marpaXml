#include <stdlib.h>

#include "API/marpaXml/DOM.h"
#include "internal/config.h"

#define MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(typeName)	\
  static C_INLINE marpaXml_DOM_##boolean##_t _marpaXml_DOM_##typeName##_init(marpaXml_DOM_##typeName##_t marpaXml_DOM_##typeName); \
  static C_INLINE void _marpaXml_DOM_##typeName##_free(marpaXml_DOM_##typeName##_t marpaXml_DOM_##typeName); \
  marpaXml_DOM_##typeName##_t marpaXml_DOM_##typeName##_new(void) {	\
    marpaXml_DOM_##typeName##_t marpaXml_DOM_##typeName = (marpaXml_DOM_##typeName##_t) malloc(sizeof(struct marpaXml_DOM_##typeName)); \
    if (marpaXml_DOM_##typeName == NULL) {				\
      return NULL;							\
    }									\
    if (_marpaXml_DOM_##typeName##_init(marpaXml_DOM_##typeName) == MARPAXML_DOM_FALSE) { \
      _marpaXml_DOM_##typeName##_free(marpaXml_DOM_##typeName);		\
      return NULL;							\
    }									\
    return marpaXml_DOM_##typeName;					\
  }									\
  void marpaXml_DOM_##typeName##_destroy(marpaXml_DOM_##typeName##_t this) { if (this != NULL) {free(this); } }

#define _MARPAXML_DOM_FUNC_INIT(typeName) _marpaXml_DOM_##typeName##_init
#define MARPAXML_DOM_VAR(typeName)         marpaXml_DOM_##typeName

MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMImplementation)
/*
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DocumentType)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Document)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(NodeList)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(NamedNodeMap)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(UserDataHandler)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Element)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(TypeInfo)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMLocator)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMException)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMStringList)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(NameList)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMImplementationList)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMImplementationSource)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Node)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Attr)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Text)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Comment)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMError)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMErrorHandler)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DOMConfiguration)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(CDATASection)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Notation)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(Entity)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(EntityReference)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(ProcessingInstruction)
MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(DocumentFragment)
*/

static C_INLINE MARPAXML_DOM_TYPE(boolean) _DOMImplementation_hasFeature(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version) {
}

static C_INLINE MARPAXML_DOM_TYPE(boolean) _MARPAXML_DOM_FUNC_INIT(DOMImplementation)(MARPAXML_DOM_TYPE(DOMImplementation) MARPAXML_DOM_VAR(DOMImplementation)) {
  MARPAXML_DOM_VAR(DOMImplementation)->hasFeature = &_DOMImplementation_hasFeature;
}

