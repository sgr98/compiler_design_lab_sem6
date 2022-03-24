.text
.globl main
main:
    li $t6, 10

    li $t4, 3
    li $s0, 2
    li $s1, 1
    move $a0, $s0
    move $a1, $s1
    jal powerCorrection
    move $s0, $a0

    # End of the program
    li $v0, 10
    syscall

powerCorrection:
    beq $a1, $t4, endLoop
    addi $a1, $a1, 1
    mul $a0, $a0, $t6
    j powerCorrection

    endLoop:
    jr $ra