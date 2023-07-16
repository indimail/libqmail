/*
 * $Log: makesalt.h,v $
 * Revision 1.4  2023-07-16 13:50:27+05:30  Cprogrammer
 * increased SALTSIZE
 *
 * Revision 1.3  2022-08-26 18:43:30+05:30  Cprogrammer
 * added additional characters to random generated passwords
 *
 * Revision 1.2  2022-04-17 08:20:52+05:30  Cprogrammer
 * change in return type of makesalt()
 *
 * Revision 1.1  2020-04-01 18:13:27+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef HAVE_MAKESALT_H
#define HAVE_MAKESALT_H

#define SALTSIZE 64
extern char     pchars[];

int             makesalt(char *, int);
char           *genpass(int);

#endif
