#ifndef MARPAXML_READER_H
#define MARPAXML_READER_H

#include "marpaXml/Boolean.h"

typedef struct marpaXml_Reader {
  void               (*close)();
  void               (*mark)(int readAheadLimit);
  marpaXml_Boolean_t (*markSupported)();
} marpaXml_Reader_t;

marpaXml_Reader_t *marpaXml_Reader_new();
marpaXml_Reader_t *marpaXml_Reader_new_byLock(void *lock);

#endif /* MARPAXML_READER_H */
