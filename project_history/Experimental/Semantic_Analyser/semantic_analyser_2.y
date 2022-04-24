%{
	#include <fstream>
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include <vector>
	#include <fstream>

	using namespace std;

	extern FILE *yyin;

	extern "C"
	{
		// int yyparse(void);
		int yylex();
		void yyerror(const char* s) {
			fprintf (stderr, "%s\n", s);
			exit(EXIT_SUCCESS);
		}
		int yywrap() {
			return 1;
		}
	}
	int DEBUG_CODE = 1;

	string TAC = "";
%}

%start program_start
// %union {char *str; int type;}

%token MAIN VOID RETURN INT FLOAT CHAR BOOLEAN IF ELIF ELSE LOOP BREAK CONTINUE
%token IDENTIFIER BOOLEAN_LIT FLOAT_LIT INT_LIT CHAR_LIT
%token SEMICOLON COMMA LP RP LC RC
%token ADD_ASSIGN_OP SUB_ASSIGN_OP MUL_ASSIGN_OP DIV_ASSIGN_OP REM_ASSIGN_OP
%token EQUAL_OP NOT_EQUAL_OP MRTE LSTE MRT LST
%token LOGICAL_AND_OP LOGICAL_OR_OP EXCLAMATION_OP
%token ASSIGN_OP ADD_OP SUB_OP MUL_OP DIV_OP REM_OP

%%

program_start:  program
				{
					if(DEBUG_CODE == 1)
						printf("program_start\n");
				}
            	;

program:	MAIN block
			{
				if(DEBUG_CODE == 1)
					printf("program 1\n");
			}

        |	functions MAIN block
			{
				if(DEBUG_CODE == 1)
					printf("program 2\n");
			}
        ;

functions:		function_declaration
				{
					if(DEBUG_CODE == 1)
						printf("functions 1\n");
				}

			|	functions function_declaration
				{
					if(DEBUG_CODE == 1)
						printf("functions 2\n");
				}
            ;

function_declaration:	VOID IDENTIFIER LP RP block
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 1\n");
						}

					|	VOID IDENTIFIER LP params RP block
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 2\n");
						}

					|	data_type IDENTIFIER LP RP block
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 3\n");
						}

					|	data_type IDENTIFIER LP params RP block
						{
							if(DEBUG_CODE == 1)
								printf("function_declaration 4\n");
						}
                    ;

params:		param
			{
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}

		|	params COMMA param
			{
				if(DEBUG_CODE == 1)
					printf("params 2\n");
			}
		;

param:		data_type IDENTIFIER
			{
				if(DEBUG_CODE == 1)
					printf("param \n");
			}
    	;

block:		LC RC
			{
				if(DEBUG_CODE == 1)
					printf("block 1\n");
			}

        |   LC statement_list RC
			{
				if(DEBUG_CODE == 1)
					printf("block 2\n");
			}
        ;

statement_list:		statement
					{
						if(DEBUG_CODE == 1)
							printf("statement_list 1\n");
					}

				|	statement_list statement
					{
						if(DEBUG_CODE == 1)
							printf("statement_list 2\n");
					}
            	;

statement:		variable_declaration SEMICOLON
				{
					if(DEBUG_CODE == 1)
						printf("statement 1\n");
				}

			|	expression SEMICOLON
				{
					if(DEBUG_CODE == 1)
						printf("statement 2\n");
				}

			|	conditional_statement
				{
					if(DEBUG_CODE == 1)
						printf("statement 3\n");
				}

			|	loop_statement
				{
					if(DEBUG_CODE == 1)
						printf("statement 4\n");
				}

			|	return_statement SEMICOLON
				{
					if(DEBUG_CODE == 1)
						printf("statement 5\n");
				}

			|	SEMICOLON
				{
					if(DEBUG_CODE == 1)
						printf("statement 6\n");
				}
            ;

variable_declaration:	data_type variable_list
						{
							if(DEBUG_CODE == 1)
								printf("variable_declaration \n");
						}
                    ;

variable_list:		IDENTIFIER
					{
						if(DEBUG_CODE == 1)
							printf("variable_list 1 ");
					}

				|	IDENTIFIER ASSIGN_OP expression
					{
						if(DEBUG_CODE == 1)
							printf("variable_list 2 ");
					}

				|	variable_list COMMA IDENTIFIER
					{
						if(DEBUG_CODE == 1)
							printf("variable_list 3 ");
					}

				|	variable_list COMMA IDENTIFIER ASSIGN_OP expression
					{
						if(DEBUG_CODE == 1)
							printf("variable_list 4 ");
					}
				;

expression:		assign_expression
				{
					if(DEBUG_CODE == 1)
						printf("expression 1 ");
				}

			|	op_or_expression
				{
					if(DEBUG_CODE == 1)
						printf("expression 2 ");
				}
            ;

assign_expression:		IDENTIFIER ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 1 ");
						}

					|	IDENTIFIER ADD_ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 2 ");
						}

					|	IDENTIFIER SUB_ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 3 ");
						}

					|	IDENTIFIER MUL_ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 4 ");
						}

					|	IDENTIFIER DIV_ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 5 ");
						}

					|	IDENTIFIER REM_ASSIGN_OP op_or_expression
						{
							if(DEBUG_CODE == 1)
								printf("assign_expression 6 ");
						}
                    ;

op_or_expression:   op_and_expression
                    {
                        if(DEBUG_CODE == 1)
							printf("op_or_expression 1 ");
                    }

                |	op_or_expression LOGICAL_OR_OP op_and_expression
                    {
                        if(DEBUG_CODE == 1)
							printf("op_or_expression 2 ");
                    }
                ;

