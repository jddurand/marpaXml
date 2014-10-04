#include <stdlib.h>

#include "internal/config.h"

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#include "internal/grammar/xml_common.h"
#include "marpaXml/String.h"
#include "internal/DOM_Lexeme.h"

/*****************************/
/* xml_common_optionDefaultb */
/*****************************/
marpaWrapperBool_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp) {

  if (xml_common_optionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  xml_common_optionp->xml_common_topi = XML_COMMON_TOP_DOCUMENT;
  xml_common_optionp->encodings       = NULL;

  return MARPAWRAPPER_BOOL_TRUE;
}

/********************************************************************/
/* xml_common_lexemeValueb                                          */
/* DOM layer is supposed to have been already correctly initialized */
/********************************************************************/
marpaWrapperBool_t xml_common_lexemeValueb(marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, int *lexemeValueip, int *lexemeLengthip) {
  char                  *dests;
  size_t                 byteLengthl;
  marpaXml_String_t     *stringp;
  marpaXml_Lexeme_t     *lexemep;
  sqlite3_int64          id;
  size_t                 lengthl;
  marpaXmlLog_t         *marpaXmlLogp = marpaWrapper_marpaXmlLogp(marpaWrapperp);

  /* Our caller must have guaranteed that:
     - marker in streamInp is at where the lexeme is starting
     - current position in streamInp is where the lexeme is ending
     - lengthl, if > 0, is the correct number of characters within this range
  */
  if (streamInUtf8_extractFromMarkedb(streamInp, &dests, &byteLengthl, &lengthl) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* We use SQLite to store strings. Internal storage is optimized so that equivalent strings are not stored twice, via an internal relational table */
  stringp = marpaXml_String_newFromUTF8(dests, NULL);
  if (stringp == NULL) {
    free(dests);
    return MARPAWRAPPER_BOOL_FALSE;
  }
  free(dests);

  lexemep = marpaXml_Lexeme_new(stringp);
  if (lexemep == NULL) {
    marpaXml_String_free(&stringp);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaXml_Lexeme_getId(lexemep, &id) == marpaXml_false) {
    marpaXml_Lexeme_free(&lexemep);
    marpaXml_String_free(&stringp);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if ((id < INT_MIN) || (id > INT_MAX) || (id == 0)) {
    /* Marpa is using an int, and disregard strongly value 0 (which means 'undef' to him) */
    MARPAXML_ERRORX("index would exceed the 'int' representation at %s:%d", __FILE__, __LINE__);
    marpaXml_Lexeme_free(&lexemep);
    marpaXml_String_free(&stringp);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  *lexemeValueip = (int) id;
  /* We use the character-per-earleme model */
  *lexemeLengthip = (int) lengthl;

  marpaXml_Lexeme_free(&lexemep);
  marpaXml_String_free(&stringp);

  return MARPAWRAPPER_BOOL_TRUE;
}

/********************************************************************/
/* xml_common_readerb                                               */
/********************************************************************/
marpaWrapperBool_t xml_common_readerb(marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, signed int *currentip, marpaWrapperBool_t *endOfInputbp) {
  if (streamInUtf8_nexti(streamInp, currentip) == STREAMIN_BOOL_FALSE) {
    *endOfInputbp = (streamInUtf8_eofb(streamInp) == STREAMIN_BOOL_TRUE) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

