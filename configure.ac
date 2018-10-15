#
# $Log: configure.ac,v $
# Revision 1.1  2014-09-02 22:13:49+05:30  Cprogrammer
# Initial revision
#
#
# $Id: configure.ac,v 1.1 2014-09-02 22:13:49+05:30 Cprogrammer Exp mbhangui $
#
AC_PREREQ([2.64])
AC_INIT([libqmail],0.1,[Manvendra Bhangui manvendra@indimail.org],libqmail, [https://sourceforge.net/projects/indimail])
AC_CANONICAL_TARGET
PACKAGE=$PACKAGE_NAME
VERSION=$PACKAGE_VERSION
LT_INIT
AM_INIT_AUTOMAKE([silent-rules])
AM_CONFIG_HEADER(config.h)
AC_DEFINE_UNQUOTED(PACKAGE_BUGREPORT, "mbhangui@gmail.com")
if test "$GCC" = yes ; then
	CXXFLAGS="$CXXFLAGS -Wall"
	CFLAGS="$CFLAGS -O4 -Wall"
fi

dnl Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

dnl Checks for header files.
AC_ISC_POSIX
dnl AC_HEADER_STDC
AC_CHECK_HEADERS(ctype.h errno.h stdarg.h unistd.h fcntl.h signal.h sys/types.h sys/wait.h sys/file.h)

AC_CHECK_FUNC(flock)
if test "$ac_cv_func_flock" = yes ; then
	AC_DEFINE([HAVE_FLOCK], [1], [flock function])
fi

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

AC_OUTPUT(Makefile)
