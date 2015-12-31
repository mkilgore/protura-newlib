
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int open(const char *file, int flags, mode_t mode)
{
    int ret;
    ret = syscall3(SYSCALL_OPEN, (uint32_t)file, (uint32_t)flags, (uint32_t)mode);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

