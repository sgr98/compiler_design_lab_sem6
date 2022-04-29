.data
	i_0: .word 0
	n_1: .word 0
	fact_2: .word 0
.text
.global main
main:
	li $t0,1
	sw $t0,i_0
	li $v0,5
	syscall
	sw $v0,n_1
	li $t0,1
	sw $t0,fact_2
	LOOP_LABEL1:
	lw $t0,i_0
	lw $t1,n_1
	ble $t0,$t1,L1
	li $t2,0
	j L2
	L1:
	li $t2,1
	L2:

	ble $t2,$zero,LABEL1
	lw $t0,i_0
	lw $t1,fact_2
	mult $t1,$t0
	mflo $t2
	sw $t2,fact_2
	li $t0,1
	lw $t1,i_0
	add $t2,$t1,$t0
	sw $t2,i_0
	j  LOOP_LABEL1

	LABEL1:
	li $v0,1
	lw $t0,fact_2
	move $a0,$t0
	syscall

