
.section .init
.globl _init
_init:
    pop %ebp
    ret

.section .fini
.globl _fini
_fini:
    pop %ebp
    ret

