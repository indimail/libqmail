/*
 * $Log: now.c,v $
 * Revision 1.5  2025-10-03 16:02:35+05:30  Cprogrammer
 * fixed datatype
 *
 * Revision 1.4  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2004-10-22 20:27:44+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:19:58+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <time.h>
#include "datetime.h"
#include "now.h"

datetime_sec
now()
{
	return time((time_t *) NULL);
}

void
getversion_now_c()
{
	const char     *x = "$Id: now.c,v 1.5 2025-10-03 16:02:35+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
