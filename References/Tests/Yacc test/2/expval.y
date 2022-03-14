%{
    #include<stdio.h>
    int flag=0;
    // extern FILE *yyin;
%}

%token NUMBER

%left '+' '-'

%%
ArithmeticExpression: E{
         printf("\nResult = %d\n",$$);
         return 0;
        }
E   :   E'+'E     { $$ = $1 + $3; }
    |   E'-'E     { $$ = $1 - $3; }
    |   NUMBER    { $$ = $1; }
;
%%

int main(int argc, char *argv[]) {
  // FILE *fp; int i;
  // fp=fopen("sample.txt","r");
  // yyin=fp;
 
  // for(i=0;i<5;i++)
  //   yyparse();

  // if(flag==0)
  //   printf("\nEntered arithmetic expression is Valid\n\n");
  yyparse();
  return 0;
}
int yyerror() {
  printf("\nEntered arithmetic expression is Invalid\n\n");
  flag=1;
}





























// %{
//     #include<stdio.h>
//     int flag=0;
//     extern FILE *yyin;
 
// %}

// // %union {
// // 	int numval;
// // }

// %token NUMBER SCOL
// %left ADD
// %left SUB

// %%

// ArithmeticExpression: E {
//           printf("\nResult=%d\n",$1);
//           return 0;
//         }
// E : E'+'E {$$=$1+$3;}
//   | E'-'E {$$=$1-$3;}
//   | NUMBER {$$=$1;}
// ;

// %%

// // statement	: statement EXPR SCOL   { printf("\n\nResult = %d\n\n", $$); };

// // statement : ;

// // EXPR 			: EXPR ADD VAL        {$$ = $1 + $3;};

// // EXPR 			: EXPR SUB VAL        {$$ = $1 - $3;};

// // EXPR 			: VAL                 {$$ = $1;};

// // VAL 			: NUMBER              {$$ = $1;};



// // int main(int argc, char *argv[]) {

// //     // If a file is inputted in the command line
// //     if(argc > 1) {
// //         FILE *fp = fopen(argv[1], "r");
// //         if(fp)
// //             yyin = fp;
// //     }

// //     yyparse();
// //     return 0;
// // }

// void main() {
//   FILE *fp; int i;
//   fp=fopen("sample.txt","r");
//   yyin=fp;
 
//   for(i=0;i<5;i++)
//     yyparse();

//   if(flag==0)
//     printf("\nEntered arithmetic expression is Valid\n\n");

// }

// void yyerror() {
//   printf("\nEntered arithmetic expression is Invalid\n\n");
//   flag=1;
// }
