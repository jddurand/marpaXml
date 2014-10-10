#include "internal/config.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#include "unicode/utext.h"
#include "unicode/ustring.h"
#include "unicode/uchar.h"
#include "unicode/uclean.h"
#include "sqlite3.h"
#include "marpaXml/DOM2.h"

#include "internal/messageBuilder.h"
#include "internal/hash.h"
#include "internal/streamIn.h"
#include "internal/manageBuf.h"
#include "internal/grammar/qname_1_0.h"
#include "internal/grammar/qname_1_1.h"
#include "internal/DOM_Lexeme.h"
#include "../db/Dom Level 3 Core.h"

/********************************************************************************/
/*                            Internal types                                    */
/********************************************************************************/
/* In any case it is VITAL that xxx_new and xxx_free are surrounding other methods */
/* Management of dynamic prepared statements rely on this */
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

  _marpaXml_DOMUtils_new_e,
  _marpaXml_DOMUtils_vacuum_e,
  _marpaXml_DOMUtils_free_e,

  _marpaXml_DOMStringList_new_e,
  _marpaXml_DOMStringList_item_e,
  _marpaXml_DOMStringList_getLength_e,
  _marpaXml_DOMStringList_contains_e,
  _marpaXml_DOMStringList_free_e,

  _marpaXml_NameList_new_e,
  _marpaXml_NameList_getName_e,
  _marpaXml_NameList_getNamespaceURI_e,
  _marpaXml_NameList_getLength_e,
  _marpaXml_NameList_contains_e,
  _marpaXml_NameList_containsNS_e,
  _marpaXml_NameList_free_e,

  _marpaXml_Node_new_e,
  _marpaXml_Node_free_e,

  _marpaXml_DOMImplementationList_new_e,
  _marpaXml_DOMImplementationList_item_e,
  _marpaXml_DOMImplementationList_getLength_e,
  _marpaXml_DOMImplementationList_free_e,

  _marpaXml_DOMImplementationSource_new_e,
  _marpaXml_DOMImplementationSource_getDOMImplementation_e,
  _marpaXml_DOMImplementationSource_getDOMImplementationList_e,
  _marpaXml_DOMImplementationSource_free_e,

  _marpaXml_DOMImplementation_new_e,
  _marpaXml_DOMImplementation_newFromFeatureAndVersion_e,
  _marpaXml_DOMImplementation_newFromImplementationName_e,
  _marpaXml_DOMImplementation_hasFeature_e,
  _marpaXml_DOMImplementation_createDocumentType_e,
  _marpaXml_DOMImplementation_createDocument_e,
  _marpaXml_DOMImplementation_getFeature_e,
  _marpaXml_DOMImplementation_free_e,

  _marpaXml_DocumentType_new_e,
  _marpaXml_DocumentType_free_e,

  _marpaXml_Lexeme_new_e,
  _marpaXml_Lexeme_insertFromUTF16_e,
  _marpaXml_Lexeme_insertFromUTF8_e,
  _marpaXml_Lexeme_insertFromString_e,
  _marpaXml_Lexeme_getId_e,
  _marpaXml_Lexeme_getString_e,
  _marpaXml_Lexeme_delete_e,
  _marpaXml_Lexeme_free_e,

  __marpaXml_stmt_max_e,
} _marpaXml_stmt_e;

typedef struct _marpaXml_cachedStmtExclusiveRange {
  _marpaXml_stmt_e new_e;
  _marpaXml_stmt_e free_e;
} _marpaXml_cachedStmtExclusiveRange_t;

static _marpaXml_cachedStmtExclusiveRange_t DOMStringListCachedStmt         = { _marpaXml_DOMStringList_new_e, _marpaXml_DOMStringList_free_e };
static _marpaXml_cachedStmtExclusiveRange_t NameListCachedStmt              = { _marpaXml_NameList_new_e, _marpaXml_NameList_free_e };
static _marpaXml_cachedStmtExclusiveRange_t DOMImplementationListCachedStmt = { _marpaXml_DOMImplementationList_new_e, _marpaXml_DOMImplementationList_free_e };
static _marpaXml_cachedStmtExclusiveRange_t LexemeCachedStmt                = { _marpaXml_Lexeme_new_e, _marpaXml_Lexeme_free_e };

/* This is used to exec() anything that must be done before init the init */
typedef struct _marpaXml_init {
  const char *sql;
} _marpaXml_init_t;

/* Describe the type of request : does it change the db ? */
#define MARPAXML_DB_TYPE_ANY       =      0:
#define MARPAXML_DB_TYPE_CHANGE    = 1 << 0:
#define MARPAXML_DB_TYPE_NOCHANGE  = 1 << 1; 

/* Describe what is expected :  what check after the statement has been executed ?*/
#define MARPAXML_DB_NOCHECK     =      0;
#define MARPAXML_DB_CHECKCHANGE = 1 << 0;
#define MARPAXML_DB_CHECKONEROW = 1 << 1;
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
  marpaXml_boolean_t  noopb;
  const char          *sql;
} _marpaXml_stmt_t;

/* For the SQLite exec callback */
typedef int (*_marpaXml_SQLiteExecCallback_t)(void *, int, char **, char **);

/* DOMObjects should be internal only */
typedef struct marpaXml_DOMObjects marpaXml_DOMObjects_t;
static C_INLINE marpaXml_DOMObjects_t *marpaXml_DOMObjects_new(char *objectName);
static C_INLINE marpaXml_boolean_t     marpaXml_DOMObjects_free(marpaXml_DOMObjects_t **thisp);

/* DOMUtils should be internal only */
typedef struct marpaXml_DOMUtils marpaXml_DOMUtils_t;
static C_INLINE marpaXml_DOMUtils_t *marpaXml_DOMUtils_new(void);
static C_INLINE marpaXml_boolean_t   marpaXml_DOMUtils_free(marpaXml_DOMUtils_t **thisp);

/* DOMImplementation constructor should be internal only */
static C_INLINE marpaXml_DOMImplementation_t *marpaXml_DOMImplementation_new(void);
static C_INLINE marpaXml_boolean_t            marpaXml_DOMImplementation_newFromFeatureAndVersion(marpaXml_String_t *featurep, marpaXml_String_t *versionp, marpaXml_DOMImplementation_t **rcp);
static C_INLINE marpaXml_boolean_t            marpaXml_DOMImplementation_newFromImplementationName(marpaXml_String_t *implementationNamep, marpaXml_DOMImplementation_t **rcp);

/* DOMImplementationList constructor should be internal only */
static C_INLINE marpaXml_DOMImplementationList_t   *marpaXml_DOMImplementationList_new(const char *wheres);

/* DocumentType constructor should be internal only */
static C_INLINE marpaXml_DocumentType_t   *marpaXml_DocumentType_new(marpaXml_String_t *qualifiedNamep, marpaXml_String_t *publicIdp, marpaXml_String_t *systemIdp);

/* For the API */
struct marpaXml_DOMException  { sqlite3_int64 id; };
struct marpaXml_DOMError      { sqlite3_int64 id; };
struct marpaXml_DOMObjects    { sqlite3_int64 id; };
struct marpaXml_DOMUtils      { sqlite3_int64 id; };
struct marpaXml_DOMStringList {
  sqlite3_int64          id;
  marpaXml_DOMObjects_t *DOMObjectsp;
  sqlite3_stmt          *cachedUntilFreeStmt[__marpaXml_stmt_max_e];  /* Tant pis for the few bytes unused */
  char                  *cachedUntilFreeSqls[__marpaXml_stmt_max_e];  /* Ditto */
};
struct marpaXml_NameList {
  sqlite3_int64          id;
  marpaXml_DOMObjects_t *DOMObjectsp;
  sqlite3_stmt          *cachedUntilFreeStmt[__marpaXml_stmt_max_e];  /* Tant pis for the few bytes unused */
  char                  *cachedUntilFreeSqls[__marpaXml_stmt_max_e];  /* Ditto */
};
struct marpaXml_DOMImplementationList {
  sqlite3_int64 id;
  marpaXml_DOMObjects_t *DOMObjectsp;
  const char            *wheres;
  sqlite3_stmt          *cachedUntilFreeStmt[__marpaXml_stmt_max_e];  /* Tant pis for the few bytes unused */
  char                  *cachedUntilFreeSqls[__marpaXml_stmt_max_e];  /* Ditto */
};
struct marpaXml_Node                      { sqlite3_int64 id; };
struct marpaXml_Document                  { sqlite3_int64 id; };
struct marpaXml_DOMImplementationSource   { sqlite3_int64 id; const char *wheresp; };
struct marpaXml_DOMImplementation         { sqlite3_int64 id; const char *implementationNames; };
struct marpaXml_DocumentType              { sqlite3_int64 id; };
struct marpaXml_Lexeme {
  sqlite3_int64 id;
  marpaXml_DOMObjects_t *DOMObjectsp;
  sqlite3_stmt          *cachedUntilFreeStmt[__marpaXml_stmt_max_e];  /* Tant pis for the few bytes unused */
  char                  *cachedUntilFreeSqls[__marpaXml_stmt_max_e];  /* Ditto */
};

typedef struct marpaXml_featureAndVersion {
  marpaXml_String_t *featurep;
  marpaXml_String_t *versionp;
} marpaXml_featureAndVersion_t;

/********************************************************************************/
/*                                Macros                                        */
/********************************************************************************/
#define _MARPAXML_ARGNOTUSED           0
#ifndef SQLITE_NTRANSACTION
#define _MARPAXML_TRANSACTION_BEGIN    _marpaXml_Transaction_Begin()    /* For any API call: transaction begin */
#define _MARPAXML_TRANSACTION_END      _marpaXml_Transaction_End()      /* For any API call: transaction commit */
#define _MARPAXML_TRANSACTION_ROLLBACK _marpaXml_Transaction_Rollback(); /* For any API call: transaction rollback */
#else
#define _MARPAXML_TRANSACTION_BEGIN    marpaXml_true                    /* For any API call: transaction begin is no op and always successful */
#define _MARPAXML_TRANSACTION_END      marpaXml_true                    /* For any API call: transaction commit is no op and always successful */
#define _MARPAXML_TRANSACTION_ROLLBACK                                  /* For any API call: transaction rollback is no op */
#endif
#define _MARPAXML_MAXCHARS_IN_TRACE    30                               /* Maximum length when printing out SQL commands */
#define _MARPAXML_FEATURE_LIKE         " (feature LIKE '%s') "
#define _MARPAXML_AND                  " AND "
#define _MARPAXML_VERSION_EQ           " (version = '%s') "
#define _MARPAXML_INTERSECT            " INTERSECT "
#ifdef _WIN32
#define _marpaXml_snprintf(p, s, fmt, ...)  _snprintf_s(p, s, _TRUNCATE, fmt, __VA_ARGS__)
#else
#define _marpaXml_snprintf(p, s, fmt, ...)  snprintf(p, s, fmt, __VA_ARGS__)
#endif
/* Endianness detection - reference: http://www.ibm.com/developerworks/aix/library/au-endianc/ */
#define _MARPAXML_LITTLE_ENDIAN 0
#define _MARPAXML_BIG_ENDIAN    1
#define _MARPAXML_VACUUM_FREQUENCY 10000
#define _MARPAXML_SELECT_DISTINCT_implementationName_FROM_DOMImplementation_WHERE " SELECT DISTINCT implementationName FROM DOMImplementation WHERE "
#define _MARPAXML_SELECT_STAR_FROM_BEG " SELECT * FROM ( "
#define _MARPAXML_SELECT_STAR_FROM_END " ) "
#define _MARPAXML_LIMIT_ONE " LIMIT 1 "
static C_INLINE void *sqlite3_column_ptr(sqlite3_stmt*, int iCol);

/* Any API call must have these macros surrounding database access */
#define MARPAXML_DOM_DB_API_HEADER(method, badRc)                       \
  if (marpaXml_DOM_init(NULL) == marpaXml_false) { return badRc; }      \
  MARPAXML_TRACEX("[%s] %s", _MARPAXML_APICALL, method);                    \
  if (_MARPAXML_TRANSACTION_BEGIN == marpaXml_false) { return badRc; }

#define MARPAXML_DOM_DB_API_TRAILER(rc, badRc)                          \
  if (((rc) == marpaXml_false) || (_MARPAXML_TRANSACTION_END == marpaXml_false)) { \
    _MARPAXML_TRANSACTION_ROLLBACK                                      \
    return badRc;                                                       \
  }

#define MARPAXML_GENERIC_GET_API(staticStorage, rcType, class, method, dbType, dbMapType, rcDb2Rc) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType *rcp) { \
    dbMapType rcDb;                                                     \
    int    sqliteRc;                                                    \
    unsigned short nbRows = 0;                                          \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
    _marpaXml_stmt_e stmte = _marpaXml_##class##_##method##_e;		\
                                                                        \
    if (rcp == NULL) {                                                  \
      MARPAXML_ERROR0("Last argument must be != NULL");               \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    if (_marpaXml_getStmt(thisp, stmte, &sqls, &sqliteStmtp) == marpaXml_false) { \
      return marpaXml_false;                                            \
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, sqls);			\
                                                                        \
    if (_marpaXml_bind_int64(sqliteStmtp, 1, thisp->id, _MARPAXML_ARGNOTUSED) == marpaXml_false) { \
      _marpaXml_reset(sqliteStmtp); \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
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
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (nbRows <= 0) {                                                  \
      MARPAXML_ERRORX("[%s] no row", sqls);				\
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    else if (nbRows > 1) {						\
      MARPAXML_ERRORX("[%s] more than one row", sqls); \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
    return marpaXml_true;                                               \
  }                                                                     \
                                                                        \
  staticStorage marpaXml_boolean_t marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType *rcp) { \
    marpaXml_boolean_t rc;                                                          \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)    \
    rc = _marpaXml_##class##_##method(thisp, rcp);                 \
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

/* This macros requires that the first argument is always thisp, and last argument is always rcp */
/* selectb mode requires that exactly one row is fetched */
/* changesb mode requires that SQLite detected changes */
/* insertb mode requires that last inserted ID is > 0 */
/* It is the responsability of _marpaXml_stmt_[] array to set changesb accordingly to insertb, if wanted */

#define MARPAXML_GENERIC_METHOD_API(staticStorage, class, method, decl, args, prolog, bindingResult, dbType, dbMapType, rcDb2Rc, defaultRc, changeId, epilog) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(decl) { \
    marpaXml_boolean_t rcb = marpaXml_false;				\
    dbMapType       rcDb;                                               \
    int             sqliteRc;                                           \
    unsigned short  nbRows = 0;                                         \
    char           *sqls;						\
    sqlite3_stmt   *sqliteStmtp;					\
    sqlite3_int64   id;                                                 \
    _marpaXml_stmt_e stmte = _marpaXml_##class##_##method##_e;		\
    prolog                                                              \
                                                                        \
    if (rcp == NULL) {                                                  \
      MARPAXML_ERROR0("Last argument must be != NULL");                 \
      goto end;								\
    }                                                                   \
                                                                        \
    defaultRc                                                           \
                                                                        \
    if (_marpaXml_getStmt(thisp, stmte, &sqls, &sqliteStmtp) == marpaXml_false) { \
      goto end;								\
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, sqls);			\
                                                                        \
    if ((bindingResult) == marpaXml_false) {				\
      _marpaXml_reset(sqliteStmtp);					\
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
      goto end;								\
    }                                                                   \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
      if (++nbRows > 1) {                                               \
        break;                                                          \
      }                                                                 \
      rcDb = sqlite3_column_##dbType(sqliteStmtp, 0);			\
      rcDb2Rc	  						        \
    }                                                                   \
                                                                        \
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
      goto end;								\
    }                                                                   \
                                                                        \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
      goto end;								\
    }                                                                   \
    if (_marpaXml_stmt[stmte].selectb == marpaXml_true) {		\
      if (nbRows <= 0) {						\
        MARPAXML_ERRORX("[%s] no row", sqls);				\
        _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
        goto end;							\
      }                                                                 \
      else if (nbRows > 1) {						\
        MARPAXML_ERRORX("[%s] more than one row", sqls);              \
        _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
        goto end;							\
      }                                                                 \
    }                                                                   \
    if (_marpaXml_stmt[stmte].changesb == marpaXml_true){		\
      if (_marpaXml_changes() == marpaXml_false) {                      \
        _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
        goto end;							\
      }                                                                 \
    }                                                                   \
    if ((_marpaXml_stmt[stmte].insertb == marpaXml_true) && (changeId == marpaXml_true)) { \
      id = sqlite3_last_insert_rowid(_marpaXml_dbp);			\
      if (id <= 0) {                                                    \
	MARPAXML_ERRORX("[%s] id <= 0 at %s:%d", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(thisp, _marpaXml_##class##_new_e, &sqls, &sqliteStmtp); \
        goto end;							\
      }	else {								\
        thisp->id = id;                                                 \
      }                                                                 \
      MARPAXML_TRACEX("[%s] %lld", _MARPAXML_ID, (unsigned long long int) thisp->id); \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp);		\
    rcb = marpaXml_true;						\
									\
  end:									\
    epilog                                                              \
                                                                        \
    return rcb;                                                         \
  }                                                                     \
                                                                        \
  staticStorage marpaXml_boolean_t marpaXml_##class##_##method(decl) {  \
    marpaXml_boolean_t rc;						\
    									\
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)	\
    rc = _marpaXml_##class##_##method(args);				\
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

