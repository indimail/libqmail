COFLAGS=-z+05:30
ACLOCAL_AMFLAGS=-I m4

DEFS=@DEFS@ -I. -Ibase -Iarray -Itextcode -Isocket -Itls

libqmail_LTLIBRARIES = libqmail.la
libqmail_la_SOURCES = $(COMMONSOURCES)
libqmail_la_LIBADD = @LIB_CRYPT@ @LIB_SSL@ @LIB_CRYPTO@ @LIB_SODIUM@ -lm
libqmail_la_LDFLAGS = -version-info @LIBVER@:0:0
libqmail_la_CFLAGS = -fPIC
libqmaildir=@libdir@

BUILT_SOURCES = base/uint32.h base/uint64.h base/haswaitp.h \
	base/hasflock.h base/hassgact.h base/hassgprm.h base/select.h \
	base/hasmkffo.h base/direntry.h base/hasbltnofl.h \
	base/iopause.h base/haveuint128.h base/hasshsgr.h base/hashmethods.h

MOSTLYCLEANFILES = base/uint32.h base/uint64.h base/haswaitp.h \
	base/hasflock.h base/hassgact.h base/hassgprm.h base/select.h \
	base/hasmkffo.h base/direntry.h base/hasbltnofl.h \
	base/iopause.h base/haveuint128.h base/hasshsgr.h base/chkshsgr

pkgconfigdir=@pkgconfigdir@
pkgconfig_DATA = libqmail.pc

noinst_DATA = libqmail.spec libqmail.changes PKGBUILD

man_MANS = base/alloc.3 base/buffer.3 base/byte.3 base/caldate.3 base/caldate_mjd.3 \
	base/caltime.3 base/caltime_tai.3 base/case.3 base/cdb.3 base/coe.3 \
	base/commands.3 base/config.3 base/datetime.3 base/direntry.3 \
	base/env.3 base/error_str.3 base/error_temp.3 base/fd_copy.3 \
	base/fd_move.3 base/fifo_make.3 base/fmt_8long.3 base/fmt_double.3 \
	base/fmt_fill.3 base/fmt_minus.3 base/fmt_pad.3 base/fmt_plusminus.3 \
	base/fmt_ulonglong.3 base/getln2.3 base/getln.3 base/iopause.3 \
	base/leapsecs.3 base/mess822.3 base/mess822_addr.3 base/mess822_date.3 \
	base/mess822_fold.3 base/mess822_quote.3 base/mess822_token.3 \
	base/mess822_when.3 base/now.3 base/qgetgrnam_r.3 base/qgetpwuid.3 \
	base/qgetpwuid_r.3 base/qerror.3 base/qendgrent.3 base/qendpwent.3 base/qgetgrent.3 \
	base/qgetgrgid_r.3 base/qgetgrgid.3 base/qgetgrent_r.3 base/qgetgrnam.3 \
	base/qgetpwent.3 base/qgetpwent_r.3 base/qgetpwnam.3 base/qgetservbyname.3 \
	base/qgetservbyname_r.3 base/qgetservbyport.3 base/qgetservbyport_r.3 \
	base/qgetservent.3 base/qgetservent_r.3 base/qprintf.3 base/qsetgrent.3 \
	base/qsetpwent.3 base/qsnprintf.3 base/qtime.3 base/rewritehost.3 \
	base/scan_double.3 base/scan_int.3 base/scan_long.3 base/scan_plusminus.3 \
	base/scan_ulonglong.3 base/sgetopt.3 base/stralloc.3 base/subgetopt.3 \
	base/subprintf.3 base/substdio.3 base/substdio_copy.3 \
	base/substdio_in.3 base/substdio_out.3 base/tai.3 base/tai_now.3 \
	base/tai_pack.3 base/tai_unpack.3 base/tai_sub.3 base/tai_less.3 \
	base/tai_approx.3 base/tai_add.3 base/taia.3 base/taia_addsec.3 \
	base/taia_now.3 base/taia_pack.3 base/taia_unpack.3 base/wait.3 \
	base/fmt_long.3 base/fmt_int.3 base/scan_xlong.3 base/scan_ushort.3 \
	base/scan_uint.3 base/scan_ulong.3 base/scan_8long.3 base/str_start.3 \
	base/str_len.3 base/str_rchr.3 base/str_diff.3 base/str_diffn.3 base/str_chr.3 \
	base/str_copy.3 base/setuserid.3 base/grpscan.3 base/setuser_privileges.3 \
	base/str_tok.3 base/str_str.3 base/uint16_pack.3 base/uint16_pack_big.3 \
	base/uint16_read.3 base/uint16_read_big.3 base/uint16_unpack.3 base/constmap.3 \
	base/uint16_unpack_big.3 base/uint32_pack.3 base/uint32_pack_big.3 \
	base/uint32_read.3 base/uint32_read_big.3 base/uint32_unpack.3 \
	base/uint32_unpack_big.3 base/uint64_pack.3 base/uint64_pack_big.3 \
	base/uint64_read.3 base/uint64_read_big.3 base/uint64_unpack.3 \
	base/uint64_unpack_big.3 textcode/fmt_asn1derlength.3 textcode/fmt_asn1dertag.3 \
	textcode/fmt_utf8.3 array/array_get.3 array/array.3 array/array_reset.3 \
	array/array_cate.3 array/iarray_init.3 array/array_equal.3 array/array_length.3 \
	array/array_catb.3 array/array_trunc.3 array/array_cats.3 array/array_cats0.3 \
	array/array_fail.3 array/array_truncate.3 array/array_bytes.3 \
	array/array_cat.3 array/array_start.3 array/iarray_allocate.3 \
	array/iarray_get.3 array/array_cat0.3 array/iarray_free.3 \
	array/array_allocate.3 \
	mult/add_of.3 mult/assign.3 mult/imult16.3 mult/imult32.3 \
	mult/imult64.3 mult/range_ptrinbuf.3 mult/range_str2inbuf.3 \
	mult/range_str4inbuf.3 mult/range_strinbuf.3 mult/range_validbuf.3 \
	mult/sub_of.3 mult/umult16.3 mult/umult32.3 mult/umult64.3

