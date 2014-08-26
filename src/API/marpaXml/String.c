#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "marpaXml/String.h"

struct marpaXml_String_Context {
  char              *utf8;                /* Internal representation: null terminated UTF-8 */
  size_t             utf8ByteLength;      /* Internal representation: byte length, including eventual forced null byte */
  size_t             length;              /* Number of characters (minus null byte) */
  marpaXml_boolean_t nullByteAddedb;      /* When the input clearly did not have a null byte at the end */
  marpaXmlLog_t     *_marpaXmlLogp;
  size_t             _origUtf8ByteLength; /* Internal representation: original UTF-8 byte length */
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
marpaXml_String *marpaXml_String_new(marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset("", 1, "UTF-8", optionp);

}

/*********************************************/
/* marpaXml_String_newFromUTF8               */
/*********************************************/
marpaXml_String *marpaXml_String_newFromUTF8(char *utf8, marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, strlen(utf8)+1, "UTF-8", optionp);

}

/*********************************************/
/* marpaXml_String_newFromUTF8AndByteLength  */
/*********************************************/
marpaXml_String *marpaXml_String_newFromUTF8AndByteLength(char *utf8, size_t byteLength, marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, byteLength, "UTF-8", optionp);

}

/******************************************************/
/* marpaXml_String_newFromAnyAndByteLengthAndCharset  */
/******************************************************/
marpaXml_String *marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t *optionp) {
  marpaXml_String        *thisp;
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

  if (optionp != NULL) {
    marpaXmlLogp = marpaXmlLog_newp(optionp->logOption.logCallbackp, optionp->logOption.logCallbackDatavp, optionp->logOption.logLevelWantedi);
  }

  if (bytes == NULL || byteLength <= 0) {
    return NULL;
  }

  if ((thisp = malloc(sizeof(marpaXml_String))) == NULL                          ||
      (thisp->_contextp = malloc(sizeof(struct marpaXml_String_Context))) == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_String_free(&thisp);
    return NULL;
  }

  thisp->_contextp->utf8 = NULL;
  thisp->_contextp->utf8ByteLength = 0;
  thisp->_contextp->length = 0;
  thisp->_contextp->nullByteAddedb = marpaXml_false;
  thisp->_contextp->_marpaXmlLogp = marpaXmlLogp;
  thisp->_contextp->_origUtf8ByteLength = 0;

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
  if (optionp != NULL) {
    streamInOption.logLevelWantedi = optionp->logOption.logLevelWantedi;
    streamInOption.logCallbackp = optionp->logOption.logCallbackp;
    streamInOption.logCallbackDatavp = optionp->logOption.logCallbackDatavp;
  }

  streamInOptionUtf8.fromEncodings = charset;
  streamInOptionUtf8.toEncodings = "UTF-8";
  if (optionp != NULL) {
    if (_marpaXml_String_CallbackOptionValue(optionp->marpaXml_String_Option_ICU, &streamInOptionUtf8.ICUFromCallback) == marpaXml_false) {
      marpaXml_String_free(&thisp);
      return NULL;
    }
    streamInOptionUtf8.ICUFromFallback = (optionp->fallback == marpaXml_true) ? STREAMIN_BOOL_TRUE : STREAMIN_BOOL_FALSE;
  }

  if ((streamInp = streamInUtf8_newp(&streamInOption, &streamInOptionUtf8)) == NULL) {
    marpaXml_String_free(&thisp);
    return NULL;
  }

  firstCallToNextBufferb = marpaXml_true;
  while (streamInUnicode_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer, &lengthInBuffer) == STREAMIN_BOOL_TRUE) {
    if (firstCallToNextBufferb == marpaXml_true) {
      /* First call: the array allocated by streamIn is ok for us, just take the pointer value */
      thisp->_contextp->utf8 = byteArrayp;
      thisp->_contextp->utf8ByteLength = bytesInBuffer;
      thisp->_contextp->length = lengthInBuffer;
      thisp->_contextp->_origUtf8ByteLength = bytesInBuffer;
      firstCallToNextBufferb = marpaXml_false;
    } else {
      /* Argh, bad luck */
      tmpUtf8       = thisp->_contextp->utf8;
      tmpByteLength = thisp->_contextp->_origUtf8ByteLength + bytesInBuffer;
      tmpLength     = thisp->_contextp->length + lengthInBuffer;

      if (tmpByteLength < thisp->_contextp->_origUtf8ByteLength || tmpLength < thisp->_contextp->length) {
        /* bits turnaround */
        MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&thisp);
        return NULL;
      }

      if ((tmpUtf8 = realloc(thisp->_contextp->utf8, tmpByteLength)) == NULL) {
        MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&thisp);
        return NULL;
      }

      memcpy(tmpUtf8 + thisp->_contextp->_origUtf8ByteLength, byteArrayp, bytesInBuffer);
      thisp->_contextp->utf8 = tmpUtf8;
      thisp->_contextp->utf8ByteLength = tmpByteLength;
      thisp->_contextp->length = tmpLength;
      thisp->_contextp->_origUtf8ByteLength = tmpByteLength;
    }
    if (streamInUnicode_doneBufferb(streamInp, indexBufferi) == STREAMIN_BOOL_FALSE) {
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
    }
  }

  if (firstCallToNextBufferb == marpaXml_true) {
    /* StreamIn returned KO at the very first call !? */
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
  }

  if (thisp->_contextp->utf8[thisp->_contextp->_origUtf8ByteLength - 1] != '\0') {
    /* Either input did not have the null byte in its byteLength count, either the conversion did not */
    /* introduce such null byte. We unfortunately have to do it ourself */
    tmpUtf8       = thisp->_contextp->utf8;
    tmpByteLength = thisp->_contextp->_origUtf8ByteLength + 1;

    if (tmpByteLength < thisp->_contextp->_origUtf8ByteLength) {
      /* bits turnaround */
      MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
    }

    if ((tmpUtf8 = realloc(thisp->_contextp->utf8, tmpByteLength)) == NULL) {
      MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
    }

    tmpUtf8[byteLength] = '\0';
    thisp->_contextp->utf8 = tmpUtf8;
    thisp->_contextp->utf8ByteLength = tmpByteLength;
    thisp->_contextp->nullByteAddedb = marpaXml_true;
  }

  streamIn_destroyv(&streamInp);

  return thisp;
}

