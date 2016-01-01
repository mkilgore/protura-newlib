
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

pid_t getppid(void)
{
    return syscall0(SYSCALL_GETPPID);
}

