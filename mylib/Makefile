
all:
	gcc -g -Wall -Werror -fPIC -shared -o libmylib.so -fvisibility=hidden calc.c mylib.c -Xlinker -Map=mylib.map
	@echo "built!"

	@echo "\n\nexposed functions:"
	objdump -T libmylib.so

	@echo "\n\nvar addr in memory map:"
	cat mylib.map | grep MYLIB_VERSION
	cat mylib.map | grep MY_BASE

clean:
	rm -f *.o
	rm -f *.so

