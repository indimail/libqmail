/*
 * $Log: matchregex.h,v $
 * Revision 1.4  2024-05-09 23:46:54+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.3  2023-09-05 11:03:15+05:30  Cprogrammer
 * added error definitions for matchregex function
 *
 * Revision 1.2  2009-05-01 10:40:37+05:30  Cprogrammer
 * added errorstr argument to matchregex()
 *
 * Revision 1.1  2009-04-30 15:49:47+05:30  Cprogrammer
 * Initial revision
 *
 */
/*
 * simple header file for the matchregex prototype
 */
#ifndef _MATCHREGEX_H_
#define _MATCHREGEX_H_

#ifndef AM_MEMORY_ERR
#define  AM_MEMORY_ERR -1
#endif
#ifndef AM_FILE_ERR
#define  AM_FILE_ERR   -2
#endif
#ifndef AM_LSEEK_ERR
#define  AM_LSEEK_ERR  -3
#endif
#ifndef AM_REGEX_ERR
#define  AM_REGEX_ERR  -4
#endif
#ifndef AM_CONFIG_ERR
#define  AM_CONFIG_ERR -5
#endif
#define MAX_AM_ERR -5

int             matchregex(const char *, const char *, const char *[]);
#endif
