            global maxoftwo
            section .text
maxoftwo:
            mov     rax, rdx    ; result (rax) initially holds x
            cmp     rax, rcx    ; is x less than y?
            cmovl   rax, rcx    ; if so, set result to y
            ret     