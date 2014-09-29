#ifndef MARPAXML_INTERNAL_MARPAWRAPPER_H
#define MARPAXML_INTERNAL_MARPAWRAPPER_H

#include <stddef.h>                  /* size_t definition */

#include "internal/streamIn.h"

/* Convention is:
   - all pointer symbols end with 'p'
   - all number  symbols end with 'i'
   - all boolean symbols end with 'b'
   - all string  symbols end with 's'
   - all void    symbols end with 'v'
   - all types    end with '_t'
*/

#include "API/marpaXml/log.h"

/***********************/
/* Opaque object types */
/***********************/
typedef struct marpaWrapper           marpaWrapper_t;
typedef struct marpaWrapperSymbol     marpaWrapperSymbol_t;
typedef struct marpaWrapperRule       marpaWrapperRule_t;
typedef struct marpaWrapperGrammar    marpaWrapperGrammar_t;
typedef struct marpaWrapperRecognizer marpaWrapperRecognizer_t;
typedef struct marpaWrapperValue      marpaWrapperValue_t;

/*******************/
/* Published types */
/*******************/

/* Boolean */
typedef enum marpaWrapperBool {
  MARPAWRAPPER_BOOL_FALSE =  0,
  MARPAWRAPPER_BOOL_TRUE  =  1
} marpaWrapperBool_t;

/* Value callback: boolean and stop directive */
typedef enum marpaWrapperValueBool {
  MARPAWRAPPER_VALUECALLBACKBOOL_STOP  = -1,     /* Used only when iterating over values via marpaWrapperValueCallback() */
  MARPAWRAPPER_VALUECALLBACKBOOL_FALSE =  0,
  MARPAWRAPPER_VALUECALLBACKBOOL_TRUE  =  1
} marpaWrapperValueBool_t;

/* Events */
typedef enum marpaWrapperEventType {
  MARPAWRAPPER_EVENTTYPE_COMPLETED = 0x01,
  MARPAWRAPPER_EVENTTYPE_NULLED    = 0x02,
  MARPAWRAPPER_EVENTTYPE_PREDICTED = 0x04,
} marpaWrapperEventType_t;

typedef struct marpaWrapperEvent {
  marpaWrapperEventType_t  eventType;
  marpaWrapperSymbol_t    *marpaWrapperSymbolp;
} marpaWrapperEvent_t;

/* Callbacks */

/* marpaWrapperEventCallback_t happen during lexing phase only */
typedef marpaWrapperBool_t      (*marpaWrapperEventCallback_t)           (void *datavp, marpaWrapper_t *marpaWrapperp, size_t nEventi, marpaWrapperEvent_t *marpaWrapperEventp);

/* Rule, symbol, nulling and result callbacks happen during value phase only. In this phase there is the notion of generic stack as well. */
typedef marpaWrapperBool_t      (*marpaWrapperValueRuleCallback_t)       (void *datavp, marpaWrapper_t *marpaWrapperp, marpaWrapperRule_t *marpaWrapperRulep, size_t nValueInputi, void **valueInputArraypp, void **valueOutputpp);
typedef marpaWrapperBool_t      (*marpaWrapperValueSymbolCallback_t)     (void *datavp, marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int value, void **valueOutputpp);
typedef marpaWrapperBool_t      (*marpaWrapperValueNullingCallback_t)    (void *datavp, marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, void **valueOutputpp);
typedef marpaWrapperValueBool_t (*marpaWrapperValueResultCallback_t)     (void *datavp, marpaWrapper_t *marpaWrapperp, void *valuep);
typedef marpaWrapperBool_t      (*marpaWrapperStackElementFreeCallback_t)(void *datavp, marpaWrapper_t *marpaWrapperp, void *elementp);
typedef marpaWrapperBool_t      (*marpaWrapperStackElementCopyCallback_t)(void *datavp, marpaWrapper_t *marpaWrapperp, void *elementDstp, void *elementSrcp);

