#ifndef MARPAXML_SAX_ENTITYRESOLVER_H
#define MARPAXML_SAX_ENTITYRESOLVER_H

#include "marpaXml/String.h"
#include "marpaXml/IOException.h"
#include "marpaXml/SAX/Locator.h"
#include "marpaXml/SAX/InputSource.h"
#include "marpaXml/SAX/AttributeList.h"
#include "marpaXml/SAX/SAXException.h"

typedef struct marpaXml_SAX_EntityResolver {
  marpaXml_SAX_InputSource_t (*resolveEntity)(marpaXml_String_t *publicId, marpaXml_String_t *systemId, marpaXml_SAX_SAXException_t *SAXException, marpaXml_IOException_t *IOException);
} *marpaXml_SAX_EntityResolver_t;

marpaXml_SAX_EntityResolver_t *marpaXml_SAX_EntityResolver_new();
void                           marpaXml_SAX_EntityResolver_destroy(marpaXml_SAX_EntityResolver_t *this);

#endif /* MARPAXML_SAX_ENTITYRESOLVER_H */
