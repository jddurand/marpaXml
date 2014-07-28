#include <iconv.h>
int main(){
  iconv_t conv = iconv_open(NULL, NULL);
  return 0;
}

