#ifndef MARPAXML_SAX_XMLREADER_H
#define MARPAXML_SAX_XMLREADER_H

#include "marpaXml/SAX/XMLReader.h"

typedef struct marpaXml_SAX_XMLReader {
  void (*setParent)(struct marpaXml_SAX_XMLReader *parent);
  struct marpaXml_SAX_XMLReader_t *(*getParent)();
} *marpaXml_SAX_XMLReader_t;

marpaXml_SAX_XMLReader_t *marpaXml_SAX_XMLReader_new();
void                      marpaXml_SAX_XMLReader_destroy(marpaXml_SAX_XMLReader_t *this);

#endif /* MARPAXML_SAX_XMLREADER_H */
