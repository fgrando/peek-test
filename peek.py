#!/bin/python3

# pip install cffi
from cffi import FFI

mylib_api = '''
int peek(uint64_t addr, uint32_t *output);
int calc(void);
void say_hi(void);
'''

ffi_io = FFI()
ffi_io.cdef(mylib_api)

lib = ffi_io.dlopen('./mylib/libmylib.so')

lib.say_hi()

addr = 0x4050

print("try to read addr", addr)
aux = ffi_io.new("uint32_t *")
result = lib.peek(addr, aux)

print(result, addr, aux[0])
