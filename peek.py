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
print("calc now:", lib.calc())
addr = 0x74fbfeca0050

print(f"calling peek to address 0x{addr:0x}.....")
aux = ffi_io.new("uint32_t *")
result = lib.peek(addr, aux)

print(result, addr, aux[0])
