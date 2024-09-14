global loader                   ; the entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate the checksum
                                ; (magic number + checksum + flags should equal 0)

section .text:                  ; start of the text (code) section
align 4                         ; the code must be 4 byte aligned
    dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum

KERNAL_STACK_SIZE equ 4096


section .bss
align 4
kernal_stack :
    resb KERNAL_STACK_SIZE

mov esp, kernal_stack + KERNAL_STACK_SIZE

section .text
extern Boot   ; the function sum_of_three is defined elsewhere
loader:
    ; The assembly code
    call Boot       ; call the function, the result will be in eax

.loop:
    jmp .loop
