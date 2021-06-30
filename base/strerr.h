/*
 * $Log: strerr.h,v $
 * Revision 1.8  2021-06-30 14:16:15+05:30  Cprogrammer
 * added STRERR2, STRERR3, STRERR_SYS2 macros
 *
 * Revision 1.7  2020-11-24 13:34:28+05:30  Cprogrammer
 * added noreturn attribute for strerr_die()
 *
 * Revision 1.6  2020-11-22 23:53:39+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.5  2019-06-24 21:28:40+05:30  Cprogrammer
 * added more sterr_warnx, strerr_diex macros
 *
 * Revision 1.4  2004-10-21 21:50:27+05:30  Cprogrammer
 * added strerr_warn8,strerr_warn7,strerr_die8,strerr_die7,strerr_die8sys,strerr_die7sys,
 * strerr_die8x,strerr_die7x
 *
 * Revision 1.3  2004-10-11 14:09:04+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.2  2004-06-18 23:01:58+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef STRERR_H
#define STRERR_H

struct strerr
{
	struct strerr  *who;
	char           *x;
	char           *y;
	char           *z;
} ;

extern struct strerr strerr_sys;

typedef const char c_char;

void            strerr_sysinit(void);
void            strerr_warn(c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, struct strerr *);
void            strerr_die(int, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, c_char *, c_char *, c_char *,
					c_char *, c_char *, struct strerr *)
					__attribute__((noreturn));

#define STRERR(r,se,a) \
{ se.who = 0; se.x = a; se.y = 0; se.z = 0; return r; }
#define STRERR2(r,se,a,b) \
{ se.who = 0; se.x = a; se.y = b; se.z = 0; return r; }
#define STRERR3(r,se,a,b,c) \
{ se.who = 0; se.x = a; se.y = b; se.z = c; return r; }

#define STRERR_SYS(r,se,a) \
{ se.who = &strerr_sys; se.x = a; se.y = 0; se.z = 0; return r; }
#define STRERR_SYS2(r,se,a,b) \
{ se.who = &strerr_sys; se.x = a; se.y = b; se.z = 0; return r; }
#define STRERR_SYS3(r,se,a,b,c) \
{ se.who = &strerr_sys; se.x = a; se.y = b; se.z = c; return r; }

#define strerr_warn16(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(x16),(struct strerr *) (se))
#define strerr_warn15(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(c_char *)0,(struct strerr *) (se))
#define strerr_warn14(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn13(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn12(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn11(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn10(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn9(x1,x2,x3,x4,x5,x6,x7,x8,x9,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn8(x1,x2,x3,x4,x5,x6,x7,x8,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn7(x1,x2,x3,x4,x5,x6,x7,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(x7),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn6(x1,x2,x3,x4,x5,x6,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(x6),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn5(x1,x2,x3,x4,x5,se) \
strerr_warn((x1),(x2),(x3),(x4),(x5),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn4(x1,x2,x3,x4,se) \
strerr_warn((x1),(x2),(x3),(x4),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn3(x1,x2,x3,se) \
strerr_warn((x1),(x2),(x3),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn2(x1,x2,se) \
strerr_warn((x1),(x2),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_warn1(x1,se) \
strerr_warn((x1),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))

#define strerr_die16(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(x16),(struct strerr *) (se))
#define strerr_die15(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(c_char *)0,(struct strerr *) (se))
#define strerr_die14(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die13(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die12(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die11(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die10(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die9(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die8(e,x1,x2,x3,x4,x5,x6,x7,x8,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die7(e,x1,x2,x3,x4,x5,x6,x7,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die6(e,x1,x2,x3,x4,x5,x6,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die5(e,x1,x2,x3,x4,x5,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die4(e,x1,x2,x3,x4,se) \
strerr_die((e),(x1),(x2),(x3),(x4),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die3(e,x1,x2,x3,se) \
strerr_die((e),(x1),(x2),(x3),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die2(e,x1,x2,se) \
strerr_die((e),(x1),(x2),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))
#define strerr_die1(e,x1,se) \
strerr_die((e),(x1),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *) (se))

#define strerr_die16sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(x16), &strerr_sys)
#define strerr_die15sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(c_char *)0, &strerr_sys)
#define strerr_die14sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die13sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die12sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die11sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die10sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die9sys(e,x1,x2,x3,x4,x5,x6,x7,x8,x9) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die8sys(e,x1,x2,x3,x4,x5,x6,x7,x8) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die7sys(e,x1,x2,x3,x4,x5,x6,x7) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die6sys(e,x1,x2,x3,x4,x5,x6) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die5sys(e,x1,x2,x3,x4,x5) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die4sys(e,x1,x2,x3,x4) \
strerr_die((e),(x1),(x2),(x3),(x4),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die3sys(e,x1,x2,x3) \
strerr_die((e),(x1),(x2),(x3),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die2sys(e,x1,x2) \
strerr_die((e),(x1),(x2),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)
#define strerr_die1sys(e,x1) \
strerr_die((e),(x1),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0, &strerr_sys)

#define strerr_die16x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(x16),(struct strerr *)0)
#define strerr_die15x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(x15),(c_char *)0,(struct strerr *)0)
#define strerr_die14x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(x14),(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die13x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(x13),(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die12x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(x12),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die11x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(x11),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die10x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(x10),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die9x(e,x1,x2,x3,x4,x5,x6,x7,x8,x9) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(x9),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die8x(e,x1,x2,x3,x4,x5,x6,x7,x8) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(x8),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die7x(e,x1,x2,x3,x4,x5,x6,x7) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(x7),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die6x(e,x1,x2,x3,x4,x5,x6) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(x6),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die5x(e,x1,x2,x3,x4,x5) \
strerr_die((e),(x1),(x2),(x3),(x4),(x5),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die4x(e,x1,x2,x3,x4) \
strerr_die((e),(x1),(x2),(x3),(x4),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die3x(e,x1,x2,x3) \
strerr_die((e),(x1),(x2),(x3),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die2x(e,x1,x2) \
strerr_die((e),(x1),(x2),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)
#define strerr_die1x(e,x1) \
strerr_die((e),(x1),(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(c_char *)0,(struct strerr *)0)

#endif
