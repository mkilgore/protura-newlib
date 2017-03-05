#ifndef _SYS_SOCKET_H_
#define _SYS_SOCKET_H_

#include <sys/types.h>
#include <netinet/in.h>

#include <protura/net/sockaddr.h>

int socket(int __sockfd, int __type, int __address_family);
int bind(int __sockfd,  const struct sockaddr *__addr, socklen_t __addrlen);

int getpeername(int __sockfd, struct sockaddr *__addr, socklen_t *__addrlen);
int getsockname(int __sockfd, struct sockaddr *__addr, socklen_t *__addrlen);

int getsockopt(int __sockfd, int __level, int __optname, void *__optval, socklen_t *__optlen);
int setsockopt(int __sockfd, int __level, int __optname, const void *__optval, socklen_t __optlen);

ssize_t recv    (int __sockfd, void * __buf, size_t __buflen, int __flags);
ssize_t recvfrom(int __sockfd, void * __buf, size_t __buflen, int __flags, struct sockaddr *__addr, socklen_t *__addrlen);

ssize_t send  (int __sockfd, const void *__buf, size_t __buflen, int __flags);
ssize_t sendto(int __sockfd, const void *__buf, size_t __buflen, int __flags, const struct sockaddr *__addr, socklen_t __addrlen);

int shutdown(int __sockfd, int __how);

#endif
