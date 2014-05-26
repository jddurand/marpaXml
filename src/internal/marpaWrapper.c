#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>

#include "internal/marpaWrapper.h"
#include "internal/genericStack.h"
#include "internal/messageBuilder.h"
#include "marpa.h"

#define MARPAWRAPPER_GENERATE_GETTER_DEFINITION(prefix, externalType, externalName, ref, internalName) \
  marpaWrapperBool_t prefix##_##externalName##_getb(prefix##_t * prefix##p, externalType *externalName##p) { \
    if (prefix##p != NULL) {						\
      *externalName##p = (externalType) ref(prefix##p->internalName);	\
      return MARPAWRAPPER_BOOL_TRUE;					\
    } else {                                                            \
      return MARPAWRAPPER_BOOL_FALSE;					\
    }                                                                   \
  }

/* Grrrr... No way to solve that with standard, that's why GCC invented ##__VA_ARGS__ btw */
#define MARPAWRAPPER_LOG_0(level, origin, error, callerfmts)      _marpaWrapper_log_any(marpaWrapperp, level, origin, error, callerfmts)
#define MARPAWRAPPER_LOG_X(level, origin, error, callerfmts, ...) _marpaWrapper_log_any(marpaWrapperp, level, origin, error, callerfmts, __VA_ARGS__)

/* Generic info and trace log. Per def they have no "origin" from error point of view */
#define MARPAWRAPPER_LOG_INFO0(callerfmts)      MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_INFO, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts)
#define MARPAWRAPPER_LOG_INFOX(callerfmts, ...) MARPAWRAPPER_LOG_X(MARPAWRAPPER_LOGLEVEL_INFO, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts, __VA_ARGS__)
#ifndef MARPAWRAPPER_NTRACE
#define MARPAWRAPPER_LOG_TRACE0(callerfmts)      MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_TRACE, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts)
#define MARPAWRAPPER_LOG_TRACEX(callerfmts, ...) MARPAWRAPPER_LOG_X(MARPAWRAPPER_LOGLEVEL_TRACE, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts, __VA_ARGS__)
#else
#define MARPAWRAPPER_LOG_TRACE0(callerfmts)
#define MARPAWRAPPER_LOG_TRACEX(callerfmts, ...)
#endif
#define MARPAWRAPPER_LOG_WARNING0(callerfmts)      MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_WARNING, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts)
#define MARPAWRAPPER_LOG_WARNINGX(callerfmts, ...) MARPAWRAPPER_LOG_X(MARPAWRAPPER_LOGLEVEL_WARNING, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts, __VA_ARGS__)
#define MARPAWRAPPER_LOG_ERROR0(callerfmts)      MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_ERROR, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts)
#define MARPAWRAPPER_LOG_ERRORX(callerfmts, ...) MARPAWRAPPER_LOG_X(MARPAWRAPPER_LOGLEVEL_ERROR, MARPAWRAPPERERRORORIGIN_NA, 0, callerfmts, __VA_ARGS__)

/* Dedicated Marpa log macros */
#define MARPAWRAPPER_LOG_MARPA_ERROR(errorCode) MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_ERROR, MARPAWRAPPERERRORORIGIN_MARPA, errorCode, NULL);
#define MARPAWRAPPER_LOG_MARPA_G_ERROR MARPAWRAPPER_LOG_MARPA_ERROR(marpa_g_error(marpaWrapperp->marpaGrammarp, NULL))
#define MARPAWRAPPER_LOG_MARPA_C_ERROR MARPAWRAPPER_LOG_MARPA_ERROR(marpa_c_error(&(marpaWrapperp->marpaConfig), NULL));

/* Dedicated System log macro */
#define MARPAWRAPPER_LOG_SYS_ERROR(errorCode, calls) MARPAWRAPPER_LOG_0(MARPAWRAPPER_LOGLEVEL_ERROR, MARPAWRAPPERERRORORIGIN_SYSTEM, errorCode, calls);

/****************/
/* Object types */
/****************/
struct marpaWrapper {
  Marpa_Config             marpaConfig;
  Marpa_Grammar            marpaGrammarp;
  Marpa_Recognizer         marpaRecognizerp;

  size_t                   sizeMarpaWrapperSymboli;           /* Allocated size */
  size_t                   nMarpaWrapperSymboli;              /* Used size      */
  marpaWrapperSymbol_t   **marpaWrapperSymbolpp;

  size_t                   sizeMarpaWrapperRulei;             /* Allocated size */
  size_t                   nMarpaWrapperRulei;                /* Used size      */
  marpaWrapperRule_t     **marpaWrapperRulepp;

  Marpa_Symbol_ID         *expectedMarpaSymbolIdArrayp;       /* One block allocated once a recognizer is created */
  marpaWrapperSymbol_t   **expectedMarpaWrapperSymbolArraypp; /* One block allocated once a recognizer is created */

  size_t                   sizeMarpaWrapperProgressi;         /* Allocated size */
  size_t                   nMarpaWrapperProgressi;            /* Used size      */
  marpaWrapperProgress_t **marpaWrapperProgresspp;

  marpaWrapperOption_t     marpaWrapperOption;
};

MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,                  void *, Marpa_Config, &, marpaConfig);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,                  void *, Marpa_Grammar, , marpaGrammarp);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,                  void *, Marpa_Recognizer, , marpaRecognizerp);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,                  size_t, sizeMarpaWrapperSymboli, , sizeMarpaWrapperSymboli);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper, marpaWrapperSymbol_t **, marpaWrapperSymbolpp, , marpaWrapperSymbolpp);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,                  size_t, sizeMarpaWrapperRulei, , sizeMarpaWrapperRulei);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapper,   marpaWrapperRule_t **, marpaWrapperRulepp, , marpaWrapperRulepp);

struct marpaWrapperSymbol {
  Marpa_Symbol_ID            marpaSymbolIdi;
  marpaWrapperRule_t        *marpaWrapperRulep;
  marpaWrapper_t            *marpaWrapperp;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;
};

MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperSymbol, void *, datavp, , marpaWrapperSymbolOption.datavp);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperSymbol, unsigned int, Marpa_Symbol_ID, , marpaSymbolIdi);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperSymbol, marpaWrapperRule_t *, marpaWrapperRulep, , marpaWrapperRulep);

struct marpaWrapperRule {
  Marpa_Rule_ID             marpaRuleIdi;
  marpaWrapperSymbol_t      *marpaWrapperSymbolp;
  marpaWrapper_t            *marpaWrapperp;
  marpaWrapperRuleOption_t  marpaWrapperRuleOption;
};

MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperRule, void *, datavp, , marpaWrapperRuleOption.datavp);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperRule, unsigned int, Marpa_Rule_ID, , marpaRuleIdi);
MARPAWRAPPER_GENERATE_GETTER_DEFINITION(marpaWrapperRule, marpaWrapperSymbol_t *, marpaWrapperSymbolp, , marpaWrapperSymbolp);

static int _marpaWrapper_event_cmp(const void *event1p, const void *event2p);
static int _marpaWrapper_event_weight(Marpa_Event_Type eventType);

/********************/
/* Internal methods */
/********************/
/* Logging stuff */
static void        _marpaWrapper_logWrapper(marpaWrapper_t *marpaWrapperp, marpaWrapperErrorOrigin_t errorOrigini, int errorNumberi, const char *calls, marpaWrapperLogLevel_t logLeveli);
static void        _marpaWrapper_logCallback(void *logCallbackDatavp, marpaWrapper_t *marpaWrapperp, marpaWrapperLogLevel_t logLeveli, const char *msgs);
static const char *_marpaWrapper_strerror   (marpaWrapperErrorOrigin_t errorOrigini, int errorNumberi);

/* API helpers */
static marpaWrapperBool_t    _marpaWrapper_event       (marpaWrapper_t *marpaWrapperp);
static marpaWrapperSymbol_t *_marpaWrapper_g_addSymbolp(marpaWrapper_t *marpaWrapperp, Marpa_Symbol_ID symbolIdi, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp);
static marpaWrapperRule_t   *_marpaWrapper_g_addRulep  (marpaWrapper_t *marpaWrapperp, Marpa_Rule_ID marpaRuleIdi, marpaWrapperRuleOption_t *marpaWrapperRuleOptionp, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp);
static marpaWrapperBool_t    _marpaWrapper_manage_bufb (marpaWrapper_t *marpaWrapperp, void ***ppp, size_t *sizeip, size_t wantedNumberi, size_t elementSizei);
static void                  _marpaWrapper_free_bufb   (marpaWrapper_t *marpaWrapperp, void ***ppp, size_t *sizeip);

/* Stack helpers */
typedef struct marpaWrapperStackElementFreeData {
  marpaWrapper_t                        *marpaWrapperp;
  marpaWrapperStackElementFreeCallback_t stackElementFreeCallbackp;
  void                                  *stackElementFreeCallbackUserDatap;
} marpaWrapperStackElementFreeData_t;
typedef struct marpaWrapperStackElementCopyData {
  marpaWrapper_t                        *marpaWrapperp;
  marpaWrapperStackElementCopyCallback_t stackElementCopyCallbackp;
  void                                  *stackElementCopyCallbackUserDatap;
} marpaWrapperStackElementCopyData_t;
static void                  _marpaWrapperStackFailureCallback(genericStack_error_t errorType, int errorNumber, void *failureCallbackUserDatap);
static int                   _marpaWrapperStackFreeCallback(void *elementp, void *freeCallbackUserDatap);
static int                   _marpaWrapperStackCopyCallback(void *elementDstp, void *elementSrcp, void *copyCallbackUserDatap);
static void                  _marpaWrapper_log_any(marpaWrapper_t *marpaWrapperp, marpaWrapperLogLevel_t marpaWrapperLogLeveli, marpaWrapperErrorOrigin_t marpaWrapperErrorOrigini, int errorCodei, const char *fmts, ...);

/********************************************************************************************************/
/* marpaWrapper_newp                                                                                    */
/*                                                                                                      */
/* This is the only method where we might use marpaWrapper_log() instead of _marpaWrapper_logWrapper()  */
/********************************************************************************************************/
marpaWrapper_t *marpaWrapper_newp(marpaWrapperOption_t *marpaWrapperOptionp) {
  marpaWrapper_t      *marpaWrapperp;
  Marpa_Error_Code     marpaErrorCode;
  int                  marpaVersion[3];
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  marpaWrapperp = (marpaWrapper_t *) malloc(sizeof(marpaWrapper_t));
  if (marpaWrapperp == NULL) {
    marpaWrapper_log(marpaWrapperOption.logCallbackp,
		     marpaWrapperOption.logCallbackDatavp,
		     NULL,
		     marpaWrapperOption.logLevelWantedi,
		     MARPAWRAPPERERRORORIGIN_SYSTEM,
		     errno,
		     "malloc()",
		     MARPAWRAPPER_LOGLEVEL_ERROR);
    return NULL;
  }

  marpaWrapperp->marpaWrapperOption                = marpaWrapperOption;
  marpaWrapperp->marpaGrammarp                     = NULL;
  marpaWrapperp->marpaRecognizerp                  = NULL;
  marpaWrapperp->sizeMarpaWrapperSymboli           = 0;
  marpaWrapperp->nMarpaWrapperSymboli              = 0;
  marpaWrapperp->marpaWrapperSymbolpp              = NULL;
  marpaWrapperp->sizeMarpaWrapperRulei             = 0;
  marpaWrapperp->nMarpaWrapperRulei                = 0;
  marpaWrapperp->marpaWrapperRulepp                = NULL;
  marpaWrapperp->expectedMarpaSymbolIdArrayp       = NULL;
  marpaWrapperp->expectedMarpaWrapperSymbolArraypp = NULL;
  marpaWrapperp->sizeMarpaWrapperProgressi         = 0;
  marpaWrapperp->nMarpaWrapperProgressi            = 0;
  marpaWrapperp->marpaWrapperProgresspp            = NULL;

  /* From now on we can use marpaWrapperp */
  /* Get version anyway */
  MARPAWRAPPER_LOG_TRACEX("marpa_version(%p)", &(marpaVersion[0]));
  marpaErrorCode = marpa_version(&(marpaVersion[0]));
  if (marpaErrorCode < 0) {
    MARPAWRAPPER_LOG_MARPA_ERROR(marpaErrorCode)
    marpaWrapper_destroyv(&marpaWrapperp);
    return NULL;
  } else {
    MARPAWRAPPER_LOG_INFOX("libmarpa version is: %d.%d.%d", marpaVersion[0], marpaVersion[1], marpaVersion[2]);
  }

  /* Check version ? */
  if (marpaWrapperOption.versionip != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_check_version(%d, %d, %d)", (*(marpaWrapperOption.versionip))[0], (*(marpaWrapperOption.versionip))[1], (*(marpaWrapperOption.versionip))[2]);
    marpaErrorCode = marpa_check_version((*(marpaWrapperOption.versionip))[0],
					 (*(marpaWrapperOption.versionip))[1],
					 (*(marpaWrapperOption.versionip))[2]);
    if (marpaErrorCode != MARPA_ERR_NONE) {
      MARPAWRAPPER_LOG_MARPA_ERROR(marpaErrorCode);
      marpaWrapper_destroyv(&marpaWrapperp);
      return NULL;
    }
  }

  /* Initialize Marpa - always succeed as per the doc */
  MARPAWRAPPER_LOG_TRACEX("marpa_c_init(%p)", &(marpaWrapperp->marpaConfig));
  marpa_c_init(&(marpaWrapperp->marpaConfig));

  /* Create a grammar */
  MARPAWRAPPER_LOG_TRACEX("marpa_g_new(%p)", &(marpaWrapperp->marpaConfig));
  marpaWrapperp->marpaGrammarp = marpa_g_new(&(marpaWrapperp->marpaConfig));
  if (marpaWrapperp->marpaGrammarp == NULL) {
    MARPAWRAPPER_LOG_MARPA_C_ERROR;
    marpaWrapper_destroyv(&marpaWrapperp);
    return NULL;
  }

  /* Turn off obsolete features as per the doc */
  MARPAWRAPPER_LOG_TRACEX("marpa_g_force_valued(%p)", marpaWrapperp->marpaGrammarp);
  if (marpa_g_force_valued(marpaWrapperp->marpaGrammarp) < 0) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    marpaWrapper_destroyv(&marpaWrapperp);
    return NULL;
  }

  return marpaWrapperp;
}

