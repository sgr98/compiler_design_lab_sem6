.data
    message: .asciiz "Hello World"

.text
.globl main
main:
    jal displayMessage  # Function call

    li $v0, 10          # Exit Statement
    syscall

displayMessage:
    li $v0, 4
    la $a0, message
    syscall
    jr $ra              # Return statemet