/* Symbol options - This is an optional parameter, so there are defaults if is not supplied. */
typedef struct marpaWrapperSymbolOption {
  void              *datavp;      /* Default: NULL.                    User's opaque data pointer for this symbol     */
  marpaWrapperBool_t terminalb;   /* Default: MARPAWRAPPER_BOOL_FALSE. Eventually force symbol to be terminal         */
  marpaWrapperBool_t startb;      /* Default: MARPAWRAPPER_BOOL_FALSE. Eventually force symbol to be the start symbol */
  int                eventSeti;   /* Default: 0.                                                                      */
} marpaWrapperSymbolOption_t;

/* Rule options - this is a required parameter, so the user is EXPECTED to overwrite some members */
/* with meaningful values. In particular:                                                         */
/* - lhsSymbolp                                                                                   */
/* - nRhsSymboli                                                                                  */
/* - rhsSymbolpp                                                                                  */
typedef struct marpaWrapperRuleOption {
  void                  *datavp;            /* Default: NULL.                    User's opaque data pointer for this rule                           */
  marpaWrapperSymbol_t  *lhsSymbolp;        /* Default: NULL.                    LHS symbol as returned by marpaWrapperSymbol_newp()                */
  size_t                 nRhsSymboli;       /* Default: 0.                       Number of RHS                                                      */
  marpaWrapperSymbol_t **rhsSymbolpp;       /* Default: NULL.                    RHS symbols as returned by marpaWrapperSymbol_newp()               */
  int                    ranki;             /* Default: 0.                       Rank                                                               */
  marpaWrapperBool_t     nullRanksHighb;    /* Default: MARPAWRAPPER_BOOL_FALSE. Null variant pattern                                               */

  marpaWrapperBool_t     sequenceb;         /* Default: MARPAWRAPPER_BOOL_FALSE. Sequence ?                                                         */
  marpaWrapperSymbol_t  *separatorSymbolp;  /* Default: NULL.                    Eventual separator symbol as returned by marpaWrapperSymbol_newp() */
  marpaWrapperBool_t     properb;           /* Default: MARPAWRAPPER_BOOL_FALSE. Proper flag                                                        */
  int                    minimumi;          /* Default: 0.                       Mininimum - must be 0 or 1                                         */
} marpaWrapperRuleOption_t;

/**************************/
/* Constructor/destructor */
/**************************/
typedef struct marpaWrapperOption {
  int                          (*versionip)[3];          /* Default: NULL                                                             */
  marpaXmlLogLevel_t             logLevelWantedi;        /* Default: MARPAXML_LOGLEVEL_WARNING                                        */
  marpaXmlLogCallback_t          logCallbackp;           /* Default: marpaXmlLog_defaultLogCallback()                                 */
  void                          *logCallbackDatavp;      /* Default: NULL                                                             */
  marpaWrapperEventCallback_t    eventCallbackp;         /* Default: NULL                                                             */
  void                          *eventCallbackDatavp;    /* Default: NULL                                                             */
  marpaWrapperBool_t             warningIsErrorb;        /* Default: MARPAWRAPPER_BOOL_FALSE. Have precedence over warningIsIgnoredb  */
  marpaWrapperBool_t             warningIsIgnoredb;      /* Default: MARPAWRAPPER_BOOL_FALSE                                          */
  marpaWrapperBool_t             unsortedEventsb;        /* Default: MARPAWRAPPER_BOOL_FALSE. Completed, then nulled, then predicted. */
} marpaWrapperOption_t;
marpaWrapper_t           *marpaWrapper_newp(marpaWrapperOption_t *marpaWrapperOptionp);
void                      marpaWrapper_destroyv(marpaWrapper_t **marpaWrapperpp);

/**************************************************/
/* Phase 1: Grammar definition and precomputation */
/**************************************************/
marpaWrapperSymbol_t     *marpaWrapper_g_addSymbolp (marpaWrapper_t *marpaWrapperp, marpaWrapperSymbolOption_t *marpaWrapperSymbolOption);
marpaWrapperRule_t       *marpaWrapper_g_addRulep   (marpaWrapper_t *marpaWrapperp, marpaWrapperRuleOption_t *marpaWrapperRuleOptionp);
marpaWrapperBool_t        marpaWrapper_g_precomputeb(marpaWrapper_t *marpaWrapperp);

