/*
 * $Id: subfderr.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $
 */
#include <unistd.h>
#include "substdio.h"
#include "subfd.h"

char            subfd_errbuf[SUBSTDIO_SMALL];
static substdio it = SUBSTDIO_FDBUF(write, 2, subfd_errbuf, SUBSTDIO_SMALL);
substdio       *subfderr = &it;

void
getversion_subfderr_c()
{
	const char     *x = "$Id: subfderr.c,v 1.6 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: subfderr.c,v $
 * Revision 1.6  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.5  2024-01-22 10:16:54+05:30  Cprogrammer
 * use SUBSTDIO_SMALL definition from substdio.h
 *
 * Revision 1.4  2004-10-22 20:31:03+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.3  2004-10-22 15:39:34+05:30  Cprogrammer
 * replaced readwrite.h with unistd.h
 *
 * Revision 1.2  2004-07-17 21:24:26+05:30  Cprogrammer
 * added RCS log
 *
 */
