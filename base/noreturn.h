/*
 * $Log: noreturn.h,v $
 * Revision 1.1  2021-08-29 21:41:52+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef _NORETURN_H
#define _NORETURN_H

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
  #include <stdnoreturn.h>
  #ifndef noreturn
    #ifdef _Noreturn
      #define noreturn _Noreturn
    #else
      #define noreturn
    #endif /*- #ifdef _Noreturn */
  #endif /*- ifndef noreturn */
#endif

#ifndef noreturn
  #if defined(__GNUC__)
    #define noreturn __attribute__((__noreturn__))
  #else
    #define noreturn
  #endif /*- #if defined(__GNUC__) */
#endif /*- #ifndef noreturn */

#endif /*- _NORETURN_H */
