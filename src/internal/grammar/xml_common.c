#include <stdlib.h>

#include "internal/config.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#include "internal/grammar/xml_common.h"
#include "internal/DOM_Lexeme.h"
#include "internal/manageBuf.h"

typedef struct xml_common_UTF16Info {
  const void *p;
  size_t      byteLengthl;
} xml_common_UTF16Info_t;

struct xml_common {
  xml_common_option_t xml_common_option;
  unsigned long long  linel;
  unsigned long long  columnl;
  unsigned long long  deltaLinel;
  unsigned long long  deltaColumnl;
  marpaXml_Lexeme_t  *lexemep;

  size_t                   sizeUTF16Infoi;           /* Allocated size */
  size_t                   nUTF16Infoi;              /* Used size      */
  xml_common_UTF16Info_t **UTF16Infopp;

};

/*****************************/
/* xml_common_optionDefaultb */
/*****************************/
marpaXml_boolean_t xml_common_optionDefaultb(xml_common_option_t *xml_common_optionp) {

  if (xml_common_optionp == NULL) {
    return marpaXml_false;
  }

  xml_common_optionp->xml_common_topi = XML_COMMON_TOP_DOCUMENT;
  xml_common_optionp->encodings       = NULL;
  xml_common_optionp->marpaXmlLogp    = NULL;

  return marpaXml_true;
}

/********************************************************************/
/* xml_common_lexemeValueb                                          */
/* DOM layer is supposed to have been already correctly initialized */
/********************************************************************/
marpaXml_boolean_t xml_common_lexemeValueb(xml_common_t *xml_commonp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, int *lexemeValueip, int *lexemeLengthip) {
  size_t                  byteLengthl;
  marpaXml_Lexeme_t      *lexemep = xml_commonp->lexemep;
  sqlite3_int64           id;
  marpaXmlLog_t          *marpaXmlLogp = xml_commonp->xml_common_option.marpaXmlLogp;
  const void             *p;
  xml_common_UTF16Info_t *xml_common_UTF16Infop;

  /* Our caller must have guaranteed that:
     - marker in streamInp is at where the lexeme is starting
     - current position in streamInp is where the lexeme is ending
     - lengthl, if > 0, is the correct number of characters within this range
  */
  if (streamInUtf8_Utf16InfoFromMarkedb(streamInp, &p, &byteLengthl, NULL) == STREAMIN_BOOL_FALSE) {
    return marpaXml_false;
  }

  if ((xml_commonp->nUTF16Infoi + 1) > INT_MAX) {
    /* Marpa is using an int, and disregard strongly value 0 (which means 'undef' to him) */
    MARPAXML_ERRORX("index %lld would exceed the 'int' representation at %s:%d", (long long) (xml_commonp->nUTF16Infoi + 1), __FILE__, __LINE__);
    return marpaXml_false;
  }

  /* Allocate room for the new UTF16 info */
  if (manageBuf_createp((void ***) &(xml_commonp->UTF16Infopp),
			&(xml_commonp->sizeUTF16Infoi),
			xml_commonp->nUTF16Infoi + 1,
			sizeof(xml_common_UTF16Info_t *)) == NULL) {
    MARPAXML_ERRORX("manageBuf_createp(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return marpaXml_false;
  }

  xml_common_UTF16Infop = malloc(sizeof(xml_common_UTF16Info_t));
  if (xml_common_UTF16Infop == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return marpaXml_false;
  }
  xml_common_UTF16Infop->p                             = p;
  xml_common_UTF16Infop->byteLengthl                   = byteLengthl;
  xml_commonp->UTF16Infopp[xml_commonp->nUTF16Infoi++] = xml_common_UTF16Infop;

  /* Marpa is using an int, and disregard strongly value 0 (which means 'undef' to him) */
  /* JDD START */
  if (marpaXml_Lexeme_insertFromUTF16(lexemep, (void *) p, byteLengthl, &id) == marpaXml_false) {
    return marpaXml_false;
  }

  if ((id < INT_MIN) || (id > INT_MAX) || (id == 0)) {
    MARPAXML_ERRORX("index %lld would exceed the 'int' representation at %s:%d", id, __FILE__, __LINE__);
    return marpaXml_false;
  }

  *lexemeValueip = (int) id;
  /* JDD END */

  MARPAXML_TRACEX("Storing lexeme value at index %d", (int) xml_commonp->nUTF16Infoi);
  *lexemeValueip = (int) xml_commonp->nUTF16Infoi;
  /* We use the character-per-earleme model */
  /* *lexemeLengthip = (int) lengthl; */
  /* We use the token-per-earleme model */
  *lexemeLengthip = 1;

  /* We use the LATM mode. This mean there cannot be a token with lower length. */
  /* I.e. we have the right to count line number and column number, and keep the last UTF8 characters */

  return marpaXml_true;
}

/********************************************************************/
/* xml_common_readerb                                               */
/********************************************************************/
marpaXml_boolean_t xml_common_readerb(xml_common_t *xml_commonp, marpaWrapper_t *marpaWrapperp, streamIn_t *streamInp, signed int *currentip, marpaWrapperBool_t *endOfInputbp) {
  if (streamInUtf8_nexti(streamInp, currentip) == STREAMIN_BOOL_FALSE) {
    *endOfInputbp = (streamInUtf8_eofb(streamInp) == STREAMIN_BOOL_TRUE) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
    return marpaXml_false;
  }

  return marpaXml_true;
}

/********************************************************************/
/* xml_common_newp                                                  */
/********************************************************************/
xml_common_t *xml_common_new(xml_common_option_t *xml_common_optionp) {
  marpaXmlLog_t      *marpaXmlLogp = NULL;
  xml_common_t       *xml_commonp;
  xml_common_option_t xml_common_option;
  marpaXml_Lexeme_t  *lexemep;

  if (xml_common_optionp == NULL) {
    if (xml_common_optionDefaultb(&xml_common_option) == marpaXml_false) {
      return NULL;
    }
    xml_common_optionp = &xml_common_option;
  }
  marpaXmlLogp = xml_common_optionp->marpaXmlLogp;

  lexemep = marpaXml_Lexeme_new();
  if (lexemep == NULL) {
    return NULL;
  }

  xml_commonp = malloc(sizeof(xml_common_t));
  if (xml_commonp == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_Lexeme_free(&lexemep);
    return NULL;
  }

  xml_commonp->xml_common_option = *xml_common_optionp;
  xml_commonp->linel             = 0;
  xml_commonp->columnl           = 0;
  xml_commonp->deltaLinel        = 0;
  xml_commonp->deltaColumnl      = 0;
  xml_commonp->lexemep           = lexemep;
  xml_commonp->sizeUTF16Infoi    = 0;
  xml_commonp->nUTF16Infoi       = 0;
  xml_commonp->UTF16Infopp       = NULL;

  return xml_commonp;
}

/********************************************************************/
/* xml_common_free                                                  */
/********************************************************************/
void xml_common_free(xml_common_t **xml_commonpp) {
  xml_common_t *xml_commonp;

  if (xml_commonpp != NULL) {
    xml_commonp = *xml_commonpp;
    if (xml_commonp != NULL) {
      if (xml_commonp->lexemep != NULL) {
	marpaXml_Lexeme_free(&(xml_commonp->lexemep));
      }
      manageBuf_freev((void ***) &(xml_commonp->UTF16Infopp), &(xml_commonp->sizeUTF16Infoi), &(xml_commonp->nUTF16Infoi));
      free(xml_commonp);
    }
    *xml_commonpp = NULL;
  }
}

