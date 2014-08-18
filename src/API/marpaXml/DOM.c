/*
 * DOM Level 3 Core implementation using SQLite
 * All string are internally UTF16 with native host byte endiannes
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include <unicode/ustring.h>
#include <unicode/uchar.h>
#include <unicode/uclean.h>
#include "sqlite3.h"

#include "API/marpaXml/DOM.h"
#include "internal/config.h"
#include "internal/messageBuilder.h"
#include "internal/hash.h"
#include "xxhash-read-only/xxhash.h"
#include "../db/Dom Level 3 Core.h"

/*************/
/* Constants */
/*************/
static const char *STRINGLITERAL_DB_LOADCOLLATION = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)"; /* UTF-8 compatible */

/********************/
/* Static variables */
/********************/
static sqlite3_stmt         *_db_loadcollation_stmt = NULL;
static sqlite3              *_dbp = NULL;
static sqlite3_mutex        *_mutexp = NULL;
static marpaXml_DOMBoolean_t _initialized = MARPAXML_DOMBOOLEAN_FALSE;
static struct s_DOMError_ {
  unsigned short        severity;
  marpaXml_DOMString_t  message;
  marpaXml_DOMString_t  type;
  marpaXml_DOMLocator_t location;
} s_DOMError = {MARPAXML_DOM_SEVERITY_NONE, NULL, NULL, 0};
static marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_WARNING, &_marpaXmlLog_defaultCallback, NULL, ":memory", NULL, -1};
static marpaXmlLog_t *marpaXmlLogp = NULL;

typedef struct marpaXml_DOM_data {
  const char   *name;
  const char   *sql;
} marpaXml_DOM_data_t;
static marpaXml_DOM_data_t marpaXml_DOM_data[] = {
  { "DOMStringList_counter.{nbrows}", "INSERT INTO DOMStringList_counter (nbrows) SELECT 0 WHERE NOT EXISTS (SELECT 1 FROM DOMStringList_counter)" },
  { "DOMImplementation_counter.{nbrows}", "INSERT INTO DOMImplementation_counter (nbrows) SELECT 0 WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation_counter)" },
  { NULL, NULL }
};

typedef struct marpaXml_DOM_trigger {
  const char   *name;
  const char   *sql;
} marpaXml_DOM_trigger_t;
static marpaXml_DOM_trigger_t marpaXml_DOM_trigger[] = {
  /* ------------- */
  /* DOMStringList */
  /* ------------- */
  { "DOMStringList_insert_trigger", "CREATE TRIGGER IF NOT EXISTS DOMStringList_insert_trigger INSERT ON DOMStringList FOR EACH ROW BEGIN UPDATE DOMStringList_counter SET nbrows = nbrows + 1; END " },
  { "DOMStringList_delete_trigger", "CREATE TRIGGER IF NOT EXISTS DOMStringList_delete_trigger DELETE ON DOMStringList FOR EACH ROW BEGIN UPDATE DOMStringList_counter SET nbrows = nbrows - 1; UPDATE DOMStringList SET _ordering = _ordering - 1 where (_ordering > OLD._ordering); END " },

  /* ----------------- */
  /* DOMImplementation */
  /* ----------------- */
  { "DOMImplementation_insert_trigger", "CREATE TRIGGER IF NOT EXISTS DOMImplementation_insert_trigger INSERT ON DOMImplementation FOR EACH ROW BEGIN UPDATE DOMImplementation_counter SET nbrows = nbrows + 1; END " },
  { "DOMImplementation_delete_trigger", "CREATE TRIGGER IF NOT EXISTS DOMImplementation_delete_trigger DELETE ON DOMImplementation FOR EACH ROW BEGIN UPDATE DOMImplementation_counter SET nbrows = nbrows - 1; UPDATE DOMImplementation SET _ordering = _ordering - 1 where (_ordering > OLD._ordering); END " },

  { NULL, NULL }
};

typedef struct marpaXml_DOM_stmt {
  const char   *name;
  const char   *sql;
  sqlite3_stmt *stmt;
} marpaXml_DOM_stmt_t;
enum {
  /* ------------- */
  /* DOMStringList */
  /* ------------- */
  _marpaXml_DOMStringList_insert_e = 0,
  _marpaXml_DOMStringList_delete_e,
  marpaXml_DOMStringList_item_e,
  marpaXml_DOMStringList_getLength_e,
  marpaXml_DOMStringList_contains_e,

