/*
 * $Log: fmt_plusminus.c,v $
 * Revision 1.1  2019-06-24 21:41:07+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

#ifndef lint
static char     rcsid[] = "$Id: fmt_plusminus.c,v 1.1 2019-06-24 21:41:07+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int fmt_plusminus(char *dest,int i) {
  if (i) {
    if (dest) *dest=(i>=0?'+':'-');
    return 1;
  }
  return 0;
}
