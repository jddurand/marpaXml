#include "internal/grammar/xml_1_0.h"

int main(int argc, char **argv) {
  xml_1_0_t *xml_1_0p;

  xml_1_0p = xml_1_0_newp(NULL);
  if (xml_1_0p != NULL) {
    xml_1_0_destroyv(&xml_1_0p);
  }

  return 0;
}