docdir=@docdir@
doc_DATA = README.md doc/ChangeLog COPYING AUTHORS

include_HEADERS = base/alloc.h base/allwrite.h base/arc4random.h \
	base/authmethods.h base/base64.h base/buffer.h base/builtinoflmacros.h \
	base/byte.h base/caldate.h base/caltime.h base/case.h \
	base/cdb.h base/cdb_make.h base/cdbmake.h base/cdbmss.h \
	base/check_domain.h base/coe.h base/commands.h base/wildmat.h \
	base/constmap.h base/date822fmt.h base/datetime.h base/digest_md5.h \
	base/direntry.h base/env.h base/error.h base/envdir.h base/evaluate.h \
	base/fd.h base/fifo.h base/fmt.h base/gen_allocdefs.h \
	base/gen_alloc.h base/get_scram_secrets.h base/getEnvConfig.h \
	base/getln.h base/global.h base/hasbltnofl.h base/hashmethods.h base/hmac.h \
	base/in_crypt.h base/iopause.h base/isnum.h base/leapsecs.h \
	base/lock.h base/makeargs.h base/makesalt.h base/matchregex.h base/md5.h \
	base/mess822.h base/mkpasswd.h base/mktempfile.h base/ndelay.h \
	base/noreturn.h base/now.h base/no_of_days.h base/open.h \
	base/openreadclose.h base/pathexec.h base/prot.h base/pw_comp.h \
	base/qgetpwgr.h base/qtime.h base/readclose.h base/replacestr.h \
	base/rewritehost.h base/ripemd.h base/r_mkdir.h base/scan.h \
	base/sconfig.h base/seek.h base/select.h base/setuserid.h base/sgetopt.h \
	base/sha1.h base/sig.h base/sodium_random.h base/stralloc.h \
	base/strerr.h base/str.h base/strmsg.h base/subfd.h base/subgetopt.h \
	base/substdio.h base/taia.h base/tai.h base/tai2.h base/timeoutread.h \
	base/timeoutwrite.h base/timestamp.h base/token822.h base/typesx.h \
	base/uint16.h base/uint32.h base/uint64.h base/wait.h base/qprintf.h \
	array/array.h textcode/entities.h textcode/textcode.h base/likely.h \
	base/iarray.h base/safemult.h base/rangecheck.h socket/tcpbind.h \
	base/valid_password_chars.h socket/tcpopen.h socket/udpopen.h socket/tcpremoteip.h \
	base/qdirname.h tls/tls.h qmailconfig.h

