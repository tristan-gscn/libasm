# libasm

## Mandatory

### ft_strlen

```mermaid
flowchart TD
    S(["ft_strlen<br/>RAX = 0"]) --> L[".loop"]
    L -->|"JE — byte is NUL"| E[".end"]
    L -->|"JMP — RAX + 1"| L
    E --> R(["RET — RAX = length"])
```

### ft_strcpy

```mermaid
flowchart TD
    S(["ft_strcpy<br/>RAX = dst"]) --> L[".loop"]
    L -->|"JE — byte just copied is NUL"| E[".end"]
    L -->|"JMP — both cursors + 1, RAX untouched"| L
    E --> R(["RET — RAX = dst"])
```

### ft_strcmp

```mermaid
flowchart TD
    S(["ft_strcmp"]) --> L[".loop"]
    L -->|"JNE — bytes differ"| E[".end<br/>RAX = s1[i] - s2[i]"]
    L -->|"JE — byte is NUL"| E
    L -->|"JMP — both cursors + 1"| L
    E --> R(["RET — RAX"])
```

### ft_write / ft_read

```mermaid
flowchart TD
    S(["ft_write / ft_read<br/>RAX = syscall number"]) --> SC["SYSCALL<br/>RAX = bytes, or -errno"]
    SC -->|"JL — RAX < 0"| ER[".error<br/>RAX = -RAX, saved on the stack"]
    SC --> R1(["RET — RAX = bytes"])
    ER --> C["CALL __errno_location<br/>RAX = address of errno"]
    C --> ST["store the saved code there<br/>RAX = -1"]
    ST --> R2(["RET — RAX = -1"])
```

### ft_strdup

```mermaid
flowchart TD
    S(["ft_strdup"]) --> A["CALL ft_strlen<br/>RAX = len"]
    A --> B["CALL malloc, RDI = len + 1<br/>RAX = new block, or NULL"]
    B -->|"JZ — malloc returned NULL"| E[".end"]
    B --> C["CALL ft_strcpy<br/>RAX = same pointer back"]
    C --> E
    E --> R(["RET — RAX = copy, or NULL"])
```

## Bonus

### ft_atoi_base

```mermaid
flowchart TD
    S(["ft_atoi_base"]) --> CV["CALL .char_val<br/>RDX = base length"]
    CV -->|"JB — base shorter than 2"| INV[".invalid<br/>RAX = 0"]
    CV --> CH[".check_base"]

    CH -->|"any rejection below"| INV
    CH -->|"JE — end of base"| SK[".skip_spaces"]

    SK -->|"JNC — not a whitespace"| SG[".read_sign<br/>R10 = 1"]
    SK -->|"JMP"| SK

    SG -->|"JE — char is +"| SC[".skip_sign"]
    SG -->|"JNE — char is not -"| P[".parse<br/>RCX = 0"]
    SG -->|"NEG R10 → -1"| SC
    SC --> P

    P --> L[".parse_loop<br/>RCX = RCX × RDX + digit"]
    L -->|"JE — not in base"| E[".end<br/>RCX = RCX × R10"]
    L -->|"JMP"| L

    E --> R1(["RET — RAX = RCX"])
    INV --> R2(["RET — RAX = 0"])
```

#### .check_base

```mermaid
flowchart TD
    C([".check_base"]) --> T1{"CMP RCX, RDX"}
    T1 -->|"JE — whole base seen"| OK([".skip_spaces — base accepted"])
    T1 --> T2{"CMP char, '+'"}
    T2 -->|"JE"| INV([".invalid"])
    T2 --> T3{"CMP char, '-'"}
    T3 -->|"JE"| INV
    T3 --> T4["CALL .is_space"]
    T4 -->|"JC — whitespace"| INV
    T4 --> T5["CALL .char_val<br/>CMP RAX, RCX"]
    T5 -->|"JNE — seen earlier"| INV
    T5 -->|"JMP — RCX + 1"| C
```

#### .char_val

```mermaid
flowchart TD
    S(["char_val<br/>RAX = 0"]) --> L[".char_val_loop"]
    L -->|"JE — base[i] is NUL"| C[".char_val_cut"]
    L -->|"JE — base[i] matches"| C
    L -->|"JMP — RAX + 1"| L
    C --> R(["RET — RAX = index, or base length"])
```

#### .is_space

```mermaid
flowchart TD
    S(["is_space"]) --> CMP["CMP with ' '"]
    CMP -->|"JE — char is a space"| Y[".is_space_yes<br/>STC sets CF"]
    CMP --> SUB["SUB 9, then CMP 5<br/>CF set for TAB..CR"]
    SUB --> R1(["RET — CF"])
    Y --> R2(["RET — CF = 1"])
```

### ft_list_size

```mermaid
flowchart TD
    S(["ft_list_size<br/>EAX = 0"]) --> L[".loop"]
    L -->|"JZ — pointer is NULL"| E[".end"]
    L -->|"JMP — EAX + 1, follow next"| L
    E --> R(["RET — EAX = count"])
```

### ft_list_push_front

```mermaid
flowchart TD
    S(["ft_list_push_front"]) --> M["CALL malloc<br/>RAX = new node, or NULL"]
    M -->|"JZ — malloc returned NULL"| E[".end"]
    M --> LK["node.data = data<br/>node.next = old head<br/>*begin_list = node"]
    LK --> E
    E --> R(["RET — no value"])
```
