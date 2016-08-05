
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int rmdir(const char *file)
{
    int ret;
    ret = syscall1(SYSCALL_RMDIR, (uint32_t)file);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

