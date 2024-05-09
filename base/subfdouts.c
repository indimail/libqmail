/*
 * $Id: subfdouts.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $
 */

#include <unistd.h>
#include "substdio.h"
#include "subfd.h"

char            subfd_outbufsmall[SUBSTDIO_SMALL];
static substdio it = SUBSTDIO_FDBUF(write, 1, subfd_outbufsmall, SUBSTDIO_SMALL);
substdio       *subfdoutsmall = &it;

void
getversion_subfdouts_c()
{
	const char     *x = "$Id: subfdouts.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: subfdouts.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2024-01-22 10:18:21+05:30  Cprogrammer
 * use SUBSTDIO_SMALL definition from substdio.h
 *
 * Revision 1.4  2004-10-22 20:31:06+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-22 15:39:46+05:30  Cprogrammer
 * replaced readwrite.h with unistd.h
 *
 * Revision 1.2  2004-07-17 21:24:33+05:30  Cprogrammer
 * added RCS log
 *
 */
