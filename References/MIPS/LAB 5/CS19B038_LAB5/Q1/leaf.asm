.data
    varg: .word 20
    varh: .word 15
    vari: .word 23
    varj: .word 5

.text
.globl main
main:
    la $s0, varg
    la $s1, varh
    la $s2, vari
    la $s3, varj

    #Initializing the arguments
    lw $a0, 0($s0)
    lw $a1, 0($s1)
    lw $a2, 0($s2)
    lw $a3, 0($s3)

    jal leaf_example         # Calling the function

    move $s5, $v1

    li $v0, 10              # Exiting the program
    syscall

leaf_example:
    add $t0, $a0, $a1
    add $t1, $a2, $a3
    sub $v1, $t0, $t1

    jr $ra

