
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _fcntl(int fd, int cmd, ...)
{
    errno = EACCES;
    return -1;
}

