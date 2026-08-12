SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_strcmp

ft_strcmp:
    XOR RAX, RAX

.loop:
    MOV DL, [RDI]
    CMP BYTE DL, [RSI]
    JNE .end
    CMP BYTE DL, 0
    JE .end
    ADD RDI, 1
    ADD RSI, 1
    JMP .loop

.end:
    MOVZX EAX, BYTE [RDI]
    MOVZX EBX, BYTE [RSI]
    SUB EAX, EBX
    RET
