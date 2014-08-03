#include <unicode/ucsdet.h>
#include "config.h"

encodingBool_t encoding_detectb() {
  UErrorCode           uErrorCode = U_ZERO_ERROR;
  UCharsetDetector    *uCharsetDetector;
  const UCharsetMatch *uCharsetMatch;
  const char          *fromEncodings;
  int32_t              confidence; 
  streamInBool_t       rcb = STREAMIN_BOOL_TRUE;

  STREAMIN_TRACE0("Determining encoding using ICU");

  STREAMIN_TRACEX("ucsdet_open(%p)", &uErrorCode);
  uCharsetDetector = ucsdet_open(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_open(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_setText(%p, %p, %ld, %p)", uCharsetDetector, streamInp->byteBufpp[0], (unsigned long) streamInp->realSizeByteBufip[0], &uErrorCode);
  ucsdet_setText(uCharsetDetector, streamInp->byteBufpp[0], streamInp->realSizeByteBufip[0], &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_setText(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_detect(%p, %p)", uCharsetDetector, &uErrorCode);
  uCharsetMatch = ucsdet_detect(uCharsetDetector, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (uCharsetMatch == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_detect() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getName(%p, %p)", uCharsetMatch, &uErrorCode);
  fromEncodings = ucsdet_getName(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (fromEncodings == NULL) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned NULL at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }
  if (strlen(fromEncodings) <= 0) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getName() returned empty string at %s:%d", __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_TRACEX("ucsdet_getConfidence(%p, %p)", uCharsetMatch, &uErrorCode);
  confidence = ucsdet_getConfidence(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "ucsdet_getConfidence(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  if (confidence < 10) {
    STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ucsdet_getConfidence() returned encoding \"%s\" with too low confidence %d < 10 - rejected", fromEncodings, confidence);
    rcb = STREAMIN_BOOL_FALSE;
    goto ICU_end;
  }

  STREAMIN_LOGX(STREAMIN_LOGLEVEL_INFO, "ICU returned encoding \"%s\" with confidence %d", fromEncodings, confidence);

 ICU_end:

  if (rcb == STREAMIN_BOOL_TRUE) {
    /* Save the result */
    streamInp->streamInUtf8Option.fromEncodings = malloc(sizeof(char) * (strlen(fromEncodings) + 1));
    if (streamInp->streamInUtf8Option.fromEncodings == NULL) {
      STREAMIN_LOGX(STREAMIN_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
      rcb = STREAMIN_BOOL_FALSE;
    } else {
      strcpy(streamInp->streamInUtf8Option.fromEncodings, fromEncodings);
    }
  }

  if (uCharsetDetector != NULL) {
    STREAMIN_TRACEX("ucsdet_close(%p)", uCharsetDetector);
    ucsdet_close(uCharsetDetector);
  }

  return rcb;
}
