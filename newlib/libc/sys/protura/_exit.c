
#include "syscall.h"
#include <sys/errno.h>

void _fini(void);

void _exit(int code)
{
    _fini();
    syscall1(SYSCALL_EXIT, code);
    for (;;)
        ;
}