#define MARPAXML_GENERIC_SET_API(staticStorage, rcType, class, method, dbType, var, var2VarDb) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType var) { \
    int    sqliteRc;                                                    \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
    _marpaXml_stmt_e stmte = _marpaXml_##class##_##method##_e;		\
                                                                        \
    if (_marpaXml_getStmt(thisp, stmte, &sqls, &sqliteStmtp) == marpaXml_false) { \
      return marpaXml_false;                                            \
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, sqls); \
                                                                        \
    if ((_marpaXml_bind_int64(sqliteStmtp, 1, thisp->id, _MARPAXML_ARGNOTUSED) == marpaXml_false) || \
	/* The argument IS used when dbType is "text" - not in the other cases */ \
        (_marpaXml_bind_##dbType(sqliteStmtp, 2, var2VarDb, 0) == marpaXml_false)) { \
      _marpaXml_reset(sqliteStmtp);					\
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
    }                                                                   \
                                                                        \
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
    if (sqliteRc != SQLITE_DONE) {                                      \
      MARPAXML_ERRORX("[%s] _marpaXml_step() returns %d != SQLITE_DONE: %s", sqls, sqliteRc, sqlite3_errstr(sqliteRc)); \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    if ((_marpaXml_stmt[stmte].changesb == marpaXml_true) && (_marpaXml_changes() == marpaXml_false)) { \
      _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
      return marpaXml_false;                                            \
    }                                                                   \
                                                                        \
    _marpaXml_freeStmt(thisp, stmte, &sqls, &sqliteStmtp); \
									\
    return marpaXml_true;                                               \
  }                                                                     \
                                                                        \
  staticStorage marpaXml_boolean_t marpaXml_##class##_##method(marpaXml_##class##_t *thisp, rcType var) { \
    marpaXml_boolean_t rc;                                                          \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, 0)    \
    rc = _marpaXml_##class##_##method(thisp, var);                 \
    MARPAXML_DOM_DB_API_TRAILER(rc == marpaXml_true, marpaXml_false)    \
                                                                        \
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_APIRC, (rc == marpaXml_true) ? _MARPAXML_TRUE : _MARPAXML_FALSE); \
    return rc;                                                          \
  }

/* Hack to make the preprocessor believe a concatenation is a single argument */
#define MARPAXML_ARG(x) ,x

