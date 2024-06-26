/*
 * $Log: tcpbind.c,v $
 * Revision 1.4  2024-05-09 23:49:23+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2024-02-08 10:32:24+05:30  Cprogrammer
 * remove unlink of unix domain socket
 *
 * Revision 1.2  2022-12-06 08:31:31+05:30  Cprogrammer
 * display servicename, hostname in getaddrinfo error
 *
 * Revision 1.1  2022-05-10 19:49:51+05:30  Cprogrammer
 * Initial revision
 *
 */

#ifndef	lint
static char     sccsid[] = "$Id: tcpbind.c,v 1.4 2024-05-09 23:49:23+05:30 mbhangui Exp mbhangui $";
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifdef HAVE_SYS_UN_H
#include <sys/un.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#include "byte.h"
#include "error.h"
#include "strerr.h"
#include "scan.h"
#include "qdirname.h"

int
tcpbind(char *hostname, char *servicename, int backlog)
{
	int             listenfd; /*- listen socket descriptor */
#ifdef ENABLE_IPV6
	struct addrinfo hints, *res, *res0;
	int             bind_fail = -1;
#else
#ifdef HAVE_IN_ADDR_T
	in_addr_t       inaddr;
#else
	unsigned long   inaddr;
#endif
	struct sockaddr_in localinaddr;	/*- for local socket address */
	struct servent *sp;	/*- pointer to service information */
	struct hostent *hp;
#endif /*- #ifdef ENABLE_IPV6 */
#ifdef HAVE_SYS_UN_H
	struct sockaddr_un localunaddr;	/*- for local socket address */
	char           *dir;
#endif
	int             idx;
	struct linger cflinger;

	/*- Set up address structure for the listen socket. */
	cflinger.l_onoff = 1;
	cflinger.l_linger = 60;
#ifdef HAVE_SYS_UN_H
	if ((dir = qdirname(hostname)) && !access(dir, F_OK)) {
		byte_zero((char *) &localunaddr, sizeof(struct sockaddr_un));
		if ((listenfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
			return (-1);
		idx = 1;
		if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *) &idx, sizeof(idx)) < 0) {
			close(listenfd);
			return (-1);
		}
		if (setsockopt(listenfd, SOL_SOCKET, SO_LINGER, (char *) &cflinger, sizeof (struct linger)) == -1) {
			close(listenfd);
			return (-1);
		}
    	localunaddr.sun_family = AF_UNIX;
    	byte_copy(localunaddr.sun_path, sizeof(localunaddr.sun_path), hostname);
		if (bind(listenfd, (struct sockaddr *) &localunaddr, sizeof(localunaddr)) == -1) {
			close(listenfd);
			return (-1);
		}
		if (listen(listenfd, backlog) == -1) {
			close(listenfd);
			return (-1);
		}
		return (listenfd);
	}
#endif
#ifdef ENABLE_IPV6
	byte_zero((char *) &hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((idx = getaddrinfo(hostname, servicename, &hints, &res0))) {
		strerr_warn6("tcpbind: getaddrinfo: [", servicename, "@", hostname, "]: ", (char *) gai_strerror(idx), 0);
		return (-1);
	}
	listenfd = -1;
	for (res = res0; res; res = res->ai_next) {
		if ((listenfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
			freeaddrinfo(res0);
			return (-1);
		}
		idx = 1;
		if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *) &idx, sizeof (int)) == -1) {
			close(listenfd);
			freeaddrinfo(res0);
			return (-1);
		}
		if (setsockopt(listenfd, SOL_SOCKET, SO_LINGER, (char *) &cflinger, sizeof (struct linger)) == -1) {
			close(listenfd);
			freeaddrinfo(res0);
			return (-1);
		}
		if ((bind_fail = bind(listenfd, res->ai_addr, res->ai_addrlen)) == 0)
			break;
		close(listenfd);
	} /*- for (res = res0; res; res = res->ai_next) */
	if (bind_fail == -1) {
		bind_fail = errno;
		freeaddrinfo(res0);
		errno = bind_fail;
		return (-1);
	}
	freeaddrinfo(res0);
#else
	byte_zero((char *) &localinaddr, sizeof(struct sockaddr_in));
	localinaddr.sin_family = AF_INET;
	/*- It's a dotted decimal */
	if ((inaddr = inet_addr(hostname)) != INADDR_NONE)
		localinaddr.sin_addr.s_addr = inaddr;
	else
	if ((hp = gethostbyname(hostname)) != NULL)
		byte_copy((char *) &localinaddr.sin_addr, hp->h_length, hp->h_addr);
	else {
		strerr_warn3("gethostbyname: ", hostname, ": No such host", 0);
		errno = EINVAL;
		return (-1);
	}
	if (isnum(servicename)) {
		scan_int(servicename, &t);
		localinaddr.sin_port = htons(t);
	} else
	if ((sp = getservbyname(servicename, "tcp")) != (struct servent *) 0)
		localinaddr.sin_port = sp->s_port;
	else
		return (-1);
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (-1);
	idx = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *) &idx, sizeof(idx)) < 0) {
		close(listenfd);
		return (-1);
	}
	if (setsockopt(listenfd, SOL_SOCKET, SO_LINGER, (char *) &cflinger, sizeof (struct linger)) == -1) {
		close(listenfd);
		return (-1);
	}
	if (bind(listenfd, (struct sockaddr *) &localinaddr, sizeof(localinaddr)) == -1) {
			close(listenfd);
		return (-1);
	}
#endif
	if (listen(listenfd, backlog) == -1) {
		close(listenfd);
		return (-1);
	}
	return (listenfd);
}

void
getversion_tcpbind_c()
{
	const char     *x = "$Id: tcpbind.c,v 1.4 2024-05-09 23:49:23+05:30 mbhangui Exp mbhangui $";

	x++;
}
