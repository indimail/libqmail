/*
 * $Log: sig_catch.c,v $
 * Revision 1.6  2025-01-21 22:19:54+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.5  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:30:22+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:23:04+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <signal.h>
#include "sig.h"
#include "hassgact.h"

void
sig_catch(int sig, void (*f) (int))
{
#ifdef HASSIGACTION
	struct sigaction sa;
	sa.sa_handler = f;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(sig, &sa, (struct sigaction *) 0);
#else
	signal(sig, f);	/*- won't work under System V, even nowadays---dorks */
#endif
}

void
getversion_sig_catch_c()
{
	const char     *x = "$Id: sig_catch.c,v 1.6 2025-01-21 22:19:54+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
