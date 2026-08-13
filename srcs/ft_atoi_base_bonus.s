SECTION .note.GNU-stack noalloc noexec nowrite progbits

SECTION .text
    GLOBAL ft_atoi_base

ft_atoi_base:
    XCHG RDI, RSI

    XOR R9D, R9D
    CALL .char_val
    MOV RDX, RAX

    CMP RDX, 2
    JB .invalid
    XOR RCX, RCX
.check_base:
    CMP RCX, RDX
    JE .skip_spaces
    MOVZX R9D, BYTE [RDI + RCX]
    CMP R9B, '+'
    JE .invalid
    CMP R9B, '-'
    JE .invalid
    CALL .is_space
    JC .invalid
    CALL .char_val
    CMP RAX, RCX
    JNE .invalid
    INC RCX
    JMP .check_base

.skip_spaces:
    MOVZX R9D, BYTE [RSI]
    CALL .is_space
    JNC .read_sign
    INC RSI
    JMP .skip_spaces

.read_sign:
    MOV R10, 1
    CMP R9B, '+'
    JE .skip_sign
    CMP R9B, '-'
    JNE .parse
    NEG R10
.skip_sign:
    INC RSI

.parse:
    XOR RCX, RCX
.parse_loop:
    MOVZX R9D, BYTE [RSI]
    CALL .char_val
    CMP RAX, RDX
    JE .end
    IMUL RCX, RDX
    ADD RCX, RAX
    INC RSI
    JMP .parse_loop

.end:
    IMUL RCX, R10
    MOV RAX, RCX
    RET

.invalid:
    XOR EAX, EAX
    RET

.char_val:
    XOR RAX, RAX
.char_val_loop:
    CMP BYTE [RDI + RAX], 0
    JE .char_val_cut
    CMP R9B, BYTE [RDI + RAX]
    JE .char_val_cut
    INC RAX
    JMP .char_val_loop
.char_val_cut:
    RET

.is_space:
    CMP R9B, ' '
    JE .is_space_yes
    MOV R11B, R9B
    SUB R11B, 9
    CMP R11B, 5
    RET
.is_space_yes:
    STC
    RET
