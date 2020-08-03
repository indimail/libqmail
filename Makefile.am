COFLAGS=-z+05:30
ACLOCAL_AMFLAGS=-I m4

DEFS=@DEFS@ -I. -Iarray -Itextcode

INSTALL_PROGRAM = ${INSTALL}          -c
install_sh_PROGRAM = $(install_sh)    -c
INSTALL_SCRIPT = ${INSTALL}           -c
install_sh_SCRIPT = $(install_sh)     -c
INSTALL_STRIP_PROGRAM = $(install_sh) -c $(STRIP_OPT)

libqmail_LTLIBRARIES = libqmail.la
libqmail_la_SOURCES = $(COMMONSOURCES)
libqmail_la_LIBADD = @LIB_CRYPT@ @LIB_CRYPTO@ @LIB_SSL@
libqmail_la_LDFLAGS = -version-info @LIBVER@:0:0
libqmail_la_CFLAGS = -fPIC
libqmaildir=@libdir@

BUILT_SOURCES = uint32.h uint64.h haswaitp.h hasflock.h hassgact.h hassgprm.h \
	select.h hasmkffo.h hasbltnofl.h builtinoflmacros.h iopause.h

MOSTLYCLEANFILES = uint32.h uint64.h haswaitp.h hasflock.h hassgact.h \
	hassgprm.h select.h hasmkffo.h hasbltnofl.h iopause.h

pkgconfigdir=@pkgconfigdir@
pkgconfig_DATA = libqmail.pc

noinst_DATA = libqmail.spec

man_MANS = alloc.3 byte.3 caldate.3 caldate_mjd.3 caltime.3 \
	caltime_tai.3 case.3 cdb.3 coe.3 datetime.3 env.3 error_str.3 \
	error_temp.3 fd_copy.3 fd_move.3 fifo_make.3 fmt_8long.3 \
	fmt_double.3 fmt_fill.3 fmt_minus.3 fmt_pad.3 fmt_plusminus.3 \
	fmt_ulonglong.3 getln2.3 getln.3 leapsecs.3 now.3 qerror.3 \
	scan_double.3 scan_int.3 scan_long.3 scan_plusminus.3 \
	scan_ulonglong.3 sgetopt.3 stralloc.3 subgetopt.3 substdio.3 \
	substdio_copy.3 substdio_in.3 substdio_out.3 tai.3 tai_now.3 \
	tai_pack.3 tai_unpack.3 tai_sub.3 tai_less.3 tai_approx.3 \
	tai_add.3 taia_unpack.3 taia_addsec.3 wait.3 fmt_long.3 fmt_int.3 \
	scan_xlong.3 scan_ushort.3 scan_uint.3 scan_ulong.3 scan_8long.3 \
	str_start.3 str_len.3 str_rchr.3 str_diff.3 str_diffn.3 str_chr.3 \
	str_copy.3 setuserid.3 grpscan.3 setuser_privileges.3 str_tok.3 \
	str_str.3 uint16_pack.3 uint16_pack_big.3 uint16_read.3 \
	uint16_read_big.3 uint16_unpack.3 uint16_unpack_big.3 \
	uint32_pack.3 uint32_pack_big.3 uint32_read.3 uint32_read_big.3 \
	uint32_unpack.3 uint32_unpack_big.3 uint64_pack.3 uint64_pack_big.3 \
	uint64_read.3 uint64_read_big.3 uint64_unpack.3 uint64_unpack_big.3 \
	textcode/fmt_asn1derlength.3 textcode/fmt_asn1dertag.3 \
	textcode/fmt_utf8.3 array/array_get.3 array/array.3 \
	array/array_reset.3 array/array_cate.3 array/iarray_init.3 \
	array/array_equal.3 array/array_length.3 array/array_catb.3 \
	array/array_trunc.3 array/array_cats.3 array/array_cats0.3 \
	array/array_fail.3 array/array_truncate.3 array/array_bytes.3 \
	array/array_cat.3 array/array_start.3 array/iarray_allocate.3 \
	array/iarray_get.3 array/array_cat0.3 array/iarray_free.3 \
	array/array_allocate.3

