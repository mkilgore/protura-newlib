
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mount.h>

int mount(const char *source, const char *target, const char *fsystem, unsigned long flags, const void *data)
{
    int ret;

    ret = syscall5(SYSCALL_MOUNT, (int)source, (int)target, (int)fsystem, (int)flags, (int)data);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int umount(const char *target)
{
    int ret;

    ret = syscall1(SYSCALL_UMOUNT, (int)target);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

