SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_write

EXTERN __errno_location

ft_write:
    MOV RAX, 1
    SYSCALL
    CMP RAX, 0
    JL .error
    RET

.error:
    NEG RAX
    PUSH RAX
    CALL __errno_location WRT ..plt
    POP RDI
    MOV [RAX], EDI
    MOV RAX, -1
    RET
