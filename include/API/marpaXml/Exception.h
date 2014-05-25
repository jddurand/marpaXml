#ifndef MARPAXML_EXCEPTION_H
#define MARPAXML_EXCEPTION_H

#include "marpaXml/String.h"

typedef struct marpaXml_Exception {
  int                errorCode;
  marpaXml_String_t *message;  /* String returned by the low-level, always compatible with what your C natively understand */
} marpaXml_Exception_t;

#endif /* MARPAXML_EXCEPTION_H */
