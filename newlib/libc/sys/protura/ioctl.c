
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int ioctl(int fd, int cmd, int arg)
{
    int ret;
    ret = syscall3(SYSCALL_IOCTL, (uint32_t)fd, (uint32_t)cmd, (uint32_t)arg);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

