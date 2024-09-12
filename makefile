
all: bin/os.img
	bochs -f bochsrc.txt -q

bin/os.img: bin/loader.o
	cd bin
	type $(subst bin/,,$^) > $@

bin/kernel.elf: bin/loader.o
	ld -T link.ld -mi386pe -o $@ $^

bin/loader.o: src/assembly/loader.s
	nasm -f elf32 $^ -o $@


clean:
	del /Q bin\*.o bin\*.bin bin\*.img bin\*.elf