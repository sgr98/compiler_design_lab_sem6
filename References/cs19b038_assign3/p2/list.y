%{
    #include<stdio.h>
    int flag=0;
    int yylex();
    int yyerror();
    extern FILE *yyin;
%}

%token E_VAL LP RP COMMA SCOL

%%
S   :   A SCOL 
    |   S A SCOL
    ;
A   :   LP B RP             { printf("yes"); };    
B   :   LP B RP C
    |   E_VAL C
    ;
C   :   COMMA E_VAL C
    |   COMMA LP B RP
    |
    ;
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

int yyerror(){
  printf("no\n");
}