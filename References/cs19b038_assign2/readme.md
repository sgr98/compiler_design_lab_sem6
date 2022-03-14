# Compiler Design Programmin Assignment 2

<br>

## My Details

<br>

Name: Sagar Singh  
Roll No.: CS19B038  
Email: cs19b038@iittp.ac.in

<br>

## Aim

<br>

To identify the constructs of C programming language and develop a lexical analyzer to tokenize the programs written in C programming language.

<br>

## Description

### General

* In this assignment, a lex file is constructed called **constructs.l** which will generate a C program file.
* The lex file consists of lexemes such as constants, identifiers, keywords, operators and other tokens.
* This lex file is then used to create a lexical analyser generator for the C programming language.
* The generated C program file is called **lex.yy.c**.
* Compiling this C program file, we get an executable file **lexer**.
* We can send a file as an argument during execution to execute this file.
* The output of the executable is displayed in the command line. 

<br>

### Main Files

1. constructs.l : Lex file for C programmin language
2. Makefile : Can be used for compilations using the `make` command
3. prog1.c : Test C Program1
4. prog2.c : Test C Program2
5. prog3.c : Test C Program3
6. prog4.c : Test C Program4
7. undertaking.pdf : My undertaking for the assignment

<br>

### Essential Changes

Since I am using Windows OS for this assignment. There are some differences when compared to the linux version taught in class. The following are the differences:

* Windows uses `flex` command instead of `lex` command. So be sure to change Makefile before compiling.
* Windows requires an extra `int yywrap(){}` statement which is present just above the `int main() {...}` line.

<br>

## Run Commands

<br>

In order to run the executable file, first navigate to the "cs19b038_assign2" directory and then run this command in the command line:

> make

This will run the lex file compilation and c file compilation command:

> flex constructs.l  
> gcc lex.yy.c -o lexer

Then you can execute the file using this command along with a file as an argumment:

> ./lexer file_name.c

<br>
