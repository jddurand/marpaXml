#ifndef MARPAXML_STRING_H
#define MARPAXML_STRING_H

#include <stddef.h>

typedef struct marpaXml_String {
  const char  *string;            /* Not a hazard it is the first member */
  const size_t byteLength;        /* Number of bytes */
  const size_t characterLength;   /* Number of characters */
  const char  *encoding;          /* If NULL: native encoding of your C implementation */
} *marpaXml_String_t;

#endif /* MARPAXML_STRING_H */
