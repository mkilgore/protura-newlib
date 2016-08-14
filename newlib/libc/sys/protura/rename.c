
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int rename(const char *old, const char *new)
{
    int ret;
    ret = syscall2(SYSCALL_RENAME, (uint32_t)old, (uint32_t)new);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

