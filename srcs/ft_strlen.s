SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_strlen

ft_strlen:
    XOR RAX, RAX

.loop:
    CMP BYTE [RDI + RAX], 0
    JE .end
    ADD RAX, 1
    JMP .loop

.end:
    RET
