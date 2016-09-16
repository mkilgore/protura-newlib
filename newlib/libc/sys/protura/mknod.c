
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int mknod(const char *file, mode_t mode, dev_t dev)
{
    int ret;
    ret = syscall3(SYSCALL_MKNOD, (uint32_t)file, (uint32_t)mode, (uint32_t)dev);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int mkfifo(const char *fifo, mode_t mode)
{
    return mknod(fifo, mode, 0);
}

