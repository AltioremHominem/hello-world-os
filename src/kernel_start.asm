global start
extern  kmain

MODULEALIGH     equ 1<<0
MEMINFO         equ 1<<1

FLAGS           equ MODULEALIGH | MEMINFO
MAGIC           equ 0x1BADB002
CHECKSUM        equ -(MAGIC + FLAGS)

section .text
align 4

MultiBootHeader:
        dd MAGIC
        dd FLAGS
        dd CHECKSUM


start:
        call kmain
        cli

esperar:
        hlt
        jmp esperar


section .bss
        align 4