  /* ----------------- */
  /* DOMImplementation */
  /* ----------------- */
  marpaXml_DOMImplementation_insert_e,
  _marpaXml_DOMImplementation_delete_e,
  marpaXml_DOMImplementation_hasFeature_e,
  _marpaXml_DOMImplementation_count_e,
};
static marpaXml_DOM_stmt_t marpaXml_DOM_stmt[] = {
  /* ------------- */
  /* DOMStringList */
  /* ------------- */
  { "_marpaXml_DOMStringList_insert",
    "INSERT INTO DOMStringList (item, _itemHash, _ordering) SELECT ?1, xxhash(?1), nbrows FROM DOMStringList_counter", NULL }, /* Will trigger DOMStringList_insert_trigger */
  { "_marpaXml_DOMStringList_delete",
    "DELETE FROM DOMStringList WHERE (id = ?1)", NULL },                                                                       /* Will trigger DOMStringList_delete_trigger */
  { "marpaXml_DOMStringList_item",
    "SELECT item FROM DOMStringList WHERE (_ordering = ?1)", NULL },                                                              /* _ordering is indexed */
  { "marpaXml_DOMStringList_getLength",
    "SELECT nbrows FROM DOMStringList_counter", NULL },
  { "marpaXml_DOMStringList_contains",
    "SELECT 1 FROM DOMStringList WHERE ((_itemHash = xxhash(?1)) AND (item = ?1 COLLATE BINARY))", NULL },                    /* _itemHash is indexed */

  /* ----------------- */
  /* DOMImplementation */
  /* ----------------- */
  { "marpaXml_DOMImplementation_insert",
    "INSERT INTO DOMImplementation (feature, _featureHash, version, _versionHash, _ordering) SELECT ?1, xxhash(?1), ?2, xxhash(?2), nbrows FROM DOMImplementation_counter", NULL }, /* Will trigger DOMImplementation_insert_trigger */
  { "_marpaXml_DOMImplementation_delete",
    "DELETE FROM DOMImplementation WHERE (id = ?1)", NULL },                                                               /* Will trigger DOMImplementation_delete_trigger */
  { "marpaXml_DOMImplementation_hasFeature",
    "SELECT 1 FROM DOMImplementation WHERE ((feature LIKE ?1) AND ((?2 IS NULL) OR (version = ?2)))", NULL },           /* feature test is case insensitive, version is not (contains only digits or dot -;) */
  { "_marpaXml_DOMImplementation_count",
    "SELECT count(id) FROM DOMImplementation", NULL },
  { NULL, NULL, NULL }
};

/*********************/
/* Static prototypes */
/*********************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(sqlite3 *db, const char *sql);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_prepare(sqlite3 *db, const char *zSql, sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_create_function(sqlite3 *db,
								const char *zFunctionName,
								int nArg,
								int eTextRep,
								void *pApp,
								void (*xFunc)(sqlite3_context*,int,sqlite3_value**),
								void (*xStep)(sqlite3_context*,int,sqlite3_value**),
								void (*xFinal)(sqlite3_context*),
								void(*xDestroy)(void*));
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_reset(sqlite3_stmt *pStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_finalize(sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_text(sqlite3_stmt* pStmt, int pos, const char *txt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_int(sqlite3_stmt* pStmt, int pos, int val);
static C_INLINE void _marpaXml_DOMError_set(marpaXml_DOM_ErrorSeverity_t severity,
					    marpaXml_DOMString_t         message,
					    marpaXml_DOMString_t         type,
					    marpaXml_DOMLocator_t        location);
static C_INLINE void _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg);
static C_INLINE void _marpaXml_xxhash_xDestroy(void *p);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_insert(marpaXml_DOMString_t feature, marpaXml_DOMString_t version);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_count(sqlite_int64 *countp);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version);

/**********/
/* Macros */
/**********/
/* Per-def the mutex macros can never be called before marpaXml_DOM_init() has been called */
#define MARPAXML_DOM_MUTEX_ENTER {if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {sqlite3_mutex_enter(_mutexp);}}
#define MARPAXML_DOM_MUTEX_LEAVE {if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {sqlite3_mutex_leave(_mutexp);}}
#define MARPAXML_DOM_DB_MUTEX_ENTER sqlite3_mutex_enter(sqlite3_db_mutex(_dbp))
#define MARPAXML_DOM_DB_MUTEX_LEAVE sqlite3_mutex_leave(sqlite3_db_mutex(_dbp))
#define MARPAXML_DOM_DB_BEGTRANS _marpaXml_exec(_dbp, "BEGIN IMMEDIATE TRANSACTION")
#define MARPAXML_DOM_DB_ENDTRANS _marpaXml_exec(_dbp, "END TRANSACTION")
#define MARPAXML_DOM_DB_ROLLBACK _marpaXml_exec(_dbp, "ROLLBACK TRANSACTION")
#define MARPAXML_DOM_DB_API_HEADER   \
  if (marpaXml_DOM_init(NULL) == MARPAXML_DOMBOOLEAN_FALSE) {	\
    return MARPAXML_DOMBOOLEAN_FALSE;				\
  }								\
  MARPAXML_DOM_DB_MUTEX_ENTER;					\
  if (MARPAXML_DOM_DB_BEGTRANS == MARPAXML_DOMBOOLEAN_FALSE) {	\
    MARPAXML_DOM_DB_MUTEX_LEAVE;				\
    return MARPAXML_DOMBOOLEAN_FALSE;				\
  }
