SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_strcpy

ft_strcpy:
    MOV RAX, RDI

.loop:
    MOV DL, [RSI]
    MOV [RDI], DL
    CMP BYTE [RSI], 0
    JE .end
    ADD RDI, 1
    ADD RSI, 1
    JMP .loop

.end:
    RET
