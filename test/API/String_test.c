#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
#include "API/marpaXml/String.h"

const char *testUtf8String = "myString";
const char *testGb2312String = "\xbe\xb2\xcc\xac\xc4\xa3\xca\xbd"; /* http://www.cprogramdevelop.com/1747404/ */

void hexdump(void *mem, unsigned int len);
void test(char *bytes, size_t byteLength, char *charset, marpaXml_String_Option_t *optionp);

struct marpaXml_String_Option option = {MARPAXML_STRING_OPTION_ICU_DEFAULT, marpaXml_false,NULL};

void test(char *origBytes, size_t origByteLength, char *origCharset, marpaXml_String_Option_t *optionp) {
  char              *p;
  size_t             byteLength;
  size_t             length;
  marpaXml_String_t *s;
  marpaXml_String_t *s2;
  marpaXml_String_t *s3;
  marpaXml_String_t *s4;
  marpaXml_String_t *s5;

  /* First with the null byte added */
  s = marpaXml_String_newFromAnyAndByteLengthAndCharset(origBytes, origByteLength, origCharset, &option);  /* Null byte volontarily ommited */

  fprintf(stdout, "\n==>UTF-8 : %ld characters, %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s), (unsigned long) marpaXml_String_getUtf8ByteLength(s), (marpaXml_String_getNullByteAddedb(s) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s), marpaXml_String_getUtf8ByteLength(s));

  p = marpaXml_String_encode(s, &byteLength, &length, (char *) "UTF-8", &option);
  fprintf(stdout, "\n-->UTF-8  : %ld characters, %ld bytes\n", (unsigned long) length, (unsigned long) byteLength);
  hexdump(p, byteLength);
  free(p);

  p = marpaXml_String_encode(s, &byteLength, &length, (char *) "UCS-2", &option);
  fprintf(stdout, "\n-->UCS-2  : %ld characters, %ld bytes\n", (unsigned long) length, (unsigned long) byteLength);
  hexdump(p, byteLength);
  free(p);

  p = marpaXml_String_encode(s, &byteLength, &length, (char *) "UTF-32", &option);
  fprintf(stdout, "\n-->UTF-32  : %ld characters, %ld bytes\n", (unsigned long) length, (unsigned long) byteLength);
  hexdump(p, byteLength);
  free(p);

  p = marpaXml_String_encode(s, &byteLength, &length, (char *) "GB2312", &option);
  fprintf(stdout, "\n-->GB2312  : %ld characters, %ld bytes\n", (unsigned long) length, (unsigned long) byteLength);
  hexdump(p, byteLength);
  free(p);

  s2 = marpaXml_String_clone(s);
  fprintf(stdout, "\n   Clone : %ld characters, %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s2), (unsigned long) marpaXml_String_getUtf8ByteLength(s2), (marpaXml_String_getNullByteAddedb(s2) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s2), marpaXml_String_getUtf8ByteLength(s2));

  marpaXml_String_cat(s, s2);
  fprintf(stdout, "\n   Cat : %ld characters, %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s), (unsigned long) marpaXml_String_getUtf8ByteLength(s), (marpaXml_String_getNullByteAddedb(s) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s), marpaXml_String_getUtf8ByteLength(s));

  s3 = marpaXml_String_newFromValidUTF8(marpaXml_String_getUtf8(s), marpaXml_String_getUtf8ByteLength(s), marpaXml_String_getLength(s), &option);
  fprintf(stdout, "\nfromValidUtf8: %ld characters (specified), %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s3), (unsigned long) marpaXml_String_getUtf8ByteLength(s3), (marpaXml_String_getNullByteAddedb(s3) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s3), marpaXml_String_getUtf8ByteLength(s3));

  s4 = marpaXml_String_newFromValidUTF8(marpaXml_String_getUtf8(s), marpaXml_String_getUtf8ByteLength(s), 0, &option);
  fprintf(stdout, "\nfromValidUtf8: %ld characters (unspecified), %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s4), (unsigned long) marpaXml_String_getUtf8ByteLength(s4), (marpaXml_String_getNullByteAddedb(s4) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s4), marpaXml_String_getUtf8ByteLength(s4));

  s5 = marpaXml_String_newFromValidUTF8(marpaXml_String_getUtf8(s), marpaXml_String_getUtf8ByteLength(s) - 1, 0, &option);
  fprintf(stdout, "\nfromValidUtf8 without the null byte: %ld characters (unspecified), %ld bytes, null byte added: %s\n", (unsigned long) marpaXml_String_getLength(s5), (unsigned long) marpaXml_String_getUtf8ByteLength(s5), (marpaXml_String_getNullByteAddedb(s5) == marpaXml_true) ? "yes" : "no");
  hexdump(marpaXml_String_getUtf8(s5), marpaXml_String_getUtf8ByteLength(s5));

  marpaXml_String_free(&s);
  marpaXml_String_free(&s2);
  marpaXml_String_free(&s3);
  marpaXml_String_free(&s4);
  marpaXml_String_free(&s5);
}

int main(int argc, char **argv) {

  /* First with the null byte added, then without */

  fprintf(stdout, "*** Origin: UTF-8 string with no charset hint\n");
  fprintf(stdout, "*********************************************\n");
  test((char*) testUtf8String, strlen(testUtf8String)    , NULL, &option);
  test((char *)testUtf8String, strlen(testUtf8String) + 1, NULL, &option);

  fprintf(stdout, "*** Origin: UTF-8 string with charset hint\n");
  fprintf(stdout, "******************************************\n");
  test((char*) testUtf8String, strlen(testUtf8String)    , (char *) "UTF-8", &option);
  test((char *)testUtf8String, strlen(testUtf8String) + 1, (char *) "UTF-8", &option);

  fprintf(stdout, "*** Origin: GB2312 string with no charset hint\n");
  fprintf(stdout, "**********************************************\n");
  test((char*) testGb2312String, strlen(testGb2312String), NULL, &option);

  fprintf(stdout, "*** Origin: GB2312 string with charset hint\n");
  fprintf(stdout, "*******************************************\n");
  test((char*) testGb2312String, strlen(testGb2312String), (char*) "GB2312", &option);

  return 0;
}

/* From http://grapsus.net/blog/post/Hexadecimal-dump-in-C */
#ifndef HEXDUMP_COLS
#define HEXDUMP_COLS 8
#endif
 
void hexdump(void *mem, unsigned int len)
{
        unsigned int i, j;
        int c;
        
        for(i = 0; i < len + ((len % HEXDUMP_COLS) ? (HEXDUMP_COLS - len % HEXDUMP_COLS) : 0); i++)
        {
                /* print offset */
                if(i % HEXDUMP_COLS == 0)
                {
                        printf("0x%06x: ", i);
                }
 
                /* print hex data */
                if(i < len)
                {
                        printf("%02x ", 0xFF & ((char*)mem)[i]);
                }
                else /* end of block, just aligning for ASCII dump */
                {
                        printf("   ");
                }
                
                /* print ASCII dump */
                if(i % HEXDUMP_COLS == (HEXDUMP_COLS - 1))
                {
                        for(j = i - (HEXDUMP_COLS - 1); j <= i; j++)
                        {
                                if(j >= len) /* end of block, not really printing */
                                {
                                        putchar(' ');
                                }
                                else if(((c = ((char*)mem)[j]) <= 255) && c >= 0 && isprint(((char*)mem)[j])) /* printable char */
                                {
                                        putchar(0xFF & ((char*)mem)[j]);        
                                }
                                else /* other char */
                                {
                                        putchar('.');
                                }
                        }
                        putchar('\n');
                }
        }
}