docs = README ChangeLog COPYING AUTHORS
docdir=@docdir@

include_HEADERS = alloc.h base64.h builtinoflmacros.h byte.h caldate.h \
	caltime.h case.h cdb.h cdbmake.h cdb_make.h coe.h constmap.h \
	datetime.h digest_md5.h env.h error.h exit.h fd.h fifo.h fmt.h \
	gen_allocdefs.h gen_alloc.h getEnvConfig.h getln.h global.h \
	hasbltnofl.h hmac.h in_crypt.h iopause.h leapsecs.h lock.h md5.h \
	makesalt.h mkpasswd.h ndelay.h now.h open.h pw_comp.h ripemd.h \
	scan.h seek.h select.h setuserid.h sgetopt.h sha1.h sig.h stralloc.h \
	strerr.h str.h subfd.h subgetopt.h substdio.h taia.h tai.h tai2.h \
	timeoutread.h timeoutwrite.h typesx.h uint16.h uint32.h uint64.h wait.h \
	qprintf.h strmsg.h array/array.h textcode/entities.h textcode/textcode.h \
	likely.h iarray.h safemult.h

includedir=@prefix@/include/qmail
COMMONSOURCES = alloc.c alloc_re.c base64sub.c byte_chr.c \
	byte_copy.c byte_cr.c byte_cspn.c byte_diff.c byte_rchr.c byte_rcspn.c \
	byte_zero.c caldate_fmjd.c caldate_fmt.c caldate_mjd.c caldate_scan.c \
	caltime_fmt.c caltime_tai.c caltime_utc.c case_diffb.c case_diffs.c \
	case_lowerb.c case_lowers.c case_startb.c case_starts.c cdb.c cdb_hash.c \
	cdb_make.c cdbmake_add.c cdbmake_hash.c cdbmake_pack.c cdb_seek.c \
	cdb_unpack.c coe.c constmap.c datetime.c datetime_un.c digest_md5.c \
	env.c envread.c error.c error_str.c error_temp.c fd_copy.c fd_move.c \
	fifo.c fmt_8long.c fmt_double.c \
	fmt_fill.c fmt_hexbytes.c fmt_int.c fmt_long.c fmt_minus.c fmt_pad.c \
	fmt_plusminus.c fmt_str.c fmt_strn.c fmt_tohex.c fmt_uint0.c fmt_uint.c \
	fmt_ulong.c fmt_ulonglong.c fmt_ushort.c fmt_xlong.c getEnvConfig.c \
	getln2.c getln.c hmac_md5.c hmac_ripemd.c hmac_sha1.c hmac_sha256.c \
	hmac_sha512.c in_crypt.c iopause.c leapsecs_add.c leapsecs_init.c \
	leapsecs_read.c leapsecs_sub.c lock_ex.c lock_exnb.c lock_un.c makesalt.c \
	md5.c md5_crypt.c ndelay.c ndelay_off.c now.c open_append.c open_excl.c \
	open_read.c open_readwrite.c open_trunc.c open_write.c mkpasswd.c \
	pw_comp.c qprintf.c scan_8long.c scan_double.c scan_fromhex.c scan_int.c \
	scan_long.c scan_plusminus.c scan_uint.c scan_ulong.c scan_ulonglong.c \
	scan_ushort.c scan_xlong.c seek_cur.c seek_end.c seek_set.c \
	seek_trunc.c setuserid.c sgetopt.c sha256_crypt.c sha512_crypt.c \
	sig.c sig_alarm.c sig_block.c sig_bug.c sig_catch.c sig_child.c \
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
	timeoutwrite.c uint16_pack.c uint16_read.c uint16_unpack.c \
	uint32_pack.c uint32_read.c uint32_unpack.c \
	wait_nohang.c wait_pid.c \
	textcode/base64url.c textcode/fmt_asn1derlength.c \
	textcode/fmt_asn1dertag.c textcode/fmt_base64.c \
	textcode/fmt_base64url.c textcode/fmt_cescape.c \
	textcode/fmt_foldwhitespace.c textcode/fmt_html.c \
	textcode/fmt_html_tagarg.c textcode/fmt_jsonescape.c \
	textcode/fmt_ldapescape2.c textcode/fmt_ldapescape.c \
	textcode/fmt_quotedprintable.c textcode/fmt_to_array.c \
	textcode/fmt_tofrom_array.c textcode/fmt_to_sa.c \
	textcode/fmt_urlencoded.c textcode/fmt_utf8.c textcode/fmt_uuencoded.c \
	textcode/fmt_xml.c textcode/fmt_yenc.c textcode/scan_base64.c \
	textcode/scan_base64url.c textcode/scan_cescape.c textcode/scan_html.c \
	textcode/scan_jsonescape.c textcode/scan_ldapescape.c \
	textcode/scan_quotedprintable.c textcode/scan_to_array.c \
	textcode/scan_tofrom_array.c textcode/scan_to_sa.c \
	textcode/scan_urlencoded.c textcode/scan_uuencoded.c \
	textcode/scan_yenc.c \
	array/array_cats0.c array/iarray_allocate.c array/array_start.c \
	array/iarray_init.c array/array_trunc.c array/array_reset.c \
	array/array_get.c array/iarray_free.c array/array_catb.c \
	array/iarray_length.c array/array_fail.c array/array_cate.c \
	array/array_bytes.c array/iarray_get.c array/array_truncate.c \
	array/array_cat.c array/array_cat0.c array/array_cats.c \
	array/array_allocate.c array/array_equal.c array/array_length.c

