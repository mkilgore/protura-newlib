
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
{
    int ret;

    ret = syscall3(SYSCALL_SIGACTION, signum, (int)act, (int)oldact);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int sigpending(sigset_t *set)
{
    int ret;

    ret = syscall1(SYSCALL_SIGPENDING, (int)set);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int sigwait(const sigset_t *set, int *sig)
{
    int ret;

    ret = syscall2(SYSCALL_SIGWAIT, (int)set, (int)sig);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
    int ret;

    ret = syscall3(SYSCALL_SIGPROCMASK, how, (int)set, (int)oldset);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

_sig_func_ptr signal(int signum, _sig_func_ptr handler)
{
    _sig_func_ptr ret;

    ret = (_sig_func_ptr)syscall2(SYSCALL_SIGNAL, signum, (int)handler);

    return ret;
}

int pause(void)
{
    int ret;

    ret = syscall0(SYSCALL_PAUSE);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int sigsuspend(const sigset_t *mask)
{
    int ret;

    ret = syscall1(SYSCALL_SIGSUSPEND, (int)mask);

    if (ret) {
        errno = -ret;
        return -1;
    }

    return 0;
}

int sleep(int seconds)
{
    int ret;

    ret = syscall1(SYSCALL_SLEEP, seconds);

    return ret;
}

unsigned int alarm(unsigned int __seconds)
{
    return 0;
}
