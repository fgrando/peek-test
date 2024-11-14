#include <time.h>

#include "mylib.h"

typedef struct tuple_tag
{
    int first;
    double second;
} tuple_t;

tuple_t MY_BASE = {10, 3.141592};

EXTERN_C DLL_PUBLIC int calc(void)
{
    return (int)MY_BASE.second * time(NULL);
}

int inner_calc(void)
{
    return MY_BASE.first * 3;
}