#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "marpaXml/String.h"

struct marpaXml_String_Context {
  char          *utf8;            /* Internal representation: null terminated UTF-8 */
  size_t         byteLength;      /* Internal representation: byte length, including the null byte */
  size_t         length;          /* Internal representation: character length, not including the null character (== null byte) */
  marpaXmlLog_t *marpaXmlLogp;
};

typedef struct marpaXml_streamInData {
  char          *buffer;
  size_t         byteLength;
  streamInBool_t firstb;
} marpaXml_streamInData_t;

static C_INLINE marpaXml_boolean_t _marpaXml_String_CallbackOptionValue(marpaXml_String_Option_ICU_t optionValue, streamInUtf8Option_ICU_t *optionValuep);
static C_INLINE streamInBool_t     _marpaXml_String_readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);

/*********************************************/
/* marpaXml_String_new                       */
/*********************************************/
marpaXml_String_t marpaXml_String_new(marpaXml_String_Option_t option) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset("", 1, "UTF-8", option);

}

/*********************************************/
/* marpaXml_String_newFromUTF8               */
/*********************************************/
marpaXml_String_t marpaXml_String_newFromUTF8(char *utf8, marpaXml_String_Option_t option) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, strlen(utf8)+1, "UTF-8", option);

}

/*********************************************/
/* marpaXml_String_newFromUTF8AndByteLength  */
/*********************************************/
marpaXml_String_t marpaXml_String_newFromUTF8AndByteLength(char *utf8, size_t byteLength, marpaXml_String_Option_t option) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, byteLength, "UTF-8", option);

}

/******************************************************/
/* marpaXml_String_newFromAnyAndByteLengthAndCharset  */
/******************************************************/
marpaXml_String_t marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t option) {
  marpaXml_String_t       this;
  streamIn_t             *streamInp;
  streamInOption_t        streamInOption;
  streamInUtf8Option_t    streamInOptionUtf8;
  marpaXml_streamInData_t marpaXml_streamInData;
  size_t                  indexBufferi;
  char                   *byteArrayp;
  size_t                  bytesInBuffer;
  size_t                  lengthInBuffer;
  marpaXml_boolean_t      firstCallToNextBufferb;
  marpaXmlLog_t          *marpaXmlLogp = NULL;
  char                   *tmpUtf8;
  size_t                  tmpByteLength;
  size_t                  tmpLength;

  if (option != NULL) {
    marpaXmlLogp = marpaXmlLog_newp(option->logCallbackp, option->logCallbackDatavp, option->logLevelWantedi);
  }

  if (bytes == NULL || byteLength <= 0) {
    return NULL;
  }

  if ((this = malloc(sizeof(marpaXml_String))) == NULL                          ||
      (this->_context = malloc(sizeof(struct marpaXml_String_Context))) == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_String_free(&this);
    return NULL;
  }

  this->_context->utf8 = NULL;
  this->_context->byteLength = 0;
  this->_context->length = 0;
  this->_context->marpaXmlLogp = marpaXmlLogp;

  /* These calls never fail if you provide a non-NULL pointer -; */
  streamIn_optionDefaultb(&streamInOption);
  streamInUtf8_optionDefaultb(&streamInOptionUtf8);

  marpaXml_streamInData.buffer     = bytes;
  marpaXml_streamInData.byteLength = byteLength;
  marpaXml_streamInData.firstb     = STREAMIN_BOOL_TRUE;

  streamInOption.bufMaxSizei                 = byteLength;
  streamInOption.allBuffersAreManagedByUserb = STREAMIN_BOOL_TRUE;
  streamInOption.readCallbackp               = &_marpaXml_String_readBufferCallback;
  streamInOption.readCallbackDatavp          = &marpaXml_streamInData;
  if (option != NULL) {
    streamInOption.logLevelWantedi = option->logLevelWantedi;
    streamInOption.logCallbackp = option->logCallbackp;
    streamInOption.logCallbackDatavp = option->logCallbackDatavp;
  }

  streamInOptionUtf8.fromEncodings = charset;
  streamInOptionUtf8.toEncodings = "UTF-8";
  if (option != NULL) {
    if (_marpaXml_String_CallbackOptionValue(option->marpaXml_String_Option_ICU, &streamInOptionUtf8.ICUFromCallback) == marpaXml_false) {
      marpaXml_String_free(&this);
      return NULL;
    }
    streamInOptionUtf8.ICUFromFallback = (option->fallback == marpaXml_true) ? STREAMIN_BOOL_TRUE : STREAMIN_BOOL_FALSE;
  }

  if ((streamInp = streamInUtf8_newp(&streamInOption, &streamInOptionUtf8)) == NULL) {
    marpaXml_String_free(&this);
    return NULL;
  }

  firstCallToNextBufferb = marpaXml_true;
  while (streamInUnicode_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer, &lengthInBuffer) == STREAMIN_BOOL_TRUE) {
    if (firstCallToNextBufferb == marpaXml_true) {
      /* First call: the array allocated by streamIn is ok for us, just take the pointer value */
      this->_context->utf8 = byteArrayp;
      this->_context->byteLength = bytesInBuffer;
      this->_context->length = lengthInBuffer;
      firstCallToNextBufferb = marpaXml_false;
    } else {
      /* Argh, bad luck */
      tmpUtf8       = this->_context->utf8;
      tmpByteLength = this->_context->byteLength + bytesInBuffer;
      tmpLength     = this->_context->length + lengthInBuffer;

      if (tmpByteLength < this->_context->byteLength || tmpLength < this->_context->length) {
        /* bits turnaround */
        MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&this);
        return NULL;
      }

      if ((tmpUtf8 = realloc(this->_context->utf8, tmpByteLength)) == NULL) {
        MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&this);
        return NULL;
      }

      memcpy(tmpUtf8 + this->_context->byteLength, byteArrayp, bytesInBuffer);
      this->_context->utf8 = tmpUtf8;
      this->_context->byteLength = tmpByteLength;
      this->_context->length = tmpLength;
    }
    if (streamInUnicode_doneBufferb(streamInp, indexBufferi) == STREAMIN_BOOL_FALSE) {
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&this);
      return NULL;
    }
  }

  if (firstCallToNextBufferb == marpaXml_true) {
    /* StreamIn returned KO at the very first call !? */
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&this);
      return NULL;
  }

  if (this->_context->utf8[byteLength - 1] != '\0') {
    /* Either input did not have the null byte in its byteLength count, either the conversion did not */
    /* introduce such null byte. We unfortunately have to do it ourself */
    tmpUtf8       = this->_context->utf8;
    tmpByteLength = this->_context->byteLength + 1;

    if (tmpByteLength < this->_context->byteLength) {
      /* bits turnaround */
      MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&this);
      return NULL;
    }

    if ((tmpUtf8 = realloc(this->_context->utf8, tmpByteLength)) == NULL) {
      MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&this);
      return NULL;
    }

    tmpUtf8[byteLength] = '\0';
    this->_context->utf8 = tmpUtf8;
    this->_context->byteLength = tmpByteLength;
  }

  streamIn_destroyv(&streamInp);

  return this;
}

