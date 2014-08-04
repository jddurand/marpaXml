#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "internal/config.h"
#include "internal/messageBuilder.h"
#include "internal/dateBuilder.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include "API/marpaXml/log.h"

static const char *MARPAXML_LOG_NO_MESSAGE = "No message";

struct marpaXmlLog {
  marpaXmlLogCallback_t  logCallbackp;
  void                  *userDatavp;
  marpaXmlLogLevel_t     marpaXmlLogLeveli;
};

void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs);

/*****************************/
/* marpaXmlLog_logLevel_seti */
/*****************************/
marpaXmlLogLevel_t marpaXmlLog_logLevel_seti(marpaXmlLog_t *marpaXmlLogp, marpaXmlLogLevel_t logLeveli) {
  marpaXmlLogp->marpaXmlLogLeveli = logLeveli;
  return marpaXmlLogp->marpaXmlLogLeveli;
}

/*****************************/
/* marpaXmlLog_logLevel_geti */
/*****************************/
marpaXmlLogLevel_t marpaXmlLog_logLevel_geti(marpaXmlLog_t *marpaXmlLogp) {
  return marpaXmlLogp->marpaXmlLogLeveli;
}

/**********************************/
/* marpaXmlLog_defaultLogCallback */
/**********************************/
marpaXmlLogCallback_t marpaXmlLog_defaultLogCallback(void) {
  return &_marpaXmlLog_defaultCallback;
}

/********************************/
/* _marpaXmlLog_defaultCallback */
/********************************/
void _marpaXmlLog_defaultCallback(void *userDatavp, marpaXmlLogLevel_t logLeveli, const char *msgs) {
  /* We are NOT going to do a general log4c mechanism (this can come later), using marpaXml in fact */
  /* I.e. we are fixing the default output to be: DD/MM/YYYY hh::mm::ss PREFIX MESSAGE */
  const char   *prefix =
    (logLeveli == MARPAXML_LOGLEVEL_TRACE    ) ? "TRACE"     :
    (logLeveli == MARPAXML_LOGLEVEL_DEBUG    ) ? "DEBUG"     :
    (logLeveli == MARPAXML_LOGLEVEL_INFO     ) ? "INFO"      :
    (logLeveli == MARPAXML_LOGLEVEL_NOTICE   ) ? "NOTICE"    :
    (logLeveli == MARPAXML_LOGLEVEL_WARNING  ) ? "WARNING"   :
    (logLeveli == MARPAXML_LOGLEVEL_ERROR    ) ? "ERROR"     :
    (logLeveli == MARPAXML_LOGLEVEL_CRITICAL ) ? "CRITICAL"  :
    (logLeveli == MARPAXML_LOGLEVEL_ALERT    ) ? "ALERT"     :
    (logLeveli == MARPAXML_LOGLEVEL_EMERGENCY) ? "EMERGENCY" :
    "UNKOWN";
  char   *dates = dateBuilder("%d/%m/%Y %H:%M:%S");
  char   *localMsgs = messageBuilder("%s %9s %s", dates, prefix, (msgs != NULL) ? (char *) msgs : (char *) MARPAXML_LOG_NO_MESSAGE);
#if (defined(WIN32) || (_POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE))
#ifdef WIN32
  int filenoStderr = _fileno(stderr);
#else
  int filenoStderr = fileno(stderr);
#endif
  char *p = localMsgs;
  ssize_t bytesWriten = 0;
  size_t  count = strlen(p) + sizeof(char);
#endif

#if (defined(WIN32) || (_POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE))
  while (bytesWriten < count) {
    bytesWriten += write(filenoStderr, p+bytesWriten, count-bytesWriten);
  }
#else
  /* Note: this is not asynchroneous safe */
  fprintf(stderr, "%s", p);
#endif

  if (dates != dateBuilder_internalErrors()) {
    free(dates);
  }
  if (localMsgs != messageBuilder_internalErrors()) {
    free(localMsgs);
  }
}

/********************/
/* marpaXmlLog_newp */
/********************/
marpaXmlLog_t *marpaXmlLog_newp(marpaXmlLogCallback_t logCallbackp, void *userDatavp, marpaXmlLogLevel_t marpaXmlLogLeveli) {
  marpaXmlLog_t *marpaXmlLogp = malloc(sizeof(marpaXmlLog_t));

  if (marpaXmlLogp == NULL) {
    /* Well, shall we log about this - a priori no: the caller wanted to set up a particular */
    /* logging system, and not use our default */
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
  if (marpaXmlLogpp != NULL) {
    if (*marpaXmlLogpp != NULL) {
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
