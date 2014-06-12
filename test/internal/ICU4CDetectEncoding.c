#include <stdio.h>
#include <stddef.h>                  /* size_t definition */
#include "unicode/ucsdet.h"

static void icu4c_getEncoding(const char *s, size_t lengthl);

int main(int argc, char **argv) {
  if (argc == 2) {
    char buf[10000];
    FILE *fh = fopen(argv[1], "rb");
    size_t n;
    if (fh == NULL) {
      perror(argv[1]);
      return 1;
    }
    if ((n = fread((void *) buf, 1, sizeof(buf), fh)) == 0) {
      perror(argv[1]);
      fclose(fh);
      return 1;
    }
    icu4c_getEncoding(buf, n);
    fclose(fh);   
  } else {
    icu4c_getEncoding("ᚠᛇᚻ᛫ᛒᛦᚦ᛫ᚠᚱᚩᚠᚢᚱ᛫ᚠᛁᚱᚪ᛫ᚷᛖᚻ", 15);
  }
  return 0;
}

static void icu4c_getEncoding(const char *s, size_t lengthl) {
  UErrorCode           uErrorCode = U_ZERO_ERROR;
  UCharsetDetector    *uCharsetDetector;
  const UCharsetMatch *uCharsetMatch;
  const char          *encodings;
  int32_t              confidence; 

  uCharsetDetector = ucsdet_open(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    fprintf(stderr, "ucsdet_open failure\n");
    goto error;
  }

  ucsdet_setText(uCharsetDetector, s, lengthl, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    fprintf(stderr, "ucsdet_setText failure\n");
    goto error;
  }

  uCharsetMatch = ucsdet_detect(uCharsetDetector, &uErrorCode);
  if (uCharsetMatch == NULL || U_FAILURE(uErrorCode)) {
    fprintf(stderr, "ucsdet_detect failure\n");
    goto error;
  }

  encodings = ucsdet_getName(uCharsetMatch, &uErrorCode);
  if (encodings == NULL || U_FAILURE(uErrorCode)) {
    fprintf(stderr, "ucsdet_getName failure\n");
    goto error;
  }

  confidence = ucsdet_getConfidence(uCharsetMatch, &uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    fprintf(stderr, "ucsdet_getConfidence failure\n");
    goto error;
  }

  if (confidence < 10) {
    fprintf(stderr, "Detected encoding %s has confidence %d < 10\n", encodings, (int) confidence);
    goto error;
  }

  fprintf(stderr, "Detected encoding: %s, confidence %d\n", encodings, confidence);

 error:
  if (uCharsetDetector != NULL) {
    ucsdet_close(uCharsetDetector);
  }
}
