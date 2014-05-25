#ifndef MARPAXML_SAX_XMLFILTER_H
#define MARPAXML_SAX_XMLFILTER_H

#include "marpaXml/SAX/XMLReader.h"

typedef struct marpaXml_SAX_XMLFilter {
  void (*setParent)(marpaXml_SAX_XMLReader_t *parent);
  marpaXml_SAX_XMLReader_t *(*getParent)();
} *marpaXml_SAX_XMLFilter_t;

marpaXml_SAX_XMLFilter_t *marpaXml_SAX_XMLFilter_new();
void                      marpaXml_SAX_XMLFilter_destroy(marpaXml_SAX_XMLFilter_t *this);

#endif /* MARPAXML_SAX_XMLFILTER_H */
