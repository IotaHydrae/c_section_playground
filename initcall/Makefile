
test: test.ld test.c
	gcc -DFOO=bar -T $^ -o test

all: test
	

dump: test
	readelf -a $^ > elf_dump.txt

clean:
	rm -rf test *.o