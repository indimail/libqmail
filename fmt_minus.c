/*
 * $Log: fmt_minus.c,v $
 * Revision 1.1  2019-06-24 21:40:59+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "fmt.h"

#ifndef lint
static char     rcsid[] = "$Id: fmt_minus.c,v 1.1 2019-06-24 21:40:59+05:30 Cprogrammer Exp mbhangui $";
#endif

unsigned int fmt_minus(char *dest,int i) {
  if (i<0) {
    if (dest) *dest='-';
    return 1;
  }
  return 0;
}
