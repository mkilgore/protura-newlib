
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

time_t time(time_t *t)
{
    int ret;
    time_t tim;

    ret = syscall1(SYSCALL_TIME, (uint32_t)&tim);
    if (ret) {
        errno = -ret;
        return (time_t)-1;
    }

    if (t)
        *t = tim;

    return tim;
}

int _gettimeofday(struct timeval *tv, void *vtz)
{
    struct timezone *tz = vtz;
    time_t t = time(NULL);

    if (t == (time_t)-1)
        return -1;

    tv->tv_sec = t;
    tv->tv_usec = 0;

    return 0;
}

