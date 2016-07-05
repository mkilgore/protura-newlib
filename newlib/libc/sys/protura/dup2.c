
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int dup2(int oldfd, int newfd)
{
    int ret;

    ret = syscall2(SYSCALL_DUP2, oldfd, newfd);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

