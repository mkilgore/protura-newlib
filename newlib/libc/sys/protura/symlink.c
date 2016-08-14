
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int symlink(const char *target, const char *path)
{
    int ret;

    ret = syscall2(SYSCALL_SYMLINK, (int)target, (int)path);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

ssize_t readlink(const char *path, char *buf, size_t bufsize)
{
    int ret;

    ret = syscall3(SYSCALL_READLINK, (int)path, (int)buf, (int)bufsize);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

