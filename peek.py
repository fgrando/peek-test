#!/bin/python3

# pip install cffi
from cffi import FFI

mylib_api = '''
int peek(uint64_t addr, uint32_t *output);
int calc(void);
void say_hi(void);
uint64_t somevar(void);
'''

ffi_io = FFI()
ffi_io.cdef(mylib_api)

lib = ffi_io.dlopen('./mylib/libmylib.so')

lib.say_hi()
print("calc now:", lib.calc())

somevar = lib.somevar()
print(f"some var is at addr 0x{somevar:0x}")


from_map_file = 0x0000000000004038

addr = (somevar&0xfffffffffffff000) | (from_map_file&0x0000000000000fff)


print(f"calling peek to address 0x{addr:0x}.....")
aux = ffi_io.new("uint32_t *")
result = lib.peek(addr, aux)

print(result, addr, aux[0])
