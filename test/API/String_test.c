#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#include "API/marpaXml/String.h"

#define TESTSTRING (char *) "TestString"

void hexdump(void *mem, unsigned int len);

struct marpaXml_String_Option option = {
  MARPAXML_STRING_OPTION_ICU_DEFAULT,
  marpaXml_false,
  {NULL,
   NULL,
   MARPAXML_LOGLEVEL_TRACE
  }
};

int main(int argc, char **argv) {

  marpaXml_String_t *s = marpaXml_String_newFromAnyAndByteLengthAndCharset(TESTSTRING, strlen(TESTSTRING), NULL, &option);  /* Null byte volontarily ommited */

  fprintf(stdout, "\nUTF-8   : %d characters, %d bytes, null byte added: %s\n", marpaXml_String_getLength(s), marpaXml_String_getUtf8ByteLength(s), (marpaXml_String_getNullByteAddedb(s) == marpaXml_true) ? "yes" : "no");

  marpaXml_String_free(&s);

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
