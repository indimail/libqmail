/*
 * $Log: scan_double.c,v $
 * Revision 1.2  2019-07-18 09:55:33+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

#ifndef lint
static char     rcsid[] = "$Id: scan_double.c,v 1.2 2019-07-18 09:55:33+05:30 Cprogrammer Exp mbhangui $";
#endif

#ifdef __GNUC__
static inline int isdigit(int c) { return (c>='0' && c<='9'); }
#else
#include <ctype.h>
#endif

unsigned int scan_double(const char *in, double *dest) {
  double d=0;
  register const char *c=in;
  char neg=0;
  switch (*c) {
  case '-': neg=1;
  case '+': c++; break;
  default: break;
  }
  while (isdigit(*c)) {
    d=d*10+(*c-'0');
    ++c;
  }
  if (*c=='.') {
    double factor=.1;
    while (isdigit(*++c)) {
      d=d+(factor*(*c-'0'));
      factor/=10;
    }
  }
  if ((*c|32)=='e') {
    int exp=0;
    char neg=0;
    if (c[1]<'0') {
      switch (*c) {
      case '-': neg=1;
      case '+': c++; break;
      default:
	d=0;
	c=in;
	goto done;
      }
    }
    while (isdigit(*++c))
      exp=exp*10+(*c-'0');
    if (neg)
      while (exp) {	/* XXX: this introduces rounding errors */
	d/=10; --exp;
      }
    else 
      while (exp) {	/* XXX: this introduces rounding errors */
	d*=10; --exp;
      }
  }
done:
  *dest=(neg?-d:d);
  return (c-in);
}

void
getversion_scan_double_c()
{
	static char    *x = "$Id: scan_double.c,v 1.2 2019-07-18 09:55:33+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
