#ifndef MARPAXML_API_DOM_USERDATAHANDLER_H
#define MARPAXML_API_DOM_USERDATAHANDLER_H

#include "marpaXml/cplus.h"

SUBCLASS(UserDataHandler, Object)
  void           *ctx;
  unsigned short  NODE_IMPORTED;
  unsigned short  NODE_DELETED;
  unsigned short  NODE_RENAMED;
  unsigned short  NODE_ADOPTED;
VTABLE(UserDataHandler, Object)
  void (*handle)(UserDataHandler *me, short operation, String *key, Object *data, Node *src, Node *dst);
METHODS
  UserDataHandler *UserDataHandler_new();
  void             UserDataHandler_free(UserDataHandler *me);
END_CLASS

#endif /* MARPAXML_API_DOM_USERDATAHANDLER_H */
