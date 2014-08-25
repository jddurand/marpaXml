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
#include "marpaXml/cplus.h"
#include <assert.h>

/* Global objects ----------------------------------------------------------*/
ObjectVTABLE CP_ObjectVTABLE = {
    0, /* no superclass */
    (void (*)(Object *))&Object_abstract             /* purely virtual Xtor */
};
/*..........................................................................*/
int Object_isKindOf__(Object const *me, void const *vtable) {
    ObjectVTABLE *vt;
    for (vt = me->vptr__; vt; vt = vt->super__) {
        if (vt == vtable) {
            return 1;
        }
    }
    return 0;
}
/*..........................................................................*/
void Object_abstract(void) {
    assert(0);                    /* abstract method should never be called */
}

