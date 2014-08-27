#include "internal/config.h"

#include <string.h>
#include <stdlib.h>

#include "unicode/ustring.h"
#include "unicode/uchar.h"
#include "unicode/uclean.h"
#include "sqlite3.h"
#include "marpaXml/DOM2.h"

#include "internal/messageBuilder.h"
#include "internal/hash.h"
#include "../db/Dom Level 3 Core.h"

/********************************************************************************/
/*                            Internal types                                    */
/********************************************************************************/
typedef enum {
  _marpaXml_Transaction_BeginImmediate_e = 0,
  _marpaXml_Transaction_End_e,
  _marpaXml_Transaction_Rollback_e,

  _marpaXml_DOMException_new_e,
  _marpaXml_DOMException_getCode_e,
  _marpaXml_DOMException_setCode_e,
  _marpaXml_DOMException_getMessage_e,
  _marpaXml_DOMException_setMessage_e,
  _marpaXml_DOMException_free_e,

} _marpaXml_stmt_e;

/*
 * We inserted the enum in this structure just to make sure we do not get wrong with
 * enum value v.s. the indice in _marpaXml_stmt[]
 */
typedef struct _marpaXml_stmt {
  sqlite3_stmt        *stmt;
  _marpaXml_stmt_e e;
  const char          *sql;
} _marpaXml_stmt_t;

/* For the SQLite exec callback */
typedef int (*_marpaXml_SQLiteExecCallback_t)(void *, int, char **, char **);

/* For the API */
struct marpaXml_DOMException_Context {  sqlite3_int64 id; };

/********************************************************************************/
/*                                Macros                                        */
/********************************************************************************/
#define _MARPAXML_TRANSACTION_BEGIN    _marpaXml_Transaction_Begin()    /* For any API call: transaction begin */
#define _MARPAXML_TRANSACTION_END      _marpaXml_Transaction_End()      /* For any API call: transaction commit */
#define _MARPAXML_TRANSACTION_ROLLBACK _marpaXml_Transaction_Rollback() /* For any API call: transaction rollback */
#define _MARPAXML_MAXCHARS_IN_TRACE    30                               /* Maximum length when printing out SQL commands */

/* Any API call must have these macros surrounding database access */
#define MARPAXML_DOM_DB_API_HEADER(method, badRc)                       \
  if (marpaXml_DOM_init(NULL) == marpaXml_false) { return badRc; }      \
  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_APICALL, method);                    \
  if (_MARPAXML_TRANSACTION_BEGIN == marpaXml_false) { return badRc; }

#define MARPAXML_DOM_DB_API_TRAILER(rc, badRc)                          \
  if (((rc) == marpaXml_false) || (_MARPAXML_TRANSACTION_END == marpaXml_false)) { \
    _MARPAXML_TRANSACTION_ROLLBACK;                                     \
    return badRc;                                                       \
  }

/********************************************************************************/
/*                                 Constants                                    */
/********************************************************************************/
static const char *_MARPAXML_LOADCOLLATION = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)";
static const char *_MARPAXML_EXEC          = "   EXEC";
static const char *_MARPAXML_PREPARE       = "PREPARE";
static const char *_MARPAXML_NEWFUNC       = "NEWFUNC";
static const char *_MARPAXML_BINDING       = "    SQL";
static const char *_MARPAXML_BINDTEXT      = "   BIND";
static const char *_MARPAXML_BINDINT       = "   BIND";
static const char *_MARPAXML_BINDINT64     = "   BIND";
static const char *_MARPAXML_STEP          = "   STEP";
static const char *_MARPAXML_APICALL       = ">>> API";
static const char *_MARPAXML_INTERNALCALL  = "       ";
static const char *_MARPAXML_INSERTID      = "INSERTID";
static const char *_MARPAXML_SQLITE_BUSY   = "SQLITE_BUSY";
static const char *_MARPAXML_SQLITE_DONE   = "SQLITE_DONE";
static const char *_MARPAXML_SQLITE_ROW    = "SQLITE_ROW";
static const char *_MARPAXML_SQLITE_ERROR  = "SQLITE_ERROR";
static const char *_MARPAXML_SQLITE_MISUSE = "SQLITE_MISUSE";

