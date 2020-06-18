
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>
#include <utime.h>
#include <sys/time.h>

mode_t umask(mode_t new_mode)
{
    return syscall1(SYSCALL_UMASK, (int)new_mode);
}

int chmod(const char *path, mode_t mode)
{
    int ret;

    ret = syscall2(SYSCALL_CHMOD, (int)path, (int)mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int fchmod(int fd, mode_t mode)
{
    int ret;

    ret = syscall2(SYSCALL_FCHMOD, fd, (int)mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int chown(const char *pathname, uid_t owner, gid_t group)
{
    int ret;

    ret = syscall3(SYSCALL_CHOWN, (int)pathname, (int)owner, (int)group);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int lchown(const char *pathname, uid_t owner, gid_t group)
{
    int ret;

    ret = syscall3(SYSCALL_LCHOWN, (int)pathname, (int)owner, (int)group);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int fchown(int fd, uid_t owner, gid_t group)
{
    int ret;

    ret = syscall3(SYSCALL_FCHOWN, fd, (int)owner, (int)group);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int utimes(const char *filename, const struct timeval *times)
{
    int ret;

    ret = syscall2(SYSCALL_UTIMES, (int)filename, (int)times);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int utime(const char *filename, const struct utimbuf *times)
{
    struct timeval timevals[2];
    memset(&timevals, 0, sizeof(timevals));

    timevals[0].tv_sec = times->actime;
    timevals[2].tv_sec = times->modtime;

    return utimes(filename, timevals);
}
