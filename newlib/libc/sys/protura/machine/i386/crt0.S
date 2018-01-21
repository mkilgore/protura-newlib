
.extern main
.extern exit
.extern _init

.data
.globl environ
.align 4
environ: .long 0

.text
.globl _start
_start:
    /* envp is actually the third argument to 'main'. We read it directly and
     * store it into the global variable 'environ' */
    movl 8(%esp), %eax
    movl %eax, environ

    call _init
    call main

    push %eax
    call exit

