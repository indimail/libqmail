/*
 * $Log: qtime.c,v $
 * Revision 1.1  2021-06-01 09:52:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "datetime.h"
#include "fmt.h"
#include "qtime.h"

static char    *daytab[7] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static char    *montab[12] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static char     result[30];

char           *
qtime(datetime_sec t)
{
	struct datetime dt;
	unsigned int    len;

	datetime_tai(&dt, t);
	len = 0;
	len += fmt_str(result + len, daytab[dt.wday]);
	result[len++] = ' ';
	len += fmt_str(result + len, montab[dt.mon]);
	result[len++] = ' ';
	len += fmt_uint0(result + len, dt.mday, 2);
	result[len++] = ' ';
	len += fmt_uint0(result + len, dt.hour, 2);
	result[len++] = ':';
	len += fmt_uint0(result + len, dt.min, 2);
	result[len++] = ':';
	len += fmt_uint0(result + len, dt.sec, 2);
	result[len++] = ' ';
	len += fmt_uint(result + len, 1900 + dt.year);
	result[len++] = '\n';
	result[len++] = 0;
	return result;
}

void
getversion_qtime_c()
{
	static char    *x = "$Id: qtime.c,v 1.1 2021-06-01 09:52:27+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
