.data
	a_0: .word 0
	n_1: .word 0
	i_2: .word 0
.text
.globl main
	j main
main:
	li $t0,0
	sw $t0,a_0
	li $t0,10
	sw $t0,n_1
	li $t0,0
	sw $t0,i_2
	LOOP_LABEL1:
	lw $t0,i_2
	lw $t1,n_1
	blt $t0,$t1,L1
	li $t2,0
	j L2
	L1:
	li $t2,1
	L2:

	ble $t2,$zero,LABEL1
	lw $t0,i_2
	lw $t1,a_0
	add $t2,$t1,$t0
	sw $t2,a_0
	li $t0,1
	lw $t1,i_2
	add $t2,$t1,$t0
	sw $t2,i_2
	lw $t0,i_2
	li $t1,5
	beq $t0,$t1,L3
	li $t2,0
	j L4
	L3:
	li $t2,1
	L4:

	ble $t2,$zero,LABEL2
		j LABEL2

	LABEL2:
		j LOOP_LABEL1

	LABEL1:
	li $t0,5
	lw $t1,n_1
	sub $t2,$t1,$t0
	sw $t2,n_1
	li $v0,10
	syscall