.data
    var: .word 7

.text
.globl main
main:
    la $s0, var
    lw $a1, 0($s0)

    li $t1, 1
    li $v1, 1

    jal factorial

    return:
    move $s1, $v1

    li $v0, 10
    syscall

factorial:
    bne $a1, $t1, check
        jr $ra

    check:
    mul $v1, $v1, $a1
    sub $a1, $a1, $t1

    jal factorial
    j return