
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _fstat(int fd, struct stat *buf)
{
    errno = EACCES;
    return -1;
}

