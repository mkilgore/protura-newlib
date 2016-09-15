
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <poll.h>

int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    int ret;

    ret = syscall3(SYSCALL_POLL, (int)fds, (int)nfds, timeout);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

