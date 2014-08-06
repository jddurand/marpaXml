#ifndef MARPAXML_INTERNAL_DOMSTRINGLITERALS_HPP
#define MARPAXML_INTERNAL_DOMSTRINGLITERALS_HPP

#include <unicode/uchar.h>

/* The DOMInit stuff existence has a single purpose: With C++, ICU offers
   Unicode string initialisations natively, while in C you have to do
   with macros U_STRING_DECL() and U_STRING_INIT(): you cannot produce
   a constant ICU Unicode string initializer in C. And I did NOT want
   to have a dependency on any mutex/semaphore stuff. Therefore DOM
   string literals are initialized the C++ way
*/

#ifdef __cplusplus 
extern "C" {
#endif

typedef enum {
  MARPAXML_DOM_STRINGLITERAL_1_0 = 0,
  MARPAXML_DOM_STRINGLITERAL_2_0,
  MARPAXML_DOM_STRINGLITERAL_3_0,
  MARPAXML_DOM_STRINGLITERAL_CORE,
  MARPAXML_DOM_STRINGLITERAL_XML,
  _MARPAXML_DOM_STRINGLITERAL_MAX,
} marpaXml_DOMStringLiteral_t;

const unsigned short *marpaXml_DOMStringLiteral_buffer(marpaXml_DOMStringLiteral_t marpaXml_DOMStringLiteral);
int32_t               marpaXml_DOMStringLiteral_length(marpaXml_DOMStringLiteral_t marpaXml_DOMStringLiteral);

#ifdef __cplusplus 
}
#endif

#endif /* MARPAXML_INTERNAL_DOMSTRINGLITERALS_HPP */
