#ifndef _NEWLIB_PROTURA_SYSCALL_H
#define _NEWLIB_PROTURA_SYSCALL_H

#include <protura/syscall.h>

#define QQ(x) #x
#define Q(x) QQ(x)

static inline int syscall5(int sys, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys), "b" (arg1), "c" (arg2), "d" (arg3), "S" (arg4), "D" (arg5)
                 : "memory");

    return out;
}

static inline int syscall4(int sys, int arg1, int arg2, int arg3, int arg4)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys), "b" (arg1), "c" (arg2), "d" (arg3), "S" (arg4)
                 : "memory");

    return out;
}

static inline int syscall3(int sys, int arg1, int arg2, int arg3)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys), "b" (arg1), "c" (arg2), "d" (arg3)
                 : "memory");

    return out;
}

static inline int syscall2(int sys, int arg1, int arg2)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys), "b" (arg1), "c" (arg2)
                 : "memory");

    return out;
}

static inline int syscall1(int sys, int arg1)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys), "b" (arg1)
                 : "memory");

    return out;
}

static inline int syscall0(int sys)
{
    int out;
    asm volatile("int $" Q(INT_SYSCALL) "\n"
                 : "=a" (out)
                 : "0" (sys)
                 : "memory");

    return out;
}


#endif
