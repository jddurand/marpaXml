#ifndef MARPAXML_LOCALE_H
#define MARPAXML_LOCALE_H

#include <marpaXml/String.h>

typedef struct marpaXml_Locale {
  int                category;
  marpaXml_String_t *locale;
} marpaXml_Locale_t;

#endif /* MARPAXML_LOCALE_H */
