#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "internal/config.h"
#include "internal/log.h"
#include "internal/messageBuilder.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

static const char *MARPAXML_LOG_NO_MESSAGE = "No message";

struct marpaXmlLog {
  marpaXmlLogCallback_t  logCallbackp;
  void                  *userDatavp;
  marpaXmlLogLevel_t     marpaXmlLogLeveli;
};

void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs);

/********************************/
/* _marpaXmlLog_defaultCallback */
/********************************/
void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs) {
#if (defined(WIN32) || (_POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE))
#ifdef WIN32
  int filenoStderr = _fileno(stderr);
#else
  int filenoStderr = fileno(stderr);
#endif
  char *p = (msgs != NULL) ? (char *) msgs : (char *) MARPAXML_LOG_NO_MESSAGE;
  ssize_t bytesWriten = 0;
  size_t  count = strlen(p) + sizeof(char);
#endif

#if (defined(WIN32) || (_POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE))
  while (bytesWriten < count) {
    bytesWriten += write(filenoStderr, p+bytesWriten, count-bytesWriten);
  }
#else
  /* Note: this is not asynchroneous safe */
  fprintf(stderr, "%s", (msgs != NULL) ? msgs : "No message\n");
#endif
}

/********************/
/* marpaXmlLog_newp */
/********************/
marpaXmlLog_t *marpaXmlLog_newp(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli) {
  marpaXmlLog_t *marpaXmlLogp = malloc(sizeof(marpaXmlLog_t));

  if (marpaXmlLogp == NULL) {
    marpaXml_log(NULL, MARPAXML_LOGLEVEL_ERROR, "malloc(): %s at %s:%d", strerror(errno), __FILE__, __LINE__);
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
void marpaXmlLog_freev(marpaXmlLog_t **marpaXmlLogpp) {
  if (marpaXmlLogpp == NULL) {
    marpaXml_log(NULL, MARPAXML_LOGLEVEL_ERROR, "marpaXmlLogpp is NULL at %s:%d", __FILE__, __LINE__);
  } else {
    if (*marpaXmlLogpp == NULL) {
      marpaXml_log(NULL, MARPAXML_LOGLEVEL_ERROR, "*marpaXmlLogpp is NULL at %s:%d", __FILE__, __LINE__);
    } else {
      free(*marpaXmlLogpp);
      *marpaXmlLogpp = NULL;
    }
  }
}

/****************/
/* marpaXml_log */
/****************/
void marpaXml_log(marpaXmlLog_t *marpaXmlLogp, marpaXmlLogLevel_t marpaXmlLogLeveli, const char *fmts, ...) {
  va_list                ap;
#ifdef VA_COPY
  va_list                ap2;
#endif
  char                  *msgs;
  static const char     *emptyMessages = "Empty message";
  marpaXmlLogCallback_t  logCallbackp;
  void                  *userDatavp;
  marpaXmlLogLevel_t     marpaXmlDefaultLogLeveli;

  if (marpaXmlLogp != NULL) {
    if (marpaXmlLogp->logCallbackp != NULL) {
      logCallbackp = marpaXmlLogp->logCallbackp;
    } else {
      logCallbackp = &_marpaXmlLog_defaultCallback;
    }
    userDatavp = marpaXmlLogp->userDatavp;
    marpaXmlDefaultLogLeveli = marpaXmlLogp->marpaXmlLogLeveli;
  } else {
    userDatavp = NULL;
    logCallbackp = &_marpaXmlLog_defaultCallback;
    marpaXmlDefaultLogLeveli = MARPAXML_LOGLEVEL_TRACE;
  }

  if (marpaXmlLogLeveli >= marpaXmlDefaultLogLeveli) {

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

}
