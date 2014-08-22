/*****************************************************************************
* Product:  "C+" Object Oriented Programming in C
* Version:  3.0
* Updated:  January 29, 2005
*
* Copyright (C) 2002-2005 Quantum Leaps. All rights reserved.
*
* This software may be distributed and modified under the terms of the
* BSD open source license, which is provided below.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
*
* Neither the name of the Quantum Leaps nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL QUANTUM LEAPS OR OTHER CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Contact information:
* Quantum Leaps Web site:  http://www.quantum-leaps.com
* Quantum Leaps licensing: http://www.quantum-leaps.com/licensing
* e-mail:                  sales@quatnum-leaps.com
*****************************************************************************/
#ifndef cplus_h
#define cplus_h

#ifdef __cplusplus
extern "C" {
#endif

              /* Macros for declaring simple classes (without polymorphism) */
#define CLASS(name_) \
    typedef struct name_##Tag name_; \
    struct name_##Tag {
#define METHODS };
#define END_CLASS

       /* Abstract base class Object, root of all classes with polymorphism */
CLASS(Object)
    struct ObjectVTABLETag *vptr__;              /* private virtual pointer */
METHODS
                                       /* protected constructor 'inline'... */
    #define Object_ctor_(me_) ((me_)->vptr__ = &CP_ObjectVTABLE, (me_))

                                        /* protected destructor 'inline'... */
    #define Object_xtor_(me_) ((void)0)

                               /* dummy implementation for abstract methods */
    void Object_abstract(void);

                                     /* Run Time Type Identification (RTTI) */
    #define Object_IS_KIND_OF(me_, class_) \
        Object_isKindOf__((Object *)(me_), &CP_##class_##VTABLE)

    int Object_isKindOf__(Object const *me, void const *vtable);
END_CLASS

CLASS(ObjectVTABLE)
    ObjectVTABLE *super__;                   /* pointer to superclass' VTBL */
    void (*xtor)(Object *);                    /* public virtual destructor */
METHODS
END_CLASS

extern ObjectVTABLE CP_ObjectVTABLE;             /* Object class descriptor */

                                         /* Macros for declaring subclasses */
#define SUBCLASS(class_, superclass_) \
    CLASS(class_) \
        superclass_ super_;

               /* Macros for defining VTABLEs and binding virtual functions */
#define VTABLE(class_, superclass_) }; \
    typedef struct class_##VTABLETag class_##VTABLE; \
    extern class_##VTABLE CP_##class_##VTABLE; \
    struct class_##VTABLETag { \
        superclass_##VTABLE super_;

#define BEGIN_VTABLE(class_, superclass_) \
    class_##VTABLE CP_##class_##VTABLE; \
    static ObjectVTABLE *class_##VTABLECtor(class_ *t) { \
        class_##VTABLE *me = &CP_##class_##VTABLE; \
        *(superclass_##VTABLE *)me = \
            *(superclass_##VTABLE *)((Object *)t)->vptr__;

#define VMETHOD(class_, meth_) ((class_##VTABLE *)me)->meth_

#define END_VTABLE \
        ((ObjectVTABLE *)me)->super__ = ((Object *)t)->vptr__; \
        return (ObjectVTABLE *)me; \
    }

                      /* Macro to hook virtual pointer used in constructors */
#define VHOOK(class_) \
    if (((ObjectVTABLE *)&CP_##class_##VTABLE)->super__ == 0) \
        ((Object *)me)->vptr__ = class_##VTABLECtor(me); \
    else \
       (((Object *)me)->vptr__ = (ObjectVTABLE *)&CP_##class_##VTABLE)

                                               /* Macro to access v-pointer */
#define VPTR(class_, obj_) \
    ((class_##VTABLE *)(((Object *)(obj_))->vptr__))

                                /* Macro for invoking virtual class methods */
#define VCALL(class_, meth_, obj_) \
    (*VPTR(class_, obj_)->meth_)((class_*)(obj_)
#define END_CALL )

                               /* Find an offset of a member into its class */
#define OFFSET_OF(class_, attr_) ((unsigned)&((class_ *)0)->attr_)

#ifdef __cplusplus
}
#endif

/* Addon : forward declaration of type */
#define FORWARD_CLASS(name_) typedef struct name_##Tag name_;

#endif                                                           /* cplus_h */
