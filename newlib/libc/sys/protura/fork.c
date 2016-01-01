
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

pid_t _fork(void)
{
    int ret;
    ret = syscall0(SYSCALL_FORK);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

pid_t vfork(void)
{
    return fork();
}

