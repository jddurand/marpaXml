#ifndef MARPAXML_CHARSET_H
#define MARPAXML_CHARSET_H

#include "marpaXml/cplus.h"

SUBCLASS(Charset, Object)
VTABLE(Charset, Object)
  void *(*decode)(void *bytes, size_t length);
    Charset (*new)(void);
    Charset (*new2)(void bytes[], unsigned long long int length);
    Charset (*new3)(void bytes[], unsigned long long int length, char *charset);
    Charset (*new4)(Charset obj, char *charset);
typedef struct marpaXml_Charset {
  const char  *charset;            /* Not a hazard it is the first member */
  const size_t byteLength;        /* Number of bytes */
  const size_t characterLength;   /* Number of characters */
  const char  *encoding;          /* If NULL: native encoding of your C implementation */
} *marpaXml_Charset_t;

#endif /* MARPAXML_CHARSET_H */
