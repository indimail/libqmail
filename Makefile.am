COFLAGS=-z+05:30
ACLOCAL_AMFLAGS=-I m4

DEFS=@DEFS@ -fno-strict-aliasing -I. -g

INSTALL_PROGRAM = ${INSTALL}          -c
install_sh_PROGRAM = $(install_sh)    -c
INSTALL_SCRIPT = ${INSTALL}           -c
install_sh_SCRIPT = $(install_sh)     -c
INSTALL_STRIP_PROGRAM = $(install_sh) -c $(STRIP_OPT)
all: uint32.h uint64.h haswaitp.h hasflock.h hassgact.h hassgprm.h \
	select.h hasmkffo.h hasbltnoverflow.h

libqmail_LTLIBRARIES = libqmail.la
libqmail_la_SOURCES = $(COMMONSOURCES)
libqmail_la_LIBADD = @LIB_CRYPT@ @LIB_SSL@ 
libqmail_la_LDFLAGS = -version-info @LIBVER@:0:0
libqmail_la_CFLAGS = -fPIC
libqmaildir=@libdir@

MOSTLYCLEANFILES = uint32.h uint64.h haswaitp.h hasflock.h hassgact.h \
	hassgprm.h select.h hasmkffo.h hasbltnoverflow.h

pkgconfigdir=@pkgconfigdir@
pkgconfig_DATA = libqmail.pc

man_MANS = alloc.3 byte.3 caldate.3 caldate_mjd.3 caltime.3 \
	caltime_tai.3 case.3 cdb.3 coe.3 datetime.3 env.3 error_str.3 \
	error_temp.3 fd_copy.3 fd_move.3 fifo_make.3 fmt_8long.3 \
	fmt_double.3 fmt_fill.3 fmt_minus.3 fmt_pad.3 fmt_plusminus.3 \
	fmt_ulonglong.3 getln2.3 getln.3 leapsecs.3 now.3 qerror.3 \
	scan_double.3 scan_int.3 scan_long.3 scan_plusminus.3 \
	scan_ulonglong.3 sgetopt.3 stralloc.3 subgetopt.3 substdio.3 \
	substdio_copy.3 substdio_in.3 substdio_out.3 tai.3 tai_now.3 \
	tai_pack.3 tai_unpack.3 tai_sub.3 tai_less.3 tai_approx.3 \
	tai_add.3 taia_unpack.3 taia_addsec.3 wait.3 fmt_long.3 fmt_int.3

docs = README ChangeLog COPYING AUTHORS
docdir=@docdir@

include_HEADERS = alloc.h base64.h byte.h caldate.h caltime.h case.h \
	cdb.h cdbmake.h cdb_make.h coe.h constmap.h datetime.h digest_md5.h \
	env.h error.h exit.h fd.h fifo.h fmt.h gen_allocdefs.h gen_alloc.h \
	getEnvConfig.h getln.h global.h hasbltnoverflow.h hmac.h in_crypt.h \
	leapsecs.h lock.h md5.h makesalt.h mkpasswd.h ndelay.h now.h open.h \
	pw_comp.h ripemd.h scan.h seek.h select.h sgetopt.h sha1.h sig.h \
	stralloc.h strerr.h str.h subfd.h subgetopt.h substdio.h taia.h \
	tai.h tai2.h timeoutread.h timeoutwrite.h typesx.h uint32.h \
	uint64.h wait.h qprintf.h strmsg.h

