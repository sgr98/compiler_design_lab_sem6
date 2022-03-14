%{
    #include<stdio.h>
    int flag=0;
    extern FILE *yyin;

    int yylex();
    int yyerror();
    struct ComplexNumber {
      int real;
      int comp;
    };
%}

%union {
  int num;
  struct ComplexNumber *complex_number;
}

%token NUMBER IOTA SCOL
%type <num> NUMBER
%type <num> C
%type <complex_number> B
%type <complex_number> A
// %type <complex_number> S

%%
S   :   A               {   
                            if($1->comp >= 0)
                              printf("Sum = %d + %di\n", $1->real, $1->comp);
                            else
                              printf("Sum = %d - %di\n", $1->real, -1 * $1->comp);
                        }
    ;

A   :   A B SCOL        {
                            $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                            $$->real = $1->real + $2->real; 
                            $$->comp = $1->comp + $2->comp;
                        }
    |   B SCOL          {
                            $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                            $$->real = $1->real; 
                            $$->comp = $1->comp;
                        }
    ; 

B   :   C'+'C IOTA     { 
                          $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                          $$->real = $1;
                          $$->comp = $3;
                        }
    |   C'-'C IOTA        { 
                          $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                          $$->real = $1;
                          $$->comp = -1 * $3;
                        }
    |   '-'C'+'C IOTA   { 
                          $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                          $$->real = -1 * $2;
                          $$->comp = $4;
                        }
    |   '-'C'-'C IOTA   { 
                          $$ = (struct ComplexNumber *) malloc(sizeof(struct ComplexNumber));
                          $$->real = -1 * $2;
                          $$->comp = -1 * $4;
                        }
    ;
C   :    NUMBER         { $$ = $1; };
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