
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

pid_t _getpid(void)
{
    return syscall0(SYSCALL_GETPID);
}

