applet_SCRIPTS = university-python-applet
appletdir = $(libexecdir)

APPLET_LOCATION = $(libexecdir)/university-python-applet

appletsdir       = $(datadir)/mate-panel/applets
applets_in_files = org.mate.university.PythonApplet.mate-panel-applet.in
applets_DATA     = $(applets_in_files:.mate-panel-applet.in=.mate-panel-applet)

org.mate.university.PythonApplet.mate-panel-applet: $(applets_in_files)
	$(AM_V_GEN)sed \
		-e "s|\@LOCATION\@|$(APPLET_LOCATION)|" \
		$< > $@

servicedir       = $(datadir)/dbus-1/services
service_in_files = org.mate.panel.applet.UniversityPythonAppletFactory.service.in
service_DATA     = $(service_in_files:.service.in=.service)

org.mate.panel.applet.UniversityPythonAppletFactory.service: $(service_in_files)
	$(AM_V_GEN)sed \
		-e "s|\@LOCATION\@|$(APPLET_LOCATION)|" \
		$< > $@

CLEANFILES = \
	$(applets_DATA) \
	$(service_DATA)

EXTRA_DIST = \
	$(applet_SCRIPTS) \
	$(applets_in_files) \
	$(service_in_files)

