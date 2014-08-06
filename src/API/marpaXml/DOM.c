#include <stdlib.h>

#include <unicode/ustring.h>
#include <unicode/uchar.h>

#include "internal/DOMStringLiterals.hpp"
#include "API/marpaXml/DOM.h"
#include "internal/config.h"

static C_INLINE MARPAXML_DOM_TYPE(boolean) _DOMImplementation_hasFeature(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version);

#define MARPAXML_DOM_OBJECT_CONSTRUCTOR_AND_DESTRUCTOR(typeName)	\
  static C_INLINE marpaXml_DOM_##boolean##_t _marpaXml_DOM_##typeName##_init(marpaXml_DOM_##typeName##_t thisp); \
  static C_INLINE void                       _marpaXml_DOM_##typeName##_destroy(marpaXml_DOM_##typeName##_t thisp); \
									\
  marpaXml_DOM_##typeName##_t marpaXml_DOM_##typeName##_new(void) {	\
    marpaXml_DOM_##typeName##_t thisp = (marpaXml_DOM_##typeName##_t) malloc(sizeof(struct marpaXml_DOM_##typeName)); \
    if (thisp == NULL) {						\
      return NULL;							\
    }									\
    if (_marpaXml_DOM_##typeName##_init(thisp) == MARPAXML_DOM_FALSE) {	\
      marpaXml_DOM_##typeName##_free(thisp);				\
      return NULL;							\
    }									\
    return thisp;								\
  }									\
  void marpaXml_DOM_##typeName##_free(marpaXml_DOM_##typeName##_t thisp) { _marpaXml_DOM_##typeName##_destroy(thisp); } \

#define _MARPAXML_DOM_FUNC_INIT(typeName)     _marpaXml_DOM_##typeName##_init
#define _MARPAXML_DOM_FUNC_DESTROY(typeName)  _marpaXml_DOM_##typeName##_destroy

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

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/
typedef enum {
  MARPAXML_DOM_DOMIMPLEMENTATION_HASFEATURE_CORE = MARPAXML_DOM_STRINGLITERAL_CORE,
  MARPAXML_DOM_DOMIMPLEMENTATION_HASFEATURE_XML = MARPAXML_DOM_STRINGLITERAL_XML,
  _MARPAXML_DOM_DOMIMPLEMENTATION_HASFEATURE_MAX
} marpaXml_DOM_DOMImplementation_feature_t;

typedef enum {
  MARPAXML_DOM_DOMIMPLEMENTATION_VERSION_1_0 = MARPAXML_DOM_STRINGLITERAL_1_0,
  MARPAXML_DOM_DOMIMPLEMENTATION_VERSION_2_0 = MARPAXML_DOM_STRINGLITERAL_2_0,
  MARPAXML_DOM_DOMIMPLEMENTATION_VERSION_3_0 = MARPAXML_DOM_STRINGLITERAL_3_0,
  _MARPAXML_DOM_DOMIMPLEMENTATION_VERSION_MAX
} marpaXml_DOM_DOMImplementation_version_t;

static C_INLINE MARPAXML_DOM_TYPE(boolean) _MARPAXML_DOM_FUNC_INIT(DOMImplementation)(MARPAXML_DOM_TYPE(DOMImplementation) thisp) {
  thisp->hasFeature = &_DOMImplementation_hasFeature;
  return MARPAXML_DOM_TRUE;
}

static C_INLINE void _MARPAXML_DOM_FUNC_DESTROY(DOMImplementation)(MARPAXML_DOM_TYPE(DOMImplementation) thisp) {
  if (thisp != NULL) {
    free(thisp);
  }
}

static C_INLINE MARPAXML_DOM_TYPE(boolean) _DOMImplementation_hasFeature(MARPAXML_DOM_TYPE(DOMString) feature, MARPAXML_DOM_TYPE(DOMString) version) {
  UErrorCode uErrorCode = U_ZERO_ERROR;
  int i;

  if (feature == NULL) {
    return MARPAXML_DOM_FALSE;
  }

  /* version can be NULL or one of those known */
  if (version != NULL) {
    for (i = 0; i < _MARPAXML_DOM_DOMIMPLEMENTATION_VERSION_MAX; i++) {
      if (u_strCaseCompare((UChar *) version->s,
			   version->length,
			   marpaXml_DOMStringLiteral_buffer(i), marpaXml_DOMStringLiteral_length(i),
			   U_FOLD_CASE_DEFAULT,
			   &uErrorCode) != 0 || U_FAILURE(uErrorCode)) {
	return MARPAXML_DOM_FALSE;
      }
    }
  }

  for (i = 0; i < _MARPAXML_DOM_DOMIMPLEMENTATION_HASFEATURE_MAX; i++) {
    if (u_strCaseCompare((UChar *) feature->s,
			 feature->length,
			 marpaXml_DOMStringLiteral_buffer(i), marpaXml_DOMStringLiteral_length(i),
			 U_FOLD_CASE_DEFAULT,
			 &uErrorCode) == 0 && U_SUCCESS(uErrorCode)) {
      return MARPAXML_DOM_TRUE;
    }
  }

  return MARPAXML_DOM_FALSE;
}

