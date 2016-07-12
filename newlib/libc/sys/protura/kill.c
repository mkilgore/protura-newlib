
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

int _kill(pid_t pid, int sig)
{
    int ret;

    ret = syscall2(SYSCALL_KILL, (int)pid, sig);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