/********************************************************************************/
/*                           Static variables                                   */
/********************************************************************************/
static sqlite3              *_dbp = NULL;
static marpaXml_boolean_t    _initialized = marpaXml_false;
static marpaXmlLog_t        *marpaXmlLogp = NULL;  /* Intentionnaly without s_ prefix because of MARPAXML log macros */

static _marpaXml_stmt_t _marpaXml_stmt[] = {
  { NULL, _marpaXml_Transaction_BeginImmediate_e,        "BEGIN IMMEDIATE TRANSACTION" },
  { NULL, _marpaXml_Transaction_End_e,                   "END TRANSACTION" },
  { NULL, _marpaXml_Transaction_Rollback_e,              "ROLLBACK TRANSACTION" },

  /* DOMException: the lifetime of the row is the lifetime of the object */
  { NULL, _marpaXml_DOMException_new_e,                  "INSERT INTO DOMException (code, message) VALUES (?1, ?2)" },
  { NULL, _marpaXml_DOMException_getCode_e,              "SELECT code FROM DOMException WHERE (id = ?1)" },
  { NULL, _marpaXml_DOMException_setCode_e,              "UPDATE DOMException SET code = ?2 WHERE (id = ?1)" },
  { NULL, _marpaXml_DOMException_getMessage_e,           "SELECT message FROM DOMException WHERE (id = ?1)" },
  { NULL, _marpaXml_DOMException_setMessage_e,           "UPDATE DOMException SET message = ?2 WHERE (id = ?1)" },
  { NULL, _marpaXml_DOMException_free_e,                 "DELETE FROM DOMException WHERE (id = ?1)" },

  { NULL, 0, NULL }
};


/*********************/
/* Static prototypes */
/*********************/
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Begin(void);
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_End(void);
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Rollback(void);
static C_INLINE void               _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg);
static C_INLINE marpaXml_boolean_t _marpaXml_exec(sqlite3 *db, const char *sql, _marpaXml_SQLiteExecCallback_t execCallback, void *p);
static C_INLINE marpaXml_boolean_t _marpaXml_prepare(sqlite3 *db, const char *zSql, sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_boolean_t _marpaXml_create_function(sqlite3 *db,
								const char *zFunctionName,
								int nArg,
								int eTextRep,
								void *pApp,
								void (*xFunc)(sqlite3_context*,int,sqlite3_value**),
								void (*xStep)(sqlite3_context*,int,sqlite3_value**),
								void (*xFinal)(sqlite3_context*),
								void(*xDestroy)(void*));
static C_INLINE marpaXml_boolean_t _marpaXml_reset(sqlite3_stmt *pStmt);
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* pStmt, int pos, const char *txt);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* pStmt, int pos, int val);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* pStmt, int pos, sqlite3_int64 val);
static C_INLINE marpaXml_boolean_t _marpaXml_step(sqlite3_stmt* pStmt);
static C_INLINE void               _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg);
static C_INLINE void               _marpaXml_xxhash_xDestroy(void *p);

static C_INLINE marpaXml_DOMException_t *_marpaXml_DOMException_new(short code, marpaXml_String_t *messagep);
static C_INLINE void                     _marpaXml_DOMException_free(marpaXml_DOMException_t **thispp);

/*******************************************************************/
/* _marpaXml_DOMErrorLogCallback                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg) {
  if (marpaXmlLogp != NULL) {
    /* Not thread-safe but OK: this value can be true only if marpa is initialized, which is done */
    /* in a thread-safe routine, and marpaXmlLogp, when setted, does never interfer with any DB call */
    MARPAXML_ERRORX("SQLite error code %d: %s\n", iErrCode, (zMsg != NULL) ? zMsg : "(null)");
  }
}

