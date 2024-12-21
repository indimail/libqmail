/*
 * $Log: commands.h,v $
 * Revision 1.7  2024-12-21 10:12:37+05:30  Cprogrammer
 * added cmd_name() function
 *
 * Revision 1.6  2024-05-12 00:10:20+05:30  mbhangui
 * fix function prototypes
 *
 * Revision 1.5  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2020-09-15 10:00:39+05:30  Cprogrammer
 * added ctl_maxcmdlen variable in commands.c
 *
 * Revision 1.3  2004-10-11 13:51:32+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 22:58:14+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef COMMANDS_H
#define COMMANDS_H
#include "substdio.h"

struct commands
{
	const char     *text;
	void            (*fun) (const char *);
	void            (*flush) (void);
};
#ifndef COMMANDS_C
extern int      ctl_maxcmdlen;
#endif

int             commands(substdio *, struct commands *);
const char     *cmd_name(void);

#endif
