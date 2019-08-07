
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>
#include <utime.h>

mode_t umask(mode_t new_mode)
{
    return 0;
}

uid_t getuid(void)
{
    return 0;
}

gid_t getgid(void)
{
    return 0;
}

int chown(const char *pathname, uid_t owner, gid_t group)
{
    return 0;
}

int utime(const char *filename, const struct utimbuf *times)
{
    return 0;
}


