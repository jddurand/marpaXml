#ifndef MARPAXML_API_DOM_USERDATAHANDLER_H
#define MARPAXML_API_DOM_USERDATAHANDLER_H

#include "marpaXml/cplus.h"

SUBCLASS(UserDataHandler, Object)
  VTABLE(UserDataHandler, Object)
  short NODE_ADOPTED;
  short NODE_CLONED;
  short NODE_DELETED;
  short NODE_IMPORTED;
  short NODE_RENAMED;
METHODS
  void handle(short operation, String key, Object data, Node src, Node dst);
END_CLASS

#endif /* MARPAXML_API_DOM_USERDATAHANDLER_H */
