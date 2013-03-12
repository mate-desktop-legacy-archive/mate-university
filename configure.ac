
AC_INIT([mate-university],
        [1.5.0],
        [https://github.com/mate-desktop/mate-university/issues],
        [mate-university],
        [http://www.mate-desktop.org])

AC_CONFIG_HEADERS(config.h)
AC_PROG_CC
AC_PROG_INSTALL
AM_INIT_AUTOMAKE([1.9 no-dist-gzip dist-xz tar-ustar -Wno-portability])
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=mate-university
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Define the gettext package to be used])
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT

# applet-c
PKG_CHECK_MODULES(APPLET, libmatepanelapplet-4.0 >= 1.5.0)
AC_SUBST(APPLET_CFLAGS)
AC_SUBST(APPLET_LIBS)

AC_OUTPUT([
Makefile
applet-c/Makefile
po/Makefile.in
])