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

const char *Shift_JIS = (const char*) "Shift_JIS";
const char *KOI8_R = "KOI8-R";
const char *UCS_2 = (const char *) "UCS-2";

static streamInBool_t _readFileCallback  (void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);
static streamInBool_t _readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp);
static void           _fileTest(streamIn_t *streamInp, streamInBool_t utf8b, streamInBool_t utf8bufb, char **argv);
static void           _bufferTest(streamIn_t *streamInp, streamInBool_t utf8b, char **argv);

#define STREAMIN_NEW(utf8b) {						\
  streamInUtf8Option_t streamInOptionUtf8;				\
  streamInUtf8_optionDefaultb(&streamInOptionUtf8);			\
  /* streamInOptionUtf8.fromEncodings = NULL; */                        \
  /* streamInOptionUtf8.fromEncodings = KOI8_R; */			\
  streamInOptionUtf8.toEncodings = UCS_2;				\
    streamInp = (utf8b == STREAMIN_BOOL_TRUE) ? streamInUtf8_newp(NULL, &streamInOptionUtf8) : streamIn_newp(NULL); \
    if (streamInp == NULL) {						\
      fprintf(stderr, ((utf8b == STREAMIN_BOOL_TRUE) ? "streamInUtf8_newp failure\n" : "streamIn_newp failure\n")); \
      return EXIT_FAILURE;						\
    }									\
}

/********/
/* main */
/********/
int main(int argc, char **argv) {
  streamIn_t      *streamInp = NULL;
  streamInBool_t   utf8bufb;
  streamInBool_t   utf8b;

  int rc = EXIT_SUCCESS;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

#ifdef _WIN32
  Sleep(10000);
#endif

  /* UTF 8 - character mode */
  STREAMIN_NEW(utf8b = STREAMIN_BOOL_TRUE);
  _fileTest(streamInp, utf8b, utf8bufb = STREAMIN_BOOL_TRUE, argv);
  streamIn_destroyv(&streamInp);

  /* UTF 8 - buffer mode */
  STREAMIN_NEW(utf8b = STREAMIN_BOOL_TRUE);
  _fileTest(streamInp, utf8b, utf8bufb = STREAMIN_BOOL_FALSE, argv);
  streamIn_destroyv(&streamInp);

  /* Byte mode - only buffer mode is available */
  STREAMIN_NEW(utf8b = STREAMIN_BOOL_FALSE);
  _fileTest(streamInp, utf8b, utf8bufb = STREAMIN_BOOL_FALSE, argv);
  streamIn_destroyv(&streamInp);

  STREAMIN_NEW(utf8b = STREAMIN_BOOL_TRUE);
  _bufferTest(streamInp, utf8b, argv);
  streamIn_destroyv(&streamInp);

  STREAMIN_NEW(utf8b = STREAMIN_BOOL_FALSE);
  _bufferTest(streamInp, utf8b, argv);
  streamIn_destroyv(&streamInp);

  return(rc);
}

