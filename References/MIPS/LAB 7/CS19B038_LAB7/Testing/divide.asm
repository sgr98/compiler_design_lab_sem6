.text
.globl main
main:
    li $s0, 23
    li $s1, 10

    div $s0, $s1

    mflo $s2
    mfhi $s3

    # End of the program
    li $v0, 10
    syscall