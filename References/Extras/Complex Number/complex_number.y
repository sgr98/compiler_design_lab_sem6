%{
    #include<stdio.h>
    int flag=0;
    extern FILE *yyin;

    int yylex();
    int yyerror();
%}

%union {
  int num;
  struct ComplexNumber {
      int real;
      int img;
  } comp_num;
}
%start S
%token IOTA SCOL
%token <num> NUMBER
%type <num> C
%type <comp_num> B
%type <comp_num> A
// %type <comp_num> S

%%
S   :   A                   {   
                                if($1.img >= 0)
                                  printf("Sum = %d + %di\n", $1.real, $1.img);
                                else
                                  printf("Sum = %d - %di\n", $1.real, -1 * $1.img);
                            }
    ;

A   :   A B SCOL            {
                                $$.real = $1.real + $2.real; 
                                $$.img = $1.img + $2.img;
                            }
    |   B SCOL              {
                                $$.real = $1.real; 
                                $$.img = $1.img;
                            }
    ; 

B   :   C '+' C IOTA        { 
                              $$.real = $1;
                              $$.img = $3;
                            }
    |   C '-' C IOTA        {
                              $$.real = $1;
                              $$.img = -1 * $3;
                            }
    |   '-' C '+' C IOTA    { 
                              $$.real = -1 * $2;
                              $$.img = $4;
                            }
    |   '-' C '-' C IOTA    { 
                              $$.real = -1 * $2;
                              $$.img = -1 * $4;
                            }
    ;
C   :    NUMBER             { $$ = $1; };
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
  printf("Error in one of the inputs.\n");
  return 0;
}