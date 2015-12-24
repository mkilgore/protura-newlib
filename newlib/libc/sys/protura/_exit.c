
#include "syscall.h"
#include <sys/errno.h>

void _exit(int code)
{
    syscall1(SYSCALL_EXIT, code);
    for (;;)
        ;
}

