SUBDIRS = po applet-c applet-python cairo-test

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
			INSTALL \
			$(top_srcdir)/applet-c/org.mate.university.Applet.mate-panel-applet.in \
			$(top_srcdir)/applet-c/org.mate.university.Applet.mate-panel-applet \
			$(top_srcdir)/applet-c/org.mate.panel.applet.UniversityAppletFactory.service \
			$(top_srcdir)/applet-python/org.mate.university.PythonApplet.mate-panel-applet.in \
			$(top_srcdir)/applet-python/org.mate.university.PythonApplet.mate-panel-applet \
			$(top_srcdir)/applet-python/org.mate.panel.applet.UniversityPythonAppletFactory.service

mu-clean: maintainer-clean
	-test -z "$(MUCLEANFILES)" || rm -f $(MUCLEANFILES)
	find . -name "Makefile.in" -exec rm \{\} \;

.PHONY: mu-clean
