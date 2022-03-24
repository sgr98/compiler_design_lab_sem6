- Today you will be working with the Intel x86 architecture which more or less means that you will be writing assembly code and executing it on your laptop.
- Install nasm (`sudo apt-get install nasm`)
- On Windows: https://www.nasm.us/pub/nasm/releasebuilds/2.14.02/win64/ (Kindly note that I haven't tested this on Windows)
- What is nasm?
	- https://en.wikipedia.org/wiki/Netwide_Assembler
	- The Netwide Assembler (NASM) is an assembler and disassembler for the Intel x86 architecture. It can be used to write 16-bit, 32-bit (IA-32) and 64-bit (x86-64) programs. NASM is considered to be one of the most popular assemblers for Linux.
	- Many many developers all over the net respect NASM for what it is: a widespread (thus netwide), portable (thus netwide!), very flexible and mature assembler tool with support for many output formats (thus netwide!!): https://github.com/netwide-assembler/nasm
- Mix, Remix, Sing, Dance! Yes, you can mix C and assembly language.
- Write a simple function that takes in three integers and returns the maximum value.
- Explore nasm.
	- We will be spending more time with nasm in the coming weeks!

Not for evaluation:
- Read about ELF: https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
- On your linux box, read the manual page for elf: `$man elf`
	- You might not understand anything. Just give it a try.