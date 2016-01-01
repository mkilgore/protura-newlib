
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

int _stat(char *file, struct stat *st)
{
    errno = EACCES;
    return -1;
}

