SUBDIRS = applet-c applet-python cairo-test

# project cleanup
MUCLEANFILES = aclocal.m4 \
			compile \
			config.* \
			configure \
			depcomp \
			install-sh \
			missing \
			omf.make \
			xmldocs.make \
			INSTALL

mu-clean: maintainer-clean
	-test -z "$(MUCLEANFILES)" || rm -f $(MUCLEANFILES)
	find . -name "Makefile.in" -exec rm \{\} \;

.PHONY: mu-clean
