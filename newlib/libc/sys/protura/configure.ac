AC_PREREQ(2.59)
AC_INIT([newlib], [NEWLIB_VERSION])
AC_CONFIG_SRCDIR([open.c])
dnl Can't be done in NEWLIB_CONFIGURE because that confuses automake. 
AC_CONFIG_AUX_DIR(../../../..)

NEWLIB_CONFIGURE(../../..)

AC_CONFIG_SUBDIRS([machine])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

