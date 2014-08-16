/*
 * DOM Level 3 Core implementation using SQLite
 * All string are internally UTF16 with native host byte endiannes
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include <unicode/ustring.h>
#include <unicode/uchar.h>
#include <unicode/uclean.h>
#include "sqlite3.h"

#include "API/marpaXml/DOM.h"
#include "internal/config.h"
#include "internal/messageBuilder.h"
#include "../db/Dom Level 3 Core.h"

/*************/
/* Constants */
/*************/
static const char *STRINGLITERAL_CORE = "CORE";  /* UTF-8 compatible */
static const char *STRINGLITERAL_XML  = "XML";   /* UTF-8 compatible */
static const char *STRINGLITERAL_1_0  = "1.0";   /* UTF-8 compatible */
static const char *STRINGLITERAL_2_0  = "2.0";   /* UTF-8 compatible */
static const char *STRINGLITERAL_3_0  = "3.0";   /* UTF-8 compatible */
static const char *STRINGLITERAL_DB_LOADCOLLATION = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)"; /* UTF-8 compatible */
static const char *STRINGLITERAL_DB_CHECK = "SELECT * FROM DOMNode";  /* UTF-8 compatible */
static const char *STRINGLITERAL_DB_FILENAME = ":memory:";  /* UTF-8 compatible */

/********************/
/* Static variables */
/********************/
static sqlite3_stmt         *_db_loadcollation_stmt = NULL;
static sqlite3              *_dbp;
static sqlite3_mutex        *_mutexp;
static marpaXml_DOMBoolean_t _initialized = MARPAXML_DOMBOOLEAN_FALSE;
static marpaXml_DOMObject_t marpaXml_DOMObject_None = {0, MARPAXML_DOM_OBJECTTYPE_NONE};
static struct s_DOMError_ {
  unsigned short        severity;
  marpaXml_DOMString_t  message;
  marpaXml_DOMString_t  type;
  marpaXml_DOMObject_t  relatedException;
  marpaXml_DOMObject_t  relatedData;
  marpaXml_DOMLocator_t location;
} s_DOMError = {MARPAXML_DOM_SEVERITY_NONE, 0, 0, {0, MARPAXML_DOM_OBJECTTYPE_NONE}, {0, MARPAXML_DOM_OBJECTTYPE_NONE}, 0 };
static marpaXml_DOM_Option_t marpaXml_DOM_Option = {MARPAXML_LOGLEVEL_WARNING, &_marpaXmlLog_defaultCallback, NULL, ":memory", NULL, -1};
static marpaXmlLog_t *marpaXmlLogp = NULL;

typedef struct marpaXml_DOM_data {
  const char   *name;
  const char   *sql;
} marpaXml_DOM_data_t;
static marpaXml_DOM_data_t marpaXml_DOM_data[] = {
  { "DOMImplementation.{CORE, '1.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'CORE', '1.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'CORE' AND version like '1.0'))" },
  { "DOMImplementation.{CORE, '2.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'CORE', '2.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'CORE' AND version like '2.0'))" },
  { "DOMImplementation.{CORE, '3.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'CORE', '3.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'CORE' AND version like '3.0'))" },
  { "DOMImplementation.{XML, '1.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'XML', '1.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'XML' AND version like '1.0'))" },
  { "DOMImplementation.{XML, '2.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'XML', '2.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'XML' AND version like '2.0'))" },
  { "DOMImplementation.{XML, '3.0'}", "INSERT INTO DOMImplementation (feature, version) SELECT 'XML', '3.0' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE (feature like 'XML' AND version like '3.0'))" },
  { NULL, NULL }
};

