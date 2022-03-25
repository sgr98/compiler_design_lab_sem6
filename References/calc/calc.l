%{
#include "y.tab.h"
#include<string.h>
void yyerror (char *s);
int yylex();
%}
%%
"print"				   {return print;}
"exit"				   {return exit_command;}
[a-zA-Z]			   {yylval.str = strdup(yytext); return identifier;}
[0-9]+                 {yylval.str = strdup(yytext); return number;}
[ \t\n]                ;
[-+=;]           	   {return yytext[0];}
.                      {ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) {return 1;}