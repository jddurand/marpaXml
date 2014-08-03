#include <stdlib.h>
#include <stdio.h>

#include "internal/config.h"
#include "internal/messageBuilder.h"

static const char *_messageBuilder_internalErrors = "Internal error";

/*********************************/
/* messageBuilder_internalErrors */
/*********************************/
char *messageBuilder_internalErrors(void) {
  return (char *) _messageBuilder_internalErrors;
}

/******************/
/* messageBuilder */
/******************/
char *messageBuilder(const char *fmts, ...) {
  va_list ap;
#ifdef VA_COPY
  va_list ap2;
#endif
  char   *msgs;

  va_start(ap, fmts);
#ifdef VA_COPY
  VA_COPY(ap2, ap);
  msgs = messageBuilder_ap(fmts, ap2);
  va_end(ap2);
#else
  msgs = messageBuilder_ap(fmts, ap);
#endif
  va_end(ap);

  return msgs;
}

/*********************/
/* messageBuilder_ap */
/*********************/
char *messageBuilder_ap(const char *fmts, va_list ap) {
  int     n;
  int     size = 100;     /* Guess we need no more than 100 bytes */
  char   *p, *np;
#ifdef VA_COPY
  va_list ap2;
#endif

  /* ----------------------------------------------------------------------------------------------------------------------- */
  /* Take care: Windows's vsnpritnf is not like UNIX's, i.e:                                                                 */
  /*                                                                                                                         */
  /* Output:                                                                                                                 */
  /* [Windows] -1 if the number of chars to write if > size-1, or number of characters. Always minus trailing null character */
  /* [ UNIX  ] number of chars that would have been writen, including trailing null character                                */
  /*                                                                                                                         */
  /* Argument:                                                                                                               */
  /* [Windows] does not include the trailing null character                                                                  */
  /* [ UNIX  ] include the trailing null character                                                                           */
  /* ----------------------------------------------------------------------------------------------------------------------- */

  p = malloc(size);
  if (p == NULL) {
    return messageBuilder_internalErrors();
  }

  while (1) {

    /* Try to print in the allocated space */

#ifdef VA_COPY
    VA_COPY(ap2, ap);
    n = vsnprintf(p, size, fmts, ap2);
    va_end(ap2);
#else
    n = vsnprintf(p, size - 1, fmts, ap);
#endif

    /* Check error code */
#ifndef _WIN32
    if (n < 0) {
      free(p);
      return messageBuilder_internalErrors();
    }
#endif

    /* If that worked, return the string */

    if
#ifdef _WIN32
      (n >= 0 && n < size)
#else
      (n < size)
#endif
        {
      return p;
    }

    /* Else try again with more space */

#ifdef _WIN32
    size *= 2;          /* Maybe enough ? */
#else
    size = n + 1;       /* Precisely what is needed */
#endif

    np = realloc(p, size);
    if (np == NULL) {
      free(p);
      return messageBuilder_internalErrors();
    } else {
      p = np;
    }
  }

  /* Should never happen */
  return messageBuilder_internalErrors();
}

