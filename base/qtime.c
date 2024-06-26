/*
 * $Log: qtime.c,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2021-06-01 09:52:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "datetime.h"
#include "fmt.h"
#include "qtime.h"

typedef const char c_char;
static c_char  *daytab[7] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static c_char  *montab[12] = {
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
	const char     *x = "$Id: qtime.c,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
