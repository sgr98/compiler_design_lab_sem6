# $s0 : Number is stored at this location
# $t0 : to be shifted and ANDed
# $t1 : used for indexing
# $t2 : upper limit for indexing
# $s1 : address location of final
# $t4 : current bit sequence
# $s4 : tracking sequence count of 0
# $s5 : tracking sequence count of 1
# $t3 : to get current bit

.data
sto: .word 0, 1

.text
.globl main
main:
    li $s0, 0x39b2f578          # Random Number = 0011 1001 1011 0010 1111 0101 0111 1000 in binary
    la $s1, sto
    lw $t0, 4($s1)              # Storing first shift value as 1
    lw $t1, 0($s1)              # Storing first index as 0
    li $t2, 31

    li $s4, 0
    li $s5, 0

    and $t3, $s0, $t0
    beq $t3, $0, initZero
    j initOne

    loop:
        and $t3, $s0, $t0
        bne $t4, $t3, check

        nextItr:
        addi $t1, $t1, 1
        beq $t2, $t1, Terminate
        sll $t0, $t0, 1
        sll $t4, $t4, 1
        j loop

Terminate:
    sw $s4, 0($s1)
    sw $s5, 4($s1)
    jr $ra


#FUNCTIONS
check:
beq $t3, $0, initZero
    j initOne

initZero:
    addi $s4, $s4, 1
    li $t4, 0
    j nextItr

initOne:
    move $t4, $t3
    addi $s5, $s5, 1
    j nextItr