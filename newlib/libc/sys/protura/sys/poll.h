#ifndef _SYS_POLL_H
#define _SYS_POLL_H

#include <_ansi.h>
#include <protura/fs/poll.h>

int _EXFUN(poll, (struct pollfd *__fds, nfds_t __nfds, int __timeout));

#endif
