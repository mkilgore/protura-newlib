
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

pid_t _wait(int *wait_ret)
{
    pid_t ret;
    ret = syscall1(SYSCALL_WAIT, (uint32_t)wait_ret);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

pid_t waitpid(pid_t child, int *wstatus, int options)
{
    pid_t ret;

    ret = syscall3(SYSCALL_WAITPID, (uint32_t)child, (uint32_t)wstatus, (uint32_t)options);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

