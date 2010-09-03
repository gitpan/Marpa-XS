dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)

dnl ***********************************
dnl *** include special libmarpa macros ***
dnl ***********************************

m4_define(libmarpa_configure_in)

# Making releases:
#   libmarpa_micro_version += 1;
#   libmarpa_interface_age += 1;
#   libmarpa_binary_age += 1;
# if any functions have been added, set libmarpa_interface_age to 0.
# if backwards compatibility has been broken,
# set libmarpa_binary_age _and_ libmarpa_interface_age to 0.
#
m4_define([libmarpa_major_version], [0])
m4_define([libmarpa_minor_version], [1])
m4_define([libmarpa_micro_version], [0])
m4_define([libmarpa_interface_age], [100])
m4_define([libmarpa_binary_age],
          [m4_eval(100 * libmarpa_minor_version + libmarpa_micro_version)])
m4_define([libmarpa_version],
          [libmarpa_major_version.libmarpa_minor_version.libmarpa_micro_version])

# libtool version related macros
m4_define([libmarpa_lt_release], [libmarpa_major_version.libmarpa_minor_version])
m4_define([libmarpa_lt_current],
          [m4_eval(100 * libmarpa_minor_version + libmarpa_micro_version - libmarpa_interface_age)])
m4_define([libmarpa_lt_revision], [libmarpa_interface_age])
m4_define([libmarpa_lt_age], [m4_eval(libmarpa_binary_age - libmarpa_interface_age)])
m4_define([libmarpa_lt_current_minus_age],
          [m4_eval(libmarpa_lt_current - libmarpa_lt_age)])

# if the minor version number is odd, then we want debugging.  Otherwise
# we only want minimal debugging support.
m4_define([libmarpa_debug_default],
          [m4_if(m4_eval(libmarpa_minor_version % 2), [1], [yes], [minimum])])dnl

AC_INIT([libmarpa], [libmarpa_version],
    [http://rt.cpan.org/NoAuth/Bugs.html?Dist=Marpa])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Specify a configuration file
AC_CONFIG_HEADERS([config.h])

LIBMARPA_MAJOR_VERSION=libmarpa_major_version
LIBMARPA_MINOR_VERSION=libmarpa_minor_version
LIBMARPA_MICRO_VERSION=libmarpa_micro_version
LIBMARPA_INTERFACE_AGE=libmarpa_interface_age
LIBMARPA_BINARY_AGE=libmarpa_binary_age
LIBMARPA_VERSION=libmarpa_version

AC_SUBST(LIBMARPA_MAJOR_VERSION)
AC_SUBST(LIBMARPA_MINOR_VERSION)
AC_SUBST(LIBMARPA_MICRO_VERSION)
AC_SUBST(LIBMARPA_VERSION)
AC_SUBST(LIBMARPA_INTERFACE_AGE)
AC_SUBST(LIBMARPA_BINARY_AGE)

AC_DEFINE(LIBMARPA_MAJOR_VERSION, [libmarpa_major_version],
	  [Define to the LIBMARPA major version])
AC_DEFINE(LIBMARPA_MINOR_VERSION, [libmarpa_minor_version],
	  [Define to the LIBMARPA minor version])
AC_DEFINE(LIBMARPA_MICRO_VERSION, [libmarpa_micro_version],
	  [Define to the LIBMARPA micro version])
AC_DEFINE(LIBMARPA_INTERFACE_AGE, [libmarpa_interface_age],
	  [Define to the LIBMARPA interface age])
AC_DEFINE(LIBMARPA_BINARY_AGE, [libmarpa_binary_age],
	  [Define to the LIBMARPA binary age])

# libtool versioning
LT_RELEASE=libmarpa_lt_release
LT_CURRENT=libmarpa_lt_current
LT_REVISION=libmarpa_lt_revision
LT_AGE=libmarpa_lt_age
LT_CURRENT_MINUS_AGE=libmarpa_lt_current_minus_age
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)
AC_SUBST(LT_CURRENT_MINUS_AGE)

dnl declare --enable-* args and collect ac_help strings
AC_ARG_ENABLE(debug,
              AC_HELP_STRING([--enable-debug=@<:@no/minimum/yes@:>@],
                             [turn on debugging @<:@default=libmarpa_debug_default@:>@]),,
              enable_debug=libmarpa_debug_default)

AC_PROG_CC
AC_PROG_RANLIB
AC_C_INLINE
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LN_S

PKG_PROG_PKG_CONFIG([0.22])
PKG_CHECK_MODULES(GLIB, [glib-2.0 >= 2.6.0] )

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

