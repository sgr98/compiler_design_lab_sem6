%{
void yyerror (char *s);
int yylex();
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {char *str; int num;}         /* Yacc definitions */
%start line
%token print
%token exit_command
%token <str> number
%token <str> identifier
%type <str> line term
%type <str> exp
%type <str> assignment

%%

line    : assignment ';'		{;}
		| exit_command ';'		{exit(EXIT_SUCCESS);}
		| print exp ';'			{printf("Printing %s\n", $2);}
		| line assignment ';'	{;}
		| line print exp ';'	{printf("0 %s\n", $3);}
		| line exit_command ';'	{exit(EXIT_SUCCESS);}
        ;

assignment  : identifier '=' exp  {printf("1 %s |||| %s\n", $1, $3);}
		    ;
exp    	: term                  {$$ = $1; printf("2 %s\n", $1);}
       	| exp '+' term          {$$ = $1; printf("3 %s |||| %s\n", $1, $3);}
       	| exp '-' term          {$$ = $1; printf("4 %s\n", $1);}
       	;
term   	: number                {$$ = $1; printf("5 %s\n", $1);}
		| identifier			{$$ = $1; printf("6 %s\n", $1);} 
        ;

%%                     /* C code */

int main (void) {
	/* init symbol table */

	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);}