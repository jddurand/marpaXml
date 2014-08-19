#ifndef MARPAXML_INTERNAL_HASH_H
#define MARPAXML_INTERNAL_HASH_H

void                  *marpaXml_HashInit(void);
unsigned long long int marpaXml_HashLongLong(const void *state, const void* input, unsigned long long int len);

#endif /* MARPAXML_INTERNAL_HASH_H */
