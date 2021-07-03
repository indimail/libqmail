/*
 * $Log: qgetpwgr.h,v $
 * Revision 1.1  2021-07-03 17:52:52+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _QPWD_H
#define _QPWD_H
#include <pwd.h>
#include <grp.h>

typedef struct passwd PASSWD;
typedef struct group GROUP;

void            qsetpwent();
void            qendpwent();
int             qgetpwent_r(struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
int             qgetpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
int             qgetpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
struct passwd  *qgetpwnam(const char *name);
struct passwd  *qgetpwuid(uid_t uid);
struct passwd  *qgetpwent();

void            qsetgrent();
void            qendgrent();
int             qgetgrent_r(struct group *grp, char *buf, size_t buflen, struct group **result);
int             qgetgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **result);
int             qgetgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result);
struct group   *qgetgrnam(const char *name);
struct group   *qgetgrgid(gid_t gid);
struct group   *qgetgrent();
#endif
