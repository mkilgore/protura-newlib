
#include "syscall.h"
#include <sys/errno.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

in_addr_t inet_addr(const char *ip)
{
    int vals[4];
    int i;

    for (i = 0; i < 4; i++) {
        int new_val = 0;
        while (*ip >= '0' && *ip <= '9') {
            new_val = new_val * 10 + (*ip - '0');
            ip++;
        }

        vals[i] = new_val;
        ip++;
    }

    return (vals[3] << 24) + (vals[2] << 16) + (vals[1] << 8) + vals[0];
}

char *inet_ntoa(struct in_addr addr)
{
    static char buf[17];
    uint8_t *c = (uint8_t *)&addr.s_addr;

    snprintf(buf, sizeof(buf), "%d.%d.%d.%d",
            c[0], c[1], c[2], c[3]);

    return buf;
}

