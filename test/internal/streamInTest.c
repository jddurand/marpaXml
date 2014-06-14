#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <io.h>
#define OPEN _open
#define CLOSE _close
#define READ _read
#define LSEEK _lseek
#define STRDUP _strdup
#include <windows.h>
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#define READ read
#define LSEEK lseek
#define STRDUP strdup
#endif
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "internal/streamIn.h"

typedef struct myReadData {
  int            fd;
  char          *buffer;
  streamInBool_t firstb;
  off_t          offseti;
} myReadData_t;


static streamInBool_t _readFileCallback  (void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *charArrayp, char **charManagedArrayp);
static streamInBool_t _readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *charArrayp, char **charManagedArrayp);
static void           _fileTest(streamIn_t *streamInp, char **argv);
static void           _bufferTest(streamIn_t *streamInp, char **argv);

/********/
/* main */
/********/
int main(int argc, char **argv) {
  streamIn_t      *streamInp = NULL;
  int rc = EXIT_SUCCESS;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

#ifdef _WIN32
  Sleep(10000);
#endif

  streamInp = streamInUtf8_newp(NULL, NULL);
  if (streamInp == NULL) {
    fprintf(stderr, "streamInUtf8_newp failure\n");
    return EXIT_FAILURE;
  }
  _fileTest(streamInp, argv);
  streamIn_destroyv(&streamInp);

  streamInp = streamInUtf8_newp(NULL, NULL);
  if (streamInp == NULL) {
    fprintf(stderr, "streamInUtf8_newp failure\n");
    return EXIT_FAILURE;
  }

  _bufferTest(streamInp, argv);
  streamIn_destroyv(&streamInp);

  return(rc);
}

/***************/
/* _bufferTest */
/***************/
static void _fileTest(streamIn_t *streamInp, char **argv) {
  streamInOption_t streamInOption;
  int              fd;
  myReadData_t     myReadData;
  size_t           indexBufferi;
  char             *charArrayp;
  size_t           bytesInBuffer;

  fprintf(stderr, "Filename test\n");
  fprintf(stderr, "-------------\n");

  if ((fd = OPEN(argv[1], O_RDONLY
#ifdef O_BINARY
		 |O_BINARY
#endif
		 )) < 0) {
    fprintf(stderr, "Failed to open %s, %s\n", argv[1], strerror(errno));
    return;
  }

  myReadData.fd = fd;
  myReadData.offseti = 0;
  myReadData.firstb = STREAMIN_BOOL_TRUE;

  if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionDefaultb failure\n");
    return;
  }
  streamInOption.bufMaxSizei = 100;
  streamInOption.logLevelWantedi = STREAMIN_LOGLEVEL_TRACE;
  streamInOption.readCallbackp = &_readFileCallback;
  streamInOption.readCallbackUserDatap = &myReadData;
  if (streamIn_optionb(streamInp, &streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionb failure\n");
    return;
  }

  while (streamIn_nextBufferb(streamInp, &indexBufferi, &charArrayp, &bytesInBuffer)) {
    char *s = malloc(bytesInBuffer + 1);
    if (s != NULL) {
      memcpy(s, charArrayp, bytesInBuffer);
      s[bytesInBuffer] = '\0';
      // fprintf(stderr, "%s\n", s);
      free(s);
    }
    if (indexBufferi % 2 == 1) {
      streamIn_doneBufferb(streamInp, -1);
    }
  }

  streamIn_doneBufferb(streamInp, 0);

  if (fd >= 0 && CLOSE(fd) != 0) {
    fprintf(stderr, "Failed to close %s, %s\n", argv[1], strerror(errno));
  }
}

/***************/
/* _bufferTest */
/***************/
static void _bufferTest(streamIn_t *streamInp, char **argv) {
  streamInOption_t streamInOption;
  static const char *buffer = "1234abcdABCD";
  myReadData_t     myReadData;
  size_t           indexBufferi;
  char             *charArrayp;
  size_t           bytesInBuffer;

  fprintf(stderr, "Buffer test\n");
  fprintf(stderr, "-----------\n");

  myReadData.buffer = (char *) buffer;
  myReadData.firstb = STREAMIN_BOOL_TRUE;

  if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionDefaultb failure\n");
    return;
  }
  streamInOption.bufMaxSizei = 2;
  streamInOption.logLevelWantedi = STREAMIN_LOGLEVEL_TRACE;
  streamInOption.readCallbackp = &_readBufferCallback;
  streamInOption.readCallbackUserDatap = &myReadData;
  if (streamIn_optionb(streamInp, &streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionb failure\n");
    return;
  }

  while (streamIn_nextBufferb(streamInp, &indexBufferi, &charArrayp, &bytesInBuffer)) {
    char *s = malloc(bytesInBuffer + 1);
    if (s != NULL) {
      memcpy(s, charArrayp, bytesInBuffer);
      s[bytesInBuffer] = '\0';
      fprintf(stderr, "%s\n", s);
      free(s);
    }
    if (indexBufferi % 2 == 1) {
      streamIn_doneBufferb(streamInp, -1);
    }
  }

  streamIn_doneBufferb(streamInp, 0);
}

/*********************/
/* _readFileCallback */
/*********************/
static streamInBool_t _readFileCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *charArrayp, char **charManagedArrayp) {
  myReadData_t *myReadDatap = (myReadData_t *) datavp;
  int      n;

  n = READ(myReadDatap->fd, charArrayp, wantedBytesi);
  if (n <= 0) {
    if (n < 0) {
      perror("read");
    }
    n = 0;
  }

  *gotBytesip = n;
  myReadDatap->offseti = LSEEK(myReadDatap->fd, 0, SEEK_CUR);

  return STREAMIN_BOOL_TRUE;
}

/***********************/
/* _readBufferCallback */
/***********************/
static streamInBool_t _readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *charArrayp, char **charManagedArrayp) {
  myReadData_t *myReadDatap = (myReadData_t *) datavp;

  if (myReadDatap->firstb == STREAMIN_BOOL_TRUE) {
    *gotBytesip = strlen(myReadDatap->buffer) + 1;
    *charManagedArrayp = myReadDatap->buffer;
    myReadDatap->firstb = STREAMIN_BOOL_FALSE;
  } else {
    *gotBytesip = 0;
  }

  return STREAMIN_BOOL_TRUE;
}
