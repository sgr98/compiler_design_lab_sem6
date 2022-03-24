; -----------------------------------------------------------------------------
; I have read it and understood it.
; -----------------------------------------------------------------------------

        global  three_max
        section .text
three_max:
        mov     rax, rdi                ; result (rax) initially holds x        | stores x in rax
        cmp     rax, rsi                ; is x less than y?                     | x < y
        cmovl   rax, rsi                ; if so, set result to y                | stores max(x, y) in rax
        cmp     rax, rdx                ; is max(x,y) less than z?              | [rax] < z
        cmovl   rax, rdx                ; if so, set result to z                | stores max([rax], z) in rax
        ret                             ; the max will be in rax                | exit function