/*-
 * $Log: no_of_days.c,v $
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2021-08-21 12:10:52+05:30  Cprogrammer
 * removed #ifdef HAVE_QMAIL
 *
 * Revision 1.2  2020-10-12 22:57:33+05:30  Cprogrammer
 * fixed no of days variable getting clobbered due to use of stralloc_copyb() instead of stralloc_catb()
 *
 * Revision 1.1  2019-04-20 08:16:13+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_TIME_H
#include <time.h>
#endif
#include <stralloc.h>
#include <strerr.h>
#include <fmt.h>

#ifndef	lint
const char      sccsid[] = "$Id: no_of_days.c,v 1.4 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
#endif

static void
die_nomem()
{
	strerr_warn1("no_of_days: out of memory", 0);
	_exit(111);
}

char *
no_of_days(time_t seconds)
{
	int days, hours, mins, secs;
	char            strnum[FMT_ULONG];
	static stralloc tmpbuf = {0};

	days = seconds/86400;
	hours = (seconds % 86400)/3600;
	mins = ((seconds % 86400) % 3600)/60;
	secs = ((seconds % 86400) % 3600) % 60;
	if (!stralloc_copyb(&tmpbuf, strnum, fmt_uint(strnum, days)) ||
			!stralloc_catb(&tmpbuf, " days ", 6))
		die_nomem();
	if (hours < 10 && !stralloc_append(&tmpbuf, "0"))
		die_nomem();
	if (!stralloc_catb(&tmpbuf, strnum, fmt_uint(strnum, hours)) ||
			!stralloc_catb(&tmpbuf, " Hrs ", 5))
		die_nomem();
	if (mins < 10 && !stralloc_append(&tmpbuf, "0"))
		die_nomem();
	if (!stralloc_catb(&tmpbuf, strnum, fmt_uint(strnum, mins)) ||
			!stralloc_catb(&tmpbuf, " Mins ", 6))
		die_nomem();
	if (secs < 10 && !stralloc_append(&tmpbuf, "0"))
		die_nomem();
	if (!stralloc_catb(&tmpbuf, strnum, fmt_uint(strnum, secs)) ||
			!stralloc_catb(&tmpbuf, " Secs", 5) ||
			!stralloc_0(&tmpbuf))
		die_nomem();
	return (tmpbuf.s);
}
