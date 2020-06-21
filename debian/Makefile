all: debian.tar.gz
version=$(shell cat ../conf-version)
arch=$(shell uname -m)

edit = sed \
	-e 's,@version\@,$(version),g' \
	-e 's,@mandir\@,$(mandir),g' \
	-e "s,@release\@,"`cat ../conf-release`",g" \
	-e 's,@prefix\@,$(prefix),g'

changelog: changelog.in ../conf-release ../conf-version
	(cat $@.in; echo ""; \
	echo " -- libqmail <libqmail@indimail.org>  `date +'%a, %d %b %Y %H:%M:%S %z'`" ) \
	| $(edit) > $@

libqmail.dsc: libqmail.dsc.in ../conf-release ../conf-version
	$(edit) $@.in > $@

libqmail.install: libqmail.install.in
	$(edit) $@.in > $@

libqmail-dev.install: libqmail-dev.install.in
	$(edit) $@.in > $@

clean:
	/bin/rm -f changelog libqmail.dsc libqmail.install libqmail-dev.install

debian.tar.gz: changelog compat control copyright libqmail-dev.dirs \
libqmail-dev.docs libqmail.dirs libqmail.docs \
libqmail.dsc README rules libqmail.install \
libqmail-dev.install
	tar cf - changelog compat control copyright libqmail-dev.dirs \
		libqmail-dev.docs libqmail.dirs libqmail.docs \
		libqmail.dsc README rules libqmail.install \
		libqmail-dev.install |gzip -c >$@
