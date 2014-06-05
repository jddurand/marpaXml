#ifndef MARPAXML_SAX_PARSER_H
#define MARPAXML_SAX_PARSER_H

#include "marpaXml/String.h"
#include "marpaXml/Locale.h"
#include "marpaXml/IOException.h"
#include "marpaXml/SAX/SAXException.h"
#include "marpaXml/SAX/EntityResolver.h"
#include "marpaXml/SAX/DTDHandler.h"
#include "marpaXml/SAX/DocumentHandler.h"
#include "marpaXml/SAX/ErrorHandler.h"
#include "marpaXml/SAX/InputSource.h"

typedef struct marpaXml_SAX_Parser {
  void (*setLocale)(marpaXml_Locale_t *locale, marpaXml_SAX_SAXException_t *SAXException);
  void (*setEntityResolver)(marpaXml_SAX_EntityResolver_t *resolver);
  void (*setDTDHandler)(marpaXml_SAX_DTDHandler_t *handler);
  void (*setDocumentHandler)(marpaXml_SAX_DocumentHandler_t *handler);
  void (*setErrorHandler)(marpaXml_SAX_ErrorHandler_t *handler);
  void (*parse)(marpaXml_SAX_InputSource_t *source, marpaXml_SAX_SAXException_t *SAXException, marpaXml_IOException_t *IOException);
  void (*parse_bySystemId)(marpaXml_String_t *systemId, marpaXml_SAX_SAXException_t *SAXException, marpaXml_IOException_t *IOException);
} *marpaXml_SAX_Parser_t;

marpaXml_SAX_Parser_t *marpaXml_SAX_Parser_new();
void                   marpaXml_SAX_Parser_destroy(marpaXml_SAX_Parser_t *this);

#endif /* MARPAXML_SAX_PARSER_H */
