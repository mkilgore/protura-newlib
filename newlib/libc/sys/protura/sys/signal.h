#ifndef _SYS_SIGNAL_H
#define _SYS_SIGNAL_H
#define _SIGNAL_H

#include <sys/types.h>

#include <protura/signal.h>

typedef void (*_sig_func_ptr) (int);
typedef _sig_func_ptr __sighandler_t;

#undef SIG_DFL
#undef SIG_IGN
#undef SIG_ERR

int _EXFUN(kill, (pid_t pid, int signum));
int _EXFUN(sigaction, (int signum, const struct sigaction *act, struct sigaction *oldact));
int _EXFUN(sigaddset, (sigset_t *set, const int signum));
int _EXFUN(sigdelset, (sigset_t *set, const int signum));
int _EXFUN(sigismember, (const sigset_t *set, const int signum));
int _EXFUN(sigemptyset, (sigset_t *set));
int _EXFUN(sigfillset, (sigset_t *set));
int _EXFUN(sigpending, (sigset_t *set));
int _EXFUN(sigwait, (const sigset_t *, int *signum));
int _EXFUN(sigsuspend, (const sigset_t *mask));
int _EXFUN(sigprocmask, (int how, const sigset_t *set, sigset_t *oldset));

#endif
