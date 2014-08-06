#include <unicode/unistr.h>
#include "internal/DOMStringLiterals.hpp"

UnicodeString DOMStringLiteral[_MARPAXML_DOM_STRINGLITERAL_MAX] = 
  {
    UNICODE_STRING_SIMPLE("1.0"),
    UNICODE_STRING_SIMPLE("2.0"),
    UNICODE_STRING_SIMPLE("3.0"),
    UNICODE_STRING_SIMPLE("Core"),
    UNICODE_STRING_SIMPLE("XML"),
  };

const unsigned short *marpaXml_DOMStringLiteral_buffer(marpaXml_DOMStringLiteral_t marpaXml_DOMStringLiteral) {
  /* It CAN happen that UChar is not unsigned short. ICU just guarantees that UChar can store what
     an unsigned short stores. But sometimes the type can be char16_t, wchar_t, etc... So we
     typecase explicitely, because it know that the storage size of UChar is the one of unsigned short */
  return (unsigned short *) DOMStringLiteral[marpaXml_DOMStringLiteral].getBuffer();
}

int32_t marpaXml_DOMStringLiteral_length(marpaXml_DOMStringLiteral_t marpaXml_DOMStringLiteral) {
  return DOMStringLiteral[marpaXml_DOMStringLiteral].length();
}
