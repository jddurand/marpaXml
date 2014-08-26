#include "internal/config.h"

#include "sqlite3.h"
#include "marpaXml/DOM2.h"

#include "internal/messageBuilder.h"
#include "internal/hash.h"

/********************************************************************************/
/*                                 Constants                                    */
/********************************************************************************/
static const char *STRINGLITERAL_DB_LOADCOLLATION = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)"; /* UTF-8 compatible */
static const char *STRINGLITERAL_DB_EXEC         = "   EXEC";
static const char *STRINGLITERAL_DB_PREPARE      = "PREPARE";
static const char *STRINGLITERAL_DB_NEWFUNC      = "NEWFUNC";
static const char *STRINGLITERAL_DB_BINDING      = "    SQL";
static const char *STRINGLITERAL_DB_BINDTEXT     = "   BIND";
static const char *STRINGLITERAL_DB_BINDINT      = "   BIND";
static const char *STRINGLITERAL_DB_BINDINT64    = "   BIND";
static const char *STRINGLITERAL_DB_STEP         = "   STEP";
static const char *STRINGLITERAL_DB_APICALL      = ">>> API";
static const char *STRINGLITERAL_DB_INTERNALCALL = "       ";

static const char *STRINGLITERAL_DB_SQLITE_BUSY     = "SQLITE_BUSY";
static const char *STRINGLITERAL_DB_SQLITE_DONE     = "SQLITE_DONE";
static const char *STRINGLITERAL_DB_SQLITE_ROW      = "SQLITE_ROW";
static const char *STRINGLITERAL_DB_SQLITE_ERROR    = "SQLITE_ERROR";
static const char *STRINGLITERAL_DB_SQLITE_MISUSE   = "SQLITE_MISUSE";

/********************************************************************************/
/*                           Static variables                                   */
/********************************************************************************/
static sqlite3_stmt         *db_loadcollation_stmt = NULL;
static sqlite3              *dbp = NULL;
static sqlite3_mutex        *mutexp = NULL;
static marpaXml_boolean_t    initialized = marpaXml_false;
static marpaXml_DOM_Option_t marpaXml_DOM_Option = {":memory", NULL, -1, { NULL, NULL, MARPAXML_LOGLEVEL_WARNING }};
static marpaXmlLog_t        *marpaXmlLogp = NULL;

typedef struct marpaXml_DOM_data {
  const char   *name;
  const char   *sql;
} marpaXml_DOM_data_t;
static marpaXml_DOM_data_t marpaXml_DOM_data[] = {
  {
    "DOMString_counter.{nbrows}",
    "INSERT INTO DOMString_counter (nbrows) SELECT 0 WHERE NOT EXISTS (SELECT 1 FROM DOMString_counter)"
  },
  {
    "DOMImplementation_counter.{nbrows}",
    "INSERT INTO DOMImplementation_counter (nbrows) SELECT 0 WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation_counter)"
  },
  {
    "DOMNode_counter.{nbrows}",
    "INSERT INTO DOMNode_counter (nbrows) SELECT 0 WHERE NOT EXISTS (SELECT 1 FROM DOMNode_counter)"
  },
  { NULL, NULL }
};

typedef struct marpaXml_DOM_trigger {
  const char   *sql;
} marpaXml_DOM_trigger_t;
static marpaXml_DOM_trigger_t marpaXml_DOM_trigger[] = {
  /* ------------------*/
  /* DOMString counter */
  /* ------------------*/
  { "CREATE TRIGGER IF NOT EXISTS DOMString_insert_trigger INSERT ON DOMString FOR EACH ROW "
    "BEGIN "
    "  UPDATE DOMString_counter SET nbrows = nbrows + 1; "
    "END " },

  /* --------------------------*/
  /* DOMImplementation counter */
  /* --------------------------*/
  { "CREATE TRIGGER IF NOT EXISTS DOMImplementation_insert_trigger INSERT ON DOMImplementation FOR EACH ROW "
    "BEGIN "
    "  UPDATE DOMImplementation_counter SET nbrows = nbrows + 1; "
    "END " },

  /* ----------------*/
  /* DOMNode counter */
  /* ----------------*/
  { "CREATE TRIGGER IF NOT EXISTS DOMNode_insert_trigger INSERT ON DOMNode FOR EACH ROW "
    "BEGIN "
    "  UPDATE DOMNode_counter SET nbrows = nbrows + 1; "
    "END " },
  { "CREATE TRIGGER IF NOT EXISTS DOMNode_delete_trigger DELETE ON DOMNode FOR EACH ROW "
    "BEGIN "
    "  UPDATE DOMNode_counter SET nbrows = nbrows - 1; "
    "  UPDATE DOMNode SET _ordering = _ordering - 1 where (_ordering > OLD._ordering); "
    "END "
  },

  { NULL }
};

