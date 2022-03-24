.data
enterStmt: .asciiz "Enter 2 numbers:\n"
input1: .space 20   # Taking float1 as an input string
input2: .space 20   # Taking float2 as an input string
finalStmt: .asciiz "Final Answer:\n"
decimal: .asciiz "."

.text
.globl main
main:
    # Ask for input
    li $v0, 4
    la $a0, enterStmt
    syscall

    # Getting input 1
    li $v0, 8
    la $a0, input1
    syscall
    # Getting input 2
    li $v0, 8
    la $a0, input2
    syscall

    # Initialising for conversion
    li $t7, 48
    li $t6, 10

        # Get Input 1
    li $t1, 0   #Initialising t1 to 0
    li $t3, 0   #Initialising t3 to 0
    li $t4, 1   #Initialising t4 to 1
    la $a0, input1
    jal strignToFloat
    move $s0, $v0
    move $s1, $v1

        # Get Input 2
    li $t1, 0   #Initialising t1 to 0
    li $t3, 0   #Initialising t3 to 0
    li $t4, 1   #Initialising t4 to 1
    la $a0, input2
    jal strignToFloat
    move $s2, $v0
    move $s3, $v1

    # Power Correction before addition
    li $t4, 3
        # Correction for number1
    move $a0, $s0
    move $a1, $s1
    jal powerCorrection
    move $s0, $a0
        # Correction for number2
    move $a0, $s2
    move $a1, $s3
    jal powerCorrection
    move $s2, $a0

    # Performing Additon
    add $s4, $s0, $s2

    # Print final-answer statement
    li $v0, 4
    la $a0, finalStmt
    syscall

    # Printing the final Answer
    li $t5, 1000

        # Separate the integer and fractional part of the float
    move $a0, $s4
    jal separate
    move $s5, $v0
    move $s6, $v1

        # Print integer part of the float
    li $v0, 1
    move $a0, $s5
    syscall
        # Print decimal point
    li $v0, 4
    la $a0, decimal
    syscall
        # Print fractional part of the float
    li $v0, 1
    move $a0, $s6
    syscall

    # END of the program
    li $v0, 10
    syscall


#Funcions for STRING_TO_FLOAT
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
#END of STRING_TO_FLOAT

#Funcions for POWER_CORRECTION
    powerCorrection:
        beq $a1, $t4, endLoop
        addi $a1, $a1, 1
        mul $a0, $a0, $t6
        j powerCorrection

        endLoop:
        jr $ra
#END of POWER_CORRECTION

#Funcions for SEPARATE_AT_DECIMAL
    separate:
        div $a0, $t5
        mflo $v0
        mfhi $v1
        jr $ra
#END of SEPARATE_AT_DECIMAL