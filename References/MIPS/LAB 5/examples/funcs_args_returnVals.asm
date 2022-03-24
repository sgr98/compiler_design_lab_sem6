.data
    vara: .word 10
    varb: .word 5
    varRes: .word 0

.text
.globl main
main:
    la $s0, vara
    la $s1, varb

    #Arguments
    lw $a2, 0($s0)
    lw $a3, 0($s1)

    jal addNumbers
    li $v0, 1
    move $a0, $v1
    syscall

    li $v0, 10
    syscall

addNumbers:
    add $v1, $a2, $a3
    jr $ra
