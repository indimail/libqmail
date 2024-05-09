/*
 * $Log: fifo.c,v $
 * Revision 1.5  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2022-10-18 20:00:50+05:30  Cprogrammer
 * converted proto to ansic
 *
 * Revision 1.3  2004-10-22 20:25:05+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.2  2004-07-17 21:18:48+05:30  Cprogrammer
 * added RCS log
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include "hasmkffo.h"
#include "fifo.h"

#ifdef HASMKFIFO
int
fifo_make(const char *fn, mode_t mode)
{
	return mkfifo(fn, mode);
}
#else
int
fifo_make(const char *fn, mode_t mode)
{
	return mknod(fn, S_IFIFO | mode, 0);
}
#endif

void
getversion_fifo_c()
{
	const char     *x = "$Id: fifo.c,v 1.5 2024-05-09 23:46:54+05:30 mbhangui Exp mbhangui $";

	x++;
}
