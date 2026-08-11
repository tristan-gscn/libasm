SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL addition

addition:
    MOV RAX, RDI
    ADD RAX, RSI
    RET
