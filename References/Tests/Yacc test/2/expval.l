%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
extern int yylval;
%}

digit [0-9]

%%
{digit}+    { 
                yylval=atoi(yytext);
                return NUMBER;
            }


[ \t] ;
[\n] return 0;
. return yytext[0];
%%

// "+"      							return ADD;
// "-"      							return SUB;
// ";"									return SCOL;

int yywrap(){}  // This line is only required in Windows OS
