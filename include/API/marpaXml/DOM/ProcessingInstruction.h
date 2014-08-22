#ifndef MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H
#define MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(ProcessingInstruction, Node)
  VTABLE(ProcessingInstruction, Node)
METHODS
  String getData();
  String getTarget();
  void   setData(String data);
END_CLASS

#endif /* MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H */
