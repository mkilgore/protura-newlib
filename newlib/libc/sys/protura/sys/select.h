#ifndef _SYS_SELECT_H
#define _SYS_SELECT_H 1

#include <sys/types.h>
#include <sys/time.h>

int select(int __nfds, fd_set *__readfds, fd_set *__writefds, fd_set *__exfds, struct timeval *__timeout);

#endif
