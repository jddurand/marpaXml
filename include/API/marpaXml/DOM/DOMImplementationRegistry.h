#ifndef MARPAXML_DOM_DOMImplementationRegistry_H
#define MARPAXML_DOM_DOMImplementationRegistry_H

extern struct {
  DOMImplementation*	getDOMImplementation(const XMLCh* features);
  DOMImplementationList*	getDOMImplementationList(const XMLCh* features);
  void	addSource(DOMImplementationSource* source);
} marpaXml_DOM_DOMImplementationRegistry;

#endif /* MARPAXML_DOM_DOMImplementationRegistry_H */
