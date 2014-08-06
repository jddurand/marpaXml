#include <stdlib.h>

#include <unicode/ustring.h>
#include <unicode/uchar.h>
#include <unicode/uclean.h>

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

#define MARPAXML_DOM_U_STRCASECOMPARE(s1, s2) u_strCaseCompare((UChar *) (s1)->s, (s1)->length,(UChar *) (s2)->s, (s2)->length, U_FOLD_CASE_DEFAULT, &uErrorCode) == 0 && U_SUCCESS(uErrorCode)

#define MARPAXML_DOM_N_ELEMENTS(array) (sizeof(array)/sizeof((array)[0])) 

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
/*                            init                                 */
/*                                                                 */
/*******************************************************************/
#define MARPAXML_DOM_STRINGLITERAL_CORE_LENGTH 4
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_CORE, "Core", MARPAXML_DOM_STRINGLITERAL_CORE_LENGTH);

#define MARPAXML_DOM_STRINGLITERAL_XML_LENGTH 3
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_XML, "XML", MARPAXML_DOM_STRINGLITERAL_XML_LENGTH);

#define MARPAXML_DOM_STRINGLITERAL_1_0_LENGTH 3
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_1_0, "1.0", MARPAXML_DOM_STRINGLITERAL_1_0_LENGTH);

#define MARPAXML_DOM_STRINGLITERAL_2_0_LENGTH 3
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_2_0, "2.0", MARPAXML_DOM_STRINGLITERAL_2_0_LENGTH);

#define MARPAXML_DOM_STRINGLITERAL_3_0_LENGTH 3
U_STRING_DECL(MARPAXML_DOM_STRINGLITERAL_3_0, "3.0", MARPAXML_DOM_STRINGLITERAL_3_0_LENGTH);

MARPAXML_DOM_TYPE(boolean) marpaXml_DOM_init(void) {
  UErrorCode uErrorCode = U_ZERO_ERROR;

  u_init(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    return MARPAXML_DOM_FALSE;
  }

  U_STRING_INIT(MARPAXML_DOM_STRINGLITERAL_CORE, "Core", MARPAXML_DOM_STRINGLITERAL_CORE_LENGTH);
  U_STRING_INIT(MARPAXML_DOM_STRINGLITERAL_XML, "XML", MARPAXML_DOM_STRINGLITERAL_XML_LENGTH);
  U_STRING_INIT(MARPAXML_DOM_STRINGLITERAL_1_0, "1.0", MARPAXML_DOM_STRINGLITERAL_1_0_LENGTH);
  U_STRING_INIT(MARPAXML_DOM_STRINGLITERAL_2_0, "2.0", MARPAXML_DOM_STRINGLITERAL_2_0_LENGTH);
  U_STRING_INIT(MARPAXML_DOM_STRINGLITERAL_3_0, "3.0", MARPAXML_DOM_STRINGLITERAL_3_0_LENGTH);

  return MARPAXML_DOM_TRUE;
}

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/

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
  UErrorCode                      uErrorCode = U_ZERO_ERROR;
  MARPAXML_DOM_STRUCT(DOMString) versions[3] = {
    { (unsigned short *) MARPAXML_DOM_STRINGLITERAL_1_0, MARPAXML_DOM_STRINGLITERAL_1_0_LENGTH },
    { (unsigned short *) MARPAXML_DOM_STRINGLITERAL_2_0, MARPAXML_DOM_STRINGLITERAL_2_0_LENGTH },
    { (unsigned short *) MARPAXML_DOM_STRINGLITERAL_3_0, MARPAXML_DOM_STRINGLITERAL_3_0_LENGTH }
  };
  MARPAXML_DOM_STRUCT(DOMString) features[3] = {
    { (unsigned short *) MARPAXML_DOM_STRINGLITERAL_CORE, MARPAXML_DOM_STRINGLITERAL_CORE_LENGTH },
    { (unsigned short *) MARPAXML_DOM_STRINGLITERAL_XML, MARPAXML_DOM_STRINGLITERAL_XML_LENGTH },
  };
  MARPAXML_DOM_TYPE(boolean)      versionOk = MARPAXML_DOM_FALSE;
  MARPAXML_DOM_TYPE(boolean)      featureOk = MARPAXML_DOM_FALSE;
  int                             i;

  if (feature == NULL) {
    return MARPAXML_DOM_FALSE;
  }

  /* version can be NULL or one of those known */
  if (version != NULL) {
    for (i = 0; i < MARPAXML_DOM_N_ELEMENTS(versions); i++) {
      uErrorCode = U_ZERO_ERROR;
      if (MARPAXML_DOM_U_STRCASECOMPARE(version, &(versions[i]))) {
	versionOk = MARPAXML_DOM_TRUE;
	break;
      }
    }
  } else {
    versionOk = MARPAXML_DOM_TRUE;
  }

  if (versionOk == MARPAXML_DOM_FALSE) {
    return MARPAXML_DOM_FALSE;
  }

  for (i = 0; i < MARPAXML_DOM_N_ELEMENTS(features); i++) {
    uErrorCode = U_ZERO_ERROR;
    if (MARPAXML_DOM_U_STRCASECOMPARE(feature, &(features[i]))) {
      featureOk = MARPAXML_DOM_TRUE;
      break;
    }
  }

  return featureOk;
}

