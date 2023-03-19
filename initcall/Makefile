
test.out: test.ld test.c
	gcc -DFOO=bar -T $^ -o $@

all: test.out
	

dump: test.out
	readelf -a $^ > elf_dump.txt

clean:
	rm -rf *.out *.o *.txt
