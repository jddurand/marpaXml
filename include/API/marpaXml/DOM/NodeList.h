#ifndef MARPAXML_API_DOM_NODELIST_H
#define MARPAXML_API_DOM_NODELIST_H

#include "marpaXml/cplus.h"

SUBCLASS(NodeList, Object)
  VTABLE(NodeList, Object)
METHODS
 int  getLength();
 Node item(int index);
END_CLASS

#endif /* MARPAXML_API_DOM_NODELIST_H */
