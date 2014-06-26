#ifndef MARPAXML_STATICCLASSPROTOTYPE
#define MARPAXML_STATICCLASSPROTOTYPE

/*
  We are not gonna use a generic C object simulation framework because
  our class are all static.
  Excellent literature on this subject can found at e.g. http://ldeniau.web.cern.ch/ldeniau/oopc.html
  and elsewhere on the internet.

  Because everything in our case is static we handle ourself class and objects with our own
  macros. This implementation only support inheritance. Which is enough in case of DOM3 and SAX2.
*/

/* Generic prefix for symbol unicity */
#define module(name) marpaXml ## _ ## name

#define MARPAXLM_STATICCLASSPROTOTYPE_REFERENCE(a) &a

/* Class definition: structure pointer, constructor, destructor */
#define class_decl(class) {   						\
  typedef struct module(class) * module(class ## p);                    \
  void * module(class ## _newp());                                      \
  void   module(class ## _destroyv( struct module(class) * module(class ## p) ) );
}

/* Class method */
#define class_meth(class, meth) module(class) ## _ ## meth

/* Subclass definition */
#define subclass_decl(subclass, class) class_decl(subclass)
#define subclass_meth(subclass, class, meth) class_meth(subclass, meth)

class_decl(dom)


#endif /* MARPAXML_STATICCLASSPROTOTYPE */
