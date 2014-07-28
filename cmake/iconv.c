#include <iconv.h>
int main(){
  iconv_t conv = 0;
#ifdef ICONV_SECOND_ARGUMENT_IS_CONST
  const char* in = 0;
#else
  char* in = 0;
#endif
  size_t ilen = 0;
  char* out = 0;
  size_t olen = 0;

  iconv(conv, &in, &ilen, &out, &olen);

  return 0;
}

