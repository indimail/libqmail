/*
 * $Log: sig_int.c,v $
 * Revision 1.4  2025-01-21 22:20:11+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.1  2016-03-31 16:13:57+05:30  Cprogrammer
 * Initial revision
 *
 *
 */
#include <signal.h>
#include "sig.h"

void
sig_intblock()
{
	sig_block(SIGINT);
}

void
sig_intunblock()
{
	sig_unblock(SIGINT);
}

void
sig_intcatch(void (*f) (int))
{
	sig_catch(SIGINT, f);
}

void
sig_intdefault()
{
	sig_catch(SIGINT, SIG_DFL);
}

void
getversion_sig_int_c()
{
	const char     *x = "$Id: sig_int.c,v 1.4 2025-01-21 22:20:11+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
