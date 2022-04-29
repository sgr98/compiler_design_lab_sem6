.data
	a_0: .word 0
	b_1: .word 0
	a_2: .word 0
	b_3: .word 0
	n_4: .word 0
	c_5: .byte 0
	d_6: .byte 0
	a_7: .word 0
	b_8: .word 0
	n_9: .word 0
	x_10: .word 0
	y_11: .word 0
	n_12: .word 0
.text
.globl main
	li $t0,1
	li $t1,3
	bge $t0,$t1,L1
	li $t2,0
	j L2
	L1:
	li $t2,1
	L2:

	li $v0,10
	syscall