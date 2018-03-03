AM_CPPFLAGS = \
	$(APPLET_CFLAGS) \
	-I$(srcdir) \
	$(DISABLE_DEPRECATED_CFLAGS)
AM_CFLAGS = $(WARN_CFLAGS)

APPLET_SOURCES = applet.c
APPLET_LDADD = $(APPLET_LIBS)
APPLET_LOCATION = $(libexecdir)/university-applet

libexec_PROGRAMS = university-applet
university_applet_SOURCES = $(APPLET_SOURCES)
university_applet_LDADD = $(APPLET_LDADD)
university_applet_CFLAGS = $(AM_CFLAGS)

appletsdir       = $(datadir)/mate-panel/applets
applets_in_files = org.mate.university.Applet.mate-panel-applet.in
applets_DATA     = $(applets_in_files:.mate-panel-applet.in=.mate-panel-applet)

org.mate.university.Applet.mate-panel-applet: $(applets_in_files)
	$(AM_V_GEN)sed \
		-e "s|\@LOCATION\@|$(APPLET_LOCATION)|" \
		$< > $@

servicedir       = $(datadir)/dbus-1/services
service_in_files = org.mate.panel.applet.UniversityAppletFactory.service.in
service_DATA     = $(service_in_files:.service.in=.service)

org.mate.panel.applet.UniversityAppletFactory.service: $(service_in_files)
	$(AM_V_GEN)sed \
		-e "s|\@LOCATION\@|$(APPLET_LOCATION)|" \
		$< > $@

CLEANFILES = \
	$(applets_DATA) \
	$(service_DATA)

EXTRA_DIST = \
	$(applets_in_files) \
	$(service_in_files)

