/*
 * $Log: qtime.h,v $
 * Revision 1.2  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2021-06-01 09:52:43+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef MYCTIME_H
#define MYCTIME_H

#ifndef	lint
static const char sccsidmyctimeh[] = "$Id: qtime.h,v 1.2 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";
#endif

#include "datetime.h"

char           *qtime(datetime_sec);

#endif