includedir=@prefix@/include/qmail
COMMONSOURCES = base/alloc.c base/alloc_re.c base/allwrite.c base/arc4random.c \
	base/authmethods.c base/base64sub.c base/buffer.c base/byte_chr.c base/byte_copy.c \
	base/byte_cr.c base/byte_cspn.c base/byte_diff.c base/byte_rchr.c \
	base/byte_rcspn.c base/byte_zero.c base/caldate_fmjd.c base/caldate_fmt.c \
	base/caldate_mjd.c base/caldate_scan.c base/caltime_fmt.c \
	base/caltime_tai.c base/caltime_utc.c base/case_diffb.c base/wildmat.c \
	base/case_diffs.c base/case_lowerb.c base/case_lowers.c base/case_startb.c \
	base/case_upperb.c base/case_uppers.c base/case_starts.c base/cdb.c \
	base/cdb_hash.c base/cdb_make.c \
	base/cdbmake_add.c base/cdbmake_hash.c base/cdbmss.c base/cdbmake_pack.c \
	base/cdb_seek.c base/cdb_unpack.c base/check_domain.c base/coe.c \
	base/commands.c base/constmap.c base/date822fmt.c base/datetime.c \
	base/datetime_un.c base/digest_md5.c base/env.c base/envdir.c \
	base/envread.c base/error.c base/error_str.c base/error_temp.c \
	base/estack.c base/evaluate.c base/fd_copy.c base/fd_move.c base/fifo.c \
	base/fmt_8long.c base/fmt_double.c base/fmt_fill.c base/fmt_hexbytes.c \
	base/fmt_hexdump.c base/fmt_int.c base/fmt_long.c base/fmt_minus.c base/fmt_pad.c \
	base/fmt_plusminus.c base/fmt_str.c base/fmt_strn.c base/fmt_uint0.c \
	base/fmt_uint.c base/fmt_ulong.c base/fmt_ulonglong.c base/fmt_ushort.c \
	base/fmt_xlong.c base/get_scram_secrets.c base/getEnvConfig.c base/getln2.c \
	base/getln.c base/hmac_md5.c base/hmac_ripemd.c base/hmac_sha1.c \
	base/hmac_sha224.c base/hmac_sha256.c base/hmac_sha384.c base/hmac_sha512.c \
	base/in_crypt.c base/iopause.c base/isnum.c base/leapsecs_add.c \
	base/leapsecs_init.c base/leapsecs_read.c base/leapsecs_sub.c base/lock_ex.c \
	base/lock_exnb.c base/lock_un.c base/makeargs.c base/makesalt.c base/matchregex.c \
	base/md5.c base/md5_crypt.c base/mess822_addr.c base/mess822_fold.c \
	base/mess822_line.c base/mess822_quote.c base/mess822_when.c base/mess822_date.c \
	base/mess822.h base/mess822_ok.c base/mess822_token.c base/mktempfile.c \
	base/ndelay.c base/ndelay_off.c base/no_of_days.c base/now.c \
	base/open_append.c base/open_excl.c base/open_exclr.c base/open_read.c \
	base/open_readwrite.c base/open_trunc.c base/open_write.c \
	base/openreadclose.c base/mkpasswd.c base/pathexec_env.c \
	base/pathexec_run.c base/prot.c base/pw_comp.c base/qdirname.c \
	base/qgetpwgr.c base/qprintf.c base/qtime.c base/readclose.c \
	base/replacestr.c base/rewritehost.c base/r_mkdir.c base/scan_8long.c \
	base/scan_double.c base/scan_fromhex.c base/scan_int.c base/scan_long.c \
	base/scan_plusminus.c base/scan_uint.c base/scan_ulong.c \
	base/scan_ulonglong.c base/scan_ushort.c base/scan_xlong.c \
	base/scan_short.c base/sconfig.c base/seek_cur.c base/seek_end.c \
	base/seek_set.c base/seek_trunc.c base/setuserid.c base/sgetopt.c \
	base/sha256_crypt.c base/sha512_crypt.c base/sig.c base/sig_alarm.c \
	base/sig_block.c base/sig_bug.c base/sig_catch.c base/sig_child.c \
	base/sig_hup.c base/sig_int.c base/sig_misc.c base/sig_pause.c \
	base/sig_pipe.c base/sig_term.c base/snprintf.c base/sodium_random.c \
	base/stralloc_arts.c base/stralloc_catb.c base/stralloc_cat.c \
	base/stralloc_cats.c base/stralloc_copy.c base/stralloc_eady.c \
	base/stralloc_num.c base/stralloc_opyb.c base/stralloc_opys.c \
	base/stralloc_pend.c base/str_chr.c base/str_chrn.c base/str_cpyb.c \
	base/str_cpy.c base/str_spn.c base/str_cspn.c base/str_diff.c \
	base/str_diffn.c base/str_end.c base/strerr_die.c base/strerr_sys.c \
	base/str_len.c base/strmsg_out.c base/str_rchr.c base/str_start.c \
	base/str_str.c base/str_tok.c base/subfderr.c base/subfdin.c \
	base/subfdins.c base/subfdout.c base/subfdouts.c base/subgetopt.c \
	base/substdi.c base/substdio.c base/substdio_copy.c base/substdo.c \
	base/taia_add.c base/taia_addsec.c base/taia_approx.c base/taia_half.c \
	base/taia_fmtfrac.c base/taia_frac.c base/taia_less.c base/taia_now.c \
	base/taia_pack.c base/taia_sub.c base/taia_tai.c base/taia_uint.c \
	base/taia_unpack.c base/tai64n_decode.c base/tai64n_encode.c base/tai_add.c \
	base/tai_decode.c base/tai_encode.c base/tai_now.c base/tai_pack.c \
	base/tai_sub.c base/tai_uint.c base/tai_unpack.c base/timeoutread.c \
	base/timeoutwrite.c base/timestamp.c base/token822.c base/uint16_pack.c \
	base/uint16_read.c base/uint16_unpack.c base/uint32_pack.c \
	base/uint32_read.c base/uint32_unpack.c base/valid_password_chars.c \
	base/wait_handler.c base/wait_nohang.c base/wait_pid.c \
	textcode/base64url.c textcode/fmt_asn1derlength.c textcode/fmt_asn1dertag.c \
	textcode/fmt_base64.c textcode/fmt_base64url.c textcode/fmt_cescape.c \
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
	array/array_allocate.c array/array_equal.c array/array_length.c \
	mult/imult16.c mult/imult32.c mult/imult64.c mult/range_arrayinbuf.c \
	mult/range_str2inbuf.c mult/range_str4inbuf.c mult/range_strinbuf.c \
	mult/umult16.c mult/umult32.c mult/umult64.c \
	socket/tcpbind.c socket/tcpopen.c socket/udpopen.c socket/tcpremoteip.c \
	tls/tls.c

