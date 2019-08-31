#ifndef _SYS_UTSNAME_H
#define _SYS_UTSNAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <protura/utsname.h>

int uname(struct utsname *__name);

#ifdef __cplusplus
}
#endif

#endif
