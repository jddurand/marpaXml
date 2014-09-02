#include "internal/config.h"

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

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

  _marpaXml_DOMError_new_e,
  _marpaXml_DOMError_getSeverity_e,
  _marpaXml_DOMError_setSeverity_e,
  _marpaXml_DOMError_free_e,

  _marpaXml_DOMObjects_new_e,
  _marpaXml_DOMObjects_free_e,

  _marpaXml_DOMStringList_new_e,
  _marpaXml_DOMStringList_contains_e,
  _marpaXml_DOMStringList_free_e,

  __marpaXml_stmt_max_e,
} _marpaXml_stmt_e;

/* This is used to exec() anything that must be done before init the init */
typedef struct _marpaXml_init {
  const char *sql;
} _marpaXml_init_t;

/*
 * We inserted the enum in this structure just to make sure we do not get wrong with
 * enum value v.s. the indice in _marpaXml_stmt[]
 */
typedef struct _marpaXml_stmt {
  sqlite3_stmt        *stmt;
  marpaXml_boolean_t  generatedb;
  marpaXml_boolean_t  changesb;
  marpaXml_boolean_t  selectb;
  marpaXml_boolean_t  insertb;
  _marpaXml_stmt_e     e;
  const char          *sql;
} _marpaXml_stmt_t;

/* For the SQLite exec callback */
typedef int (*_marpaXml_SQLiteExecCallback_t)(void *, int, char **, char **);

/* DOMObjects should be internal only */
typedef struct marpaXml_DOMObjects marpaXml_DOMObjects_t;
marpaXml_DOMObjects_t *marpaXml_DOMObjects_new(char *objectName);
marpaXml_boolean_t      marpaXml_DOMObjects_free(marpaXml_DOMObjects_t **thisp);

/* For the API */
struct marpaXml_DOMException  { sqlite3_int64 id; };
struct marpaXml_DOMError      { sqlite3_int64 id; };
struct marpaXml_DOMObjects    { sqlite3_int64 id; };
struct marpaXml_DOMStringList {
  sqlite3_int64          id;
  marpaXml_DOMObjects_t *DOMObjectsp;
  sqlite3_stmt          *cachedUntilFreeStmt[__marpaXml_stmt_max_e];  /* Tant pis for the few bytes unused */
  char                  *cachedUntilFreeSqls[__marpaXml_stmt_max_e];  /* Ditto */
};

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

#define MARPAXML_GENERIC_GET_API(rcType, class, method, dbType, dbMapType, rcDb2Rc) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType *rcp) { \
    dbMapType rcDb;                                                     \
    int    sqliteRc;                                                    \
    unsigned short nbRows = 0;                                          \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
                                                                        \
    if (rcp == NULL) {                                                  \
      MARPAXML_ERROR0("Last argument must be != NULL\n");               \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    if (_marpaXml_getStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
      return marpaXml_false;                                            \
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, sqls);			\
                                                                        \
    if (_marpaXml_bind_int64(sqliteStmtp, 1, thisp->id) == marpaXml_false) { \
      _marpaXml_reset(sqliteStmtp); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
      if (++nbRows > 1) {                                               \
        break;                                                          \
      }                                                                 \
      rcDb = sqlite3_column_##dbType(sqliteStmtp, 0);			\
     *rcp = rcDb2Rc;							\
    }                                                                   \
                                                                        \
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s\n", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (nbRows <= 0) {                                                  \
      MARPAXML_ERRORX("[%s] no row\n", sqls);				\
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    else if (nbRows > 1) {						\
      MARPAXML_ERRORX("[%s] more than one row\n", sqls); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
    return marpaXml_true;                                               \
  }                                                                     \
                                                                        \
  marpaXml_boolean_t marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType *rcp) { \
    marpaXml_boolean_t rc;                                                          \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)    \
    rc = _marpaXml_##class##_##method(thisp, rcp);                 \
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

/* This macros requires that the first argument is always thisp, and last argument is always rcp */
/* selectb mode requires that exactly one row is fetched */
/* changesb mode requires that SQLite detected changes */
/* insertb mode requires that last inserted ID is > 0 */
/* It is the responsability of _marpaXml_stmt_[] array to set changesb accordingly to insertb, if wanted */

