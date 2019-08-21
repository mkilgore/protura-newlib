#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <protura/waitbits.h>

#define WNOHANG      __kWNOHANG
#define WUNTRACED    __kWUNTRACED
#define WSTOPPED     __kWSTOPPED
#define WCONTINUED   __kWCONTINUED

#define WIFEXITED    __kWIFEXITED
#define WIFSIGNALED  __kWIFSIGNALED
#define WIFSTOPPED   __kWIFSTOPPED

#define WEXITSTATUS  __kWEXITSTATUS
#define WTERMSIG     __kWTERMSIG
#define WSTOPSIG     __kWSTOPSIG

#define WIFCONTINUED __kWIFCONTINUED

#include <_ansi.h>
#include <sys/types.h>

pid_t wait (int *);
pid_t waitpid (pid_t, int *, int);

pid_t _wait (int *);

#ifdef __cplusplus
}
#endif

#endif
