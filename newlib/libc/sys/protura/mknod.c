
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int mknod(const char *file, mode_t mode, dev_t dev)
{
    int ret;
    printf("mknod: %hd, unsigned: %d\n", dev, (uint32_t)dev);
    ret = syscall3(SYSCALL_MKNOD, (uint32_t)file, (uint32_t)mode, (uint32_t)dev);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

