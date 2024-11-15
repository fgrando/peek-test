#include <stdio.h>
#include <string.h>

#include "mylib.h"

int MYLIB_VERSION = 666;
extern tuple_t MY_BASE;

char MYLIB_SOMEVAR;

static char SOMEBUFFER[500];

void show_vars(void)
{
    printf("debug info...\n");

    printf("MYLIB_VERSION           %p\n", &MYLIB_VERSION);
    printf("MY_BASE                 %p\n", &MY_BASE);
    printf("SOMEBUFFER              %p\n", &SOMEBUFFER);
    printf("MYLIB_SOMEVAR           %p\n", &MYLIB_SOMEVAR);
    printf("__MYLIB_start_data      %p\n", &__MYLIB_start_data);
    printf("__MYLIB_end_data        %p\n", &__MYLIB_end_data);
    printf("__MYLIB_start_bss       %p\n", &__MYLIB_start_bss);
    printf("__MYLIB_end_bss         %p\n", &__MYLIB_end_bss);
}

void* translate(uint64_t addr)
{
    uintptr_t local_addr = (addr + (uintptr_t)&__MYLIB_start_data);
    return (void*)local_addr;
}

int peek(uint64_t addr, uint32_t *output)
{
    //show_vars();
    memcpy(output, translate(addr), sizeof(*output));
    return 0; /* always ok */
}

void say_hi(void)
{
    puts("hello world!");
}