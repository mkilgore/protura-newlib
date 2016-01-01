
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _close(int fd)
{
    int ret;
    ret = syscall1(SYSCALL_CLOSE, (uint32_t)fd);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

