
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>

int _stat(const char *file, struct stat *st)
{
    int ret;

    ret = syscall2(SYSCALL_STAT, (int)file, (int)st);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int lstat(const char *file, struct stat *st)
{
    int ret;

    ret = syscall2(SYSCALL_LSTAT, (int)file, (int)st);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int access(const char *path, int mode)
{
    int ret;

    ret = syscall2(SYSCALL_ACCESS, (int)path, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int gethostname(char *name, size_t len)
{
    strncpy(name, "Laptop", len);
    return 0;
}
