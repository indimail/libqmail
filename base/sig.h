/*
 * $Log: sig.h,v $
 * Revision 1.9  2025-01-21 22:20:07+05:30  Cprogrammer
 * fixes for gcc14
 *
 * Revision 1.8  2020-08-03 18:10:35+05:30  Cprogrammer
 * added sig_usr1, sig_usr2
 *
 * Revision 1.7  2019-10-26 21:04:33+05:30  Cprogrammer
 * fixed definitions of signals
 *
 * Revision 1.6  2016-03-31 17:03:30+05:30  Cprogrammer
 * added functions to handle SIGINT
 *
 * Revision 1.5  2009-06-04 12:09:02+05:30  Cprogrammer
 * added function prototypes
 *
 * Revision 1.4  2004-10-09 23:31:44+05:30  Cprogrammer
 * added new function definitions for daemontools inclusion
 *
 * Revision 1.3  2004-10-09 19:21:53+05:30  Cprogrammer
 * added sig_ignore() and sig_uncatch()
 *
 * Revision 1.2  2004-06-18 23:01:50+05:30  Cprogrammer
 * added RCS log
 *
 */
#ifndef SIG_H
#define SIG_H

void            sig_catch(int, void(*)(int));
void            sig_block(int);
void            sig_unblock(int);
void            sig_blocknone(void);
void            sig_pause(void);

void            sig_dfl();

void            sig_miscignore(void);
void            sig_bugcatch(void (*)(int));

void            sig_pipeignore(void);
void            sig_pipedefault(void);

void            sig_contblock();
void            sig_contunblock();
void            sig_contcatch();
void            sig_contdefault();

void            sig_termblock(void);
void            sig_termunblock(void);
void            sig_termcatch(void (*)(int));
void            sig_termdefault(void);

void            sig_alarmblock(void);
void            sig_alarmunblock(void);
void            sig_alarmcatch(void (*)(int));
void            sig_alarmdefault(void);

void            sig_intblock(void);
void            sig_intunblock(void);
void            sig_intcatch(void (*)(int));
void            sig_intdefault(void);

void            sig_childblock(void);
void            sig_childunblock(void);
void            sig_childcatch(void (*)(int));
void            sig_childdefault(void);

void            sig_hangupblock(void);
void            sig_hangupunblock(void);
void            sig_hangupcatch(void (*)(int));
void            sig_hangupdefault(void);

extern int      sig_alarm;
extern int      sig_child;
extern int      sig_cont;
extern int      sig_hangup;
extern int      sig_int;
extern int      sig_pipe;
extern int      sig_term;
extern int      sig_usr1;
extern int      sig_usr2;

extern void     (*sig_defaulthandler) (int);
extern void     (*sig_ignorehandler) (int);
#define sig_ignore(s) (sig_catch((s),sig_ignorehandler))
#define sig_uncatch(s) (sig_catch((s),sig_defaulthandler))

#endif
