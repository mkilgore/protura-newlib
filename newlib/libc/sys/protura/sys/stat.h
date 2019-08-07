#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <_ansi.h>
#include <sys/types.h>
#include <protura/fs/stat.h>

int _EXFUN(fstat, (int __fd, struct stat *__buf));
int _EXFUN(stat, (const char *__path, struct stat *__buf));
int _EXFUN(lstat, (const char *__path, struct stat *__buf));
int _EXFUN(mkdir, (const char *path, mode_t mode));
int _EXFUN(mknod, (const char *path, mode_t mode, dev_t dev));
int _EXFUN(mkfifo, (const char *path, mode_t mode));
mode_t _EXFUN(umask, (mode_t mode));
int _EXFUN(chmod, (const char *path, mode_t mode));

#ifdef _COMPILING_NEWLIB
int _EXFUN(_fstat, (int __fd, struct stat *__buf));
int _EXFUN(_stat, (const char *__path, struct stat *__buf));
int _EXFUN(_lstat, (const char *__path, struct stat *__buf));
#endif

#endif
