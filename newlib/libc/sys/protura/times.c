
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

int _times(struct tms *buf)
{
    errno = EACCES;
    return -1;
}

