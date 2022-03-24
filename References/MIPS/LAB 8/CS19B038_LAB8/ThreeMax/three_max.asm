; Using a friend work as it just isnt working on my laptop and just wanted to check whether its working or not
global three_max
section .text

three_max:
	mov rax, rdx
	cmp rax, rcx
	cmovl rax, rcx
	cmp rax, r8
	cmovl rax, r8
	ret