[![Matrix](https://img.shields.io/matrix/indimail:matrix.org.svg)](https://matrix.to/#/#indimail:matrix.org)

**Compilation Status (from Github Actions)**

[![libqmail Ubuntu, Mac OSX](https://github.com/indimail/libqmail/actions/workflows/libqmail-c-cpp.yml/badge.svg)](https://github.com/indimail/libqmail/actions/workflows/libqmail-c-cpp.yml)
[![libqmail FreeBSD](https://github.com/indimail/libqmail/actions/workflows/libqmail-freebsd.yml/badge.svg)](https://github.com/indimail/libqmail/actions/workflows/libqmail-freebsd.yml)

# Introduction

libqmail is a library of general purpose APIs extracted from Dan Bernstein's [qmail](http://cr.yp.to/qmail.html), reimplemented and covered by the GNU General Public License Version. Many of the functions implemented here have since been placed in the public domain. Many of the functions have been generously borrowed from [libowfat](http://www.fefe.de/libowfat/). libqmail is used by [indimail-mta](https://github.com/indimail/indimail-mta) and it's subpackages daemontools and ucspi-tcp, [indimail-virtualdomains](https://github.com/indimail/indimail-virtualdomains), [ezmlm](https://github.com/indimail/ezmlm), [ezmlm-idx](https://github.com/indimail/ezmlm-idx), [tinydnssec](https://github.com/indimail/tinydnssec). It is also used by [mpdev](https://github.com/indimail/mpdev) - An event watcher for [Music Player Daemon (mpd)](https://www.musicpd.org/). The library comes with a set of man pages, though few are missing. Another thing that is missing are the DNS, ipv4 and ipv6 functions. They are in the todo list.

# Compilation

You will need to have the compiler, make, autoconf, automake, libtool, m4 installed.

```
Linux (RPM based)
# yum/dnf install gcc gcc-c++ autoconf automake libtool pkgconfig m4 sed findutils diffutils openssl-devel libsodium-devel

Linux (Debian based)
# apt-get install build-essential gcc g++ autoconf automake libtool pkg-config m4 libssl-dev libsodium-dev

Linux (Arch Linux)
# pacman -S --needed archlinux-keyring
# pacman -S --refresh --sysupgrade
# pacman -S base-devel diffutils coreutils openssl libsodium

Gentoo Linux
# emaint -a sync
# emerge-webrsync
# emerge -a app-portage/eix
# emerge -a dev-libs/libsodium
# eix-sync
# etc-update

FreeBSD
# pkg install automake autoconf libtool pkgconf libsodium

Darwin
# port install autoconf libtool automake pkgconfig openssl libsodium
# port update outdated

alpine Linux

# apk add gcc g++ make git autoconf automake libtool m4 sed openssl-dev libsodium-dev
```

* NOTE: For Darwin (Mac OSX), install [MacPorts](https://www.macports.org/) or [Homebrew](https://brew.sh/). You can look at this [document](https://paolozaino.wordpress.com/2015/05/05/how-to-install-and-use-autotools-on-mac-os-x/) for installing MacPorts.
* NOTE: libqmail build has been done with clang and gcc. So the instructions should work fine if you have either of them on FreeBSD or Darwin (Mac OSX)
* NOTE: The crypt(3) function on OSX is crippled. the default.configure script passes --enable-passwd-hash=md5 to the configure script. This enables the internal hash functions instead of the crippled system supplied crypt(3) function. Read about his issue [here](https://stackoverflow.com/questions/32569597/how-to-get-same-crypt3-function-in-mac-os-x-as-linux-gcc-gnu-crypt3-linux-g) and [here](https://bugs.python.org/issue33213).
* NOTE: If you use brew to install openssl on OSX, then you have to do some crazy stuff like setting CPPFLAGS and LDFLAGS before calling default.configure and make commands given below in this document. Using macports is cleaner and easier.

```
CPPFLAGS="-I/usr/local/opt/openssl@1.1/include"
LDFLAGS="-L/usr/local/opt/openssl@1.1/lib"
```

```
$ cd /usr/local/src
$ git clone https://github.com/indimail/libqmail.git
$ cd /usr/local/src/libqmail/libqmail
$ ./default.configure
$ make
$ sudo make install
```

# Binary Builds on openSUSE Build Service and Copr

**[Build Status on](https://build.opensuse.org/project/monitor/home:mbhangui) [Open Build Service](https://build.opensuse.org/project/show/home:mbhangui)**

[![libqmail obs CI](https://github.com/indimail/libqmail/actions/workflows/libqmail-obs.yml/badge.svg)](https://github.com/indimail/libqmail/actions/workflows/libqmail-obs.yml)

[![libqmail](https://build.opensuse.org/projects/home:mbhangui/packages/libqmail/badge.svg?type=percent)](https://build.opensuse.org/package/show/home:mbhangui/libqmail)

You can get binary RPM / Debian packages at

* [Stable Releases](http://download.opensuse.org/repositories/home:/indimail/)
* [Experimental Releases](http://download.opensuse.org/repositories/home:/mbhangui/)
* [copr Releases](https://copr.fedorainfracloud.org/coprs/cprogrammer/indimail)

If you want to use DNF / YUM / apt-get, the corresponding install instructions for the two repositories, depending on whether you want to install a stable or an experimental release, are

* [Stable](https://software.opensuse.org/download.html?project=home%3Aindimail&package=libqmail)
* [Experimental](https://software.opensuse.org/download.html?project=home%3Ambhangui&package=libqmail)
* [copr Releases](https://copr.fedorainfracloud.org/coprs/cprogrammer/indimail). The copr repository can be enabled by running the command 
  `$ sudo dnf copr enable cprogrammer/indimail`

**[Build Status on](https://copr.fedorainfracloud.org/coprs/cprogrammer/indimail/monitor/) [copr](https://copr.fedorainfracloud.org/coprs/)**

[![libqmail](https://copr.fedorainfracloud.org/coprs/cprogrammer/indimail/package/libqmail/status_image/last_build.png)](https://copr.fedorainfracloud.org/coprs/cprogrammer/indimail/package/libqmail/)

```
Currently, the list of supported binary distributions for libqmail is

    * Arch Linux

    * SUSE
          o openSUSE_Leap_15.4
          o openSUSE_Leap_15.5
          o openSUSE_Leap_15.6
          o openSUSE_Tumbleweed
          o SUSE Linux Enterprise 12
          o SUSE Linux Enterprise 12 SP1
          o SUSE Linux Enterprise 12 SP2
          o SUSE Linux Enterprise 12 SP3
          o SUSE Linux Enterprise 12 SP4
          o SUSE Linux Enterprise 12 SP5
          o SUSE Linux Enterprise 15
          o SUSE Linux Enterprise 15 SP1
          o SUSE Linux Enterprise 15 SP2
          o SUSE Linux Enterprise 15 SP3
          o SUSE Linux Enterprise 15 SP4
          o SUSE Linux Enterprise 15 SP5
          o SUSE Linux Enterprise 15 SP6

    * Red Hat
          o Fedora 39
          o Fedora 40
          o Fedora Rawhide
          o Red Hat Enterprise Linux 7
          o Red Hat Enterprise Linux 8 +
          o Red Hat Enterprise Linux 9 +
          o EPEL 8 +
          o EPEL 9 +
          o Scientific Linux 7
          o CentOS 7
          o CentOS 8
          o CentOS 8  Stream
          o CentOS 9  Stream
          o CentOS 10 Stream
          o RockyLinux 8
          o RockyLinux 9
          o OracleLinux 8
          o OracleLinux 9
          o AlmaLinux 8
          o AlmaLinux 9
          o AmazonLinux 2023

          +: Some of the above Red Hat flavoured distributions are available
             only on copr (RHEL 8, RHEL9, EPEL9, EPEL9)

    * Debian
          o Debian 10.0
          o Debian 11.0
          o Debian 12.0

    * Ubuntu
          o Ubuntu 18.04
          o Ubuntu 20.04
          o Ubuntu 22.04
          o Ubuntu 23.04
          o Ubuntu 24.04

    * Mageia
          o Mageia 8
          o Mageia 9
```

NOTE: You can also build local binary packages. To generate RPM packages locally for all components refer to [Create Local Binary Packages](.github/CREATE-Packages.md)

# SUPPORT INFORMATION

libqmail is supported at IndiMail and you can contact on IRC or mailing list

## IRC / Matrix

[![Matrix](https://img.shields.io/matrix/indimail:matrix.org.svg)](https://matrix.to/#/#indimail:matrix.org)

* Join me [#indimail:matrix.org](https://matrix.to/#/#indimail:matrix.org)
* IndiMail has an IRC channel #indimail-mta

## Mailing list

There are two Mailing Lists for IndiMail

1. indimail-support  - You can subscribe for Support [here](https://lists.sourceforge.net/lists/listinfo/indimail-support). You can mail [indimail-support](mailto:indimail-support@lists.sourceforge.net) for support Old discussions can be seen [here](https://sourceforge.net/mailarchive/forum.php?forum_name=indimail-support)
2. Archive at [Google Groups](http://groups.google.com/group/indimail). This groups acts as a remote archive for indimail-support and indimail-devel.

There is also a [Project Tracker](http://sourceforge.net/tracker/?group_id=230686) for IndiMail (Bugs, Feature Requests, Patches, Support Requests)