/*********************************************/
/* marpaXml_String_getUtf8                   */
/*********************************************/
char *marpaXml_String_getUtf8(marpaXml_String_t this) {
  if (this == NULL) {
    return NULL;
  }

  return this->_context->utf8;
}

/*********************************************/
/* marpaXml_String_getByteLength             */
/*********************************************/
size_t marpaXml_String_getByteLength(marpaXml_String_t this) {
  if (this == NULL) {
    return 0;
  }

  return this->_context->byteLength;
}

/*********************************************/
/* marpaXml_String_getLength                 */
/*********************************************/
size_t marpaXml_String_getLength(marpaXml_String_t this) {
  if (this == NULL) {
    return 0;
  }

  return this->_context->length;
}

/*********************************************/
/* marpaXml_String_free                      */
/*********************************************/
void marpaXml_String_free(marpaXml_String_t *thisp) {
  marpaXml_String_t this;

  if (thisp != NULL) {
    this = *thisp;
    if (this != NULL) {
      if (this->_context != NULL) {
        if (this->_context->utf8 != NULL) {
          free(this->_context->utf8);
        }
        marpaXmlLog_freev(&(this->_context->marpaXmlLogp));
        free(this->_context);
      }
      free(this);
    }
    *thisp = NULL;
  }
}

/*********************************************/
/* _marpaXml_String_CallbackOptionValue      */
/*********************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_String_CallbackOptionValue(marpaXml_String_Option_ICU_t optionValue, streamInUtf8Option_ICU_t *optionValuep) {
  marpaXml_boolean_t rcb = marpaXml_true;

  switch (optionValue) {
  case MARPAXML_STRING_OPTION_ICU_DEFAULT:
    *optionValuep = STREAMINUTF8OPTION_ICU_DEFAULT;
    break;
  case MARPAXML_STRING_OPTION_ICU_SUBSTITUTE:
    *optionValuep = STREAMINUTF8OPTION_ICU_SUBSTITUTE;
    break;
  case MARPAXML_STRING_OPTION_ICU_SKIP:
    *optionValuep = STREAMINUTF8OPTION_ICU_SKIP;
    break;
  case MARPAXML_STRING_OPTION_ICU_STOP:
    *optionValuep = STREAMINUTF8OPTION_ICU_STOP;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_ICU:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_ICU;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_JAVA:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_JAVA;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_C:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_C;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_XML:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_XML;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_XML_HEX:
    *optionValuep = STREAMINUTF8OPTION_ICU_DEFAULT;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_XML_DEC:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_XML_DEC;
    break;
  case MARPAXML_STRING_OPTION_ICU_ESCAPE_UNICODE:
    *optionValuep = STREAMINUTF8OPTION_ICU_ESCAPE_UNICODE;
    break;
  default:
    rcb = marpaXml_false;
    break;
  }

  return rcb;
}

/*********************************************/
/* _marpaXml_String_readBufferCallback       */
/*********************************************/
static C_INLINE streamInBool_t _marpaXml_String_readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  marpaXml_streamInData_t *marpaXml_streamInDatap = (marpaXml_streamInData_t *) datavp;

  if (marpaXml_streamInDatap->firstb == STREAMIN_BOOL_TRUE) {
    *gotBytesip = marpaXml_streamInDatap->byteLength;
    *charManagedArrayp = marpaXml_streamInDatap->buffer;
    marpaXml_streamInDatap->firstb = STREAMIN_BOOL_FALSE;
  } else {
    *gotBytesip = 0;
  }

  return STREAMIN_BOOL_TRUE;
}

