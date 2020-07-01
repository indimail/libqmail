#include "array.h"
#include "str.h"

void array_cats0(array* to,const char* from) {
  array_catb(to,from,str_len((char *) from)+1);
}
