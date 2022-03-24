.data
.word 127

.text
.globl main
main:
    lui $s0, 0x1001
	lw $s3, 0($s0) 
    jr $ra