/*************/
/* _fileTest */
/*************/
static void _fileTest(streamIn_t *streamInp, streamInBool_t utf8b, streamInBool_t utf8bufb, char **argv) {
  streamInOption_t streamInOption;
  int              fd;
  myReadData_t     myReadData;
  size_t           indexBufferi;
  char             *byteArrayp;
  size_t           bytesInBuffer;

  
  fprintf(stderr, "Filename test (utf8 mode: %s)\n", (utf8b == STREAMIN_BOOL_TRUE) ? "on" : "off");
  fprintf(stderr, "------------------------------\n");

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
  streamInOption.bufMaxSizei = 1;
  streamInOption.logLevelWantedi = STREAMIN_LOGLEVEL_TRACE;
  streamInOption.readCallbackp = &_readFileCallback;
  streamInOption.readCallbackUserDatap = &myReadData;
  if (streamIn_optionb(streamInp, &streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionb failure\n");
    return;
  }

  if (utf8b == STREAMIN_BOOL_TRUE) {
    size_t     lengthInBuffer;

    if (utf8bufb == STREAMIN_BOOL_TRUE) {
      fprintf(stderr, "Filename test (utf8 mode: %s): buffer-per-buffer test\n", (utf8b == STREAMIN_BOOL_TRUE) ? "on" : "off");
      while (streamInUnicode_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer, &lengthInBuffer) == STREAMIN_BOOL_TRUE) {
	int i;
	fprintf(stderr, "Buffer No %d gives encoded content of %d bytes, %d characters\n", indexBufferi, bytesInBuffer, lengthInBuffer);
	for (i = 0; i < bytesInBuffer; i++) {
	  fprintf(stderr, "0x%x\n", (unsigned char) byteArrayp[i]);
	}
	free(byteArrayp);
	if (indexBufferi % 2 == 1) {
	  streamInUnicode_doneBufferb(streamInp, -1);
	}
      }
      streamInUnicode_doneBufferb(streamInp, 0);
    } else {
      signed int currenti;

      fprintf(stderr, "Filename test (utf8 mode: %s): character-per-character test\n", (utf8b == STREAMIN_BOOL_TRUE) ? "on" : "off");
      while (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_TRUE) {
	fprintf(stdout, "0x%0x\n", currenti);
	streamInUtf8_markPreviousb(streamInp);
	streamInUtf8_doneb(streamInp);
      }
    }
  } else {
    while (streamIn_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer) == STREAMIN_BOOL_TRUE) {
      char *s = malloc(bytesInBuffer + 1);
      if (s != NULL) {
	memcpy(s, byteArrayp, bytesInBuffer);
	s[bytesInBuffer] = '\0';
	// fprintf(stderr, "%s\n", s);
	free(s);
      }
      if (indexBufferi % 2 == 1) {
	streamIn_doneBufferb(streamInp, -1);
      }
    }
    streamIn_doneBufferb(streamInp, 0);
  }

  if (fd >= 0 && CLOSE(fd) != 0) {
    fprintf(stderr, "Failed to close %s, %s\n", argv[1], strerror(errno));
  }
}

/***************/
/* _bufferTest */
/***************/
static void _bufferTest(streamIn_t *streamInp, streamInBool_t utf8b, char **argv) {
  streamInOption_t streamInOption;
  static const char *buffer = "1234abcdABCD";
  myReadData_t     myReadData;
  size_t           indexBufferi;
  char             *byteArrayp;
  size_t           bytesInBuffer;

  fprintf(stderr, "Buffer test (utf8 mode: %s)\n", (utf8b == STREAMIN_BOOL_TRUE) ? "on" : "off");
  fprintf(stderr, "-----------------------------\n");

  myReadData.buffer = (char *) buffer;
  myReadData.firstb = STREAMIN_BOOL_TRUE;

  if (streamIn_optionDefaultb(&streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionDefaultb failure\n");
    return;
  }
  streamInOption.bufMaxSizei = 1002;
  streamInOption.logLevelWantedi = STREAMIN_LOGLEVEL_TRACE;
  streamInOption.readCallbackp = &_readBufferCallback;
  streamInOption.readCallbackUserDatap = &myReadData;
  if (streamIn_optionb(streamInp, &streamInOption) == STREAMIN_BOOL_FALSE) {
    fprintf(stderr, "streamIn_optionb failure\n");
    return;
  }

  while (streamIn_nextBufferb(streamInp, &indexBufferi, &byteArrayp, &bytesInBuffer)) {
    char *s = malloc(bytesInBuffer + 1);
    if (s != NULL) {
      memcpy(s, byteArrayp, bytesInBuffer);
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
static streamInBool_t _readFileCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
  myReadData_t *myReadDatap = (myReadData_t *) datavp;
  int      n;

  n = READ(myReadDatap->fd, byteArrayp, wantedBytesi);
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
static streamInBool_t _readBufferCallback(void *datavp, size_t wantedBytesi, size_t *gotBytesip, char *byteArrayp, char **charManagedArrayp) {
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
