/*
 * $Id: allwrite.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $
 */
#include <unistd.h>
#include <sys/types.h>
#include "error.h"

ssize_t
allwrite(int fd, const char *buf, size_t len)
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
	const char     *x = "$Id: allwrite.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: allwrite.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2023-01-02 19:47:18+05:30  Cprogrammer
 * Initial revision
 *
 */
