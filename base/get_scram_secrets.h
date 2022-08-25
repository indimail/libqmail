/*
 * $Log: get_scram_secrets.h,v $
 * Revision 1.2  2022-08-25 12:05:11+05:30  Cprogrammer
 * added hexsaltedpw, cleartxt fields
 *
 * Revision 1.1  2022-08-04 10:01:03+05:30  Cprogrammer
 * Initial revision
 *
 */

#ifndef _GET_SECRETS_H
#define _GET_SECRETS_H

int             get_scram_secrets(char *, int *, int *, char **, char **, char **, char **, char **, char **);

#endif
