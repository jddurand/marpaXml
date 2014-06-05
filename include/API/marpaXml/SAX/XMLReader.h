#ifndef MARPAXML_SAX_XMLREADER_H
#define MARPAXML_SAX_XMLREADER_H

#include "marpaXml/SAX/ContentHandler.h"
#include "marpaXml/SAX/DTDHandler.h"
#include "marpaXml/SAX/EntityResolver.h"
#include "marpaXml/SAX/ErrorHandler.h"
#include "marpaXml/SAX/InputSource.h"
#include "marpaXml/Boolean.h"
#include "marpaXml/String.h"

typedef struct marpaXml_SAX_XMLReader {
  marpaXml_SAX_ContentHandler_t *(*getContentHandler)();
  marpaXml_SAX_DTDHandler_t     *(*getDTDHandler)();
  marpaXml_SAX_EntityResolver_t	*(*getEntityResolver)();
  marpaXml_SAX_ErrorHandler_t   *(*getErrorHandler)();
  marpaXml_Boolean_t             (*getFeature)(marpaXml_String_t *name);
  void                           (*getProperty)(marpaXml_String_t *name);
  void                           (*parse)(marpaXml_SAX_InputSource_t *input);
  void                           (*parse_bySystemId)(marpaXml_String_t *systemId);
  void                           (*setContentHandler)(marpaXml_SAX_ContentHandler_t *handler);
  void                           (*setDTDHandler)(marpaXml_SAX_DTDHandler_t *handler);
  void                           (*setEntityResolver)(marpaXml_SAX_EntityResolver_t *resolver);
  void                           (*setErrorHandler)(marpaXml_SAX_ErrorHandler_t *handler);
  void                           (*setFeature)(marpaXml_String_t *name, marpaXml_Boolean_t value);
  void                           (*setProperty)(marpaXml_String_t *name, void *value);
} *marpaXml_SAX_XMLReader_t;

marpaXml_SAX_XMLReader_t *marpaXml_SAX_XMLReader_new();
void                      marpaXml_SAX_XMLReader_destroy(marpaXml_SAX_XMLReader_t *this);

#endif /* MARPAXML_SAX_XMLREADER_H */
