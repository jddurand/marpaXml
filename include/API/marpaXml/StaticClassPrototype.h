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

#define module(name) MARPAXML ## _ ## name

#define class_decl(class) typedef struct class *class;
#define class_meth(class, meth) class ## _ ## method

#define subclass_decl(subclass, class) typedef struct subclass { class *parent; } *subclass;
#define subclass_meth(subclass, class, meth) subclass ## _ ## meth

#endif /* MARPAXML_STATICCLASSPROTOTYPE */
