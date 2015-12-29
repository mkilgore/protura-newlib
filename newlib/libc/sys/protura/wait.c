
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int wait(int *wait_ret)
{
    int ret;
    ret = syscall1(SYSCALL_WAIT, (uint32_t)wait_ret);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

