
AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)
AM_CCASFLAGS = $(INCLUDES)

SUBDIRS = machine \
		  .

noinst_LIBRARIES = lib.a

toollibdir = $(tooldir)/lib$(MULTISUBDIR)
toollib_DATA = crtn.o crti.o

extra_sources = \
	read.c \
	write.c \
	open.c \
	close.c \
	link.c \
	unlink.c \
	mkdir.c \
	mknod.c \
	rmdir.c \
	rename.c \
	sync.c \
	wait.c \
	execve.c \
	_exit.c \
	sbrk.c \
	lseek.c \
	fstat.c \
	isatty.c \
	getdents.c \
	getpid.c \
	getppid.c \
	chdir.c \
	truncate.c \
	ftruncate.c \
	fork.c \
	fcntl.c \
	gettimeofday.c \
	kill.c \
	stat.c \
	times.c \
	pipe.c \
	dup.c \
	dup2.c \
	signal.c \
	symlink.c \
	mount.c \
	pgrp.c \
	ioctl.c \
	poll.c \
	termios.c \
	socket.c \
	arpa_inet.c

lib_a_SOURCES = $(extra_sources)
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

# This is necessary because automake doesn't think there are any .S sources
# here - The only one is crt0.S, which is used to build crt0.o.
#
# There is probably a better way to do this but this gets us what we want.
SUFFIXES = .S

all-local: crt0.o crtn.o crti.o

crt0.o: machine/crt0.o
	rm -f $@
	ln machine/crt0.o $@ >/dev/null 2>/dev/null || cp machine/crt0.o $@

machine/crt0.o: ; @true

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/arpa; \
	for i in $(srcdir)/include/arpa/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/arpa/`basename $$i`; \
	done; \
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/netinet; \
	for i in $(srcdir)/include/netinet/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/netinet/`basename $$i`; \
	done;

