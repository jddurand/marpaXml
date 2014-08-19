#ifndef MARPAXML_INTERNAL_HASH_H
#define MARPAXML_INTERNAL_HASH_H

typedef enum marpaXml_Hash_Boolean {
  MARPAXML_HASH_FALSE = 0,
  MARPAXML_HASH_TRUE
} marpaXml_Hash_Boolean_t;

marpaXml_Hash_Boolean_t marpaXml_HashInit(void **ctxpp);
marpaXml_Hash_Boolean_t marpaXml_HashLongLong(const void *state, const void* input, unsigned long long int len, unsigned long long int *hashp);
marpaXml_Hash_Boolean_t marpaXml_HashFree(void **ctxpp);

#endif /* MARPAXML_INTERNAL_HASH_H */
