/*
 * $Log: sig_block.c,v $
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:30:20+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:22:58+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void
sig_block(int sig)
{
#ifdef HASSIGPROCMASK
	sigset_t        ss;
	sigemptyset(&ss);
	sigaddset(&ss, sig);
	sigprocmask(SIG_BLOCK, &ss, (sigset_t *) 0);
#else
	sigblock(1 << (sig - 1));
#endif
}

void
sig_unblock(int sig)
{
#ifdef HASSIGPROCMASK
	sigset_t        ss;
	sigemptyset(&ss);
	sigaddset(&ss, sig);
	sigprocmask(SIG_UNBLOCK, &ss, (sigset_t *) 0);
#else
	sigsetmask(sigsetmask(~0) & ~(1 << (sig - 1)));
#endif
}

void
sig_blocknone()
{
#ifdef HASSIGPROCMASK
	sigset_t        ss;
	sigemptyset(&ss);
	sigprocmask(SIG_SETMASK, &ss, (sigset_t *) 0);
#else
	sigsetmask(0);
#endif
}

void
getversion_sig_block_c()
{
	const char     *x = "$Id: sig_block.c,v 1.4 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
