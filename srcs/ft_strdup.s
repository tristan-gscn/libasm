SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_strdup

EXTERN malloc
EXTERN ft_strlen
EXTERN ft_strcpy

ft_strdup:
    PUSH RBX
    MOV RBX, RDI
    CALL ft_strlen
    ADD RAX, 1
    MOV RDI, RAX
    CALL malloc WRT ..plt
    TEST RAX, RAX
    JZ .end
    MOV RDI, RAX
    MOV RSI, RBX
    CALL ft_strcpy

.end:
    POP RBX
    RET
