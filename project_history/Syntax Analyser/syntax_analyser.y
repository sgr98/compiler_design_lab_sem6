%{
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
extern FILE *yyin;
%}

%start program_start
%token MAIN VOID RETURN INT FLOAT CHAR BOOLEAN
%token IDENTIFIER BOOLEAN_LIT FLOAT_LIT INT_LIT CHAR_LIT
%token SEMICOLON COMMA LP RP LC RC
%token ADD_ASSIGN_OP SUB_ASSIGN_OP MUL_ASSIGN_OP DIV_ASSIGN_OP REM_ASSIGN_OP
%token EQUAL_OP NOT_EQUAL_OP MRTE LSTE MRT LST
%token LOGICAL_AND_OP LOGICAL_OR_OP EXCLAMATION_OP
%token ASSIGN_OP ADD_OP SUB_OP MUL_OP DIV_OP REM_OP

%%

program_start:  program	{printf("program_start\n");}
            	;

program:	functions MAIN block	{printf("program 1\n");}
        |	MAIN block              {printf("program 2\n");}
        ;

functions:		function_declaration            {printf("functions 1\n");}
			|	functions function_declaration	{printf("functions 2\n");}
            ;

function_declaration:	VOID IDENTIFIER LP params RP block      {printf("function_declaration 1\n");}
					|	data_type IDENTIFIER LP params RP block	{printf("function_declaration 2\n");}
                    ;

params:		param               {printf("params 1\n");}
		|	params COMMA param	{printf("params 2\n");}
		|	                    {printf("params 3\n");}
        ;

param:		data_type IDENTIFIER	{printf("param\n");}
    	;

block:		LC statements RC	{printf("block 1\n");}
        |   LC RC	            {printf("block 2\n");}
        ;

statements:		statement               {printf("statements 1\n");}
			|	statements statement	{printf("statements 2\n");}
            ;

statement:		variable_declaration SEMICOLON  {printf("statement 1\n");}
			|	expression SEMICOLON            {printf("statement 2\n");}
			|	return_statement SEMICOLON      {printf("statement 3\n");}
            ;

variable_declaration:		data_type variable	{printf("variable_declaration ");}
                        ;

variable:		IDENTIFIER                                      {printf("variable 1 ");}
			|	IDENTIFIER ASSIGN_OP expression                 {printf("variable 2 ");}
			|	variable COMMA IDENTIFIER                       {printf("variable 3 ");}
			|	variable COMMA IDENTIFIER ASSIGN_OP expression  {printf("variable 4 ");}
            ;

expression:		assign_expression	{printf("expression 1 ");}
			|	op_expression       {printf("expression 2 ");}
            ;

assign_expression:		IDENTIFIER ASSIGN_OP op_expression      {printf("assign_expression 1 ");}
					|	IDENTIFIER ADD_ASSIGN_OP op_expression  {printf("assign_expression 2 ");}
					|	IDENTIFIER SUB_ASSIGN_OP op_expression  {printf("assign_expression 3 ");}
					|	IDENTIFIER MUL_ASSIGN_OP op_expression  {printf("assign_expression 4 ");}
					|	IDENTIFIER DIV_ASSIGN_OP op_expression  {printf("assign_expression 5 ");}
					|	IDENTIFIER REM_ASSIGN_OP op_expression  {printf("assign_expression 6 ");}
                    ;

op_expression:		sub_expression                      		{printf("op_expression 1 ");}
				|	op_expression ADD_OP sub_expression         {printf("op_expression 2 ");}
				|	op_expression SUB_OP sub_expression         {printf("op_expression 3 ");}

				|	op_expression EQUAL_OP op_expression        {printf("op_expression 4 ");}
				|	op_expression NOT_EQUAL_OP op_expression    {printf("op_expression 5 ");}
				| 	op_expression LST op_expression             {printf("op_expression 6 ");}
				| 	op_expression LSTE op_expression            {printf("op_expression 7 ");}
				| 	op_expression MRT op_expression             {printf("op_expression 8 ");}
				| 	op_expression MRTE op_expression            {printf("op_expression 9 ");}

				|	op_expression LOGICAL_OR_OP sub_expression	{printf("op_expression 10 ");}
				|	EXCLAMATION_OP op_expression                {printf("op_expression 11 ");}
                ;

sub_expression:		term                                			{printf("sub_expression 1 ");}
                |	sub_expression MUL_OP sub_expression 	        {printf("sub_expression 2 ");}
				|	sub_expression DIV_OP sub_expression          	{printf("sub_expression 3 ");}
				|	sub_expression REM_OP sub_expression          	{printf("sub_expression 4 ");}
				|	sub_expression LOGICAL_AND_OP sub_expression	{printf("sub_expression 5 ");}
				|	LP op_expression RP                 			{printf("sub_expression 6 ");}
                ;

return_statement:		RETURN op_expression	{printf("return_statement ");}
                    ;

term:		BOOLEAN_LIT     {printf("term 1 ");}
		|	FLOAT_LIT       {printf("term 2 ");}
		|	INT_LIT         {printf("term 3 ");}
		|	CHAR_LIT        {printf("term 4 ");}
		|	functional_call {printf("term 5 ");}
		|	IDENTIFIER		{printf("term 6 ");}
        ;

functional_call:	IDENTIFIER LP args RP	{printf("functional_call 6 ");}
                ;

args:		term            {printf("args 1 ");}
		|	args COMMA term {printf("args 2 ");}
		|	                {printf("args 3 ");}
        ;

data_type:		INT		{printf("data_type 1 ");}
			|	FLOAT 	{printf("data_type 2 ");}
			|	CHAR    {printf("data_type 3 ");}
			|	BOOLEAN	{printf("data_type 4 ");}
			;
%%

// ./parser arithmetic.xgvs
int main(int argc, char *argv[]) {
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
           yyin = fp;
		else
			printf("Error opening file\n");
    }

    yyparse();
    return 0;
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 