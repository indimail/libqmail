/*
 * $Log: tryulong64.c,v $
 * Revision 1.2  2024-04-29 15:41:06+05:30  Cprogrammer
 * fixed compiler warning/error
 *
 * Revision 1.1  2004-05-14 00:45:23+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <unistd.h>
int
main()
{
	unsigned long   u;
	u = 1;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	u += u;
	if (!u)
		_exit(1);
	_exit(0);
}
