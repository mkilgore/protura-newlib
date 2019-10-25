
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/reboot.h>

int reboot(int magic1, int magic2, int cmd)
{
    int ret = syscall3(SYSCALL_REBOOT, (uint32_t)magic1, (uint32_t)magic2, (uint32_t)cmd);
    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}