typedef struct marpaXml_DOM_stmt {
  const char   *sql;
  sqlite3_stmt *stmt;
} marpaXml_DOM_stmt_t;
enum {
  /* ---------------------- */
  /* Transaction management */
  /* ---------------------- */
  _marpaXml_BeginImmediateTransaction_e,    /* Internal */
  _marpaXml_EndTransaction_e,               /* Internal */
  _marpaXml_RollbackTransaction_e,          /* Internal */

  /* --------- */
  /* DOMString */
  /* --------- */
  _marpaXml_DOMString_insert_e,             /* Internal */

  /* ----------------- */
  /* DOMImplementation */
  /* ----------------- */
  _marpaXml_DOMImplementation_insert_e,     /* Internal */
};
static marpaXml_DOM_stmt_t marpaXml_DOM_stmt[] = {
  /* ---------------------- */
  /* Transaction management */
  /* ---------------------- */
  { "BEGIN IMMEDIATE TRANSACTION" },
  { "END TRANSACTION" },
  { "ROLLBACK TRANSACTION" },

  /* --------- */
  /* DOMString */
  /* --------- */
  /* Note: very small table, with very small value. No need to invent something complicated */
  { "INSERT INTO DOMString (item) VALUES (?1)", NULL },

  /* ----------------- */
  /* DOMImplementation */
  /* ----------------- */
  /* Note: very small table, with very small value. No need to invent something complicated */
  { "INSERT INTO DOMImplementation (feature, _featureHash, version, _versionHash) VALUES (?1, xxhash(?1), ?2, xxhash(?2))", NULL }, /* Will trigger */

  { NULL, NULL }
};

typedef struct marpaXml_DOMList_stmt {
  const char   *sql;
  sqlite3_stmt *stmt;
} marpaXml_DOMList_stmt_t;
enum {
  /* ------------- */
  /* DOMStringList */
  /* ------------- */
  marpaXml_DOMStringList_item_e,            /* API      */
  marpaXml_DOMStringList_getLength_e,       /* API      */
  marpaXml_DOMStringList_contains_e,        /* API      */

  /* --------------------- */
  /* DOMImplementationList */
  /* --------------------- */
  marpaXml_DOMImplementationList_hasFeature_e,  /* API      */
  _marpaXml_DOMImplementationList_count_e,
};
static marpaXml_DOM_stmt_t marpaXml_DOMList_stmt[] = {
  /* ------------- */
  /* DOMStringList */
  /* ------------- */
  /* Note: this is a view that need to be dropped by a call to marpaXml_DOMStringList_free() */
  { "SELECT item FROM %s WHERE (_order = ?1)", NULL },
  { "SELECT COUNT(*) FROM %s", NULL },
  { "SELECT 1 FROM %s WHERE (item = ?1) LIMIT 1", NULL },

  /* --------------------- */
  /* DOMImplementationList */
  /* --------------------- */
  { "SELECT 1 FROM %s WHERE ((feature LIKE ?1) AND ((?2 IS NULL) OR (version = ?2))) LIMIT 1", NULL },  /* feature test is case insensitive, version is not (contains only digits or dot -;) */
  { "SELECT COUNT(*) FROM %s", NULL },

  { NULL, NULL }
};

/**********/
/* Macros */
/**********/
/* For the marpaXml_DOM_init() singleton: lock of the entire database */
#define MARPAXML_DOM_DB_MUTEX_ENTER sqlite3_mutex_enter(sqlite3_db_mutex(_dbp))
#define MARPAXML_DOM_DB_MUTEX_LEAVE sqlite3_mutex_leave(sqlite3_db_mutex(_dbp))

#define MARPAXML_DOM_DB_BEGTRANS _marpaXml_BeginImmediateTransaction()
#define MARPAXML_DOM_DB_ENDTRANS _marpaXml_EndTransaction()
#define MARPAXML_DOM_DB_ROLLBACK _marpaXml_RollbackTransaction()