includedir=@prefix@/include/qmail
COMMONSOURCES = alloc.c alloc_re.c base64sub.c builtin_overflow.c byte_chr.c \
	byte_copy.c byte_cr.c byte_cspn.c byte_diff.c byte_rchr.c byte_rcspn.c \
	byte_zero.c caldate_fmjd.c caldate_fmt.c caldate_mjd.c caldate_scan.c \
	caltime_fmt.c caltime_tai.c caltime_utc.c case_diffb.c case_diffs.c \
	case_lowerb.c case_lowers.c case_startb.c case_starts.c cdb.c cdb_hash.c \
	cdb_make.c cdbmake_add.c cdbmake_hash.c cdbmake_pack.c cdb_seek.c \
	cdb_unpack.c coe.c constmap.c datetime.c datetime_un.c digest_md5.c \
	env.c envread.c error.c error_str.c error_temp.c fd_copy.c fd_move.c \
	fifo.c fmt_8long.c fmt_double.c fmt_fill.c fmt_hexbytes.c fmt_int.c \
	fmt_long.c fmt_minus.c fmt_pad.c fmt_plusminus.c fmt_str.c \
	fmt_strn.c fmt_uint0.c fmt_uint.c fmt_ulong.c fmt_ulonglong.c \
	fmt_ushort.c fmt_xlong.c getEnvConfig.c getln2.c getln.c \
	hmac_md5.c hmac_ripemd.c hmac_sha1.c hmac_sha256.c hmac_sha512.c \
	in_crypt.c leapsecs_add.c leapsecs_init.c leapsecs_read.c \
	leapsecs_sub.c lock_ex.c lock_exnb.c lock_un.c makesalt.c md5.c \
	md5_crypt.c ndelay.c ndelay_off.c now.c open_append.c open_excl.c \
	open_read.c open_readwrite.c open_trunc.c open_write.c mkpasswd.c \
	pw_comp.c qprintf.c scan_8long.c scan_double.c scan_int.c scan_long.c \
	scan_plusminus.c scan_uint.c scan_ulong.c scan_ulonglong.c \
	scan_ushort.c scan_xlong.c seek_cur.c seek_end.c seek_set.c \
	seek_trunc.c sgetopt.c sha256_crypt.c sha512_crypt.c sig.c \
	sig_alarm.c sig_block.c sig_bug.c sig_catch.c sig_child.c \
	sig_hup.c sig_int.c sig_misc.c sig_pause.c sig_pipe.c sig_term.c \
	stralloc_arts.c stralloc_catb.c stralloc_cat.c stralloc_cats.c \
	stralloc_copy.c stralloc_eady.c stralloc_num.c stralloc_opyb.c \
	stralloc_opys.c stralloc_pend.c str_chr.c str_chrn.c str_cpyb.c \
	str_cpy.c str_cspn.c str_diff.c str_diffn.c str_end.c strerr_die.c \
	strerr_sys.c str_len.c strmsg_out.c str_rchr.c str_start.c \
	str_str.c str_tok.c subfderr.c subfdin.c subfdins.c \
	subfdout.c subfdouts.c subgetopt.c substdi.c substdio.c \
	substdio_copy.c substdo.c taia_add.c taia_addsec.c taia_approx.c \
	taia_half.c taia_fmtfrac.c taia_frac.c taia_less.c taia_now.c \
	taia_pack.c taia_sub.c taia_tai.c taia_uint.c taia_unpack.c \
	tai64n_decode.c tai64n_encode.c tai_decode.c tai_encode.c \
	tai_now.c tai_pack.c tai_sub.c tai_unpack.c timeoutread.c \
	timeoutwrite.c uint32_pack.c uint32_unpack.c wait_nohang.c wait_pid.c