/*******************************************************************/
/* _marpaXml_xxhash_xFunc                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg) {
  void                  *xxhp = sqlite3_user_data(pCtx);
  const char            *zString;
  unsigned long long int hash;

  /* No assert: we know what we are doing */
  zString = (const char *)sqlite3_value_text(apArg[0]);

  if (marpaXml_HashLongLong(xxhp, zString, zString != NULL ? strlen(zString) : 0, &hash) == MARPAXML_HASH_TRUE) {
    sqlite3_result_int64(pCtx, hash);
  } else {
    sqlite3_result_null(pCtx);
  }
}

/*******************************************************************/
/* _marpaXml_xxhash_xDestroy                                       */
/*******************************************************************/
static C_INLINE void _marpaXml_xxhash_xDestroy(void *p) {
  marpaXml_HashFree(&p);
}

/*******************************************************************/
/* _marpaXml_exec                                                  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_exec(sqlite3 *db, const char *sql, _marpaXml_SQLiteExecCallback_t execCallback, void *p) {
  char *errmsg = NULL;
  int   sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_EXEC, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_exec(db, sql, execCallback, p, &errmsg)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_exec(..., %s%s%s, ...): %s\n", sql != NULL ? "\"" : "",  sql != NULL ? sql : "(null)", sql != NULL ? "\"" : "",  errmsg != NULL ? errmsg : "(null)");
    if (errmsg != NULL) {
      sqlite3_free(errmsg);
    }
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_create_function                                       */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_create_function(sqlite3 *db,
								const char *name,
								int nArg,
								int eTextRep,
								void *pApp,
								void (*xFunc)(sqlite3_context*,int,sqlite3_value**),
								void (*xStep)(sqlite3_context*,int,sqlite3_value**),
								void (*xFinal)(sqlite3_context*),
								void (*xDestroy)(void*)) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s]: %s\n", _MARPAXML_NEWFUNC, name != NULL ? name : "(null)");
  if ((sqliteRc = sqlite3_create_function_v2(db,
					     name,
					     nArg,
					     eTextRep,
					     pApp,
					     xFunc,
					     xStep,
					     xFinal,
					     xDestroy)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_create_function_v2(..., %s%s%s, ...): %s\n", name != NULL ? "\"" : "",  name != NULL ? name : "(null)", name != NULL ? "\"" : "",  sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_prepare                                               */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **ppStmt) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_PREPARE, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_prepare_v2(db, sql, -1, ppStmt, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_prepare_v2(): %s\n\nSQL sequence was:\n\n%s\n", sqlite3_errstr(sqliteRc), sql);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_finalize                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(sqlite3_stmt **ppStmt) {
  int sqliteRc;

  if ((sqliteRc = sqlite3_finalize(*ppStmt)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_finalize(): %s\n", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  } else {
    *ppStmt = NULL;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_reset                                                 */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_reset(sqlite3_stmt *pStmt) {
  int sqliteRc;

  if ((sqliteRc = sqlite3_reset(pStmt)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_reset(): %s\n", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_text                                             */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* pStmt, int pos, const char *txt) {
  int sqliteRc;

#ifndef MARPAXML_NTRACE
  {
    int i = -1;
    char trace[_MARPAXML_MAXCHARS_IN_TRACE+1];
    marpaXml_boolean_t truncated = marpaXml_false;

    /* We intentionnally limit the printout of text to _MARPAXML_MAXCHARS_IN_TRACE characters */
    if (txt == NULL) {
      trace[0] = '\0';
    } else {
      while (txt[++i] != '\0' && i < _MARPAXML_MAXCHARS_IN_TRACE) {
	trace[i] = txt[i];
      }
      trace[i] = '\0';
      if (i == _MARPAXML_MAXCHARS_IN_TRACE && txt[i] != '\0') {
	truncated = marpaXml_true;
      }
    }
    MARPAXML_TRACEX("[%s] Pos: %d, Val: %s%s%s%s\n", _MARPAXML_BINDTEXT, pos, txt != NULL ? "\"" : "", txt != NULL ? trace : "NULL", truncated == marpaXml_true ? "<truncated>" : "", txt != NULL ? "\"" : "");
  }
#endif

  if ((sqliteRc = sqlite3_bind_text(pStmt, pos, txt, -1, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_int                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* pStmt, int pos, int val) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %d\n", _MARPAXML_BINDINT, pos, val);

  if ((sqliteRc = sqlite3_bind_int(pStmt, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_int64                                            */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* pStmt, int pos, sqlite3_int64 val) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %lld\n", _MARPAXML_BINDINT64, pos, val);

  if ((sqliteRc = sqlite3_bind_int64(pStmt, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int64(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_step                                                  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_step(sqlite3_stmt* pStmt) {
  /* No need to spend time on this switch is trace is not enabled */
#ifndef MARPAXML_NTRACE
  int sqliteRc = sqlite3_step(pStmt);

  switch (sqliteRc) {
    /* We list explicitely only the legacy error codes */
  case SQLITE_BUSY:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_BUSY);
    break;
  case SQLITE_DONE:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_DONE);
    break;
  case SQLITE_ROW:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_ROW);
    break;
  case SQLITE_ERROR:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_ERROR);
    break;
  case SQLITE_MISUSE:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_MISUSE);
    break;
  default:
    MARPAXML_TRACEX("[%s] code %d\n", _MARPAXML_STEP, sqliteRc);
    break;
  }

  return sqliteRc;
#else
  /* The compiler will certainly optimise it and put it inline */
  return sqlite3_step(pStmt);
#endif
}

/*******************************************************************/
/* marpaXml_DOM_release                                            */
/*******************************************************************/
marpaXml_boolean_t marpaXml_DOM_release(void) {
  int                   i;
  int                   sqliteRc;
  marpaXml_boolean_t rc = marpaXml_true;

  /* Not thread-safe */
  if (_initialized == marpaXml_false || _dbp == NULL) {
    return marpaXml_false;
  }

  /* Free the statements */
  i = -1;
  while (_marpaXml_stmt[++i].stmt != NULL) {
    if (_marpaXml_finalize(&_marpaXml_stmt[i].stmt) == marpaXml_false) {
      rc = marpaXml_false;
    }
  }

  /* Close connection to the DB - this will call destructors for created functions */
  if ((sqliteRc = sqlite3_close_v2(_dbp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_close_v2(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    rc = marpaXml_false;
  }

  /* Free logging */
  if (marpaXmlLogp != NULL) {
    marpaXmlLog_freev(&marpaXmlLogp);
  }

#ifdef MARPAXML_DOM_TEST_APPLICATION_ONLY
  sqlite3_shutdown();
#endif

#ifdef MARPAXML_DOM_TEST_APPLICATION_ONLY
  /* ICU recommendation is to NOT call this. This is done automatically at library unload */
  u_cleanup();
#endif

  /* Pretend we were not _initialized */
  _initialized = marpaXml_false;

  return rc;
}

/*******************************************************************/
/* marpaXml_DOM_init                                               */
/*******************************************************************/
marpaXml_boolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp) {
  UErrorCode          uErrorCode = U_ZERO_ERROR;
  sqlite3_mutex       *master_mutexp = NULL;
  sqlite3_mutex       *mutexp = NULL;
  sqlite3_stmt         *loadcollation_stmt = NULL;
  static sqlite3       *dbp = NULL;
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {":memory", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_WARNING }};
  int                  sqliteRc;
  int                  i;
  void                 *xxhp;

  /* We first check _initialized in a non thread-safe way for quick return */
  if (_initialized == marpaXml_true) {
    return marpaXml_true;
  }

  /* This is painful, it seems that sqlite3_config() can only be called before sqlite3_initialize */
  /* Therefore we do not check its return value */
  sqlite3_config(SQLITE_CONFIG_LOG, &_marpaXml_DOMErrorLogCallback, NULL);

  /* Note: sqlite3_initialize() is thread-safe and only the first one is effective */
  if ((sqliteRc = sqlite3_initialize()) != SQLITE_OK) {
    goto error;
  }

  /* We intentionnaly do not use ICU's mutex because they say their interface may change */
  /* On the other hand, sqlite says their mutex interface can be used */

  /* SQLite already has global mutexes, we use its master mutex to completely block any DOM access */
  master_mutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_STATIC_MASTER);
  if (master_mutexp == NULL) {
    goto error;
  }

  sqlite3_mutex_enter(master_mutexp);
  /* From now on we are sure we are in a synchronized call: we can recheck _initialized */
  if (_initialized == marpaXml_true) {
    sqlite3_mutex_leave(mutexp);
    return marpaXml_true;
  }

  /* We are synchronized here: this mean we can setup logging right now if not already done */
  if (marpaXml_DOM_Optionp != NULL) {
    marpaXml_DOM_Option = *marpaXml_DOM_Optionp;
  }

  if (marpaXmlLogp == NULL) {
    marpaXmlLogp = marpaXmlLog_newp(marpaXml_DOM_Option.logOption.logCallbackp, marpaXml_DOM_Option.logOption.logCallbackDatavp, marpaXml_DOM_Option.logOption.logLevelWantedi);
    if (marpaXmlLogp == NULL) {
      goto error;
    }
  }

  mutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_FAST);
  if (mutexp == NULL) {
    MARPAXML_ERRORX("sqlite3_mutex_alloc(SQLITE_MUTEX_FAST): %s (latest errno string) at %s:%d\n", strerror(errno), __FILE__, __LINE__);
    goto error;
  }
  sqlite3_mutex_enter(mutexp);
  sqlite3_mutex_leave(master_mutexp);
  master_mutexp = NULL;

  /* Note: u_init() is thread-safe */
  u_init(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    MARPAXML_ERRORX("u_init(): %s at %s:%d\n", u_errorName(uErrorCode), __FILE__, __LINE__);
    goto error;
  }

  /* Open the DB */
  MARPAXML_INFOX("Opening database \"%s\"\n", marpaXml_DOM_Option.dbFilename);
  if ((sqliteRc = sqlite3_open_v2(marpaXml_DOM_Option.dbFilename, &dbp, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE|SQLITE_OPEN_FULLMUTEX|SQLITE_OPEN_SHAREDCACHE|SQLITE_OPEN_URI, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_open_v2(%s%s%s, ...): %s at %s:%d\n",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        marpaXml_DOM_Option.dbFilename != NULL ? marpaXml_DOM_Option.dbFilename : "",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    goto error;
  }

  /* Very first thing: load collation */
  if (_marpaXml_prepare(dbp, _MARPAXML_LOADCOLLATION, &loadcollation_stmt) == marpaXml_false) {
    goto error;
  }

  if (_marpaXml_bind_text(loadcollation_stmt, 1, marpaXml_DOM_Option.locale)       == marpaXml_false ||
      _marpaXml_bind_int (loadcollation_stmt, 2, marpaXml_DOM_Option.collStrength) == marpaXml_false) {
    goto error;
  }
  do {
  } while ((sqliteRc = _marpaXml_step(loadcollation_stmt)) == SQLITE_ROW);

  /* Free the statement regardles of the last status */
  if (_marpaXml_finalize(&loadcollation_stmt) == marpaXml_false) {
    loadcollation_stmt = NULL;
    goto error;
  }

  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    goto error;
  }

  /* Create the tables */
  for (i = 0; i < _DDL_NBSTATEMENT; i++) {
    if (_marpaXml_exec(dbp, _DDL_STATEMENT[i], NULL, NULL) == marpaXml_false) {
      goto error;
    }
  }

  /* Create the xxhash function */
  if (marpaXml_HashInit(&xxhp) == MARPAXML_HASH_FALSE) {
    MARPAXML_ERRORX("marpaXml_HashInit(): %s\n", strerror(errno));
    goto error;
  }
  if (_marpaXml_create_function(dbp, "xxhash", 1,  SQLITE_UTF8|SQLITE_DETERMINISTIC, xxhp, &_marpaXml_xxhash_xFunc, NULL, NULL, _marpaXml_xxhash_xDestroy) == marpaXml_false) {
    goto error;
  }

  /* Prepare all the statements */
  i = -1;
  while (_marpaXml_stmt[++i].sql != NULL) {
    if (_marpaXml_prepare(dbp, _marpaXml_stmt[i].sql, &_marpaXml_stmt[i].stmt) == marpaXml_false) {
      goto error;
    }
  }

  /* Fill hardcoded data using standard methods */
/*
  if ((_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "1.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "1.0") == marpaXml_false) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "2.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "2.0") == marpaXml_false) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "3.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "3.0") == marpaXml_false) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "1.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "1.0") == marpaXml_false) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "2.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "2.0") == marpaXml_false) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "3.0") ==  marpaXml_false && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "3.0") == marpaXml_false)

      ||

      (_marpaXml_StringList_contains((char*) "canonical-form")                ==  marpaXml_false && _marpaXml_String_insert((char*) "canonical-form")                == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "cdata-sections")                ==  marpaXml_false && _marpaXml_String_insert((char*) "cdata-sections")                == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "check-character-normalization") ==  marpaXml_false && _marpaXml_String_insert((char*) "check-character-normalization") == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "comments")                      ==  marpaXml_false && _marpaXml_String_insert((char*) "comments")                      == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "datatype-normalization")        ==  marpaXml_false && _marpaXml_String_insert((char*) "datatype-normalization")        == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "element-content-whitespace")    ==  marpaXml_false && _marpaXml_String_insert((char*) "element-content-whitespace")    == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "entities")                      ==  marpaXml_false && _marpaXml_String_insert((char*) "entities")                      == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "error-handler")                 ==  marpaXml_false && _marpaXml_String_insert((char*) "error-handler")                 == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "infoset")                       ==  marpaXml_false && _marpaXml_String_insert((char*) "infoset")                       == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "namespaces")                    ==  marpaXml_false && _marpaXml_String_insert((char*) "namespaces")                    == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "namespace-declarations")        ==  marpaXml_false && _marpaXml_String_insert((char*) "namespace-declarations")        == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "normalize-characters")          ==  marpaXml_false && _marpaXml_String_insert((char*) "normalize-characters")          == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "schema-location")               ==  marpaXml_false && _marpaXml_String_insert((char*) "schema-location")               == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "schema-type")                   ==  marpaXml_false && _marpaXml_String_insert((char*) "schema-type")                   == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "split-cdata-sections")          ==  marpaXml_false && _marpaXml_String_insert((char*) "split-cdata-sections")          == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "validate")                      ==  marpaXml_false && _marpaXml_String_insert((char*) "validate")                      == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "validate-if-schema")            ==  marpaXml_false && _marpaXml_String_insert((char*) "validate-if-schema")            == marpaXml_false) ||
      (_marpaXml_StringList_contains((char*) "well-formed")                   ==  marpaXml_false && _marpaXml_String_insert((char*) "well-formed")                   == marpaXml_false)

      ) {

        goto error;
      }
*/

  /* OK */
  _initialized = marpaXml_true;
  _dbp = dbp;

  sqlite3_mutex_leave(mutexp);

  return marpaXml_true;

 error:
  if (master_mutexp != NULL) {
    sqlite3_mutex_leave(master_mutexp);
  }
  if (dbp != NULL) {
    sqlite3_close_v2(dbp);
  }
  if (mutexp != NULL) {
    sqlite3_mutex_leave(mutexp);
    sqlite3_mutex_free(mutexp);
  }
  if (loadcollation_stmt != NULL) {
    _marpaXml_finalize(&loadcollation_stmt);
  }

  return marpaXml_false;
}

/*******************************************************************/
/*                                                                 */
/*               Transaction Management                            */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Begin() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_INTERNALCALL, "_marpaXml_Transaction_Begin");
  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_BINDING, _marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_End() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_INTERNALCALL, "_marpaXml_Transaction_End");
  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_BINDING, _marpaXml_stmt[_marpaXml_Transaction_End_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_End_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_End_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Rollback() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_INTERNALCALL, "_marpaXml_Transaction_Rollback");
  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_BINDING, _marpaXml_stmt[_marpaXml_Transaction_Rollback_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_Rollback_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_Rollback_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/*                                                                 */
/*                        DOMException                             */
/*                                                                 */
/*******************************************************************/
/* ---------------------------------------------------------------- */
/* marpaXml_DOMException_new                                        */
/* ---------------------------------------------------------------- */
marpaXml_DOMException_t *marpaXml_DOMException_new(short code, marpaXml_String_t *messagep) {
  marpaXml_DOMException_t *rc;

  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMException_new", NULL);
  rc = _marpaXml_DOMException_new(code, messagep);
  MARPAXML_DOM_DB_API_TRAILER(rc != NULL ? marpaXml_true : marpaXml_false, NULL);

  return rc;
}

static C_INLINE marpaXml_DOMException_t *_marpaXml_DOMException_new(short code, marpaXml_String_t *messagep) {
  marpaXml_DOMException_t *rc;
  int                      sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_INTERNALCALL, "_marpaXml_DOMException_new");

  if (((rc = malloc(sizeof(marpaXml_DOMException_t)))                    == NULL) ||
      ((rc->_contextp = malloc(sizeof(marpaXml_DOMException_Context_t))) == NULL)) {
    MARPAXML_ERRORX("malloc() returns NULL: %s at %s:%d\n", strerror(errno), __FILE__, __LINE__);
    marpaXml_DOMException_free(&rc);
    return NULL;
  }
  rc->_contextp->id = 0;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_BINDING, _marpaXml_stmt[_marpaXml_DOMException_new_e].sql);

  if (_marpaXml_bind_int (_marpaXml_stmt[_marpaXml_DOMException_new_e].stmt, 1, code                             ) == marpaXml_false ||
      _marpaXml_bind_text(_marpaXml_stmt[_marpaXml_DOMException_new_e].stmt, 2, marpaXml_String_getUtf8(messagep)) == marpaXml_false) {
    _marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt);
    marpaXml_DOMException_free(&rc);
    return NULL;
  }

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_DOMException_new_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt) == marpaXml_false) {
    marpaXml_DOMException_free(&rc);
    return NULL;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    marpaXml_DOMException_free(&rc);
    return NULL;
  }
  rc->_contextp->id = sqlite3_last_insert_rowid(_dbp);
  if (rc->_contextp->id <= 0) {
    MARPAXML_ERRORX("sqlite3_last_insert_rowid return a number <= 0 at %s:%d\n", __FILE__, __LINE__);
    marpaXml_DOMException_free(&rc);
    return NULL;
  }

  MARPAXML_TRACEX("[%s] %lld\n", _MARPAXML_INSERTID, (unsigned long long int) rc->_contextp->id);

  return rc;
}

/* ---------------------------------------------------------------- */
/* marpaXml_DOMException_free                                       */
/* Note: the lifetime of a DOMException in the DB is the object     */
/* ---------------------------------------------------------------- */

void marpaXml_DOMException_free(marpaXml_DOMException_t **thispp) {
  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMException_free",);
  _marpaXml_DOMException_free(thispp);
  MARPAXML_DOM_DB_API_TRAILER(marpaXml_true,);

  return;
}

static C_INLINE void _marpaXml_DOMException_free(marpaXml_DOMException_t **thispp) {
  marpaXml_DOMException_t *thisp;
  int                      sqliteRc;

  if (thispp != NULL) {
    thisp = *thispp;

    if (thisp != NULL) {
      if (thisp->_contextp != NULL && thisp->_contextp->id > 0) {
        MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_BINDING, _marpaXml_stmt[_marpaXml_DOMException_free_e].sql);
        if (_marpaXml_bind_int64(_marpaXml_stmt[_marpaXml_DOMException_free_e].stmt, 1, thisp->_contextp->id) == marpaXml_true) {
          do {
          } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_DOMException_free_e].stmt)) == SQLITE_ROW);
          if (sqliteRc != SQLITE_DONE) {
            MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
          }
        }
        _marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt);
        free(thisp->_contextp);
      }
      free(thisp);
    }

    *thispp = NULL;
  }
}

