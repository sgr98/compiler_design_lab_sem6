%{
    #include<stdio.h>
    int yylex();
    int yyerror();
    extern FILE *yyin;
    int count = 0;
%}

%token A_VAL D_VAL SCOL

%%
S   :   A SCOL 
    |   S A SCOL
    ;
A   :   B                   {   
                                if(count < 0)
                                    printf("no");
                                else
                                    printf("yes");
                                count = 0;
                            }
B   :   A_VAL B             { count++; }
    |   D_VAL B             { count--; }
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
  printf("Error\n");
}