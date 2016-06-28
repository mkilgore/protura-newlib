
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int pipe(int pipefd[])
{
    int ret;
    ret = syscall1(SYSCALL_PIPE, (uint32_t)pipefd);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

