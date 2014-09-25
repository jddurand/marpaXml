#ifndef MARPAXML_API_LOG_H
#define MARPAXML_API_LOG_H

typedef enum marpaXmlLogLevel {
  MARPAXML_LOGLEVEL_TRACE = 0,
  MARPAXML_LOGLEVEL_DEBUG,
  MARPAXML_LOGLEVEL_INFO,
  MARPAXML_LOGLEVEL_NOTICE,
  MARPAXML_LOGLEVEL_WARNING,
  MARPAXML_LOGLEVEL_ERROR,
  MARPAXML_LOGLEVEL_CRITICAL,
  MARPAXML_LOGLEVEL_ALERT,
  MARPAXML_LOGLEVEL_EMERGENCY
} marpaXmlLogLevel_t;

/*************************
   Opaque object pointer
 *************************/
typedef struct marpaXmlLog marpaXmlLog_t;
typedef void (*marpaXmlLogCallback_t)(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs);

marpaXmlLogCallback_t marpaXmlLog_defaultLogCallback(void);
/* For applications that want to initialize a structure outside of executable blocks: */
extern void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs);

marpaXmlLogLevel_t    marpaXmlLog_logLevel_seti(marpaXmlLog_t *marpaXmlLogp, marpaXmlLogLevel_t logLeveli);
marpaXmlLogLevel_t    marpaXmlLog_logLevel_geti(marpaXmlLog_t *marpaXmlLogp);

marpaXmlLog_t        *marpaXmlLog_newp(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli);
marpaXmlLog_t        *marpaXmlLog_clonep(marpaXmlLog_t *marpaXmlLogp);
void                  marpaXmlLog_freev(marpaXmlLog_t **marpaXmlLogpp);


/*****************************************/
/* Convenience structure for log options */
/*****************************************/
typedef struct marpaXmlLog_Option {
  marpaXmlLogCallback_t logCallbackp;
  void                 *logCallbackDatavp;
  marpaXmlLogLevel_t    logLevelWantedi;
} marpaXmlLog_Option_t;

/* C99 has problems with empty __VA_ARGS__ so we split macros in two categories: */
/* logging with no variable parameter */
/* logging with    variable paramerer(s) */

void marpaXml_log(marpaXmlLog_t *marpaXmlLogp, marpaXmlLogLevel_t marpaXmlLogLeveli, const char *fmts, ...);

#define MARPAXML_LOG0(logLeveli, msgs)      marpaXml_log(marpaXmlLogp, logLeveli, msgs)
#define MARPAXML_LOGX(logLeveli, fmts, ...) marpaXml_log(marpaXmlLogp, logLeveli, fmts, __VA_ARGS__)

#ifndef MARPAXML_NTRACE
#define MARPAXML_TRACE0(fmts)               MARPAXML_LOG0(MARPAXML_LOGLEVEL_TRACE, fmts)
#define MARPAXML_TRACEX(fmts, ...)          MARPAXML_LOGX(MARPAXML_LOGLEVEL_TRACE, fmts, __VA_ARGS__)
#else
#define MARPAXML_TRACE0(fmts)
#define MARPAXML_TRACEX(fmts, ...)
#endif

#define MARPAXML_DEBUG0(fmts)               MARPAXML_LOG0(MARPAXML_LOGLEVEL_DEBUG, fmts)
#define MARPAXML_DEBUGX(fmts, ...)          MARPAXML_LOGX(MARPAXML_LOGLEVEL_DEBUG, fmts, __VA_ARGS__)

#define MARPAXML_INFO0(fmts)                MARPAXML_LOG0(MARPAXML_LOGLEVEL_INFO, fmts)
#define MARPAXML_INFOX(fmts, ...)           MARPAXML_LOGX(MARPAXML_LOGLEVEL_INFO, fmts, __VA_ARGS__)

#define MARPAXML_NOTICE0(fmts)              MARPAXML_LOG0(MARPAXML_LOGLEVEL_NOTICE, fmts)
#define MARPAXML_NOTICEX(fmts, ...)         MARPAXML_LOGX(MARPAXML_LOGLEVEL_NOTICE, fmts, __VA_ARGS__)

#define MARPAXML_WARNING0(fmts)             MARPAXML_LOG0(MARPAXML_LOGLEVEL_WARNING, fmts)
#define MARPAXML_WARNINGX(fmts, ...)        MARPAXML_LOGX(MARPAXML_LOGLEVEL_WARNING, fmts, __VA_ARGS__)

#define MARPAXML_ERROR0(fmts)               MARPAXML_LOG0(MARPAXML_LOGLEVEL_ERROR, fmts)
#define MARPAXML_ERRORX(fmts, ...)          MARPAXML_LOGX(MARPAXML_LOGLEVEL_ERROR, fmts, __VA_ARGS__)

#define MARPAXML_CRITICAL0(fmts)            MARPAXML_LOG0(MARPAXML_LOGLEVEL_CRITICAL, fmts)
#define MARPAXML_CRITICALX(fmts, ...)       MARPAXML_LOGX(MARPAXML_LOGLEVEL_CRITICAL, fmts, __VA_ARGS__)

#define MARPAXML_ALERT0(fmts)               MARPAXML_LOG0(MARPAXML_LOGLEVEL_ALERT, fmts)
#define MARPAXML_ALERTX(fmts, ...)          MARPAXML_LOGX(MARPAXML_LOGLEVEL_ALERT, fmts, __VA_ARGS__)

#define MARPAXML_EMERGENCY0(fmts)           MARPAXML_LOG0(MARPAXML_LOGLEVEL_EMERGENCY, fmts)
#define MARPAXML_EMERGENCYX(fmts, ...)      MARPAXML_LOGX(MARPAXML_LOGLEVEL_EMERGENCY, fmts, __VA_ARGS__)

#endif /* MARPAXML_API_LOG_H */
