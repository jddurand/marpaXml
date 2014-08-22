#ifndef MARPAXML_API_DOM_CDATASECTION_H
#define MARPAXML_API_DOM_CDATASECTION_H

#include "marpaXml/DOM/Text.h"

SUBCLASS(CDATASection, Text)
  void *ctx;
VTABLE(CDATASection, Text)
METHODS
  CDATASection *CDATASection_new();
  void          CDATASection_free(CDATASection *me);
END_CLASS

#endif /* MARPAXML_API_DOM_CDATASECTION_H */
