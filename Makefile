CC = gcc
ASM = nasm
LD = ld
CFLAGS = -Wall -Wextra -std=gnu23 -Iinclude

CC_x64 = 0
CC_x32 = 0

LD_x32 = 0
LD_x64 = 0

ASM_x32 = 0
ASM_x64 = 0

all:
	$(ASM) -f elf32 src/kernel_start.asm -o build/ks.o
	$(CC) -m32 -c src/kernel.c -o build/kernel.o $(CFLAGS)
	$(LD) -melf_i386 -T src/linker.ld -o build/kernel.bin build/ks.o build/kernel.o
clean:
	rm build/*.o
	rm build/kernel.bin
run:
	qemu-system-i386 -kernel build/kernel.bin