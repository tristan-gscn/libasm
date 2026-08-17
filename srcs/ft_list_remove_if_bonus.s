SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_list_remove_if

EXTERN free

ft_list_remove_if:
    PUSH RBP
    PUSH R12
    PUSH R13
    PUSH R14
    PUSH R15

    MOV R15, RDI
    MOV R12, RSI
    MOV R13, RDX
    MOV R14, RCX

.loop:
    MOV RBP, [R15]
    TEST RBP, RBP
    JZ .end

    MOV RDI, [RBP]
    MOV RSI, R12
    CALL R13
    TEST EAX, EAX
    JNZ .skip

    MOV RDI, [RBP]
    CALL R14
    MOV RAX, [RBP + 8]
    MOV [R15], RAX
    MOV RDI, RBP
    CALL free WRT ..plt
    JMP .loop

.skip:
    LEA R15, [RBP + 8]
    JMP .loop

.end:
    POP R15
    POP R14
    POP R13
    POP R12
    POP RBP
    RET
