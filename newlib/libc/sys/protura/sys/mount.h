#ifndef _SYS_MOUNT_H
#define _SYS_MOUNT_H

#include <sys/types.h>

int _EXFUN(mount, (const char *__source, const char *__target, const char *__fsystem, unsigned long __flags, const void *__data));
int _EXFUN(umount, (const char *__mountpoint));

#endif
