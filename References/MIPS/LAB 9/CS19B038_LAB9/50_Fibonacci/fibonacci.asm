; -----------------------------------------------------------------------------
; I have read it and understood it.
; Also sorry I could not do much with the code since my linux dual boot has some problem with the source list
; which does not allow me to "sudo apt-get install build essentials" which does not allow me to get gnu to run gcc
; Also I have looked for some solutions but I do not know whether they would work with ubuntu 20.04 so I would 
; fix them later.
; -----------------------------------------------------------------------------

        global  main
        extern  printf
        section .text
main:
        push    rbx                     ; we have to save this since we use it  | saving rbx

        mov     ecx, 50                 ; ecx will countdown to 0               | storing the counter for the series
        xor     rax, rax                ; rax will hold the current number      | holding the current number of the series (i.e. a in c = b + a)
        xor     rbx, rbx                ; rbx will hold the next number         | holding the next number of the series (i.e. b in c = b + a)
        inc     rbx                     ; rbx is originally 1                   | initialising the b = 1, and a = 0
print:
        ; We need to call printf, but we are using rax, rbx, and rcx.  printf
        ; may destroy rax and rcx so we will save these before the call and
        ; restore them afterwards.

        push    rax                     ; caller-save register                  |
        push    rcx                     ; caller-save register                  |

        mov     rdi, format             ; set 1st parameter (format)            | saving format in printf for the number to be printed
        mov     rsi, rax                ; set 2nd parameter (current_number)    | saving number in printf that is the number to be printed
        xor     rax, rax                ; because printf is varargs             |

        ; Stack is already aligned because we pushed three 8 byte registers     

        call    printf                  ; printf(format, current_number)        | calling the printf in the function

        pop     rcx                     ; restore caller-save register          | 
        pop     rax                     ; restore caller-save register          | 

        mov     rdx, rax                ; save the current number               | (<-exactly as left)
        mov     rax, rbx                ; next number is now current            | setting next as current number
        add     rbx, rdx                ; get the new next number               | add to get new number (i.e. c in c = b + a)
        dec     ecx                     ; count down                            | decrement the counter
        jnz     print                   ; if not done counting, do some more    | check the counter

        pop     rbx                     ; restore rbx before returning          |
        ret                                                                     | Exit
format:
        db  "%20ld", 10, 0