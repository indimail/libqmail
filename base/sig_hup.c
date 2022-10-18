/*
 * $Log: sig_hup.c,v $
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:30:24+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:23:08+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <signal.h>
#include "sig.h"

void
sig_hangupblock()
{
	sig_block(SIGHUP);
}

void
sig_hangupunblock()
{
	sig_unblock(SIGHUP);
}

void
sig_hangupcatch(void (*f) ())
{
	sig_catch(SIGHUP, f);
}

void
sig_hangupdefault()
{
	sig_catch(SIGHUP, SIG_DFL);
}

void
getversion_sig_hup_c()
{
	static char    *x = "$Id: sig_hup.c,v 1.4 2022-10-18 20:00:50+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
