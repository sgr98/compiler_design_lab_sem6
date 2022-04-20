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

program_start:  program
				{
					printf("program_start\n");
				}
            	;

program:	MAIN block
			{
				printf("program 1\n");
			}

        |	functions MAIN block
			{
				printf("program 2\n");
			}
        ;

functions:		function_declaration
				{
					printf("functions 1\n");
				}

			|	functions function_declaration
				{
					printf("functions 2\n");
				}
            ;

function_declaration:	VOID IDENTIFIER LP RP block
						{
							printf("function_declaration 1\n");
						}

					|	VOID IDENTIFIER LP params RP block
						{
							printf("function_declaration 2\n");
						}

					|	data_type IDENTIFIER LP RP block
						{
							printf("function_declaration 3\n");
						}

					|	data_type IDENTIFIER LP params RP block
						{
							printf("function_declaration 4\n");
						}
                    ;

params:		param
			{
				printf("params 2\n");
			}

		|	params COMMA param
			{
				printf("params 2\n");
			}
		;

param:		data_type IDENTIFIER
			{
				printf("param \n");
			}
    	;

block:		LC RC
			{
				printf("block 1\n");
			}

        |   LC statement_list RC
			{
				printf("block 2\n");
			}
        ;

statement_list:		statement
					{
						printf("statement_list 1\n");
					}

				|	statement_list statement
					{
						printf("statement_list 2\n");
					}
            	;

statement:		variable_declaration SEMICOLON
				{
					printf("statement 1\n");
				}

			|	expression SEMICOLON
				{
					printf("statement 2\n");
				}

			|	return_statement SEMICOLON
				{
					printf("statement 3\n");
				}

			|	SEMICOLON
				{
					printf("statement 4\n");
				}
            ;

variable_declaration:	data_type variable_list
						{
							printf("variable_declaration \n");
						}
                    ;

variable_list:		IDENTIFIER
					{
						printf("variable_list 1 ");
					}

				|	IDENTIFIER ASSIGN_OP expression
					{
						printf("variable_list 2 ");
					}

				|	variable_list COMMA IDENTIFIER
					{
						printf("variable_list 3 ");
					}

				|	variable_list COMMA IDENTIFIER ASSIGN_OP expression
					{
						printf("variable_list 4 ");
					}
				;

expression:		assign_expression
				{
					printf("expression 1 ");
				}

			|	op_or_expression
				{
					printf("expression 2 ");
				}
            ;

assign_expression:		IDENTIFIER ASSIGN_OP op_or_expression
						{
							printf("expression 1 ");
						}

					|	IDENTIFIER ADD_ASSIGN_OP op_or_expression
						{
							printf("expression 2 ");
						}

					|	IDENTIFIER SUB_ASSIGN_OP op_or_expression
						{
							printf("expression 3 ");
						}

					|	IDENTIFIER MUL_ASSIGN_OP op_or_expression
						{
							printf("expression 4 ");
						}

					|	IDENTIFIER DIV_ASSIGN_OP op_or_expression
						{
							printf("expression 5 ");
						}

					|	IDENTIFIER REM_ASSIGN_OP op_or_expression
						{
							printf("expression 6 ");
						}
                    ;

op_or_expression:   op_and_expression
                    {
                        printf("op_or_expression 1 ");
                    }

                |	op_or_expression LOGICAL_OR_OP op_and_expression
                    {
                        printf("op_or_expression 2 ");
                    }
                ;

op_and_expression:      op_rel_expression
                        {
                            printf("op_and_expression 1 ");
                        }

                    |	op_and_expression LOGICAL_AND_OP op_rel_expression
                        {
                            printf("op_and_expression 2 ");
                        }
                    ;

op_rel_expression:      op_condt_expression
                        {
                            printf("op_rel_expression 1 ");
                        }

                    |	op_rel_expression EQUAL_OP op_condt_expression
                        {
                            printf("op_rel_expression 2 ");
                        }
                    
                    |	op_rel_expression NOT_EQUAL_OP op_condt_expression
                        {
                            printf("op_rel_expression 3 ");
                        }
                    ;

op_condt_expression:    op_additive_expression
                        {
                            printf("op_condt_expression 1 ");
                        }

                    |	op_condt_expression LST op_additive_expression
                        {
                            printf("op_condt_expression 2 ");
                        }

                    |	op_condt_expression LSTE op_additive_expression
                        {
                            printf("op_condt_expression 3 ");
                        }

                    |	op_condt_expression MRT op_additive_expression
                        {
                            printf("op_condt_expression 4 ");
                        }

                    |	op_condt_expression MRTE op_additive_expression
                        {
                            printf("op_condt_expression 5 ");
                        }
                    ;

op_additive_expression:     op_multiplicative_expression
                            {
                                printf("op_additive_expression 1 ");
                            }

                        |	op_additive_expression ADD_OP op_multiplicative_expression
                            {
                                printf("op_additive_expression 2 ");
                            }

                        |	op_additive_expression SUB_OP op_multiplicative_expression
                            {
                                printf("op_additive_expression 3 ");
                            }
                        ;

op_multiplicative_expression:       op_neg_expression
                                    {
                                        printf("op_multiplicative_expression 1 ");
                                    }

                                |	op_multiplicative_expression MUL_OP op_neg_expression
                                    {
                                        printf("op_multiplicative_expression 2 ");
                                    }

                                |	op_multiplicative_expression DIV_OP op_neg_expression
                                    {
                                        printf("op_multiplicative_expression 3 ");
                                    }
                                
                                |	op_multiplicative_expression REM_OP op_neg_expression
                                    {
                                        printf("op_multiplicative_expression 4 ");
                                    }
                                ;

op_neg_expression:      factor
                        {
                            printf("op_neg_expression 1 ");
                        }

                    |	EXCLAMATION_OP factor
                        {
                            printf("op_neg_expression 2 ");
                        }
                    ;

return_statement:	RETURN op_or_expression
					{
						printf("return_statement ");
					}
				;

factor:		term
			{
				printf("factor 1 ");
			}

		|	LP op_or_expression RP
			{
				printf("factor 2 ");
			}
		;
term:		BOOLEAN_LIT
			{
				printf("term 1 ");
			}

		|	FLOAT_LIT
			{
				printf("term 2 ");
			}

		|	INT_LIT
			{
				printf("term 3 ");
			}

		|	CHAR_LIT
			{
				printf("term 4 ");
			}

		|	functional_call
			{
				printf("term 5 ");
			}

		|	IDENTIFIER
			{
				printf("term 6 ");
			}
        ;

functional_call:	IDENTIFIER LP RP
					{
						printf("functional_call 1 ");
					}

				|	IDENTIFIER LP args RP
					{
						printf("functional_call 2 ");
					}
                ;

args:		term
			{
				printf("args 1 ");
			}

		|	args COMMA term
			{
				printf("args 2 ");
			}
        ;

data_type:		INT
				{
					printf("data_type 1 ");
				}

			|	FLOAT
				{
					printf("data_type 2 ");
				}

			|	CHAR
				{
					printf("data_type 3 ");
				}

			|	BOOLEAN
				{
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