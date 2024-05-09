/*
 * $Log: replacestr.h,v $
 * Revision 1.2  2023-02-08 11:22:59+05:30  Cprogrammer
 * include qmailconfig.h if HAVE_CONFIG_H is not defined
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * replacestr.h
 *
 */
#ifndef REPLACESTR_H
#define REPLACESTR_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include "qmailconfig.h"
#endif
#ifdef HAVE_QMAIL
#include <stralloc.h>
#endif

int             replacestr(const char *, const char *, const char *, stralloc *);

#endif
