SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_list_sort

EXTERN ft_list_size

ft_list_sort:
    PUSH RBX
    PUSH R12
    PUSH R13
    PUSH R14
    PUSH R15

    MOV R12, RDI
    MOV R13, RSI

    MOV RDI, [R12]
    CALL ft_list_size
    MOV RBX, RAX

    MOV R14, -1
.loop:
    CMP R14, RBX
    JE .end
    ADD R14, 1
    MOV R15, [R12]
    TEST R15, R15
    JZ .loop
.subloop:
    MOV RAX, [R15 + 8]
    TEST RAX, RAX
    JZ .loop
    MOV RDI, [R15]
    MOV RSI, [RAX]
    CALL R13
    TEST EAX, EAX
    JLE .skip
    MOV RAX, [R15 + 8]
    MOV RCX, [R15]
    MOV RDX, [RAX]
    MOV [R15], RDX
    MOV [RAX], RCX
.skip:
    MOV R15, [R15 + 8]
    JMP .subloop

.end:
    POP R15
    POP R14
    POP R13
    POP R12
    POP RBX
    RET
