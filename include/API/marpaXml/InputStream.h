#ifndef MARPAXMl_INPUTSTREAM_H
#define MARPAXMl_INPUTSTREAM_H

#include "marpaXml/Boolean.h"

typedef struct marpaXml_InputStream {
  int                (*available)();
  void               (*close)();
  void               (*mark)(int readlimit);
  marpaXml_Boolean_t (*markSupported)();
  int                (*read_nextByte)();
  int                (*read_bytes)(char *b, int *lenp);
  int                (*read_byOff_byLen)(char *b, int off, int len);
  void               (*reset)();
  long               (*skip)(long n);
} marpaXml_InputStream_t;

marpaXml_InputStream_t *marpaXml_InputStream_new();
void                    marpaXml_InputStream_destroy(marpaXml_InputStream_t *this);

#endif /* MARPAXML_INPUTSTREAM_H */
