/*
 * $Log: commands.c,v $
 * Revision 1.11  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.10  2023-02-17 11:36:34+05:30  Cprogrammer
 * return -3 for out of memory error
 *
 * Revision 1.9  2023-01-02 20:31:53+05:30  Cprogrammer
 * return -2 for command too long
 *
 * Revision 1.8  2022-06-20 00:57:33+05:30  Cprogrammer
 * set errno=0 for EOF
 *
 * Revision 1.7  2020-09-15 10:00:56+05:30  Cprogrammer
 * added ctl_maxcmdlen variable
 *
 * Revision 1.6  2005-05-13 13:13:43+05:30  Cprogrammer
 * 2GB limit bug
 *
 * Revision 1.5  2004-10-22 20:24:02+05:30  Cprogrammer
 * added RCS id
 *
 * Revision 1.4  2004-07-17 21:17:42+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef COMMANDS_C
#define COMMANDS_C
#endif
#include <stdio.h>
#include <errno.h>
#include "commands.h"
#include "substdio.h"
#include "stralloc.h"
#include "str.h"
#include "case.h"

static stralloc cmd = { 0 };
unsigned int    ctl_maxcmdlen;

int
commands(substdio *ss, struct commands *c)
{
	unsigned int    i;
	char           *arg;

	for (;;) {
		if (!stralloc_copys(&cmd, ""))
			return -3;
		for (;;) {
			if (!stralloc_readyplus(&cmd, 1))
				return -3;
			if (!(i = substdio_get(ss, cmd.s + cmd.len, 1))) {
				errno = 0;
				return 0;
			} else
			if (i != 1)
				return i;
			if (cmd.s[cmd.len] == '\n')
				break;
			if (!cmd.s[cmd.len])
				cmd.s[cmd.len] = '\n';
			++cmd.len;
			if (ctl_maxcmdlen && cmd.len > ctl_maxcmdlen)
				return -2;
		}
		if (cmd.len > 0 && cmd.s[cmd.len - 1] == '\r')
			--cmd.len;
		cmd.s[cmd.len] = 0;
		i = str_chr(cmd.s, ' ');
		arg = cmd.s + i;
		while (*arg == ' ')
			++arg;
		cmd.s[i] = 0;
		for (i = 0; c[i].text; ++i) {
			if (case_equals(c[i].text, cmd.s))
				break;
		}
		if(!(c[i].text) && (*(cmd.s) == 'x' || *(cmd.s) == 'X'))
			c[i].fun("unimplemented");
		else
			c[i].fun(arg);
		if (c[i].flush)
			c[i].flush();
	}
}

void
getversion_commands_c()
{
	const char     *x = "$Id: commands.c,v 1.11 2024-05-09 23:46:19+05:30 mbhangui Exp mbhangui $";

	x++;
}
