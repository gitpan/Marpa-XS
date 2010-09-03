## Makefile.am -- Process this file with automake to produce Makefile.in
ACLOCAL_AMFLAGS = -I m4
noinst_LIBRARIES = libmarpa.a
libmarpa_a_SOURCES = marpa.c utils.c
libmarpa_a_LIBADD = $(LIBOBJS)
libmarpa_a_CFLAGS = $(GLIB_CFLAGS)
include_HEADERS = utils.h

