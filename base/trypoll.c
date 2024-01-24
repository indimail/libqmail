/*
 * $Log: trypoll.c,v $
 * Revision 1.2  2024-01-23 18:37:05+05:30  Cprogrammer
 * pass filename as argument
 *
 * Revision 1.1  2003-12-31 19:47:31+05:30  Cprogrammer
 * Initial revision
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>

int
main(int argc, char **argv)
{
	struct pollfd   x;

	x.fd = open(argv[1], O_RDONLY);
	if (x.fd == -1)
		_exit(111);
	x.events = POLLIN;
	if (poll(&x, 1, 10) == -1)
		_exit(1);
	if (x.revents != POLLIN)
		_exit(1);

	/*- XXX: try to detect and avoid poll() imitation libraries */
	_exit(0);
}
