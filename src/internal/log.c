#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "internal/config.h"
#include "internal/log.h"
#include "internal/messageBuilder.h"

struct marpaXmlLog {
  marpaXmlLogCallback_t  logCallbackp;
  void                  *userDatavp;
  marpaXmlLogLevel_t     marpaXmlLogLeveli;
};

void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs);
static C_INLINE void _marpaXml_log(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli, const char *fmts, ...);

/********************************/
/* _marpaXmlLog_defaultCallback */
/********************************/
void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs) {
  const char *prefix;

  switch (logLeveli) {
  case MARPAXML_LOGLEVEL_TRACE:     prefix = "TRACE";     break;
  case MARPAXML_LOGLEVEL_DEBUG:     prefix = "DEBUG";     break;
  case MARPAXML_LOGLEVEL_INFO:      prefix = "INFO";      break;
  case MARPAXML_LOGLEVEL_NOTICE:    prefix = "NOTICE";    break;
  case MARPAXML_LOGLEVEL_WARNING:   prefix = "WARNING";   break;
  case MARPAXML_LOGLEVEL_ERROR:     prefix = "ERROR";     break;
  case MARPAXML_LOGLEVEL_CRITICAL:  prefix = "CRITICAL";  break;
  case MARPAXML_LOGLEVEL_ALERT:     prefix = "ALERT";     break;
  case MARPAXML_LOGLEVEL_EMERGENCY: prefix = "EMERGENCY"; break;
  default:                          prefix = "UNKNOWN";   break;
  }

  fprintf(stderr, "[%9s] %s\n", prefix, (msgs != NULL) ? msgs : "No message");
}

/********************/
/* marpaXmlLog_newp */
/********************/
marpaXmlLog_t *marpaXmlLog_newp(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli) {
  marpaXmlLog_t *marpaXmlLogp = malloc(sizeof(marpaXmlLog_t));

  if (marpaXmlLogp == NULL) {
    _marpaXml_log(logCallbackp, userDatavp, MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
    return NULL;
  }

  marpaXmlLogp->logCallbackp      = logCallbackp;
  marpaXmlLogp->userDatavp        = userDatavp;
  marpaXmlLogp->marpaXmlLogLeveli = marpaXmlLogLeveli;

  return marpaXmlLogp;
}

/*********************/
/* marpaXmlLog_freev */
/*********************/
void marpaXmlLog_freev(marpaXmlLog_t *marpaXmlLogp) {

  if (marpaXmlLogp == NULL) {
    _marpaXml_log(NULL, NULL, MARPAXML_LOGLEVEL_ERROR, "Invalid log pointer at %s:%d", __FILE__, __LINE__);
    return;
  }

  free(marpaXmlLogp);
  return;
}

/*****************/
/* _marpaXml_log */
/*****************/
static C_INLINE void _marpaXml_log(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli, const char *fmts, ...) {
  va_list                ap;
#ifdef VA_COPY
  va_list                ap2;
#endif
  char                  *msgs;
  static const char     *emptyMessages = "Empty message";

  if (logCallbackp == NULL) {
    logCallbackp = &_marpaXmlLog_defaultCallback;
    userDatavp   = NULL;
  }

  va_start(ap, fmts);
#ifdef VA_COPY
  VA_COPY(ap2, ap);
  msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap2) : (char *) emptyMessages;
  va_end(ap2);
#else
  msgs = (fmts != NULL) ? messageBuilder_ap(fmts, ap) : (char *) emptyMessages;
#endif
  va_end(ap);

  if (msgs != messageBuilder_internalErrors()) {
    logCallbackp(userDatavp, marpaXmlLogLeveli, msgs);
  } else {
    logCallbackp(userDatavp, MARPAXML_LOGLEVEL_ERROR, msgs);
  }

  if (msgs != emptyMessages && msgs != messageBuilder_internalErrors()) {
    /* No need to assign to NULL, this is a local variable and we will return just after */
    free(msgs);
  }
}

/****************/
/* marpaXml_log */
/****************/
void marpaXml_log(marpaXmlLog_t *marpaXmlLogp, marpaXmlLogLevel_t marpaXmlLogLeveli, const char *fmts, ...) {
  va_list               ap;
#ifdef VA_COPY
  va_list               ap2;
#endif

  if (marpaXmlLogLeveli >= marpaXmlLogp->marpaXmlLogLeveli) {

    va_start(ap, fmts);
#ifdef VA_COPY
    VA_COPY(ap2, ap);
    _marpaXml_log(marpaXmlLogp->logCallbackp, marpaXmlLogp->userDatavp, marpaXmlLogLeveli, fmts, ap2);
    va_end(ap2);
#else
    _marpaXml_log(marpaXmlLogp->logCallbackp, marpaXmlLogp->userDatavp, marpaXmlLogLeveli, fmts, ap);
#endif
    va_end(ap);
  }

}