#define MARPAXML_GENERIC_METHOD_API(rcType, class, method, decl, args, bindingResult, dbType, dbMapType, rcDb2Rc, defaultRc, changeId) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(decl) { \
    dbMapType       rcDb;                                               \
    int             sqliteRc;                                           \
    unsigned short  nbRows = 0;                                         \
    char           *sqls;						\
    sqlite3_stmt   *sqliteStmtp;					\
    sqlite3_int64   id;                                                 \
                                                                        \
    if (rcp == NULL) {                                                  \
      MARPAXML_ERROR0("Last argument must be != NULL\n");               \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    *rcp = defaultRc;                                                   \
                                                                        \
    if (_marpaXml_getStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
      return marpaXml_false;                                            \
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, sqls);			\
                                                                        \
    if ((bindingResult) == marpaXml_false) {				\
      _marpaXml_reset(sqliteStmtp); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
      if (++nbRows > 1) {                                               \
        break;                                                          \
      }                                                                 \
      rcDb = sqlite3_column_##dbType(sqliteStmtp, 0);			\
     *rcp = rcDb2Rc;							\
    }                                                                   \
                                                                        \
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s\n", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (_marpaXml_stmt[_marpaXml_##class##_##method##_e].selectb == marpaXml_true) { \
      if (nbRows <= 0) {                                               \
        MARPAXML_ERRORX("[%s] no row\n", sqls);				\
        _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
        return marpaXml_false;                                          \
      }                                                                 \
      else if (nbRows > 1) {						\
        MARPAXML_ERRORX("[%s] more than one row\n", sqls);              \
        _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
        return marpaXml_false;                                          \
      }                                                                 \
    }                                                                   \
    if (_marpaXml_stmt[_marpaXml_##class##_##method##_e].changesb == marpaXml_true){ \
      if (_marpaXml_changes() == marpaXml_false) {                      \
        _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
        return marpaXml_false;                                          \
      }                                                                 \
    }                                                                   \
    if (_marpaXml_stmt[_marpaXml_##class##_##method##_e].changesb == marpaXml_true) { \
      if (_marpaXml_changes() == marpaXml_false) {                      \
        _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
        return marpaXml_false;                                          \
      }                                                                 \
    }                                                                   \
    if ((_marpaXml_stmt[_marpaXml_##class##_##method##_e].insertb == marpaXml_true) && (changeId == marpaXml_true)) { \
      id = sqlite3_last_insert_rowid(_dbp);                             \
      if (id <= 0) {                                                    \
	MARPAXML_ERRORX("[%s] id <= 0 at %s:%d\n", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(thisp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
        return marpaXml_false;                                          \
      }	else {								\
        thisp->id = id;                                                 \
      }                                                                 \
      MARPAXML_TRACEX("[%s] %lld\n", _MARPAXML_ID, (unsigned long long int) thisp->id); \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
    return marpaXml_true;                                               \
  }                                                                     \
                                                                        \
  marpaXml_boolean_t marpaXml_##class##_##method(decl) { \
    marpaXml_boolean_t rc;                                                          \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)    \
    rc = _marpaXml_##class##_##method(args);                 \
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

#define MARPAXML_GENERIC_SET_API(rcType, class, method, dbType, var, var2VarDb) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType var) { \
    int    sqliteRc;                                                    \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
                                                                        \
    if (_marpaXml_getStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
      return marpaXml_false;                                            \
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, sqls); \
                                                                        \
    if ((_marpaXml_bind_int64(sqliteStmtp, 1, thisp->id) == marpaXml_false) || \
        (_marpaXml_bind_##dbType(sqliteStmtp, 2, var2VarDb) == marpaXml_false)) { \
      _marpaXml_reset(sqliteStmtp);					\
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
    }                                                                   \
                                                                        \
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s\n", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    if ((_marpaXml_stmt[_marpaXml_##class##_##method##_e].changesb == marpaXml_true) && (_marpaXml_changes() == marpaXml_false)) { \
      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
									\
    return marpaXml_true;                                               \
  }                                                                     \
                                                                        \
  marpaXml_boolean_t marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType var) { \
    marpaXml_boolean_t rc;                                                          \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)    \
    rc = _marpaXml_##class##_##method(thisp, var);                 \
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

/* Hack to make the preprocessor believe a concatenation is a single argument */
#define MARPAXML_ARG(x) ,x

#define MARPAXML_GENERIC_NEW_API(class, decl, args, extraInit, bindingResult) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_free(marpaXml_##class##_t **thispp); \
  static C_INLINE marpaXml_##class##_t *_marpaXml_##class##_new(decl) { \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
    marpaXml_##class##_t *rcp;                                          \
    int                   sqliteRc;                                     \
    unsigned short        nbRows = 0;					\
    sqlite_int64          id = 0;					\
                                                                        \
    if ((rcp = malloc(sizeof(marpaXml_##class##_t))) == NULL) {          \
      MARPAXML_ERRORX("malloc() returns NULL: %s at %s:%d\n", strerror(errno), __FILE__, __LINE__); \
      return NULL;							\
    }                                                                   \
    rcp->id = 0;								\
    extraInit								\
                                                                        \
    if (_marpaXml_getStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, sqls);			\
    									\
    if ((bindingResult) == marpaXml_false) {				\
      _marpaXml_reset(sqliteStmtp);					\
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
                                                                        \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
      if (++nbRows > 1) {						\
        break;                                                          \
      }                                                                 \
      id = sqlite3_column_int64(sqliteStmtp, 0);			\
    }									\
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
    									\
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] step returned %d != SQLITE_DONE: %s at %s:%d\n", sqls, sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__); \
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
                                                                        \
    if (_marpaXml_stmt[_marpaXml_##class##_new_e].changesb == marpaXml_true) { \
      if (_marpaXml_changes() == marpaXml_false) {			\
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      rcp->id = sqlite3_last_insert_rowid(_dbp);				\
      if (rcp->id <= 0) {						\
	MARPAXML_ERRORX("[%s] id <= 0 at %s:%d\n", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      MARPAXML_TRACEX("[%s] %lld\n", _MARPAXML_ID, (unsigned long long int) rcp->id); \
    }									\
    else if (_marpaXml_stmt[_marpaXml_##class##_new_e].selectb == marpaXml_true) { \
      if (nbRows == 0) {						\
	MARPAXML_ERRORX("[%s] no row at %s:%d\n", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      else if (nbRows > 1) {						\
	MARPAXML_ERRORX("[%s] more than one row at %s:%d\n", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      rcp->id = id;							\
      if (rcp->id <= 0) {						\
	MARPAXML_ERRORX("[%s] id is <= 0 at %s:%d\n", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      MARPAXML_TRACEX("[%s] %lld\n", _MARPAXML_ID, (unsigned long long int) rcp->id); \
    }									\
    									\
    _marpaXml_freeStmt(rcp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
    									\
    return rcp;                                                          \
  }                                                                     \
                                                                        \
  marpaXml_##class##_t *marpaXml_##class##_new(decl) {                  \
    marpaXml_##class##_t *rc;                                           \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_new", NULL)         \
    rc = _marpaXml_##class##_new(args);                                 \
    MARPAXML_DOM_DB_API_TRAILER(rc != NULL ? marpaXml_true : marpaXml_false, NULL)  \
                                                                        \
    MARPAXML_TRACEX("[%s] %p\n", _MARPAXML_APIRC, rc);		        \
                                                                        \
    return rc;                                                          \
  }

#define MARPAXML_GENERIC_FREE_API(class, impactOnDb)			\
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_free(marpaXml_##class##_t **thispp) { \
    marpaXml_##class##_t *thisp;                                        \
    int                  sqliteRc;                                      \
    marpaXml_boolean_t   rc = marpaXml_true;                            \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
                                                                        \
    if (thispp != NULL) {                                               \
      thisp = *thispp;                                                  \
                                                                        \
      if (thisp != NULL) {                                              \
        if (impactOnDb == marpaXml_true) {				\
	  if (_marpaXml_getStmt(thisp, _marpaXml_##class##_free_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
	    rc = marpaXml_false;					\
	  } else {							\
	    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, sqls);		\
	    if ((thisp->id > 0) && _marpaXml_bind_int64(sqliteStmtp, 1, thisp->id) == marpaXml_false) { \
	      _marpaXml_reset(sqliteStmtp);				\
	      _marpaXml_freeStmt(thisp, _marpaXml_##class##_free_e, &sqls, &sqliteStmtp); \
	      rc = marpaXml_false;					\
	    } else {							\
	      do {							\
	      } while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW); \
	      if (sqliteRc != SQLITE_DONE) {				\
		MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d\n", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__); \
		_marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_free_e].stmt); \
		_marpaXml_freeStmt(thisp, _marpaXml_##class##_free_e, &sqls, &sqliteStmtp); \
		rc = marpaXml_false;					\
	      } else {							\
		if ((_marpaXml_stmt[_marpaXml_##class##_free_e].changesb == marpaXml_true) && (_marpaXml_changes() == marpaXml_false)) { \
		  _marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_free_e].stmt); \
		  _marpaXml_freeStmt(thisp, _marpaXml_##class##_free_e, &sqls, &sqliteStmtp); \
		  rc = marpaXml_false;					\
		} else {						\
		  _marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_free_e].stmt); \
		  _marpaXml_freeStmt(thisp, _marpaXml_##class##_free_e, &sqls, &sqliteStmtp); \
		  free(thisp);						\
		  *thispp = NULL;					\
		}							\
	      }								\
	    }								\
	  }								\
        } else {                                                        \
          free(thisp);                                                  \
          *thispp = NULL;                                               \
        }                                                               \
      } else {                                                          \
        rc = marpaXml_false;                                            \
      }                                                                 \
    } else {                                                            \
      rc = marpaXml_false;                                              \
    }                                                                   \
                                                                        \
    return rc;                                                          \
  }                                                                     \
                                                                        \
  marpaXml_boolean_t marpaXml_##class##_free(marpaXml_##class##_t **thispp) { \
    marpaXml_boolean_t rc;                                              \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_free", marpaXml_false) \
    rc = _marpaXml_##class##_free(thispp);                              \
    MARPAXML_DOM_DB_API_TRAILER(rc, marpaXml_false)                     \
                                                                        \
    return rc;                                                          \
  }

/********************************************************************************/
/*                                 Constants                                    */
/********************************************************************************/
static const char *_MARPAXML_LOADCOLLATION     = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)";
static const char *_MARPAXML_EXEC              = "   EXEC";
static const char *_MARPAXML_PREPARE           = "PREPARE";
static const char *_MARPAXML_CACHE             = "  CACHE";
static const char *_MARPAXML_CACHED            = " CACHED";
static const char *_MARPAXML_FINALIZE          = "  FINAL";
static const char *_MARPAXML_SKIPPED           = "SKIPPED";
static const char *_MARPAXML_NEWFUNC           = "NEWFUNC";
static const char *_MARPAXML_SQL               = "    SQL";
static const char *_MARPAXML_BINDTEXT          = "   BIND";
static const char *_MARPAXML_BINDINT           = "   BIND";
static const char *_MARPAXML_BINDINT64         = "   BIND";
static const char *_MARPAXML_STEP              = "   STEP";
static const char *_MARPAXML_ID                = "     ID";
static const char *_MARPAXML_APICALL           = "--- API";
static const char *_MARPAXML_APIRC             = "===  RC";
static const char *_MARPAXML_SQLITE_BUSY       = "SQLITE_BUSY";
static const char *_MARPAXML_SQLITE_DONE       = "SQLITE_DONE";
static const char *_MARPAXML_SQLITE_ROW        = "SQLITE_ROW";
static const char *_MARPAXML_SQLITE_ERROR      = "SQLITE_ERROR";
static const char *_MARPAXML_SQLITE_MISUSE     = "SQLITE_MISUSE";
static const char *_MARPAXML_SQLITE_CONSTRAINT = "SQLITE_CONSTRAINT";
static const char *_MARPAXML_FALSE             = "marpaXml_false";
static const char *_MARPAXML_TRUE              = "marpaXml_true";

/********************************************************************************/
/*                           Static variables                                   */
/********************************************************************************/
static sqlite3              *_dbp = NULL;
static marpaXml_boolean_t    _initialized = marpaXml_false;
static marpaXmlLog_t        *marpaXmlLogp = NULL;  /* Intentionnaly without s_ prefix because of MARPAXML log macros */
static marpaXml_String_Option_t marpaXml_String_Option;

static _marpaXml_stmt_t _marpaXml_stmt[] = {

  /* ------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       sql        */
  /* ------------------------------------------------------------------------------------------------------------------------*/
  /* Note: For selectb, we put 0 instead of marpaXml_false to indicate this is a noop in this context.                       */
  /*       Indeed, selectb is meaninful only in the new() sql's that have changesb to false                                  */
  /* ------------------------------------------------------------------------------------------------------------------------*/

  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_BeginImmediate_e, "BEGIN IMMEDIATE TRANSACTION" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_End_e,            "END TRANSACTION" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_Rollback_e,       "ROLLBACK TRANSACTION" },

  /* DOMException: the lifetime of the row is the lifetime of the object */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMException_new_e,           "INSERT INTO DOMException (code, message) VALUES (?1, ?2)" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMException_getCode_e,       "SELECT code FROM DOMException WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_setCode_e,       "UPDATE DOMException SET code = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMException_getMessage_e,    "SELECT message FROM DOMException WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_setMessage_e,    "UPDATE DOMException SET message = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_free_e,          "DELETE FROM DOMException WHERE (id = ?1)" },

  /* DOMError */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMError_new_e,               "INSERT INTO DOMError DEFAULT VALUES" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMError_getSeverity_e,       "SELECT severity FROM DOMError WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMError_setSeverity_e,       "UPDATE DOMError SET severity = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMError_free_e,              "DELETE FROM DOMError WHERE (id = ?1)" },

  /* DOMObjects: used to track dynamic objects, i.e. those that have generatedb to marpaXml_true */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMObjects_new_e,             "INSERT INTO DOMObjects (objectName) VALUES (?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMObjects_free_e,            "DELETE FROM DOMObjects WHERE (id = ?1)" },

  /* DOMStringList : we use the temp namespace so that main is not changed */
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMStringList_new_e,          "CREATE TEMPORARY VIEW DOMStringList%lld AS SELECT *, (SELECT COUNT(*) FROM DOMString b WHERE a.id >= b.id) AS _order FROM DOMString a" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMStringList_contains_e,     "SELECT COALESCE((SELECT 1 FROM DOMStringList%lld WHERE (item = ?1)), 0)" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMStringList_free_e,         "DROP VIEW DOMStringList%lld" },

  { NULL, 0, 0, 0, 0, 0, NULL }
};

static _marpaXml_init_t _marpaXml_init[] = {
  {
    "CREATE TRIGGER IF NOT EXISTS DOMException_setCode_Insert_Trigger "
    "BEFORE INSERT ON DOMException "
    "FOR EACH ROW "
    "WHEN (NEW.code < 1 OR NEW.code > 17) "
    "BEGIN "
    "  SELECT RAISE(FAIL, 'Invalid code number'); "
    "END;"
  },
  {
    "CREATE TRIGGER IF NOT EXISTS DOMException_setCode_Update_Trigger "
    "BEFORE UPDATE ON DOMException "
    "FOR EACH ROW "
    "WHEN (NEW.code < 1 OR NEW.code > 17) "
    "BEGIN "
    "  SELECT RAISE(FAIL, 'Invalid code number'); "
    "END;"
  },
  {
    "PRAGMA integrity_check;"
  },
  { NULL }
};

/*********************/
/* Static prototypes */
/*********************/
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Begin(void);
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_End(void);
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Rollback(void);
static C_INLINE void               _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg);
static C_INLINE marpaXml_boolean_t _marpaXml_exec(sqlite3 *db, const char *sql, _marpaXml_SQLiteExecCallback_t execCallback, void *p);
static C_INLINE marpaXml_boolean_t _marpaXml_prepare(sqlite3 *db, const char *zSql, sqlite3_stmt **stmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_create_function(sqlite3 *db,
								const char *zFunctionName,
								int nArg,
								int eTextRep,
								void *pApp,
								void (*xFunc)(sqlite3_context*,int,sqlite3_value**),
								void (*xStep)(sqlite3_context*,int,sqlite3_value**),
								void (*xFinal)(sqlite3_context*),
								void(*xDestroy)(void*));
static C_INLINE marpaXml_boolean_t _marpaXml_changes(void);
static C_INLINE marpaXml_boolean_t _marpaXml_reset(sqlite3_stmt *stmtp);
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(const char *sqls, sqlite3_stmt **stmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* stmtp, int pos, const char *txt);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* stmtp, int pos, int val);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* stmtp, int pos, sqlite3_int64 val);
static C_INLINE marpaXml_boolean_t _marpaXml_step(sqlite3_stmt* stmtp);
static C_INLINE void               _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg);
static C_INLINE void               _marpaXml_xxhash_xDestroy(void *p);
static C_INLINE marpaXml_boolean_t _marpaXml_getStmt(void *objp, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE void               _marpaXml_freeStmt(void *obj, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_generateStmt(void *objp, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp);

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

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_NEWFUNC, name != NULL ? name : "(null)");
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
static C_INLINE marpaXml_boolean_t _marpaXml_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **stmtpp) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_PREPARE, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_prepare_v2(db, sql, strlen(sql) + sizeof(char), stmtpp, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_prepare_v2(): %s\n\nSQL sequence was:\n\n%s\n", sqlite3_errstr(sqliteRc), sql);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_finalize                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(const char *sqls, sqlite3_stmt **stmtpp) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_FINALIZE, sqls != NULL ? sqls : "(null)");
  if ((sqliteRc = sqlite3_finalize(*stmtpp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_finalize(): %s\n", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  } else {
    *stmtpp = NULL;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_changes                                               */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_changes(void) {
  int changes;

  changes = sqlite3_changes(_dbp);

  if (changes != 1) {
    MARPAXML_ERRORX("sqlite3_changes(): %d\n", changes);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_reset                                                 */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_reset(sqlite3_stmt *stmtp) {
  int sqliteRc;

  if ((sqliteRc = sqlite3_reset(stmtp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_reset(): %s\n", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_text                                             */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* stmtp, int pos, const char *txt) {
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

  if ((sqliteRc = sqlite3_bind_text(stmtp, pos, txt, -1, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_int                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* stmtp, int pos, int val) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %d\n", _MARPAXML_BINDINT, pos, val);

  if ((sqliteRc = sqlite3_bind_int(stmtp, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_int64                                            */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* stmtp, int pos, sqlite3_int64 val) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %lld\n", _MARPAXML_BINDINT64, pos, val);

  if ((sqliteRc = sqlite3_bind_int64(stmtp, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int64(): %s at %s:%d\n", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_step                                                  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_step(sqlite3_stmt* stmtp) {
  /* No need to spend time on this switch is trace is not enabled */
#ifndef MARPAXML_NTRACE
  int sqliteRc = sqlite3_step(stmtp);

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
  case SQLITE_CONSTRAINT:
    MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_STEP, _MARPAXML_SQLITE_CONSTRAINT);
    break;
  default:
    MARPAXML_TRACEX("[%s] code %d\n", _MARPAXML_STEP, sqliteRc);
    break;
  }

  return sqliteRc;
#else
  /* The compiler will certainly optimise it and put it inline */
  return sqlite3_step(stmtp);
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
    if (_marpaXml_finalize(_marpaXml_stmt[i].sql, &_marpaXml_stmt[i].stmt) == marpaXml_false) {
      rc = marpaXml_false;
    }
  }

  /* Close connection to the DB - this will call destructors for created functions */
  MARPAXML_INFO0("Closing database\n");
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

  marpaXml_String_Option.marpaXml_String_Option_ICU = MARPAXML_STRING_OPTION_ICU_DEFAULT;
  marpaXml_String_Option.fallback                   = marpaXml_true;
  marpaXml_String_Option.logOption                  = marpaXml_DOM_Option.logOption;

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
  if (_marpaXml_finalize(_MARPAXML_LOADCOLLATION, &loadcollation_stmt) == marpaXml_false) {
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

  /* Execute fixed SQL statements */
  i = -1;
  while (_marpaXml_init[++i].sql != NULL) {
    if (_marpaXml_exec(dbp, _marpaXml_init[i].sql, NULL, NULL) == marpaXml_false) {
      goto error;
    }
  }

  /* Prepare all the statements NOW ONLY: upper fixed SQL statement could have changed the schema. Done except for statements declared dynamic */
  i = -1;
  while (_marpaXml_stmt[++i].sql != NULL) {
    if (_marpaXml_stmt[i].generatedb == marpaXml_false) {
      if (_marpaXml_prepare(dbp, _marpaXml_stmt[i].sql, &_marpaXml_stmt[i].stmt) == marpaXml_false) {
	goto error;
      }
    } else {
      MARPAXML_INFOX("[%s] %s\n", _MARPAXML_SKIPPED, _marpaXml_stmt[i].sql);
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
  sqlite3_mutex_free(mutexp);

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
    _marpaXml_finalize(_MARPAXML_LOADCOLLATION, &loadcollation_stmt);
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

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].sql);

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

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_End_e].sql);

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

  MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_Rollback_e].sql);

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
/* --------------------------------------------------------------- */
/* marpaXml_DOMException_new                                       */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(DOMException,                              /* class */
                         short code MARPAXML_ARG(marpaXml_String_t *messagep),    /* decl */
                         code MARPAXML_ARG(messagep),               /* args */
			 ,                                          /* extraInit */
                          /* bindingResult */
                         (_marpaXml_bind_int (sqliteStmtp, 1, code                             ) == marpaXml_true &&
			  _marpaXml_bind_text(sqliteStmtp, 2, marpaXml_String_getUtf8(messagep)) == marpaXml_true) ? marpaXml_true : marpaXml_false
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_getCode                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(unsigned short,                            /* rcType */
                         DOMException,                              /* class */
                         getCode,                                   /* method */
                         int,                                       /* dbType */
                         int,                                       /* dbMapType */
                         (unsigned short) rcDb                      /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_setCode                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(unsigned short,                            /* rcType */
                         DOMException,                              /* class */
                         setCode,                                   /* method */
                         int,                                       /* dbType */
                         code,                                      /* var */
                         code                                       /* var2VarDb */
			 )


/* --------------------------------------------------------------- */
/* marpaXml_DOMException_getMessage                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(marpaXml_String_t *,                       /* rcType */
                         DOMException,                              /* class */
                         getMessage,                                /* method */
                         text,                                      /* dbType */
                         const unsigned char *,                     /* dbMapType */
                         marpaXml_String_newFromUTF8((char *)rcDb, &marpaXml_String_Option) /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_setMessage                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(marpaXml_String_t *,                       /* rcType */
                         DOMException,                              /* class */
                         setMessage,                                /* method */
                         text,                                      /* dbType */
                         messagep,                                  /* var */
                         marpaXml_String_getUtf8(messagep)          /* var2VarDb */
			 )


/* --------------------------------------------------------------- */
/* marpaXml_DOMException_free                                      */
/* Note: the lifetime of a DOMException in the DB is the object    */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(DOMException,                             /* class */
                          marpaXml_true                             /* impactOnDb */
			  )

/*******************************************************************/
/*                                                                 */
/*                          DOMError                               */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMError_new                                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(DOMError,                                  /* class */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true                              /* bindingResult */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMError_getSeverity                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(unsigned short,                            /* rcType */
                         DOMError,                                  /* class */
                         getSeverity,                               /* method */
                         int,                                       /* dbType */
                         int,                                       /* dbMapType */
                         rcDb                                       /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMError_setSeverity                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(unsigned short,                            /* rcType */
                         DOMError,                                  /* class */
                         setSeverity,                               /* method */
                         int,                                       /* dbType */
                         severity,                                  /* var */
                         severity                                   /* var2VarDb */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMError_free                                          */
/* Note: the lifetime of a DOMError in the DB is the object        */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(DOMError,                                 /* class */
                          marpaXml_true                             /* impactOnDb */
			  )

/*******************************************************************/
/*                                                                 */
/*                         DOMObjects                              */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMObjects_new                                         */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(DOMObjects,                                /* class */
                         char *objectName,                          /* decl */
                         objectName,                                /* args */
			 ,                                          /* extraInit */
                          /* bindingResult */
                         (_marpaXml_bind_text(sqliteStmtp, 1, objectName) == marpaXml_true) ? marpaXml_true : marpaXml_false
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMObjects_free                                        */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(DOMObjects,                               /* class */
                          marpaXml_true                             /* impactOnDb */
			  )

/*******************************************************************/
/*                                                                 */
/*                       DOMStringList                             */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_new                                      */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(DOMStringList,                             /* class */
                         void,                                      /* decl */
                         ,                                          /* args */
			 /* extraInit */
			 {
			   rcp->DOMObjectsp = NULL;
			   rcp -> cachedUntilFreeStmt[_marpaXml_DOMStringList_contains_e] = NULL;
			   rcp -> cachedUntilFreeSqls[_marpaXml_DOMStringList_contains_e] = NULL;
			 },
			 marpaXml_true                              /* bindingResult */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_contains                                 */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(marpaXml_boolean_t,                     /* rcType */
                            DOMStringList,                          /* class */
                            contains,                               /* method */
                            marpaXml_DOMStringList_t *thisp MARPAXML_ARG(marpaXml_String_t *strp) MARPAXML_ARG(marpaXml_boolean_t *rcp), /* decl */
                            thisp MARPAXML_ARG(strp) MARPAXML_ARG(rcp), /* args */
                            (_marpaXml_bind_text(sqliteStmtp, 1, marpaXml_String_getUtf8(strp)) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int,                                    /* dbType */
                            int,                                    /* dbMapType */
                            rcDb,                                   /* rcDb2rc */
                            marpaXml_false,                         /* defaultRc */
                            marpaXml_false                          /* changeId */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_free                                     */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(DOMStringList,                            /* class */
                          marpaXml_true                             /* impactOnDb */
			  )

/*******************************************************************/
/* _marpaXml_getStmt                                               */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_getStmt(void *objp, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  if (_marpaXml_stmt[stmt].generatedb == marpaXml_false) {
    *sqlsp = (char *) _marpaXml_stmt[stmt].sql;
    *sqliteStmtpp = _marpaXml_stmt[stmt].stmt;
    return marpaXml_true;
  } else {
    return _marpaXml_generateStmt(objp, stmt, sqlsp, sqliteStmtpp);
  }
}

/*******************************************************************/
/* _marpaXml_freeStmt                                              */
/*******************************************************************/
static C_INLINE void _marpaXml_freeStmt(void *objp, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  marpaXml_DOMStringList_t *DOMStringListp;

  if (_marpaXml_stmt[stmt].generatedb == marpaXml_true) {

    switch (stmt) {
    case _marpaXml_DOMStringList_contains_e:
      /* Delayed until free */
      break;
    case _marpaXml_DOMStringList_free_e:
      /* Cached dynamic statements */
      DOMStringListp = (marpaXml_DOMStringList_t *) objp;
      if (DOMStringListp->cachedUntilFreeStmt[stmt] != NULL && DOMStringListp->cachedUntilFreeSqls[stmt] != NULL) {
	MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_CACHED, DOMStringListp->cachedUntilFreeSqls[stmt]);
	_marpaXml_finalize(DOMStringListp->cachedUntilFreeSqls[stmt], &(DOMStringListp->cachedUntilFreeStmt[stmt]));
	free(DOMStringListp->cachedUntilFreeSqls[stmt]);
	DOMStringListp->cachedUntilFreeSqls[stmt] = NULL;
      }
      goto _default;
      break;
    default:
    _default:
      _marpaXml_finalize(*sqlsp, sqliteStmtpp);
      free(*sqlsp);
      *sqlsp = NULL;
      break;
    }
  }
}

/*******************************************************************/
/* _marpaXml_generateStmt                                          */
/* Note: it is not a hasard that this method is after all GENERIC  */
/*       stuff: it is using the internal marpaXml_DOMObjects_xxx   */
/*       whose prototypes are defined by the GENERIC macros upper. */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_generateStmt(void *objp, _marpaXml_stmt_e stmt, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  marpaXml_boolean_t        rcb = marpaXml_false;
  char                     *sqls;
  marpaXml_DOMObjects_t    *DOMObjectsp;
  marpaXml_DOMStringList_t *DOMStringListp;

  switch (stmt) {
  case _marpaXml_DOMStringList_new_e:
    if ((DOMObjectsp = _marpaXml_DOMObjects_new((char *) "DOMStringList")) == NULL) {
      break;
    }
    if ((sqls = messageBuilder(_marpaXml_stmt[stmt].sql, DOMObjectsp->id)) == messageBuilder_internalErrors()) {
      MARPAXML_ERRORX("%s", sqls);
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }
    if (_marpaXml_prepare(_dbp, sqls, sqliteStmtpp) == marpaXml_false) {
      free(sqls);
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }

    DOMStringListp = (marpaXml_DOMStringList_t *) objp;
    DOMStringListp->DOMObjectsp = DOMObjectsp;
    DOMStringListp->cachedUntilFreeStmt[_marpaXml_DOMStringList_contains_e] = NULL;
    DOMStringListp->cachedUntilFreeSqls[_marpaXml_DOMStringList_contains_e] = NULL;
    *sqlsp = sqls;
    rcb = marpaXml_true;

    break;

  case _marpaXml_DOMStringList_free_e:
    DOMStringListp = (marpaXml_DOMStringList_t *) objp;
    DOMObjectsp = DOMStringListp->DOMObjectsp;

    if ((sqls = messageBuilder(_marpaXml_stmt[stmt].sql, DOMObjectsp->id)) == messageBuilder_internalErrors()) {
      MARPAXML_ERRORX("%s", sqls);
      /* Free at least DOMObjectsp */
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }
    if (_marpaXml_prepare(_dbp, sqls, sqliteStmtpp) == marpaXml_false) {
      free(sqls);
      /* Free at least DOMObjectsp */
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }

    *sqlsp = sqls;
    rcb = marpaXml_true;
    _marpaXml_DOMObjects_free(&DOMObjectsp);

    break;

  case _marpaXml_DOMStringList_contains_e:
    DOMStringListp = (marpaXml_DOMStringList_t *) objp;
    if (DOMStringListp->cachedUntilFreeStmt[_marpaXml_DOMStringList_contains_e] != NULL &&
	DOMStringListp->cachedUntilFreeSqls[_marpaXml_DOMStringList_contains_e] != NULL) {

      *sqliteStmtpp = DOMStringListp->cachedUntilFreeStmt[_marpaXml_DOMStringList_contains_e];
      *sqlsp        = DOMStringListp->cachedUntilFreeSqls[_marpaXml_DOMStringList_contains_e];
      rcb = marpaXml_true;

    } else {

      DOMStringListp = (marpaXml_DOMStringList_t *) objp;
      DOMObjectsp = DOMStringListp->DOMObjectsp;

      if ((DOMStringListp->cachedUntilFreeSqls[stmt] = messageBuilder(_marpaXml_stmt[stmt].sql, DOMObjectsp->id)) == messageBuilder_internalErrors()) {
	MARPAXML_ERRORX("%s", DOMStringListp->cachedUntilFreeSqls[stmt]);
	DOMStringListp->cachedUntilFreeSqls[stmt] = NULL;
	break;
      }
      if (_marpaXml_prepare(_dbp, DOMStringListp->cachedUntilFreeSqls[stmt], &(DOMStringListp->cachedUntilFreeStmt[stmt])) == marpaXml_false) {
	free(DOMStringListp->cachedUntilFreeSqls[stmt]);
	DOMStringListp->cachedUntilFreeSqls[stmt] = NULL;
	break;
      }

      MARPAXML_TRACEX("[%s] %s\n", _MARPAXML_CACHE, DOMStringListp->cachedUntilFreeSqls[stmt]);

      *sqliteStmtpp = DOMStringListp->cachedUntilFreeStmt[stmt];
      *sqlsp        = DOMStringListp->cachedUntilFreeSqls[stmt];
      rcb = marpaXml_true;
    }

    break;

  default:
    MARPAXML_ERRORX("_marpaXml_generateStmt called with an invalid statement code %d\n", stmt);
    break;
  }

  return rcb;
}

