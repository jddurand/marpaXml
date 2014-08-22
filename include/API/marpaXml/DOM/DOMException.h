#ifndef MARPAXML_API_DOM_DOMEXCEPTION_H
#define MARPAXML_API_DOM_DOMEXCEPTION_H

#include "marpaXml/cplus.h"

CLASS(DOMException)
  short   code;
  String *message;
  short   DOMSTRING_SIZE_ERR;
  short   HIERARCHY_REQUEST_ERR;
  short   INDEX_SIZE_ERR;
  short   INUSE_ATTRIBUTE_ERR;
  short   INVALID_ACCESS_ERR;
  short   INVALID_CHARACTER_ERR;
  short   INVALID_MODIFICATION_ERR;
  short   INVALID_STATE_ERR;
  short   NAMESPACE_ERR;
  short   NO_DATA_ALLOWED_ERR;
  short   NO_MODIFICATION_ALLOWED_ERR;
  short   NOT_FOUND_ERR;
  short   NOT_SUPPORTED_ERR;
  short   SYNTAX_ERR;
  short   TYPE_MISMATCH_ERR;
  short   VALIDATION_ERR;
  short   WRONG_DOCUMENT_ERR;
METHODS
  DOMException *DOMException_new(short code, String *message);
  void          DOMException_free(DOMException *me);
END_CLASS

#endif /* MARPAXML_API_DOM_DOMEXCEPTION_H */
