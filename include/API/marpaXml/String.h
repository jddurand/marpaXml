#ifndef MARPAXML_STRING_H
#define MARPAXML_STRING_H

#include "marpaXml/cplus.h"

SUBCLASS(String, Object)
  VTABLE(String, Object)
  unsigned char *utf8__;                    /* Internal representation: UTF-8 */
  unsigned long long int *byteLength__;     /* Length of internal representation, including NULL byte */
METHODS
    String (*new)(void);
    String (*new2)(char *bytes, unsigned long long int length);
    String (*new3)(char *bytes, unsigned long long int length, char *charset);
END_CLASS

#endif /* MARPAXML_STRING_H */
