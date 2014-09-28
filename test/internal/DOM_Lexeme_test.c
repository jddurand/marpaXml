#include <stdio.h>
#include <stdlib.h>
#include "internal/DOM_Lexeme.h"
#include "API/marpaXml/DOM2.h"

#define MYSTRING (char *) "myString"

/********/
/* main */
/********/
int main(int argc, char **argv) {
  marpaXml_Lexeme_t *lexeme1p, *lexeme2p, *lexeme3p;
  marpaXml_String_t *string1p;
  sqlite3_int64      counter;
#ifdef _WIN32
#define MARPAXML_DB_PATH "C:\\Windows\\Temp\\test.sqlite"
#else
#define MARPAXML_DB_PATH "/tmp/test.sqlite"
#endif
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_DB_PATH, NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_TRACE } };

  /*************************************/
  /*                Init               */
  /*************************************/
  remove((const char *) MARPAXML_DB_PATH);
  if (marpaXml_DOM_init(&marpaXml_DOM_Option) == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_init() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  string1p = marpaXml_String_newFromUTF8(MYSTRING, NULL);  /* Null byte volontarily ommited */

  lexeme1p = marpaXml_Lexeme_new(string1p);
  if (lexeme1p == NULL) {
    fprintf(stderr, "marpaXml_Lexeme_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  lexeme2p = marpaXml_Lexeme_new(string1p);
  if (lexeme1p == NULL) {
    fprintf(stderr, "marpaXml_Lexeme_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  if (marpaXml_Lexeme_getCounter(lexeme2p, &counter) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (counter != 2) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter give counter %lld failure at %s:%d\n", (long long int) counter, __FILE__, __LINE__);
    return 1;
  }

  lexeme3p = marpaXml_Lexeme_new(string1p);
  if (lexeme3p == NULL) {
    fprintf(stderr, "marpaXml_Lexeme_new failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  marpaXml_Lexeme_free(&lexeme1p);

  if (marpaXml_Lexeme_getCounter(lexeme2p, &counter) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (counter != 3) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter give counter %lld failure at %s:%d\n", (long long int) counter, __FILE__, __LINE__);
    return 1;
  }

  marpaXml_Lexeme_delete(&lexeme2p);

  if (marpaXml_Lexeme_getCounter(lexeme3p, &counter) == marpaXml_false) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }
  if (counter != 2) {
    fprintf(stderr, "marpaXml_Lexeme_getCounter give counter %lld failure at %s:%d\n", (long long int) counter, __FILE__, __LINE__);
    return 1;
  }

  marpaXml_Lexeme_delete(&lexeme3p);

  /*************************************/
  /*                End                */
  /*************************************/
  if (marpaXml_DOM_release() == marpaXml_false) {
    fprintf(stderr, "marpaXml_DOM_release() failure at %s:%d\n", __FILE__, __LINE__);
    return 1;
  }

  return 0;
}
