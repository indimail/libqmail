# Introduction

libqmail is a library of general purpose APIs extracted from Dan Bernstein's [qmail](http://cr.yp.to/qmail.html), reimplemented and covered by the GNU General Public License Version 2. Many of the functions implemented here have since been placed in the public domain. Many of the functions have been generously borrowed from [libowfat](http://www.fefe.de/libowfat/). libqmail is used by [indimail-mta](https://github.com/mbhangui/indimail-mta) and it's subpackages daemontools and ucspi-tcp, [indimail-virtualdomains](https://github.com/mbhangui/indimail-virtualdomains). It is also used by [mpdev](https://github.com/mbhangui/mpdev) - An event watcher for [Music Player Daemon (mpd)](https://www.musicpd.org/). The library comes with a set of man pages, though few are missing.

**Complation Status (from Github Actions)**

[![libqmail Ubuntu, Mac OSX](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-c-cpp.yml/badge.svg)](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-c-cpp.yml)
[![libqmail FreeBSD](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-freebsd.yml/badge.svg)](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-freebsd.yml)

# Compilation

```
$ cd /usr/local/src
$ git clone https://github.com/mbhangui/libqmail.git
$ cd /usr/local/src/libqmail/libqmail
$ ./default.configure
$ make
$ sudo make install
```

* NOTE: for FreeBSD, install automake, autoconf, libtool, pkgconf using pkg.
* NOTE: For Darwin (Mac OSX), install [MacPorts](https://www.macports.org/) or [Homebrew](https://brew.sh/). You can look at this [document](https://paolozaino.wordpress.com/2015/05/05/how-to-install-and-use-autotools-on-mac-os-x/) for installing MacPorts.
* NOTE: libqmail build has been done with clang and gcc. So the instructions should work fine if you have either of them on FreeBSD or Darwin (Mac OSX)
```
# port install automake autoconf libtool pkgconfig
# port install openssl
# port update outdated
```
* NOTE: The crypt(3) function on OSX is crippled. the default.configure script passes --enable-passwd-hash=md5 to the configure script. This enables the internal hash functions instead of the crippled system supplied crypt(3) function. Read about his issue [here](https://stackoverflow.com/questions/32569597/how-to-get-same-crypt3-function-in-mac-os-x-as-linux-gcc-gnu-crypt3-linux-g) and [here](https://bugs.python.org/issue33213).
* NOTE: If you use brew to install openssl on OSX, then you have to do some crazy stuff like setting CPPFLAGS and LDFLAGS before calling default.configure and make commands given below in this document. Using macports is cleaner and easier.
```
CPPFLAGS="-I/usr/local/opt/openssl@1.1/include"
LDFLAGS="-L/usr/local/opt/openssl@1.1/lib"
```

# Binary Builds on openSUSE Build Service

[![libqmail obs CI](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-obs.yml/badge.svg)](https://github.com/mbhangui/libqmail/actions/workflows/libqmail-obs.yml)

You can get binary RPM / Debian packages at

* [Stable Releases](http://download.opensuse.org/repositories/home:/indimail/)
* [Experimental Releases](http://download.opensuse.org/repositories/home:/mbhangui/)

If you want to use DNF / YUM / apt-get, the corresponding install instructions for the two repositories, depending on whether you want to install a stable or an experimental release, are

* [Stable](https://software.opensuse.org/download.html?project=home%3Aindimail&package=libqmail)
* [Experimental](https://software.opensuse.org/download.html?project=home%3Ambhangui&package=libqmail)

```
Currently, the list of supported distributions for libqmail is

    * SUSE
          o openSUSE_Leap_15.0
          o openSUSE_Leap_15.1
          o openSUSE_Leap_15.2
          o openSUSE_Tumbleweed
          o SUSE Linux Enterprise 12
          o SUSE Linux Enterprise 12 SP1
          o SUSE Linux Enterprise 12 SP2
          o SUSE Linux Enterprise 12 SP3
          o SUSE Linux Enterprise 12 SP4
          o SUSE Linux Enterprise 12 SP5
          o SUSE Linux Enterprise 15
          o SUSE Linux Enterprise 15 SP1

    * Red Hat
          o Fedora 32
          o Fedora 33
          o Red Hat Enterprise Linux 7
          o CentOS 7
          o CentOS 8

    * Debian
          o Debian  9.0
          o Debian 10.0

    * Ubuntu
          o Ubuntu 16.04
          o Ubuntu 17.04
          o Ubuntu 18.04
          o Ubuntu 19.04
          o Ubuntu 19.10
          o Ubuntu 20.04
          o Ubuntu 20.10
```

# SUPPORT INFORMATION

libqmail is supported at IndiMail

## IRC / Matrix

* Join me [#indimail:matrix.org](https://matrix.to/#/#indimail:matrix.org)
* IndiMail has an IRC channel #indimail-mta

## Mailing list

There are four Mailing Lists for IndiMail

1. indimail-support  - You can subscribe for Support [here](https://lists.sourceforge.net/lists/listinfo/indimail-support). You can mail [indimail-support](mailto:indimail-support@lists.sourceforge.net) for support Old discussions can be seen [here](https://sourceforge.net/mailarchive/forum.php?forum_name=indimail-support)
2. indimail-devel - You can subscribe [here](https://lists.sourceforge.net/lists/listinfo/indimail-devel). You can mail [indimail-devel](mailto:indimail-devel@lists.sourceforge.net) for development activities. Old discussions can be seen [here](https://sourceforge.net/mailarchive/forum.php?forum_name=indimail-devel)
3. indimail-announce - This is only meant for announcement of New Releases or patches. You can subscribe [here](http://groups.google.com/group/indimail)
4. Archive at [Google Groups](http://groups.google.com/group/indimail). This groups acts as a remote archive for indimail-support and indimail-devel.

There is also a [Project Tracker](http://sourceforge.net/tracker/?group_id=230686) for IndiMail (Bugs, Feature Requests, Patches, Support Requests)
