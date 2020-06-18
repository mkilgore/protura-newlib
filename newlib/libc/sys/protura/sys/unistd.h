#ifndef _SYS_UNISTD_H
#define _SYS_UNISTD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#define __need_size_t
#define __need_ptrdiff_t
#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/_types.h>
#include <stddef.h>

extern char **environ;

void _EXFUN(_exit, (int __status) _ATTRIBUTE((__noreturn__)));

int _EXFUN(chdir, (const char *__path));
int _EXFUN(close, (int __fildes));

int _EXFUN(dup, (int oldfd));
int _EXFUN(dup2, (int oldfd, int newfd));

int _EXFUN(execl,  (const char *__path, const char *, ...));
int _EXFUN(execle,  (const char *__path, const char *, ...));
int _EXFUN(execlp, (const char *__file, const char *, ...));

int _EXFUN(execv,  (const char *__path, char *const __argv[]));
int _EXFUN(execve, (const char *__path, char *const __argv[], char *const __envp[]));
int _EXFUN(execvp, (const char *__file, char *const __argv[]));

void _EXFUN(sync, (void));

pid_t _EXFUN(getpid, (void));
pid_t _EXFUN(getppid, (void));

uid_t _EXFUN(getuid, (void));
uid_t _EXFUN(geteuid, (void));
int _EXFUN(setuid, (uid_t __uid ));
int _EXFUN(seteuid, (uid_t __uid ));
int _EXFUN(setreuid, (uid_t __ruid, uid_t __euid));
int _EXFUN(setresuid, (uid_t __ruid, uid_t __euid, uid_t __suid));

gid_t _EXFUN(getgid, (void));
gid_t _EXFUN(getegid, (void));
int _EXFUN(setgid, (gid_t __gid ));
int _EXFUN(setegid, (gid_t __gid ));
int _EXFUN(setregid, (gid_t __rgid, gid_t __egid));
int _EXFUN(setresgid, (gid_t __rgid, gid_t __egid, gid_t __sgid));

int _EXFUN(setgroups, (int ngroups, const gid_t *grouplist ));
int _EXFUN(getgroups, (int __gidsetsize, gid_t __grouplist[] ));

int _EXFUN(gethostname, (char *name, size_t len));
int _EXFUN(isatty, (int __fildes));

int _EXFUN(link, (const char *__path1, const char *__path2));

off_t _EXFUN(lseek, (int __fildes, off_t __offset, int __whence));

void *_EXFUN(sbrk, (ptrdiff_t __incr));
int _EXFUN(unlink, (const char *__path));

pid_t   _EXFUN(fork, (void ));
pid_t   _EXFUN(vfork, (void ));
pid_t   _EXFUN(fork_pgrp, (pid_t __pgrp));

_READ_WRITE_RETURN_TYPE _EXFUN(read, (int __fd, void *__buf, size_t __nbyte));
_READ_WRITE_RETURN_TYPE _EXFUN(write, (int __fd, const void*__buf, size_t __nbyte));

int _EXFUN(rmdir, (const char *__name));

extern char *optarg;
extern int optind, opterr, optopt;
int getopt(int, char *const[], const char *);
extern int optreset;

int _EXFUN(ftruncate, (int __fd, off_t __length));
int _EXFUN(truncate, (const char *, off_t __length));

int _EXFUN(pipe, (int __pipefd[2]));

int _EXFUN(pause, (void));
int _EXFUN(sleep, (int seconds));

ssize_t _EXFUN(readlink, (const char *__path, char *__buf, size_t __bufsize));
int _EXFUN(symlink, (const char *__target, const char *__linkpath));

int _EXFUN(setpgid, (pid_t __pid, pid_t __pgid));
int _EXFUN(setpgrp, (pid_t pid, pid_t pgid));
pid_t _EXFUN(getpgrp, (void));

pid_t _EXFUN(setsid, (void));
pid_t _EXFUN(getsid, (pid_t __pid));

char *_EXFUN(ttyname, (int __fd));
int   _EXFUN(ttyname_r, (int __fd, char *__buf, size_t __buflen));

int _EXFUN(access, (const char *__path, int __mode));
int _EXFUN(chown, (const char *pathname, uid_t owner, gid_t group));
int _EXFUN(lchown, (const char *pathname, uid_t owner, gid_t group));
int _EXFUN(fchown, (int __fd, uid_t owner, gid_t group));

char *_EXFUN(getcwd, (char *__buf, size_t __len));

long _EXFUN(pathconf, (const char *__path, int __name ));

unsigned int _EXFUN(alarm, (unsigned int __seconds));

#ifdef _COMPILING_NEWLIB
/* Definitions for newlib */
int _EXFUN(_close, (int __fildes));
pid_t _EXFUN(_fork, (void));
pid_t _EXFUN(_getpid, (void));
int _EXFUN(_isatty, (int __fildes));
int _EXFUN(_link, (const char *__path1, const char *__path2));
off_t _EXFUN(_lseek, (int __fildes, off_t __offset, int __whence));
_READ_WRITE_RETURN_TYPE _EXFUN(_read, (int __fd, void *__buf, size_t __nbyte));
_READ_WRITE_RETURN_TYPE _EXFUN(_write, (int __fd, const void *__buf, size_t __nbyte));
void *_EXFUN(_sbrk, (ptrdiff_t __incr));
int _EXFUN(_unlink, (const char *__path));
int _EXFUN(_execve, (const char *__path, char *const __argv[], char *const __envp[]));
#endif

#define	F_OK	0
#define	R_OK	4
#define	W_OK	2
#define	X_OK	1

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#define _PC_LINK_MAX                      0
#define _PC_MAX_CANON                     1
#define _PC_MAX_INPUT                     2
#define _PC_NAME_MAX                      3
#define _PC_PATH_MAX                      4
#define _PC_PIPE_BUF                      5
#define _PC_CHOWN_RESTRICTED              6
#define _PC_NO_TRUNC                      7
#define _PC_VDISABLE                      8
#define _PC_ASYNC_IO                      9
#define _PC_PRIO_IO                      10
#define _PC_SYNC_IO                      11
#define _PC_FILESIZEBITS                 12
#define _PC_2_SYMLINKS                   13
#define _PC_SYMLINK_MAX                  14
#define _PC_ALLOC_SIZE_MIN               15
#define _PC_REC_INCR_XFER_SIZE           16
#define _PC_REC_MAX_XFER_SIZE            17
#define _PC_REC_MIN_XFER_SIZE            18
#define _PC_REC_XFER_ALIGN               19
#define _PC_TIMESTAMP_RESOLUTION         20

#ifdef __cplusplus
}
#endif

#endif
