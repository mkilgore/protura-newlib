
.extern main
.extern exit
.extern _init

.globl _start
_start:
    call _init
    call main
    push %eax
    call exit