typedef struct marpaXml_DOM_stmt {
  const char   *name;
  const char   *sql;
  sqlite3_stmt *stmt;
} marpaXml_DOM_stmt_t;
enum {
  marpaXml_DOMImplementation_hasFeature_e = 0,
};
static marpaXml_DOM_stmt_t marpaXml_DOM_stmt[] = {
  { "marpaXml_DOMImplementation_hasFeature", "SELECT 1 FROM DOMImplementation WHERE (feature LIKE ?1 and ((?2 IS NULL) OR (version like ?2)))", NULL },
  { NULL, NULL, NULL }
};

/*********************/
/* Static prototypes */
/*********************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(const char *sql);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_prepare(sqlite3 *db, const char *zSql, sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_reset(sqlite3_stmt *pStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_finalize(sqlite3_stmt **ppStmt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_text(sqlite3_stmt* pStmt, int pos, const char *txt);
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_bind_int(sqlite3_stmt* pStmt, int pos, int val);
static C_INLINE void _marpaXml_DOMError_set(marpaXml_DOM_ErrorSeverity_t severity,
					    marpaXml_DOMString_t         message,
					    marpaXml_DOMString_t         type,
					    marpaXml_DOMObject_t         relatedException,
					    marpaXml_DOMObject_t         relatedData,
					    marpaXml_DOMLocator_t        location);
/**********/
/* Macros */
/**********/
/* Per-def the mutex macros can never be called before marpaXml_DOM_init() has been called */
#define MARPAXML_DOM_MUTEX_ENTER {if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {sqlite3_mutex_enter(_mutexp);}}
#define MARPAXML_DOM_MUTEX_LEAVE {if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {sqlite3_mutex_leave(_mutexp);}}
#define MARPAXML_DOM_BEGTRANS _marpaXml_exec("BEGIN IMMEDIATE TRANSACTION")
#define MARPAXML_DOM_ENDTRANS _marpaXml_exec("END TRANSACTION")
#define MARPAXML_DOM_ROLLBACK _marpaXml_exec("ROLLBACK TRANSACTION")

