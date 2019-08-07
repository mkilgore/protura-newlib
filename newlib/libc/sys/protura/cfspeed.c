
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

speed_t cfgetospeed(const struct termios *termios)
{
    return termios->c_cflag & CBAUD;
}

speed_t cfgetispeed(const struct termios *termios)
{
    return termios->c_cflag & CBAUD;
}

int cfsetospeed(struct termios *termios, speed_t speed)
{
    termios->c_cflag &= ~CBAUD;
    termios->c_cflag |= speed;

    return 0;
}

int cfsetispeed(struct termios *termios, speed_t speed)
{
    if (speed != 0)
    {
        termios->c_cflag &= ~CBAUD;
        termios->c_cflag |= speed;
    }

    return 0;
}
