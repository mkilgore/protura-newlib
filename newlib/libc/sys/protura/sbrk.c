
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

void *_sbrk(ptrdiff_t increment)
{
    int ret;
    ret = syscall1(SYSCALL_SBRK, (uint32_t)increment);
    return (void *)ret;
}

