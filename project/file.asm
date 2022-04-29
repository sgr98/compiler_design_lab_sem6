.data
	a_0: .word 0
	b_1: .word 0
	d_2: .word 0
	l_3: .word 0
	e_4: .word 0
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
	li $t0,10
	sw $t0,d_2
	LOOP_LABEL1:
	lw $t0,d_2
	li $t1,20
	bge $t0,$t1,L3
	li $t2,0
	j L4
	L3:
	li $t2,1
	L4:

	ble $t2,$zero,LABEL2
	li $t0,1
	lw $t1,d_2
	add $t2,$t1,$t0
	sw $t2,d_2
	li $t0,5
	sw $t0,l_3
		j LOOP_LABEL1

	LABEL2:
	li $t0,-1
	sw $t0,a_0
	li $v0,1
	lw $t0,d_2
	move $a0,$t0
	syscall

	li $v0,1
	lw $t1,a_0
	move $a0,$t1
	syscall

		j END1

	LABEL1:
	li $t2,20
	sw $t2,e_4
	li $t2,-1
	sw $t2,a_0
	li $t2,-1
	sw $t2,b_1
	END1:
	lw $t2,a_0
	lw $t3,b_1
	blt $t2,$t3,L5
	li $t4,0
	j L6
	L5:
	li $t4,1
	L6:

	ble $t4,$zero,LABEL3
	li $t2,1
	lw $t3,a_0
	sub $t4,$t3,$t2
	sw $t4,a_0
	LABEL3:
	li $v0,10
	syscall