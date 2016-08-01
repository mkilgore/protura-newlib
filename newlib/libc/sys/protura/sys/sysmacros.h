#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#include <sys/types.h>

#define makedev(maj, min) \
    (((maj) << 8) | ((min) & 0xFF))

#define major(dev) \
    ((dev) >> 8)

#define minor(dev) \
    ((dev) & 0xFF)

#endif
