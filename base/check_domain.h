/*
 * $Log: check_domain.h,v $
 * Revision 1.1  2021-08-24 11:16:15+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef CHECK_DOMAIN_H
#define CHECK_DOMAIN_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <strerr.h>

#ifndef AM_MEMORY_ERR
#define  AM_MEMORY_ERR -1
#endif

extern struct strerr check_domain_err;

int              check_domain(char *);

#endif