/*********************************************/
/* marpaXml_String_getUtf8                   */
/*********************************************/
char *marpaXml_String_getUtf8(marpaXml_String *thisp) {
  if (thisp == NULL) {
    return NULL;
  }

  return thisp->_contextp->utf8;
}

/*********************************************/
/* marpaXml_String_getUtf8ByteLength         */
/*********************************************/
size_t marpaXml_String_getUtf8ByteLength(marpaXml_String *thisp) {
  if (thisp == NULL) {
    return 0;
  }

  return thisp->_contextp->utf8ByteLength;
}

/*********************************************/
/* marpaXml_String_getLength                 */
/*********************************************/
size_t marpaXml_String_getLength(marpaXml_String *thisp) {
  if (thisp == NULL) {
    return 0;
  }

  return thisp->_contextp->length;
}

/*********************************************/
/* marpaXml_String_getNullByteAddedb         */
/*********************************************/
marpaXml_boolean_t marpaXml_String_getNullByteAddedb(marpaXml_String *thisp) {
  if (thisp == NULL) {
    return 0;
  }

  return thisp->_contextp->nullByteAddedb;
}

/*********************************************/
/* marpaXml_String_free                      */
/*********************************************/
void marpaXml_String_free(marpaXml_String **thispp) {
  marpaXml_String *thisp;

  if (thispp != NULL) {
    thisp = *thispp;
    if (thisp != NULL) {
      if (thisp->_contextp != NULL) {
        if (thisp->_contextp->utf8 != NULL) {
          free(thisp->_contextp->utf8);
        }
        marpaXmlLog_freev(&(thisp->_contextp->_marpaXmlLogp));
        free(thisp->_contextp);
      }
      free(thisp);
    }
    *thispp = NULL;
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
char *marpaXml_String_encode(marpaXml_String *thisp, size_t *byteLengthp, size_t *lengthp, char *charset, marpaXml_String_Option_t *optionp) {
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

  if (thisp == NULL) {
    return NULL;
  }

  marpaXmlLogp = thisp->_contextp->_marpaXmlLogp;

  /* These calls never fail if you provide a non-NULL pointer -; */
  streamIn_optionDefaultb(&streamInOption);
  streamInUtf8_optionDefaultb(&streamInOptionUtf8);

  marpaXml_streamInData.buffer     = thisp->_contextp->utf8;
  marpaXml_streamInData.byteLength = thisp->_contextp->_origUtf8ByteLength;
  marpaXml_streamInData.firstb     = STREAMIN_BOOL_TRUE;

  streamInOption.bufMaxSizei                 = thisp->_contextp->_origUtf8ByteLength;
  streamInOption.allBuffersAreManagedByUserb = STREAMIN_BOOL_TRUE;
  streamInOption.readCallbackp               = &_marpaXml_String_readBufferCallback;
  streamInOption.readCallbackDatavp          = &marpaXml_streamInData;
  if (optionp != NULL) {
    streamInOption.logLevelWantedi = optionp->logOption.logLevelWantedi;
    streamInOption.logCallbackp = optionp->logOption.logCallbackp;
    streamInOption.logCallbackDatavp = optionp->logOption.logCallbackDatavp;
  }

  streamInOptionUtf8.fromEncodings = "UTF-8";
  streamInOptionUtf8.toEncodings = charset;
  if (optionp != NULL) {
    if (_marpaXml_String_CallbackOptionValue(optionp->marpaXml_String_Option_ICU, &streamInOptionUtf8.ICUToCallback) == marpaXml_false) {
      marpaXml_String_free(&thisp);
      return NULL;
    }
    streamInOptionUtf8.ICUToFallback = (optionp->fallback == marpaXml_true) ? STREAMIN_BOOL_TRUE : STREAMIN_BOOL_FALSE;
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
