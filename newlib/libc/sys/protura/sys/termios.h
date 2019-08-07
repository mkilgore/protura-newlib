#ifndef _SYS_TERMIOS_H
#define _SYS_TERMIOS_H

#include <unistd.h>
#include <protura/drivers/tty.h>

pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pgrp);

int tcgetattr(int fd, struct termios *);
int tcsetattr(int fd, int optional, const struct termios *);

speed_t cfgetospeed(const struct termios *termios);
speed_t cfgetispeed(const struct termios *termios);
int cfsetospeed(struct termios *termios, speed_t speed);
int cfsetispeed(struct termios *termios, speed_t speed);

#endif
