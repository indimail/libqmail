/*
 * $Log: no_of_days.h,v $
 * Revision 1.2  2023-02-08 11:22:51+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * no_of_days.h
 *
 */
#ifndef NO_OF_DAYS_H
#define NO_OF_DAYS_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_TIME_H
#include <time.h>
#endif

char            *no_of_days(time_t);

#endif
