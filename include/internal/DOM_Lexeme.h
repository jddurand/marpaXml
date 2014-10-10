#ifndef MARPAXML_DOM_LEXEME_H
#define MARPAXML_DOM_LEXEME_H

/*
 * DOM external functions for lexeme storage are putted here because they are not supposed
 * to be visible in the DOM API.
 * This is also why we are allowed to include sqlite3.h.
 */
#include "marpaXml/boolean.h"
#include "marpaXml/String.h"
#include "sqlite3.h"

/***********************************/
/* Internal storage during parsing */
/***********************************/
typedef struct marpaXml_Lexeme marpaXml_Lexeme_t;
marpaXml_Lexeme_t  *marpaXml_Lexeme_new(void);
marpaXml_boolean_t  marpaXml_Lexeme_insertFromUTF16(marpaXml_Lexeme_t *thisp, void *txt16, size_t byteLengthl, sqlite3_int64 *idlp);
marpaXml_boolean_t  marpaXml_Lexeme_insertFromUTF8(marpaXml_Lexeme_t *thisp, char *txt, size_t byteLengthl, sqlite3_int64 *idlp);
marpaXml_boolean_t  marpaXml_Lexeme_insertFromString(marpaXml_Lexeme_t *thisp, marpaXml_String_t *stringp, sqlite3_int64 *idlp);
marpaXml_boolean_t  marpaXml_Lexeme_getString(marpaXml_Lexeme_t *thisp, sqlite3_int64 idl, marpaXml_String_t **stringpp);
marpaXml_boolean_t  marpaXml_Lexeme_delete(marpaXml_Lexeme_t *thisp, sqlite3_int64 idl, sqlite3_int64 *idlp);
marpaXml_boolean_t  marpaXml_Lexeme_free(marpaXml_Lexeme_t **thispp);

#endif /* MARPAXML_DOM_LEXEME_H_ */
