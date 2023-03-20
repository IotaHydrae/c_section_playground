
test.out: test.ld test.c
	gcc -DFOO=bar -D__KBUILD_MODNAME=kmod_test -T $^ -o $@

all: test.out
	

dump: test.out
	readelf -a $^ > elf_dump.txt
	objdump -D -S $^ > obj_dump.txt

clean:
	rm -rf *.out *.o *.txt
