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
      #define no_return _Noreturn
    #else
      #define no_return
    #endif /*- #ifdef _Noreturn */
  #endif /*- ifndef noreturn */
#endif

#ifndef noreturn
  #if defined(__GNUC__)
    #define no_return __attribute__((__noreturn__))
  #else
    #define no_return
  #endif /*- #if defined(__GNUC__) */
#else
  #define no_return noreturn
#endif /*- #ifndef noreturn */

#endif /*- _NORETURN_H */
