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

program:	MAIN block              {printf("program 1\n");}
        |	functions MAIN block	{printf("program 2\n");}
        ;

functions:		function_declaration            {printf("functions 1\n");}
			|	functions function_declaration	{printf("functions 2\n");}
            ;

function_declaration:	VOID IDENTIFIER LP RP block      		{printf("function_declaration 1\n");}
					|	VOID IDENTIFIER LP params RP block      {printf("function_declaration 2\n");}
					|	data_type IDENTIFIER LP RP block		{printf("function_declaration 3\n");}
					|	data_type IDENTIFIER LP params RP block	{printf("function_declaration 4\n");}
                    ;

params:		param               {printf("params 1\n");}
		|	params COMMA param	{printf("params 2\n");}
		;

param:		data_type IDENTIFIER	{printf("param\n");}
    	;

block:		LC statement_list RC	{printf("block 1\n");}
        |   LC RC	            	{printf("block 2\n");}
        ;

statement_list:		statement               	{printf("statement_list 1\n");}
				|	statement_list statement	{printf("statement_list 2\n");}
            	;

statement:		variable_declaration SEMICOLON  {printf("statement 1\n");}
			|	expression SEMICOLON            {printf("statement 2\n");}
			|	return_statement SEMICOLON      {printf("statement 3\n");}
			|	SEMICOLON						{printf("statement 4\n");}
            ;

variable_declaration:		data_type variable_list	{printf("variable_declaration ");}
                        ;

variable_list:		IDENTIFIER                                      	{printf("variable_list 1 ");}
				|	IDENTIFIER ASSIGN_OP expression                 	{printf("variable_list 2 ");}
				|	variable_list COMMA IDENTIFIER                      {printf("variable_list 3 ");}
				|	variable_list COMMA IDENTIFIER ASSIGN_OP expression {printf("variable_list 4 ");}
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

op_expression:		arithmetic_additive_expression              {printf("op_expression 1 ");}
				|	logical_or_expression         				{printf("op_expression 2 ");}
                ;

arithmetic_additive_expression:		arithmetic_multiplicative_expression
									{
										printf("arithmetic_additive_expression 1 ");
									}

								|	arithmetic_additive_expression ADD_OP arithmetic_multiplicative_expression
									{
										printf("arithmetic_additive_expression 2 ");
									}

								|	arithmetic_additive_expression SUB_OP arithmetic_multiplicative_expression
									{
										printf("arithmetic_additive_expression 3 ");
									}

								;

arithmetic_multiplicative_expression:	term
										{
											printf("arithmetic_multiplicative_expression 1 ");
										}	
									
									|	arithmetic_multiplicative_expression MUL_OP term
										{
											printf("arithmetic_multiplicative_expression 2 ");
										}

									|	arithmetic_multiplicative_expression DIV_OP term
										{
											printf("arithmetic_multiplicative_expression 3 ");
										}

									|	arithmetic_multiplicative_expression REM_OP term
										{
											printf("arithmetic_multiplicative_expression 4 ");
										}

									|	LP op_expression RP
										{
											printf("arithmetic_multiplicative_expression 6 ");
										}
									;

logical_or_expression:		logical_and_expression
							{
								printf("logical_or_expression 1 ");
							}

						|	logical_or_expression LOGICAL_OR_OP logical_and_expression
							{
								printf("logical_or_expression 2 ");
							}
						;
						
logical_and_expression:		logical_rel_expression
							{
								printf("logical_and_expression 1 ");
							}

						|	logical_and_expression LOGICAL_AND_OP logical_rel_expression
							{
								printf("logical_and_expression 1 ");
							}
						;

logical_rel_expression:		logical_comp_expression
							{
								printf("logical_rel_expression 1 ");
							}

						|	logical_rel_expression EQUAL_OP logical_comp_expression
							{
								printf("logical_rel_expression 2 ");
							}
						
						|	logical_rel_expression NOT_EQUAL_OP logical_comp_expression
							{
								printf("logical_rel_expression 3 ");
							}
						;

logical_comp_expression:	logical_not_expression
							{
								printf("logical_comp_expression 1 ");
							}

						|	logical_comp_expression	LST logical_not_expression
							{
								printf("logical_comp_expression 2 ");
							}
						
						|	logical_comp_expression	LSTE logical_not_expression
							{
								printf("logical_comp_expression 3 ");
							}

						|	logical_comp_expression	MRT logical_not_expression
							{
								printf("logical_comp_expression 4 ");
							}

						|	logical_comp_expression	MRTE logical_not_expression
							{
								printf("logical_comp_expression 5 ");
							}
						;

logical_not_expression:		term
							{
								printf("logical_not_expression 1 ");
							}
						
						|	EXCLAMATION_OP logical_not_expression
							{
								printf("logical_not_expression 2 ");
							}

						|	LP op_expression RP
							{
								printf("logical_not_expression 4 ");
							}

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

functional_call:	IDENTIFIER LP RP		{printf("functional_call 1 ");}
				|	IDENTIFIER LP args RP	{printf("functional_call 2 ");}
                ;

args:		term            {printf("args 1 ");}
		|	args COMMA term {printf("args 2 ");}
        ;

data_type:		INT		{printf("data_type 1 ");}
			|	FLOAT 	{printf("data_type 2 ");}
			|	CHAR    {printf("data_type 3 ");}
			|	BOOLEAN	{printf("data_type 4 ");}
			;
%%

// ./parser ./exmp/arithmetic.xvgs
int main(int argc, char *argv[]) {
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
           yyin = fp;
		else
			printf("Error opening file\n");
    }

    yyparse();
	// printf("Hello\n");
    return 0;
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 