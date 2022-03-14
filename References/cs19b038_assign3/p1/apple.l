%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
"a"             return A_VAL;
"d"             return D_VAL;
";"			    return SCOL;

[ \t] ;
.               return yytext[0];
%%

int yywrap(){}  // This line is only required in Windows OS