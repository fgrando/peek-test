#include <stdio.h>
#include <string.h>

#include "mylib.h"

int MYLIB_VERSION = 666;

int peek(uint64_t addr, uint32_t *output)
{
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