hasbltnoverflow.h: trybltnoverflow.c
	(($(COMPILE) -c trybltnoverflow.c && $(CC) \
		-o trybltnoverflow trybltnoverflow.o) > /dev/null 2>&1 \
	&& echo \#define HAS_BUILTIN_OVERFLOW 1 || exit 0 ) > hasbltnoverflow.h
	rm -f trybltnoverflow.o trybltnoverflow

uint32.h: tryulong32.c uint32.h1 uint32.h2
	(( $(COMPILE) -c tryulong32.c && $(CC) -o tryulong32 tryulong32.o && \
	./tryulong32 ) >/dev/null 2>&1 \
	&& cat uint32.h2 || cat uint32.h1 ) > uint32.h
	rm -f tryulong32.o tryulong32

uint64.h: tryulong64.c uint64.h1 uint64.h2
	(( $(COMPILE) -c tryulong64.c && $(CC) -o tryulong64 tryulong64.o && \
	./tryulong64 ) >/dev/null 2>&1 \
	&& cat uint64.h1 || cat uint64.h2 ) > uint64.h
	rm -f tryulong64.o tryulong64

haswaitp.h: trywaitp.c
	(( $(COMPILE) -c trywaitp.c && $(CC) -o trywaitp trywaitp.o ) >/dev/null 2>&1 \
	&& echo \#define HASWAITPID 1 || exit 0 ) > haswaitp.h
	rm -f trywaitp.o trywaitp

hasflock.h: tryflock.c
	( ( $(COMPILE) -c tryflock.c && $(CC) -o tryflock tryflock.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASFLOCK 1 || exit 0 ) > hasflock.h
	rm -f tryflock.o tryflock

hasmkffo.h: trymkffo.c
	( ( $(COMPILE) -c trymkffo.c && $(CC) -o trymkffo trymkffo.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASMKFIFO 1 || exit 0 ) > hasmkffo.h
	rm -f trymkffo.o trymkffo

hassgact.h: trysgact.c
	( ( $(COMPILE) -c trysgact.c && $(CC) -o trysgact trysgact.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASSIGACTION 1 || exit 0 ) > hassgact.h
	rm -f trysgact.o trysgact

hassgprm.h: trysgprm.c
	( ( $(COMPILE) -c trysgprm.c && $(CC) -o trysgprm trysgprm.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASSIGPROCMASK 1 || exit 0 ) > hassgprm.h
	rm -f trysgprm.o trysgprm
select.h: trysysel.c select.h1 select.h2
	( $(COMPILE) -c trysysel.c >/dev/null 2>&1 \
	&& cat select.h2 || cat select.h1 ) > select.h
	rm -f trysysel.o trysysel

base64sub.lo: base64.h stralloc.h str.h gen_alloc.h
builtin_overflow.lo:hasbltnoverflow.c
byte_copy.lo: byte.h
byte_chr.lo: byte.h
byte_rchr.lo: byte.h
byte_cr.lo: byte.h
byte_cspn.lo: byte.h
byte_rcspn.lo: byte.h
byte_zero.lo: byte.h
byte_diff.lo: byte.h
coe.lo: coe.h
constmap.lo: constmap.h alloc.h case.h
error.lo: error.h
error_str.lo: error.h
error_temp.lo: error.h
mkpasswd.lo: gen_alloc.h str.h strerr.h stralloc.h in_crypt.h makesalt.h
pw_comp.lo: gen_alloc.h stralloc.h strerr.h env.h error.h str.h subfd.h \
	in_crypt.h hmac.h digest_md5.h mkpasswd.h pw_comp.h
str_len.lo: str.h
str_chr.lo: str.h
str_chrn.lo: str.h
str_rchr.lo: str.h
str_diff.lo: str.h
str_diffn.lo: str.h
str_start.lo: str.h
str_end.lo: str.h
str_cpy.lo: str.h
str_cpyb.lo: str.h
str_cspn.lo: str.h
subprintf.lo: config.h
substdi.lo: substdio.c byte.h error.h
substdo.lo: substdio.h str.h byte.h error.h
substdio.lo: substdio.h
substdio_copy.lo: substdio.h
getln.lo: getln.h substdio.h stralloc.h byte.h gen_alloc.h
getln2.lo: getln.h substdio.h stralloc.h byte.h gen_alloc.h
stralloc_arts.lo: stralloc.h byte.h str.h gen_alloc.h
stralloc_cat.lo: byte.h stralloc.h gen_alloc.h
stralloc_catb.lo: stralloc.h byte.h gen_alloc.h
stralloc_cats.lo: byte.h str.h stralloc.h gen_alloc.h
stralloc_copy.lo: byte.h stralloc.h gen_alloc.h
stralloc_eady.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnoverflow.h
stralloc_num.lo: stralloc.h gen_alloc.h
stralloc_opyb.lo: stralloc.h byte.h gen_alloc.h
stralloc_opys.lo: byte.h str.h stralloc.h gen_alloc.h
stralloc_pend.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnoverflow.h
alloc.lo: alloc.h error.h
alloc_re.lo: alloc.h byte.h
getEnvConfig.lo: config.h scan.h env.h
env.lo: env.h str.h alloc.h
envread.lo: env.h str.h
sgetopt.lo: substdio.h subfd.h sgetopt.h subgetopt.h
subgetopt.lo: subgetopt.h
subfderr.lo: substdio.h subfd.h
subfdin.lo: substdio.h subfd.h
subfdins.lo: substdio.h subfd.h
subfdout.lo: substdio.h subfd.h
subfdouts.lo: substdio.h subfd.h
strerr_die.lo: substdio.h subfd.h exit.h strerr.h
strerr_sys.lo: strerr.h error.h
case_diffb.lo: case.h
case_diffs.lo: case.h
case_lowerb.lo: case.h
case_lowers.lo: case.h
case_startb.lo: case.h
case_starts.lo: case.h
datetime.lo: datetime.h
datetime_un.lo: datetime.h
now.lo: now.h datetime.h
cdb.lo: error.h seek.h byte.h cdb.h
cdb_hash.lo: cdb.h uint32.h
cdb_unpack.lo: cdb.h uint32.h
cdb_seek.lo: cdb.h uint32.h
cdb_make.lo: cdb.h cdbmake.h uint32.h
cdbmake_pack.lo: cdbmake.h uint32.h
cdbmake_hash.lo: cdbmake.h uint32.h
cdbmake_add.lo: cdbmake.h alloc.h uint32.h
digest_md5.lo: global.h md5.h
fifo.lo: hasmkffo.h fifo.h
fmt_str.lo: fmt.h
fmt_strn.lo: fmt.h
fmt_uint.lo: fmt.h
fmt_uint0.lo: fmt.h
fmt_ulong.lo: fmt.h
fmt_hexbytes.lo: fmt.h
fmt_xlong.lo: fmt.h
fmt_ushort.lo: fmt.h
fmt_double.lo: fmt.h uint64.h
leapsecs_read.lo: tai.h leapsecs.h uint64.h
leapsecs_init.lo: leapsecs.h
leapsecs_sub.lo: tai.h leapsecs.h uint64.h
leapsecs_add.lo: tai.h leapsecs.h uint64.h
caldate_fmjd.lo: caldate.h
caldate_mjd.lo: caldate.h
caldate_fmt.lo: caldate.h
caldate_scan.lo: caldate.h
caltime_utc.lo: tai.h leapsecs.h caldate.h caltime.h uint64.h
caltime_fmt.lo: caldate.h caltime.h uint64.h
caltime_tai.lo: tai.h leapsecs.h caldate.h caltime.h uint64.h
wait_pid.lo: error.h haswaitp.h
wait_nohang.lo: wait.h
fd_copy.lo: fd.h
fd_move.lo: fd.h
getEnvConfig.lo: env.h scan.h
hmac_md5.lo: global.h md5.h
hmac_ripemd.lo: typesx.h ripemd.h
hmac_sha1.lo: typesx.h sha1.h
hmac_sha256.lo: typesx.h sha1.h
hmac_sha512.lo: typesx.h sha1.h
in_crypt.lo: getEnvConfig.h in_crypt.h
lock_ex.lo: lock.h hasflock.h
lock_exnb.lo: lock.h
lock_un.lo: lock.h
md5.c: global.h md5.h
md5_crypt.lo: config.h global.h md5.h
ndelay.lo: ndelay.h
ndelay_off.lo: ndelay.h
open_append.lo: open.h
open_excl.lo: open.h
open_read.lo: open.h
open_write.lo: open.h
open_trunc.lo: open.h
scan_ulong.lo: scan.h
scan_xlong.lo: scan.h
scan_8long.lo: scan.h
scan_ushort.lo: scan.h
scan_uint.lo: scan.h
seek_cur.lo: seek.h
seek_end.lo: seek.h
seek_set.lo: seek.h
seek_trunc.lo: seek.h
sig.lo: sig.h
sig_alarm.lo: sig.h
sig_block.lo: sig.h hassgprm.h
sig_catch.lo: sig.h hassgact.h
sig_pause.lo: sig.h hassgprm.h
sig_pipe.lo: sig.h
sig_child.lo: sig.h
sig_hup.lo: sig.h
sig_term.lo: sig.h
sig_int.lo: sig.h
sig_bug.lo: sig.h
sig_misc.lo: sig.h
sha512_crypt.lo: config.h
sha256_crypt.lo: config.h
tai_sub.lo: tai.h uint64.h
tai_now.lo: tai.h uint64.h
tai_unpack.lo: tai.h uint64.h
tai_pack.lo: tai.h uint64.h
tai_encode.lo: tai2.h 
tai_decode.lo: tai2.h stralloc.h gen_alloc.h
tai64n_encode.lo: tai2.h uint64.h
tai64n_decode.lo: tai2.h uint64.h
taia_add.lo: taia.h
taia_less.lo: taia.h
taia_sub.lo: taia.h
taia_approx.lo: taia.h
taia_uint.lo: taia.h
taia_frac.lo: taia.h
taia_now.lo: taia.h
taia_pack.lo: taia.h
taia_fmtfrac.lo: taia.h
taia_tai.lo: taia.h
taia_unpack.lo: taia.h uint32.h
taia_half.lo: taia.h uint32.h
taia_addsec.lo: taia.h
timeoutread.lo: timeoutread.h select.h error.h
timeoutwrite.lo: timeoutwrite.h select.h error.h
uint32_pack.lo: uint32.h
uint32_unpack.lo: uint32.h

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

AUTOMAKE_OPTIONS = foreign no-dependencies
