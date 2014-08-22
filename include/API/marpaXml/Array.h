#ifndef MARPAXML_ARRAY_H
#define MARPAXML_ARRAY_H

#include <stddef.h>

#include "marpaXml/cplus.h"

SUBCLASS(Array, Object)
  void *buf;
  size_t byteLength;
  size_t length;
  size_t unitSize;
VTABLE(Array, Object)
  size_t (*getUnitSize)();
  size_t (*getLength)();
  size_t (*getByteLength)();
  void  *(*getAddress)();
METHODS
  Array *Array_new(size_t byteLength);
  Array *Array_new2(size_t length, size_t unitSize);
  void   Array_free(Array *me);
END_CLASS

#endif /* MARPAXML_ARRAY_H */
