.data
	a_0: .word 0
	b_1: .word 0
	c_2: .word 0
.text
.globl main
main:
	li $t0,0
	sw $t0,a_0
	li $t0,1
	sw $t0,b_1
	lw $t0,a_0
	lw $t1,b_1
	blt $t0,$t1,L1
	li $t2,0
	j L2
	L1:
	li $t2,1
	L2:

	ble $t2,$zero,LABEL1
	li $t0,-1
	sw $t0,a_0
	LABEL1:
	lw $t0,a_0
	lw $t1,b_1
	bgt $t0,$t1,L3
	li $t2,0
	j L4
	L3:
	li $t2,1
	L4:

	ble $t2,$zero,LABEL2
	li $t0,-1
	sw $t0,b_1
	LABEL2:
	li $t0,5
	sw $t0,c_2
	lw $t0,a_0
	lw $t1,c_2
	bgt $t0,$t1,L5
	li $t2,0
	j L6
	L5:
	li $t2,1
	L6:

	ble $t2,$zero,LABEL3
	li $t0,-1
	sw $t0,c_2
	LABEL3:
	li $v0,10
	syscall