#define MARPAXML_DOM_DB_API_TRAILER(rc)					\
  if ((rc) == MARPAXML_DOMBOOLEAN_FALSE || MARPAXML_DOM_DB_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) { \
    MARPAXML_DOM_DB_ROLLBACK;						\
    MARPAXML_DOM_DB_MUTEX_LEAVE;					\
    return MARPAXML_DOMBOOLEAN_FALSE;					\
  }									\
  MARPAXML_DOM_DB_MUTEX_LEAVE;

/*******************************************************************/
/* _marpaXml_xxhash_xFunc                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg) {
  void       *xxhp = sqlite3_user_data(pCtx);
  const char *zString;

  assert(nArg==1);
  zString = (const char *)sqlite3_value_text(apArg[0]);

  sqlite3_result_int64(pCtx, marpaXml_HashLongLong(xxhp, zString, zString != NULL ? strlen(zString) : 0)); 
}

/*******************************************************************/
/* _marpaXml_xxhash_xDestroy                                       */
/*******************************************************************/
static C_INLINE void _marpaXml_xxhash_xDestroy(void *p) {
  if (p != NULL) {
    free(p);
  }
}

/*******************************************************************/
/* _marpaXml_exec                                                  */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(sqlite3 *db, const char *sql) {
  char *errmsg = NULL;
  int   sqliteRc;

  MARPAXML_TRACEX("%s\n", sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_exec(db, sql, NULL, NULL, &errmsg)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_exec(..., %s%s%s, ...): %s\n", sql != NULL ? "\"" : "",  sql != NULL ? sql : "(null)", sql != NULL ? "\"" : "",  errmsg != NULL ? errmsg : "(null)");
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", errmsg != NULL ? errmsg : "(null)"),
			   NULL,
			   0
			   );
    if (errmsg != NULL) {
      sqlite3_free(errmsg);
    }
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_create_function                                       */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_create_function(sqlite3 *db,
								const char *name,
								int nArg,
								int eTextRep,
								void *pApp,
								void (*xFunc)(sqlite3_context*,int,sqlite3_value**),
								void (*xStep)(sqlite3_context*,int,sqlite3_value**),
								void (*xFinal)(sqlite3_context*),
								void (*xDestroy)(void*)) {
  int sqliteRc;

  MARPAXML_TRACEX("Create FUNCTION: %s\n", name != NULL ? name : "(null)");
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
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_prepare                                               */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **ppStmt) {
  int sqliteRc;

  MARPAXML_TRACEX("Prepare SQL: %s\n", sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_prepare_v2(_dbp, sql, -1, ppStmt, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_prepare_v2(): %s\n\nSQL sequence was:\n\n%s\n", sqlite3_errstr(sqliteRc), sql);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_finalize                                              */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_finalize(sqlite3_stmt **ppStmt) {
  int sqliteRc;

  if ((sqliteRc = sqlite3_finalize(*ppStmt)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_finalize(): %s\n", sqlite3_errstr(sqliteRc));
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  } else {
    *ppStmt = NULL;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_reset                                                 */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_reset(sqlite3_stmt *pStmt) {
  int sqliteRc;

  if ((sqliteRc = sqlite3_reset(pStmt)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_reset(): %s\n", sqlite3_errstr(sqliteRc));
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_bind_text                                             */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_text(sqlite3_stmt* pStmt, int pos, const char *txt) {
  int sqliteRc;

  MARPAXML_TRACEX("sqlite3_bind_text(%p, %d, %p %s%s%s)\n", pStmt, pos, txt, txt != NULL ? "\"" : "", txt != NULL ? txt : "", txt != NULL ? "\"" : "");

  if ((sqliteRc = sqlite3_bind_text(pStmt, pos, txt, -1, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* _marpaXml_bind_int                                              */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_int(sqlite3_stmt* pStmt, int pos, int val) {
  int sqliteRc;

  MARPAXML_TRACEX("sqlite3_bind_int(%p, %d, %d)\n", pStmt, pos, val);

  if ((sqliteRc = sqlite3_bind_int(pStmt, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* marpaXml_DOM_release                                            */
/*******************************************************************/
marpaXml_DOMBoolean_t marpaXml_DOM_release(void) {
  int                   i;
  int                   sqliteRc;
  marpaXml_DOMBoolean_t rc = MARPAXML_DOMBOOLEAN_TRUE;

  /* Not thread-safe */
  if (_initialized == MARPAXML_DOMBOOLEAN_FALSE || _dbp == NULL) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Free the statements */
  i = -1;
  while (marpaXml_DOM_stmt[++i].stmt != NULL) {
    if (_marpaXml_finalize(&marpaXml_DOM_stmt[i].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
      rc = MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Free internal mutex */
  if (_mutexp != NULL) {
    sqlite3_mutex_free(_mutexp);
    _mutexp = NULL;
  }

  /* Close connection to the DB */
  if ((sqliteRc = sqlite3_close_v2(_dbp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_close_v2(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    rc = MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Free static DOMError content */
  _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_NONE, NULL, NULL, 0);

  /* Free logging */
  if (marpaXmlLogp != NULL) {
    marpaXmlLog_freev(&marpaXmlLogp);
  }

#ifdef MARPAXML_DOM_TEST_APPLICATION_ONLY
  /* ICU recommendation is to NOT call this. This is done automatically at library unload */
  u_cleanup();
#endif

  /* Pretend we were not initialized */
  _initialized = MARPAXML_DOMBOOLEAN_FALSE;

  return rc;
}

/*******************************************************************/
/* marpaXml_DOM_init                                               */
/*******************************************************************/
marpaXml_DOMBoolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp) {
  UErrorCode     uErrorCode = U_ZERO_ERROR;
  sqlite3_mutex *masterMutexp;
  int            sqliteRc;
  int            i;
  void          *xxhp;

  /* We first check _initialized in a non thread-safe way for quick return */
  if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {
    return MARPAXML_DOMBOOLEAN_TRUE;
  }

  /* Note: sqlite3_initialize() is thread-safe and only the first one is effective */
  if ((sqliteRc = sqlite3_initialize()) != SQLITE_OK) {
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("sqlite3_initialize(): %s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* We intentionnaly do not use ICU's mutex because they say their interface may change */
  /* On the other hand, sqlite says their mutex interface can be used */

  /* SQLite already has global mutexes, we use its master mutex to completely block any DOM access */
  masterMutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_STATIC_MASTER);
  if (masterMutexp == NULL) {
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", strerror(errno)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  sqlite3_mutex_enter(masterMutexp);

  /* We are synchronized here: this mean we can setup logging right now if not already done */
  if (marpaXml_DOM_Optionp != NULL) {
    marpaXml_DOM_Option = *marpaXml_DOM_Optionp;
  }

  if (marpaXmlLogp == NULL) {
    marpaXmlLogp = marpaXmlLog_newp(marpaXml_DOM_Option.logCallbackp, marpaXml_DOM_Option.logCallbackDatavp, marpaXml_DOM_Option.logLevelWantedi);
  }

  _mutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_FAST);
  if (_mutexp == NULL) {
    MARPAXML_ERRORX("sqlite3_mutex_alloc(SQLITE_MUTEX_FAST): %s (latest errno string) at %s:%d\n", strerror(errno), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", strerror(errno)),
			   NULL,
			   0
			   );
    sqlite3_mutex_leave(masterMutexp);
    return MARPAXML_DOMBOOLEAN_FALSE;
  }
  sqlite3_mutex_enter(_mutexp);
  sqlite3_mutex_leave(masterMutexp);

  /* From now on we are sure we are in a synchronized call: we can recheck _initialized */
  if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {
    sqlite3_mutex_leave(_mutexp);
    return MARPAXML_DOMBOOLEAN_TRUE;
  }

  /* Note: u_init() is thread-safe */
  u_init(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    MARPAXML_ERRORX("u_init(): %s at %s:%d\n", u_errorName(uErrorCode), __FILE__, __LINE__),
      _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			     messageBuilder("%s", u_errorName(uErrorCode)),
			     NULL,
			     0
			     );
    sqlite3_mutex_leave(_mutexp);
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Open the DB */
  MARPAXML_INFOX("Opening database \"%s\"\n", marpaXml_DOM_Option.dbFilename);
  if ((sqliteRc = sqlite3_open_v2(marpaXml_DOM_Option.dbFilename, &_dbp, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE|SQLITE_OPEN_FULLMUTEX|SQLITE_OPEN_SHAREDCACHE|SQLITE_OPEN_URI, NULL)) != SQLITE_OK) {
    sqlite3_mutex_leave(_mutexp);
    MARPAXML_ERRORX("sqlite3_open_v2(%s, ...): %s at %s:%d\n", marpaXml_DOM_Option.dbFilename, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Very first thing: load collation */
  if (_marpaXml_prepare(_dbp, STRINGLITERAL_DB_LOADCOLLATION, &_db_loadcollation_stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    sqlite3_mutex_leave(_mutexp);
    sqlite3_close_v2(_dbp);
    _dbp = NULL;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  if (_marpaXml_bind_text(_db_loadcollation_stmt, 1, marpaXml_DOM_Option.locale)       == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_int (_db_loadcollation_stmt, 2, marpaXml_DOM_Option.collStrength) == MARPAXML_DOMBOOLEAN_FALSE) {
    sqlite3_mutex_leave(_mutexp);
    sqlite3_close_v2(_dbp);
    _dbp = NULL;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }
  do {
  } while ((sqliteRc = sqlite3_step(_db_loadcollation_stmt)) == SQLITE_ROW);

  if (sqliteRc != SQLITE_DONE) {
    sqlite3_mutex_leave(_mutexp);
    sqlite3_close_v2(_dbp);
    MARPAXML_ERRORX("sqlite3_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    _dbp = NULL;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }
  if (_marpaXml_finalize(&_db_loadcollation_stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    sqlite3_mutex_leave(_mutexp);
    sqlite3_close_v2(_dbp);
    _dbp = NULL;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Create the tables */
  for (i = 0; i < STRINGLITERAL_DDL_NBSTATEMENT; i++) {
    if (_marpaXml_exec(_dbp, STRINGLITERAL_DDL[i]) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Create the xxhash function */
  xxhp = XXH_init();
  if (xxhp == NULL) {
    MARPAXML_ERRORX("XXH_init(): %s\n", strerror(errno));
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", strerror(errno)),
			   NULL,
			   0
			   );
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }
  if (_marpaXml_create_function(_dbp, "xxhash", 1,  SQLITE_UTF8|SQLITE_DETERMINISTIC, xxhp, &_marpaXml_xxhash_xFunc, NULL, NULL, _marpaXml_xxhash_xDestroy) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }

  /* Insert triggers */
  i = -1;
  while (marpaXml_DOM_trigger[++i].name != NULL && marpaXml_DOM_trigger[i].sql != NULL) {
    if (_marpaXml_exec(_dbp, marpaXml_DOM_trigger[i].sql) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Insert datas */
  if (MARPAXML_DOM_DB_BEGTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  i = -1;
  while (marpaXml_DOM_data[++i].name != NULL && marpaXml_DOM_data[i].sql != NULL) {
    if (_marpaXml_exec(_dbp, marpaXml_DOM_data[i].sql) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  if (MARPAXML_DOM_DB_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Prepare the statements */
  i = -1;
  while (marpaXml_DOM_stmt[++i].name != NULL && marpaXml_DOM_stmt[i].sql != NULL) {
    if (_marpaXml_prepare(_dbp, marpaXml_DOM_stmt[i].sql, &marpaXml_DOM_stmt[i].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Done */
  _initialized = MARPAXML_DOMBOOLEAN_TRUE;

  /* Fill other data using standard methods */
  if (marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "1.0") == MARPAXML_DOMBOOLEAN_FALSE ||
      marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "2.0") == MARPAXML_DOMBOOLEAN_FALSE ||
      marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "3.0") == MARPAXML_DOMBOOLEAN_FALSE ||
      marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "1.0") == MARPAXML_DOMBOOLEAN_FALSE ||
      marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "2.0") == MARPAXML_DOMBOOLEAN_FALSE ||
      marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "3.0") == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  sqlite3_mutex_leave(_mutexp);

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/*                                                                 */
/*                          DOMError                               */
/*                                                                 */
/*******************************************************************/
unsigned short marpaXml_DOMError_getSeverity(void) {
  unsigned short severity;

  MARPAXML_DOM_MUTEX_ENTER;
  severity = s_DOMError.severity;
  MARPAXML_DOM_MUTEX_LEAVE;

  return severity;
}

marpaXml_DOMString_t  marpaXml_DOMError_getMessage(void) {
  marpaXml_DOMString_t  message;

  MARPAXML_DOM_MUTEX_ENTER;
  message = s_DOMError.message;
  MARPAXML_DOM_MUTEX_LEAVE;

  return message;
}

marpaXml_DOMString_t  marpaXml_DOMError_getType(void) {
  marpaXml_DOMString_t  type;

  MARPAXML_DOM_MUTEX_ENTER;
  type = s_DOMError.type;
  MARPAXML_DOM_MUTEX_LEAVE;

  return type;
}

marpaXml_DOMLocator_t marpaXml_DOMError_getLocation(void) {
  marpaXml_DOMLocator_t location;

  MARPAXML_DOM_MUTEX_ENTER;
  location = s_DOMError.location;
  MARPAXML_DOM_MUTEX_LEAVE;

  return location;
}

/* Per-def we always send to DOMError strings that are allocated via messageBuilder */
static C_INLINE void _marpaXml_DOMError_set(marpaXml_DOM_ErrorSeverity_t severity,
					    marpaXml_DOMString_t         message,
					    marpaXml_DOMString_t         type,
					    marpaXml_DOMLocator_t        location) {
  MARPAXML_DOM_MUTEX_ENTER;

  if ((s_DOMError.message != NULL)  && (s_DOMError.message != messageBuilder_internalErrors())) {
    free(s_DOMError.message);
  }
  if ((s_DOMError.type != NULL)  && (s_DOMError.type != messageBuilder_internalErrors())) {
    free(s_DOMError.type);
  }

  s_DOMError.severity = severity;
  s_DOMError.message = (message != NULL) ? strdup(message) : NULL;
  s_DOMError.type = (type != NULL) ? strdup(type) : NULL;
  s_DOMError.location = location;

  MARPAXML_DOM_MUTEX_LEAVE;
}

/*******************************************************************/
/*                                                                 */
/*                        DOMStringList                            */
/*                                                                 */
/*******************************************************************/
/* Introduced in DOM Level 3: */
marpaXml_DOMString_t marpaXml_DOMStringList_item(unsigned long long int index) {
}

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_count(sqlite_int64 *countp) {
  int                   sqliteRc;
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("%s\n", marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].sql);

  while (1) {
    if ((sqliteRc = sqlite3_step(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].stmt)) == SQLITE_ROW) {
      /* We expect (at least) one row */
      *countp = sqlite3_column_int64(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].stmt, 0);
      domRc = MARPAXML_DOMBOOLEAN_TRUE;
    } else {
      break;
    }
  }

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }
  
  return domRc;
}

/* --------------------------------------------------------------- */

marpaXml_DOMBoolean_t marpaXml_DOMImplementation_insert(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  marpaXml_DOMBoolean_t domRc;

  MARPAXML_DOM_DB_API_HEADER
  domRc = _marpaXml_DOMImplementation_insert(feature, version);
  MARPAXML_DOM_DB_API_TRAILER(domRc);

  return domRc;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_insert(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  int sqliteRc;

  MARPAXML_TRACEX("%s\n", marpaXml_DOM_stmt[marpaXml_DOMImplementation_insert_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_insert_e].stmt, 1, feature) == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_insert_e].stmt, 2, version) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  do {
  } while ((sqliteRc = sqlite3_step(marpaXml_DOM_stmt[marpaXml_DOMImplementation_insert_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMImplementation_insert_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("sqlite3_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/* --------------------------------------------------------------- */

marpaXml_DOMBoolean_t marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  marpaXml_DOMBoolean_t domRc;

  MARPAXML_DOM_DB_API_HEADER
  domRc = _marpaXml_DOMImplementation_hasFeature(feature, version);
  MARPAXML_DOM_DB_API_TRAILER(MARPAXML_DOMBOOLEAN_TRUE)

  return domRc;
}

/* --------------------------------------------------------------- */

marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("%s\n", marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 1, feature) == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 2, version) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  while (1) {
    if (sqlite3_step(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt) == SQLITE_ROW) {
      domRc = MARPAXML_DOMBOOLEAN_TRUE;
    } else {
      break;
    }
  }

  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return domRc;
}
