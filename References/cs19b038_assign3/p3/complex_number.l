%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}

digit [0-9]

%%
{digit}+            { 
                        yylval.num=atoi(yytext);
                        return NUMBER;
                    }
"i"                 return IOTA;
";"                 return SCOL;

[ \t\n]             ;
.                   return yytext[0];
%%

int yywrap(){}  // This line is only required in Windows OS