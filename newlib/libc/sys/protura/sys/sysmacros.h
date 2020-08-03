#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#include <sys/types.h>

#define makedev(maj, min) \
    (((maj) << 20) | ((min) & 0xFFFFF))

#define major(dev) \
    ((dev) >> 20)

#define minor(dev) \
    ((dev) & 0xFFFFF)

#endif
