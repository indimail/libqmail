/*
 * $Log: fmt_minus.c,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2019-07-18 10:08:21+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:40:59+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int fmt_minus(char *dest,int i) {
  if (i<0) {
    if (dest) *dest='-';
    return 1;
  }
  return 0;
}

void
getversion_fmt_minus_c()
{
	const char     *x = "$Id: fmt_minus.c,v 1.3 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
