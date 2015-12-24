
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _execve(const char *filename, char *const argv[], char *const envp[])
{
    int ret;
    ret = syscall3(SYSCALL_EXECVE, (uint32_t)filename, (uint32_t)argv, (uint32_t)envp);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

