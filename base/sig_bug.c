/*
 * $Log: sig_bug.c,v $
 * Revision 1.6  2025-01-21 22:19:51+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:30:21+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:23:01+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <signal.h>
#include "sig.h"

void
sig_bugcatch(void (*f) (int))
{
	sig_catch(SIGILL, f);
	sig_catch(SIGABRT, f);
	sig_catch(SIGFPE, f);
	sig_catch(SIGBUS, f);
	sig_catch(SIGSEGV, f);
#ifdef SIGSYS
	sig_catch(SIGSYS, f);
#endif
#ifdef SIGEMT
	sig_catch(SIGEMT, f);
#endif
}

void
getversion_sig_bug_c()
{
	const char     *x = "$Id: sig_bug.c,v 1.6 2025-01-21 22:19:51+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
