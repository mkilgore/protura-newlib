
## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

SUBDIRS = $(machine_dir) .

noinst_DATA = crt0.o

crt0.o: $(machine_dir)/crt0.o
	rm -f $@
	ln $(machine_dir)/crt0.o $@ >/dev/null 2>/dev/null \
	 || cp $(machine_dir)/crt0.o $@

$(machine_dir)/crt0.o: ; @true
	
all-local: crt0.o

CLEANFILES = crt0.o

doc:

ACLOCAL_AMFLAGS = -I ../../../.. -I ../../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host

