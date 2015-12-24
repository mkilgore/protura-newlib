
.extern main
.extern exit

.globl _start
_start:
    call main
    push %eax
    call exit

