.data
	a_0: .word 0
	b_1: .word 0
	d_2: .word 0
	l_3: .word 0
	e_4: .word 0
.text
.global main
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
	li $t1,10
	sw $t1,d_2
	LOOP_LABEL1:
	lw $t1,d_2
	li $t2,20
	blt $t0,$t2,L3
	li $t3,0
	j L4
	L3:
	li $t3,1
	L4:

	ble $t3,$zero,LABEL2
	li $t2,1
	lw $t3,d_2
	add $t4,$t3,$t2
	sw $t4,d_2
	li $t2,5
	sw $t2,l_3
	j  LOOP_LABEL1

	LABEL2:
	li $t2,-1
	sw $t2,a_0
	li $v0,1
	lw $t2,d_2
	move $a0,$t2
	syscall

	li $v0,1
	lw $t3,a_0
	move $a0,$t3
	syscall

	j  END1

	LABEL1:
	li $t4,20
	sw $t4,e_4
	li $t4,-1
	sw $t4,a_0
	li $t4,-1
	sw $t4,b_1
	END1:
	lw $t4,a_0
	lw $t5,b_1
	blt $t0,$t5,L5
	li $t6,0
	j L6
	L5:
	li $t6,1
	L6:

	ble $t6,$zero,LABEL3
	li $t5,1
	lw $t6,a_0
	sub $t7,$t6,$t5
	sw $t7,a_0
	LABEL3:
