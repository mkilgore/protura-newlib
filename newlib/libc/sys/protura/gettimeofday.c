
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _gettimeofday(struct timeval *tv, struct timezone *tz)
{
    errno = EINVAL;
    return -1;
}

