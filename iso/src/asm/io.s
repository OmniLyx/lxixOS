global OutB     ; make the label OutB visible outside this file

OutB:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret