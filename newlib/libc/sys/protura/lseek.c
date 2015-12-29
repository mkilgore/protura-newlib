
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence)
{
    int ret;
    ret = syscall3(SYSCALL_LSEEK, fd, (uint32_t)offset, whence);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (off_t)ret;
}

