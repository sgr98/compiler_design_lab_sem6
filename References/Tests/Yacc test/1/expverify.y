%{
#include<stdio.h>
int yylex();
int yyerror(char *);
extern FILE *yyin;
%}

%token NUMBER ADD SUB MUL DIV	ID ASGN 	LP RP SCOL
%%

statement_list: statement SCOL 
					 | statement_list statement SCOL 
					 ;

statement	: 	ID ASGN EXPR {printf("\n\nAccepted\n\n");};
EXPR 			: 	EXPR ADD TERM | EXPR SUB TERM | TERM ;
TERM 			:	TERM MUL FACT | TERM DIV FACT | FACT ;
FACT 			: 	LP EXPR RP  | ID | NUMBER ;

%%

int main(int argc, char *argv[]) {

    // If a file is inputted in the command line
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }

    yyparse();
    return 0;
}

int yyerror(char *s){
  printf("\n\nError: %s\n", s);
}
