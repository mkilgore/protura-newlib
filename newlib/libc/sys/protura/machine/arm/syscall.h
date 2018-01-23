#ifndef _NEWLIB_PROTURA_SYSCALL_H
#define _NEWLIB_PROTURA_SYSCALL_H

#include <protura/syscall.h>

#define QQ(x) #x
#define Q(x) QQ(x)

static inline int syscall6(int sys, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    int out = 0;
    return out;
}

static inline int syscall5(int sys, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    int out = 0;
    return out;
}

static inline int syscall4(int sys, int arg1, int arg2, int arg3, int arg4)
{
    int out = 0;
    return out;
}

static inline int syscall3(int sys, int arg1, int arg2, int arg3)
{
    int out = 0;
    return out;
}

static inline int syscall2(int sys, int arg1, int arg2)
{
    int out = 0;
    return out;
}

static inline int syscall1(int sys, int arg1)
{
    int out = 0;
    return out;
}

static inline int syscall0(int sys)
{
    int out = 0;
    return out;
}


#endif
