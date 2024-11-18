#include <stdio.h>

#include "mem.h"

char another_global_var = 42;

extern char __MYLIB_map_start;  // set by linker file
extern char __MYLIB_start_data; // set by linker file
extern char __MYLIB_end_data;   // set by linker file
extern char __MYLIB_start_bss;  // set by linker file
extern char __MYLIB_end_bss;    // set by linker file


void show_vars(void)
{
    printf("debug info...\n");

    printf("__MYLIB_map_start       %p\n", &__MYLIB_map_start);
    printf("__MYLIB_start_data      %p\n", &__MYLIB_start_data);
    printf("__MYLIB_end_data        %p\n", &__MYLIB_end_data);
    printf("__MYLIB_start_bss       %p\n", &__MYLIB_start_bss);
    printf("__MYLIB_end_bss         %p\n", &__MYLIB_end_bss);
}

void* translate(uint64_t addr)
{
    //show_vars();

    uint64_t offset = addr - (uint64_t)&(__MYLIB_map_start);
    uintptr_t local_addr = (uintptr_t)(&__MYLIB_start_data) + (uintptr_t)offset;
    return (void*)local_addr;
}
