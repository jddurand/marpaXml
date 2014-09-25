#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "internal/config.h"
#include "internal/streamIn.h"
#include "marpaXml/String.h"

struct marpaXml_String {
  char              *utf8;                /* Internal representation: null terminated UTF-8 */
  size_t             utf8ByteLength;      /* Internal representation: byte length, including eventual forced null byte */
  size_t             length;              /* Number of characters (minus null byte) */
  marpaXml_boolean_t nullByteAddedb;      /* When the input clearly did not have a null byte at the end */
  marpaXmlLog_t     *marpaXmlLogp;
  size_t             origUtf8ByteLength; /* Internal representation: original UTF-8 byte length */
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
marpaXml_String_t *marpaXml_String_new(marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset((char *) "", 1, (char *) "UTF-8", optionp);

}

/*********************************************/
/* marpaXml_String_newFromUTF8               */
/*********************************************/
marpaXml_String_t *marpaXml_String_newFromUTF8(char *utf8, marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, strlen(utf8)+1, (char *) "UTF-8", optionp);

}

/*********************************************/
/* marpaXml_String_newFromUTF8AndByteLength  */
/*********************************************/
marpaXml_String_t *marpaXml_String_newFromUTF8AndByteLength(char *utf8, size_t byteLength, marpaXml_String_Option_t *optionp) {

  return marpaXml_String_newFromAnyAndByteLengthAndCharset(utf8, byteLength, (char *) "UTF-8", optionp);

}

/******************************************************/
/* marpaXml_String_newFromAnyAndByteLengthAndCharset  */
/******************************************************/
marpaXml_String_t *marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t *optionp) {
  marpaXml_String_t      *thisp;
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
    if (marpaXmlLogp == NULL) {
      return NULL;
    }
  }

  if (bytes == NULL || byteLength <= 0) {
    return NULL;
  }

  if ((thisp = malloc(sizeof(marpaXml_String_t))) == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_String_free(&thisp);
    return NULL;
  }

  thisp->utf8 = NULL;
  thisp->utf8ByteLength = 0;
  thisp->length = 0;
  thisp->nullByteAddedb = marpaXml_false;
  thisp->marpaXmlLogp = marpaXmlLogp;
  thisp->origUtf8ByteLength = 0;

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
  streamInOptionUtf8.toEncodings = (char *) "UTF-8";
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
      thisp->utf8 = byteArrayp;
      thisp->utf8ByteLength = bytesInBuffer;
      thisp->length = lengthInBuffer;
      thisp->origUtf8ByteLength = bytesInBuffer;
      firstCallToNextBufferb = marpaXml_false;
    } else {
      /* Argh, bad luck */
      tmpUtf8       = thisp->utf8;
      tmpByteLength = thisp->origUtf8ByteLength + bytesInBuffer;
      tmpLength     = thisp->length + lengthInBuffer;

      if (tmpByteLength < thisp->origUtf8ByteLength || tmpLength < thisp->length) {
        /* bits turnaround */
        MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&thisp);
        return NULL;
      }

      if ((tmpUtf8 = realloc(thisp->utf8, tmpByteLength)) == NULL) {
        MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        streamIn_destroyv(&streamInp);
        marpaXml_String_free(&thisp);
        return NULL;
      }

      memcpy(tmpUtf8 + thisp->origUtf8ByteLength, byteArrayp, bytesInBuffer);
      thisp->utf8 = tmpUtf8;
      thisp->utf8ByteLength = tmpByteLength;
      thisp->length = tmpLength;
      thisp->origUtf8ByteLength = tmpByteLength;
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

  if (thisp->utf8[thisp->origUtf8ByteLength - 1] != '\0') {
    /* Either input did not have the null byte in its byteLength count, either the conversion did not */
    /* introduce such null byte. We unfortunately have to do it ourself */
    tmpUtf8       = thisp->utf8;
    tmpByteLength = thisp->origUtf8ByteLength + 1;

    if (tmpByteLength < thisp->origUtf8ByteLength) {
      /* bits turnaround */
      MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
    }

    if ((tmpUtf8 = realloc(thisp->utf8, tmpByteLength)) == NULL) {
      MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      streamIn_destroyv(&streamInp);
      marpaXml_String_free(&thisp);
      return NULL;
    }

    tmpUtf8[tmpByteLength - 1] = '\0';
    thisp->utf8 = tmpUtf8;
    thisp->utf8ByteLength = tmpByteLength;
    thisp->nullByteAddedb = marpaXml_true;
  }

  streamIn_destroyv(&streamInp);

  return thisp;
}