/*******************************************************************/
/* _marpaXml_exec                                                  */
/*******************************************************************/
static C_INLINE marpaXml_DOMBoolean_t _marpaXml_exec(const char *sql) {
  char *errmsg = NULL;
  int   sqliteRc;

  MARPAXML_TRACEX("Exec SQL: %s\n", sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_exec(_dbp, sql, NULL, NULL, &errmsg)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_exec(..., \"%s\", ...): %s\n", sql != NULL ? sql : "(null)", errmsg != NULL ? errmsg : "(null)");
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", errmsg != NULL ? errmsg : "(null)"),
			   NULL,
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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

  MARPAXML_TRACEX("sqlite3_bind_text(%p, %d, %s%s%s)\n", pStmt, pos, txt != NULL ? "\"" : "", txt != NULL ? txt : "(null)", txt != NULL ? "\"" : "");

  if ((sqliteRc = sqlite3_bind_text(pStmt, pos, txt, -1, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("%s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
			   0
			   );
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return MARPAXML_DOMBOOLEAN_TRUE;
}

/*******************************************************************/
/* marpaXml_DOM_init                                               */
/*******************************************************************/
marpaXml_DOMBoolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp) {
  UErrorCode     uErrorCode = U_ZERO_ERROR;
  sqlite3_mutex *masterMutexp;
  int            sqliteRc;
  int            i;

  /* We first check _initialized in a non thread-safe way for quick return */
  if (_initialized == MARPAXML_DOMBOOLEAN_TRUE) {
    return MARPAXML_DOMBOOLEAN_TRUE;
  }

  /* Note: sqlite3_initialize() is thread-safe and only the first one is effective */
  if ((sqliteRc = sqlite3_initialize()) != SQLITE_OK) {
    _marpaXml_DOMError_set(MARPAXML_DOM_SEVERITY_FATAL_ERROR,
			   messageBuilder("sqlite3_initialize(): %s", sqlite3_errstr(sqliteRc)),
			   NULL,
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			     marpaXml_DOMObject_None,
			     marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
			   marpaXml_DOMObject_None,
			   marpaXml_DOMObject_None,
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
  for (i = 0; i < STRINGLITERAL_DDL_NBTABLES; i++) {
    if (_marpaXml_exec(STRINGLITERAL_DDL[i]) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  /* Insert fixed data */
  if (MARPAXML_DOM_BEGTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  i = -1;
  while (marpaXml_DOM_data[++i].name != NULL && marpaXml_DOM_data[i].sql != NULL) {
    if (_marpaXml_exec(marpaXml_DOM_data[i].sql) == MARPAXML_DOMBOOLEAN_FALSE) {
      sqlite3_mutex_leave(_mutexp);
      sqlite3_close_v2(_dbp);
      _dbp = NULL;
      return MARPAXML_DOMBOOLEAN_FALSE;
    }
  }

  if (MARPAXML_DOM_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
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

marpaXml_DOMObject_t  marpaXml_DOMError_getRelatedException(void) {
  marpaXml_DOMObject_t  relatedException;

  MARPAXML_DOM_MUTEX_ENTER;
  relatedException = s_DOMError.relatedException;
  MARPAXML_DOM_MUTEX_LEAVE;

  return relatedException;
}

marpaXml_DOMObject_t  marpaXml_DOMError_getRelatedData(void) {
  marpaXml_DOMObject_t  relatedData;

  MARPAXML_DOM_MUTEX_ENTER;
  relatedData = s_DOMError.relatedData;
  MARPAXML_DOM_MUTEX_LEAVE;

  return relatedData;
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
					    marpaXml_DOMObject_t         relatedException,
					    marpaXml_DOMObject_t         relatedData,
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
  s_DOMError.relatedException = relatedException;
  s_DOMError.relatedData = relatedData;
  s_DOMError.location = location;

  MARPAXML_DOM_MUTEX_LEAVE;
}

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/
marpaXml_DOMBoolean_t marpaXml_DOMImplementation_hasFeature(marpaXml_DOMString_t feature, marpaXml_DOMString_t version) {
  int                   sqliteRc;
  int                   colRc;
  marpaXml_DOMBoolean_t domRc = MARPAXML_DOMBOOLEAN_FALSE;

  if (marpaXml_DOM_init(NULL) == MARPAXML_DOMBOOLEAN_FALSE) {
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  MARPAXML_TRACEX("marpaXml_DOMImplementation_hasFeature(%s, %s)\n", feature != NULL ? feature : "(null)", version != NULL ? version : "(null)");

  if (MARPAXML_DOM_BEGTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
      return MARPAXML_DOMBOOLEAN_FALSE;
  }

  if (_marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 1, feature) == MARPAXML_DOMBOOLEAN_FALSE ||
      _marpaXml_bind_text(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 2, version) == MARPAXML_DOMBOOLEAN_FALSE) {
    MARPAXML_DOM_ROLLBACK;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  while (1) {
    if ((sqliteRc = sqlite3_step(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt)) == SQLITE_ROW) {
      if ((colRc = sqlite3_column_int(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt, 0)) == 1) {
	domRc = MARPAXML_DOMBOOLEAN_TRUE;
      } else {
	MARPAXML_WARNINGX("Unexpected value from sqlite3_column_int(): %d at %s:%d\n", colRc, __FILE__, __LINE__);
	domRc = MARPAXML_DOMBOOLEAN_FALSE;
      }
    } else {
      break;
    }
  }

  if (_marpaXml_reset(marpaXml_DOM_stmt[marpaXml_DOMImplementation_hasFeature_e].stmt) == MARPAXML_DOMBOOLEAN_FALSE) {
    MARPAXML_DOM_ROLLBACK;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  if (MARPAXML_DOM_ENDTRANS == MARPAXML_DOMBOOLEAN_FALSE) {
    MARPAXML_DOM_ROLLBACK;
    return MARPAXML_DOMBOOLEAN_FALSE;
  }

  return domRc;
}
