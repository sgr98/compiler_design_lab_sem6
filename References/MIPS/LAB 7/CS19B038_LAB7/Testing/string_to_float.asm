.data
    vara: .asciiz "0.02"

.text
.globl main
main:
    li $t7, 48
    li $t6, 10
    li $t1, 0   #Initialising t1 to 0
    li $t3, 0   #Initialising t3 to 0
    li $t4, 1   #Initialising t4 to 1
    la $a0, vara
    jal strignToFloat

    move $s0, $v0
    move $s1, $v1

    li $v0, 10
    syscall

stringLoop:
    sub $t2, $t0, $t7
    blt $t2, $0, encounter

    mul $t1, $t1, $t6
    add $t1, $t1, $t2

    bne $t4, $0, back
    addi $t3, $t3, 1

    back:
    addi $a0, $a0, 1

strignToFloat:
    lb $t0, 0($a0)
    bne $t0, $0, stringLoop

    move $v0, $t1
    move $v1, $t3
    jr $ra

encounter:
    li $t4, 0
    j back
