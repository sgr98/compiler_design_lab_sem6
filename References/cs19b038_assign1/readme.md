# DFA SIMULATION ASSIGNMENT 1

<br>

## Aim

To simulate a given DFA which acts similar to generic, table-driven lexical analyser.  

<br>

## Description

### General

* The assignment uses **C++** as its programming language.  
* The DFA is given in the form of a table representing different states, input symbols, and state transitions. The details of it is provided in a text file called "**config.txt**".  
* The assignment implements a class called "**DFA**" which stores all the necessary configurations and provides a method called "**isInputAcceptable(char str[])**" that checks whether a string is accepatble by the DFA or not. The method requires 1 parameter of 'char array' type and returns a boolean.  
* All data members in the class are private and all class methods are public.  
* There is an unsued method called "**printDFA()**" which prints all the configuration details of the DFA which requires no parameters and returns nothing.
* The output of the executable is displayed in the command line.

### Configuration file Details

Line Numbers | Representation
----- | --------------
**First Line** | n as the number of states; States are numbered 1 to n
**Second Line** | s<sub>0</sub> as Starting State
**Third Line** | k as the number of final states
**Fourth Line** | k space-seperated integers as the final states 
**Fifth Line** | m as the number of unique input symbols
**Sixth Line** | m space-seperated characters as the input symbols from the set {a, b, ..., z}
**Next n lines** | m space-seperated integers that indicates the transition table in the order of Sixth Line consisting of either states from 1 to N or -1 which means that there is no transition from that state for the given symbol.
**Next Line** | N<sub>s</sub> as the number of test input strings
**Next N<sub>s</sub> lines** | Input Strings to be tested

<br>

## Run Commands

In order to run the executable file, first navigate to the "cs19b038_assign1" directory and then run this command in the command line:  

> make

This will run the cpp file compilation command:

> g++ dfa_simulation.cpp -o mylex

Then you can execute the file using this command:

> ./mylex

<br>

## About the student

Name: Sagar Singh  
Roll Number: CS19B038  
Email: cs19b038@iittp.ac.in  