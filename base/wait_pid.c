/*
 * $Log: wait_pid.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:32:12+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:25:07+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <sys/wait.h>
#include "error.h"
#include "haswaitp.h"

#ifdef HASWAITPID

int
wait_pid(int *wstat, int pid)
{
	int             r;

	do
		r = waitpid(pid, wstat, 0);
	while ((r == -1) && (errno == error_intr));
	return r;
}

#else

/*
 * XXX untested 
 * XXX breaks down with more than two children 
 */
static int      oldpid = 0;
static int      oldwstat;		/*- defined if(oldpid) */

int
wait_pid(int *wstat, int pid)
{
	int             r;

	if (pid == oldpid)
	{
		*wstat = oldwstat;
		oldpid = 0;
		return pid;
	}

	do
	{
		r = wait(wstat);
		if ((r != pid) && (r != -1))
		{
			oldwstat = *wstat;
			oldpid = r;
			continue;
		}
	}
	while ((r == -1) && (errno == error_intr));
	return r;
}

#endif

void
getversion_wait_pid_c()
{
	const char     *x = "$Id: wait_pid.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