/* Any API call must have these macros surrounding database access */
#define MARPAXML_DOM_DB_API_HEADER(method, badRc)                       \
  if (marpaXml_DOM_init(NULL) == marpaXml_false) {			\
    return badRc;                                                       \
  }                                                                     \
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_APICALL, method);       \
  if (MARPAXML_DOM_DB_BEGTRANS == marpaXml_false) {			\
    return badRc;                                                       \
  }

#define MARPAXML_DOM_DB_API_TRAILER(rc, badRc)                          \
  if ((rc) == marpaXml_false || MARPAXML_DOM_DB_ENDTRANS == marpaXml_false) { \
    MARPAXML_DOM_DB_ROLLBACK;						\
    return badRc;                                                       \
  }

/* Maximum length when printing out SQL commands that are C-strings UTF8 compatible, null terminated */
#define STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE 30


/*********************/
/* Static prototypes */
/*********************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_BeginImmediateTransaction(void);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_EndTransaction(void);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_RollbackTransaction(void);
static C_INLINE void                  _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg);
typedef int (*execCallback_t)(void *, int, char **, char **);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(sqlite3 *db, const char *sql, execCallback_t execCallback, void *p);
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
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_int64(sqlite3_stmt* pStmt, int pos, sqlite3_int64 val);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_step(sqlite3_stmt* pStmt);
static C_INLINE void                  _marpaXml_DOMError_set(marpaXml_DOM_ErrorSeverity_t severity,
							     marpaXml_DOMString_t         message,
							     marpaXml_DOMString_t         type,
							     marpaXml_DOMLocator_t        location);
static C_INLINE void                  _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg);
static C_INLINE void                  _marpaXml_xxhash_xDestroy(void *p);

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMString_insert(marpaXml_DOMString_t item);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMStringList_item(unsigned long long int index, marpaXml_DOMString_t *domRcp);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMStringList_getLength(unsigned long long int *domRcp);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMStringList_contains(marpaXml_DOMString_t str);

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
#define MARPAXML_DOM_DB_BEGTRANS _marpaXml_BeginImmediateTransaction() /* _marpaXml_exec(_dbp, "BEGIN IMMEDIATE TRANSACTION") */
#define MARPAXML_DOM_DB_ENDTRANS _marpaXml_EndTransaction() /* _marpaXml_exec(_dbp, "END TRANSACTION") */
#define MARPAXML_DOM_DB_ROLLBACK _marpaXml_RollbackTransaction() /* _marpaXml_exec(_dbp, "ROLLBACK TRANSACTION") */
#define MARPAXML_DOM_DB_API_HEADER(method, badRc)                       \
  if (marpaXml_DOM_init(NULL) == MARPAXML_DOMBOOLEAN_FALSE) {           \
    return badRc;                                                       \
  }                                                                     \
  MARPAXML_DOM_DB_MUTEX_ENTER;                                          \
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_APICALL, method);       \
  if (MARPAXML_DOM_DB_BEGTRANS == MARPAXML_DOMBOOLEAN_FALSE) {          \
    MARPAXML_DOM_DB_MUTEX_LEAVE;                                        \
    return badRc;                                                       \
  }

#define MARPAXML_DOM_DB_API_TRAILER(rc, badRc)                          \
  if ((rc) == MARPAXML_DOMBOOLEAN_FALSE || MARPAXML_DOM_DB_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) { \
    MARPAXML_DOM_DB_ROLLBACK;						\
    MARPAXML_DOM_DB_MUTEX_LEAVE;					\
    return badRc;                                                       \
  }									\
  MARPAXML_DOM_DB_MUTEX_LEAVE;

#define STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE 30

