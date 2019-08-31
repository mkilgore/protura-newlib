
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/utsname.h>

int uname(struct utsname *__name)
{
    int ret = syscall1(SYSCALL_UNAME, (uint32_t)__name);
    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}
