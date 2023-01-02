/*
 * $Id: allwrite.c,v 1.1 2023-01-02 19:47:18+05:30 Cprogrammer Exp mbhangui $
 */
#include <unistd.h>
#include <sys/types.h>
#include "error.h"

ssize_t
allwrite(int fd, char *buf, size_t len)
{
	ssize_t         w;
	size_t          total = 0;

	while (len) {
		if ((w = write(fd, buf, len)) == -1) {
			if (errno == error_intr)
				continue;
			return -1;	/*- note that some data may have been written */
		}
		if (w == 0)
			;	/*- luser's fault */
		buf += w;
		total += w;
		len -= w;
	}
	return total;
}

void
getversion_allwrite_c()
{
	static char    *x = "$Id: allwrite.c,v 1.1 2023-01-02 19:47:18+05:30 Cprogrammer Exp mbhangui $";

	x++;
}

/*
 * $Log: allwrite.c,v $
 * Revision 1.1  2023-01-02 19:47:18+05:30  Cprogrammer
 * Initial revision
 *
 */
