#ifndef MARPAXML_EXCEPTION_H
#define MARPAXML_EXCEPTION_H

#include "marpaXml/String.h"

typedef struct marpaXml_Exception {
  int                 errorCode;
  marpaXml_String_t  *message;
} marpaXml_Exception_t;

marpaXml_Exception_t *marpaXml_Exception_new();
void                  marpaXml_Exception_destroy(marpaXml_Exception_t *this);

#endif /* MARPAXML_EXCEPTION_H */
