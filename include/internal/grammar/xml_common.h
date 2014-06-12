#ifndef MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H
#define MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H

#include <stddef.h>

typedef enum xml_commonLexemeState {
  XML_COMMON_LEXEME_STATE_PENDING = -1,
  XML_COMMON_LEXEME_STATE_FALSE   = 0,
  XML_COMMON_LEXEME_STATE_COMPLETE = 1
} xml_commonLexemeState_t;

typedef struct xml_commonOption {
  char      *encodings;
} xml_commonOption_t;

#endif /* MARPAXML_INTERNAL_GRAMMAR_XML_COMMON_H */

