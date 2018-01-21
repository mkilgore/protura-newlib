## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

# LIB_SOURCES = get_clockfreq.c getpagesize.c hp-timing.c setjmp.S sigaction.c dl-procinfo.c

# liblinuxi386_la_LDFLAGS = -Xcompiler -nostdlib

AM_CFLAGS = -I$(srcdir)/../..
AM_CCASFLAGS = -I$(srcdir)/../.. $(INCLUDES)

# if USE_LIBTOOL
# noinst_LTLIBRARIES = liblinuxi386.la
# liblinuxi386_la_SOURCES = $(LIB_SOURCES)
# noinst_DATA = objectlist.awk.in
# else
# noinst_LIBRARIES = lib.a
# lib_a_SOURCES = $(LIB_SOURCES)
# lib_a_CFLAGS = $(AM_CFLAGS)
# lib_a_CCASFLAGS = $(AM_CCASFLAGS)
# noinst_DATA =
# endif # USE_LIBTOOL

include $(srcdir)/../../../../../Makefile.shared

# This is necessary because automake doesn't think there are any .S sources
# here - The only one is crt0.S, which is used to build crt0.o.
#
# There is probably a better way to do this but this gets us what we want.
SUFFIXES = .S

all-local: crt0.o

ACLOCAL_AMFLAGS = -I ../../../../.. -I ../../../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