op_and_expression:      op_rel_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_and_expression 1 ");
                        }

                    |	op_and_expression LOGICAL_AND_OP op_rel_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_and_expression 2 ");
                        }
                    ;

op_rel_expression:      op_condt_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 1 ");
                        }

                    |	op_rel_expression EQUAL_OP op_condt_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 2 ");
                        }
                    
                    |	op_rel_expression NOT_EQUAL_OP op_condt_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_rel_expression 3 ");
                        }
                    ;

op_condt_expression:    op_additive_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 1 ");
                        }

                    |	op_condt_expression LST op_additive_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 2 ");
                        }

                    |	op_condt_expression LSTE op_additive_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 3 ");
                        }

                    |	op_condt_expression MRT op_additive_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 4 ");
                        }

                    |	op_condt_expression MRTE op_additive_expression
                        {
                            if(DEBUG_CODE == 1)
								printf("op_condt_expression 5 ");
                        }
                    ;

op_additive_expression:     op_multiplicative_expression
                            {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 1 ");
                            }

                        |	op_additive_expression ADD_OP op_multiplicative_expression
                            {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 2 ");
                            }

                        |	op_additive_expression SUB_OP op_multiplicative_expression
                            {
                                if(DEBUG_CODE == 1)
									printf("op_additive_expression 3 ");
                            }
                        ;

op_multiplicative_expression:       op_neg_expression
                                    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 1 ");
                                    }

                                |	op_multiplicative_expression MUL_OP op_neg_expression
                                    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 2 ");
                                    }

                                |	op_multiplicative_expression DIV_OP op_neg_expression
                                    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 3 ");
                                    }
                                
                                |	op_multiplicative_expression REM_OP op_neg_expression
                                    {
                                        if(DEBUG_CODE == 1)
											printf("op_multiplicative_expression 4 ");
                                    }
                                ;

op_neg_expression:      factor
                        {
                            if(DEBUG_CODE == 1)
								printf("op_neg_expression 1 ");
                        }

                    |	EXCLAMATION_OP factor
                        {
                            if(DEBUG_CODE == 1)
								printf("op_neg_expression 2 ");
                        }
                    ;

conditional_statement:		simple_if
							{
								if(DEBUG_CODE == 1)
									printf("conditional_statement 1 ");
							}

						|	simple_if simple_else
							{
								if(DEBUG_CODE == 1)
									printf("conditional_statement 2 ");
							}

						|	simple_if ladder_elif
							{
								if(DEBUG_CODE == 1)
									printf("conditional_statement 3 ");
							}

						|	simple_if ladder_elif simple_else
							{
								if(DEBUG_CODE == 1)
									printf("conditional_statement 4 ");
							}
						;

simple_if:		IF LP op_or_expression RP block
				{
					if(DEBUG_CODE == 1)
						printf("simple_if ");
				}
			;

ladder_elif:	ELIF LP op_or_expression RP block
				{
					if(DEBUG_CODE == 1)
						printf("ladder_elif 1 ");
				}

			|	ELIF LP op_or_expression RP block ladder_elif
				{
					if(DEBUG_CODE == 1)
						printf("ladder_elif 2 ");
				}
			;

simple_else:	ELSE block
				{
					if(DEBUG_CODE == 1)
						printf("simple_else ");
				}
			;

loop_statement:		LOOP LP op_or_expression RP block
					{
						if(DEBUG_CODE == 1)
							printf("loop_statement ");
					}
				;

return_statement:	RETURN op_or_expression
					{
						if(DEBUG_CODE == 1)
							printf("return_statement ");
					}
				;

factor:		term
			{
				if(DEBUG_CODE == 1)
					printf("factor 1 ");
			}

		|	LP op_or_expression RP
			{
				if(DEBUG_CODE == 1)
					printf("factor 2 ");
			}
		;
term:		BOOLEAN_LIT
			{
				if(DEBUG_CODE == 1)
					printf("term 1 ");
			}

		|	FLOAT_LIT
			{
				if(DEBUG_CODE == 1)
					printf("term 2 ");
			}

		|	INT_LIT
			{
				if(DEBUG_CODE == 1)
					printf("term 3 ");
			}

		|	CHAR_LIT
			{
				if(DEBUG_CODE == 1)
					printf("term 4 ");
			}

		|	functional_call
			{
				if(DEBUG_CODE == 1)
					printf("term 5 ");
			}

		|	IDENTIFIER
			{
				if(DEBUG_CODE == 1)
					printf("term 6 ");
			}
        ;

functional_call:	IDENTIFIER LP RP
					{
						if(DEBUG_CODE == 1)
							printf("functional_call 1 ");
					}

				|	IDENTIFIER LP args RP
					{
						if(DEBUG_CODE == 1)
							printf("functional_call 2 ");
					}
                ;

args:		term
			{
				if(DEBUG_CODE == 1)
					printf("args 1 ");
			}

		|	args COMMA term
			{
				if(DEBUG_CODE == 1)
					printf("args 2 ");
			}
        ;

data_type:		INT
				{
					if(DEBUG_CODE == 1)
						printf("data_type 1 ");
				}

			|	FLOAT
				{
					if(DEBUG_CODE == 1)
						printf("data_type 2 ");
				}

			|	CHAR
				{
					if(DEBUG_CODE == 1)
						printf("data_type 3 ");
				}

			|	BOOLEAN
				{
					if(DEBUG_CODE == 1)
						printf("data_type 4 ");
				}
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