edit = sed \
	-e 's}@PACKAGE\@}$(PACKAGE)}g' \
	-e 's}@PACKAGE_VERSION\@}$(PACKAGE_VERSION)}g' \
	-e 's}@version\@}$(VERSION)}g' \
	-e "s|@release\@|"`cat conf-release`"|g" \
	-e 's|@email\@|'"`cat conf-email`"'|g' \
	-e 's}@pkgconfigdir\@}$(pkgconfigdir)}g' \
	-e 's}@VERSION\@}$(VERSION)}g' \
	-e 's}@prefix\@}$(prefix)}g'

libqmail.spec: libqmail.spec.in catChangeLog doc/ChangeLog conf-version conf-release conf-email
	(cat $@.in;./catChangeLog) | $(edit) > $@
libqmail.changes: doc/ChangeLog conf-version conf-release conf-email \
catChangeLog
	./catChangeLog --changes doc/ChangeLog > $@
PKGBUILD: PKGBUILD.in catChangeLog Makefile conf-email \
conf-version conf-release doc/ChangeLog libqmail.changes
	cat $@.in | $(edit) > $@

qmailconfig.h: config.h
	cp config.h qmailconfig.h

base/hasbltnofl.h: base/trybltnoverflow.c
	( ( $(COMPILE) -c base/trybltnoverflow.c && $(CC) \
		-o trybltnoverflow trybltnoverflow.o) > /dev/null 2>&1 \
	&& echo \#define HAS_BUILTIN_OVERFLOW 1 || \
		echo \#warning \"builtin overflow unavailable\"; exit 0 ) > base/hasbltnofl.h
	rm -f trybltnoverflow.o trybltnoverflow

base/uint32.h: base/tryulong32.c base/uint32.h1 base/uint32.h2
	( ( $(COMPILE) -c base/tryulong32.c && $(CC) -o tryulong32 tryulong32.o && \
	./tryulong32 ) >/dev/null 2>&1 \
	&& cat base/uint32.h2 || cat base/uint32.h1 ) > base/uint32.h
	rm -f tryulong32.o tryulong32

base/uint64.h: base/tryulong64.c base/uint64.h1 base/uint64.h2
	( ( $(COMPILE) -c base/tryulong64.c && $(CC) -o tryulong64 tryulong64.o && \
	./tryulong64 ) >/dev/null 2>&1 \
	&& cat base/uint64.h1 || cat base/uint64.h2 ) > base/uint64.h
	rm -f tryulong64.o tryulong64

base/direntry.h: base/trydrent.c base/direntry.h1 base/direntry.h2
	( ( $(COMPILE) -c base/trydrent.c && $(CC) -o trydrent trydrent.o && \
	./trydrent ) >/dev/null 2>&1 \
	&& cat base/direntry.h1 || cat base/direntry.h2 ) > base/direntry.h
	rm -f trydrent.o trydrent

base/haswaitp.h: base/trywaitp.c
	( ( $(COMPILE) -c base/trywaitp.c && $(CC) -o trywaitp trywaitp.o ) >/dev/null 2>&1 \
	&& echo \#define HASWAITPID 1 || exit 0 ) > base/haswaitp.h
	rm -f trywaitp.o trywaitp

base/hasflock.h: base/tryflock.c
	( ( $(COMPILE) -c base/tryflock.c && $(CC) -o tryflock tryflock.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASFLOCK 1 || exit 0 ) > base/hasflock.h
	rm -f tryflock.o tryflock

base/hasmkffo.h: base/trymkffo.c
	( ( $(COMPILE) -c base/trymkffo.c && $(CC) -o trymkffo trymkffo.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASMKFIFO 1 || exit 0 ) > base/hasmkffo.h
	rm -f trymkffo.o trymkffo

base/hassgact.h: base/trysgact.c
	( ( $(COMPILE) -c base/trysgact.c && $(CC) -o trysgact trysgact.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASSIGACTION 1 || exit 0 ) > base/hassgact.h
	rm -f trysgact.o trysgact

base/hassgprm.h: base/trysgprm.c
	( ( $(COMPILE) -c base/trysgprm.c && $(CC) -o trysgprm trysgprm.o ) >/dev/null \
	2>&1 \
	&& echo \#define HASSIGPROCMASK 1 || exit 0 ) > base/hassgprm.h
	rm -f trysgprm.o trysgprm
base/select.h: base/trysysel.c base/select.h1 base/select.h2
	( $(COMPILE) -c base/trysysel.c >/dev/null 2>&1 \
	&& cat base/select.h2 || cat base/select.h1 ) > base/select.h
	rm -f trysysel.o trysysel

base/haveuint128.h: base/tryuint128.c
	-rm -f $@
	if $(COMPILE) -c base/tryuint128.c >/dev/null 2>&1; then echo "#define HAVE_UINT128"; fi > $@
	-rm -f tryuint128.o

base/iopause.h: base/trypoll.c base/iopause.h1 base/iopause.h2
	( ( $(COMPILE) -c base/trypoll.c && $(CC) -o trypoll trypoll.o && \
	./trypoll base/trypoll.c ) >/dev/null 2>&1 \
	&& cat base/iopause.h2 || cat base/iopause.h1 ) > base/iopause.h
	rm -f trypoll.o trypoll

base/hasshsgr.h: base/chkshsgr base/warn-shsgr base/tryshsgr.c
	./base/chkshsgr || ( cat base/warn-shsgr; exit 1 )
	( ( $(COMPILE) -c base/tryshsgr.c && $(CC) -o tryshsgr tryshsgr.o && \
	./tryshsgr ) >/dev/null 2>&1 \
	&& echo \#define HASSHORTSETGROUPS 1 || exit 0 ) > base/hasshsgr.h
	rm -f tryshsgr.o tryshsgr

base/chkshsgr: base/chkshsgr.o
	$(CC) -o base/chkshsgr base/chkshsgr.o

base/chkshsgr.o: base/chkshsgr.c
	$(COMPILE) -c base/chkshsgr.c -o base/chkshsgr.o

base/allwrite.lo: allwrite.h
base/base64sub.lo: base64.h stralloc.h str.h gen_alloc.h
base/byte_copy.lo: byte.h
base/byte_chr.lo: byte.h
base/byte_rchr.lo: byte.h
base/byte_cr.lo: byte.h
base/byte_cspn.lo: byte.h
base/byte_rcspn.lo: byte.h
base/byte_zero.lo: byte.h
base/byte_diff.lo: byte.h
base/coe.lo: coe.h
base/constmap.lo: constmap.h alloc.h case.h hasbltnofl.h builtinoflmacros.h
base/date822fmt.lo: datetime.h fmt.h date822fmt.h
base/envdir.lo: error.h open.h pathexec.h openreadclose.h byte.h \
direntry.h stralloc.h
base/error_str.lo: error.h
base/error_temp.lo: error.h
base/evaluate.lo: evaluate.h str.h alloc.h
base/makesalt.lo: makesalt.h config.h
base/mkpasswd.lo: gen_alloc.h str.h strerr.h stralloc.h in_crypt.h makesalt.h
base/pw_comp.lo: gen_alloc.h stralloc.h strerr.h env.h error.h str.h subfd.h \
	in_crypt.h hmac.h digest_md5.h mkpasswd.h pw_comp.h
base/str_len.lo: str.h
base/str_chr.lo: str.h
base/str_chrn.lo: str.h
base/str_rchr.lo: str.h
base/str_diff.lo: str.h
base/str_diffn.lo: str.h
base/str_start.lo: str.h
base/str_end.lo: str.h
base/str_cpy.lo: str.h
base/str_cpyb.lo: str.h
base/str_cspn.lo: str.h
base/subprintf.lo: config.h
base/substdi.lo: substdio.c byte.h error.h
base/substdo.lo: substdio.h str.h byte.h error.h
base/substdio.lo: substdio.h
base/substdio_copy.lo: substdio.h
base/get_scram_secrets.lo: get_scram_secrets.h str.h stralloc.h scan.h authmethods.h
base/getln.lo: getln.h substdio.h stralloc.h byte.h gen_alloc.h
base/getln2.lo: getln.h substdio.h stralloc.h byte.h gen_alloc.h
base/stralloc_arts.lo: stralloc.h byte.h str.h gen_alloc.h
base/stralloc_cat.lo: byte.h stralloc.h gen_alloc.h
base/stralloc_catb.lo: stralloc.h byte.h gen_alloc.h hasbltnofl.h builtinoflmacros.h error.h
base/stralloc_cats.lo: byte.h str.h stralloc.h gen_alloc.h
base/stralloc_copy.lo: byte.h stralloc.h gen_alloc.h
base/stralloc_eady.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnofl.h error.h
base/stralloc_num.lo: stralloc.h gen_alloc.h
base/stralloc_opyb.lo: stralloc.h byte.h gen_alloc.h hasbltnofl.h builtinoflmacros.h error.h
base/stralloc_opys.lo: byte.h str.h stralloc.h gen_alloc.h
base/stralloc_pend.lo: alloc.h stralloc.h gen_alloc.h gen_allocdefs.h hasbltnofl.h error.h
base/alloc.lo: alloc.h error.h hasbltnofl.h
base/alloc_re.lo: alloc.h byte.h
base/getEnvConfig.lo: config.h scan.h env.h
base/env.lo: env.h str.h alloc.h hasbltnofl.h builtinoflmacros.h
base/envread.lo: env.h str.h
base/sgetopt.lo: substdio.h subfd.h sgetopt.h subgetopt.h
base/subgetopt.lo: subgetopt.h
base/subfderr.lo: substdio.h subfd.h
base/subfdin.lo: substdio.h subfd.h
base/subfdins.lo: substdio.h subfd.h
base/subfdout.lo: substdio.h subfd.h
base/subfdouts.lo: substdio.h subfd.h
base/strerr_die.lo: substdio.h subfd.h strerr.h
base/strerr_sys.lo: strerr.h error.h
base/case_diffb.lo: case.h
base/case_diffs.lo: case.h
base/case_lowerb.lo: case.h
base/case_lowers.lo: case.h
base/case_startb.lo: case.h
base/case_starts.lo: case.h
base/case_upperb.lo: case.h
base/case_uppers.lo: case.h
base/datetime.lo: datetime.h
base/datetime_un.lo: datetime.h
base/now.lo: now.h datetime.h
base/cdb.lo: error.h seek.h byte.h cdb.h
base/cdb_hash.lo: cdb.h uint32.h
base/cdb_unpack.lo: cdb.h uint32.h
base/cdb_seek.lo: cdb.h uint32.h
base/cdb_make.lo: cdb.h cdbmake.h uint32.h
base/cdbmake_pack.lo: cdbmake.h uint32.h
base/cdbmake_hash.lo: cdbmake.h uint32.h
base/cdbmake_add.lo: cdbmake.h alloc.h uint32.h
base/cdbmss.lo: cdbmss.h seek.h alloc.h
base/digest_md5.lo: global.h md5.h
base/fifo.lo: hasmkffo.h fifo.h
base/fmt_str.lo: fmt.h
base/fmt_strn.lo: fmt.h
base/fmt_uint.lo: fmt.h
base/fmt_uint0.lo: fmt.h
base/fmt_ulong.lo: fmt.h
base/fmt_hexbytes.lo: fmt.h
base/fmt_hexdump.lo: fmt.h
base/fmt_xlong.lo: fmt.h
base/fmt_ushort.lo: fmt.h
base/fmt_double.lo: fmt.h uint64.h
base/leapsecs_read.lo: tai.h leapsecs.h uint64.h
base/leapsecs_init.lo: leapsecs.h
base/leapsecs_sub.lo: tai.h leapsecs.h uint64.h
base/leapsecs_add.lo: tai.h leapsecs.h uint64.h
base/caldate_fmjd.lo: caldate.h
base/caldate_mjd.lo: caldate.h
base/caldate_fmt.lo: caldate.h
base/caldate_scan.lo: caldate.h
base/caltime_utc.lo: tai.h leapsecs.h caldate.h caltime.h uint64.h
base/caltime_fmt.lo: caldate.h caltime.h uint64.h
base/caltime_tai.lo: tai.h leapsecs.h caldate.h caltime.h uint64.h
base/wait_pid.lo: error.h haswaitp.h
base/wait_nohang.lo: wait.h
base/fd_copy.lo: fd.h
base/fd_move.lo: fd.h
base/getEnvConfig.lo: env.h scan.h
base/hmac_md5.lo: global.h md5.h
base/hmac_ripemd.lo: typesx.h ripemd.h
base/hmac_sha1.lo: typesx.h sha1.h
base/hmac_sha256.lo: typesx.h sha1.h
base/hmac_sha512.lo: typesx.h sha1.h
base/in_crypt.lo: getEnvConfig.h in_crypt.h config.h
base/lock_ex.lo: lock.h hasflock.h
base/lock_exnb.lo: lock.h
base/lock_un.lo: lock.h
base/md5.lo: global.h md5.h
base/md5_crypt.lo: config.h global.h md5.h
base/ndelay.lo: ndelay.h
base/ndelay_off.lo: ndelay.h
base/no_of_days.lo: no_of_days.h
base/open_append.lo: open.h
base/open_excl.lo: open.h
base/open_exclr.lo: open.h
base/open_read.lo: open.h
base/open_write.lo: open.h
base/open_trunc.lo: open.h
base/pathexec_env.lo: stralloc.h alloc.h str.h byte.h env.h pathexec.h
base/pathexec_run.lo: error.h stralloc.h str.h env.h pathexec.h
base/scan_ulong.lo: scan.h
base/scan_xlong.lo: scan.h
base/scan_8long.lo: scan.h
base/scan_ushort.lo: scan.h
base/scan_uint.lo: scan.h
base/seek_cur.lo: seek.h
base/seek_end.lo: seek.h
base/seek_set.lo: seek.h
base/seek_trunc.lo: seek.h
base/setuserid.lo: alloc.h str.h
base/sig.lo: sig.h
base/sig_alarm.lo: sig.h
base/sig_block.lo: sig.h hassgprm.h
base/sig_catch.lo: sig.h hassgact.h
base/sig_pause.lo: sig.h hassgprm.h
base/sig_pipe.lo: sig.h
base/sig_child.lo: sig.h
base/sig_hup.lo: sig.h
base/sig_term.lo: sig.h
base/sig_int.lo: sig.h
base/sig_bug.lo: sig.h
base/sig_misc.lo: sig.h
base/sha512_crypt.lo: config.h
base/sha256_crypt.lo: config.h
base/tai_sub.lo: tai.h uint64.h
base/tai_now.lo: tai.h uint64.h
base/tai_unpack.lo: tai.h uint64.h
base/tai_pack.lo: tai.h uint64.h
base/tai_encode.lo: tai2.h
base/tai_decode.lo: tai2.h stralloc.h gen_alloc.h
base/tai64n_encode.lo: tai2.h uint64.h
base/tai64n_decode.lo: tai2.h uint64.h
base/taia_add.lo: taia.h
base/taia_less.lo: taia.h
base/taia_sub.lo: taia.h
base/taia_approx.lo: taia.h
base/taia_uint.lo: taia.h
base/taia_frac.lo: taia.h
base/taia_now.lo: taia.h
base/taia_pack.lo: taia.h
base/taia_fmtfrac.lo: taia.h
base/taia_tai.lo: taia.h
base/taia_unpack.lo: taia.h uint32.h
base/taia_half.lo: taia.h uint32.h
base/taia_addsec.lo: taia.h
base/timeoutread.lo: timeoutread.h select.h error.h
base/timeoutwrite.lo: timeoutwrite.h select.h error.h
base/token822.lo: token822.h stralloc.h alloc.h str.h gen_allocdefs.h
base/uint32_pack.lo: uint32.h
base/uint32_read.lo: uint32.h
base/uint32_unpack.lo: uint32.h
base/uint16_pack.lo: uint16.h
base/uint16_read.lo: uint16.h
base/uint16_unpack.lo: uint16.h
base/qdirname.lo: base/qdirname.c base/stralloc.h base/strerr.h base/str.h
base/isnum.lo: base/isnum.c base/isnum.h
### textcode comes from libowfat, http://www.fefe.de/libowfat
textcode/base64url.o: textcode/base64url.c
textcode/fmt_base64.o: textcode/fmt_base64.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_base64url.o: textcode/fmt_base64url.c fmt.h byte.h textcode.h haveinline.h
textcode/fmt_cescape.o: textcode/fmt_cescape.c fmt.h byte.h textcode.h str.h haveinline.h
textcode/fmt_foldwhitespace.o: textcode/fmt_foldwhitespace.c fmt.h byte.h textcode.h str.h haveinline.h
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
imult16.o: mult/imult16.c uint16.h
imult32.o: mult/imult32.c uint32.h
imult64.o: mult/imult64.c uint64.h
range_arrayinbuf.o: mult/range_arrayinbuf.c rangecheck.h safemult.h uint16.h uint32.h uint64.h
range_str2inbuf.o: mult/range_str2inbuf.c rangecheck.h
range_str4inbuf.o: mult/range_str4inbuf.c rangecheck.h
range_strinbuf.o: mult/range_strinbuf.c rangecheck.h
umult16.o: mult/umult16.c uint16.h
umult32.o: mult/umult32.c uint32.h
umult64.o: mult/umult64.c uint64.h

socket/tcpbind.lo: socket/tcpbind.c base/byte.h base/error.h base/strerr.h \
base/scan.h base/qdirname.h

socket/tcpopen.lo: socket/tcpopen.c socket/hassresvport.h base/fmt.h \
socket/haveip6.h base/env.h base/scan.h base/str.h base/byte.h \
base/subfd.h base/strerr.h

socket/udpopen.o: socket/udpopen.c socket/haveip6.h base/subfd.h \
base/strerr.h base/fmt.h base/byte.h

tls/tls.lo: tls/tls.h

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

# AUTOMAKE_OPTIONS = foreign