/**************************/
/* marpaWrapper_destroyv  */
/**************************/
void marpaWrapper_destroyv(marpaWrapper_t **marpaWrapperpp) {
  marpaWrapper_t *marpaWrapperp;

  if (marpaWrapperpp != NULL) {
    marpaWrapperp = *marpaWrapperpp;
    if (marpaWrapperp != NULL) {
      if (marpaWrapperp->marpaRecognizerp != NULL) {
        MARPAWRAPPER_LOG_TRACEX("marpa_r_unref(%p)", marpaWrapperp->marpaRecognizerp);
        marpa_r_unref(marpaWrapperp->marpaRecognizerp);
      }
      if (marpaWrapperp->marpaGrammarp != NULL) {
        MARPAWRAPPER_LOG_TRACEX("marpa_g_unref(%p)", marpaWrapperp->marpaGrammarp);
        marpa_g_unref(marpaWrapperp->marpaGrammarp);
      }
      _marpaWrapper_free_bufb(marpaWrapperp, (void ***) &(marpaWrapperp->marpaWrapperSymbolpp), &(marpaWrapperp->sizeMarpaWrapperSymboli));
      _marpaWrapper_free_bufb(marpaWrapperp, (void ***) &(marpaWrapperp->marpaWrapperRulepp), &(marpaWrapperp->sizeMarpaWrapperRulei));
      /* In theory, this can be not NULL only if there is a recognizer alive */
      if (marpaWrapperp->expectedMarpaSymbolIdArrayp != NULL) {
        free(marpaWrapperp->expectedMarpaSymbolIdArrayp);
      }
      /* Idem */
      if (marpaWrapperp->expectedMarpaWrapperSymbolArraypp != NULL) {
        free(marpaWrapperp->expectedMarpaWrapperSymbolArraypp);
      }
      _marpaWrapper_free_bufb(marpaWrapperp, (void ***) &(marpaWrapperp->marpaWrapperProgresspp), &(marpaWrapperp->sizeMarpaWrapperProgressi));
      free(marpaWrapperp);
    }
    *marpaWrapperpp = NULL;
  }
}

