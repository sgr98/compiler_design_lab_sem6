%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
"e"             return E_VAL;
"("             return LP;
")"             return RP;
","             return COMMA;
";"			    return SCOL;

[ \t] ;
.               return yytext[0];
%%

int yywrap(){}  // This line is only required in Windows OS