/***********************/
/* Phase 2: Recognizer */
/***********************/
typedef struct marpaWrapperProgress {
  int                 marpaEarleySetIdi;
  int                 marpaEarleySetIdOrigini;
  marpaWrapperRule_t *marpaWrapperRulep;
  int                 positioni;
} marpaWrapperProgress_t;

/* For those wanting to have manual control on recognizer */
marpaWrapperBool_t        marpaWrapper_r_startb               (marpaWrapper_t *marpaWrapperp);
marpaWrapperBool_t        marpaWrapper_r_alternativeb         (marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int value, int length);
marpaWrapperBool_t        marpaWrapper_r_completeb            (marpaWrapper_t *marpaWrapperp);
marpaWrapperBool_t        marpaWrapper_r_readb                (marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int value, int length);
marpaWrapperBool_t        marpaWrapper_r_event_activateb      (marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int eventSeti, marpaWrapperBool_t onb);
marpaWrapperBool_t        marpaWrapper_r_terminals_expectedb  (marpaWrapper_t *marpaWrapperp, size_t *nMarpaWrapperSymbolip, marpaWrapperSymbol_t ***marpaWrapperSymbolppp);
marpaWrapperBool_t        marpaWrapper_r_terminal_is_expectedb(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, marpaWrapperBool_t *isExpectedbp);
marpaWrapperBool_t        marpaWrapper_r_progressb            (marpaWrapper_t *marpaWrapperp, int starti, int endi, size_t *nmarpaWrapperProgressip, marpaWrapperProgress_t ***marpaWrapperProgressppp);

/* Generic routine using all of the above */
/* streamInp is supposed to have been opened in UTF-8 mode */
typedef marpaWrapperBool_t (*marpaWrapper_isLexemebCallback_t)(void *p, signed int currenti, streamIn_t *streamInp, size_t *lengthlp);
typedef marpaWrapperBool_t (*marpaWrapper_lexemeValuebCallback_t)(void *lexemeValuebCallbackDatavp, streamIn_t *streamInp, size_t lengthl, int *lexemeValueip);
typedef marpaWrapperBool_t (*marpaWrapper_ruleToStringb_t)(marpaWrapperRule_t *marpaWrapperRulep, const char **rulesp);
typedef marpaWrapperBool_t (*marpaWrapper_symbolToStringb_t)(marpaWrapperSymbol_t *marpaWrapperSymbolp, const char **rulesp);

marpaWrapperBool_t        marpaWrapper_r_recognizeb           (marpaWrapper_t *marpaWrapperp,
                                                               streamIn_t *streamInp,
                                                               marpaWrapper_isLexemebCallback_t isLexemebCallbackp,
                                                               void *lexemeValuebCallbackDatavp,
                                                               marpaWrapper_lexemeValuebCallback_t lexemeValuebCallbackp,
                                                               void *symbolToStringDatavp,
                                                               marpaWrapper_symbolToStringb_t symbolToStringCallbackp,
                                                               void *ruleToStringDatavp,
                                                               marpaWrapper_ruleToStringb_t ruleToStringCallbackp);

/******************/
/* Phase 3: Value */
/******************/
typedef struct marpaWrapperValueOption {
  /* Ordering options */
  marpaWrapperBool_t                     highRankOnlyb;                          /* Default: MARPAWRAPPER_BOOL_TRUE  */
  marpaWrapperBool_t                     orderByRankb;                           /* Default: MARPAWRAPPER_BOOL_TRUE  */
  marpaWrapperBool_t                     ambiguityb;                             /* Default: MARPAWRAPPER_BOOL_TRUE  */
  marpaWrapperBool_t                     nullb;                                  /* Default: MARPAWRAPPER_BOOL_TRUE  */
  /* Stack manipulation */
  marpaWrapperValueRuleCallback_t        valueRuleCallbackp;                     /* Default: NULL                    */
  void                                  *valueRuleCallbackDatavp;                /* Default: NULL                    */
  marpaWrapperValueSymbolCallback_t      valueSymbolCallbackp;                   /* Default: NULL                    */
  void                                  *valueSymbolCallbackDatavp;              /* Default: NULL                    */
  marpaWrapperValueNullingCallback_t     valueNullingCallbackp;                  /* Default: NULL                    */
  void                                  *valueNullingCallbackDatavp;             /* Default: NULL                    */
  marpaWrapperValueResultCallback_t      valueResultCallbackp;                   /* Default: NULL                    */
  void                                  *valueResultCallbackDatavp;              /* Default: NULL                    */
} marpaWrapperValueOption_t;

