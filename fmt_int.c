#include "fmt.h"

unsigned int fmt_int(char *dest, int i)
{
	if (i < 0) {
		if (dest)
			*dest++='-';
		return (fmt_uint(dest, (unsigned int) -i) + 1);
	} else
	return (fmt_uint(dest, (unsigned int) i));
}
