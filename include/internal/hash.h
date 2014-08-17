#ifndef MARPAXML_INTERNAL_HASH_H
#define MARPAXML_INTERNAL_HASH_H

#include "internal/config.h"

#define DEFAULT_XXH_SEED 0
#if SIZEOF_VOID_P >= 8 /* At least a 64bits target: XXH64 */
#define XXH_init()                       XXH64_init(DEFAULT_XXH_SEED)
#else                  /* At maximum 32bits target: XXH32 */
#define XXH_init()                       XXH32_init(DEFAULT_XXH_SEED)
#endif

unsigned long long int marpaXml_HashLongLong(const void *state, const void* input, unsigned long long int len);

#endif /* MARPAXML_INTERNAL_HASH_H */
