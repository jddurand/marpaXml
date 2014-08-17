#include <stddef.h>
#include "internal/hash.h"
#include "xxhash-read-only/xxhash.h"

#define DEFAULT_XXH_SEED 0
#if SIZEOF_VOID_P >= 8 /* At least a 64bits target: XXH64 */
#define XXH_update(state, input, length) XXH64_update(state, input, length)
#define XXH_digest(state)                XXH64_digest(state)
#define XXH_intermediateDigest(state)    XXH64_intermediateDigest(state)
#else                  /* At maximum 32bits target: XXH32 */
#define XXH_update(state, input, length) XXH32_update(state, input, length)
#define XXH_digest(state)                XXH32_digest(state)
#define XXH_intermediateDigest(state)    XXH32_intermediateDigest(state)
#endif

static unsigned int unsignedintMax = -1;

unsigned long long int marpaXml_HashLongLong(const void *state, const void* input, unsigned long long int len) {
  void                  *ctx = (void *) state;
  char                  *p = (char *) input;
  XXH_errorcode          errorcode;
  unsigned long long int rc;

  /* We assume that if input is NULL, len is correspondingly equal to zero */
  /*
  if (input == NULL) {
    return 0;
  }
  */

  /* To avoid unnecessary malloc, the caller can provide a state */
  if (ctx == NULL) {
    ctx = XXH_init();
    if (ctx == NULL) {
      return 0;
    }
  }

  while (len >= 0) {
    if (len > unsignedintMax) {
      errorcode = XXH_update(ctx, (void *) p, unsignedintMax);
      if (errorcode != XXH_OK) {
	if (state == NULL) {
	  XXH_digest(ctx);  /* This will free ctx as per the doc */
	}
	return 0;
      }
      p   += unsignedintMax;
      len -= unsignedintMax;
    } else {
      errorcode = XXH_update(ctx, (void *) p, len);
      if (errorcode != XXH_OK) {
	if (state == NULL) {
	  XXH_digest(ctx);  /* This will free ctx as per the doc */
	}
	return 0;
      }
      break;
    }
  }

  if (state == NULL) {
    rc = XXH_digest(ctx);  /* This will free ctx as per the doc */
  } else {
    rc = XXH_intermediateDigest(ctx);  /* This will not free ctx */
  }

  return rc;
}

