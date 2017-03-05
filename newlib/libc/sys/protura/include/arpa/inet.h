#ifndef _ARPA_INET_H_
#define _ARPA_INET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static inline uint32_t htonl(uint32_t hostl)
{
    return ((hostl & 0xFF000000) >> 24)
         | ((hostl & 0x00FF0000) >> 8)
         | ((hostl & 0x0000FF00) << 8)
         | ((hostl & 0x000000FF) << 24);
}

static inline uint16_t htons(uint16_t hosts)
{
    return ((hosts & 0xFF00) >> 8)
         | ((hosts & 0x00FF) << 8);
}

#define ntohl(hostl) htonl(hostl)
#define ntohs(hostw) htons(hostw)

in_addr_t inet_addr(const char *);
char     *inet_ntoa(struct in_addr);

#endif
