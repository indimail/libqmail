/*
 * $Log: env.h,v $
 * Revision 1.7  2020-05-15 11:35:17+05:30  Cprogrammer
 * made defintions extern
 *
 * Revision 1.6  2019-10-26 21:06:27+05:30  Cprogrammer
 * define env_isinit as extern
 *
 * Revision 1.5  2009-05-03 22:46:20+05:30  Cprogrammer
 * restore_env() now returns void
 *
 * Revision 1.4  2004-10-11 13:53:08+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.3  2004-09-26 00:03:19+05:30  Cprogrammer
 * added restore_env()
 *
 * Revision 1.2  2004-06-18 22:58:29+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef ENV_H
#define ENV_H

extern int      env_isinit;
extern char   **environ;

extern int      env_init(void);
extern int      env_put(char *);
extern int      env_put2(char *, char *);
extern int      env_unset(char *);
extern void     restore_env(void);
extern char    *env_get(char *);
extern char    *env_pick(void);
extern void     env_clear(void);
extern char    *env_findeq(char *);

#endif
