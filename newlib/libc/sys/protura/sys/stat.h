#ifndef _SYS_STAT_H
#define _SYS_STAT_H

#include <sys/types.h>
#include <protura/fs/stat.h>

int _EXFUN(fstat, (int __fd, struct stat *__buf));
int _EXFUN(stat, (const char *__restrict __path, struct stat *__restrict __buf));

#endif
