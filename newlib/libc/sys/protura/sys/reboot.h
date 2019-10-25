#ifndef _SYS_REBOOT_H
#define _SYS_REBOOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <_ansi.h>
#include <protura/reboot.h>

int _EXFUN(reboot, (int magic1, int magic2, int cmd));

#ifdef __cplusplus
}
#endif

#endif
