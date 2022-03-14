# Compiler Design Programmin Assignment 3 / problem 1

<br>

## My Details

<br>

Name: Sagar Singh  
Roll No.: CS19B038  
Email: cs19b038@iittp.ac.in

<br>

## Aim

<br>

Consider a robot arm that accepts two commands: Command a puts an apple in a bag, and command d takes an apple from the bag. Assume that the robot arm starts with an empty bag. A valid command sequence for the robot arm should have no prefix that takes more apples than it puts in the bag.  
Construct a parser for this problem.

<br>

## Description

### General

* This problem involves a lex and yacc file called **apple.l** and **apple.y** respectively.
* The lex file provides lexemes for the yacc parsing file.
* The yacc file creates a LALR parser.
* The generated C program file are **lex.yy.c**, **y.tab.c** and **y.tab.h**.
* Compiling this C program file, we get an executable file **parser**.
* We can send a text file as an argument during execution while executing this file.
* The output of the executable is displayed in the command line. 

<br>

### Derivations

```
S   =>  A ;    |   S A ;  
A   =>  B  
B   =>  a B    |   d B      |   
```

<br>

### Main Files

1. apple.l : Lex file
2. apple.y : Yacc file
3. Makefile : Can be used for compilations using the `make` command
4. apple.txt : Test data

<br>

## NOTE

<br>

### Essential Changes

Since I am using Windows OS for this assignment. There are some differences when compared to the linux version taught in class. The following are the differences:

* Windows uses `flex` command instead of `lex` command. So be sure to change Makefile before compiling.
* Windows uses `bison` command instead of `yacc` command. So be sure to change Makefile before compiling.
* Windows requires an extra `int yywrap(){}` statement which is present at the bottom in lex files.

Be sure to make these changes before executing any files.

<br>

## Run Commands

<br>

In order to compile the source program, first navigate to the "cs19b038_assign3/p1" directory and then run this command in the command line:

> make -f Makefile.mk

Then you can execute the file using this command along with a file as an argumment:

> ./parser apple.txt

<br>
