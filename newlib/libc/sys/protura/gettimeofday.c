
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

int _gettimeofday(struct timeval *tv, void *vtz)
{
    struct timezone *tz = vtz;

    int ret = syscall2(SYSCALL_GETTIMEOFDAY, tv, vtz);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

time_t time(time_t *t)
{
    int ret;
    struct timeval tv;

    ret = _gettimeofday(&tv, NULL);

    if (ret < 0)
        return -1;

    return tv.tv_sec;
}

int usleep(useconds_t seconds)
{
    int ret = syscall1(SYSCALL_USLEEP, seconds);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