/*******************************************************************/
/* _marpaXml_DOMErrorLogCallback                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg) {
  MARPAXML_ERRORX("SQLite error code %d: %s\n", iErrCode, (zMsg != NULL) ? zMsg : "(null)");
}

/*******************************************************************/
/* _marpaXml_xxhash_xFunc                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg) {
  void                  *xxhp = sqlite3_user_data(pCtx);
  const char            *zString;
  unsigned long long int hash;

  assert(nArg==1);
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
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(sqlite3 *db, const char *sql, execCallback_t execCallback, void *p) {
  char *errmsg = NULL;
  int   sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_EXEC, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_exec(db, sql, execCallback, p, &errmsg)) != SQLITE_OK) {
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

  MARPAXML_TRACEX("[%s]: %s\n", STRINGLITERAL_DB_NEWFUNC, name != NULL ? name : "(null)");
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

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_PREPARE, sql != NULL ? sql : "(null)");
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

#ifndef MARPAXML_NTRACE
  {
    int i = -1;
    char trace[STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE+1];
    marpaXml_DOMBoolean_t truncated = MARPAXML_DOMBOOLEAN_FALSE;

    /* We intentionnally limit the printout of text to STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE characters */
    if (txt == NULL) {
      trace[0] = '\0';
    } else {
      while (txt[++i] != '\0' && i < STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE) {
	trace[i] = txt[i];
      }
      trace[i] = '\0';
      if (i == STRINGLITERAL_DB_BINDTEXT_MAXCHARS_IN_TRACE && txt[i] != '\0') {
	truncated = MARPAXML_DOMBOOLEAN_TRUE;
      }
    }
    MARPAXML_TRACEX("[%s] Pos: %d, Val: %s%s%s%s\n", STRINGLITERAL_DB_BINDTEXT, pos, txt != NULL ? "\"" : "", txt != NULL ? trace : "NULL", truncated == MARPAXML_DOMBOOLEAN_TRUE ? "<truncated>" : "", txt != NULL ? "\"" : "");
  }
