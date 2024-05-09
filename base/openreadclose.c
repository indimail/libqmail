/* 
 * $Log: openreadclose.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2020-11-24 09:35:24+05:30  Cprogrammer
 * Initial revision
 *
 *
 * Public domain, from djbdns-1.05.
 */

#include "error.h"
#include "open.h"
#include "readclose.h"
#include "openreadclose.h"

int openreadclose(const char *fn,stralloc *sa,unsigned int bufsize)
{
  int fd;
  fd = open_read(fn);
  if (fd == -1) {
    if (errno == error_noent) return 0;
    return -1;
  }
  if (readclose(fd,sa,bufsize) == -1) return -1;
  return 1;
}

void
getversion_openreadclose_c()
{
	const char     *x = "$Id: openreadclose.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
