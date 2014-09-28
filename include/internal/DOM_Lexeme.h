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
marpaXml_Lexeme_t  *marpaXml_Lexeme_new(marpaXml_String_t *stringp);
marpaXml_boolean_t  marpaXml_Lexeme_getId(marpaXml_Lexeme_t *thisp, sqlite3_int64 *idlp);
marpaXml_boolean_t  marpaXml_Lexeme_getString(marpaXml_Lexeme_t *thisp, marpaXml_String_t **stringpp);
marpaXml_boolean_t  marpaXml_Lexeme_getCounter(marpaXml_Lexeme_t *thisp, sqlite3_int64 *counterp);
marpaXml_boolean_t  marpaXml_Lexeme_delete(marpaXml_Lexeme_t **thispp);
marpaXml_boolean_t  marpaXml_Lexeme_free(marpaXml_Lexeme_t **thispp);

#endif /* MARPAXML_DOM_LEXEME_H_ */
