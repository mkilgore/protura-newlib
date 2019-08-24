
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uintptr_t __stack_chk_guard = 0xDEADBEEF;;

void __stack_chk_fail(void)
{
    fprintf(stderr, "Stack smashing detected!\n");
	abort();
}
