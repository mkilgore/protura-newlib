#ifndef _SYS_TERMIOS_H
#define _SYS_TERMIOS_H

#include <unistd.h>
#include <protura/drivers/tty.h>

pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pgrp);

#endif
