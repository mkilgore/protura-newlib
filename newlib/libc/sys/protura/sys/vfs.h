#ifndef _SYS_VFS_H
#define _SYS_VFS_H

#include <protura/block/statvfs.h>

typedef __kfsblkcnt_t fsblkcnt_t;
typedef __kfsfilcnt_t fsfilcnt_t;

int statvfs(const char *path, struct statvfs *buf);
int fstatvfs(int fd, struct statvfs *buf);

#endif
