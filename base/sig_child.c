/*
 * $Log: sig_child.c,v $
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:30:23+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:23:06+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <signal.h>
#include "sig.h"

void
sig_childblock()
{
	sig_block(SIGCHLD);
}

void
sig_childunblock()
{
	sig_unblock(SIGCHLD);
}

void
sig_childcatch(void (*f) (int))
{
	sig_catch(SIGCHLD, f);
}

void
sig_childdefault()
{
	sig_catch(SIGCHLD, SIG_DFL);
}

void
getversion_sig_child_c()
{
	const char     *x = "$Id: sig_child.c,v 1.5 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
