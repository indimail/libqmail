/*
 * $Log: uint16.h,v $
 * Revision 1.2  2020-07-04 23:47:29+05:30  Cprogrammer
 * include inttypes.h if config.h is not included
 *
 * Revision 1.1  2020-07-01 17:16:55+05:30  Cprogrammer
 * Initial revision
 *
 *
 * this header file comes from libowfat, http://www.fefe.de/libowfat/ 
 */
#ifndef UINT16_H
#define UINT16_H
#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#include <inttypes.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#ifdef __cplusplus
extern          "C" {
#endif

typedef uint16_t uint16;
typedef int16_t int16;

#if (defined(__i386__) || defined(__x86_64__)) && !defined(NO_UINT16_MACROS)
static inline void uint16_pack(char *out, uint16 in)
{
	*(uint16 *) out = in;
}

static inline void uint16_unpack(const char *in, uint16 * out)
{
	*out = *(uint16 *) in;
}

static inline uint16 uint16_read(const char *in)
{
	return *(uint16 *) in;
}

void            uint16_pack_big(char *out, uint16 in);
void            uint16_unpack_big(const char *in, uint16 * out);
uint16          uint16_read_big(const char *in);
#else
void            uint16_pack(char *out, uint16 in);
void            uint16_pack_big(char *out, uint16 in);
void            uint16_unpack(const char *in, uint16 * out);
void            uint16_unpack_big(const char *in, uint16 * out);
uint16          uint16_read(const char *in);
uint16          uint16_read_big(const char *in);
#endif

#ifdef __cplusplus
}
#endif
#endif
