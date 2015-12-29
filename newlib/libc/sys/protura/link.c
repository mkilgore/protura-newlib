
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int link(const char *file, const char *file2)
{
    int ret;
    ret = syscall2(SYSCALL_UNLINK, (uint32_t)file, (uint32_t)file2);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

