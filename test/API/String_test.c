#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#include "API/marpaXml/String.h"

#define TESTSTRING "TestString"

void hexdump(void *mem, unsigned int len);

int main(int argc, char **argv) {

  struct marpaXml_String_Option option = {
    MARPAXML_STRING_OPTION_ICU_DEFAULT,
    marpaXml_false,
    MARPAXML_LOGLEVEL_TRACE,
    NULL,
    NULL
  };
  size_t byteLength[6];
  size_t length[6];

  marpaXml_String_t marpaXml_String1 = marpaXml_String_new(&option);
  marpaXml_String_t marpaXml_String2 = marpaXml_String_newFromUTF8(TESTSTRING, &option);
  marpaXml_String_t marpaXml_String3 = marpaXml_String_newFromUTF8AndByteLength(TESTSTRING, sizeof(TESTSTRING), &option);
  marpaXml_String_t marpaXml_String4 = marpaXml_String_newFromUTF8AndByteLength(TESTSTRING, strlen(TESTSTRING), &option);  /* Null byte volontarily ommited */
  marpaXml_String_t marpaXml_String5 = marpaXml_String_newFromAnyAndByteLengthAndCharset(TESTSTRING, strlen(TESTSTRING), NULL, &option);  /* Null byte volontarily ommited */
  char *String6  = marpaXml_String_encode(marpaXml_String5, &(byteLength[0]), &(length[0]), "UTF-16", &option);
  char *String7  = marpaXml_String_encode(marpaXml_String5, &(byteLength[1]), &(length[1]), "UTF-16LE", &option);
  char *String8  = marpaXml_String_encode(marpaXml_String5, &(byteLength[2]), &(length[2]), "UTF-16BE", &option);
  char *String9  = marpaXml_String_encode(marpaXml_String5, &(byteLength[3]), &(length[3]), "KOI8_R", &option);
  char *String10 = marpaXml_String_encode(marpaXml_String3, &(byteLength[4]), &(length[4]), "UTF-16", &option);
  char *String11 = marpaXml_String_encode(marpaXml_String3, &(byteLength[5]), &(length[5]), "UTF-16LE", &option);

  fprintf(stdout, "\nUTF-8   : %d characters, %d bytes (input with null byte)\n", marpaXml_String_getLength(marpaXml_String3), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String3));
  hexdump(marpaXml_String_getUtf8(marpaXml_String3), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String3));
  fprintf(stdout, "UTF-16  : %d characters, %d bytes (original input with null byte)\n", length[4], byteLength[4]);
  hexdump(String10, byteLength[4]);
  fprintf(stdout, "UTF-16LE: %d characters, %d bytes (original input with null byte)\n", length[5], byteLength[5]);
  hexdump(String11, byteLength[5]);

  fprintf(stdout, "\n");
  fprintf(stdout, "UTF-8   : %d characters, %d bytes (input without null byte)\n", marpaXml_String_getLength(marpaXml_String4), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String4));
  hexdump(marpaXml_String_getUtf8(marpaXml_String4), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String4));
  fprintf(stdout, "UTF-8   : %d characters, %d bytes (input without null byte)\n", marpaXml_String_getLength(marpaXml_String5), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String5));
  hexdump(marpaXml_String_getUtf8(marpaXml_String5), marpaXml_String_getOrigUtf8ByteLength(marpaXml_String5));
  fprintf(stdout, "UTF-16  : %d characters, %d bytes\n", length[0], byteLength[0]);
  hexdump(String6, byteLength[0]);
  fprintf(stdout, "UTF-16LE: %d characters, %d bytes\n", length[1], byteLength[1]);
  hexdump(String7, byteLength[1]);
  fprintf(stdout, "UTF-16BE: %d characters, %d bytes\n", length[2], byteLength[2]);
  hexdump(String8, byteLength[2]);
  fprintf(stdout, "KOI8_R  : %d characters, %d bytes\n", length[3], byteLength[3]);
  hexdump(String9, byteLength[3]);

  marpaXml_String_free(&marpaXml_String1);
  marpaXml_String_free(&marpaXml_String2);
  marpaXml_String_free(&marpaXml_String3);
  marpaXml_String_free(&marpaXml_String4);
  marpaXml_String_free(&marpaXml_String5);
  free(String6);
  free(String7);
  free(String8);
  free(String9);
  free(String10);
  free(String11);

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
