#include <stdio.h>
#include <string.h>

#include "mylib.h"

int MYLIB_VERSION = 666;
extern tuple_t MY_BASE;

char MYLIB_SOMEVAR;

void display(void)
{
    void *ptr = (void*)&MYLIB_VERSION;
    printf("MYLIB_VERSION           %p\n", ptr);

    ptr = (void*)&MY_BASE;
    printf("MY_BASE                 %p\n", ptr);

    ptr = (void*)&MYLIB_SOMEVAR;
    printf("MYLIB_SOMEVAR           %p\n", ptr);
}

uintptr_t somevar(void)
{
    uintptr_t addr = (uintptr_t)&MYLIB_SOMEVAR;
    return addr;
}

static uint32_t *find_ptr(uintptr_t addr)
{
     char *mb = (char *)&MY_BASE;
     const uintptr_t my_base = (uintptr_t)mb;
     const uintptr_t my_base_4 = (uintptr_t)(mb + 4);
     const uintptr_t my_base_8 = (uintptr_t)(mb + 8);
     const uintptr_t my_base_12 = (uintptr_t)(mb + 12);

     if (addr == my_base)
         return (uint32_t *)my_base;
     if (addr == my_base_4)
         return (uint32_t *)my_base_4;
     if (addr == my_base_8) {
         printf("PS: double to int -> 0x%x\n", (*(uint32_t *)my_base_8));
         return (uint32_t *)my_base_8;
     }
     if (addr == my_base_12) {
         printf("PS: double to int -> 0x%x\n", (*(uint32_t *)my_base_12));
         return (uint32_t *)my_base_12;
     }

     return NULL;
}

int peek(uintptr_t addr, uint32_t *output)
{
    uint32_t *exp_ptr = find_ptr(addr);
    display();

    void *ptr = (void*)addr;
    printf("reading memory at %p...", ptr);

    memcpy(output, ptr, sizeof(*output));

    printf("%x\n", *output);
    printf("\texpected: %x\n", exp_ptr != NULL ? *exp_ptr : 0);
    return 0; /* always ok */
}

void say_hi(void)
{
    puts("hello world!");
}
