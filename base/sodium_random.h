/*
 * $Log: sodium_random.h,v $
 * Revision 1.2  2023-02-08 11:23:11+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.1  2022-08-05 09:06:12+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _SODIUM_RANDOM_H
#define _SODIUM_RANDOM_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

uint32_t        sodium_random(char *, size_t);

#endif
