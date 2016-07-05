
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int dup(int oldfd)
{
    int ret;

    ret = syscall1(SYSCALL_DUP, oldfd);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

