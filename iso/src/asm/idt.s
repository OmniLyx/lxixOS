global LoadIDT

section .text
LoadIDT:
    lidt [esp + 4]  ; Load the IDT pointer
    ret
