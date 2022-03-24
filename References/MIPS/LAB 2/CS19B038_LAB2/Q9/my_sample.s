# Assembler Directive to load the
# data segment, text segment
	.data
	.word 9

	.text
	.globl main	
main:
	lui $s0, 0x1001

    lw $s1, 0($s0)

    addi $s1, $s1, 5

    sw $s1, 0($s0)

    jr $ra