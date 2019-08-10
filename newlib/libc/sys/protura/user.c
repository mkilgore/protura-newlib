
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
    return syscall0(SYSCALL_GETUID);
}

uid_t geteuid(void)
{
    return syscall0(SYSCALL_GETEUID);
}

int setuid(uid_t uid)
{
    return syscall1(SYSCALL_SETUID, (int)uid);
}

int seteuid(uid_t uid)
{
    return setresuid((uid_t)-1, uid, (uid_t)-1);
}

int setreuid(uid_t ruid, uid_t euid)
{
    return syscall2(SYSCALL_SETREUID, (int)ruid, (int)euid);
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
    return syscall3(SYSCALL_SETRESUID, (int)ruid, (int)euid, (int)suid);
}

gid_t getgid(void)
{
    return syscall0(SYSCALL_GETGID);
}

gid_t getegid(void)
{
    return syscall0(SYSCALL_GETEGID);
}

int setgid(gid_t gid)
{
    return syscall1(SYSCALL_SETGID, (int)gid);
}

int setegid(gid_t gid)
{
    return setresgid((gid_t)-1, gid, (gid_t)-1);
}

int setregid(gid_t rgid, gid_t egid)
{
    return syscall2(SYSCALL_SETREGID, (int)rgid, (int)egid);
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
    return syscall3(SYSCALL_SETRESGID, (int)rgid, (int)egid, (int)sgid);
}

int chown(const char *pathname, uid_t owner, gid_t group)
{
    return 0;
}

int utime(const char *filename, const struct utimbuf *times)
{
    return 0;
}


