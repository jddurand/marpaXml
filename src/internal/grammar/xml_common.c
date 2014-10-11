#include <stdlib.h>

#include "internal/config.h"

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#include "internal/grammar/xml_common.h"
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
marpaWrapperBool_t xml_common_lexemeValueb(xml_common_work_t *xml_common_workp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, int *lexemeValueip, int *lexemeLengthip) {
  size_t                 byteLengthl;
  marpaXml_Lexeme_t     *lexemep = xml_common_workp->lexemep;
  sqlite3_int64          id;
  marpaXmlLog_t         *marpaXmlLogp = marpaWrapper_marpaXmlLogp(marpaWrapperp);
  const void            *p;

  /* Our caller must have guaranteed that:
     - marker in streamInp is at where the lexeme is starting
     - current position in streamInp is where the lexeme is ending
     - lengthl, if > 0, is the correct number of characters within this range
  */
  if (streamInUtf8_Utf16InfoFromMarkedb(streamInp, &p, &byteLengthl, NULL) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaXml_Lexeme_insertFromUTF16(lexemep, (void *) p, byteLengthl, &id) == marpaXml_false) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if ((id < INT_MIN) || (id > INT_MAX) || (id == 0)) {
    /* Marpa is using an int, and disregard strongly value 0 (which means 'undef' to him) */
    MARPAXML_ERRORX("index %lld would exceed the 'int' representation at %s:%d", id, __FILE__, __LINE__);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  *lexemeValueip = (int) id;
  /* We use the character-per-earleme model */
  /* *lexemeLengthip = (int) lengthl; */
  /* We use the token-per-earleme model */
  *lexemeLengthip = 1;

  /* We use the LATM mode. This mean there cannot be a token with lower length. */
  /* I.e. we have the right to count line number and column number, and keep the last UTF8 characters */

  return MARPAWRAPPER_BOOL_TRUE;
}

/********************************************************************/
/* xml_common_readerb                                               */
/********************************************************************/
marpaWrapperBool_t xml_common_readerb(xml_common_work_t *xml_common_workp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, signed int *currentip, marpaWrapperBool_t *endOfInputbp) {
  if (streamInUtf8_nexti(streamInp, currentip) == STREAMIN_BOOL_FALSE) {
    *endOfInputbp = (streamInUtf8_eofb(streamInp) == STREAMIN_BOOL_TRUE) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

