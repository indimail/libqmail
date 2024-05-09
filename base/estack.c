/*
 * $Log: estack.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2024-05-08 16:34:49+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "substdio.h"
#include "str.h"
#include "error.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

char           *estack(int, const char *errorst);

void
discard_stack(void)
{
	estack(-1, 0);
	return;
}

void
free_stack(void)
{
	estack(2, 0);
	return;
}

char           *
estack(int  fderr, const char *errorstr)
{
	unsigned int    len, i, tmperrno;
	static int      mylen;
	char           *ptr, *cptr;
	static char    *error_store;
	static char     sserrbuf[512];
	substdio       sserr;

	if (fderr > -1)
		substdio_fdbuf(&sserr, write, fderr, sserrbuf, sizeof(sserrbuf));
	if (errorstr && *errorstr) {
		len = str_len((char *) errorstr) + 1; /* string + 1 null byte */
		if (!(error_store = realloc(error_store, mylen + len + 1))) {	/*- The man page is wierd on Mac OS */
			tmperrno = errno;
			if (substdio_puts(&sserr, (char *) errorstr) == -1 ||
					substdio_puts(&sserr, "estack: realloc: ") == -1 ||
					substdio_puts(&sserr, error_str(tmperrno)) == -1 ||
					substdio_puts(&sserr, "\n") == -1 ||
					substdio_flush(&sserr) == -1)
				return((char *) 0);
			return ((char *) 0);
		}
		if (!mylen && atexit(free_stack)) {
			if (substdio_puts(&sserr, "atexit: ") == -1 ||
					substdio_puts(&sserr, error_str(errno)) ||
					substdio_puts(&sserr, "\n") == -1 ||
					substdio_flush(&sserr) == -1)
				return((char *) 0);
		}
		for (ptr = (char *) errorstr, cptr = error_store + mylen;*ptr;*cptr++ = *ptr++);
		error_store[mylen + len - 1] = 0;
		mylen += len;
		return (error_store);
	} else {
		if (!error_store)
			return ((char *) 0);
		if (fderr < 0) { /*- discard all error messages stored */
			free(error_store);
			error_store = 0;
			mylen = 0;
			substdio_flush(&sserr);
			return((char *) 0);
		}
		for (ptr = error_store, i = len = 0; len < mylen; len++, ptr++) {
			if (*ptr == 0) {
				if (substdio_puts(&sserr, error_store + i))
					return((char *) 0);
				i = len + 1;
			}
		}
		free(error_store);
		error_store = 0;
		mylen = 0;
		if (substdio_flush(&sserr) == -1)
			return((char *) 0);
		return (char *) "";
	}
}

void
getversion_estack_qc()
{
	const char     *x = "$Id: estack.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
	x++; /*- No dollar for OSS/FS */
}
