.data
    varj: .word 0
    vark: .word 3
    varl: .word 7
    varm: .word 8
    varn: .word 2

.text
.globl main
main:
    la $s0, varj
    la $s1, vark
    la $s2, varl
    la $s3, varm
    la $s4, varn

    #Initialize the arguments
    lw $a2, 0($s2)
    lw $a3, 0($s3)

    lw $s5, 0($s1)          # Accessing value at k
    lw $s6, 0($s4)          # Accessing value at n

    jal multi_fun           # multi_fun(l, m)
    move $t0, $v1

    div $t0, $s6            # multi_fun(l, m) / n
    mflo $t1

    add $t2, $t1, $s5       # k + multi_fun(l, m) / n

    sw $t2, 0($s0)          # j = k + multi_fun(l, m) / n

    li $v0, 10              # Exiting the program
    syscall

multi_fun:
    mul $v1, $a2, $a3  
    jr $ra