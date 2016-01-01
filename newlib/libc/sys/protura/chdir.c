
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int chdir(const char *path)
{
    int ret;

    ret = syscall1(SYSCALL_CHDIR, (int)path);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

