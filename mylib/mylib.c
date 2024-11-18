#include <stdio.h>
#include <string.h>

#include "mylib.h"
#include "mem.h"

int MYLIB_VERSION = 666;

uint32_t MYLIB_SOMEVAR = 123456789;

int peek(uint64_t addr, uint32_t *output)
{
    memcpy(output, translate(addr), sizeof(*output));
    return 0; /* always ok */
}

void say_hi(void)
{
    puts("hello world!");
}
