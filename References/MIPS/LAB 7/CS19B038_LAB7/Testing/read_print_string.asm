.data
enter: .asciiz "Enter a string:\n"
input1: .space 20

.text
.globl main
main:
    li $v0, 4
    la $a0, enter
    syscall

    li $v0, 8
    la $a0, input1
    move $t0, $a0
    syscall

    li $v0, 4
    move $t0, $a0
    la $a0, input1
    syscall

    # End of the program
    li $v0, 10
    syscall