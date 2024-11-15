#include <time.h>

#include "mylib.h"

tuple_t MY_BASE = {10, 0, 3.141592};

EXTERN_C DLL_PUBLIC int calc(void)
{
    return (int)MY_BASE.second * time(NULL);
}

int inner_calc(void)
{
    return MY_BASE.first * 3;
}
