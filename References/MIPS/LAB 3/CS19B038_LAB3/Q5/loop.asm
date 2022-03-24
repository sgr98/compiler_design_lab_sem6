.data
k: .word 3
i: .word 0
save: .word 3, 3, 4, 3
title: .asciiz "Tirutsava 2020"
value_print: .asciiz "Value of i is: "
new_line: .asciiz "\n"
    
.text
.globl main
main:
    lw $s0, save
    lw $s1, k
    lw $s2, i  
    loop:
        sll $t1, $s2, 2             # Multiplying index with 4
        add $t1, $t1, $s0           # getting the address for i(%s0) = save[i]
        # lw $t0, $t1                 # loading the content at save[i] in $t0 
        bne $t1, $s1, Terminate     # comparing integer in $t1 with k
        addi $s2, $s2, 2            # incrementing index by 2
        j loop
Terminate:
    sw $s2, i

    li $v0, 4
    la $a0, title
	syscall
    la $a0, new_line
	syscall
    la $a0, value_print
	syscall

    li $v0, 1
    lw $a0, i
	syscall

    li $v0, 4
    la $a0, new_line
	syscall

    jr $ra

