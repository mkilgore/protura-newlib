
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>


pid_t tcgetpgrp(int fd)
{
    int ret;
    pid_t pgrp = 0;

    ret = ioctl(fd, TIOCGPGRP, &pgrp);

    if (ret == -1)
        return -1;

    return pgrp;
}

int tcsetpgrp(int fd, pid_t pgrp)
{
    return ioctl(fd, TIOCSPGRP, &pgrp);
}

