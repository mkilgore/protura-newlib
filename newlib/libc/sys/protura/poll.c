
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <signal.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/select.h>
#include <poll.h>

int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    int ret;

    ret = syscall3(SYSCALL_POLL, (int)fds, (int)nfds, timeout);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exfds, struct timeval *timeout)
{
    int i;
    int mstimeout;
    int ret;
    int flag_count = 0;
    struct pollfd fds[nfds];

    for (i = 0; i < nfds; i++) {
        fds[i].fd = -1;
        fds[i].events = 0;
        fds[i].revents = 0;
    }

    for (i = 0; i < nfds; i++) {
        if (readfds && FD_ISSET(i, readfds)) {
            fds[i].fd = i;
            fds[i].events |= POLLIN;
        }

        if (writefds && FD_ISSET(i, writefds)) {
            fds[i].fd = i;
            fds[i].events |= POLLOUT;
        }

        if (exfds && FD_ISSET(i, exfds)) {
            fds[i].fd = i;
            fds[i].events |= POLLERR;
        }
    }

    if (timeout)
        mstimeout = timeout->tv_sec * 1000 + timeout->tv_usec / 1000;
    else
        mstimeout = -1;

    ret = poll(fds, nfds, mstimeout);
    if (ret == -1)
        return -1;

    for (i = 0; i < nfds; i++) {
        if (fds[i].fd != -1) {
            if (readfds && fds[i].events & POLLIN) {
                if (fds[i].revents & POLLIN) {
                    FD_SET(i, readfds);
                    flag_count++;
                } else {
                    FD_CLR(i, readfds);
                }
            }

            if (writefds && fds[i].events & POLLOUT) {
                if (fds[i].revents & POLLOUT) {
                    flag_count++;
                    FD_SET(i, writefds);
                } else {
                    FD_CLR(i, writefds);
                }
            }

            if (exfds && fds[i].events & POLLERR) {
                if (fds[i].revents & POLLERR) {
                    flag_count++;
                    FD_SET(i, exfds);
                } else {
                    FD_CLR(i, exfds);
                }
            }
        }
    }

    return flag_count;
}

