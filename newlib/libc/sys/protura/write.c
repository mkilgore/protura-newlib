
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    int ret;
    ret = syscall3(SYSCALL_WRITE, (uint32_t)fd, (uint32_t)buf, (uint32_t)count);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
