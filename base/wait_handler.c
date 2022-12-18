/*
 * $Log: wait_handler.c,v $
 * Revision 1.1  2022-12-18 13:38:05+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <signal.h>
#include "wait.h"

int
wait_handler(int wstat, int *sig)
{
	if (wait_stopped(wstat) || wait_continued(wstat)) {
		if (sig)
			*sig = wait_stopped(wstat) ? wait_stopsig(wstat) : SIGCONT;
		return 0;
	} else
	if (wait_signaled(wstat)) {
		if (sig)
			*sig = wait_termsig(wstat);
		return 1;
	} else
	if (wait_exited(wstat)) {
		if (sig)
			*sig = 0;
		return (wait_exitcode(wstat));
	}
	if (sig)
		*sig = -1;
	return -1;
}

void
getversion_wait_handler_c()
{
	static char    *x = "$Id: wait_handler.c,v 1.1 2022-12-18 13:38:05+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
