; gdt.s - Global Descriptor Table setup
global load_gdt
global flush_segments

section .text
gdt_start:
    dq 0x0000000000000000  ; Null segment
    dq 0x00CF9A000000FFFF  ; Code segment
    dq 0x00CF92000000FFFF  ; Data segment

gdt_end:

gdt_descriptor_text:
    dw gdt_end - gdt_start - 1  ; Limit
    dd gdt_start                ; Base address

; Load the GDT
load_gdt:
    lgdt [gdt_descriptor_text]
    mov ax, 0x10                ; Data segment selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush_segments     ; Code segment selector

flush_segments:
    mov ax, 0x10                ; Reload data segment selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret

section .bss
align 16
gdt_descriptor_bss resb 10