/*******************************/
/* marpaWrapper_r_alternativeb */
/*******************************/
marpaWrapperBool_t marpaWrapper_r_alternativeb(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int value, int length) {

  if (marpaWrapperp == NULL || marpaWrapperSymbolp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_alternative(%p, %d, %d, %d)", marpaWrapperp->marpaRecognizerp, (int) marpaWrapperSymbolp->marpaSymbolIdi, value, length);
  if (marpa_r_alternative(marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi, value, length) != MARPA_ERR_NONE) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* marpaWrapper_r_readb */
/************************/
marpaWrapperBool_t marpaWrapper_r_readb(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int value, int length) {

  if (marpaWrapper_r_alternativeb(marpaWrapperp, marpaWrapperSymbolp, value, length) == MARPAWRAPPER_BOOL_TRUE) {
    return marpaWrapper_r_completeb(marpaWrapperp);
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}

/****************************/
/* marpaWrapper_r_completeb */
/****************************/
marpaWrapperBool_t marpaWrapper_r_completeb(marpaWrapper_t *marpaWrapperp) {

  if (marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_earleme_complete(%p)", marpaWrapperp->marpaRecognizerp);
  if (marpa_r_earleme_complete(marpaWrapperp->marpaRecognizerp) == -2) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Events can happen */
  return (_marpaWrapper_event(marpaWrapperp));
}

/***************************/
/* marpaWrapper_g_addSymbolp */
/***************************/
marpaWrapperSymbol_t *marpaWrapper_g_addSymbolp(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp) {
  Marpa_Symbol_ID marpaSymbolIdi;

  if (marpaWrapperp == NULL) {
    return NULL;
  }

  /* Create symbol */
  MARPAWRAPPER_LOG_TRACEX("marpa_g_symbol_new(%p)", marpaWrapperp->marpaGrammarp);
  marpaSymbolIdi = marpa_g_symbol_new(marpaWrapperp->marpaGrammarp);
  if (marpaSymbolIdi == -2) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return NULL;
  }

  /* Add it */
  return _marpaWrapper_g_addSymbolp(marpaWrapperp, marpaSymbolIdi, marpaWrapperSymbolOptionp);
}

/**************************************/
/* marpaWrapper_r_terminals_expectedb */
/**************************************/
marpaWrapperBool_t marpaWrapper_r_terminals_expectedb(marpaWrapper_t *marpaWrapperp, size_t *nMarpaWrapperSymbolip, marpaWrapperSymbol_t ***marpaWrapperSymbolppp) {
  int highestSymbolIdi;
  int nSymbolIdi;
  int i;

  if (marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->expectedMarpaSymbolIdArrayp == NULL) {
    /* Grammar is freezed per def. Fetch the maximum number of symbols once for this grammar */
    MARPAWRAPPER_LOG_TRACEX("marpa_g_highest_symbol_id(%p)", marpaWrapperp->marpaGrammarp);
    highestSymbolIdi = marpa_g_highest_symbol_id(marpaWrapperp->marpaGrammarp);
    if (highestSymbolIdi == -2) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperp->expectedMarpaSymbolIdArrayp = (Marpa_Symbol_ID *) malloc((highestSymbolIdi + 1) * sizeof(Marpa_Symbol_ID));
    if (marpaWrapperp->expectedMarpaSymbolIdArrayp == NULL) {
      MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* These two buffers are synchronized. No need to test on nullity of the following */
    marpaWrapperp->expectedMarpaWrapperSymbolArraypp = (marpaWrapperSymbol_t **) malloc((highestSymbolIdi + 1) * sizeof(marpaWrapperSymbol_t *));
    if (marpaWrapperp->expectedMarpaWrapperSymbolArraypp == NULL) {
      MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
      free(marpaWrapperp->expectedMarpaSymbolIdArrayp);
      marpaWrapperp->expectedMarpaSymbolIdArrayp = NULL;
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_terminals_expected(%p, %p)", marpaWrapperp->marpaRecognizerp, marpaWrapperp->expectedMarpaSymbolIdArrayp);
  nSymbolIdi = marpa_r_terminals_expected(marpaWrapperp->marpaRecognizerp, marpaWrapperp->expectedMarpaSymbolIdArrayp);
  if (nSymbolIdi == -2) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Fill preallocated buffer using the ids as a index */
  if (nSymbolIdi > 0) {
    for (i = 0; i < nSymbolIdi; i++) {
      marpaWrapperp->expectedMarpaWrapperSymbolArraypp[i] = marpaWrapperp->marpaWrapperSymbolpp[marpaWrapperp->expectedMarpaSymbolIdArrayp[i]];
    }
  }

  if (nMarpaWrapperSymbolip != NULL) {
    *nMarpaWrapperSymbolip = nSymbolIdi;
  }
  if (marpaWrapperSymbolppp != NULL) {
    *marpaWrapperSymbolppp = marpaWrapperp->expectedMarpaWrapperSymbolArraypp;
  }

  return MARPAWRAPPER_BOOL_TRUE;

}

/****************************************/
/* marpaWrapper_r_terminal_is_expectedb */
/****************************************/
marpaWrapperBool_t marpaWrapper_r_terminal_is_expectedb(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, marpaWrapperBool_t *isExpectedbp) {
  int isExpectedi;

  if (marpaWrapperp == NULL || marpaWrapperSymbolp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_terminal_is_expected(%p, %d)", marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi);
  isExpectedi = marpa_r_terminal_is_expected(marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi);
  if (isExpectedi == -2) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (isExpectedbp != NULL) {
    *isExpectedbp = (isExpectedi > 0) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/******************************/
/* _marpaWrapper_g_addSymbolp */
/******************************/
static marpaWrapperSymbol_t *_marpaWrapper_g_addSymbolp(marpaWrapper_t *marpaWrapperp, Marpa_Symbol_ID marpaSymbolIdi, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp) {
  marpaWrapperSymbol_t  *marpaWrapperSymbolp;
  size_t                 nMarpaWrapperSymboli = marpaSymbolIdi + 1;

  /* Allocate room for the new symbol */
  if (_marpaWrapper_manage_bufb(marpaWrapperp,
				(void ***) &(marpaWrapperp->marpaWrapperSymbolpp),
				&(marpaWrapperp->sizeMarpaWrapperSymboli),
				nMarpaWrapperSymboli,
				sizeof(marpaWrapperSymbol_t *)) != MARPAWRAPPER_BOOL_TRUE) {
    return NULL;
  }

  marpaWrapperSymbolp = (marpaWrapperSymbol_t *) malloc(sizeof(marpaWrapperSymbol_t));
  if (marpaWrapperSymbolp == NULL) {
    MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
    return NULL;
  }
  marpaWrapperp->nMarpaWrapperSymboli = nMarpaWrapperSymboli;
  marpaWrapperp->marpaWrapperSymbolpp[marpaSymbolIdi] = marpaWrapperSymbolp;

  /* Fill the defaults */
  marpaWrapperSymbolp->marpaSymbolIdi = marpaSymbolIdi;
  marpaWrapperSymbolp->marpaWrapperRulep = NULL;
  marpaWrapperSymbolp->marpaWrapperp = marpaWrapperp;
  if (marpaWrapperSymbolOptionp == NULL) {
    marpaWrapper_symbolOptionDefaultb(&(marpaWrapperSymbolp->marpaWrapperSymbolOption));
  } else {
    marpaWrapperSymbolp->marpaWrapperSymbolOption = *marpaWrapperSymbolOptionp;
  }

  /* Apply options */
  if (marpaWrapperSymbolp->marpaWrapperSymbolOption.terminalb == MARPAWRAPPER_BOOL_TRUE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_symbol_is_terminal_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, (int) marpaWrapperSymbolp->marpaSymbolIdi, (int) 1);
    if (marpa_g_symbol_is_terminal_set(marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1) != 1) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }
  if (marpaWrapperSymbolp->marpaWrapperSymbolOption.startb == MARPAWRAPPER_BOOL_TRUE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_start_symbol_set(%p, %d)", marpaWrapperp->marpaGrammarp, (int) marpaWrapperSymbolp->marpaSymbolIdi);
    if (marpa_g_start_symbol_set(marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi) < 0) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }
  if ((marpaWrapperSymbolp->marpaWrapperSymbolOption.eventSeti & MARPAWRAPPER_EVENTTYPE_COMPLETED) == MARPAWRAPPER_EVENTTYPE_COMPLETED) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_symbol_is_completion_event_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, (int) marpaWrapperSymbolp->marpaSymbolIdi, (int) 1);
    if (marpa_g_symbol_is_completion_event_set(marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1) != 1) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }
  if ((marpaWrapperSymbolp->marpaWrapperSymbolOption.eventSeti & MARPAWRAPPER_EVENTTYPE_NULLED) == MARPAWRAPPER_EVENTTYPE_NULLED) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_symbol_is_nulled_event_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1);
    if (marpa_g_symbol_is_nulled_event_set(marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1) != 1) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }
  if ((marpaWrapperSymbolp->marpaWrapperSymbolOption.eventSeti & MARPAWRAPPER_EVENTTYPE_PREDICTED) == MARPAWRAPPER_EVENTTYPE_PREDICTED) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_symbol_is_prediction_event_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1);
    if (marpa_g_symbol_is_prediction_event_set(marpaWrapperp->marpaGrammarp, marpaWrapperSymbolp->marpaSymbolIdi, 1) != 1) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }

  return marpaWrapperSymbolp;
}

/**********************************/
/* marpaWrapper_r_event_activateb */
/**********************************/
marpaWrapperBool_t marpaWrapper_r_event_activateb(marpaWrapper_t *marpaWrapperp, marpaWrapperSymbol_t *marpaWrapperSymbolp, int eventSeti, marpaWrapperBool_t onb) {
  int booleani = (onb == MARPAWRAPPER_BOOL_TRUE) ? 1 : 0;

  if (marpaWrapperp == NULL || marpaWrapperSymbolp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if ((eventSeti & MARPAWRAPPER_EVENTTYPE_COMPLETED) == MARPAWRAPPER_EVENTTYPE_COMPLETED) {
    if (marpa_r_completion_symbol_activate(marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi, booleani) != booleani) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  if ((eventSeti & MARPAWRAPPER_EVENTTYPE_NULLED) == MARPAWRAPPER_EVENTTYPE_NULLED) {
    if (marpa_r_nulled_symbol_activate(marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi, booleani) != booleani) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  if ((eventSeti & MARPAWRAPPER_EVENTTYPE_PREDICTED) == MARPAWRAPPER_EVENTTYPE_PREDICTED) {
    if (marpa_r_prediction_symbol_activate(marpaWrapperp->marpaRecognizerp, marpaWrapperSymbolp->marpaSymbolIdi, booleani) != booleani) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/***************************/
/* marpaWrapper_g_addRulep */
/***************************/
marpaWrapperRule_t *marpaWrapper_g_addRulep(marpaWrapper_t *marpaWrapperp, marpaWrapperRuleOption_t *marpaWrapperRuleOptionp, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp) {
  Marpa_Symbol_ID    *rhsIdp = NULL;
  Marpa_Rule_ID       marpaRuleIdi;
  size_t              i;
  int                 sequenceFlagsi;
  int                 separatorSymbolIdi;

  if (marpaWrapperp == NULL) {
    return NULL;
  }

  if (marpaWrapperRuleOptionp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("marpaWrapperRuleOptionp is NULL");
    return NULL;
  }
  if (marpaWrapperRuleOptionp->lhsSymbolp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("marpaWrapperRuleOptionp->lhsSymbolp is NULL");
    return NULL;
  }
  if (marpaWrapperRuleOptionp->sequenceb == MARPAWRAPPER_BOOL_TRUE) {
    if (marpaWrapperRuleOptionp->nRhsSymboli != 1) {
      MARPAWRAPPER_LOG_ERROR0("A sequence must have exactly one RHS");
      return NULL;
    }
    if (marpaWrapperRuleOptionp->minimumi != 0 && marpaWrapperRuleOptionp->minimumi != 1) {
      MARPAWRAPPER_LOG_ERROR0("A sequence must have a minimum of exactly 0 or 1");
      return NULL;
    }
  }

  if (marpaWrapperRuleOptionp->nRhsSymboli > 0) {
    rhsIdp = (Marpa_Symbol_ID *) malloc(marpaWrapperRuleOptionp->nRhsSymboli * sizeof(Marpa_Symbol_ID));
    if (rhsIdp == NULL) {
      MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
      return NULL;
    }
    for (i = 0; i < marpaWrapperRuleOptionp->nRhsSymboli; i++) {
      rhsIdp[i] = marpaWrapperRuleOptionp->rhsSymbolpp[i]->marpaSymbolIdi;
    }
  }

  /* Create rule */
  if (marpaWrapperRuleOptionp->sequenceb == MARPAWRAPPER_BOOL_TRUE) {
    sequenceFlagsi = 0;
    separatorSymbolIdi = marpaWrapperRuleOptionp->separatorSymbolp != NULL ? marpaWrapperRuleOptionp->separatorSymbolp->marpaSymbolIdi : -1;
    if (marpaWrapperRuleOptionp->properb == MARPAWRAPPER_BOOL_TRUE) {
      sequenceFlagsi |= MARPA_PROPER_SEPARATION;
    }
    MARPAWRAPPER_LOG_TRACEX("marpa_g_sequence_new(%p, %d, %d, %d, %d, %d)", marpaWrapperp->marpaGrammarp, (int) marpaWrapperRuleOptionp->lhsSymbolp->marpaSymbolIdi, (int) rhsIdp[0], (int) separatorSymbolIdi, marpaWrapperRuleOptionp->minimumi, sequenceFlagsi);
    marpaRuleIdi = marpa_g_sequence_new(marpaWrapperp->marpaGrammarp,
					marpaWrapperRuleOptionp->lhsSymbolp->marpaSymbolIdi,
					rhsIdp[0],
					separatorSymbolIdi,
					marpaWrapperRuleOptionp->minimumi,
					sequenceFlagsi);
  } else {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_rule_new(%p, %d, %p, %d)", marpaWrapperp->marpaGrammarp, (int) marpaWrapperRuleOptionp->lhsSymbolp->marpaSymbolIdi, rhsIdp, (int) marpaWrapperRuleOptionp->nRhsSymboli);
    marpaRuleIdi = marpa_g_rule_new(marpaWrapperp->marpaGrammarp,
				    marpaWrapperRuleOptionp->lhsSymbolp->marpaSymbolIdi,
				    rhsIdp,
				    marpaWrapperRuleOptionp->nRhsSymboli);
  }

  if (rhsIdp != NULL) {
    free(rhsIdp);
    rhsIdp = NULL;
  }

  if (marpaRuleIdi == -2) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return NULL;
  }

  /* Add it */
  return _marpaWrapper_g_addRulep(marpaWrapperp, marpaRuleIdi, marpaWrapperRuleOptionp, marpaWrapperSymbolOptionp);
}

/**************************/
/* _marpaWrapper_g_addRulep */
/**************************/
static marpaWrapperRule_t *_marpaWrapper_g_addRulep(marpaWrapper_t *marpaWrapperp, Marpa_Rule_ID marpaRuleIdi, marpaWrapperRuleOption_t *marpaWrapperRuleOptionp, marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp) {
  Marpa_Symbol_ID       marpaSymbolidi;
  marpaWrapperRule_t   *marpaWrapperRulep;
  size_t                nMarpaWrapperRulei = marpaRuleIdi + 1;

  /* Allocate room for the new rule */
  if (_marpaWrapper_manage_bufb(marpaWrapperp,
				(void ***) &(marpaWrapperp->marpaWrapperRulepp),
				&(marpaWrapperp->sizeMarpaWrapperRulei),
				nMarpaWrapperRulei,
				sizeof(marpaWrapperRule_t *)) != MARPAWRAPPER_BOOL_TRUE) {
    return NULL;
  }

  marpaWrapperRulep = (marpaWrapperRule_t *) malloc(sizeof(marpaWrapperRule_t));
  if (marpaWrapperRulep == NULL) {
    MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
    return NULL;
  }
  marpaWrapperp->nMarpaWrapperRulei = nMarpaWrapperRulei;
  marpaWrapperp->marpaWrapperRulepp[marpaRuleIdi] = marpaWrapperRulep;

  /* Per def, marpaWrapperRuleOptionp is != NULL */
  marpaWrapperRulep->marpaRuleIdi = marpaRuleIdi;
  marpaWrapperRulep->marpaWrapperSymbolp = NULL;
  marpaWrapperRulep->marpaWrapperp = marpaWrapperp;
  marpaWrapperRulep->marpaWrapperRuleOption = *marpaWrapperRuleOptionp;

  /* Apply options */
  if (marpaWrapperRuleOptionp->ranki != 0) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_rule_rank_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, (int) marpaRuleIdi, marpaWrapperRuleOptionp->ranki);
    marpa_g_rule_rank_set(marpaWrapperp->marpaGrammarp, marpaRuleIdi, marpaWrapperRuleOptionp->ranki);
    if (marpa_g_error(marpaWrapperp->marpaGrammarp, NULL) != MARPA_ERR_NONE) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }
  if (marpaWrapperRuleOptionp->nullRanksHighb == MARPAWRAPPER_BOOL_TRUE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_g_rule_null_high_set(%p, %d, %d)", marpaWrapperp->marpaGrammarp, (int) marpaRuleIdi, 1);
    if (marpa_g_rule_null_high_set(marpaWrapperp->marpaGrammarp, marpaRuleIdi, 1) == -2) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
    }
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_g_rule_lhs(%p, %d)", marpaWrapperp->marpaGrammarp, (int) marpaRuleIdi);
  marpaSymbolidi = marpa_g_rule_lhs(marpaWrapperp->marpaGrammarp, marpaRuleIdi);
  if (marpaSymbolidi < 0) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      return NULL;
  }

  marpaWrapperRulep->marpaWrapperSymbolp = _marpaWrapper_g_addSymbolp(marpaWrapperp, marpaSymbolidi, marpaWrapperSymbolOptionp);
  if (marpaWrapperRulep->marpaWrapperSymbolp == NULL) {
    return NULL;
  }

  marpaWrapperRulep->marpaWrapperSymbolp->marpaWrapperRulep = marpaWrapperRulep;

  return marpaWrapperRulep;
}

/*********************************************************************************/
/* marpaWrapper_vb                                                               */
/*                                                                               */
/* This method explicitely returns ONLY at the end. And use exceptionnaly a goto */
/* to avoid repetition of marpa_xxx_unref().                                     */
/*********************************************************************************/
marpaWrapperBool_t marpaWrapper_vb(marpaWrapper_t *marpaWrapperp, marpaWrapperValueOption_t *marpaWrapperValueOptionp, marpaWrapperStackOption_t *marpaWrapperStackOptionp) {
  marpaWrapperValueOption_t          marpaWrapperValueOption;
  Marpa_Earley_Set_ID                marpaLatestEarleySetIdi;
  Marpa_Bocage                       marpaBocagep = NULL;
  Marpa_Order                        marpaOrderp = NULL;
  Marpa_Tree                         marpaTreep = NULL;
  Marpa_Value                        marpaValuep = NULL;
  Marpa_Step_Type                    marpaStepTypei;
  Marpa_Rule_ID                      marpaRuleIdi;
  Marpa_Symbol_ID                    marpaSymbolIdi;
  genericStack_t                    *genericStackp = NULL;
  int                                argFirsti;
  int                                argLasti;
  int                                argResulti;
  size_t                             nValueInputi;
  void                             **valueInputArraypp = NULL;
  void                              *valueOutputp;
  int                                valueOutputFreeStatusi;
  marpaWrapperBool_t                 nextb;
  marpaWrapperBool_t                 rcb = MARPAWRAPPER_BOOL_TRUE;
  size_t                             i;
  marpaWrapperValueBool_t            valueRcb;
  genericStack_option_t              genericStackOption;
  marpaWrapperStackElementFreeData_t marpaWrapperStackElementFreeData;
  marpaWrapperStackElementCopyData_t marpaWrapperStackElementCopyData;
  int                                tokenValuei;
  int                                highRankOnlyFlagi;
  int                                treeNexti;
  
  if (marpaWrapperp == NULL) {
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  if (marpaWrapperStackOptionp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("marpaWrapperStackOptionp is NULL");
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  /* Fill defaults */
  if (marpaWrapperValueOptionp == NULL) {
    marpaWrapper_valueOptionDefaultb(&marpaWrapperValueOption);
  } else {
    marpaWrapperValueOption = *marpaWrapperValueOptionp;
  }

  marpaWrapperStackElementFreeData.marpaWrapperp                     = marpaWrapperp;
  marpaWrapperStackElementFreeData.stackElementFreeCallbackp         = marpaWrapperStackOptionp->stackElementFreeCallbackp;
  marpaWrapperStackElementFreeData.stackElementFreeCallbackUserDatap = marpaWrapperStackOptionp->stackElementFreeCallbackUserDatap;

  marpaWrapperStackElementCopyData.marpaWrapperp                     = marpaWrapperp;
  marpaWrapperStackElementCopyData.stackElementCopyCallbackp         = marpaWrapperStackOptionp->stackElementCopyCallbackp;
  marpaWrapperStackElementCopyData.stackElementCopyCallbackUserDatap = marpaWrapperStackOptionp->stackElementCopyCallbackUserDatap;

  genericStackOption.growFlags                = GENERICSTACK_OPTION_GROW_DEFAULT;
  genericStackOption.failureCallbackp         = &_marpaWrapperStackFailureCallback;
  genericStackOption.failureCallbackUserDatap = marpaWrapperp;
  genericStackOption.freeCallbackp            = &_marpaWrapperStackFreeCallback;
  genericStackOption.freeCallbackUserDatap    = &marpaWrapperStackElementFreeData;
  genericStackOption.copyCallbackp            = &_marpaWrapperStackCopyCallback;
  genericStackOption.copyCallbackUserDatap    = &marpaWrapperStackElementCopyData;

  /* This function always succeed as per doc */
  MARPAWRAPPER_LOG_TRACEX("marpa_r_latest_earley_set(%p)", marpaWrapperp->marpaRecognizerp);
  marpaLatestEarleySetIdi = marpa_r_latest_earley_set(marpaWrapperp->marpaRecognizerp);

  MARPAWRAPPER_LOG_TRACEX("marpa_b_new(%p, %d)", marpaWrapperp->marpaRecognizerp, (int) marpaLatestEarleySetIdi);
  marpaBocagep = marpa_b_new(marpaWrapperp->marpaRecognizerp, marpaLatestEarleySetIdi);
  if (marpaBocagep == NULL) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_o_new(%p)", marpaBocagep);
  marpaOrderp = marpa_o_new(marpaBocagep);
  if (marpaOrderp == NULL) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  highRankOnlyFlagi = (marpaWrapperValueOption.highRankOnlyb == MARPAWRAPPER_BOOL_TRUE) ? 1 : 0;
  MARPAWRAPPER_LOG_TRACEX("marpa_o_high_rank_only_set(%p, %d)", marpaOrderp, highRankOnlyFlagi);
  if (marpa_o_high_rank_only_set(marpaOrderp, highRankOnlyFlagi) != highRankOnlyFlagi) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  if (marpaWrapperValueOption.orderByRankb == MARPAWRAPPER_BOOL_TRUE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_o_rank(%p)", marpaOrderp);
    if (marpa_o_rank(marpaOrderp) == -2) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }
  }

  if (marpaWrapperValueOption.ambiguityb == MARPAWRAPPER_BOOL_FALSE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_o_ambiguity_metric(%p)", marpaOrderp);
    if (marpa_o_ambiguity_metric(marpaOrderp) > 1) {
      MARPAWRAPPER_LOG_ERROR0("Ambiguous parse detected after bocage");
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }
  }

  if (marpaWrapperValueOption.nullb == MARPAWRAPPER_BOOL_FALSE) {
    MARPAWRAPPER_LOG_TRACEX("marpa_o_is_null(%p)", marpaOrderp);
    if (marpa_o_is_null(marpaOrderp) >= 1) {
      MARPAWRAPPER_LOG_ERROR0("Null parse detected after bocage");
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_t_new(%p)", marpaOrderp);
  marpaTreep = marpa_t_new(marpaOrderp);
  if (marpaTreep == NULL) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    rcb = MARPAWRAPPER_BOOL_FALSE;
    goto marpaWrapper_v_end_label;
  }

  while (1) {
    MARPAWRAPPER_LOG_TRACEX("marpa_t_next(%p)", marpaTreep);
    treeNexti = marpa_t_next(marpaTreep);
    if (treeNexti < 0) {
      break;
    }

    nextb = MARPAWRAPPER_BOOL_TRUE;

    MARPAWRAPPER_LOG_TRACEX("marpa_v_new(%p)", marpaTreep);
    marpaValuep = marpa_v_new(marpaTreep);
    if (marpaValuep == NULL) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }

    MARPAWRAPPER_LOG_TRACEX("marpa_v_valued_force(%p)", marpaValuep);
    if (marpa_v_valued_force(marpaValuep) < 0) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }

    genericStackp = genericStack_newp(marpaWrapperStackOptionp->stackElementSizei, &genericStackOption);
    if (genericStackp == NULL) {
      /* In theory genericStack should also have called our logging wrapper */
      rcb = MARPAWRAPPER_BOOL_FALSE;
      goto marpaWrapper_v_end_label;
    }

    while (nextb == MARPAWRAPPER_BOOL_TRUE) {
      MARPAWRAPPER_LOG_TRACEX("marpa_v_step(%p)", marpaValuep);
      marpaStepTypei = marpa_v_step(marpaValuep);
      valueOutputp = NULL;

      switch(marpaStepTypei) {
      case MARPA_STEP_RULE:

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: marpa_v_rule(%p)", marpaValuep);
	marpaRuleIdi = marpa_v_rule(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: marpa_v_arg_0(%p)", marpaValuep);
	argFirsti = marpa_v_arg_0(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: marpa_v_arg_n(%p)", marpaValuep);
	argLasti = marpa_v_arg_n(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: marpa_v_result(%p)", marpaValuep);
	argResulti = marpa_v_result(marpaValuep);

	nValueInputi = argLasti - argFirsti + 1;
	valueOutputp = NULL;

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: Stack [%d..%d] -> Stack %d", argFirsti, argLasti, argResulti);

	valueInputArraypp = (void **) malloc(nValueInputi * sizeof(void *));
	if (valueInputArraypp == NULL) {
	  MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
	  rcb = MARPAWRAPPER_BOOL_FALSE;
	  goto marpaWrapper_v_end_label;
	}
	for (i = 0; i < nValueInputi; i++) {
	  valueInputArraypp[i] = genericStack_getp(genericStackp, argFirsti + i);
	}
	if (marpaWrapperValueOption.valueRuleCallbackp != NULL) {
	  MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_RULE: valueRuleCallbackp(%p, %p, %p, %d, %p, %p)",
				  marpaWrapperValueOption.valueRuleCallbackDatavp,
				  marpaWrapperp,
				  marpaWrapperp->marpaWrapperRulepp[marpaRuleIdi],
				  nValueInputi,
				  valueInputArraypp,
				  &valueOutputp);
	  if ((*marpaWrapperValueOption.valueRuleCallbackp)
	      (
	       marpaWrapperValueOption.valueRuleCallbackDatavp,
	       marpaWrapperp,
	       marpaWrapperp->marpaWrapperRulepp[marpaRuleIdi],
	       nValueInputi,
	       valueInputArraypp,
	       &valueOutputp) == MARPAWRAPPER_BOOL_FALSE) {
	    MARPAWRAPPER_LOG_ERROR0("valueRuleCallbackp() failure");
	    rcb = MARPAWRAPPER_BOOL_FALSE;
	    goto marpaWrapper_v_end_label;
	  }
	}
	free(valueInputArraypp);
	valueInputArraypp = NULL;

	if (genericStack_seti(genericStackp, argResulti, valueOutputp) <= 0) {
	  rcb = MARPAWRAPPER_BOOL_FALSE;
	  goto marpaWrapper_v_end_label;
	}

	break;
      case MARPA_STEP_TOKEN:

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_TOKEN: marpa_v_token(%p)", marpaValuep);
	marpaSymbolIdi = marpa_v_token(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_TOKEN: marpa_v_token_value(%p)", marpaValuep);
        tokenValuei = marpa_v_token_value(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_TOKEN: marpa_v_result(%p)", marpaValuep);
	argResulti = marpa_v_result(marpaValuep);

	valueOutputp = NULL;

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_TOKEN: Token value %d -> Stack %d", tokenValuei, argResulti);

	if (marpaWrapperValueOption.valueSymbolCallbackp != NULL) {
	  MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_TOKEN: valueSymbolCallbackp(%p, %p, %p, %d, %p)",
				  marpaWrapperValueOption.valueSymbolCallbackDatavp,
				  marpaWrapperp,
				  marpaWrapperp->marpaWrapperSymbolpp[marpaSymbolIdi],
				  tokenValuei,
				  &valueOutputp);
	  if ((*marpaWrapperValueOption.valueSymbolCallbackp)
	      (
	       marpaWrapperValueOption.valueSymbolCallbackDatavp,
	       marpaWrapperp,
	       marpaWrapperp->marpaWrapperSymbolpp[marpaSymbolIdi],
               tokenValuei,
	       &valueOutputp) == MARPAWRAPPER_BOOL_FALSE) {
	    MARPAWRAPPER_LOG_ERROR0("valueSymbolCallbackp() failure");
	    rcb = MARPAWRAPPER_BOOL_FALSE;
	    goto marpaWrapper_v_end_label;
	  }
	}

	if (genericStack_seti(genericStackp, argResulti, valueOutputp) <= 0) {
	  rcb = MARPAWRAPPER_BOOL_FALSE;
	  goto marpaWrapper_v_end_label;
	}

	break;
      case MARPA_STEP_NULLING_SYMBOL:

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_NULLING_SYMBOL: marpa_v_symbol(%p)", marpaValuep);
	marpaSymbolIdi = marpa_v_symbol(marpaValuep);

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_NULLING_SYMBOL: marpa_v_result(%p)", marpaValuep);
	argResulti   = marpa_v_result(marpaValuep);

	valueOutputp = NULL;

        MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_NULLING_SYMBOL: Stack %d", argResulti);

	if (marpaWrapperValueOption.valueNullingCallbackp != NULL) {
	  MARPAWRAPPER_LOG_TRACEX("MARPA_STEP_NULLING_SYMBOL: valueNullingCallbackp(%p, %p, %p, %p)",
				  marpaWrapperValueOption.valueNullingCallbackDatavp,
				  marpaWrapperp,
				  marpaWrapperp->marpaWrapperSymbolpp[marpaSymbolIdi],
				  &valueOutputp);
	  if ((*marpaWrapperValueOption.valueNullingCallbackp)
	      (
	       marpaWrapperValueOption.valueNullingCallbackDatavp,
	       marpaWrapperp,
	       marpaWrapperp->marpaWrapperSymbolpp[marpaSymbolIdi],
	       &valueOutputp) == MARPAWRAPPER_BOOL_FALSE) {
	    MARPAWRAPPER_LOG_ERROR0("valueNullingCallbackp() failure");
	    rcb = MARPAWRAPPER_BOOL_FALSE;
	    goto marpaWrapper_v_end_label;
	  }
	}

	if (genericStack_seti(genericStackp, argResulti, valueOutputp) <= 0) {
	  rcb = MARPAWRAPPER_BOOL_FALSE;
	  goto marpaWrapper_v_end_label;
	}

	break;
      case MARPA_STEP_INACTIVE:
        MARPAWRAPPER_LOG_TRACE0("MARPA_STEP_INACTIVE");
	nextb = MARPAWRAPPER_BOOL_FALSE;
	break;
      case MARPA_STEP_INITIAL:
        MARPAWRAPPER_LOG_TRACE0("MARPA_STEP_INITIAL");
	break;
      default:
	break;
      }

      if (valueOutputp != NULL) {
        valueOutputFreeStatusi = _marpaWrapperStackFreeCallback(valueOutputp, &marpaWrapperStackElementFreeData);
        if (valueOutputFreeStatusi != 0) {
          rcb = MARPAWRAPPER_BOOL_FALSE;
          goto marpaWrapper_v_end_label;
        }
        free(valueOutputp);
        valueOutputp = NULL;
      }

    }
    
    if (marpaWrapperValueOption.valueResultCallbackp != NULL) {
      MARPAWRAPPER_LOG_TRACEX("valueResultCallbackp(%p, %p, %p)",
			      marpaWrapperValueOption.valueResultCallbackDatavp,
			      marpaWrapperp,
			      genericStack_getp(genericStackp, 0));
      valueRcb = (*marpaWrapperValueOption.valueResultCallbackp)
	(
	 marpaWrapperValueOption.valueResultCallbackDatavp,
         marpaWrapperp,
	 genericStack_getp(genericStackp, 0));
      if (valueRcb == MARPAWRAPPER_VALUECALLBACKBOOL_FALSE) {
	MARPAWRAPPER_LOG_ERROR0("valueResultCallbackp() failure");
	rcb = MARPAWRAPPER_BOOL_FALSE;
	goto marpaWrapper_v_end_label;
      } else if (valueRcb == MARPAWRAPPER_VALUECALLBACKBOOL_STOP) {
	goto marpaWrapper_v_end_label;
      }
    }

    genericStack_destroyv(&genericStackp);
    MARPAWRAPPER_LOG_TRACEX("marpa_v_unref(%p)", marpaValuep);
    marpa_v_unref(marpaValuep);
    marpaValuep = NULL;

  }

 marpaWrapper_v_end_label:
  if (valueOutputp      != NULL) {
    free(valueOutputp);
  }
  if (valueInputArraypp != NULL) {
    free(valueInputArraypp);
  }
  if (genericStackp     != NULL) {
    genericStack_destroyv(&genericStackp);
  }
  if (marpaValuep       != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_v_unref(%p)", marpaValuep);
    marpa_v_unref(marpaValuep);
  }
  if (marpaTreep        != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_t_unref(%p)", marpaTreep);
    marpa_t_unref(marpaTreep);
  }
  if (marpaOrderp       != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_o_unref(%p)", marpaOrderp);
    marpa_o_unref(marpaOrderp);
  }
  if (marpaBocagep      != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_b_unref(%p)", marpaBocagep);
    marpa_b_unref(marpaBocagep);
  }

  return rcb;
}

/****************************/
/* marpaWrapper_g_precomputeb */
/****************************/
marpaWrapperBool_t marpaWrapper_g_precomputeb(marpaWrapper_t *marpaWrapperp) {

  if (marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_g_precompute(%p)", marpaWrapperp->marpaGrammarp);
  if (marpa_g_precompute(marpaWrapperp->marpaGrammarp) < 0) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Events can happen */
  return (_marpaWrapper_event(marpaWrapperp));
}

/*************************/
/* marpaWrapper_r_startb */
/*************************/
marpaWrapperBool_t  marpaWrapper_r_startb(marpaWrapper_t *marpaWrapperp) {

  if (marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp != NULL) {
    MARPAWRAPPER_LOG_TRACEX("marpa_r_unref(%p)", marpaWrapperp->marpaRecognizerp);
    marpa_r_unref(marpaWrapperp->marpaRecognizerp);
    if (marpaWrapperp->expectedMarpaSymbolIdArrayp != NULL) {
      free(marpaWrapperp->expectedMarpaSymbolIdArrayp);
      marpaWrapperp->expectedMarpaSymbolIdArrayp = NULL;
    }
    if (marpaWrapperp->expectedMarpaWrapperSymbolArraypp != NULL) {
      free(marpaWrapperp->expectedMarpaWrapperSymbolArraypp);
      marpaWrapperp->expectedMarpaWrapperSymbolArraypp = NULL;
    }
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_new(%p)", marpaWrapperp->marpaGrammarp);
  marpaWrapperp->marpaRecognizerp = marpa_r_new(marpaWrapperp->marpaGrammarp);
  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_start_input(%p)", marpaWrapperp->marpaRecognizerp);
  if (marpa_r_start_input(marpaWrapperp->marpaRecognizerp) < 0) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Events can happen */
  return (_marpaWrapper_event(marpaWrapperp));
}

/*****************************/
/* _marpaWrapper_logCallback */
/*****************************/
static void _marpaWrapper_logCallback(void *logCallbackDatavp, marpaWrapper_t *marpaWrapperp, marpaWrapperLogLevel_t logLeveli, const char *msgs) {
  const char *prefix;

  switch (logLeveli) {
  case MARPAWRAPPER_LOGLEVEL_TRACE:     prefix = "TRACE";     break;
  case MARPAWRAPPER_LOGLEVEL_DEBUG:     prefix = "DEBUG";     break;
  case MARPAWRAPPER_LOGLEVEL_INFO:      prefix = "INFO";      break;
  case MARPAWRAPPER_LOGLEVEL_NOTICE:    prefix = "NOTICE";    break;
  case MARPAWRAPPER_LOGLEVEL_WARNING:   prefix = "WARNING";   break;
  case MARPAWRAPPER_LOGLEVEL_ERROR:     prefix = "ERROR";     break;
  case MARPAWRAPPER_LOGLEVEL_CRITICAL:  prefix = "CRITICAL";  break;
  case MARPAWRAPPER_LOGLEVEL_ALERT:     prefix = "ALERT";     break;
  case MARPAWRAPPER_LOGLEVEL_EMERGENCY: prefix = "EMERGENCY"; break;
  default:                              prefix = "UNKNOWN";   break;
  }

  fprintf(stderr, "[%9s] %s\n", prefix, (msgs != NULL) ? msgs : "No message");
}

/****************************/
/* _marpaWrapper_logWrapper */
/****************************/
static void _marpaWrapper_logWrapper(marpaWrapper_t           *marpaWrapperp,
				     marpaWrapperErrorOrigin_t errorOrigini,
				     int                       errorNumberi,
				     const char               *calls,
				     marpaWrapperLogLevel_t    logLeveli) {
  if (marpaWrapperp != NULL) {
    marpaWrapper_log(marpaWrapperp->marpaWrapperOption.logCallbackp,
		     marpaWrapperp->marpaWrapperOption.logCallbackDatavp,
		     marpaWrapperp,
		     marpaWrapperp->marpaWrapperOption.logLevelWantedi,
		     errorOrigini,
		     errorNumberi,
		     calls,
		     logLeveli);
  }
}

/********************/
/* marpaWrapper_log */
/********************/
void marpaWrapper_log(marpaWrapperLogCallback_t logCallbackp,
		      void                     *logCallbackDatavp,
		      marpaWrapper_t           *marpaWrapperp,
		      marpaWrapperLogLevel_t    logLevelWantedi,
		      marpaWrapperErrorOrigin_t errorOrigini,
		      int                       errorNumberi,
		      const char               *calls,
		      marpaWrapperLogLevel_t    logLeveli) {
  char *msgs;
  const char *strerrors;

  if (logCallbackp == NULL) {
    logCallbackp = &_marpaWrapper_logCallback;
    logCallbackDatavp = NULL;
  }

  if (logLeveli >= logLevelWantedi) {

    strerrors = _marpaWrapper_strerror(errorOrigini, errorNumberi);
    if (strlen(strerrors) > 0) {
      if (calls != NULL) {
        msgs = messageBuilder("%s: %s", calls, strerrors);
      } else {
        msgs = messageBuilder("%s", strerrors);
      }
    } else {
      msgs = messageBuilder("%s", calls != NULL ? calls : "Unknown call");
    }
    if (msgs != messageBuilder_internalErrors()) {
      logCallbackp(logCallbackDatavp, marpaWrapperp, logLeveli, msgs);
      free(msgs);
    } else {
      logCallbackp(logCallbackDatavp, marpaWrapperp, MARPAWRAPPER_LOGLEVEL_ERROR, msgs);
    }
  }

}

/*************************/
/* _marpaWrapper_log_any */
/*************************/
static void _marpaWrapper_log_any(marpaWrapper_t *marpaWrapperp, marpaWrapperLogLevel_t marpaWrapperLogLeveli, marpaWrapperErrorOrigin_t marpaWrapperErrorOrigini, int errorCodei, const char *fmts, ...) {
  va_list      ap;
#ifndef _WIN32
  va_list      ap2;
#endif
  char        *msgs;
  static char *emptyMessages = "Empty message";

  va_start(ap, fmts);
#ifndef _WIN32
  va_copy(ap2, ap);
  msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap2) : emptyMessages;
  va_end(ap2);
#else
  msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap) : emptyMessages;
#endif
  va_end(ap);

  _marpaWrapper_logWrapper(marpaWrapperp,
			   marpaWrapperErrorOrigini,
			   errorCodei,
			   msgs,
			   marpaWrapperLogLeveli);
  if (msgs != emptyMessages && msgs != messageBuilder_internalErrors()) {
    free(msgs);
  }
}

/***************************/
/* _marpaWrapper_strerror */
/***************************/
static const char *_marpaWrapper_strerror(marpaWrapperErrorOrigin_t errorOrigini, int errorNumberi) {
  switch (errorOrigini) {

  case MARPAWRAPPERERRORORIGIN_SYSTEM:             return strerror(errorNumberi);

  case MARPAWRAPPERERRORORIGIN_NA:                 return "";

  case MARPAWRAPPERERRORORIGIN_MARPA:

    switch (errorNumberi) {

    case MARPA_ERR_NONE:                           return "MARPA_ERR_NONE: No error";
    case MARPA_ERR_AHFA_IX_NEGATIVE:               return "MARPA_ERR_AHFA_IX_NEGATIVE";
    case MARPA_ERR_AHFA_IX_OOB:                    return "MARPA_ERR_AHFA_IX_OOB";
    case MARPA_ERR_ANDID_NEGATIVE:                 return "MARPA_ERR_ANDID_NEGATIVE";
    case MARPA_ERR_ANDID_NOT_IN_OR:                return "MARPA_ERR_ANDID_NOT_IN_OR";
    case MARPA_ERR_ANDIX_NEGATIVE:                 return "MARPA_ERR_ANDIX_NEGATIVE";
    case MARPA_ERR_BAD_SEPARATOR:                  return "MARPA_ERR_BAD_SEPARATOR: Separator has invalid symbol ID";
    case MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED:     return "MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED";
    case MARPA_ERR_COUNTED_NULLABLE:               return "MARPA_ERR_COUNTED_NULLABLE: Nullable symbol on RHS of a sequence rule";
    case MARPA_ERR_DEVELOPMENT:                    return "MARPA_ERR_DEVELOPMENT: Development error, see string";
    case MARPA_ERR_DUPLICATE_AND_NODE:             return "MARPA_ERR_DUPLICATE_AND_NODE";
    case MARPA_ERR_DUPLICATE_RULE:                 return "MARPA_ERR_DUPLICATE_RULE: Duplicate rule";
    case MARPA_ERR_DUPLICATE_TOKEN:                return "MARPA_ERR_DUPLICATE_TOKEN: Duplicate token";
    case MARPA_ERR_YIM_COUNT:                      return "MARPA_ERR_YIM_COUNT: Maximum number of Earley items exceeded";
    case MARPA_ERR_YIM_ID_INVALID:                 return "MARPA_ERR_YIM_ID_INVALID";
    case MARPA_ERR_EVENT_IX_NEGATIVE:              return "MARPA_ERR_EVENT_IX_NEGATIVE: Negative event index";
    case MARPA_ERR_EVENT_IX_OOB:                   return "MARPA_ERR_EVENT_IX_OOB: No event at that index";
    case MARPA_ERR_GRAMMAR_HAS_CYCLE:              return "MARPA_ERR_GRAMMAR_HAS_CYCLE: Grammar has cycle";
    case MARPA_ERR_INACCESSIBLE_TOKEN:             return "MARPA_ERR_INACCESSIBLE_TOKEN: Token symbol is inaccessible";
    case MARPA_ERR_INTERNAL:                       return "MARPA_ERR_INTERNAL";
    case MARPA_ERR_INVALID_AHFA_ID:                return "MARPA_ERR_INVALID_AHFA_ID";
    case MARPA_ERR_INVALID_AIMID:                  return "MARPA_ERR_INVALID_AIMID";
    case MARPA_ERR_INVALID_BOOLEAN:                return "MARPA_ERR_INVALID_BOOLEAN: Argument is not boolean";
    case MARPA_ERR_INVALID_IRLID:                  return "MARPA_ERR_INVALID_IRLID";
    case MARPA_ERR_INVALID_NSYID:                  return "MARPA_ERR_INVALID_NSYID";
    case MARPA_ERR_INVALID_LOCATION:               return "MARPA_ERR_INVALID_LOCATION: Location is not valid";
    case MARPA_ERR_INVALID_RULE_ID:                return "MARPA_ERR_INVALID_RULE_ID: Rule ID is malformed";
    case MARPA_ERR_INVALID_START_SYMBOL:           return "MARPA_ERR_INVALID_START_SYMBOL: Specified start symbol is not valid";
    case MARPA_ERR_INVALID_SYMBOL_ID:              return "MARPA_ERR_INVALID_SYMBOL_ID: Symbol ID is malformed";
    case MARPA_ERR_I_AM_NOT_OK:                    return "MARPA_ERR_I_AM_NOT_OK: Marpa is in a not OK state";
    case MARPA_ERR_MAJOR_VERSION_MISMATCH:         return "MARPA_ERR_MAJOR_VERSION_MISMATCH: Libmarpa major version number is a mismatch";
    case MARPA_ERR_MICRO_VERSION_MISMATCH:         return "MARPA_ERR_MICRO_VERSION_MISMATCH: Libmarpa micro version number is a mismatch";
    case MARPA_ERR_MINOR_VERSION_MISMATCH:         return "MARPA_ERR_MINOR_VERSION_MISMATCH: Libmarpa minor version number is a mismatch";
    case MARPA_ERR_NOOKID_NEGATIVE:                return "MARPA_ERR_NOOKID_NEGATIVE";
    case MARPA_ERR_NOT_PRECOMPUTED:                return "MARPA_ERR_NOT_PRECOMPUTED: This grammar is not precomputed";
    case MARPA_ERR_NOT_TRACING_COMPLETION_LINKS:   return "MARPA_ERR_NOT_TRACING_COMPLETION_LINKS";
    case MARPA_ERR_NOT_TRACING_LEO_LINKS:          return "MARPA_ERR_NOT_TRACING_LEO_LINKS";
    case MARPA_ERR_NOT_TRACING_TOKEN_LINKS:        return "MARPA_ERR_NOT_TRACING_TOKEN_LINKS";
    case MARPA_ERR_NO_AND_NODES:                   return "MARPA_ERR_NO_AND_NODES";
    case MARPA_ERR_NO_EARLEY_SET_AT_LOCATION:      return "MARPA_ERR_NO_EARLEY_SET_AT_LOCATION: Earley set ID is after latest Earley set";
    case MARPA_ERR_NO_OR_NODES:                    return "MARPA_ERR_NO_OR_NODES";
    case MARPA_ERR_NO_PARSE:                       return "MARPA_ERR_NO_PARSE: No parse";
    case MARPA_ERR_NO_RULES:                       return "MARPA_ERR_NO_RULES: This grammar does not have any rules";
    case MARPA_ERR_NO_START_SYMBOL:                return "MARPA_ERR_NO_START_SYMBOL: This grammar has no start symbol";
    case MARPA_ERR_NO_TOKEN_EXPECTED_HERE:         return "MARPA_ERR_NO_TOKEN_EXPECTED_HERE: No token is expected at this earleme location";
    case MARPA_ERR_NO_TRACE_YIM:                   return "MARPA_ERR_NO_TRACE_YIM";
    case MARPA_ERR_NO_TRACE_YS:                    return "MARPA_ERR_NO_TRACE_YS";
    case MARPA_ERR_NO_TRACE_PIM:                   return "MARPA_ERR_NO_TRACE_PIM";
    case MARPA_ERR_NO_TRACE_SRCL:                  return "MARPA_ERR_NO_TRACE_SRCL";
    case MARPA_ERR_NULLING_TERMINAL:               return "MARPA_ERR_NULLING_TERMINAL: A symbol is both terminal and nulling";
    case MARPA_ERR_ORDER_FROZEN:                   return "MARPA_ERR_ORDER_FROZEN: The ordering is frozen";
    case MARPA_ERR_ORID_NEGATIVE:                  return "MARPA_ERR_ORID_NEGATIVE";
    case MARPA_ERR_OR_ALREADY_ORDERED:             return "MARPA_ERR_OR_ALREADY_ORDERED";
    case MARPA_ERR_PARSE_EXHAUSTED:                return "MARPA_ERR_PARSE_EXHAUSTED: The parse is exhausted";
    case MARPA_ERR_PARSE_TOO_LONG:                 return "MARPA_ERR_PARSE_TOO_LONG: This input would make the parse too long";
    case MARPA_ERR_PIM_IS_NOT_LIM:                 return "MARPA_ERR_PIM_IS_NOT_LIM";
    case MARPA_ERR_POINTER_ARG_NULL:               return "MARPA_ERR_POINTER_ARG_NULL: An argument is null when it should not be";
    case MARPA_ERR_PRECOMPUTED:                    return "MARPA_ERR_PRECOMPUTED: This grammar is precomputed";
    case MARPA_ERR_PROGRESS_REPORT_EXHAUSTED:      return "MARPA_ERR_PROGRESS_REPORT_EXHAUSTED: The progress report is exhausted";
    case MARPA_ERR_PROGRESS_REPORT_NOT_STARTED:    return "MARPA_ERR_PROGRESS_REPORT_NOT_STARTED: No progress report has been started";
    case MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT:      return "MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT: The recognizer is not accepting input";
    case MARPA_ERR_RECCE_NOT_STARTED:              return "MARPA_ERR_RECCE_NOT_STARTED: The recognizer has not been started";
    case MARPA_ERR_RECCE_STARTED:                  return "MARPA_ERR_RECCE_STARTED: The recognizer has been started";
    case MARPA_ERR_RHS_IX_NEGATIVE:                return "MARPA_ERR_RHS_IX_NEGATIVE: RHS index cannot be negative";
    case MARPA_ERR_RHS_IX_OOB:                     return "MARPA_ERR_RHS_IX_OOB: RHS index must be less than rule length";
    case MARPA_ERR_RHS_TOO_LONG:                   return "MARPA_ERR_RHS_TOO_LONG: The RHS is too long";
    case MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE:        return "MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE: LHS of sequence rule would not be unique";
    case MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS:       return "MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS";
    case MARPA_ERR_SOURCE_TYPE_IS_COMPLETION:      return "MARPA_ERR_SOURCE_TYPE_IS_COMPLETION";
    case MARPA_ERR_SOURCE_TYPE_IS_LEO:             return "MARPA_ERR_SOURCE_TYPE_IS_LEO";
    case MARPA_ERR_SOURCE_TYPE_IS_NONE:            return "MARPA_ERR_SOURCE_TYPE_IS_NONE";
    case MARPA_ERR_SOURCE_TYPE_IS_TOKEN:           return "MARPA_ERR_SOURCE_TYPE_IS_TOKEN";
    case MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN:         return "MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN";
    case MARPA_ERR_START_NOT_LHS:                  return "MARPA_ERR_START_NOT_LHS: Start symbol not on LHS of any rule";
    case MARPA_ERR_SYMBOL_VALUED_CONFLICT:         return "MARPA_ERR_SYMBOL_VALUED_CONFLICT: Symbol is treated both as valued and unvalued";
    case MARPA_ERR_TERMINAL_IS_LOCKED:             return "MARPA_ERR_TERMINAL_IS_LOCKED: The terminal status of the symbol is locked";
    case MARPA_ERR_TOKEN_IS_NOT_TERMINAL:          return "MARPA_ERR_TOKEN_IS_NOT_TERMINAL: Token symbol must be a terminal";
    case MARPA_ERR_TOKEN_LENGTH_LE_ZERO:           return "MARPA_ERR_TOKEN_LENGTH_LE_ZERO: Token length must greater than zero";
    case MARPA_ERR_TOKEN_TOO_LONG:                 return "MARPA_ERR_TOKEN_TOO_LONG: Token is too long";
    case MARPA_ERR_TREE_EXHAUSTED:                 return "MARPA_ERR_TREE_EXHAUSTED: Tree iterator is exhausted";
    case MARPA_ERR_TREE_PAUSED:                    return "MARPA_ERR_TREE_PAUSED: Tree iterator is paused";
    case MARPA_ERR_UNEXPECTED_TOKEN_ID:            return "MARPA_ERR_UNEXPECTED_TOKEN_ID: Unexpected token";
    case MARPA_ERR_UNPRODUCTIVE_START:             return "MARPA_ERR_UNPRODUCTIVE_START: Unproductive start symbol";
    case MARPA_ERR_VALUATOR_INACTIVE:              return "MARPA_ERR_VALUATOR_INACTIVE: Valuator inactive";
    case MARPA_ERR_VALUED_IS_LOCKED:               return "MARPA_ERR_VALUED_IS_LOCKED: The valued status of the symbol is locked";
    case MARPA_ERR_RANK_TOO_LOW:                   return "MARPA_ERR_RANK_TOO_LOW: Rule or symbol rank too low";
    case MARPA_ERR_RANK_TOO_HIGH:                  return "MARPA_ERR_RANK_TOO_HIGH: Rule or symbol rank too high";
    case MARPA_ERR_SYMBOL_IS_NULLING:              return "MARPA_ERR_SYMBOL_IS_NULLING: Symbol is nulling";
    case MARPA_ERR_SYMBOL_IS_UNUSED:               return "MARPA_ERR_SYMBOL_IS_UNUSED: Symbol is not used";
    case MARPA_ERR_NO_SUCH_RULE_ID:                return "MARPA_ERR_NO_SUCH_RULE_ID: No rule with this ID exists";
    case MARPA_ERR_NO_SUCH_SYMBOL_ID:              return "MARPA_ERR_NO_SUCH_SYMBOL_ID: No symbol with this ID exists";
    case MARPA_ERR_BEFORE_FIRST_TREE:              return "MARPA_ERR_BEFORE_FIRST_TREE: Tree iterator is before first tree";
    case MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT: return "MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT: Symbol is not set up for completion events";
    case MARPA_ERR_SYMBOL_IS_NOT_NULLED_EVENT:     return "MARPA_ERR_SYMBOL_IS_NOT_NULLED_EVENT: Symbol is not set up for nulled events";
    case MARPA_ERR_SYMBOL_IS_NOT_PREDICTION_EVENT: return "MARPA_ERR_SYMBOL_IS_NOT_PREDICTION_EVENT: Symbol is not set up for prediction events";
    case MARPA_ERR_RECCE_IS_INCONSISTENT:          return "MARPA_ERR_RECCE_IS_INCONSISTENT";
    case MARPA_ERR_INVALID_ASSERTION_ID:           return "MARPA_ERR_INVALID_ASSERTION_ID: Assertion ID is malformed";
    case MARPA_ERR_NO_SUCH_ASSERTION_ID:           return "MARPA_ERR_NO_SUCH_ASSERTION_ID: No assertion with this ID exists";

    default:                                       return "Unknown Marpa error";
    }

  default:                                         return "Unknown error origin";
  }
}

/***********************/
/* _marpaWrapper_event */
/***********************/
static marpaWrapperBool_t _marpaWrapper_event(marpaWrapper_t *marpaWrapperp) {
  int                  nbEventi;
  int                  i;
  int                  subscribedEventi;
  marpaWrapperEvent_t *marpaWrapperEventp;
  const char          *warningMsgs;
  const char          *fatalMsgs;
  const char          *infoMsgs;
  Marpa_Event_Type     eventType;
  Marpa_Event          event;
  int                  eventValuei;

  MARPAWRAPPER_LOG_TRACEX("marpa_g_event_count(%p)", marpaWrapperp->marpaGrammarp);
  nbEventi = marpa_g_event_count(marpaWrapperp->marpaGrammarp);

  if (nbEventi < 0) {
    /* Formally this is not an error */
    return MARPAWRAPPER_BOOL_TRUE;
  }

  marpaWrapperEventp = (marpaWrapperEvent_t *) malloc(nbEventi * sizeof(marpaWrapperEvent_t));
  if (marpaWrapperEventp == NULL) {
    MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Get all events, with a distinction between warnings, and the subscriptions */
  for (i = 0, subscribedEventi = 0; i < nbEventi; i++) {
    
    MARPAWRAPPER_LOG_TRACEX("marpa_g_event(%p, %p, %d)", marpaWrapperp->marpaGrammarp, &event, i);
    eventType = marpa_g_event(marpaWrapperp->marpaGrammarp, &event, i);
    if (eventType < 0) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      free(marpaWrapperEventp);
      return MARPAWRAPPER_BOOL_FALSE;
    }

    warningMsgs = NULL;
    fatalMsgs = NULL;
    infoMsgs = NULL;
    switch (eventType) {
    case MARPA_EVENT_NONE:
      break;
    case MARPA_EVENT_COUNTED_NULLABLE:
      fatalMsgs = "This symbol is a counted nullable";
      break;
    case MARPA_EVENT_EARLEY_ITEM_THRESHOLD:
      warningMsgs = "Too many Earley items";
      break;
    case MARPA_EVENT_EXHAUSTED:
      infoMsgs = "Recognizer is exhausted";
      break;
    case MARPA_EVENT_LOOP_RULES:
      warningMsgs = "Grammar contains a infinite loop";
      break;
    case MARPA_EVENT_NULLING_TERMINAL:
      fatalMsgs = "This symbol is a nulling terminal";
      break;
    case MARPA_EVENT_SYMBOL_COMPLETED:
      MARPAWRAPPER_LOG_TRACEX("marpa_g_event_value(%p)", &event);
      eventValuei = marpa_g_event_value(&event);
      marpaWrapperEventp[subscribedEventi].eventType = MARPAWRAPPER_EVENTTYPE_COMPLETED;
      marpaWrapperEventp[subscribedEventi].marpaWrapperSymbolp = marpaWrapperp->marpaWrapperSymbolpp[eventValuei];
      subscribedEventi++;
      MARPAWRAPPER_LOG_TRACEX("\tCompleted symbol %d", eventValuei);
      break;
    case MARPA_EVENT_SYMBOL_NULLED:
      MARPAWRAPPER_LOG_TRACEX("marpa_g_event_value(%p)", &event);
      eventValuei = marpa_g_event_value(&event);
      marpaWrapperEventp[subscribedEventi].eventType = MARPAWRAPPER_EVENTTYPE_NULLED;
      marpaWrapperEventp[subscribedEventi].marpaWrapperSymbolp = marpaWrapperp->marpaWrapperSymbolpp[eventValuei];
      subscribedEventi++;
      MARPAWRAPPER_LOG_TRACEX("\tSymbol %d was nulled", eventValuei);
      break;
    case MARPA_EVENT_SYMBOL_EXPECTED:        /* Terminals only, should not happen since we rely on the general events mechanism */
      eventValuei = marpa_g_event_value(&event);
      marpaWrapperEventp[subscribedEventi].eventType = MARPAWRAPPER_EVENTTYPE_PREDICTED;
      marpaWrapperEventp[subscribedEventi].marpaWrapperSymbolp = marpaWrapperp->marpaWrapperSymbolpp[eventValuei];
      subscribedEventi++;
      MARPAWRAPPER_LOG_TRACEX("\tExpecting symbol %d", eventValuei);
      break;
    case MARPA_EVENT_SYMBOL_PREDICTED:
      MARPAWRAPPER_LOG_TRACEX("marpa_g_event_value(%p)", &event);
      eventValuei = marpa_g_event_value(&event);
      marpaWrapperEventp[subscribedEventi].eventType = MARPAWRAPPER_EVENTTYPE_PREDICTED;
      marpaWrapperEventp[subscribedEventi].marpaWrapperSymbolp = marpaWrapperp->marpaWrapperSymbolpp[eventValuei];
      subscribedEventi++;
      MARPAWRAPPER_LOG_TRACEX("\tSymbol %d was predicted", eventValuei);
      break;
    default:
      /* shall we log that ? */
      /*
      _marpaWrapper_logWrapper(marpaWrapperp,
			       MARPAWRAPPERERRORORIGIN_NA,
			       0,
			       "Unknown event type",
			       MARPAWRAPPER_LOGLEVEL_INFO);
      */
      break;
    }
    if (warningMsgs != NULL) {
      if (marpaWrapperp->marpaWrapperOption.warningIsErrorb == MARPAWRAPPER_BOOL_TRUE) {
	MARPAWRAPPER_LOG_ERROR0(warningMsgs);
	free(marpaWrapperEventp);
	return MARPAWRAPPER_BOOL_FALSE;
      } else {
	MARPAWRAPPER_LOG_WARNING0(warningMsgs);
      }
    } else if (fatalMsgs != NULL) {
      MARPAWRAPPER_LOG_ERROR0(fatalMsgs);
      free(marpaWrapperEventp);
      return MARPAWRAPPER_BOOL_FALSE;
    } else if (infoMsgs != NULL) {
      MARPAWRAPPER_LOG_INFO0(infoMsgs);
      free(marpaWrapperEventp);
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }


  if (subscribedEventi > 0) {
    if (subscribedEventi > 1) {
      /* Eventually sort the events */
      if (marpaWrapperp->marpaWrapperOption.unsortedEventsb == MARPAWRAPPER_BOOL_FALSE) {
	qsort(marpaWrapperEventp, subscribedEventi, sizeof(marpaWrapperEvent_t), &_marpaWrapper_event_cmp);
      }
    }
    if (marpaWrapperp->marpaWrapperOption.eventCallbackp != NULL) {
      MARPAWRAPPER_LOG_TRACEX("eventCallbackp(%p, %p, %d, %p)", marpaWrapperp->marpaWrapperOption.eventCallbackDatavp, marpaWrapperp, subscribedEventi, marpaWrapperEventp);
      (*marpaWrapperp->marpaWrapperOption.eventCallbackp)(marpaWrapperp->marpaWrapperOption.eventCallbackDatavp, marpaWrapperp, subscribedEventi, marpaWrapperEventp);
    }
  }

  free(marpaWrapperEventp);

  return MARPAWRAPPER_BOOL_TRUE;
}

/***************************/
/* _marpaWrapper_event_cmp */
/***************************/
static int _marpaWrapper_event_cmp(const void *event1p, const void *event2p) {
  int rc1 = _marpaWrapper_event_weight(((marpaWrapperEvent_t *) event1p)->eventType);
  int rc2 = _marpaWrapper_event_weight(((marpaWrapperEvent_t *) event2p)->eventType);

  if (rc1 < rc2) {
    return -1;
  } else if (rc1 < rc2) {
    return 1;
  } else {
    return 0;
  }
}

/******************************/
/* _marpaWrapper_event_weight */
/******************************/
static int _marpaWrapper_event_weight(Marpa_Event_Type eventType) {
  int rc;

  switch (eventType) {
  case MARPA_EVENT_SYMBOL_COMPLETED:
    rc = -1;
    break;
  case MARPA_EVENT_SYMBOL_NULLED:
    rc = -0;
    break;
  case MARPA_EVENT_SYMBOL_EXPECTED:        /* Terminals only, should not happen since we rely on the general events mechanism */
  case MARPA_EVENT_SYMBOL_PREDICTED:
    rc = 1;
    break;
  default:
    /* Should never happen, c.f. _marpaWrapper_event() */
    break;
  }

  return rc;
}

/*****************************/
/* _marpaWrapper_manage_bufb */
/*****************************/
static marpaWrapperBool_t _marpaWrapper_manage_bufb(marpaWrapper_t *marpaWrapperp, void ***ppp, size_t *sizeip, size_t wantedNumberi, size_t elementSizei) {
  size_t  sizei = *sizeip;
  size_t  origSizei = sizei;
  size_t  prevSizei;
  void  **pp = *ppp;
  size_t  i;

  /*
   * Per def, this routine is managing an array of pointer
   */

  if (sizei < wantedNumberi) {

    prevSizei = sizei;
    while (sizei < wantedNumberi) {
      if (sizei <= 0) {
	/* Let's start at arbitrary number of elements of 100 */
	sizei = 100;
	pp = malloc(sizei * elementSizei);
	if (pp == NULL) {
	  MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
	  return MARPAWRAPPER_BOOL_FALSE;
	}
      } else {
	sizei *= 2;
	if (sizei < prevSizei) {
	  /* Turnaround */
	  MARPAWRAPPER_LOG_ERROR0("Turnaround on computing size to allocate");
	  return MARPAWRAPPER_BOOL_FALSE;
	}
	pp = realloc(pp, sizei * elementSizei);
	if (pp == NULL) {
	  MARPAWRAPPER_LOG_SYS_ERROR(errno, "realloc()");
	  return MARPAWRAPPER_BOOL_FALSE;
	}
      }
      prevSizei = sizei;
    }
  }

  /*
   * Pre-fill pointers with NULL
   */
  for (i = origSizei; i < sizei; i++) {
    pp[i] = NULL;
  }

  *ppp = pp;
  *sizeip = sizei;

  return MARPAWRAPPER_BOOL_TRUE;

}

/*************************************/
/* _marpaWrapperStackFailureCallback */
/*************************************/
static void _marpaWrapperStackFailureCallback(genericStack_error_t errorType, int errorNumber, void *failureCallbackUserDatap) {
  marpaWrapper_t *marpaWrapperp = (marpaWrapper_t *) failureCallbackUserDatap;
  const char *msgs;

  switch (errorType) {
  case GENERICSTACK_ERROR_SYSTEM:
    errorType = MARPAWRAPPERERRORORIGIN_SYSTEM;
    msgs = "Generic Stack system error";
    break;
  case GENERICSTACK_ERROR_PARAMETER:
    errorType = MARPAWRAPPERERRORORIGIN_NA;
    msgs = "Generic Stack parameter validation error";
    break;
  case GENERICSTACK_ERROR_RUNTIME:
    errorType = MARPAWRAPPERERRORORIGIN_NA;
    msgs = "Generic Stack runtime error";
    break;
  case GENERICSTACK_ERROR_CALLBACK:
    errorType = MARPAWRAPPERERRORORIGIN_NA;
    msgs = "Generic Stack callback error";
    break;
  default:
    errorType = MARPAWRAPPERERRORORIGIN_NA;
    msgs = "Generic Stack unknown error";
    break;
  }

  _marpaWrapper_logWrapper(marpaWrapperp, errorType, errorNumber, msgs, MARPAWRAPPER_LOGLEVEL_ERROR);
}

/**********************************/
/* _marpaWrapperStackFreeCallback */
/**********************************/
static int _marpaWrapperStackFreeCallback(void *elementp, void *freeCallbackUserDatap) {
  marpaWrapperStackElementFreeData_t *marpaWrapperStackElementFreeDatap = (marpaWrapperStackElementFreeData_t *) freeCallbackUserDatap;
  marpaWrapper_t                     *marpaWrapperp = marpaWrapperStackElementFreeDatap->marpaWrapperp;
  marpaWrapperBool_t                  rcb;

  MARPAWRAPPER_LOG_TRACEX("stackElementFreeCallbackp(%p, %p, %p)",
			  marpaWrapperStackElementFreeDatap->stackElementFreeCallbackUserDatap,
			  marpaWrapperStackElementFreeDatap->marpaWrapperp,
			  elementp);
  rcb = (*marpaWrapperStackElementFreeDatap->stackElementFreeCallbackp)
    (marpaWrapperStackElementFreeDatap->stackElementFreeCallbackUserDatap,
     marpaWrapperStackElementFreeDatap->marpaWrapperp,
     elementp);

  return (rcb == MARPAWRAPPER_BOOL_TRUE) ? 0 : -1;
}

/**********************************/
/* _marpaWrapperStackCopyCallback */
/**********************************/
static int _marpaWrapperStackCopyCallback(void *elementDstp, void *elementSrcp, void *copyCallbackUserDatap) {
  marpaWrapperStackElementCopyData_t *marpaWrapperStackElementCopyDatap = (marpaWrapperStackElementCopyData_t *) copyCallbackUserDatap;
  marpaWrapper_t                     *marpaWrapperp = marpaWrapperStackElementCopyDatap->marpaWrapperp;
  marpaWrapperBool_t                  rcb;

  MARPAWRAPPER_LOG_TRACEX("stackElementCopyCallbackp(%p, %p, %p, %p)",
			  marpaWrapperStackElementCopyDatap->stackElementCopyCallbackUserDatap,
			  marpaWrapperStackElementCopyDatap->marpaWrapperp,
			  elementDstp,
			  elementSrcp);
  rcb = (*marpaWrapperStackElementCopyDatap->stackElementCopyCallbackp)
    (marpaWrapperStackElementCopyDatap->stackElementCopyCallbackUserDatap,
     marpaWrapperStackElementCopyDatap->marpaWrapperp,
     elementDstp,
     elementSrcp);

  return (rcb == MARPAWRAPPER_BOOL_TRUE) ? 0 : -1;
}

/*******************************/
/* marpaWrapper_optionDefaultb */
/*******************************/
marpaWrapperBool_t marpaWrapper_optionDefaultb(marpaWrapperOption_t *marpaWrapperOptionp) {

  if (marpaWrapperOptionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperOptionp->versionip              = (int (*)[3]) NULL;
  marpaWrapperOptionp->logLevelWantedi        = MARPAWRAPPER_LOGLEVEL_WARNING;
  marpaWrapperOptionp->logCallbackp           = &_marpaWrapper_logCallback;
  marpaWrapperOptionp->logCallbackDatavp      = NULL;
  marpaWrapperOptionp->eventCallbackp         = NULL;
  marpaWrapperOptionp->eventCallbackDatavp    = NULL;
  marpaWrapperOptionp->warningIsErrorb        = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperOptionp->warningIsIgnoredb      = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperOptionp->unsortedEventsb        = MARPAWRAPPER_BOOL_FALSE;

  return MARPAWRAPPER_BOOL_TRUE;
}

/*************************************/
/* marpaWrapper_symbolOptionDefaultb */
/*************************************/
marpaWrapperBool_t marpaWrapper_symbolOptionDefaultb(marpaWrapperSymbolOption_t *marpaWrapperSymbolOptionp) {

  if (marpaWrapperSymbolOptionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperSymbolOptionp->datavp      = NULL;
  marpaWrapperSymbolOptionp->terminalb   = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperSymbolOptionp->startb      = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperSymbolOptionp->eventSeti   = 0;

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************************/
/* marpaWrapper_valueOptionDefaultb */
/************************************/
marpaWrapperBool_t marpaWrapper_valueOptionDefaultb(marpaWrapperValueOption_t *marpaWrapperValueOptionp) {
  if (marpaWrapperValueOptionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperValueOptionp->valueRuleCallbackp         = NULL;
  marpaWrapperValueOptionp->valueRuleCallbackDatavp    = NULL;
  marpaWrapperValueOptionp->valueSymbolCallbackp       = NULL;
  marpaWrapperValueOptionp->valueSymbolCallbackDatavp  = NULL;
  marpaWrapperValueOptionp->valueNullingCallbackp      = NULL;
  marpaWrapperValueOptionp->valueNullingCallbackDatavp = NULL;
  marpaWrapperValueOptionp->valueResultCallbackp       = NULL;
  marpaWrapperValueOptionp->valueResultCallbackDatavp  = NULL;
  marpaWrapperValueOptionp->highRankOnlyb              = MARPAWRAPPER_BOOL_TRUE;
  marpaWrapperValueOptionp->orderByRankb               = MARPAWRAPPER_BOOL_TRUE;
  marpaWrapperValueOptionp->ambiguityb                 = MARPAWRAPPER_BOOL_TRUE;
  marpaWrapperValueOptionp->nullb                      = MARPAWRAPPER_BOOL_TRUE;

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************************/
/* marpaWrapper_ruleOptionDefaultb */
/************************************/
marpaWrapperBool_t marpaWrapper_ruleOptionDefaultb(marpaWrapperRuleOption_t *marpaWrapperRuleOptionp) {
  if (marpaWrapperRuleOptionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperRuleOptionp->datavp           = NULL;
  marpaWrapperRuleOptionp->lhsSymbolp       = NULL;
  marpaWrapperRuleOptionp->nRhsSymboli      = 0;
  marpaWrapperRuleOptionp->rhsSymbolpp      = NULL;
  marpaWrapperRuleOptionp->ranki            = 0;
  marpaWrapperRuleOptionp->nullRanksHighb   = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperRuleOptionp->sequenceb        = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperRuleOptionp->separatorSymbolp = NULL;
  marpaWrapperRuleOptionp->properb          = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperRuleOptionp->minimumi         = 0;

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************************/
/* marpaWrapper_stackOptionDefaultb */
/************************************/
marpaWrapperBool_t marpaWrapper_stackOptionDefaultb(marpaWrapperStackOption_t *marpaWrapperStackOptionp) {
  if (marpaWrapperStackOptionp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  marpaWrapperStackOptionp->stackElementSizei                 = 0;
  marpaWrapperStackOptionp->stackElementFreeCallbackp         = NULL;
  marpaWrapperStackOptionp->stackElementFreeCallbackUserDatap = NULL;
  marpaWrapperStackOptionp->stackElementCopyCallbackp         = NULL;
  marpaWrapperStackOptionp->stackElementCopyCallbackUserDatap = NULL;

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************************/
/* marpaWrapper_stackOptionDefaultb */
/************************************/
marpaWrapperBool_t marpaWrapper_r_progressb(marpaWrapper_t *marpaWrapperp, int starti, int endi, size_t *nmarpaWrapperProgressip, marpaWrapperProgress_t ***marpaWrapperProgressppp) {
  Marpa_Earley_Set_ID     marpaLatestEarleySetIdi;
  Marpa_Earleme           marpEarlemei;
  Marpa_Earley_Set_ID     marpaEarleySetIdStarti, marpaEarleySetIdi, marpaEarleySetIdEndi, marpaEarleySetIdOrigini;
  Marpa_Rule_ID           marpaRuleIdi;
  int                     nbItemsi;
  int                     itemi;
  int                     positioni;
  size_t                  nMarpaWrapperProgressi = 0;
  marpaWrapperBool_t      rcb;
  size_t                  i;
  marpaWrapperProgress_t *marpaWrapperProgressp;

  if (marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapperp->marpaRecognizerp == NULL) {
    MARPAWRAPPER_LOG_ERROR0("Read phase not started");
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Free eventual previous rounds - progress report sizes is a volatile thing and we do not want */
  /* to hog memory.                                                                               */
  if (marpaWrapperp->marpaWrapperProgresspp != NULL) {
    if (marpaWrapperp->nMarpaWrapperProgressi > 0) {
      for (i = 0; i < marpaWrapperp->nMarpaWrapperProgressi; i++) {
        if (marpaWrapperp->marpaWrapperProgresspp[i] != NULL) {
          free(marpaWrapperp->marpaWrapperProgresspp[i]);
        }
      }
    }
    free(marpaWrapperp->marpaWrapperProgresspp);
    marpaWrapperp->marpaWrapperProgresspp = NULL;
    marpaWrapperp->sizeMarpaWrapperProgressi = 0;
    marpaWrapperp->nMarpaWrapperProgressi = 0;
  }

  /* This function always succeed as per doc */
  MARPAWRAPPER_LOG_TRACEX("marpa_r_latest_earley_set(%p)", marpaWrapperp->marpaRecognizerp);
  marpaLatestEarleySetIdi = marpa_r_latest_earley_set(marpaWrapperp->marpaRecognizerp);

  if (starti < 0) {
    starti += (marpaLatestEarleySetIdi + 1);
  }
  if ((starti < 0) || (starti > marpaLatestEarleySetIdi)) {
    MARPAWRAPPER_LOG_ERRORX("starti must be in range [%d-%d]", (int) (-(marpaLatestEarleySetIdi+1)), (int) marpaLatestEarleySetIdi);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (endi < 0) {
    endi += (marpaLatestEarleySetIdi + 1);
  }
  if ((endi < 0) || (endi > marpaLatestEarleySetIdi)) {
    MARPAWRAPPER_LOG_ERRORX("endi must be in range [%d-%d]", (int) (-(marpaLatestEarleySetIdi+1)), (int) marpaLatestEarleySetIdi);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (starti > endi) {
    MARPAWRAPPER_LOG_ERRORX("[starti,endi] range evaluated to [%d-%d]", starti, endi);
    return MARPAWRAPPER_BOOL_FALSE;
  }

  rcb = MARPAWRAPPER_BOOL_TRUE;

  marpaEarleySetIdStarti = (Marpa_Earley_Set_ID) starti;
  marpaEarleySetIdEndi   = (Marpa_Earley_Set_ID) endi;
  for (marpaEarleySetIdi = marpaEarleySetIdStarti; marpaEarleySetIdi <= marpaEarleySetIdEndi; marpaEarleySetIdi++) {

    MARPAWRAPPER_LOG_TRACEX("marpa_r_earleme(%p, %d)", marpaWrapperp->marpaRecognizerp, (int) marpaEarleySetIdi);
    marpEarlemei = marpa_r_earleme(marpaWrapperp->marpaRecognizerp, marpaEarleySetIdi);
    if (marpEarlemei == -2) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
    }

    MARPAWRAPPER_LOG_TRACEX("marpa_r_progress_report_start(%p, %d)", marpaWrapperp->marpaRecognizerp, (int) marpaEarleySetIdi);
    nbItemsi = marpa_r_progress_report_start(marpaWrapperp->marpaRecognizerp, marpaEarleySetIdi);
    if (nbItemsi == -2) {
      MARPAWRAPPER_LOG_MARPA_G_ERROR;
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
    }
    if (nbItemsi < 0) {
      MARPAWRAPPER_LOG_ERRORX("Number of items for progress report at Earley Set Id %d is %d", (int) marpaEarleySetIdi, nbItemsi);
      rcb = MARPAWRAPPER_BOOL_FALSE;
      break;
    }

    for (itemi = 0; itemi < nbItemsi; itemi++) {

      MARPAWRAPPER_LOG_TRACEX("marpa_r_progress_item(%p, %p, %p)", marpaWrapperp->marpaRecognizerp, &positioni, &marpaEarleySetIdOrigini);
      marpaRuleIdi = marpa_r_progress_item(marpaWrapperp->marpaRecognizerp, &positioni, &marpaEarleySetIdOrigini);
      if (marpaRuleIdi == -2) {
        MARPAWRAPPER_LOG_MARPA_G_ERROR;
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      if (marpaRuleIdi == -1) {
        MARPAWRAPPER_LOG_ERRORX("Progress report No %d at Earley Set Id %d failure", itemi, (int) marpaEarleySetIdi);
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }

      /* Allocate room for the new report item */
      if (_marpaWrapper_manage_bufb(marpaWrapperp,
                                    (void ***) &(marpaWrapperp->marpaWrapperProgresspp),
                                    &(marpaWrapperp->sizeMarpaWrapperProgressi),
                                    nMarpaWrapperProgressi + 1,
                                    sizeof(marpaWrapperProgress_t *)) != MARPAWRAPPER_BOOL_TRUE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
      marpaWrapperp->marpaWrapperProgresspp[nMarpaWrapperProgressi] = (marpaWrapperProgress_t *) malloc(sizeof(marpaWrapperProgress_t));
      if (marpaWrapperp->marpaWrapperProgresspp[nMarpaWrapperProgressi] == NULL) {
        MARPAWRAPPER_LOG_SYS_ERROR(errno, "malloc()");
        return MARPAWRAPPER_BOOL_FALSE;
      }
      marpaWrapperp->nMarpaWrapperProgressi = ++nMarpaWrapperProgressi;
      marpaWrapperProgressp = marpaWrapperp->marpaWrapperProgresspp[nMarpaWrapperProgressi];
      marpaWrapperProgressp->marpaEarleySetIdi       = (int) marpaEarleySetIdi;
      marpaWrapperProgressp->marpaEarleySetIdOrigini = (int) marpaEarleySetIdOrigini;
      marpaWrapperProgressp->marpaWrapperRulep       = marpaWrapperp->marpaWrapperRulepp[marpaRuleIdi];
      marpaWrapperProgressp->positioni               = positioni;
    }

    if (rcb == MARPAWRAPPER_BOOL_FALSE) {
      break;
    }

  }

  MARPAWRAPPER_LOG_TRACEX("marpa_r_progress_report_finish(%p)", marpaWrapperp->marpaRecognizerp);
  if (marpa_r_progress_report_finish(marpaWrapperp->marpaRecognizerp) < 0) {
    MARPAWRAPPER_LOG_MARPA_G_ERROR;
    rcb = MARPAWRAPPER_BOOL_FALSE;
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    if (nmarpaWrapperProgressip != NULL) {
      *nmarpaWrapperProgressip = marpaWrapperp->nMarpaWrapperProgressi;
    }
    if (marpaWrapperProgressppp != NULL) {
      *marpaWrapperProgressppp = marpaWrapperp->marpaWrapperProgresspp;
    }
  }
  return rcb; 
}

/***************************/
/* _marpaWrapper_free_bufb */
/***************************/
static void _marpaWrapper_free_bufb(marpaWrapper_t *marpaWrapperp, void ***ppp, size_t *sizeip) {
  void  **pp;
  size_t  i;

  if (ppp != NULL) {
    pp = *ppp;
    if (pp != NULL) {
      if (*sizeip > 0) {
        for (i = 0; i < *sizeip; i++) {
          if (pp[i] != NULL) {
            free(pp[i]);
            pp[i] = NULL;
          }
        }
      }
    }
    *ppp = NULL;
    *sizeip = 0;
  }
}

