
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int mkdir(const char *file, mode_t mode)
{
    int ret;
    ret = syscall2(SYSCALL_MKDIR, (uint32_t)file, (uint32_t)mode);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

