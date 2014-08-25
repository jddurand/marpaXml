#ifndef MARPAXML_STRING_H
#define MARPAXML_STRING_H

#include "marpaXml/cplus.h"

CLASS_TYPEDEF(marpaXml_String);

CLASS(marpaXml_String)
  unsigned char                *_utf8;            /* Internal representation: null terminated UTF-8 */
  unsigned long long int        _byteLength;      /* Internal representation: byte length, including the null byte */
  unsigned long long int        _length;          /* Internal representation: character length, not including the null character (== null byte) */
METHODS
  marpaXml_String_t           marpaXml_String_new(void);       /* Creates an empty string */
  marpaXml_String_t           marpaXml_String_newFromUTF8(unsigned char *utf8);  /* Assumes null terminated */
  marpaXml_String_t           marpaXml_String_newFromUTF8AndByteLength(char *utf8, unsigned long long int byteLength);
  marpaXml_String_t           marpaXml_String_newFromAnyAndByteLengthAndCharset(char *bytes, unsigned long long int byteLength, char *charset);
  unsigned char               marpaXml_String_getUtf8();
  unsigned long long int      marpaXml_String_getByteLength();
  unsigned long long int      marpaXml_String_getLength();
  void                       *marpaXml_String_encode(unsigned long long int *byteLengthp, unsigned long long int *lengthp, char *charset);  /* Convert to any charset: user will have to free it */
  void                        marpaXml_String_free(CLASS_TYPE(marpaXml_String) me);
END_CLASS

#endif /* MARPAXML_STRING_H */