#define MARPAXML_GENERIC_NEW_API(staticStorage, class, method, decl, args, extraInit, bindingResult, noStepCheck) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_free(marpaXml_##class##_t **thispp); \
  static C_INLINE marpaXml_##class##_t *_marpaXml_##class##_##method(decl) { \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
    marpaXml_##class##_t *rcp;                                          \
    int                   sqliteRc;                                     \
    unsigned short        nbRows = 0;					\
    sqlite_int64          id = 0;					\
                                                                        \
    if ((rcp = malloc(sizeof(marpaXml_##class##_t))) == NULL) {          \
      MARPAXML_ERRORX("malloc() returns NULL: %s at %s:%d", strerror(errno), __FILE__, __LINE__); \
      return NULL;							\
    }                                                                   \
    rcp->id = 0;								\
    extraInit								\
                                                                        \
    if (_marpaXml_getStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }									\
    									\
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, sqls);			\
    									\
    if ((bindingResult) == marpaXml_false) {				\
      _marpaXml_reset(sqliteStmtp);					\
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
                                                                        \
    if (noStepCheck == marpaXml_false) {				\
      while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW) {	\
	if (++nbRows > 1) {						\
	  break;							\
	}								\
	id = sqlite3_column_int64(sqliteStmtp, 0);			\
      }									\
    }									\
									\
    if (_marpaXml_reset(sqliteStmtp) == marpaXml_false) {		\
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
    									\
    if ((noStepCheck == marpaXml_false) && (sqliteRc != SQLITE_DONE)) {	\
      MARPAXML_ERRORX("[%s] step returned %d != SQLITE_DONE: %s at %s:%d", sqls, sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__); \
      _marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
      if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
      return NULL;							\
    }                                                                   \
                                                                        \
    if (_marpaXml_stmt[_marpaXml_##class##_##method##_e].changesb == marpaXml_true) { \
      if (_marpaXml_changes() == marpaXml_false) {                      \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      rcp->id = sqlite3_last_insert_rowid(_marpaXml_dbp);		\
      if (rcp->id <= 0) {						\
	MARPAXML_ERRORX("[%s] id <= 0 at %s:%d", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      MARPAXML_TRACEX("[%s] %lld", _MARPAXML_ID, (unsigned long long int) rcp->id); \
    }									\
    else if (_marpaXml_stmt[_marpaXml_##class##_##method##_e].selectb == marpaXml_true) { \
      if (nbRows == 0) {						\
	MARPAXML_ERRORX("[%s] no row at %s:%d", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      else if (nbRows > 1) {						\
	MARPAXML_ERRORX("[%s] more than one row at %s:%d", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      rcp->id = id;							\
      if (rcp->id <= 0) {						\
	MARPAXML_ERRORX("[%s] id is <= 0 at %s:%d", sqls, __FILE__, __LINE__); \
	_marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	if (_marpaXml_##class##_free(&rcp) == marpaXml_false) { free(rcp); } \
	return NULL;							\
      }									\
      MARPAXML_TRACEX("[%s] %lld", _MARPAXML_ID, (unsigned long long int) rcp->id); \
    }									\
    									\
    _marpaXml_freeStmt(rcp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
    									\
    return rcp;                                                          \
  }                                                                     \
                                                                        \
  staticStorage marpaXml_##class##_t *marpaXml_##class##_##method(decl) {	\
    marpaXml_##class##_t *rc;                                           \
                                                                        \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, NULL)    \
    rc = _marpaXml_##class##_##method(args);                            \
    MARPAXML_DOM_DB_API_TRAILER(rc != NULL ? marpaXml_true : marpaXml_false, NULL)  \
                                                                        \
    MARPAXML_TRACEX("[%s] %p", _MARPAXML_APIRC, rc);		        \
                                                                        \
    return rc;                                                          \
  }

#define MARPAXML_GENERIC_FREE_API(staticStorage, class, method, impactOnDb, prolog) \
  static C_INLINE marpaXml_boolean_t _marpaXml_##class##_##method(marpaXml_##class##_t **thispp) { \
    marpaXml_##class##_t *thisp;                                        \
    int                  sqliteRc;                                      \
    marpaXml_boolean_t   rc = marpaXml_true;                            \
    char                 *sqls;						\
    sqlite3_stmt         *sqliteStmtp;					\
    prolog                                                              \
                                                                        \
    if (thispp != NULL) {                                               \
      thisp = *thispp;                                                  \
                                                                        \
      if (thisp != NULL) {                                              \
        if (impactOnDb == marpaXml_true) {				\
	  if (_marpaXml_getStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp) == marpaXml_false) { \
	    rc = marpaXml_false;					\
	  } else {							\
	    MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, sqls);		\
	    if ((thisp->id > 0) && _marpaXml_bind_int64(sqliteStmtp, 1, thisp->id, _MARPAXML_ARGNOTUSED) == marpaXml_false) { \
	      _marpaXml_reset(sqliteStmtp);				\
	      _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
	      rc = marpaXml_false;					\
	    } else {							\
	      do {							\
	      } while ((sqliteRc = _marpaXml_step(sqliteStmtp)) == SQLITE_ROW); \
	      if (sqliteRc != SQLITE_DONE) {				\
		MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__); \
		_marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_##method##_e].stmt); \
		_marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
		rc = marpaXml_false;					\
	      } else {							\
		if ((_marpaXml_stmt[_marpaXml_##class##_##method##_e].changesb == marpaXml_true) && (_marpaXml_changes() == marpaXml_false)) { \
		  _marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_##method##_e].stmt); \
		  _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
		  rc = marpaXml_false;					\
		} else {						\
		  _marpaXml_reset(_marpaXml_stmt[_marpaXml_##class##_##method##_e].stmt); \
		  _marpaXml_freeStmt(thisp, _marpaXml_##class##_##method##_e, &sqls, &sqliteStmtp); \
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
  staticStorage marpaXml_boolean_t marpaXml_##class##_##method(marpaXml_##class##_t **thispp) { \
    marpaXml_boolean_t rc;                                              \
    MARPAXML_DOM_DB_API_HEADER("marpaXml_" #class "_" #method, marpaXml_false) \
    rc = _marpaXml_##class##_##method(thispp);                          \
    MARPAXML_DOM_DB_API_TRAILER(rc, marpaXml_false)                     \
                                                                        \
    return rc;                                                          \
  }

/********************************************************************************/
/*                                 Constants                                    */
/********************************************************************************/
static const char *_MARPAXML_LOADCOLLATION     = "SELECT icu_load_collationWithStrength(:locale, 'LOCALIZED', :collStrength)";
#ifndef MARPAXML_NTRACE
static const char *_MARPAXML_EXEC              = "   EXEC";
static const char *_MARPAXML_PREPARE           = "PREPARE";
static const char *_MARPAXML_CACHE             = "  CACHE";
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
#endif
static const char *_MARPAXML_UTF16LE           = "UTF-16LE";
static const char *_MARPAXML_UTF16BE           = "UTF-16BE";

/********************************************************************************/
/*                           Static variables                                   */
/********************************************************************************/
static sqlite3                 *_marpaXml_dbp = NULL;
static marpaXml_boolean_t       _marpaXml_isInitialized = marpaXml_false;
static marpaXmlLog_t           *marpaXmlLogp = NULL;  /* Intentionnaly without s_ prefix because of MARPAXML log macros */
static marpaXml_String_Option_t _marpaXml_String_globalOption;
static marpaXml_boolean_t       _marpaXml_isLittleEndianb = marpaXml_false;
static marpaXml_boolean_t       _marpaXml_isBigEndianb = marpaXml_false;
static char                    *_marpaXml_UTF16_Encodings = NULL;
static qname_1_0_t             *qname_1_0p = NULL;
static qname_1_1_t             *qname_1_1p = NULL;

static _marpaXml_stmt_t _marpaXml_stmt[] = {

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* Note: For selectb, we put 0 instead of marpaXml_false to indicate this is a noop in this context.                       */
  /*       Indeed, selectb is meaninful only in the new() sql's that have changesb to false                                  */
  /*       In C, _order start at 0, In db this is at 1. DOM spec says to return NULL if nothing found                        */
  /* ------------------------------------------------------------------------------------------------------------------------*/

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_BeginImmediate_e, marpaXml_false, "BEGIN IMMEDIATE TRANSACTION" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_End_e,            marpaXml_false, "END TRANSACTION" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Transaction_Rollback_e,       marpaXml_false, "ROLLBACK TRANSACTION" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMException: the lifetime of the row is the lifetime of the object */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMException_new_e,           marpaXml_false, "INSERT INTO DOMException (code, message) VALUES (?1, ?2)" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMException_getCode_e,       marpaXml_false, "SELECT code FROM DOMException WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_setCode_e,       marpaXml_false, "UPDATE DOMException SET code = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMException_getMessage_e,    marpaXml_false, "SELECT message FROM DOMException WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_setMessage_e,    marpaXml_false, "UPDATE DOMException SET message = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMException_free_e,          marpaXml_false, "DELETE FROM DOMException WHERE (id = ?1)" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMError */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMError_new_e,               marpaXml_false, "INSERT INTO DOMError DEFAULT VALUES" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMError_getSeverity_e,       marpaXml_false, "SELECT severity FROM DOMError WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMError_setSeverity_e,       marpaXml_false, "UPDATE DOMError SET severity = ?2 WHERE (id = ?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMError_free_e,              marpaXml_false, "DELETE FROM DOMError WHERE (id = ?1)" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMObjects: used to track dynamic objects, i.e. those that have generatedb to marpaXml_true */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DOMObjects_new_e,             marpaXml_false, "INSERT INTO DOMObjects (objectName) VALUES (?1)" },
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_DOMObjects_free_e,            marpaXml_false, "DELETE FROM DOMObjects WHERE (id = ?1)" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMUtils: SQLite oriented statements */
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMUtils_new_e,               marpaXml_true,  "PRAGMA _marpaXml_DOMUtils_new_e; /* No op */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMUtils_vacuum_e,            marpaXml_false, "VACUUM" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMUtils_free_e,              marpaXml_true,  "PRAGMA _marpaXml_DOMUtils_free_e; /* No op */" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMStringList : we use the temp namespace so that main is not changed */
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMStringList_new_e,          marpaXml_false, "CREATE TEMPORARY VIEW DOMStringList%lld AS SELECT item FROM DOMString" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMStringList_item_e,         marpaXml_false, "SELECT COALESCE((SELECT item FROM DOMStringList%lld LIMIT 1 OFFSET ?1), NULL)" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMStringList_getLength_e,    marpaXml_false, "SELECT COUNT(*) FROM DOMStringList%lld" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMStringList_contains_e,     marpaXml_false, "SELECT CASE WHEN EXISTS (SELECT 1 FROM DOMStringList%lld WHERE (item = ?1) LIMIT 1) THEN 1 ELSE 0 END" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMStringList_free_e,         marpaXml_false, "DROP VIEW DOMStringList%lld" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* NameList : we use the temp namespace so that main is not changed */
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_NameList_new_e,               marpaXml_false, "CREATE TEMPORARY VIEW NameList%lld AS SELECT name, namespaceURI FROM Node" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_NameList_getName_e,           marpaXml_false, "SELECT COALESCE((SELECT name FROM NameList%lld LIMIT 1 OFFSET ?1), NULL)" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_NameList_getNamespaceURI_e,   marpaXml_false, "SELECT COALESCE((SELECT namespaceURI FROM NameList%lld LIMIT 1 OFFSET ?1), NULL)" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_NameList_getLength_e,         marpaXml_false, "SELECT COUNT(*) FROM NameList%lld" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_NameList_contains_e,          marpaXml_false, "SELECT CASE WHEN EXISTS (SELECT 1 FROM NameList%lld WHERE (name = ?1) LIMIT 1) THEN 1 ELSE 0 END" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_NameList_containsNS_e,        marpaXml_false, "SELECT CASE WHEN EXISTS (SELECT 1 FROM NameList%lld WHERE (namespaceURI = ?1 AND name = ?2) LIMIT 1) THEN 1 ELSE 0 END" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_NameList_free_e,              marpaXml_false, "DROP VIEW NameList%lld" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* Node */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_Node_new_e,                   marpaXml_false, "INSERT INTO Node DEFAULT VALUES" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Node_free_e,                  marpaXml_true,  "PRAGMA _marpaXml_Node_free_e; /* No op */" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMImplementationList */
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementationList_new_e,  marpaXml_false, "CREATE TEMPORARY VIEW DOMImplementationList%lld AS %s" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMImplementationList_item_e, marpaXml_false, "SELECT COALESCE((SELECT implementationName FROM DOMImplementationList%lld LIMIT 1 OFFSET ?1), NULL)" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMImplementationList_getLength_e,    marpaXml_false, "SELECT COUNT(*) FROM DOMImplementationList%lld" },
  { NULL, marpaXml_true,  marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementationList_free_e, marpaXml_false, "DROP VIEW DOMImplementationList%lld" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMImplementationSource */
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementationSource_new_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementationSource_new_e; /* No op */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMImplementationSource_getDOMImplementation_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementationSource_getDOMImplementation_e; /* Implemented as an exec() */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementationSource_getDOMImplementationList_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementationSource_getDOMImplementationList_e; /* Implemented as an exec() */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementationSource_free_e, marpaXml_true, "PRAGMA _marpaXml_DOMImplementationSource_free_e; /* No op */" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DOMImplementation */
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_new_e,        marpaXml_true, "PRAGMA _marpaXml_DOMImplementation_new_e; /* No op */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMImplementation_newFromFeatureAndVersion_e,  marpaXml_false, "SELECT id FROM DOMImplementation WHERE ((feature LIKE ?1) AND ((?3 IS NULL) OR (version = ?2))) LIMIT 1; /* Internal */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_DOMImplementation_newFromImplementationName_e,  marpaXml_false, "SELECT id FROM DOMImplementation WHERE (implementationName = ?1) LIMIT 1; /* Internal */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_hasFeature_e,  marpaXml_false, "SELECT CASE WHEN EXISTS (SELECT 1 FROM DOMImplementation WHERE ((implementationName = (SELECT implementationName WHERE (id = ?1))) AND (feature LIKE ?2) AND ((?3 IS NULL) OR (version = ?3))) LIMIT 1) THEN 1 ELSE 0 END" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_createDocumentType_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementation_createDocumentType_e; /* TO DO */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_createDocument_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementation_createDocument_e; /* TO DO */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_getFeature_e,  marpaXml_true, "PRAGMA _marpaXml_DOMImplementation_getFeature_e; /* No op - implemented as a sw logic around hasFeature */" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DOMImplementation_free_e, marpaXml_true, "PRAGMA _marpaXml_DOMImplementation_free_e; /* No op */" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* DocumentType */
  { NULL, marpaXml_false, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_DocumentType_new_e,             marpaXml_false, "INSERT INTO DocumentType (name, publicId, systemId, internalSubset, DOMNode_id) VALUES (?1, ?2, ?3, ?4, ?5)" },
  { NULL, marpaXml_false, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_DocumentType_free_e,            marpaXml_true, "PRAGMA _marpaXml_DocumentType_free_e; /* No op */" },

  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* stmt generatedb      changesb        selectb,        insertb,        e                                       noop            sql        */
  /* ----------------------------------------------------------------------------------------------------------------------------------------*/
  /* Lexeme */
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_Lexeme_new_e,                    marpaXml_false, "CREATE TEMPORARY TABLE Lexeme%lld (id integer NOT NULL, string text, PRIMARY KEY (id))" },
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_Lexeme_insertFromUTF16_e,        marpaXml_false, "INSERT INTO Lexeme%lld (string) VALUES (?1)" },
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_Lexeme_insertFromUTF8_e,         marpaXml_false, "INSERT INTO Lexeme%lld (string) VALUES (?1)" },
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_true,  _marpaXml_Lexeme_insertFromString_e,       marpaXml_false, "INSERT INTO Lexeme%lld (string) VALUES (?1)" },
  { NULL, marpaXml_true, marpaXml_false, marpaXml_false, marpaXml_false, _marpaXml_Lexeme_getId_e,                  marpaXml_true,  "PRAGMA _marpaXml_Lexeme_getId_e; /* No op */" },
  { NULL, marpaXml_true, marpaXml_false, marpaXml_true,  marpaXml_false, _marpaXml_Lexeme_getString_e,              marpaXml_false, "SELECT string FROM Lexeme%lld WHERE (id = ?1)" },
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_Lexeme_delete_e,                 marpaXml_false, "DELETE FROM Lexeme%lld WHERE (id = ?1)" },
  { NULL, marpaXml_true, marpaXml_true,  marpaXml_false, marpaXml_false, _marpaXml_Lexeme_free_e,                   marpaXml_true,  "DROP TABLE Lexeme%lld" },

  { NULL, 0, 0, 0, 0, 0, 0, NULL }
};

static _marpaXml_init_t _marpaXml_pragmas[] = {
  {
    "PRAGMA encoding = \"UTF-16\""
  },
  { NULL }
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
  /* Features */
  {
    /* The DOM Level 3 Core module is backward compatible with the DOM Level 2 Core [DOM Level 2 Core] module, */
    "DELETE FROM DOMImplementation; "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'Core', '3.0', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'Core') AND (version = '3.0') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'Core', '2.0', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'Core') AND (version = '2.0') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'Core', '', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'Core') AND (version = '') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'Core', NULL, 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'Core') AND (version IS NULL) AND (implementationName LIKE 'marpaXml'))); "
    /* The DOM Level 3 XML module is backward compatible with the DOM Level 2 XML [DOM Level 2 Core] and DOM Level 1 XML [DOM Level 1] modules */
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'XML', '3.0', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'XML') AND (version = '3.0') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'XML', '2.0', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'XML') AND (version = '2.0') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'XML', '1.0', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'XML') AND (version = '1.0') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'XML', '', 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'XML') AND (version = '') AND (implementationName LIKE 'marpaXml'))); "
    "INSERT INTO DOMImplementation (feature, version, implementationName) SELECT 'XML', NULL, 'marpaXml' WHERE NOT EXISTS (SELECT 1 FROM DOMImplementation WHERE ((feature LIKE 'XML') AND (version IS NULL) AND (implementationName LIKE 'marpaXml'))); "
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
static C_INLINE marpaXml_boolean_t _marpaXml_total_changes(void);
static C_INLINE marpaXml_boolean_t _marpaXml_reset(sqlite3_stmt *stmtp);
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(const char *sqls, sqlite3_stmt **stmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_blob(sqlite3_stmt* stmtp, int pos, const void *p, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* stmtp, int pos, const char *txt, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text16(sqlite3_stmt* stmtp, int pos, const void *txt16, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_string(sqlite3_stmt* stmtp, int pos, marpaXml_String_t *stringp, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* stmtp, int pos, int val, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* stmtp, int pos, sqlite3_int64 val, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_ptr(sqlite3_stmt* stmtp, int pos, void *ptr, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_bind_null(sqlite3_stmt* stmtp, int pos, size_t bufferByteLengthl);
static C_INLINE marpaXml_boolean_t _marpaXml_step(sqlite3_stmt* stmtp);
static C_INLINE void               _marpaXml_xxhash_xFunc(sqlite3_context *pCtx, int nArg, sqlite3_value **apArg);
static C_INLINE void               _marpaXml_xxhash_xDestroy(void *p);
static C_INLINE marpaXml_boolean_t _marpaXml_getStmt(void *objp, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE void               _marpaXml_freeStmt(void *obj, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE void               _marpaXml_freeDynamicCachedStmt(void *obj, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_generateStmt(void *objp, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp);
static C_INLINE marpaXml_boolean_t _marpaXml_featuresWhereClause(_marpaXml_stmt_e stmte, marpaXml_String_t *requestp, char **wheresp);
static C_INLINE marpaXml_boolean_t _marpaXml_qualifiedNameToPrefixAndLocalName(marpaXml_String_t *qualifiedNamep, marpaXml_String_t **prefixpp, marpaXml_String_t **localNamepp, marpaXml_DOMException_t **exceptionpp);

/*******************************************************************/
/* _marpaXml_DOMErrorLogCallback                                          */
/*******************************************************************/
static C_INLINE void _marpaXml_DOMErrorLogCallback(void *pArg, int iErrCode, const char *zMsg) {
  /* Not thread-safe but OK: this value can be true only if marpa is initialized, which is done */
  /* in a thread-safe routine, and marpaXmlLogp, when setted, does never interfer with any DB call */
  MARPAXML_ERRORX("SQLite error code %d: %s", iErrCode, (zMsg != NULL) ? zMsg : "(null)");
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

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_EXEC, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_exec(db, sql, execCallback, p, &errmsg)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_exec(..., %s%s%s, ...): %s", sql != NULL ? "\"" : "",  sql != NULL ? sql : "(null)", sql != NULL ? "\"" : "",  errmsg != NULL ? errmsg : "(null)");
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

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_NEWFUNC, name != NULL ? name : "(null)");
  if ((sqliteRc = sqlite3_create_function_v2(db,
					     name,
					     nArg,
					     eTextRep,
					     pApp,
					     xFunc,
					     xStep,
					     xFinal,
					     xDestroy)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_create_function_v2(..., %s%s%s, ...): %s", name != NULL ? "\"" : "",  name != NULL ? name : "(null)", name != NULL ? "\"" : "",  sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_prepare                                               */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **stmtpp) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_PREPARE, sql != NULL ? sql : "(null)");
  if ((sqliteRc = sqlite3_prepare_v2(db, sql, strlen(sql) + sizeof(char), stmtpp, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_prepare_v2(): %s\n\nSQL sequence was:\n\n%s", sqlite3_errstr(sqliteRc), sql);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_finalize                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_finalize(const char *sqls, sqlite3_stmt **stmtpp) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_FINALIZE, sqls != NULL ? sqls : "(null)");
  if ((sqliteRc = sqlite3_finalize(*stmtpp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_finalize(): %s", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  } else {
    *stmtpp = NULL;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_changes                                               */
/* Our SQL statements that can do changes may change at max 1 row  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_changes(void) {
  int changes;

  changes = sqlite3_changes(_marpaXml_dbp);

  if (changes != 1) {
    MARPAXML_ERRORX("sqlite3_changes(): %d", changes);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_total_changes                                         */
/* This is the grand-total, including triggers. We expect >= 1.    */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_total_changes(void) {
  int total_changes;

  total_changes = sqlite3_total_changes(_marpaXml_dbp);

  if (total_changes <= 0) {
    MARPAXML_ERRORX("sqlite3_total_changes(): %d", total_changes);
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
    MARPAXML_ERRORX("sqlite3_reset(): %s", sqlite3_errstr(sqliteRc));
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_text                                             */
/* If bufferByteLengthl <= 0 it's assumed to be a native C (char*) */
/* ending with a null byte: length is strlen(txt) + sizeof(char)   */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text(sqlite3_stmt* stmtp, int pos, const char *txt, size_t bufferByteLengthl) {
  int sqliteRc;

  if (bufferByteLengthl <= 0 && txt != NULL) {
    bufferByteLengthl = strlen(txt) + sizeof(char);
  }
  /* SQLite uses int */
  if (bufferByteLengthl > INT_MAX) {
    MARPAXML_ERRORX("_marpaXml_bind_text(): bufferByteLengthl (%ld) > INT_MAX (%d) at %s:%d", (long) bufferByteLengthl, (int) INT_MAX);
    return marpaXml_false;
  }

#ifndef MARPAXML_NTRACE
  {
    int                   i = -1;
    char                  trace[_MARPAXML_MAXCHARS_IN_TRACE+1];
    const char           *trace_error = "**Internal Error**";
    char                 *tracep = &(trace[0]);
    marpaXml_boolean_t    truncated = marpaXml_false;
    marpaXml_boolean_t    containsNotPrintable = marpaXml_false;
    streamInOption_t      streamInOption;
    streamInUtf8Option_t  streamInUtf8Option;
    streamInFromBuffer_t *streamInUtf8_bufferp;
    signed int            nexti;

    /* We intentionnally limit the printout of text to _MARPAXML_MAXCHARS_IN_TRACE characters */
    if (txt == NULL) {
      trace[0] = '\0';
    } else {

      if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
	tracep = (char *) trace_error;
      } else {
	streamInOption.marpaXmlLogp = marpaXmlLogp;
	if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
	  tracep = (char *) trace_error;
	} else {
	  streamInUtf8Option.ICUToCallback = STREAMINUTF8OPTION_ICU_ESCAPE_XML;
	  streamInUtf8Option.fromEncodings = (char *) "UTF-8";
	  streamInUtf8_bufferp = streamInUtf8_newFromBufferp(&streamInOption, &streamInUtf8Option, txt, bufferByteLengthl);
	  if (streamInUtf8_bufferp == NULL) {
	    tracep = (char *) trace_error;
	  } else {
	    while ((++i < _MARPAXML_MAXCHARS_IN_TRACE) &&
		   (streamInUtf8_nexti(streamInUtf8_bufferp->streamInp, &nexti) == STREAMIN_BOOL_TRUE)) {   
	      if (u_isprint(nexti) == TRUE) {
		trace[i] = (char) nexti;
	      } else if (nexti == '\0') {
		break;
	      } else {
		trace[i] = ' ';
		containsNotPrintable = marpaXml_true;
	      }
	    }
	    trace[i] = '\0';
	    streamInUtf8_streamInFromBuffer_destroyv(&streamInUtf8_bufferp);
	  }
	}
      }

      if (i == _MARPAXML_MAXCHARS_IN_TRACE && trace[i-1] != '\0') {
	truncated = marpaXml_true;
      }
    }
    MARPAXML_TRACEX("[%s] Pos: %d, Val: %s%s%s%s%s",
		    _MARPAXML_BINDTEXT,
		    pos,
		    txt != NULL ? "\"" : "", txt != NULL ? tracep : "NULL", truncated == marpaXml_true ? "<truncated>" : "", txt != NULL ? "\"" : "",
		    (containsNotPrintable == marpaXml_true) ? " (contains not printable chars, replaced by space)" : "");
  }
#endif

  if ((sqliteRc = sqlite3_bind_text(stmtp, pos, txt, (int) bufferByteLengthl, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_blob                                             */
/* If ps is NULL it is a NULL blob                                 */
/* If bufferByteLengthl <= 0 it's assumed to be NULL blob          */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_blob(sqlite3_stmt* stmtp, int pos, const void *p, size_t bufferByteLengthl) {
  int sqliteRc;

  /* SQLite uses int */
  if (bufferByteLengthl > INT_MAX) {
    MARPAXML_ERRORX("_marpaXml_bind_blob(): bufferByteLengthl (%ld) > INT_MAX (%d) at %s:%d", (long) bufferByteLengthl, (int) INT_MAX);
    return marpaXml_false;
  }

  if ((sqliteRc = sqlite3_bind_blob(stmtp, pos, p, (int) bufferByteLengthl, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_blob(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_text16                                           */
/* If bufferByteLengthl <= 0 it's assumed to be a NUL ended thing  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_text16(sqlite3_stmt* stmtp, int pos, const void *txt16, size_t bufferByteLengthl) {
  int sqliteRc;

  if (bufferByteLengthl <= 0) {
    bufferByteLengthl = u_strlen((const UChar *) txt16) + sizeof(UChar);
  }
  /* SQLite uses int */
  if (bufferByteLengthl > INT_MAX) {
    MARPAXML_ERRORX("_marpaXml_bind_text16(): bufferByteLengthl (%ld) > INT_MAX (%d) at %s:%d", (long) bufferByteLengthl, (int) INT_MAX);
    return marpaXml_false;
  }
#ifndef MARPAXML_NTRACE
  {
    int                   i = -1;
    char                  trace[_MARPAXML_MAXCHARS_IN_TRACE+1];
    const char           *trace_error = "**Internal Error**";
    char                 *tracep = &(trace[0]);
    marpaXml_boolean_t    truncated = marpaXml_false;
    marpaXml_boolean_t    containsNotPrintable = marpaXml_false;
    streamInOption_t      streamInOption;
    streamInUtf8Option_t  streamInUtf8Option;
    streamInFromBuffer_t *streamInUtf8_bufferp;
    signed int            nexti;

    /* We intentionnally limit the printout of text to _MARPAXML_MAXCHARS_IN_TRACE characters */
    if (txt16 == NULL) {
      trace[0] = '\0';
    } else {

      if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
	tracep = (char *) trace_error;
      } else {
	streamInOption.marpaXmlLogp = marpaXmlLogp;
	if (streamInUtf8_optionDefaultb(&streamInUtf8Option) == STREAMIN_BOOL_FALSE) {
	  tracep = (char *) trace_error;
	} else {
	  streamInUtf8Option.ICUToCallback = STREAMINUTF8OPTION_ICU_ESCAPE_XML;
	  streamInUtf8Option.fromEncodings = _marpaXml_UTF16_Encodings;
	  streamInUtf8_bufferp = streamInUtf8_newFromBufferp(&streamInOption, &streamInUtf8Option, txt16, bufferByteLengthl);
	  if (streamInUtf8_bufferp == NULL) {
	    tracep = (char *) trace_error;
	  } else {
	    while ((++i < _MARPAXML_MAXCHARS_IN_TRACE) &&
		   (streamInUtf8_nexti(streamInUtf8_bufferp->streamInp, &nexti) == STREAMIN_BOOL_TRUE)) {
	      if (u_isprint(nexti) == TRUE) {
		trace[i] = (char) nexti;
	      } else if (nexti == '\0') {
		break;
	      } else {
		trace[i] = ' ';
		containsNotPrintable = marpaXml_true;
	      }
	    }
	    trace[i] = '\0';
	    streamInUtf8_streamInFromBuffer_destroyv(&streamInUtf8_bufferp);
	  }
	}
      }

      if (i == _MARPAXML_MAXCHARS_IN_TRACE && trace[i-1] != '\0') {
	truncated = marpaXml_true;
      }
    }
    MARPAXML_TRACEX("[%s] Pos: %d, Val: %s%s%s%s%s",
		    _MARPAXML_BINDTEXT,
		    pos,
		    txt16 != NULL ? "\"" : "", txt16 != NULL ? tracep : "NULL", truncated == marpaXml_true ? "<truncated>" : "", txt16 != NULL ? "\"" : "",
		    (containsNotPrintable == marpaXml_true) ? " (contains not printable chars, replaced by space)" : "");
  }
#endif

  if ((sqliteRc = sqlite3_bind_text16(stmtp, pos, txt16, (int) bufferByteLengthl, SQLITE_STATIC)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_text16(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_string                                           */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_string(sqlite3_stmt* stmtp, int pos, marpaXml_String_t *stringp, size_t notUsedl) {
  return (stringp != NULL) ? _marpaXml_bind_text(stmtp, pos, marpaXml_String_getUtf8(stringp), marpaXml_String_getUtf8ByteLength(stringp)) : _marpaXml_bind_null(stmtp, pos, notUsedl);
}

/*******************************************************************/
/* _marpaXml_bind_int                                              */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int(sqlite3_stmt* stmtp, int pos, int val, size_t notUsedl) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %d", _MARPAXML_BINDINT, pos, val);

  if ((sqliteRc = sqlite3_bind_int(stmtp, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_int64                                            */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_int64(sqlite3_stmt* stmtp, int pos, sqlite3_int64 val, size_t notUsedl) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %lld", _MARPAXML_BINDINT64, pos, val);

  if ((sqliteRc = sqlite3_bind_int64(stmtp, pos, val)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_int64(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/*******************************************************************/
/* sqlite3_column_ptr                                              */
/* Because SQLite does not natively support unsigned int64, we     */
/* ASSUME that this column is bound to a TEXT, containing the      */
/* the result of a sprintf("%p").                                  */
/*******************************************************************/
static C_INLINE void *sqlite3_column_ptr(sqlite3_stmt *stmtp, int iCol) {
  const unsigned char *ptrs;
  void *ptr;

  ptrs = sqlite3_column_text(stmtp, iCol);
  if (ptrs == NULL) {
    /* We expect a string, even containing zero, but really a string, not NULL */
    MARPAXML_ERRORX("sqlite3_column_text(): NULL at %s:%d", __FILE__, __LINE__);
    return NULL;
  }

  if (sscanf((const char *) ptrs, "%p", &ptr) != 1) {
    MARPAXML_ERRORX("sscanf(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return NULL;
  }
  return ptr;
}

/*******************************************************************/
/* _marpaXml_bind_ptr                                              */
/* Because SQLite does not natively support unsigned int64, we     */
/* ASSUME that this column is bound to a TEXT, containing the      */
/* the result of a sprintf("%p").                                  */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_ptr(sqlite3_stmt* stmtp, int pos, void *ptr, size_t notUsedl) {
  char *ptrs;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: %p", _MARPAXML_BINDINT64, pos, ptr);

  if ((ptrs = messageBuilder("%p", ptr)) == messageBuilder_internalErrors()) {
    return marpaXml_false;
  }

  /* We let _marpaXml_bind_text determine the byte length. Ok, because this is a native C char per def */
  if (_marpaXml_bind_text(stmtp, pos, ptrs, 0) == marpaXml_false) {
    free(ptrs);
    return marpaXml_false;
  }

  free(ptrs);
  return marpaXml_true;
}

/*******************************************************************/
/* _marpaXml_bind_null                                             */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_bind_null(sqlite3_stmt* stmtp, int pos, size_t notUsedl) {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] Pos: %d, Val: NULL", _MARPAXML_BINDINT64, pos);

  if ((sqliteRc = sqlite3_bind_null(stmtp, pos)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_bind_null(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_BUSY);
    break;
  case SQLITE_DONE:
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_DONE);
    break;
  case SQLITE_ROW:
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_ROW);
    break;
  case SQLITE_ERROR:
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_ERROR);
    break;
  case SQLITE_MISUSE:
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_MISUSE);
    break;
  case SQLITE_CONSTRAINT:
    MARPAXML_TRACEX("[%s] %s", _MARPAXML_STEP, _MARPAXML_SQLITE_CONSTRAINT);
    break;
  default:
    MARPAXML_TRACEX("[%s] code %d", _MARPAXML_STEP, sqliteRc);
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
  if (_marpaXml_isInitialized == marpaXml_false || _marpaXml_dbp == NULL) {
    return marpaXml_false;
  }

  /* Free the statements */
  for (i = 0; i < __marpaXml_stmt_max_e; i++) {
    if (_marpaXml_stmt[i].stmt != NULL) {
      if (_marpaXml_finalize(_marpaXml_stmt[i].sql, &_marpaXml_stmt[i].stmt) == marpaXml_false) {
	rc = marpaXml_false;
      }
    }
  }

  /* Close connection to the DB - this will call destructors for created functions */
  MARPAXML_TRACE0("Closing database");
  if ((sqliteRc = sqlite3_close_v2(_marpaXml_dbp)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_close_v2(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    rc = marpaXml_false;
  }

  if (qname_1_0p != NULL) {
    MARPAXML_TRACE0("Destroying qname XML 1.0 grammar");
    qname_1_0_destroyv(&qname_1_0p);
  }

  MARPAXML_TRACE0("Shutting down SQLite");

  if ((sqliteRc = sqlite3_shutdown()) != SQLITE_OK) {
    /* MARPAXML_ERRORX("sqlite3_shutdown(): %s at %s:%d", sqlite3_errstr(sqliteRc), __FILE__, __LINE__); */
    rc = marpaXml_false;
  }

#ifdef MARPAXML_DOM_TEST_APPLICATION_ONLY
  /* ICU recommendation is to NOT call this. This is done automatically at library unload */
  u_cleanup();
#endif

  /* Pretend we were not _marpaXml_isInitialized */
  _marpaXml_isInitialized = marpaXml_false;

  return rc;
}

/*******************************************************************/
/*                                                                 */
/*               Transaction Management                            */
/*                                                                 */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Begin() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_BeginImmediate_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_End() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_End_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_End_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_End_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    return marpaXml_false;
  }

  return marpaXml_true;
}

/* --------------------------------------------------------------- */

static C_INLINE marpaXml_boolean_t _marpaXml_Transaction_Rollback() {
  int sqliteRc;

  MARPAXML_TRACEX("[%s] %s", _MARPAXML_SQL, _marpaXml_stmt[_marpaXml_Transaction_Rollback_e].sql);

  do {
  } while ((sqliteRc = _marpaXml_step(_marpaXml_stmt[_marpaXml_Transaction_Rollback_e].stmt)) == SQLITE_ROW);

  /* Always reset */
  if (_marpaXml_reset(_marpaXml_stmt[_marpaXml_Transaction_Rollback_e].stmt) == marpaXml_false) {
    return marpaXml_false;
  }

  /* Check what step returned */
  if (sqliteRc != SQLITE_DONE) {
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         DOMException,                              /* class */
                         new,                                       /* method */
                         short code MARPAXML_ARG(marpaXml_String_t *messagep),    /* decl */
                         code MARPAXML_ARG(messagep),               /* args */
			 ,                                          /* extraInit */
                          /* bindingResult */
                         (_marpaXml_bind_int   (sqliteStmtp, 1, code,     _MARPAXML_ARGNOTUSED) == marpaXml_true &&
			  _marpaXml_bind_string(sqliteStmtp, 2, messagep, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false,
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_getCode                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(,                                          /* staticStorage */
                         unsigned short,                            /* rcType */
                         DOMException,                              /* class */
                         getCode,                                   /* method */
                         int,                                       /* dbType */
                         int,                                       /* dbMapType */
                         (unsigned short) rcDb                      /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_setCode                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(,                                          /* staticStorage */
                         unsigned short,                            /* rcType */
                         DOMException,                              /* class */
                         setCode,                                   /* method */
                         int,                                       /* dbType */
                         code,                                      /* var */
                         code                                       /* var2VarDb */
			 )


/* --------------------------------------------------------------- */
/* marpaXml_DOMException_getMessage                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(,                                          /* staticStorage */
                         marpaXml_String_t *,                       /* rcType */
                         DOMException,                              /* class */
                         getMessage,                                /* method */
                         text,                                      /* dbType */
                         const unsigned char *,                     /* dbMapType */
                         (rcDb != NULL) ? marpaXml_String_newFromUTF8((char *)rcDb, &_marpaXml_String_globalOption) : NULL /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMException_setMessage                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(,                                          /* staticStorage */
                         marpaXml_String_t *,                       /* rcType */
                         DOMException,                              /* class */
                         setMessage,                                /* method */
                         text,                                      /* dbType */
                         messagep,                                  /* var */
                         (messagep != NULL) ? marpaXml_String_getUtf8(messagep) : NULL          /* var2VarDb */
			 )


/* --------------------------------------------------------------- */
/* marpaXml_DOMException_free                                      */
/* Note: the lifetime of a DOMException in the DB is the object    */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMException,                             /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                          DOMError                               */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMError_new                                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         DOMError,                                  /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMError_getSeverity                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_GET_API(,                                          /* staticStorage */
                         unsigned short,                            /* rcType */
                         DOMError,                                  /* class */
                         getSeverity,                               /* method */
                         int,                                       /* dbType */
                         int,                                       /* dbMapType */
                         rcDb                                       /* rcDb2Rc */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMError_setSeverity                                   */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_SET_API(,                                          /* staticStorage */
                         unsigned short,                            /* rcType */
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
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMError,                                 /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                         DOMObjects                              */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMObjects_new                                         */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(static C_INLINE,                           /* staticStorage */
                         DOMObjects,                                /* class */
                         new,                                       /* method */
                         char *objectName,                          /* decl */
                         objectName,                                /* args */
			 ,                                          /* extraInit */
                         (_marpaXml_bind_text(sqliteStmtp, 1, objectName, 0) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMObjects_free                                        */
/* The lifetime of a DOMObject in the DB is the object             */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(static C_INLINE,                          /* staticStorage */
                          DOMObjects,                               /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                       DOMStringList                             */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_new                                      */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         DOMStringList,                             /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 /* extraInit */
			 {
                           int i = DOMStringListCachedStmt.new_e;

			   rcp->DOMObjectsp = NULL;

                           while (++i < DOMStringListCachedStmt.free_e) {
                             rcp->cachedUntilFreeStmt[i] = NULL;
                             rcp->cachedUntilFreeSqls[i] = NULL;
                           }
			 },
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_item                                     */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMStringList,                          /* class */
                            item,                                   /* method */
                            marpaXml_DOMStringList_t *thisp MARPAXML_ARG(unsigned long index) MARPAXML_ARG(marpaXml_String_t **rcp), /* decl */
                            thisp MARPAXML_ARG(index) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_int64(sqliteStmtp, 1, (sqlite3_int64) index, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
                            {
			      marpaXml_String_t *itemp;
			      if (rcDb != NULL) {
				if ((itemp = marpaXml_String_newFromUTF8((char *)rcDb, &_marpaXml_String_globalOption)) == NULL) {
				  goto end;
				}
				*rcp = itemp;
			      }
			    },                                      /* rcDb2Rc */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_getLength                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMStringList,                          /* class */
                            getLength,                              /* method */
                            marpaXml_DOMStringList_t *thisp MARPAXML_ARG(unsigned long *rcp), /* decl */
                            thisp MARPAXML_ARG(rcp),                /* args */
			    ,                                       /* prolog */
                            marpaXml_true,                          /* bindingResult */
                            int64,                                  /* dbType */
                            sqlite3_int64,                          /* dbMapType */
                            {*rcp = (unsigned long) rcDb;},         /* rcDb2rc */
                            {*rcp = 0;},                            /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_contains                                 */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMStringList,                          /* class */
                            contains,                               /* method */
                            marpaXml_DOMStringList_t *thisp MARPAXML_ARG(marpaXml_String_t *strp) MARPAXML_ARG(marpaXml_boolean_t *rcp), /* decl */
                            thisp MARPAXML_ARG(strp) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_string(sqliteStmtp, 1, strp, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int,                                    /* dbType */
                            int,                                    /* dbMapType */
                            {*rcp = rcDb;},                         /* rcDb2rc */
                            {*rcp = marpaXml_false;},               /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMStringList_free                                     */
/* The lifetime of a DOMStringList in the DB is the object         */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMStringList,                            /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                          NameList                               */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_NameList_new                                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         NameList,                                  /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 /* extraInit */
			 {
                           int i = NameListCachedStmt.new_e;

			   rcp->DOMObjectsp = NULL;

                           while (++i < NameListCachedStmt.free_e) {
                             rcp->cachedUntilFreeStmt[i] = NULL;
                             rcp->cachedUntilFreeSqls[i] = NULL;
                           }
			 },
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_getName                                       */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            NameList,                               /* class */
                            getName,                                /* method */
                            marpaXml_NameList_t *thisp MARPAXML_ARG(unsigned long index) MARPAXML_ARG(marpaXml_String_t **rcp), /* decl */
                            thisp MARPAXML_ARG(index) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_int64(sqliteStmtp, 1, (sqlite3_int64) index, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
                            {
			      marpaXml_String_t *itemp;
			      if (rcDb != NULL) {
				if ((itemp = marpaXml_String_newFromUTF8((char *)rcDb, &_marpaXml_String_globalOption)) == NULL) {
				  goto end;
				}
				*rcp = itemp;
			      }
			    },                                      /* rcDb2Rc */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_getNamespaceURI                               */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            NameList,                               /* class */
                            getNamespaceURI,                        /* method */
                            marpaXml_NameList_t *thisp MARPAXML_ARG(unsigned long index) MARPAXML_ARG(marpaXml_String_t **rcp), /* decl */
                            thisp MARPAXML_ARG(index) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_int64(sqliteStmtp, 1, (sqlite3_int64) index, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
                            {
			      marpaXml_String_t *itemp;
			      if (rcDb != NULL) {
				if ((itemp = marpaXml_String_newFromUTF8((char *)rcDb, &_marpaXml_String_globalOption)) == NULL) {
				  goto end;
				}
				*rcp = itemp;
			      }
			    },                                      /* rcDb2Rc */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_getLength                                     */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            NameList,                               /* class */
                            getLength,                              /* method */
                            marpaXml_NameList_t *thisp MARPAXML_ARG(unsigned long *rcp), /* decl */
                            thisp MARPAXML_ARG(rcp),                /* args */
			    ,                                       /* prolog */
                            marpaXml_true,                          /* bindingResult */
                            int64,                                  /* dbType */
                            sqlite3_int64,                          /* dbMapType */
                            {*rcp = (unsigned long) rcDb;},         /* rcDb2rc */
                            {*rcp = 0;},                            /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_contains                                      */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            NameList,                               /* class */
                            contains,                               /* method */
                            marpaXml_NameList_t *thisp MARPAXML_ARG(marpaXml_String_t *strp) MARPAXML_ARG(marpaXml_boolean_t *rcp), /* decl */
                            thisp MARPAXML_ARG(strp) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_string(sqliteStmtp, 1, strp, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int,                                    /* dbType */
                            int,                                    /* dbMapType */
                            {*rcp = rcDb;},                         /* rcDb2rc */
                            {*rcp = marpaXml_false;},               /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_containsNS                                    */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            NameList,                               /* class */
                            containsNS,                             /* method */
                            marpaXml_NameList_t *thisp MARPAXML_ARG(marpaXml_String_t *namespaceURIp) MARPAXML_ARG(marpaXml_String_t *namep) MARPAXML_ARG(marpaXml_boolean_t *rcp), /* decl */
                            thisp MARPAXML_ARG(namespaceURIp) MARPAXML_ARG(namep) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            ((_marpaXml_bind_string(sqliteStmtp, 1, namespaceURIp, _MARPAXML_ARGNOTUSED) == marpaXml_true) &&
                             (_marpaXml_bind_string(sqliteStmtp, 2, namep        , _MARPAXML_ARGNOTUSED) == marpaXml_true)) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int,                                    /* dbType */
                            int,                                    /* dbMapType */
                            {*rcp = rcDb;},                         /* rcDb2rc */
                            {*rcp = marpaXml_false;},               /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_NameList_free                                          */
/* The lifetime of a NameList in the DB is the object              */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          NameList,                                 /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                       DOMImplementationList                     */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationList_new                              */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(static C_INLINE,                           /* staticStorage */
                         DOMImplementationList,                     /* class */
                         new,                                       /* method */
                         const char *wheres,                        /* decl */
                         wheres,                                    /* args */
			 /* extraInit */
			 {
                           int i = DOMImplementationListCachedStmt.new_e;

			   rcp->DOMObjectsp = NULL;
			   rcp->wheres = wheres;

                           while (++i < DOMImplementationListCachedStmt.free_e) {
                             rcp->cachedUntilFreeStmt[i] = NULL;
                             rcp->cachedUntilFreeSqls[i] = NULL;
                           }
			 },
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationList_item                             */
/* --------------------------------------------------------------- */
static C_INLINE marpaXml_boolean_t _marpaXml_DOMImplementation_newFromImplementationName(marpaXml_String_t *implementationNamep, marpaXml_DOMImplementation_t **rcp);
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementationList,                  /* class */
                            item,                                   /* method */
                            marpaXml_DOMImplementationList_t *thisp MARPAXML_ARG(unsigned long index) MARPAXML_ARG(marpaXml_DOMImplementation_t **rcp), /* decl */
                            thisp MARPAXML_ARG(index) MARPAXML_ARG(rcp), /* args */
			    ,                                       /* prolog */
                            (_marpaXml_bind_int64(sqliteStmtp, 1, (sqlite3_int64) index, _MARPAXML_ARGNOTUSED) == marpaXml_true) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
                            {
			      marpaXml_String_t *implementationNamep;
			      marpaXml_DOMImplementation_t *DOMImplementationp;
			      if (rcDb != NULL) {
				if ((implementationNamep = marpaXml_String_newFromUTF8((char *)rcDb, &_marpaXml_String_globalOption)) == NULL) {
				  goto end;
				}
				if (_marpaXml_DOMImplementation_newFromImplementationName(implementationNamep, &DOMImplementationp) == marpaXml_false) {
				  marpaXml_String_free(&implementationNamep);
				  goto end;
				}
				*rcp = DOMImplementationp;
				marpaXml_String_free(&implementationNamep);
			      }
			    },                                      /* rcDb2Rc */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationList_getLength                        */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementationList,                  /* class */
                            getLength,                              /* method */
                            marpaXml_DOMImplementationList_t *thisp MARPAXML_ARG(unsigned long *rcp), /* decl */
                            thisp MARPAXML_ARG(rcp),                /* args */
			    ,                                       /* prolog */
                            marpaXml_true,                          /* bindingResult */
                            int64,                                  /* dbType */
                            sqlite3_int64,                          /* dbMapType */
                            {*rcp = (unsigned long) rcDb;},         /* rcDb2rc */
                            {*rcp = 0;},                            /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationList_free                             */
/* The lifetime of a NameList in the DB is the object              */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMImplementationList,                    /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                                                                    /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                      DOMImplementationSource                    */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationSource_new                            */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         DOMImplementationSource,                   /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationSource_getDOMImplementation           */
/* --------------------------------------------------------------- */
static C_INLINE marpaXml_boolean_t _marpaXml_DOMImplementation_newFromImplementationName(marpaXml_String_t *implementationNamep, marpaXml_DOMImplementation_t **rcp);
static C_INLINE marpaXml_boolean_t _marpaXml_DOMImplementation_free(marpaXml_DOMImplementation_t **thispp);
typedef struct _marpaXml_DOMImplementationSource_getDOMImplementation_callback {
  unsigned short *nbRowsp;
  marpaXml_String_t *implementationNamep;
} _marpaXml_DOMImplementationSource_getDOMImplementation_callback_t;
static C_INLINE int                _marpaXml_DOMImplementationSource_getDOMImplementation_callback(void *datap, int nbColumnsi, char **stringsp, char **columnNamesp) {
  const char *fcts = "_marpaXml_DOMImplementationSource_getDOMImplementation_callback";
  _marpaXml_DOMImplementationSource_getDOMImplementation_callback_t *_marpaXml_DOMImplementationSource_getDOMImplementation_callbackp = (_marpaXml_DOMImplementationSource_getDOMImplementation_callback_t *) datap;
  int rc = 0;

  if (nbColumnsi != 1) {
    MARPAXML_ERRORX("[%s] Too many columns: %d", fcts, nbColumnsi);
    rc = 1;
  } else {
    MARPAXML_TRACEX("[%s] Got column \"%s\"", fcts, columnNamesp[0]);
    if (++(*(_marpaXml_DOMImplementationSource_getDOMImplementation_callbackp->nbRowsp)) > 1) {
      rc = 1;
    } else {
      _marpaXml_DOMImplementationSource_getDOMImplementation_callbackp->implementationNamep = marpaXml_String_newFromUTF8(stringsp[0], &_marpaXml_String_globalOption);
      if (_marpaXml_DOMImplementationSource_getDOMImplementation_callbackp->implementationNamep == NULL) {
	rc = 1;
      }
    }
  }

  return rc;
}

MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementationSource,                /* class */
                            getDOMImplementation,                   /* method */
                            marpaXml_DOMImplementationSource_t *thisp MARPAXML_ARG(marpaXml_String_t *featuresp) MARPAXML_ARG(marpaXml_DOMImplementation_t **rcp), /* decl */
                            thisp MARPAXML_ARG(featuresp) MARPAXML_ARG(rcp),   /* args */

			    char *execStatement = NULL;
			    _marpaXml_DOMImplementationSource_getDOMImplementation_callback_t data;
			    data.nbRowsp = &nbRows;
			    data.implementationNamep = NULL;
			    {
			      if (_marpaXml_featuresWhereClause(stmte, featuresp, &(execStatement)) == marpaXml_false) {
				goto end;
			      }
			    }, /* prolog */

                            _marpaXml_exec(_marpaXml_dbp, execStatement, &_marpaXml_DOMImplementationSource_getDOMImplementation_callback, &data) == marpaXml_true, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
			    {
			      rcDb = rcDb;                 /* No op */
			    },                         /* rcDb2rc */
			    {
			      *rcp = NULL;
			    },                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
			    {
			      if (rcb == marpaXml_true) {
				marpaXml_DOMImplementation_t *DOMImplementationp;
				if (_marpaXml_DOMImplementation_newFromImplementationName(data.implementationNamep, &DOMImplementationp) == marpaXml_false) {
				  rcb = marpaXml_false;
				} else {
				  *rcp = DOMImplementationp;
				}
			      }
			      if (data.implementationNamep != NULL) {
				marpaXml_String_free(&(data.implementationNamep));
			      }
			      if (execStatement != NULL) {
				free(execStatement);
			      }
			    }                                        /* epilog */
			    )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationSource_getDOMImplementationList       */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementationSource,                /* class */
                            getDOMImplementationList,               /* method */
                            marpaXml_DOMImplementationSource_t *thisp MARPAXML_ARG(marpaXml_String_t *featuresp) MARPAXML_ARG(marpaXml_DOMImplementationList_t **rcp), /* decl */
                            thisp MARPAXML_ARG(featuresp) MARPAXML_ARG(rcp),   /* args */

			    char *whereStatement = NULL;
			    {
			      if (_marpaXml_featuresWhereClause(stmte, featuresp, &(whereStatement)) == marpaXml_false) {
				goto end;
			      } else {
				thisp->wheresp = whereStatement;
			      }
			    }, /* prolog */

                            _marpaXml_exec(_marpaXml_dbp, whereStatement, NULL, NULL) == marpaXml_true, /* bindingResult */
                            text,                                   /* dbType */
                            const unsigned char *,                  /* dbMapType */
			    {
			      rcDb = rcDb;                 /* No op */
			    },                         /* rcDb2rc */
			    {
			      *rcp = NULL;
			    },                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
			    {
			      if (rcb == marpaXml_true) {
				marpaXml_DOMImplementationList_t *DOMImplementationListp = _marpaXml_DOMImplementationList_new(whereStatement);
				if (DOMImplementationListp == NULL) {
				  rcb = marpaXml_false;
				} else {
				  *rcp = DOMImplementationListp;
				}
			      }
			      if (whereStatement != NULL) {
				free(whereStatement);
			      }
			    }                                        /* epilog */
			    )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementationSource_free                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMImplementationSource,                  /* class */
                          free,                                     /* method */
                          marpaXml_false,                           /* impactOnDb */
                                                                    /* prolog */
			  )


/*******************************************************************/
/*                                                                 */
/*                      DOMImplementation                          */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_new                                  */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(static C_INLINE,                           /* staticStorage */
                         DOMImplementation,                         /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_newFromImplementationName            */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(static C_INLINE,                         /* staticStorage */
                            DOMImplementation,                       /* class */
                            newFromImplementationName,               /* method */
                            marpaXml_String_t *implementationNamep MARPAXML_ARG(marpaXml_DOMImplementation_t **rcp), /* decl */
                            implementationNamep MARPAXML_ARG(rcp),   /* args */
			    marpaXml_DOMImplementation_t *thisp = _marpaXml_DOMImplementation_new();
			    {
			      if (thisp == NULL) {
				return marpaXml_false;
			      }
			    },   /* prolog */
                            _marpaXml_bind_string(sqliteStmtp, 1, implementationNamep, _MARPAXML_ARGNOTUSED), /* bindingResult */
                            int64,                                   /* dbType */
                            sqlite3_int64,                           /* dbMapType */
			    {
			      thisp->id = rcDb;
			    },                         /* rcDb2rc */
                            {*rcp = thisp;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
			    {
			      if (rcb == marpaXml_false) {
				if (thisp != NULL) {
				  _marpaXml_DOMImplementation_free(&thisp);
				}
			      }
			    }                                        /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_newFromFeatureAndVersion             */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(static C_INLINE,                        /* staticStorage */
                            DOMImplementation,                      /* class */
                            newFromFeatureAndVersion,               /* method */
                            marpaXml_String_t *featurep MARPAXML_ARG(marpaXml_String_t *versionp) MARPAXML_ARG(marpaXml_DOMImplementation_t **rcp), /* decl */
                            featurep MARPAXML_ARG(versionp) MARPAXML_ARG(rcp),   /* args */
			    marpaXml_DOMImplementation_t *thisp = _marpaXml_DOMImplementation_new();
			    {
			      if (thisp == NULL) {
				return marpaXml_false;
			      }
			    },   /* prolog */
                            ((_marpaXml_bind_string(sqliteStmtp, 1, featurep, _MARPAXML_ARGNOTUSED) == marpaXml_true) &&
			     (_marpaXml_bind_string(sqliteStmtp, 2, versionp, _MARPAXML_ARGNOTUSED) == marpaXml_true)) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int64,                                   /* dbType */
                            sqlite3_int64,                           /* dbMapType */
			    {
			      thisp->id = rcDb;
			    },                         /* rcDb2rc */
                            {*rcp = thisp;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
			    {
			      if (rcb == marpaXml_false) {
				if (thisp != NULL) {
				  _marpaXml_DOMImplementation_free(&thisp);
				}
			      }
			    }                                        /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_hasFeature                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementation,                      /* class */
                            hasFeature,                             /* method */
                            marpaXml_DOMImplementation_t *thisp MARPAXML_ARG(marpaXml_String_t *featurep) MARPAXML_ARG(marpaXml_String_t *versionp) MARPAXML_ARG(marpaXml_boolean_t *rcp), /* decl */
                            thisp MARPAXML_ARG(featurep) MARPAXML_ARG(versionp) MARPAXML_ARG(rcp),                /* args */
			    ,                                       /* prolog */
                            ((_marpaXml_bind_int64(sqliteStmtp,  1, thisp->id, _MARPAXML_ARGNOTUSED) == marpaXml_true) &&
			     (_marpaXml_bind_string(sqliteStmtp, 2, featurep , _MARPAXML_ARGNOTUSED) == marpaXml_true) &&
                             (_marpaXml_bind_string(sqliteStmtp, 3, versionp , _MARPAXML_ARGNOTUSED) == marpaXml_true)) ? marpaXml_true : marpaXml_false, /* bindingResult */
                            int,                                  /* dbType */
                            int,                                  /* dbMapType */
                            {*rcp = (rcDb != 0) ? marpaXml_true : marpaXml_false;},         /* rcDb2rc */
                            {*rcp = marpaXml_false;},               /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )


/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_createDocumentType                   */
/* --------------------------------------------------------------- */
/* TO DO */

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_createDocument                       */
/* --------------------------------------------------------------- */
/* TO DO */

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_getFeature                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            DOMImplementation,                      /* class */
                            getFeature,                             /* method */
                            marpaXml_DOMImplementation_t *thisp MARPAXML_ARG(marpaXml_String_t *featurep) MARPAXML_ARG(marpaXml_String_t *versionp) MARPAXML_ARG(marpaXml_DOMObject_t **rcp), /* decl */
                            thisp MARPAXML_ARG(featurep) MARPAXML_ARG(versionp) MARPAXML_ARG(rcp),                /* args */
			    marpaXml_boolean_t hasFeatureb = marpaXml_false;,         /* prolog */
                            marpaXml_true,                          /* bindingResult */
                            int,                                    /* dbType - No op */
                            int,                                    /* dbMapType - No op */
                            {rcDb = rcDb; *rcp = NULL;},            /* rcDb2rc - No op */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                            {
			      marpaXml_DOMImplementation_t *DOMImplementationp; 
                              if ((_marpaXml_DOMImplementation_hasFeature(thisp, featurep, versionp, &hasFeatureb) == marpaXml_true) &&
                                  (hasFeatureb == marpaXml_true)) {
                                if (_marpaXml_DOMImplementation_newFromFeatureAndVersion(featurep, versionp, &DOMImplementationp) == marpaXml_false) {
                                  return marpaXml_false;
                                }
				*rcp = (marpaXml_DOMObject_t *) DOMImplementationp;
                              }
                            }                                        /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_DOMImplementation_free                                 */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DOMImplementation,                        /* class */
                          free,                                     /* method */
                          marpaXml_false,                           /* impactOnDb */
                                                                    /* prolog */
			  )


/*******************************************************************/
/*                                                                 */
/*                           Node                                  */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_Node_new                                               */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         Node,                                      /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_Node_free                                              */
/* Note: Node deletion does not mean delete from the DB            */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          Node,                                     /* class */
                          free,                                     /* method */
                          marpaXml_false,                           /* impactOnDb */
                                                                    /* prolog */
			  )


/*******************************************************************/
/*                                                                 */
/*                       DocumentType                              */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DocumentType_new                                       */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(static C_INLINE,                           /* staticStorage */
                         DocumentType,                              /* class */
                         new,                                       /* method */
                         marpaXml_String_t *qualifiedNamep MARPAXML_ARG(marpaXml_String_t *publicIdp) MARPAXML_ARG(marpaXml_String_t *systemIdp), /* decl */
                         qualifiedNamep  MARPAXML_ARG(publicIdp)  MARPAXML_ARG(systemIdp),                                                        /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DocumentType_free                                      */
/* Note: DocumentType deletion does not mean delete from the DB    */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          DocumentType,                             /* class */
                          free,                                     /* method */
                          marpaXml_false,                            /* impactOnDb */
                                                                    /* prolog */
			  )


/*******************************************************************/
/*                                                                 */
/*                             Lexeme                              */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_new                                             */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(,                                          /* staticStorage */
                         Lexeme,                                    /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 /* extraInit */
			 {
                           int i = LexemeCachedStmt.new_e;

			   rcp->DOMObjectsp = NULL;

                           while (++i < LexemeCachedStmt.free_e) {
                             rcp->cachedUntilFreeStmt[i] = NULL;
                             rcp->cachedUntilFreeSqls[i] = NULL;
                           }
			 },
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_insertFromUTF16                                 */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            Lexeme,                                 /* class */
                            insertFromUTF16,                        /* method */
                            marpaXml_Lexeme_t *thisp MARPAXML_ARG(void *txt16) MARPAXML_ARG(size_t byteLengthl) MARPAXML_ARG(sqlite3_int64 *rcp), /* decl */
                            thisp MARPAXML_ARG(txt16) MARPAXML_ARG(byteLengthl) MARPAXML_ARG(rcp),   /* args */
			    ,                                       /* prolog */
                            _marpaXml_bind_text16(sqliteStmtp, 1, txt16, byteLengthl), /* bindingResult */
                            int,                                    /* dbType - no op */
                            int,                                    /* dbMapType - no op */
                            {rcDb = rcDb;},                         /* rcDb2rc - no op */
                            ,                                       /* defaultRc */
                            marpaXml_true,                          /* changeId */
                            {
                              if (rcb == marpaXml_true) {
                                *rcp = thisp->id;
                              }
                            }                                       /* epilog */
                            )
/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_insertFromUTF8                                  */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            Lexeme,                                 /* class */
                            insertFromUTF8,                         /* method */
                            marpaXml_Lexeme_t *thisp MARPAXML_ARG(char *txt) MARPAXML_ARG(size_t byteLengthl) MARPAXML_ARG(sqlite3_int64 *rcp), /* decl */
                            thisp MARPAXML_ARG(txt) MARPAXML_ARG(byteLengthl) MARPAXML_ARG(rcp),   /* args */
			    ,                                       /* prolog */
                            _marpaXml_bind_text(sqliteStmtp, 1, txt, byteLengthl), /* bindingResult */
                            int,                                    /* dbType - no op */
                            int,                                    /* dbMapType - no op */
                            {rcDb = rcDb;},                         /* rcDb2rc - no op */
                            ,                                       /* defaultRc */
                            marpaXml_true,                          /* changeId */
                            {
                              if (rcb == marpaXml_true) {
                                *rcp = thisp->id;
                              }
                            }                                       /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_insertFromString                                */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            Lexeme,                                 /* class */
                            insertFromString,                       /* method */
                            marpaXml_Lexeme_t *thisp MARPAXML_ARG(marpaXml_String_t *stringp) MARPAXML_ARG(sqlite3_int64 *rcp), /* decl */
                            thisp MARPAXML_ARG(stringp) MARPAXML_ARG(rcp),   /* args */
			    ,                                       /* prolog */
                            _marpaXml_bind_string(sqliteStmtp, 1, stringp, _MARPAXML_ARGNOTUSED), /* bindingResult */
                            int,                                    /* dbType - no op */
                            int,                                    /* dbMapType - no op */
                            {rcDb = rcDb;},                         /* rcDb2rc - no op */
                            ,                                       /* defaultRc */
                            marpaXml_true,                          /* changeId */
                            {
                              if (rcb == marpaXml_true) {
                                *rcp = thisp->id;
                              }
                            }                                       /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_getString                                       */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            Lexeme,                                 /* class */
                            getString,                             /* method */
                            marpaXml_Lexeme_t *thisp MARPAXML_ARG(sqlite3_int64 idl) MARPAXML_ARG(marpaXml_String_t **rcp), /* decl */
                            thisp MARPAXML_ARG(idl) MARPAXML_ARG(rcp),   /* args */
			    {id = 0;},                             /* prolog - just to avoid a warning */
                            _marpaXml_bind_int64(sqliteStmtp, 1, idl, _MARPAXML_ARGNOTUSED), /* bindingResult */
                            text16,                                 /* dbType */
                            const void *,                          /* dbMapType */
                            {
			      marpaXml_String_t *itemp;
			      if (rcDb != NULL) {
                                /* Note that it seems that SQLite guarantees that sqlite3_column_bytes16() does not return a value < 0 */
				if ((itemp = marpaXml_String_newFromAnyAndByteLengthAndCharset((char *)rcDb, sqlite3_column_bytes16(sqliteStmtp, 0), _marpaXml_UTF16_Encodings, &_marpaXml_String_globalOption)) == NULL) {
				  goto end;
				}
				*rcp = itemp;
			      }
			    },                                      /* rcDb2Rc */
                            {*rcp = NULL;},                         /* defaultRc */
                            marpaXml_false,                         /* changeId */
                                                                    /* epilog */
                            )
/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_delete                                          */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_METHOD_API(,                                       /* staticStorage */
                            Lexeme,                                 /* class */
                            delete,                             /* method */
                            marpaXml_Lexeme_t *thisp MARPAXML_ARG(sqlite3_int64 idl) MARPAXML_ARG(sqlite3_int64 *rcp), /* decl */
                            thisp MARPAXML_ARG(idl) MARPAXML_ARG(rcp),   /* args */
			    {id = 0;},                             /* prolog - just to avoid a warning */
                            _marpaXml_bind_int64(sqliteStmtp, 1, idl, _MARPAXML_ARGNOTUSED), /* bindingResult */
                            int,                                   /* dbType - no op */
                            int,                                   /* dbMapType - no op */
                            {rcDb = rcDb;},                        /* rcDb2Rc - no op */
                            ,                                      /* defaultRc - no op */
                            marpaXml_false,                        /* changeId */
                                                                   /* epilog */
                            )

/* --------------------------------------------------------------- */
/* marpaXml_Lexeme_free                                            */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(,                                         /* staticStorage */
                          Lexeme,                                   /* class */
                          free,                                     /* method */
                          marpaXml_true,                            /* impactOnDb */
                          if (thispp != NULL) {
                            (*thispp)->id = 0; /* Prevent int64 binding */
                          }                                         /* prolog */
			  )

/*******************************************************************/
/*                                                                 */
/*                         DOMUtils                                */
/*                                                                 */
/*******************************************************************/
/* --------------------------------------------------------------- */
/* marpaXml_DOMUtils_new                                           */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_NEW_API(static C_INLINE,                           /* staticStorage */
                         DOMUtils,                                  /* class */
                         new,                                       /* method */
                         void,                                      /* decl */
                         ,                                          /* args */
			 ,                                          /* extraInit */
			 marpaXml_true,                             /* bindingResult */
			 marpaXml_false                             /* noStepCheck */
			 )

/* --------------------------------------------------------------- */
/* marpaXml_DOMUtils_free                                          */
/* Note: DOMUtils deletion does not mean delete from the DB        */
/* --------------------------------------------------------------- */
MARPAXML_GENERIC_FREE_API(static C_INLINE,                          /* staticStorage */
                          DOMUtils,                                 /* class */
                          free,                                     /* method */
                          marpaXml_false,                           /* impactOnDb */
                                                                    /* prolog */
			  )


/*******************************************************************/
/* _marpaXml_getStmt                                               */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_getStmt(void *objp, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  if (_marpaXml_stmt[stmte].generatedb == marpaXml_false) {
    *sqlsp = (char *) _marpaXml_stmt[stmte].sql;
    *sqliteStmtpp = _marpaXml_stmt[stmte].stmt;
    return marpaXml_true;
  } else {
    return _marpaXml_generateStmt(objp, stmte, sqlsp, sqliteStmtpp);
  }
}

/*******************************************************************/
/* _marpaXml_freeDynamicCachedStmt                                 */
/*******************************************************************/
static C_INLINE void _marpaXml_freeDynamicCachedStmt(void *obj, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  if ((sqlsp != NULL) && (*sqlsp != NULL) && (sqliteStmtpp != NULL) && (*sqliteStmtpp != NULL)) {
    _marpaXml_finalize(*sqlsp, sqliteStmtpp);
    free(*sqlsp);
    *sqlsp = NULL;
  }
}

/*******************************************************************/
/* _marpaXml_freeStmt                                              */
/*******************************************************************/
static C_INLINE void _marpaXml_freeStmt(void *objp, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  marpaXml_DOMStringList_t             *DOMStringListp;
  marpaXml_NameList_t                  *NameListp;
  marpaXml_DOMImplementationList_t     *DOMImplementationListp;
  marpaXml_Lexeme_t                    *Lexemep;
  sqlite3_stmt                        **cachedUntilFreeStmtp;
  char                                **cachedUntilFreeSqlsp;
  _marpaXml_cachedStmtExclusiveRange_t *cachedStmtp;
  int                                   i;

  if (_marpaXml_stmt[stmte].generatedb == marpaXml_true) {

    if (
	((stmte > _marpaXml_DOMStringList_new_e)         && (stmte < _marpaXml_DOMStringList_free_e)) ||
        ((stmte > _marpaXml_NameList_new_e)              && (stmte < _marpaXml_NameList_free_e)) ||
        ((stmte > _marpaXml_DOMImplementationList_new_e) && (stmte < _marpaXml_DOMImplementationList_free_e)) ||
        ((stmte > _marpaXml_Lexeme_new_e)                && (stmte < _marpaXml_Lexeme_free_e))
	) {
      /* Delayed until free */
    } else {
      switch (stmte) {
      case _marpaXml_DOMStringList_free_e:
        /* Cached dynamic statements */
        DOMStringListp = (marpaXml_DOMStringList_t *) objp;
        cachedStmtp = &DOMStringListCachedStmt;
        cachedUntilFreeStmtp = DOMStringListp->cachedUntilFreeStmt;
        cachedUntilFreeSqlsp = DOMStringListp->cachedUntilFreeSqls;
        break;
      case _marpaXml_NameList_free_e:
        NameListp = (marpaXml_NameList_t *) objp;
        cachedStmtp = &NameListCachedStmt;
        cachedUntilFreeStmtp = NameListp->cachedUntilFreeStmt;
        cachedUntilFreeSqlsp = NameListp->cachedUntilFreeSqls;
        break;
      case _marpaXml_DOMImplementationList_free_e:
        DOMImplementationListp = (marpaXml_DOMImplementationList_t *) objp;
        cachedStmtp = &DOMImplementationListCachedStmt;
        cachedUntilFreeStmtp = DOMImplementationListp->cachedUntilFreeStmt;
        cachedUntilFreeSqlsp = DOMImplementationListp->cachedUntilFreeSqls;
        break;
      case _marpaXml_Lexeme_free_e:
        Lexemep = (marpaXml_Lexeme_t *) objp;
        cachedStmtp = &LexemeCachedStmt;
        cachedUntilFreeStmtp = Lexemep->cachedUntilFreeStmt;
        cachedUntilFreeSqlsp = Lexemep->cachedUntilFreeSqls;
        break;
      default:
        cachedStmtp = NULL;
        break;
      }
      if (cachedStmtp != NULL) {
        i = cachedStmtp->new_e;
        while (++i < cachedStmtp->free_e) {
          _marpaXml_freeDynamicCachedStmt(objp, &(cachedUntilFreeSqlsp[i]), &(cachedUntilFreeStmtp[i]));
        }
      }
      _marpaXml_finalize(*sqlsp, sqliteStmtpp);
      free(*sqlsp);
      *sqlsp = NULL;
    }
  }
}

/*******************************************************************/
/* _marpaXml_generateStmt                                          */
/* Note: it is not a hasard that this method is after all GENERIC  */
/*       stuff: it is using the internal marpaXml_DOMObjects_xxx   */
/*       whose prototypes are defined by the GENERIC macros upper. */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_generateStmt(void *objp, _marpaXml_stmt_e stmte, char **sqlsp, sqlite3_stmt **sqliteStmtpp) {
  marpaXml_boolean_t                    rcb = marpaXml_false;
  char                                 *sqls;
  marpaXml_DOMObjects_t                *DOMObjectsp;
  sqlite3_stmt                         **cachedUntilFreeStmtp;
  char                                 **cachedUntilFreeSqlsp;
  _marpaXml_cachedStmtExclusiveRange_t  *cachedStmtp;
  int                                    i;

  marpaXml_DOMStringList_t              *DOMStringListp;
  marpaXml_NameList_t                   *NameListp;
  marpaXml_DOMImplementationList_t      *DOMImplementationListp;
  marpaXml_Lexeme_t                     *Lexemep;

  switch (stmte) {
  case _marpaXml_DOMStringList_new_e:
  case _marpaXml_NameList_new_e:
  case _marpaXml_DOMImplementationList_new_e:
  case _marpaXml_Lexeme_new_e:

    if (stmte == _marpaXml_DOMStringList_new_e) {
      DOMStringListp = (marpaXml_DOMStringList_t *) objp;
      DOMStringListp->DOMObjectsp = DOMObjectsp = _marpaXml_DOMObjects_new((char *) "DOMStringList");
      cachedStmtp = &DOMStringListCachedStmt;
      cachedUntilFreeStmtp = DOMStringListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = DOMStringListp->cachedUntilFreeSqls;
      sqls = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id);
    } else if (stmte == _marpaXml_NameList_new_e) {
      NameListp = (marpaXml_NameList_t *) objp;
      NameListp->DOMObjectsp = DOMObjectsp = _marpaXml_DOMObjects_new((char *) "NameList");
      cachedStmtp = &NameListCachedStmt;
      cachedUntilFreeStmtp = NameListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = NameListp->cachedUntilFreeSqls;
      sqls = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id);
    } else if (stmte == _marpaXml_DOMImplementationList_new_e) {
      DOMImplementationListp = (marpaXml_DOMImplementationList_t *) objp;
      DOMImplementationListp->DOMObjectsp = DOMObjectsp = _marpaXml_DOMObjects_new((char *) "DOMImplementationList");
      cachedStmtp = &DOMImplementationListCachedStmt;
      cachedUntilFreeStmtp = DOMImplementationListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = DOMImplementationListp->cachedUntilFreeSqls;
      sqls = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id, DOMImplementationListp->wheres);
    } else if (stmte == _marpaXml_Lexeme_new_e) {
      Lexemep = (marpaXml_Lexeme_t *) objp;
      Lexemep->DOMObjectsp = DOMObjectsp = _marpaXml_DOMObjects_new((char *) "Lexeme");
      cachedStmtp = &LexemeCachedStmt;
      cachedUntilFreeStmtp = Lexemep->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = Lexemep->cachedUntilFreeSqls;
      sqls = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id);
    } else {
      /* Simply impossible */
      MARPAXML_ERRORX("_marpaXml_generateStmt internal error, stmt=%d, at %s:%d", stmte, __FILE__, __LINE__);
      break;
    }

    if (DOMObjectsp == NULL) {
      break;
    }

    if (sqls == messageBuilder_internalErrors()) {
      MARPAXML_ERRORX("%s", sqls);
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }
    if (_marpaXml_prepare(_marpaXml_dbp, sqls, sqliteStmtpp) == marpaXml_false) {
      free(sqls);
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }

    i = cachedStmtp->new_e;
    while (++i < cachedStmtp->free_e) {
      cachedUntilFreeStmtp[i] = NULL;
      cachedUntilFreeSqlsp[i] = NULL;
    }
    *sqlsp = sqls;
    rcb = marpaXml_true;

    break;

  case _marpaXml_DOMStringList_free_e:
  case _marpaXml_NameList_free_e:
  case _marpaXml_DOMImplementationList_free_e:
  case _marpaXml_Lexeme_free_e:

    if (stmte == _marpaXml_DOMStringList_free_e) {
      DOMStringListp = (marpaXml_DOMStringList_t *) objp;
      DOMObjectsp = DOMStringListp->DOMObjectsp;
    } else if (stmte == _marpaXml_NameList_free_e) {
      NameListp = (marpaXml_NameList_t *) objp;
      DOMObjectsp = NameListp->DOMObjectsp;
    } else if (stmte == _marpaXml_DOMImplementationList_free_e) {
      DOMImplementationListp = (marpaXml_DOMImplementationList_t *) objp;
      DOMObjectsp = DOMImplementationListp->DOMObjectsp;
    } else if (stmte == _marpaXml_Lexeme_free_e) {
      Lexemep = (marpaXml_Lexeme_t *) objp;
      DOMObjectsp = Lexemep->DOMObjectsp;
    } else {
      /* Simply impossible again -; */
      MARPAXML_ERRORX("_marpaXml_generateStmt internal error, stmt=%d, at %s:%d", stmte, __FILE__, __LINE__);
      break;
    }

    if ((sqls = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id)) == messageBuilder_internalErrors()) {
      MARPAXML_ERRORX("%s", sqls);
      /* Free at least DOMObjectsp */
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }
    if (_marpaXml_prepare(_marpaXml_dbp, sqls, sqliteStmtpp) == marpaXml_false) {
      free(sqls);
      /* Free at least DOMObjectsp */
      _marpaXml_DOMObjects_free(&DOMObjectsp);
      break;
    }

    *sqlsp = sqls;
    rcb = marpaXml_true;
    _marpaXml_DOMObjects_free(&DOMObjectsp);

    break;

  default:

    if ((stmte > _marpaXml_DOMStringList_new_e) && (stmte < _marpaXml_DOMStringList_free_e)) {
      DOMStringListp = (marpaXml_DOMStringList_t *) objp;
      DOMObjectsp = DOMStringListp->DOMObjectsp;
      cachedUntilFreeStmtp = DOMStringListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = DOMStringListp->cachedUntilFreeSqls;
    } else if ((stmte > _marpaXml_NameList_new_e) && (stmte < _marpaXml_NameList_free_e)) {
      NameListp = (marpaXml_NameList_t *) objp;
      DOMObjectsp = NameListp->DOMObjectsp;
      cachedUntilFreeStmtp = NameListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = NameListp->cachedUntilFreeSqls;
    } else if ((stmte > _marpaXml_DOMImplementationList_new_e) && (stmte < _marpaXml_DOMImplementationList_free_e)) {
      DOMImplementationListp = (marpaXml_DOMImplementationList_t *) objp;
      DOMObjectsp = DOMImplementationListp->DOMObjectsp;
      cachedUntilFreeStmtp = DOMImplementationListp->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = DOMImplementationListp->cachedUntilFreeSqls;
    } else if ((stmte > _marpaXml_Lexeme_new_e) && (stmte < _marpaXml_Lexeme_free_e)) {
      Lexemep = (marpaXml_Lexeme_t *) objp;
      DOMObjectsp = Lexemep->DOMObjectsp;
      cachedUntilFreeStmtp = Lexemep->cachedUntilFreeStmt;
      cachedUntilFreeSqlsp = Lexemep->cachedUntilFreeSqls;
    } else {
      /* This case means the big array at the top of the file is misconfigured */
      MARPAXML_ERRORX("_marpaXml_generateStmt internal error, stmt=%d, at %s:%d", stmte, __FILE__, __LINE__);
      break;
    }

    if ((cachedUntilFreeStmtp[stmte] != NULL) && (cachedUntilFreeSqlsp[stmte] != NULL)) {

      *sqliteStmtpp = cachedUntilFreeStmtp[stmte];
      *sqlsp        = cachedUntilFreeSqlsp[stmte];
      rcb = marpaXml_true;

    } else {

      if ((cachedUntilFreeSqlsp[stmte] = messageBuilder(_marpaXml_stmt[stmte].sql, DOMObjectsp->id)) == messageBuilder_internalErrors()) {
	MARPAXML_ERRORX("%s", cachedUntilFreeSqlsp[stmte]);
	cachedUntilFreeSqlsp[stmte] = NULL;
	break;
      }
      if (_marpaXml_prepare(_marpaXml_dbp, cachedUntilFreeSqlsp[stmte], &(cachedUntilFreeStmtp[stmte])) == marpaXml_false) {
	free(cachedUntilFreeSqlsp[stmte]);
	cachedUntilFreeSqlsp[stmte] = NULL;
	break;
      }

      MARPAXML_TRACEX("[%s] %s", _MARPAXML_CACHE, cachedUntilFreeSqlsp[stmte]);

      *sqliteStmtpp = cachedUntilFreeStmtp[stmte];
      *sqlsp        = cachedUntilFreeSqlsp[stmte];
      rcb = marpaXml_true;
    }

    break;
  }

  return rcb;
}

/*******************************************************************/
/* marpaXml_DOM_init                                               */
/*******************************************************************/
marpaXml_boolean_t marpaXml_DOM_init(marpaXml_DOM_Option_t *marpaXml_DOM_Optionp) {
  UErrorCode            uErrorCode = U_ZERO_ERROR;
  sqlite3_mutex        *master_mutexp = NULL;
  sqlite3_mutex        *mutexp = NULL;
  sqlite3_stmt         *loadcollation_stmt = NULL;
  static sqlite3       *dbp = NULL;
  marpaXml_DOM_Option_t marpaXml_DOM_Option = {":memory:", NULL, -1, NULL};
  int                   sqliteRc;
  int                   i;
  int                   iConstantForEndiannessDetection = 1;
  void                 *xxhp;
  char                 *pForEndiannessDetection = (char *)&iConstantForEndiannessDetection;
  marpaWrapperOption_t  marpaWrapperOption;

  /* We first check _marpaXml_isInitialized in a non thread-safe way for quick return */
  if (_marpaXml_isInitialized == marpaXml_true) {
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
  /* From now on we are sure we are in a synchronized call: we can recheck _marpaXml_isInitialized */
  if (_marpaXml_isInitialized == marpaXml_true) {
    sqlite3_mutex_leave(mutexp);
    return marpaXml_true;
  }

  /* We are synchronized here: this mean we can setup logging right now if not already done */
  if (marpaXml_DOM_Optionp != NULL) {
    marpaXml_DOM_Option = *marpaXml_DOM_Optionp;
  }

  marpaXmlLogp = marpaXml_DOM_Option.marpaXmlLogp;

  /* From now on we can use the log macros */

  /* Precompute grammars */
  MARPAXML_TRACE0("Precomputing qname XML 1.0 grammar");
  marpaWrapper_optionDefaultb(&marpaWrapperOption);
  marpaWrapperOption.marpaXmlLogp = marpaXml_DOM_Option.marpaXmlLogp;
  qname_1_0p = qname_1_0_newp(&marpaWrapperOption);
  if (qname_1_0p == NULL) {
    goto error;
  }


  /* Determine endiannes */
  if (pForEndiannessDetection[0] == 1) {
    _marpaXml_isLittleEndianb = marpaXml_true;
    _marpaXml_isBigEndianb = marpaXml_false;
    _marpaXml_UTF16_Encodings = (char*) _MARPAXML_UTF16LE;
  } else {
    _marpaXml_isLittleEndianb = marpaXml_false;
    _marpaXml_isBigEndianb = marpaXml_true;
    _marpaXml_UTF16_Encodings = (char *) _MARPAXML_UTF16BE;
  }
  MARPAXML_TRACEX("Platform UTF16 encoding is \"%s\"", _marpaXml_UTF16_Encodings);

  _marpaXml_String_globalOption.marpaXml_String_Option_ICU = MARPAXML_STRING_OPTION_ICU_DEFAULT;
  _marpaXml_String_globalOption.fallback                   = marpaXml_true;
  _marpaXml_String_globalOption.marpaXmlLogp               = marpaXml_DOM_Option.marpaXmlLogp;

  mutexp = sqlite3_mutex_alloc(SQLITE_MUTEX_FAST);
  if (mutexp == NULL) {
    MARPAXML_ERRORX("sqlite3_mutex_alloc(SQLITE_MUTEX_FAST): %s (latest errno string) at %s:%d", strerror(errno), __FILE__, __LINE__);
    goto error;
  }
  sqlite3_mutex_enter(mutexp);
  sqlite3_mutex_leave(master_mutexp);
  master_mutexp = NULL;

  /* Note: u_init() is thread-safe */
  u_init(&uErrorCode);
  if (U_FAILURE(uErrorCode)) {
    MARPAXML_ERRORX("u_init(): %s at %s:%d", u_errorName(uErrorCode), __FILE__, __LINE__);
    goto error;
  }

  /* Open the DB */
  MARPAXML_TRACEX("Opening database \"%s\"", marpaXml_DOM_Option.dbFilename);
  if ((sqliteRc = sqlite3_open_v2(marpaXml_DOM_Option.dbFilename, &dbp, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE|SQLITE_OPEN_FULLMUTEX|SQLITE_OPEN_SHAREDCACHE|SQLITE_OPEN_URI, NULL)) != SQLITE_OK) {
    MARPAXML_ERRORX("sqlite3_open_v2(%s%s%s, ...): %s at %s:%d",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        marpaXml_DOM_Option.dbFilename != NULL ? marpaXml_DOM_Option.dbFilename : "",
        marpaXml_DOM_Option.dbFilename != NULL ? "\"" : "",
        sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
    goto error;
  }

  /* Execute fixed PRAGMA SQL statements */
  i = -1;
  while (_marpaXml_pragmas[++i].sql != NULL) {
    if (_marpaXml_exec(dbp, _marpaXml_pragmas[i].sql, NULL, NULL) == marpaXml_false) {
      goto error;
    }
  }

  /* Very first thing: load collation */
  if (_marpaXml_prepare(dbp, _MARPAXML_LOADCOLLATION, &loadcollation_stmt) == marpaXml_false) {
    goto error;
  }

  if (_marpaXml_bind_text(loadcollation_stmt, 1, marpaXml_DOM_Option.locale,       0) == marpaXml_false ||
      _marpaXml_bind_int (loadcollation_stmt, 2, marpaXml_DOM_Option.collStrength, 0) == marpaXml_false) {
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
    MARPAXML_ERRORX("_marpaXml_step() returns %d != SQLITE_DONE: %s at %s:%d", sqliteRc, sqlite3_errstr(sqliteRc), __FILE__, __LINE__);
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
    MARPAXML_ERRORX("marpaXml_HashInit(): %s", strerror(errno));
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
      MARPAXML_TRACEX("[%s] %s", _MARPAXML_SKIPPED, _marpaXml_stmt[i].sql);
    }
  }

  /* Prepare static instances */
  /*
  if (((marpaXml_DOMImplementationRegistryp = _marpaXml_DOMImplementationRegistry_new()) == NULL)) {
    goto error;
  }
  */

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
  _marpaXml_isInitialized = marpaXml_true;
  _marpaXml_dbp = dbp;

  sqlite3_mutex_leave(mutexp);
  sqlite3_mutex_free(mutexp);

  return marpaXml_true;

 error:
  if (master_mutexp != NULL) {
    sqlite3_mutex_leave(master_mutexp);
  }
  /*
  if (marpaXml_DOMImplementationRegistryp != NULL) {
    marpaXml_DOMImplementationRegistry_free(&marpaXml_DOMImplementationRegistryp);
  }
  */
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
  if (qname_1_0p != NULL) {
    qname_1_0_destroyv(&qname_1_0p);
  }

  return marpaXml_false;
}

/*******************************************************************/
/* _marpaXml_featuresWhereClause                                   */
/*******************************************************************/
static C_INLINE marpaXml_boolean_t _marpaXml_featuresWhereClause(_marpaXml_stmt_e stmte, marpaXml_String_t *requestp, char **wheresp) {
  UErrorCode                     uErrorCode = U_ZERO_ERROR;
  UText                         *utextp = NULL;
  UChar32                        uChar32;
  marpaXml_boolean_t             rcb  = marpaXml_true;
  marpaXml_boolean_t             canBeVersionb = marpaXml_false;
  marpaXml_boolean_t             isVersionb = marpaXml_false;
  marpaXml_boolean_t             inTokenb = marpaXml_false;
  int64_t                        currentNativeIndex;
  int64_t                        startTokenNativeIndex = 0;
  int64_t                        endTokenNativeIndex;
  marpaXml_featureAndVersion_t **featureAndVersionpp = NULL;
  size_t                         featureAndVersionSizel = 0;
  size_t                         featureAndVersionWantedSizel = 0;
  int32_t                        uCharSizei;
  size_t                         uCharByteLengthi;
  UChar                         *uCharp;
  marpaXml_String_t            **stringpp;
  size_t                         i;
  char                          *wheres = NULL;
  size_t                         wherel;

  switch (stmte) {
  case _marpaXml_DOMImplementationSource_getDOMImplementation_e:
  case _marpaXml_DOMImplementationSource_getDOMImplementationList_e:
    break;
  default:
    MARPAXML_ERRORX("Bad stmte %d", stmte);
    return marpaXml_false;
  }

  /* Spec says this is a space-separated list of: [+]feature [version] */
  /* We assume space is any unicode character having the White_Space unicode property */
  if (requestp != NULL) {
    utextp = utext_openUTF8(NULL, (const char *) marpaXml_String_getUtf8(requestp), -1, &uErrorCode);
    if (U_FAILURE(uErrorCode)) {
      MARPAXML_ERRORX("utext_openUTF8(): %s", u_errorName(uErrorCode));
      rcb = marpaXml_false;
    } else {
      while (1) {
        currentNativeIndex = UTEXT_GETNATIVEINDEX(utextp);
	uChar32 = UTEXT_NEXT32(utextp);
	if ((uChar32 == U_SENTINEL) || u_isUWhiteSpace(uChar32)) {
	  if (inTokenb == marpaXml_true) {
            endTokenNativeIndex = currentNativeIndex;
	    /* This is the end of a token, its indexes are [startTokenNativeIndex,endTokenNativeIndex] */
	    if (isVersionb == marpaXml_false) {
              if (manageBuf_createp((void ***) &featureAndVersionpp, &featureAndVersionSizel, featureAndVersionWantedSizel + 1, sizeof(marpaXml_featureAndVersion_t *)) == NULL) {
                MARPAXML_ERRORX("manageBuf_createp(): %s", strerror(errno));
                manageBuf_freev((void ***) &featureAndVersionpp, &featureAndVersionSizel, &featureAndVersionWantedSizel);
                rcb = marpaXml_false;
                break;
              } else {
                featureAndVersionWantedSizel++;
                featureAndVersionpp[featureAndVersionWantedSizel-1] = malloc(sizeof(marpaXml_featureAndVersion_t));
                if (featureAndVersionpp[featureAndVersionWantedSizel-1] == NULL) {
                  MARPAXML_ERRORX("malloc(): %s", strerror(errno));
                  manageBuf_freev((void ***) &featureAndVersionpp, &featureAndVersionSizel, &featureAndVersionWantedSizel);
                  rcb = marpaXml_false;
                  break;
                }
                featureAndVersionpp[featureAndVersionWantedSizel-1]->featurep = NULL;
                featureAndVersionpp[featureAndVersionWantedSizel-1]->versionp = NULL;
              }

              /* Next token can be a version number */
              canBeVersionb = marpaXml_true;

            } else {

              /* Next token cannot be a version number */
              canBeVersionb = marpaXml_false;
            }

            if (isVersionb == marpaXml_true) {
              stringpp = &(featureAndVersionpp[featureAndVersionWantedSizel-1]->versionp);
            } else {
              stringpp = &(featureAndVersionpp[featureAndVersionWantedSizel-1]->featurep);
            }

            uErrorCode = U_ZERO_ERROR;
            uCharSizei = utext_extract(utextp, startTokenNativeIndex, endTokenNativeIndex, NULL, 0, &uErrorCode);
            if ((uCharSizei <= 0) || uErrorCode != U_BUFFER_OVERFLOW_ERROR) {
              if (U_FAILURE(uErrorCode)) {
                MARPAXML_ERRORX("utext_extract(): %s", u_errorName(uErrorCode));
              } else {
                MARPAXML_ERROR0("utext_extract(): returned a number <= 0");
              }
              rcb = marpaXml_false;
              break;
            }
            uCharByteLengthi = uCharSizei * sizeof(UChar);
            if ((uCharp = malloc(uCharByteLengthi)) == NULL) {
              MARPAXML_ERRORX("malloc(): %s", strerror(errno));
              rcb = marpaXml_false;
              break;
            }
            uErrorCode = U_ZERO_ERROR;
            uCharSizei = utext_extract(utextp, startTokenNativeIndex, endTokenNativeIndex, uCharp, uCharSizei, &uErrorCode);
            if ((uCharSizei <= 0) || U_FAILURE(uErrorCode)) {
              if (U_FAILURE(uErrorCode)) {
                MARPAXML_ERRORX("utext_extract(): %s", u_errorName(uErrorCode));
              } else {
                MARPAXML_ERROR0("utext_extract(): returned a number <= 0");
              }
              free(uCharp);
              rcb = marpaXml_false;
              break;
            }
	    /* ICU's UChar is using machine native endianness. */
            *stringpp = marpaXml_String_newFromAnyAndByteLengthAndCharset((char *) uCharp, uCharByteLengthi, _marpaXml_UTF16_Encodings, &_marpaXml_String_globalOption); 
            free(uCharp);
            if (*stringpp == NULL) {
              free(uCharp);
              rcb = marpaXml_false;
              break;
            } else {
              MARPAXML_TRACEX("[%s] Requested %s: %s", "_marpaXml_featuresWhereClause", (isVersionb == marpaXml_true) ? "version" : "feature", marpaXml_String_getUtf8(*stringpp));
            }
          }
          inTokenb = marpaXml_false;
          if (uChar32 == U_SENTINEL) {
            break;
          } else {
            continue;
          }
        }
	/* Here we expect a feature or a version */
	else if (uChar32 == '+') {
	  /* + is meaningful only if it is followed by a feature */
	  canBeVersionb = marpaXml_false;
	}
	else if (u_isdigit(uChar32)) {
          if (inTokenb == marpaXml_false) {
            if (canBeVersionb == marpaXml_false) {
              MARPAXML_ERROR0("Malformed input: digit not expected");
              rcb = marpaXml_false;
              break;
            } else {
              inTokenb = marpaXml_true;
              isVersionb = marpaXml_true;
              startTokenNativeIndex = currentNativeIndex;
            }
          }
	} else {
          if (inTokenb == marpaXml_false) {
            inTokenb = marpaXml_true;
            isVersionb = marpaXml_false;
            startTokenNativeIndex = currentNativeIndex;
          }
        }
      }
    }
  }

  if (utextp != NULL) {
    utext_close(utextp);
  }

  if (rcb == marpaXml_true) {
    /* We construct on-the-fly the WHERE statement */
    wherel = strlen(_MARPAXML_SELECT_STAR_FROM_BEG);
    for (i = 0; i < featureAndVersionWantedSizel; i++) {
      if (i > 0) {
	wherel += strlen(_MARPAXML_INTERSECT);
      }
      wherel += strlen(_MARPAXML_SELECT_DISTINCT_implementationName_FROM_DOMImplementation_WHERE);
      if (featureAndVersionpp[i]->featurep != NULL) {
        wherel += strlen(_MARPAXML_FEATURE_LIKE) - 2 + strlen(marpaXml_String_getUtf8(featureAndVersionpp[i]->featurep));
      }
      if (featureAndVersionpp[i]->versionp != NULL) {
	if (featureAndVersionpp[i]->featurep != NULL) {
	  wherel += strlen(_MARPAXML_AND);;
	}
        wherel += strlen(_MARPAXML_VERSION_EQ) - 2 + strlen(marpaXml_String_getUtf8(featureAndVersionpp[i]->versionp));
      }
    }
    wherel += strlen(_MARPAXML_SELECT_STAR_FROM_END);
    if (stmte == _marpaXml_DOMImplementationSource_getDOMImplementation_e) {
      wherel += strlen(_MARPAXML_LIMIT_ONE);
    }
    wherel++; /* For the null byte */

    if ((wheres = malloc(sizeof(char) * wherel)) == NULL) {
      MARPAXML_ERRORX("malloc(): %s", strerror(errno));
      rcb = marpaXml_false;
    } else {
      wheres[0] = '\0';
      _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_SELECT_STAR_FROM_BEG);
      for (i = 0; i < featureAndVersionWantedSizel; i++) {
	if (i > 0) {
	  _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_INTERSECT);
	}
	_marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_SELECT_DISTINCT_implementationName_FROM_DOMImplementation_WHERE);
        if (featureAndVersionpp[i]->featurep != NULL) {
          _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), _MARPAXML_FEATURE_LIKE, marpaXml_String_getUtf8(featureAndVersionpp[i]->featurep));
        }
        if (featureAndVersionpp[i]->versionp != NULL) {
	  if (featureAndVersionpp[i]->featurep != NULL) {
            _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_AND);
          }
          _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), _MARPAXML_VERSION_EQ, marpaXml_String_getUtf8(featureAndVersionpp[i]->versionp));
        }
      }
      _marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_SELECT_STAR_FROM_END);
      if (stmte == _marpaXml_DOMImplementationSource_getDOMImplementation_e) {
	_marpaXml_snprintf(wheres + strlen(wheres), sizeof(char) * (wherel - strlen(wheres)), "%s", _MARPAXML_LIMIT_ONE);
      }
      MARPAXML_TRACEX("[%s] Where clause: %s", "_marpaXml_featuresWhereClause", wheres);
    }
  }

  for (i = 0; i < featureAndVersionWantedSizel; i++) {
    if (featureAndVersionpp[i]->featurep != NULL) {
      marpaXml_String_free(&(featureAndVersionpp[i]->featurep));
    }
    if (featureAndVersionpp[i]->versionp != NULL) {
      marpaXml_String_free(&(featureAndVersionpp[i]->versionp));
    }
  }

  manageBuf_freev((void ***) &featureAndVersionpp, &featureAndVersionSizel, &featureAndVersionWantedSizel);

  if (rcb == marpaXml_true) {
    *wheresp = wheres;
  } else {
    if (wheres != NULL) {
      free(wheres);
    }
  }

  return rcb;
}

/*******************************************************************/
/* _marpaXml_qualifiedNameToPrefixAndLocalName                     */
/*******************************************************************/
/* A qualified name is the name of an element or attribute defined as the concatenation of a local name */
/* (as defined in this specification), optionally preceded by a namespace prefix and colon character)   */
/* A qualified name is as of XML1.0 spec, i.e.:                                                         */
/*
   [6]  QName      ::= (Prefix ':')? LocalPart
   [7]  Prefix     ::= NCName
   [8]  LocalPart  ::= NCName

   [4]  NCName     ::= (Letter | '_') (NCNameChar)*
   [5]  NCNameChar ::= Letter | Digit | '.' | '-' | '_' | CombiningChar | Extender
   [84] Letter     ::= BaseChar | Ideographic 
   [85] BaseChar   ::= [#x0041-#x005A] | [#x0061-#x007A] | [#x00C0-#x00D6] | [#x00D8-#x00F6] | [#x00F8-#x00FF] | [#x0100-#x0131] | [#x0134-#x013E] | [#x0141-#x0148] | [#x014A-#x017E] | [#x0180-#x01C3] | [#x01CD-#x01F0] | [#x01F4-#x01F5] | [#x01FA-#x0217] | [#x0250-#x02A8] | [#x02BB-#x02C1] | #x0386 | [#x0388-#x038A] | #x038C | [#x038E-#x03A1] | [#x03A3-#x03CE] | [#x03D0-#x03D6] | #x03DA | #x03DC | #x03DE | #x03E0 | [#x03E2-#x03F3] | [#x0401-#x040C] | [#x040E-#x044F] | [#x0451-#x045C] | [#x045E-#x0481] | [#x0490-#x04C4] | [#x04C7-#x04C8] | [#x04CB-#x04CC] | [#x04D0-#x04EB] | [#x04EE-#x04F5] | [#x04F8-#x04F9] | [#x0531-#x0556] | #x0559 | [#x0561-#x0586] | [#x05D0-#x05EA] | [#x05F0-#x05F2] | [#x0621-#x063A] | [#x0641-#x064A] | [#x0671-#x06B7] | [#x06BA-#x06BE] | [#x06C0-#x06CE] | [#x06D0-#x06D3] | #x06D5 | [#x06E5-#x06E6] | [#x0905-#x0939] | #x093D | [#x0958-#x0961] | [#x0985-#x098C] | [#x098F-#x0990] | [#x0993-#x09A8] | [#x09AA-#x09B0] | #x09B2 | [#x09B6-#x09B9] | [#x09DC-#x09DD] | [#x09DF-#x09E1] | [#x09F0-#x09F1] | [#x0A05-#x0A0A] | [#x0A0F-#x0A10] | [#x0A13-#x0A28] | [#x0A2A-#x0A30] | [#x0A32-#x0A33] | [#x0A35-#x0A36] | [#x0A38-#x0A39] | [#x0A59-#x0A5C] | #x0A5E | [#x0A72-#x0A74] | [#x0A85-#x0A8B] | #x0A8D | [#x0A8F-#x0A91] | [#x0A93-#x0AA8] | [#x0AAA-#x0AB0] | [#x0AB2-#x0AB3] | [#x0AB5-#x0AB9] | #x0ABD | #x0AE0 | [#x0B05-#x0B0C] | [#x0B0F-#x0B10] | [#x0B13-#x0B28] | [#x0B2A-#x0B30] | [#x0B32-#x0B33] | [#x0B36-#x0B39] | #x0B3D | [#x0B5C-#x0B5D] | [#x0B5F-#x0B61] | [#x0B85-#x0B8A] | [#x0B8E-#x0B90] | [#x0B92-#x0B95] | [#x0B99-#x0B9A] | #x0B9C | [#x0B9E-#x0B9F] | [#x0BA3-#x0BA4] | [#x0BA8-#x0BAA] | [#x0BAE-#x0BB5] | [#x0BB7-#x0BB9] | [#x0C05-#x0C0C] | [#x0C0E-#x0C10] | [#x0C12-#x0C28] | [#x0C2A-#x0C33] | [#x0C35-#x0C39] | [#x0C60-#x0C61] | [#x0C85-#x0C8C] | [#x0C8E-#x0C90] | [#x0C92-#x0CA8] | [#x0CAA-#x0CB3] | [#x0CB5-#x0CB9] | #x0CDE | [#x0CE0-#x0CE1] | [#x0D05-#x0D0C] | [#x0D0E-#x0D10] | [#x0D12-#x0D28] | [#x0D2A-#x0D39] | [#x0D60-#x0D61] | [#x0E01-#x0E2E] | #x0E30 | [#x0E32-#x0E33] | [#x0E40-#x0E45] | [#x0E81-#x0E82] | #x0E84 | [#x0E87-#x0E88] | #x0E8A | #x0E8D | [#x0E94-#x0E97] | [#x0E99-#x0E9F] | [#x0EA1-#x0EA3] | #x0EA5 | #x0EA7 | [#x0EAA-#x0EAB] | [#x0EAD-#x0EAE] | #x0EB0 | [#x0EB2-#x0EB3] | #x0EBD | [#x0EC0-#x0EC4] | [#x0F40-#x0F47] | [#x0F49-#x0F69] | [#x10A0-#x10C5] | [#x10D0-#x10F6] | #x1100 | [#x1102-#x1103] | [#x1105-#x1107] | #x1109 | [#x110B-#x110C] | [#x110E-#x1112] | #x113C | #x113E | #x1140 | #x114C | #x114E | #x1150 | [#x1154-#x1155] | #x1159 | [#x115F-#x1161] | #x1163 | #x1165 | #x1167 | #x1169 | [#x116D-#x116E] | [#x1172-#x1173] | #x1175 | #x119E | #x11A8 | #x11AB | [#x11AE-#x11AF] | [#x11B7-#x11B8] | #x11BA | [#x11BC-#x11C2] | #x11EB | #x11F0 | #x11F9 | [#x1E00-#x1E9B] | [#x1EA0-#x1EF9] | [#x1F00-#x1F15] | [#x1F18-#x1F1D] | [#x1F20-#x1F45] | [#x1F48-#x1F4D] | [#x1F50-#x1F57] | #x1F59 | #x1F5B | #x1F5D | [#x1F5F-#x1F7D] | [#x1F80-#x1FB4] | [#x1FB6-#x1FBC] | #x1FBE | [#x1FC2-#x1FC4] | [#x1FC6-#x1FCC] | [#x1FD0-#x1FD3] | [#x1FD6-#x1FDB] | [#x1FE0-#x1FEC] | [#x1FF2-#x1FF4] | [#x1FF6-#x1FFC] | #x2126 | [#x212A-#x212B] | #x212E | [#x2180-#x2182] | [#x3041-#x3094] | [#x30A1-#x30FA] | [#x3105-#x312C] | [#xAC00-#xD7A3]
   [86] Ideographic ::= [#x4E00-#x9FA5] | #x3007 | [#x3021-#x3029]
   [87] CombiningChar ::= [#x0300-#x0345] | [#x0360-#x0361] | [#x0483-#x0486] | [#x0591-#x05A1] | [#x05A3-#x05B9] | [#x05BB-#x05BD] | #x05BF | [#x05C1-#x05C2] | #x05C4 | [#x064B-#x0652] | #x0670 | [#x06D6-#x06DC] | [#x06DD-#x06DF] | [#x06E0-#x06E4] | [#x06E7-#x06E8] | [#x06EA-#x06ED] | [#x0901-#x0903] | #x093C | [#x093E-#x094C] | #x094D | [#x0951-#x0954] | [#x0962-#x0963] | [#x0981-#x0983] | #x09BC | #x09BE | #x09BF | [#x09C0-#x09C4] | [#x09C7-#x09C8] | [#x09CB-#x09CD] | #x09D7 | [#x09E2-#x09E3] | #x0A02 | #x0A3C | #x0A3E | #x0A3F | [#x0A40-#x0A42] | [#x0A47-#x0A48] | [#x0A4B-#x0A4D] | [#x0A70-#x0A71] | [#x0A81-#x0A83] | #x0ABC | [#x0ABE-#x0AC5] | [#x0AC7-#x0AC9] | [#x0ACB-#x0ACD] | [#x0B01-#x0B03] | #x0B3C | [#x0B3E-#x0B43] | [#x0B47-#x0B48] | [#x0B4B-#x0B4D] | [#x0B56-#x0B57] | [#x0B82-#x0B83] | [#x0BBE-#x0BC2] | [#x0BC6-#x0BC8] | [#x0BCA-#x0BCD] | #x0BD7 | [#x0C01-#x0C03] | [#x0C3E-#x0C44] | [#x0C46-#x0C48] | [#x0C4A-#x0C4D] | [#x0C55-#x0C56] | [#x0C82-#x0C83] | [#x0CBE-#x0CC4] | [#x0CC6-#x0CC8] | [#x0CCA-#x0CCD] | [#x0CD5-#x0CD6] | [#x0D02-#x0D03] | [#x0D3E-#x0D43] | [#x0D46-#x0D48] | [#x0D4A-#x0D4D] | #x0D57 | #x0E31 | [#x0E34-#x0E3A] | [#x0E47-#x0E4E] | #x0EB1 | [#x0EB4-#x0EB9] | [#x0EBB-#x0EBC] | [#x0EC8-#x0ECD] | [#x0F18-#x0F19] | #x0F35 | #x0F37 | #x0F39 | #x0F3E | #x0F3F | [#x0F71-#x0F84] | [#x0F86-#x0F8B] | [#x0F90-#x0F95] | #x0F97 | [#x0F99-#x0FAD] | [#x0FB1-#x0FB7] | #x0FB9 | [#x20D0-#x20DC] | #x20E1 | [#x302A-#x302F] | #x3099 | #x309A
   [88] Digit ::= [#x0030-#x0039] | [#x0660-#x0669] | [#x06F0-#x06F9] | [#x0966-#x096F] | [#x09E6-#x09EF] | [#x0A66-#x0A6F] | [#x0AE6-#x0AEF] | [#x0B66-#x0B6F] | [#x0BE7-#x0BEF] | [#x0C66-#x0C6F] | [#x0CE6-#x0CEF] | [#x0D66-#x0D6F] | [#x0E50-#x0E59] | [#x0ED0-#x0ED9] | [#x0F20-#x0F29]
   [89] Extender ::= #x00B7 | #x02D0 | #x02D1 | #x0387 | #x0640 | #x0E46 | #x0EC6 | #x3005 | [#x3031-#x3035] | [#x309D-#x309E] | [#x30FC-#x30FE] 
   
*/
static C_INLINE marpaXml_boolean_t _marpaXml_qualifiedNameToPrefixAndLocalName(marpaXml_String_t *qualifiedNamep, marpaXml_String_t **prefixpp, marpaXml_String_t **localNamepp, marpaXml_DOMException_t **exceptionpp) {
  return marpaXml_false;
}

