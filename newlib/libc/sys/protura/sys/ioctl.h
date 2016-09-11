
#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <protura/fs/ioctl.h>

int _EXFUN(ioctl, (int __fd, int _request, ...));

#ifdef __cplusplus
}
#endif

#endif
