%{
#include "y.tab.h"
void yyerror (char *s);
int yylex();
%}
%%
"main"                  {return MAIN;}
"void"                  {return VOID;}
"int"                   {return INT;}
"float"                 {return FLOAT;}
"char"                  {return CHAR;}
"boolean"				{return BOOLEAN;}
[a-zA-Z][a-zA-z_0-9]*	{return IDENTIFIER;}
[ \t\n]                 ;

[\(\)\[\]\{\}]          ;
.                       {ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) {return 1;}