#ifndef MYLIB_HEADER_INCLUDED_
#define MYLIB_HEADER_INCLUDED_

#include <stdint.h>
#include "libdefs.h"

typedef struct tuple_tag
{
    int first;
    double second;
} tuple_t;

EXTERN_C DLL_PUBLIC int peek(uint64_t addr, uint32_t *output);
EXTERN_C DLL_PUBLIC void say_hi(void);

#endif /* MYLIB_HEADER_INCLUDED_ */