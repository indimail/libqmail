/*
 * $Log: fmt_plusminus.c,v $
 * Revision 1.2  2019-07-18 10:08:29+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:41:07+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int fmt_plusminus(char *dest,int i)
{
  if (i) {
    if (dest) *dest=(i>=0?'+':'-');
    return 1;
  }
  return 0;
}

void
getversion_fmt_plusminus_c()
{
	static char    *x = "$Id: fmt_plusminus.c,v 1.2 2019-07-18 10:08:29+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
