#include <stdio.h>
void main()
{
	int save[4] = {3, 3, 4, 3};
	int k = 3;
	int i = 0;
	while (save[i] == k) {
		i += 2;
	}
	printf("Tirutsava 2020\n");
	printf("Value of i is: %d\n", i);
	// To print the contents of a register move it to $a0 and then use syscall:
	// li $v0, 1
	// move $a0, $t0 # assuming variable "i" is stored in $t0
	// syscall
}