bin_PROGRAMS = cairo-test

AM_CPPFLAGS = \
	$(CAIRO_TEST_CFLAGS) \
	-I$(srcdir) \
	-DMATELOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	$(DISABLE_DEPRECATED_CFLAGS)
AM_CFLAGS = $(WARN_CFLAGS)

cairo_test_SOURCES = cairo-test.c
cairo_test_LDADD = $(CAIRO_TEST_LIBS)
