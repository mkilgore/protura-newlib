
AUTOMAKE_OPTIONS = cygnus

# We're presumably not compiling this on a Protura system with a configured
# gcc (Since that's currently impossible), so we have to specify the include
# directory for the Protura headers by hand.
protura_include = -I$(srcdir)/../../../../../../../include -I$(srcdir)/../../../../../../../arch/x86/include

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS) $(protura_include)
AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

if MAY_SUPPLY_SYSCALLS

extra_sources = \
	read.c \
	write.c \
	execve.c \
	_exit.c

else
extra_sources =
endif

lib_a_SOURCES = $(extra_sources) crt0.S
lib_a_LIBADD =
# EXTRA_lib_a_SOURCES = $(extra_objs) crt0.S
lib_a_DEPENDENCIES =
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

if MAY_SUPPLY_SYSCALLS
all: crt0.o
endif

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host

