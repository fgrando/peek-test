#include <stdio.h>
#include <string.h>

#include "mylib.h"

int MYLIB_VERSION = 666;
extern tuple_t MY_BASE;

void display(void)
{
    void *ptr = (void*)&MYLIB_VERSION;
    printf("MYLIB_VERSION           %p\n", ptr);

    ptr = (void*)&MY_BASE;
    printf("MY_BASE                 %p\n", ptr);
}

int peek(uint64_t addr, uint32_t *output)
{
    display();

    void *ptr = (void*)addr;
    printf("reading memory at %p...", ptr);

    memcpy(output, ptr, sizeof(*output));

    printf("%x\n", *output);
    return 0; /* always ok */
}

void say_hi(void)
{
    puts("hello world!");
}