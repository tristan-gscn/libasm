SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_list_size

ft_list_size:
    XOR EAX, EAX

.loop:
    TEST RDI, RDI
    JZ .end
    INC EAX
    MOV RDI, [RDI + 8]
    JMP .loop

.end:
    RET
