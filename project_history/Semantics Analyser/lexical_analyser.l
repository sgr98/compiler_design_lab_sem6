%{
    #include "y.tab.h"
    #include <string.h>
    void yyerror (char *s);
    int yylex();
%}

boolean_literal     ("true"|"false")
float_literal       ([0-9]+\.[0-9]+|\-[0-9]+\.[0-9]+)
int_literal         ([0-9]+|\-[0-9]+)
character_literal   \'(.|\\"n"|\\"t"|\\\'|\\"0")\'
identifier          [a-zA-Z][a-zA-Z_0-9]*

%%

";"                     {return SEMICOLON;}
","                     {return COMMA;}
"("                     {return LP;}
")"                     {return RP;}
"{"                     {return LC;}
"}"                     {return RC;}

"+="                    {return ADD_ASSIGN_OP;}
"-="                    {return SUB_ASSIGN_OP;}
"*="                    {return MUL_ASSIGN_OP;}
"/="                    {return DIV_ASSIGN_OP;}
"%="                    {return REM_ASSIGN_OP;}

"=="                    {return EQUAL_OP;}
"!="                    {return NOT_EQUAL_OP;}
">="                    {return MRTE;}
"<="                    {return LSTE;}
">"                     {return MRT;}
"<"                     {return LST;}

"&&"                    {return LOGICAL_AND_OP;}
"||"                    {return LOGICAL_OR_OP;}
"!"                     {return EXCLAMATION_OP;}

"="                     {return ASSIGN_OP;}
"+"                     {return ADD_OP;}
"-"                     {return SUB_OP;}
"*"                     {return MUL_OP;}
"/"                     {return DIV_OP;}
"%"                     {return REM_OP;}

"main"                  {return MAIN;}
"void"                  {return VOID;}
"return"                {return RETURN;}

"if"                    {return IF;}
"elif"                  {return ELIF;}
"else"                  {return ELSE;}
"loop"                  {return LOOP;}
"break"                 {return BREAK;}
"continue"              {return CONTINUE;}

"int"                   {return INT;}
"float"                 {return FLOAT;}
"char"                  {return CHAR;}
"boolean"               {return BOOLEAN;}

"input()"               {return INPUT;}
"output()"              {return OUTPUT;}

{boolean_literal}       {yylval.str = strdup(yytext); return BOOLEAN_LIT;}
{float_literal}         {yylval.str = strdup(yytext); return FLOAT_LIT;}
{int_literal}           {yylval.str = strdup(yytext); return INT_LIT;}
{character_literal}     {yylval.str = strdup(yytext); return CHAR_LIT;}

{identifier}            {yylval.str = strdup(yytext); return IDENTIFIER;}

[ \t\n]                 ;
.                       {printf("unexpected character ");}

%%
// int yywrap (void) {return 1;}