edit = sed \
	-e 's}@PACKAGE\@}$(PACKAGE)}g' \
	-e 's}@PACKAGE_VERSION\@}$(PACKAGE_VERSION)}g' \
	-e 's}@version\@}$(VERSION)}g' \
	-e "s|@release\@|"`cat conf-release`"|g" \
	-e 's}@pkgconfigdir\@}$(pkgconfigdir)}g' \
	-e 's}@VERSION\@}$(VERSION)}g' \
	-e 's}@prefix\@}$(prefix)}g'

libqmail.spec: libqmail.spec.in catChangeLog ChangeLog conf-version conf-release
	(cat $@.in;./catChangeLog) | $(edit) > $@

hasbltnofl.h: trybltnoverflow.c
	(($(COMPILE) -c trybltnoverflow.c && $(CC) \
		-o trybltnoverflow trybltnoverflow.o) > /dev/null 2>&1 \
	&& echo \#define HAS_BUILTIN_OVERFLOW 1 || \
		echo \#warning \"builtin overflow unavailable\"; exit 0 ) > hasbltnofl.h
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

iopause.h: trypoll.c iopause.h1 iopause.h2
	( $(COMPILE) -c trypoll.c >/dev/null 2>&1 \
	&& cat iopause.h2 || cat iopause.h1 ) > iopause.h
	rm -f trypoll.o trypoll

base64sub.lo: base64.h stralloc.h str.h gen_alloc.h
byte_copy.lo: byte.h
byte_chr.lo: byte.h
byte_rchr.lo: byte.h
byte_cr.lo: byte.h
byte_cspn.lo: byte.h
byte_rcspn.lo: byte.h
byte_zero.lo: byte.h
byte_diff.lo: byte.h
coe.lo: coe.h
constmap.lo: constmap.h alloc.h case.h hasbltnofl.h builtinoflmacros.h
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
stralloc_catb.lo: stralloc.h byte.h gen_alloc.h hasbltnofl.h builtinoflmacros.h error.h
stralloc_cats.lo: byte.h str.h stralloc.h gen_alloc.h
stralloc_copy.lo: byte.h stralloc.h gen_alloc.h
stralloc_eady.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnofl.h error.h
stralloc_num.lo: stralloc.h gen_alloc.h
stralloc_opyb.lo: stralloc.h byte.h gen_alloc.h hasbltnofl.h builtinoflmacros.h error.h
stralloc_opys.lo: byte.h str.h stralloc.h gen_alloc.h
stralloc_pend.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnofl.h error.h
alloc.lo: alloc.h error.h hasbltnofl.h
alloc_re.lo: alloc.h byte.h
getEnvConfig.lo: config.h scan.h env.h
env.lo: env.h str.h alloc.h hasbltnofl.h builtinoflmacros.h
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
setuserid.lo: alloc.h str.h
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
uint32_read.lo: uint32.h
uint32_unpack.lo: uint32.h
uint16_pack.lo: uint16.h
uint16_read.lo: uint16.h
uint16_unpack.lo: uint16.h
### textcode comes from libowfat, http://www.fefe.de/libowfat
textcode/base64url.o: textcode/base64url.c
textcode/fmt_base64.o: textcode/fmt_base64.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_base64url.o: textcode/fmt_base64url.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_cescape.o: textcode/fmt_cescape.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_foldwhitespace.o: textcode/fmt_foldwhitespace.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_hexdump.o: textcode/fmt_hexdump.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_html.o: textcode/fmt_html.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_html_tagarg.o: textcode/fmt_html_tagarg.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_jsonescape.o: textcode/fmt_jsonescape.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_ldapescape.o: textcode/fmt_ldapescape.c fmt.h byte.h textcode.h haveinline.h str.h
textcode/fmt_ldapescape2.o: textcode/fmt_ldapescape2.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_quotedprintable.o: textcode/fmt_quotedprintable.c fmt.h byte.h textcode.h haveinline.h str.h
textcode/fmt_to_array.o: textcode/fmt_to_array.c array.h uint64.h textcode.h
textcode/fmt_to_sa.o: textcode/fmt_to_sa.c stralloc.h textcode.h
textcode/fmt_tofrom_array.o: textcode/fmt_tofrom_array.c array.h uint64.h textcode.h
textcode/fmt_urlencoded.o: textcode/fmt_urlencoded.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_uuencoded.o: textcode/fmt_uuencoded.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_xml.o: textcode/fmt_xml.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_yenc.o: textcode/fmt_yenc.c fmt.h byte.h textcode.h
textcode/scan_base64.o: textcode/scan_base64.c textcode.h haveinline.h
textcode/scan_base64url.o: textcode/scan_base64url.c textcode.h haveinline.h
textcode/scan_cescape.o: textcode/scan_cescape.c fmt.h byte.h textcode.h scan.h
textcode/scan_hexdump.o: textcode/scan_hexdump.c fmt.h byte.h textcode.h scan.h
textcode/scan_html.o: textcode/scan_html.c entities.h fmt.h byte.h textcode.h haveinline.h scan.h case.h str.h
textcode/scan_jsonescape.o: textcode/scan_jsonescape.c fmt.h byte.h textcode.h scan.h
textcode/scan_ldapescape.o: textcode/scan_ldapescape.c fmt.h byte.h textcode.h scan.h
textcode/scan_quotedprintable.o: textcode/scan_quotedprintable.c fmt.h byte.h textcode.h scan.h
textcode/scan_to_array.o: textcode/scan_to_array.c str.h array.h uint64.h textcode.h
textcode/scan_to_sa.o: textcode/scan_to_sa.c str.h stralloc.h textcode.h
textcode/scan_tofrom_array.o: textcode/scan_tofrom_array.c str.h array.h uint64.h textcode.h
textcode/scan_urlencoded.o: textcode/scan_urlencoded.c fmt.h byte.h textcode.h scan.h
textcode/scan_uuencoded.o: textcode/scan_uuencoded.c textcode.h
textcode/scan_yenc.o: textcode/scan_yenc.c fmt.h byte.h textcode.h

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

AUTOMAKE_OPTIONS = foreign no-dependencies
