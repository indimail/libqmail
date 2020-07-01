#
# $Log: configure.ac,v $
# Revision 1.8  2020-07-01 15:59:46+05:30  Cprogrammer
# added subdir-objects
#
# Revision 1.6  2020-06-21 21:27:07+05:30  Cprogrammer
# added AC_PROG_CC_C99 to configure.ac
#
# Revision 1.5  2020-06-16 16:09:30+05:30  Cprogrammer
# added pwd.h, grp.h
#
# Revision 1.4  2020-06-15 00:56:06+05:30  Cprogrammer
# updated email address
# added AC_CHECK_LIB(crypto, ..)
#
# Revision 1.3  2020-05-21 10:52:32+05:30  Cprogrammer
# version 0.3
#
# Revision 1.2  2020-05-21 09:00:12+05:30  Cprogrammer
# version 0.2
#
# Revision 1.1  2020-05-11 12:32:48+05:30  Cprogrammer
# Initial revision
#
# Revision 1.1  2014-09-02 22:13:49+05:30  Cprogrammer
# Initial revision
#
# $Id: configure.ac,v 1.8 2020-07-01 15:59:46+05:30 Cprogrammer Exp mbhangui $
#
AC_PREREQ([2.64])
AC_INIT([libqmail],0.3,[Manvendra Bhangui libqmail@indimail.org],libqmail, [https://github.com/mbhangui/libqmail])
AC_CANONICAL_TARGET
PACKAGE=$PACKAGE_NAME
VERSION=$PACKAGE_VERSION
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects silent-rules])
AM_CONFIG_HEADER(config.h)
AC_DEFINE_UNQUOTED(PACKAGE_BUGREPORT, "mbhangui@gmail.com")
if test "$GCC" = yes ; then
	CXXFLAGS="$CXXFLAGS -Wall"
	CFLAGS="$CFLAGS -O4 -Wall -Wshadow"
fi

dnl Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_INSTALL
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

dnl Checks for header files.
AC_ISC_POSIX
dnl AC_HEADER_STDC
AC_CHECK_HEADERS(ctype.h errno.h stdarg.h time.h unistd.h limits.h pwd.h grp.h fcntl.h signal.h stdint.h stddef.h)
AC_CHECK_HEADERS(sys/types.h sys/wait.h sys/file.h)

AC_CHECK_FUNC(flock)
if test "$ac_cv_func_flock" = yes ; then
	AC_DEFINE([HAVE_FLOCK], [1], [flock function])
fi

AC_CHECK_LIB(ssl, SSL_CTX_new, [AC_SUBST([LIB_SSL], ["-lssl"]) AC_DEFINE([HAVE_SSL], [1],[OpenSSL Library])],,-lssl)
AC_CHECK_LIB(crypto, CRYPTO_new_ex_data, [AC_SUBST([LIB_CRYPTO], ["-lcrypto"]) AC_DEFINE([HAVE_CRYPTO], [1],[Crypto Library])],,-lcrypto)
AC_CHECK_LIB(crypt, crypt, [AC_SUBST([LIB_CRYPT], ["-lcrypt"]) AC_DEFINE([HAVE_CRYPT], [1],[crypt Library])],,)

dnl Does not work on RHEL 5, CentOS 5 64 bit systems
RPATH_LIB="$acl_libdirstem"
defaultprefix="/usr"
AC_SUBST([LIBTOOL_DEPS])
AC_SUBST(STRIP_OPT)
AC_SUBST(RPATH_LIB)
AC_SUBST(defaultprefix)
AC_SUBST(libdir)
LIBVER=1
AC_SUBST(LIBVER)
AC_CONFIG_FILES([libqmail.pc:libqmail.pc.in],[], [])

if test x$prefix = xNONE
then
	prefix="$defaultprefix"
	ac_configure_args="$ac_configure_args -prefix=$prefix"
fi

AC_ARG_ENABLE(ENABLE_MD5_CRYPT,    [  --enable-md5-crypt            if your system crypt does not support md5],
	[with_md5crypt=$enableval],
	[with_md5crypt=no])
test "$with_md5crypt" = "no" && AC_DEFINE(ENABLE_MD5_CRYPT,1,Define if you want md5 crypt support compiled in)
AM_CONDITIONAL(ENABLE_MD5_CRYPT, test "$with_md5crypt" = yes)

AC_ARG_ENABLE(ENABLE_SHA256_CRYPT, [  --enable-sha256-crypt         if your system does not support sha256],
	[with_sha256crypt=$enableval],
	[with_sha256crypt=no])
test "$with_sha256crypt" = "no" && AC_DEFINE(ENABLE_SHA256_CRYPT,1,Define if you want sha256 crypt support compiled in)
AM_CONDITIONAL(ENABLE_SHA256_CRYPT, test "$with_sha256crypt" = yes)

AC_ARG_ENABLE(ENABLE_SHA512_CRYPT, [  --enable-sha512-crypt         if your system does not support sha512],
	[with_sha512crypt=$enableval],
	[with_sha512crypt=no])
test "$with_sha512crypt" = "no" && AC_DEFINE(ENABLE_SHA512_CRYPT,1,Define if you want sha512 crypt support compiled in)
AM_CONDITIONAL(ENABLE_SHA512_CRYPT, test "$with_sha512crypt" = yes)

pwdhash=system
AC_ARG_ENABLE(pwdhash,
	[--enable-passwd-hash=des|md5|sha256|sha512|system Passwd Hash (des - DES, md5 - MD5, sha256 - SHA256, sha512 - SHA512, system)],
	pwdhash=$enableval,
	[
	AC_DEFINE_UNQUOTED(DES_HASH,0,Enable DES Encryption)
	AC_DEFINE_UNQUOTED(MD5_HASH,1,Enable MD5 Encryption)
	AC_DEFINE_UNQUOTED(SHA256_HASH,2,Enable SHA256 Encryption)
	AC_DEFINE_UNQUOTED(SHA512_HASH,3,Enable SHA512 Encryption)
	])
case $pwdhash in
	des)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,0,Enable DES Encryption)
	;;
	md5)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,1,Enable MD5 Encryption)
	;;
	sha256)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,2,Enable SHA256 Encryption)
	;;
	sha512)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,3,Enable SHA512 Encryption)
	;;
	system)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,-1,Use System Crypt Encryption)
	;;
esac

AC_OUTPUT(Makefile)

case $pwdhash in
	des)
echo "     Password Hash = DES --enable-password-hash=des"
	;;
	md5)
echo "     Password Hash = MD5 --enable-password-hash=md5"
	;;
	sha256)
echo "     Password Hash = SHA256 --enable-password-hash=sha256"
	;;
	sha512)
echo "     Password Hash = SHA512 --enable-password-hash=sha512"
	;;
	system)
echo "     Password Hash = system --enable-password-hash=system"
	;;
esac

case $with_md5crypt in
1*|y*|Y*)
echo "         MD5 Crypt = ON  --enable-md5-crypt=y"
;;
*)
echo "         MD5 Crypt = OFF --enable-md5-crypt=n default"
;;
esac

case $with_sha256crypt in
1*|y*|Y*)
echo "      SHA256 Crypt = ON  --enable-sha256-crypt=y"
;;
*)
echo "      SHA256 Crypt = OFF --enable-sha256-crypt=n default"
;;
esac

case $with_sha512crypt in
1*|y*|Y*)
echo "      SHA512 Crypt = ON  --enable-sha512-crypt=y"
;;
*)
echo "      SHA512 Crypt = OFF --enable-sha512-crypt=n default"
;;
esac
