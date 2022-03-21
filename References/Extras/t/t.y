%{
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
%}

%start program_start
%token MAIN VOID IDENTIFIER INT FLOAT CHAR BOOLEAN

%%

program_start   :  program  {printf("program_start\n");}
                ;

program :	functions MAIN block    {printf("program 1\n");}
        |	MAIN block  {printf("program 2\n");}
        ;

functions 	:	function_declaration    {printf("functions 1\n");}
		    |	functions function_declaration  {printf("functions 2\n");}
            ;

function_declaration	:	VOID IDENTIFIER "(" params ")" block    {printf("function_declaration 1\n");}
			            |	data_type IDENTIFIER "(" params ")" block    {printf("function_declaration 2\n");}
                        ;

params	:	param                   {printf("params 1\n");}
		|	params "," param        {printf("params 2\n");}
		|	                        {printf("params 3\n");}
        ;

param	:	data_type IDENTIFIER    {printf("param\n");}
        ;

block	:	"{" statements "}"      {printf("block\n");}
        ;

statements  :                       {printf("statements\n");}
            ;

data_type	:	INT                 {printf("int\n");}
		    |	FLOAT               {printf("float\n");}
		    |	CHAR                {printf("char\n");}
		    |	BOOLEAN             {printf("boolean\n");}
            ;
%%

int main (void) {
	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 