## Makefile.am -- Process this file with automake to produce Makefile.in
ACLOCAL_AMFLAGS = -I m4
lib_LTLIBRARIES = libmarpa.la
libmarpa_la_SOURCES = marpa.c utils.c
include_HEADERS = utils.h
libmarpa_la_LIBADD = $(GLIB_LIBS)
libmarpa_la_CFLAGS = $(GLIB_CFLAGS)

EXTRA_DIST = \
	bootstrap \
	README

