/*
 * $Log: strmsg.h,v $
 * Revision 1.1  2023-02-08 11:24:25+05:30  Cprogrammer
 * Initial revision
 *
 */
#ifndef STRMSG_OUT_H
#define STRMSG_OUT_H

typedef const char c_char;
void            strmsg_out(c_char *, c_char *, c_char *, c_char *, c_char *, c_char *,
                    c_char *, c_char *, c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, c_char *);

#define strmsg_out16(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(x16))
#define strmsg_out15(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(c_char *)0)
#define strmsg_out14(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(c_char *)0,(c_char *)0)
#define strmsg_out13(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out12(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out11(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out10(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out9(x1,x2,x3,x4,x5,x6,x7,x8,x9) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out8(x1,x2,x3,x4,x5,x6,x7,x8) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out7(x1,x2,x3,x4,x5,x6,x7) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(x7),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out6(x1,x2,x3,x4,x5,x6) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(x6),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out5(x1,x2,x3,x4,x5) \
strmsg_out((x1),(x2),(x3),(x4),(x5),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out4(x1,x2,x3,x4) \
strmsg_out((x1),(x2),(x3),(x4),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out3(x1,x2,x3) \
strmsg_out((x1),(x2),(x3),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out2(x1,x2) \
strmsg_out((x1),(x2),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)
#define strmsg_out1(x1) \
strmsg_out((x1),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0)

#endif