/*********************************************/
/* marpaXml_String_clone                     */
/*********************************************/
marpaXml_String_t *marpaXml_String_clone(marpaXml_String_t *stringp) {
  marpaXml_String_t *thisp;
  marpaXmlLog_t     *marpaXmlLogp;

  if (stringp == NULL) {
    return NULL;
  }

  marpaXmlLogp = stringp->marpaXmlLogp;

  if ((thisp = malloc(sizeof(marpaXml_String_t))) == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_String_free(&thisp);
    return NULL;
  }

  thisp->utf8 = NULL;
  thisp->utf8ByteLength = 0;
  thisp->length = 0;
  thisp->nullByteAddedb = marpaXml_false;
  thisp->marpaXmlLogp = marpaXmlLogp;
  thisp->origUtf8ByteLength = 0;

  thisp->marpaXmlLogp = marpaXmlLog_clonep(marpaXmlLogp);
  if ((marpaXmlLogp != NULL) && (thisp->marpaXmlLogp == NULL)) {
    marpaXml_String_free(&thisp);
    return NULL;
  }

  marpaXmlLogp = thisp->marpaXmlLogp;

  if ((thisp->utf8 = malloc(stringp->utf8ByteLength)) == NULL) {
    MARPAXML_ERRORX("malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    marpaXml_String_free(&thisp);
    return NULL;
  }

  memcpy(thisp->utf8, stringp->utf8, stringp->utf8ByteLength);

  thisp->utf8ByteLength     = stringp->utf8ByteLength;
  thisp->length             = stringp->length;
  thisp->nullByteAddedb     = stringp->nullByteAddedb;
  thisp->origUtf8ByteLength = stringp->origUtf8ByteLength;

  return thisp;
}

/*********************************************/
/* marpaXml_String_cat                       */
/*********************************************/
marpaXml_String_t *marpaXml_String_cat(marpaXml_String_t *dstp, marpaXml_String_t *srcp) {
  marpaXmlLog_t *marpaXmlLogp;
  char           *utf8;                /* Internal representation: null terminated UTF-8 */
  size_t          utf8ByteLength;      /* Internal representation: byte length, including eventual forced null byte */

  if (dstp == NULL) {
    return NULL;
  }
  marpaXmlLogp = dstp->marpaXmlLogp;

  if (srcp == NULL) {
    return dstp;
  }

  utf8ByteLength = dstp->utf8ByteLength + srcp->utf8ByteLength - 1; /* Both internal representations are null terminated UTF-8 */
  utf8 = realloc(dstp->utf8, utf8ByteLength);
  if (utf8 == NULL) {
    MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return NULL;
  }

  dstp->utf8                = utf8;
  memcpy(dstp->utf8 + dstp->utf8ByteLength - 1, srcp->utf8, srcp->utf8ByteLength);

  dstp->utf8ByteLength      = utf8ByteLength;
  dstp->length             += srcp->length;
  dstp->nullByteAddedb      = srcp->nullByteAddedb;
  dstp->origUtf8ByteLength += srcp->origUtf8ByteLength;

  return dstp;
}

/*********************************************/
/* marpaXml_String_getUtf8                   */
/*********************************************/
char *marpaXml_String_getUtf8(marpaXml_String_t *thisp) {
  return thisp->utf8;
}

/*********************************************/
/* marpaXml_String_getUtf8ByteLength         */
/*********************************************/
size_t marpaXml_String_getUtf8ByteLength(marpaXml_String_t *thisp) {
  return thisp->utf8ByteLength;
}

/*********************************************/
/* marpaXml_String_getLength                 */
/*********************************************/
size_t marpaXml_String_getLength(marpaXml_String_t *thisp) {
  return thisp->length;
}

/*********************************************/
/* marpaXml_String_getNullByteAddedb         */
/*********************************************/
marpaXml_boolean_t marpaXml_String_getNullByteAddedb(marpaXml_String_t *thisp) {
  return thisp->nullByteAddedb;
}

/*********************************************/
/* marpaXml_String_free                      */
/*********************************************/
void marpaXml_String_free(marpaXml_String_t **thispp) {
  marpaXml_String_t *thisp;

  if (thispp != NULL) {
    thisp = *thispp;
    if (thisp != NULL) {
      if (thisp->utf8 != NULL) {
	free(thisp->utf8);
      }
      marpaXmlLog_freev(&(thisp->marpaXmlLogp));
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
char *marpaXml_String_encode(marpaXml_String_t *thisp, size_t *byteLengthp, size_t *lengthp, char *charset, marpaXml_String_Option_t *optionp) {
  streamIn_t             *streamInp;
  streamInOption_t        streamInOption;
  streamInUtf8Option_t    streamInOptionUtf8;
  marpaXml_streamInData_t marpaXml_streamInData;
  size_t                  indexBufferi;
  char                   *byteArrayp;
  size_t                  bytesInBuffer;
  size_t                  lengthInBuffer;
  marpaXml_boolean_t      firstCallToNextBufferb;
  char                   *tmpMore;
  size_t                  tmpByteLength;
  size_t                  tmpLength;
  char                   *rc = NULL;
  size_t                  byteLength = 0;
  size_t                  length = 0;
  marpaXmlLog_t          *marpaXmlLogp;

  marpaXmlLogp = thisp->marpaXmlLogp;

  /* These calls never fail if you provide a non-NULL pointer -; */
  streamIn_optionDefaultb(&streamInOption);
  streamInUtf8_optionDefaultb(&streamInOptionUtf8);

  marpaXml_streamInData.buffer     = thisp->utf8;
  marpaXml_streamInData.byteLength = thisp->origUtf8ByteLength;
  marpaXml_streamInData.firstb     = STREAMIN_BOOL_TRUE;

  streamInOption.bufMaxSizei                 = thisp->origUtf8ByteLength;
  streamInOption.allBuffersAreManagedByUserb = STREAMIN_BOOL_TRUE;
  streamInOption.readCallbackp               = &_marpaXml_String_readBufferCallback;
  streamInOption.readCallbackDatavp          = &marpaXml_streamInData;
  if (optionp != NULL) {
    streamInOption.logLevelWantedi = optionp->logOption.logLevelWantedi;
    streamInOption.logCallbackp = optionp->logOption.logCallbackp;
    streamInOption.logCallbackDatavp = optionp->logOption.logCallbackDatavp;
  }

  streamInOptionUtf8.fromEncodings = (char *) "UTF-8";
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
      tmpMore        = rc;
      tmpByteLength = byteLength + bytesInBuffer;
      tmpLength     = length + lengthInBuffer;

      if (tmpByteLength < byteLength || tmpLength < length) {
        /* bits turnaround */
        MARPAXML_ERRORX("bits turnaround detected at %s:%d", __FILE__, __LINE__);
        free(rc);
        streamIn_destroyv(&streamInp);
        return NULL;
      }

      if ((tmpMore = realloc(rc, tmpByteLength)) == NULL) {
        MARPAXML_ERRORX("realloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
        free(rc);
        streamIn_destroyv(&streamInp);
        return NULL;
      }

      memcpy(tmpMore + byteLength, byteArrayp, bytesInBuffer);
      rc = tmpMore;
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
