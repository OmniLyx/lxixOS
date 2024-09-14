OBJECTS = src/asm/loader.o
C_OBJECTS = $(patsubst %.c, %.o, $(wildcard src/c/*.c))
HEADERS = $(wildcard src/h/*.h)
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
			-nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c \
			-Isrc/h
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

runClean: clean all

all: os.iso
	echo "Done!"

kernel.elf: $(OBJECTS) $(C_OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) $(C_OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
				-b boot/grub/stage2_eltorito    \
				-no-emul-boot                   \
				-boot-load-size 4               \
				-A os                           \
				-input-charset utf8             \
				-quiet                          \
				-boot-info-table                \
				-o os.iso                   \
				iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	echo $(C_OBJECTS)
	rm -rf */*/*.o kernel.elf os.iso