#ifndef _SYS_FCNTL_H
#define _SYS_FCNTL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <protura/fs/fcntl.h>

extern int open _PARAMS((const char *, int, ...));
extern int creat _PARAMS((const char *, mode_t));

#ifdef _COMPILING_NEWLIB
extern int _open _PARAMS((const char *, int, ...));
extern int _fcntl _PARAMS((int, int, ...));
#endif

#endif
