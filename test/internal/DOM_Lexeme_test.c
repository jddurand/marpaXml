#include <stdio.h>
#include <stdlib.h>
#include "internal/DOM_Lexeme.h"
#include "API/marpaXml/DOM2.h"

#define MYSTRING (char *) "myString"

/********/
/* main */
/********/
int main(int argc, char **argv) {
  marpaXml_Lexeme_t *lexemep;
  marpaXml_String_t *stringp;
  marpaXmlLog_t     *marpaXmlLogp = marpaXmlLog_newp(NULL, NULL, MARPAXML_LOGLEVEL_TRACE);
#ifdef _WIN32
#define MARPAXML_DB_PATH "C:\\Windows\\Temp\\test.sqlite"
#else
#define MARPAXML_DB_PATH "/tmp/test.sqlite"
#endif
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_DB_PATH, NULL, -1, marpaXmlLogp};
  sqlite3_int64         idl;

  /*************************************/
  /*                Init               */
  /*************************************/
  remove((const char *) MARPAXML_DB_PATH);
  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_init() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  stringp = marpaXml_String_newFromUTF8(MYSTRING, NULL);

  lexemep = marpaXml_Lexeme_new();
  if (lexemep == NULL) {
    fprintf(stderr, "marpaXml_Lexeme_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  if (marpaXml_Lexeme_insertFromString(lexemep, stringp, &idl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_insertFromString failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  marpaXml_String_free(&stringp);

  if (marpaXml_Lexeme_getString(lexemep, idl, &stringp) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_getString failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  marpaXml_String_free(&stringp);

  if (marpaXml_Lexeme_delete(lexemep, idl, &idl) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_delete failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  marpaXml_Lexeme_free(&lexemep);

  /*************************************/
  /*                End                */
  /*************************************/
  if (marpaXml_DOM_release() == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_release() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  return 0;
}