#endif

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

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %d\n", STRINGLITERAL_DB_BINDINT, pos, val);

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
/* _marpaXml_bind_int64                                            */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_int64(sqlite3_stmt* pStmt, int pos, sqlite3_int64 val) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %lld\n", STRINGLITERAL_DB_BINDINT64, pos, val);

  if ((sqliteRc = sqlite3_bind_int64(pStmt, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int64(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
/* _marpaXml_step                                                  */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_step(sqlite3_stmt* pStmt) {
  /* No need to spend time on this switch is trace is not enabled */
#ifndef MARPAXML_NTRACE
  int sqliteRc = sqlite3_step(pStmt);

  switch (sqliteRc) {
    /* We list explicitely only the legacy error codes */
  case SQLITE_BUSY:
    MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_STEP, STRINGLITERAL_DB_SQLITE_BUSY);
    break;
  case SQLITE_DONE:
    MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_STEP, STRINGLITERAL_DB_SQLITE_DONE);
    break;
  case SQLITE_ROW:
    MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_STEP, STRINGLITERAL_DB_SQLITE_ROW);
    break;
  case SQLITE_ERROR:
    MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_STEP, STRINGLITERAL_DB_SQLITE_ERROR);
    break;
  case SQLITE_MISUSE:
    MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_STEP, STRINGLITERAL_DB_SQLITE_MISUSE);
    break;
  default:
    MARPAXML_TRACEX("[%s] code %d\n", STRINGLITERAL_DB_STEP, sqliteRc);
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

  /* Close connection to the DB - this will call destructors for created functions */
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
  sqlite3_shutdown();
#endif

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

  /* This is painful, it seems that sqlite3_config() can only be called before sqlite3_initialize */
  sqlite3_config(SQLITE_CONFIG_LOG, &_marpaXml_DOMErrorLogCallback, NULL);

  /* Note: sqlite3_initialize() is thread-safe and only the first one is effective */
  if ((sqliteRc = sqlite3_initialize()) != SQLITE_OK) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* We intentionnaly do not use ICU's mutex because they say their interface may change */
  /* On the other hand, sqlite says their mutex interface can be used */

  /* SQLite already has global mutexes, we use its master mutex to completely block any DOM access */
  masterMutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_STATIC_MASTER);
  if (masterMutexp == NULL) {
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
    MARPAXML_ERRORX("sqlite3_open_v2(%s%s%s, ...): %s at %s:%d\n",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        marpaXml_DOM_Option.dbFilename != NULL ? marpaXml_DOM_Option.dbFilename : "",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
  } while ((sqliteRc = _marpaXml_step(_db_loadcollation_stmt)) == SQLITE_ROW);

  if (sqliteRc != SQLITE_DONE) {
    sqlite3_mutex_leave(_mutexp);
    sqlite3_close_v2(_dbp);
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
    if (_marpaXml_exec(_dbp, STRINGLITERAL_DDL[i], NULL, NULL) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Create the xxhash function */
  if (marpaXml_HashInit(&xxhp) == MARPAXML_HASH_FALSE) {
    MARPAXML_ERRORX("marpaXml_HashInit(): %s\n", strerror(errno));
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
  while (marpaXml_DOM_trigger[++i].sql != NULL) {
    if (_marpaXml_exec(_dbp, marpaXml_DOM_trigger[i].sql, NULL, NULL) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Prepare the statements */
  i = -1;
  while (marpaXml_DOM_stmt[++i].sql != NULL) {
    if (_marpaXml_prepare(_dbp, marpaXml_DOM_stmt[i].sql, &marpaXml_DOM_stmt[i].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
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
    if (_marpaXml_exec(_dbp, marpaXml_DOM_data[i].sql, NULL, NULL) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Fill other data using standard methods */
  if ((_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "1.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "1.0") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "2.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "2.0") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "CORE", (char *) "3.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "CORE", (char*) "3.0") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "1.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "1.0") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "2.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "2.0") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMImplementation_hasFeature((char*) "XML",  (char *) "3.0") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMImplementation_insert((char*) "XML",  (char*) "3.0") == MARPAXML_DOMBOOLEAN_FALSE)

      ||

      (_marpaXml_DOMStringList_contains((char*) "canonical-form")                ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "canonical-form")                == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "cdata-sections")                ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "cdata-sections")                == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "check-character-normalization") ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "check-character-normalization") == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "comments")                      ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "comments")                      == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "datatype-normalization")        ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "datatype-normalization")        == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "element-content-whitespace")    ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "element-content-whitespace")    == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "entities")                      ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "entities")                      == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "error-handler")                 ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "error-handler")                 == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "infoset")                       ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "infoset")                       == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "namespaces")                    ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "namespaces")                    == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "namespace-declarations")        ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "namespace-declarations")        == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "normalize-characters")          ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "normalize-characters")          == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "schema-location")               ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "schema-location")               == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "schema-type")                   ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "schema-type")                   == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "split-cdata-sections")          ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "split-cdata-sections")          == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "validate")                      ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "validate")                      == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "validate-if-schema")            ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "validate-if-schema")            == MARPAXML_DOMBOOLEAN_FALSE) ||
      (_marpaXml_DOMStringList_contains((char*) "well-formed")                   ==  MARPAXML_DOMBOOLEAN_FALSE && _marpaXml_DOMString_insert((char*) "well-formed")                   == MARPAXML_DOMBOOLEAN_FALSE)

      ) {

      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  if (MARPAXML_DOM_DB_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Done */
  _initialized = MARPAXML_DOMBOOLEAN_TRUE;

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
/*               Transaction Management                            */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_BeginImmediateTransaction() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_BeginImmediateTransaction");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_BeginImmediateTransaction_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_BeginImmediateTransaction_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_BeginImmediateTransaction_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_EndTransaction() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_EndTransaction");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_EndTransaction_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_EndTransaction_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_EndTransaction_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_RollbackTransaction() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_RollbackTransaction");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_RollbackTransaction_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_RollbackTransaction_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_RollbackTransaction_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
/*                                                                 */
/*                          DOMString                              */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMString_insert(marpaXml_DOMString_t item) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMString_insert");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_DOMString_insert_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[_marpaXml_DOMString_insert_e].stmt, 1, item) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  do {
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_DOMString_insert_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_DOMString_insert_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
/*                                                                 */
/*                        DOMStringList                            */
/*                                                                 */
/*******************************************************************/
unsigned long long int marpaXml_DOMStringList_getLength(void) {
  int                    sqliteRc;
  unsigned long long int domRc = 0;

  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMStringList_getLength", 0);
  sqliteRc = _marpaXml_DOMStringList_getLength(&domRc);
  MARPAXML_DOM_DB_API_TRAILER(sqliteRc, 0);

  return domRc;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMStringList_getLength(unsigned long long int *domRcp) {
  int                   sqliteRc;
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMStringList_getLength");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[marpaXml_DOMStringList_getLength_e].sql);

  while (1) {
    if ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[marpaXml_DOMStringList_getLength_e].stmt)) == SQLITE_ROW) {
      /* We expect (at least) one row */
      *domRcp = sqlite3_column_int64(marpaXml_DOM_stmt[marpaXml_DOMStringList_getLength_e].stmt, 0);
      domRc = MARPAXML_DOMBOOLEAN_TRUE;
    } else {
      break;
    }
  }

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMStringList_getLength_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }
  
  return domRc;
}

