
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

void sync(void)
{
    syscall0(SYSCALL_SYNC);
    return ;
}

