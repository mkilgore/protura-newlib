
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int fstat(int fd, struct stat *buf)
{
    return -EACCES;
}

