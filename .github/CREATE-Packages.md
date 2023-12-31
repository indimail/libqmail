# Binary Packages Build

For this to work you need few things to be installed on your system. Check your system manual on how to install them.

* RPM based systems - rpm-build, gcc, g++, autoconf, automake, libtool, aclocal, rpmdevtools
* Debian based systems - build-essentials, cdbs, debhelper, gnupg2
* Arch Linux - base-devel

## Clone git repository and Create Binary packages

```
$ cd /usr/local/src
$ git clone https://github.com/indimail/libqmail.git
$ ./create_rpm     # for RPM
$ ./create_debian  # for deb
$ ./create_archpkg # for zst (Arch Linux)
```

## Install Packages

Installing and configuration is much simplied when you use the Binary Packages Build. The pre, post instlation scripts do all the hard work for you.

**For RPM based distributions**

```
$ sudo rpm -ivh file.rpm
```

**For Debian based distributions**

```
$ sudo dpkg -i file.deb
```

**For Arch Linux**

```
$ sudo pacman -U file.zst
```
