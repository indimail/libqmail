/*
 * $Log: qgetpwgr.h,v $
 * Revision 1.2  2021-07-10 22:19:48+05:30  Cprogrammer
 * added getservent functions to read /etc/services
 *
 * Revision 1.1  2021-07-03 17:52:52+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _QPWD_H
#define _QPWD_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#ifdef HAVE_GRP_H
#include <grp.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

typedef struct passwd PASSWD;
typedef struct group GROUP;
typedef struct servent SERVICE;

/*-- /etc/passwd */
void            qsetpwent();
void            qendpwent();
int             qgetpwent_r(struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
int             qgetpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
int             qgetpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
struct passwd  *qgetpwnam(const char *name);
struct passwd  *qgetpwuid(uid_t uid);
struct passwd  *qgetpwent();

/*-- /etc/group */
void            qsetgrent();
void            qendgrent();
int             qgetgrent_r(struct group *grp, char *buf, size_t buflen, struct group **result);
int             qgetgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **result);
int             qgetgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result);
struct group   *qgetgrnam(const char *name);
struct group   *qgetgrgid(gid_t gid);
struct group   *qgetgrent();

/*-- /etc/sevices */
void            qsetservent();
void            qendservent();
int             qgetservent_r(struct servent *svc, char *buf, size_t buflen, struct servent **result);
int             qgetservbyname_r(const char *name, const char *proto, struct servent *svc, char *buf, size_t buflen, struct servent **result);
int             qgetservbyport_r(int port, const char *proto, struct servent *svc, char *buf, size_t buflen, struct servent **result);
struct servent *qgetservbyname(const char *name, const char *proto);
struct servent *qgetservbyport(int port, const char *proto);
struct servent *qgetservent();

#endif
