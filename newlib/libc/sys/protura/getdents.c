
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdint.h>
#include <unistd.h>

int getdents(int fd, void *d_buf, int buf_size)
{
    int ret;

    ret = syscall3(SYSCALL_READ_DENT, fd, (int)d_buf, buf_size);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    if (ret == 0)
        return 0;

    return ((struct dirent *)(d_buf))->d_reclen;
}

