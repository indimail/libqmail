/*
 * $Log: taia_now.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2020-07-07 09:12:01+05:30  Cprogrammer
 * renamed variable now to tmval
 *
 * Revision 1.2  2004-10-22 20:31:30+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.1  2004-09-19 18:53:46+05:30  Cprogrammer
 * Initial revision
 *
 */

/*- Public domain.  */

#include <sys/types.h>
#include <sys/time.h>
#include "taia.h"

void
taia_now(struct taia *t)
{
	struct timeval  tmval;
	gettimeofday(&tmval, (struct timezone *) 0);
	tai_unix(&t->sec, tmval.tv_sec);
	t->nano = 1000 * tmval.tv_usec + 500;
	t->atto = 0;
}

void
getversion_taia_now_c()
{
	const char     *x = "$Id: taia_now.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
