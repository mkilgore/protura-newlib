
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>

int socket(int sockfd, int type, int address_family)
{
    int ret;
    ret = syscall3(SYSCALL_SOCKET, sockfd, type, address_family);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    ret = syscall3(SYSCALL_BIND, sockfd, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return -ENOTSUP;
}

int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
    ret = syscall3(SYSCALL_GETSOCKNAME, sockfd, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen)
{
    int ret;
    ret = syscall5(SYSCALL_GETSOCKOPT, sockfd, level, optname, (uint32_t)optval, (uint32_t)optlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen)
{
    int ret;
    ret = syscall5(SYSCALL_SETSOCKOPT, sockfd, level, optname, (uint32_t)optval, (uint32_t)optlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

ssize_t recv(int sockfd, void *buf, size_t buflen, int flags)
{
    int ret;
    ret = syscall4(SYSCALL_RECV, sockfd, (uint32_t)buf, (uint32_t)buflen, flags);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

ssize_t recvfrom(int sockfd, void *buf, size_t buflen, int flags, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
    ret = syscall6(SYSCALL_RECVFROM, sockfd, (uint32_t)buf, (uint32_t)buflen, flags, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

ssize_t send(int sockfd, const void *buf, size_t buflen, int flags)
{
    int ret;
    ret = syscall4(SYSCALL_SEND, sockfd, (uint32_t)buf, (uint32_t)buflen, flags);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

ssize_t sendto(int sockfd, const void *buf, size_t buflen, int flags, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    ret = syscall6(SYSCALL_SENDTO, sockfd, (uint32_t)buf, (uint32_t)buflen, flags, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret;
    ret = syscall3(SYSCALL_ACCEPT, sockfd, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int listen(int sockfd, int backlog)
{
    int ret;
    ret = syscall2(SYSCALL_LISTEN, sockfd, backlog);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret;
    ret = syscall3(SYSCALL_CONNECT, sockfd, (uint32_t)addr, (uint32_t)addrlen);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

int shutdown(int sockfd, int how)
{
    int ret;
    ret = syscall2(SYSCALL_SHUTDOWN, sockfd, how);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}

