
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>


int setpgid(pid_t pid, pid_t pgid)
{
    int ret;

    ret = syscall2(SYSCALL_SETPGID, (uint32_t)pid, (uint32_t)pgid);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int setpgrp(pid_t pid, pid_t pgid)
{
    return setpgid(pid, pgid);
}

pid_t getpgrp(void)
{
    pid_t pgid = 0;
    int ret;

    ret = syscall1(SYSCALL_GETPGRP, (uint32_t)&pgid);

    return pgid;
}

pid_t setsid(void)
{
    int ret;

    ret = syscall0(SYSCALL_SETSID);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

pid_t getsid(pid_t pid)
{
    pid_t ret;

    ret = syscall1(SYSCALL_GETSID, pid);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

