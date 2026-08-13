SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_atoi_base

EXTERN ft_strlen

ft_atoi_base:
    ; RCX final result
    XOR RCX, RCX

    ; RDX base length
    PUSH RDI
    MOV RDI, RSI
    CALL ft_strlen
    MOV RDX, RAX
    POP RSI

.loop:
    CMP BYTE [RSI], 0
    JE .end
    IMUL RCX, RDX
    CALL .char_val
    ADD RCX, RAX
    INC RSI
    JMP .loop

.end:
    MOV RAX, RCX
    RET

.char_val:
    XOR RAX, RAX
    MOVZX R9D, BYTE [RSI]
    MOV R8, RDI
.char_val_loop:
    CMP R9B, BYTE [R8]
    JE .char_val_cut
    INC RAX
    INC R8
    JMP .char_val_loop
.char_val_cut:
    RET
