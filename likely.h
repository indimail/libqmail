/*
 * $Log: likely.h,v $
 * Revision 1.1  2020-07-01 16:57:06+05:30  Cprogrammer
 * Initial revision
 *
 *
 * this header file comes from libowfat, http://www.fefe.de/libowfat/ 
 */
#ifdef __dietlibc__
#include <sys/cdefs.h>
#else

#if __GNUC__ < 3
#define __expect(foo,bar) (foo)
#else
#define __expect(foo,bar) __builtin_expect((long)(foo),bar)
#endif
#define __likely(foo) __expect((foo),1)
#define __unlikely(foo) __expect((foo),0)

#endif
