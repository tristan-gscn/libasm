SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_list_push_front

EXTERN malloc

ft_list_push_front:
    PUSH RDI
    PUSH RSI
    SUB RSP, 8

    MOV RDI, 16
    CALL malloc WRT ..plt

    ADD RSP, 8
    POP RSI
    POP RDI

    TEST RAX, RAX
    JZ .end

    MOV [RAX], RSI
    MOV RDX, [RDI]
    MOV [RAX + 8], RDX
    MOV [RDI], RAX

.end:
    RET
