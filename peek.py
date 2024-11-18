#!/bin/python3
import re
import sys

# pip install cffi
from cffi import FFI

mylib_api = '''
int peek(uint64_t addr, uint32_t *output);
int calc(void);
void say_hi(void);
uint64_t somevar(void);
'''


if len(sys.argv) < 3:
    print("f{sys.argv[0]} <shared-lib.so> <mapfile.txt>")
    exit(-1)

lib = sys.argv[1]
map = sys.argv[2]

print(f"Available addresses in {map}:")
save = False
avail_vars = []
for row in open(map).read().split('\n'):
    if '/' in row:
        continue
    if '__MYLIB_start_' in row:
        save = True
        continue
    if '__MYLIB_end_' in row:
        save = False
        continue
    if len(row.strip().split()) != 2:
        continue
    if save:
        print(row.strip())
        avail_vars.append(row.strip().split())


ffi_io = FFI()
ffi_io.cdef(mylib_api)

lib = ffi_io.dlopen(lib)

# run any stuff to see the lib is ok:
print("hello?")
lib.say_hi()
print("calc result:", lib.calc())

# now the real part:
for var in avail_vars:
    name = var[1]
    addr = int(var[0], 16)

    print(f"\ntry peek '{name}' at 0x{addr:0x}...")
    aux = ffi_io.new("uint32_t *")
    result = lib.peek(addr, aux)
    if result == 0:
        print(f"peek ok: 0x{addr:0x} = {aux[0]}")
    else:
        print(f"peek FAILED! 0x{addr:0x}")
