
AC_INIT([mate-university],
        [1.7.0],
        [https://github.com/mate-desktop/mate-university/issues],
        [mate-university],
        [https://mate-desktop.org])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_HEADERS(config.h)
AC_PROG_CC
AC_PROG_INSTALL
AM_INIT_AUTOMAKE([1.9 no-dist-gzip dist-xz tar-ustar -Wno-portability])
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=mate-university
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Define the gettext package to be used])
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT

GTK_REQUIRED=3.0.0

# applet-c
PKG_CHECK_MODULES(APPLET, libmatepanelapplet-4.0 >= 1.7.0)
AC_SUBST(APPLET_CFLAGS)
AC_SUBST(APPLET_LIBS)

# cairo-test
PKG_CHECK_MODULES(CAIRO_TEST, gtk+-3.0 >= $GTK_REQUIRED)
AC_SUBST(CAIRO_TEST_CFLAGS)
AC_SUBST(CAIRO_TEST_LIBS)

AC_OUTPUT([
Makefile
applet-c/Makefile
applet-python/Makefile
cairo-test/Makefile
po/Makefile.in
])
