/*
 * $Log: datetime.h,v $
 * Revision 1.4  2021-06-10 10:49:57+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.3  2004-10-11 13:52:00+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:59:47+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef DATETIME_H
#define DATETIME_H

struct datetime
{
	int             hour;
	int             min;
	int             sec;
	int             wday;
	int             mday;
	int             yday;
	int             mon;
	int             year;
};

typedef long    datetime_sec;

void            datetime_tai(struct datetime *, datetime_sec);
datetime_sec    datetime_untai(const struct datetime *);

#endif
