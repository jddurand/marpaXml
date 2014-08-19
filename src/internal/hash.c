#include "internal/config.h"

#include <stdlib.h>
#include <stddef.h>
#include "internal/hash.h"
#include "xxhash-read-only/xxhash.h"

#define DEFAULT_XXH_SEED 0
#if SIZEOF_VOID_P >= 8 /* At least a 64bits target: XXH64 */
#define XXH_init()                       XXH64_init(DEFAULT_XXH_SEED)
#define XXH_update(state, input, length) XXH64_update(state, input, length)
#define XXH_digest(state)                XXH64_digest(state)
#define XXH_intermediateDigest(state)    XXH64_intermediateDigest(state)
#define XXH_resetState(state)            XXH64_resetState(state, DEFAULT_XXH_SEED)
#else                  /* At maximum 32bits target: XXH32 */
#define XXH_init()                       XXH32_init(DEFAULT_XXH_SEED)
#define XXH_update(state, input, length) XXH32_update(state, input, (unsigned int) length)
#define XXH_digest(state)                XXH32_digest(state)
#define XXH_intermediateDigest(state)    XXH32_intermediateDigest(state)
#define XXH_resetState(state)            XXH32_resetState(state, DEFAULT_XXH_SEED)
#endif

static unsigned int unsignedintMax = -1;

marpaXml_Hash_Boolean_t marpaXml_HashInit(void **ctxpp) {
  if (ctxpp == NULL) {
    return MARPAXML_HASH_FALSE;
  } else {
    if ((*ctxpp = XXH_init()) == NULL) {
      return MARPAXML_HASH_FALSE;
    } else {
      return MARPAXML_HASH_TRUE;
    }
  }
}

marpaXml_Hash_Boolean_t marpaXml_HashLongLong(const void *state, const void* input, unsigned long long int len, unsigned long long int *hashp) {
  void                    *ctx = (void *) state;
  char                    *p = (char *) input;
  unsigned long long int   hash;
  marpaXml_Hash_Boolean_t  rc;

  /* To avoid unnecessary malloc, the caller can provide a state */
  if (ctx == NULL) {
    ctx = XXH_init();
    if (ctx == NULL) {
      return MARPAXML_HASH_FALSE;
    }
  }

  while (len >= 0) {
    if (len > unsignedintMax) {
      if (XXH_update(ctx, (void *) p, unsignedintMax) != XXH_OK) {
        return MARPAXML_HASH_FALSE;
      }
      p   += unsignedintMax;
      len -= unsignedintMax;
    } else {
      if (XXH_update(ctx, (void *) p, len) != XXH_OK) {
        return MARPAXML_HASH_FALSE;
      }
      break;
    }
  }

  if (state == NULL) {
    hash = XXH_digest(ctx);  /* This will free ctx as per the doc */
    rc = MARPAXML_HASH_TRUE;
  } else {
    hash = XXH_intermediateDigest(ctx);  /* This will not free ctx */
    if (XXH_resetState(ctx) == XXH_OK) {
      rc = MARPAXML_HASH_TRUE;
    } else {
      rc = MARPAXML_HASH_FALSE;
    }
  }

  if (rc == MARPAXML_HASH_TRUE) {
    if (hashp != NULL) {
      *hashp = hash;
    }
  }

  return rc;
}

marpaXml_Hash_Boolean_t marpaXml_HashFree(void **ctxpp) {
  if (ctxpp == NULL || *ctxpp == NULL) {
    return MARPAXML_HASH_FALSE;
  }
  free(*ctxpp);
  *ctxpp = NULL;
  return MARPAXML_HASH_TRUE;
}

