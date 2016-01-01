#ifndef _NEWLIB_PROTURA_SYSCALL_H
#define _NEWLIB_PROTURA_SYSCALL_H

#include <protura/syscall.h>

#if 0
#define INT_SYSCALL 0x81

#define SYSCALL_PUTCHAR 0x01
#define SYSCALL_CLOCK   0x02
#define SYSCALL_GETPID  0x03
#define SYSCALL_PUTINT  0x04
#define SYSCALL_PUTSTR  0x05
#define SYSCALL_SLEEP   0x06
#define SYSCALL_FORK    0x07
#define SYSCALL_GETPPID 0x08
#define SYSCALL_OPEN    0x09
#define SYSCALL_CLOSE   0x0A
#define SYSCALL_READ    0x0B
#define SYSCALL_WRITE   0x0C
#define SYSCALL_LSEEK   0x0D
#define SYSCALL_EXECVE  0x0E
#define SYSCALL_YIELD   0x0F
#define SYSCALL_EXIT    0x10
#define SYSCALL_WAIT    0x11
#define SYSCALL_DUP     0x12
#define SYSCALL_DUP2    0x13
#define SYSCALL_BRK     0x14
#define SYSCALL_SBRK    0x15
#define SYSCALL_READ_DENT 0x16
#define SYSCALL_CHDIR   0x17
#define SYSCALL_TRUNCATE 0x18
#define SYSCALL_FTRUNCATE 0x19
#define SYSCALL_LINK    0x1A
#define SYSCALL_SYNC    0x1B
#define SYSCALL_UNLINK  0x1C
#endif

#define QQ(x) #x
#define Q(x) QQ(x)

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
