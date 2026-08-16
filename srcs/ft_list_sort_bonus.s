SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_list_sort

EXTERN ft_list_size

ft_list_sort:
    PUSH RBX
    MOV RCX, -1
    PUSH RDI
    CALL ft_list_size
    MOV RBX, RAX
    POP RDI
    LEA R10, [RBX - 1]
.loop:
    CMP RCX, RBX
    JE .end
    ADD RCX, 1
    XOR RDX, RDX
.subloop:
    CMP RDX, R10
    JE .loop
    MOV R8, [RDI + RDX * 8]
    MOV R9, [RDI + RDX * 8 + 8]
    CMP R8, R9
    JL .skip
    MOV [RDI + RDX * 8], R9
    MOV [RDI + RDX * 8 + 8], R8
.skip:
    ADD RDX, 1
    JMP .subloop

.end:
    POP RBX
    RET