/* marpaWrapperStackOptionp is mandatory, so there is no default */
typedef struct marpaWrapperStackOption {
  size_t                                 stackElementSizei;                      /* Default: 0. Must be > 0          */
  marpaWrapperStackElementFreeCallback_t stackElementFreeCallbackp;              /* Default: NULL.                   */
  void                                  *stackElementFreeCallbackUserDatap;      /* Default: NULL                    */
  marpaWrapperStackElementCopyCallback_t stackElementCopyCallbackp;              /* Default: NULL                    */
  void                                  *stackElementCopyCallbackUserDatap;      /* Default: NULL                    */
} marpaWrapperStackOption_t;
marpaWrapperBool_t        marpaWrapper_vb(marpaWrapper_t *marpaWrapperp, marpaWrapperValueOption_t *marpaWrapperValueOptionp, marpaWrapperStackOption_t *marpaWrapperStackOptionp);

/*************************/
/* Default options helper */
/*************************/
marpaWrapperBool_t        marpaWrapper_optionDefaultb          (marpaWrapperOption_t *marpaWrapperOptionp);
marpaWrapperBool_t        marpaWrapper_symbolOptionDefaultb    (marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp);
marpaWrapperBool_t        marpaWrapper_ruleOptionDefaultb      (marpaWrapperRuleOption_t *marpaWrapperRuleOptionp);
marpaWrapperBool_t        marpaWrapper_valueOptionDefaultb     (marpaWrapperValueOption_t *marpaWrapperValueOptionp);
marpaWrapperBool_t        marpaWrapper_stackOptionDefaultb     (marpaWrapperStackOption_t *marpaWrapperStackOptionp);

/*****************/
/* Top accessors */
/*****************/
marpaXmlLog_t *marpaWrapper_marpaXmlLogp(marpaWrapper_t *marpaWrapperp);

/* Generic getter definition */
#define MARPAWRAPPER_GENERATE_GETTER_DECLARATION(prefix, externalType, externalName) \
  marpaWrapperBool_t prefix##_##externalName##_getb(prefix##_t * prefix##p, externalType *externalName##p)

/***************************************************************************************/
/* From a wrapper opaque pointer, get size of/array of opaque symbol and rule pointers */
/***************************************************************************************/
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper,                  size_t, sizeMarpaWrapperSymboli);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper, marpaWrapperSymbol_t **, marpaWrapperSymbolpp);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper,                  size_t, sizeMarpaWrapperRulei);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper,   marpaWrapperRule_t **, marpaWrapperRulepp);

/******************************************************************/
/* From a symbol opaque pointer, get opaque user data, work flags */
/******************************************************************/
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapperSymbol, void *, datavp);

/****************************************************/
/* From a rule opaque pointer, get opaque user data */
/****************************************************/
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapperRule, void *, datavp);

/*************************************************************************************/
/* Avdanced users will want to play themselves with Marpa objects                    */
/* The user application will have to #include "marpa.h" and typecast correspondingly */
/*************************************************************************************/
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper, void *, Marpa_Config);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper, void *, Marpa_Grammar);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapper, void *, Marpa_Recognizer);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapperSymbol, unsigned int, Marpa_Symbol_ID);
MARPAWRAPPER_GENERATE_GETTER_DECLARATION(marpaWrapperRule, unsigned int, Marpa_Rule_ID);

#endif /* MARPAXML_INTERNAL_MARPAWRAPPER_H */
