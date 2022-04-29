.data
	i_0: .word 0
	n_1: .word 0
	sum_2: .word 0
.text
.global main
main:
	li $t0,2
	sw $t0,i_0
	lw $t0,n_1
	li $t1,0
	sw $t1,sum_2
	LOOP_LABEL1:
	lw $t1,i_0
	lw $t2,n_1
	ble $t1,$t2,L1
	li $t3,0
	j L2
	L1:
	li $t3,1
	L2:

	bge $t3,$zero,LABEL1
	lw $t1,i_0
	lw $t2,sum_2
	add $t3,$t2,$t1
	sw $t3,sum_2
	li $t1,1
	lw $t2,i_0
	add $t3,$t2,$t1
	sw $t3,i_0
	j  LOOP_LABEL1

	LABEL1:
	lw $t1,sum_2
