

#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _kill(pid_t pid, int sig)
{
    errno = EINVAL;
    return -1;
}

