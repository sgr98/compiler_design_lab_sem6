.data
	n_0: .word 0
	i_1: .word 0
	mul_2: .word 0
	n_3: .word 0
	mul_4: .word 0
.text
.globl main
	j main
FUNC_LABEL1:
	li $t0,1
	sw $t0,i_1
	li $t0,1
	sw $t0,mul_2
	LOOP_LABEL1:
	lw $t0,i_1
	lw $t1,n_0
	ble $t0,$t1,L1
	li $t2,0
	j L2
	L1:
	li $t2,1
	L2:

	ble $t2,$zero,LABEL1
	lw $t0,i_1
	lw $t1,mul_2
	mult $t1,$t0
	mflo $t2
	sw $t2,mul_2
	li $t0,1
	lw $t1,i_1
	add $t2,$t1,$t0
	sw $t2,i_1
		j LOOP_LABEL1

	LABEL1:
	lw $t0,mul_2
	move $v1,$t0
	jr $ra
main:
	li $v0,5
	syscall
	sw $v0,n_3
	lw $t0,n_3
	sw $t0,n_0
	jal FUNC_LABEL1
	move $t0,$v1
	sw $t0,mul_4
	li $v0,1
	lw $t0,mul_4
	move $a0,$t0
	syscall

	li $v0,10
	syscall