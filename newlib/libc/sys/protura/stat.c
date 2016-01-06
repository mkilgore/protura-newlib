
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _stat(char *file, struct stat *st)
{
    int ret;

    ret = syscall2(SYSCALL_STAT, (int)file, (int)st);

    if (ret < 0) {
        errno = ret;
        return -1;
    }

    return 0;
}

