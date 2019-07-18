/*
 * $Log: fmt_ulonglong.c,v $
 * Revision 1.2  2019-07-18 10:08:32+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:41:11+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

unsigned int fmt_ulonglong(char *dest,unsigned long long int i)
{
  register unsigned long len;
  unsigned long long tmp,len2;
  /* first count the number of bytes needed */
  for (len=1, tmp=i; tmp>9; ++len) tmp/=10;
  if (dest)
    for (tmp=i, dest+=len, len2=len+1; --len2; tmp/=10)
      *--dest = (char)((tmp%10)+'0');
  return len;
}

void
getversion_fmt_ulonglong_c()
{
	static char    *x = "$Id: fmt_ulonglong.c,v 1.2 2019-07-18 10:08:32+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
