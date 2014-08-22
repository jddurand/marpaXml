#ifndef MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H
#define MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H

#include "marpaXml/DOM/Node.h"

SUBCLASS(ProcessingInstruction, Node)
  void *ctx;
VTABLE(ProcessingInstruction, Node)
  String *(*getData)(ProcessingInstruction *me);
  String *(*getTarget)(ProcessingInstruction *me);
  void    (*setData)(ProcessingInstruction *me, String *data);
METHODS
  ProcessingInstruction *ProcessingInstruction_new();
  void                   ProcessingInstruction_free(ProcessingInstruction *me);
END_CLASS

#endif /* MARPAXML_API_DOM_PROCESSINGINSTRUCTION_H */
