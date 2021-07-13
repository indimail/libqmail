all: debian.tar.gz
version=$(shell cat ../conf-version)
arch=$(shell uname -m)
email=$(shell cat ../conf-email)

edit = sed \
	-e 's,@version\@,$(version),g' \
	-e 's,@mandir\@,$(mandir),g' \
	-e "s,@release\@,"`cat ../conf-release`",g" \
	-e 's,@email\@,$(email),g' \
	-e 's,@prefix\@,$(prefix),g'

changelog: ../doc/ChangeLog Makefile ../conf-version ../conf-release \
../conf-email
	../catChangeLog --debian --name=libqmail --state=stable \
		--urgency=low ../doc/ChangeLog > $@
control: control.in ../conf-email
	$(edit) $@.in > $@
copyright: copyright.in ../conf-email
	$(edit) $@.in > $@

libqmail.dsc: libqmail.dsc.in ../conf-release ../conf-version ../conf-email
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