/* =============================================================== */

marpaXml_DOMString_t marpaXml_DOMStringList_item(unsigned long long int index) {
  int                  sqliteRc;
  marpaXml_DOMString_t domRc = NULL;

  /* Indice in DOM spec start at 0, our id start at 1 */
  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMStringList_item", NULL);
  sqliteRc = _marpaXml_DOMStringList_item(index+1, &domRc);
  MARPAXML_DOM_DB_API_TRAILER(sqliteRc, NULL);

  return domRc;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMStringList_item(unsigned long long int index, marpaXml_DOMString_t *domRcp) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMStringList_item");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[marpaXml_DOMStringList_item_e].sql);

  if (_marpaXml_bind_int64(marpaXml_DOM_stmt[marpaXml_DOMStringList_item_e].stmt, 1, index) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  do {
    *domRcp = (void *) sqlite3_column_text(marpaXml_DOM_stmt[marpaXml_DOMStringList_item_e].stmt, 0);
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[marpaXml_DOMStringList_item_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMStringList_item_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/* =============================================================== */

marpaXml_DOMBoolean_t  marpaXml_DOMStringList_contains(marpaXml_DOMString_t str) {
  marpaXml_DOMBoolean_t domRc;

  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMStringList_contains", MARPAXML_DOMBOOLEAN_FALSE);
  domRc = _marpaXml_DOMStringList_contains(str);
  MARPAXML_DOM_DB_API_TRAILER(MARPAXML_DOMBOOLEAN_TRUE /* We force the API to ignore domRc and always do an END TRANSACTION */, MARPAXML_DOMBOOLEAN_FALSE);

  return domRc;
}

/* --------------------------------------------------------------- */

marpaXml_DOMBoolean_t _marpaXml_DOMStringList_contains(marpaXml_DOMString_t str) {
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMStringList_contains");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[marpaXml_DOMStringList_contains_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMStringList_contains_e].stmt, 1, str) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  while (1) {
    if (_marpaXml_step(marpaXml_DOM_stmt[marpaXml_DOMStringList_contains_e].stmt) == SQLITE_ROW) {
      /* No need for more - we also made sure the select statement is limited to one row */
      domRc = MARPAXML_DOMBOOLEAN_TRUE;
    } else {
      break;
    }
  }

  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMStringList_contains_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return domRc;
}

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_count(sqlite_int64 *countp) {
  int                   sqliteRc;
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMImplementation_count");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].sql);

  while (1) {
    if ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_count_e].stmt)) == SQLITE_ROW) {
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

/* =============================================================== */

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_insert(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMImplementation_insert");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[_marpaXml_DOMImplementation_insert_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_insert_e].stmt, 1, feature) == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_text(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_insert_e].stmt, 2, version) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  do {
  } while ((sqliteRc = _marpaXml_step(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_insert_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(marpaXml_DOM_stmt[_marpaXml_DOMImplementation_insert_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/* =============================================================== */

marpaXml_DOMBoolean_t marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  marpaXml_DOMBoolean_t domRc;

  MARPAXML_DOM_DB_API_HEADER("marpaXml_DOMImplementation_hasFeature", MARPAXML_DOMBOOLEAN_FALSE);
  domRc = _marpaXml_DOMImplementation_hasFeature(feature, version);
  MARPAXML_DOM_DB_API_TRAILER(MARPAXML_DOMBOOLEAN_TRUE /* We force the API to ignore domRc and always do an END TRANSACTION */, MARPAXML_DOMBOOLEAN_FALSE)

  return domRc;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_DOMBoolean_t _marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_INTERNALCALL, "_marpaXml_DOMImplementation_hasFeature");
  MARPAXML_TRACEX("[%s] %s\n", STRINGLITERAL_DB_BINDING, marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].sql);

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 1, feature) == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 2, version) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  while (1) {
    if (_marpaXml_step(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt) == SQLITE_ROW) {
      /* No need for more - we also made sure the select statement is limited to one row */
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
