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

int _EXFUN(isatty, (int __fildes));

int _EXFUN(link, (const char *__path1, const char *__path2));

off_t _EXFUN(lseek, (int __fildes, off_t __offset, int __whence));

void *_EXFUN(sbrk, (ptrdiff_t __incr));
int _EXFUN(unlink, (const char *__path));

pid_t   _EXFUN(fork, (void ));
pid_t   _EXFUN(vfork, (void ));

_READ_WRITE_RETURN_TYPE _EXFUN(read, (int __fd, void *__buf, size_t __nbyte));
_READ_WRITE_RETURN_TYPE _EXFUN(write, (int __fd, const void*__buf, size_t __nbyte));

extern char *optarg;
extern int optind, opterr, optopt;
int getopt(int, char *const[], const char *);
extern int optreset;

int _EXFUN(ftruncate, (int __fd, off_t __length));
int _EXFUN(truncate, (const char *, off_t __length));

int _EXFUN(pipe, (int __pipefd[2]));

int _EXFUN(pause, (void));
int _EXFUN(sleep, (int seconds));

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#ifdef __cplusplus
}
#endif

#endif
