/*
 * $Id: tcpremoteip.c,v 1.2 2024-05-09 23:49:23+05:30 mbhangui Exp mbhangui $
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#include "strerr.h"
#include "tcpremoteip.h"

const char     *
tcpremoteip(int s)
{
#ifdef ENABLE_IPV6
	static char     addrBuf[INET6_ADDRSTRLEN];
	struct sockaddr_storage sa = {0};
#else
	struct sockaddr sa = {0};
	struct sockaddr_in *sin = (struct sockaddr_in *) (&sa);
#endif
	int             r, dummy = sizeof(sa);

	if ((r = getpeername(s, (struct sockaddr *) &sa, (socklen_t *) &dummy)) == -1)
		return ((char *) 0);
#ifdef ENABLE_IPV6
	if (((struct sockaddr *) &sa)->sa_family == AF_INET) {
		return (char *) inet_ntop(AF_INET,
			(void *) &((struct sockaddr_in *) &sa)->sin_addr, addrBuf,
			INET_ADDRSTRLEN);
	} else
	if (((struct sockaddr *)&sa)->sa_family == AF_INET6) {
		return inet_ntop(AF_INET6,
			(void *) &((struct sockaddr_in6 *) &sa)->sin6_addr, addrBuf,
			INET6_ADDRSTRLEN);
	} else
	if (((struct sockaddr *) &sa)->sa_family == AF_UNSPEC)
		return "::1";
#else
	if (((struct sockaddr *) sin)->sa_family == AF_INET)
		return inet_ntoa(sin->sin_addr);
	else
	if (((struct sockaddr *) sin)->sa_family == AF_UNSPEC)
		return "127.0.0.1";
#endif
	return ((char *) 0);
}

void
getversion_tcpremoteip_c()
{
	const char     *x = "$Id: tcpremoteip.c,v 1.2 2024-05-09 23:49:23+05:30 mbhangui Exp mbhangui $";

	x++;
}

/*
 * $Log: tcpremoteip.c,v $
 * Revision 1.2  2024-05-09 23:49:23+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.1  2023-06-28 12:29:43+05:30  Cprogrammer
 * Initial revision
 *
 */
