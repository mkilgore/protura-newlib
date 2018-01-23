
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>

int _fstat(int fd, struct stat *buf)
{
    int ret;

    ret = syscall2(SYSCALL_FSTAT, fd, (int)buf);

    if (ret < 0) {
        errno = ret;
        return -1;
    }

    return 0;
}

