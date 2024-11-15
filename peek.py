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

# run any stuff to see the lib is ok:
print("hello?")
lib.say_hi()
print("number please:", lib.calc())



# now the real part:
section_start = 0x0000000000000890 #__MYLIB_start_data (from map file)
variable_addr = 0x0000000000000890 # the var I want (also from map file)

addr = variable_addr - section_start # offset from the start

print(f"\ntry peek to 0x{addr:0x}.....")
aux = ffi_io.new("uint32_t *")
result = lib.peek(addr, aux)

if result == 0:
    print(f"peek ok: 0x{variable_addr:0x} = {aux[0]}")