/*********************************************/
/* marpaXml_String_encode                    */
/*********************************************/
char *marpaXml_String_encode(marpaXml_String_t this, size_t *byteLengthp, size_t *lengthp, char *charset, marpaXml_String_Option_t option) {
  streamIn_t             *streamInp;
  streamInOption_t        streamInOption;
  streamInUtf8Option_t    streamInOptionUtf8;
  marpaXml_streamInData_t marpaXml_streamInData;
  size_t                  indexBufferi;
  char                   *byteArrayp;
  size_t                  bytesInBuffer;
  size_t                  lengthInBuffer;
  marpaXml_boolean_t      firstCallToNextBufferb;
  char                   *tmpAny;
  size_t                  tmpByteLength;
  size_t                  tmpLength;
  char                   *rc = NULL;
  size_t                  byteLength = 0;
  size_t                  length = 0;
  marpaXmlLog_t          *marpaXmlLogp;

  if (this == NULL) {
    return NULL;
  }

  marpaXmlLogp = this->_context->marpaXmlLogp;

  /* These calls never fail if you provide a non-NULL pointer -; */
  streamIn_optionDefaultb(&streamInOption);
  streamInUtf8_optionDefaultb(&streamInOptionUtf8);

  marpaXml_streamInData.buffer     = this->_context->utf8;
  marpaXml_streamInData.byteLength = this->_context->byteLength;
  marpaXml_streamInData.firstb     = STREAMIN_BOOL_TRUE;

  streamInOption.bufMaxSizei                 = this->_context->byteLength;
  streamInOption.allBuffersAreManagedByUserb = STREAMIN_BOOL_TRUE;
  streamInOption.readCallbackp               = &_marpaXml_String_readBufferCallback;
  streamInOption.readCallbackDatavp          = &marpaXml_streamInData;
  if (option != NULL) {
    streamInOption.logLevelWantedi = option->logLevelWantedi;
    streamInOption.logCallbackp = option->logCallbackp;
    streamInOption.logCallbackDatavp = option->logCallbackDatavp;
  }

  streamInOptionUtf8.fromEncodings = "UTF-8";
  streamInOptionUtf8.toEncodings = charset;
  if (option != NULL) {
    if (_marpaXml_String_CallbackOptionValue(option->marpaXml_String_Option_ICU, &streamInOptionUtf8.ICUToCallback) == marpaXml_false) {
      marpaXml_String_free(&this);
      return NULL;
    }
    streamInOptionUtf8.ICUToFallback = (option->fallback == marpaXml_true) ? STREAMIN_BOOL_TRUE : STREAMIN_BOOL_FALSE;
  }

  if ((streamInp = streamInUtf8_newp(&streamInOption, &streamInOptionUtf8)) == NULL) {
    return NULL;
  }

  firstCallToNextBufferb = marpaXml_true;
  while (streamInUnicode_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer, &lengthInBuffer) == STREAMIN_BOOL_TRUE) {
    if (firstCallToNextBufferb == marpaXml_true) {
      /* First call: the array allocated by streamIn is ok for us, just take the pointer value */
      rc = byteArrayp;
      byteLength = bytesInBuffer;
      length = lengthInBuffer;
      firstCallToNextBufferb = marpaXml_false;
    } else {
      /* Argh, bad luck */
      tmpAny        = rc;
      tmpByteLength = byteLength + bytesInBuffer;
      tmpLength     = length + lengthInBuffer;

      if (tmpByteLength < byteLength || tmpLength < length) {
        /* bits turnaround */
        MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
        free(rc);
        streamIn_destroyv(&streamInp);
        return NULL;
      }

      if ((tmpAny = realloc(rc, tmpByteLength)) == NULL) {
        MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        free(rc);
        streamIn_destroyv(&streamInp);
        return NULL;
      }

      memcpy(tmpAny + byteLength, byteArrayp, bytesInBuffer);
      rc = tmpAny;
      byteLength = tmpByteLength;
      length = tmpLength;
    }
    if (streamInUnicode_doneBufferb(streamInp, indexBufferi) == STREAMIN_BOOL_FALSE) {
      free(rc);
      streamIn_destroyv(&streamInp);
      return NULL;
    }
  }

  if (firstCallToNextBufferb == marpaXml_true) {
    /* StreamIn returned KO at the very first call !? */
      streamIn_destroyv(&streamInp);
      return NULL;
  }

  streamIn_destroyv(&streamInp);

  if (byteLengthp != NULL) {
    *byteLengthp = byteLength;
  }
  if (lengthp != NULL) {
    *lengthp = length;
  }

  return rc;
}
