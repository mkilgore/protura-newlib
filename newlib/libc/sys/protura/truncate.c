
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int truncate(const char *path, off_t length)
{
    int ret;

    ret = syscall2(SYSCALL_TRUNCATE, (int)path, (int)length);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

