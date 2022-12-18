/*
 * $Log: wait.h,v $
 * Revision 1.5  2022-12-17 00:43:54+05:30  Cprogrammer
 * added wait_handler() and wait_exited macro
 *
 * Revision 1.4  2022-12-13 19:47:18+05:30  Cprogrammer
 * use system defined wait macros
 *
 * Revision 1.3  2004-10-11 14:16:12+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:02:30+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef WAIT_H
#define WAIT_H
#include <sys/wait.h>

int             wait_pid(int *, int);
int             wait_nohang(int *);
int             wait_handler(int, int *);

/*
 * If the child stopped, wait_stopped is nonzero; wait_stopsig is the signal that caused the child to stop.
 * If the child exited by crashing, wait_stopped is zero; wait_crashed is nonzero.
 * If the child exited normally, wait_stopped is zero; wait_crashed is zero; and wait_exitcode is the child's exit code.
 *
 * Everything extant so far uses these same bits.
 */
#define wait_crashed(w)   WTERMSIG((w))
#define wait_exitcode(w)  WEXITSTATUS((w))
#define wait_exited(w)    WIFEXITED((w))
#define wait_stopsig(w)   WSTOPSIG((w))
#define wait_stopped(w)   WIFSTOPPED((w))
#define wait_continued(w) WIFCONTINUED((w))
#define wait_termsig(w)   WTERMSIG((w))
#define wait_signaled(w)  WIFSIGNALED((w))

#endif
