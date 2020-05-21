all: debian.tar.gz
version=$(shell cat ../conf-version)
release := $(shell head -1 ../conf-release 2>/dev/null|| echo "1.1")

edit = sed \
	-e 's,@version\@,$(version),g' \
	-e 's,@mandir\@,$(mandir),g' \
	-e 's,@release\@,$(release),g' \
	-e 's,@prefix\@,$(prefix),g'

changelog: changelog.in ../conf-release ../conf-version
	(cat $@.in; echo ""; \
	echo " -- libqmail <libqmail@indimail.org>  `date +'%a, %d %b %Y %H:%S:%M %z'`" ) \
	| $(edit) > $@

libqmail.dsc: libqmail.dsc.in ../conf-release ../conf-version
	$(edit) $@.in > $@

debian.tar.gz: changelog compat control copyright libqmail-dev.dirs \
libqmail-dev.docs libqmail-dev.install libqmail.dirs libqmail.docs \
libqmail.dsc libqmail.install README rules
	tar cf - changelog compat control copyright libqmail-dev.dirs \
		libqmail-dev.docs libqmail-dev.install libqmail.dirs libqmail.docs \
		libqmail.dsc libqmail.install README rules |gzip -c >$@
