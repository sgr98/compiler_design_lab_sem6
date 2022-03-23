%{
#include "y.tab.h"
void yyerror (char *s);
int yylex();
%}

boolean_literal     ("true"|"false")
float_literal       [0-9]+\.[0-9]+
int_literal         [0-9]+
character_literal   \'(.|\\"n"|\\"t"|\\\')\'
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

"int"                   {return INT;}
"float"                 {return FLOAT;}
"char"                  {return CHAR;}
"boolean"               {return BOOLEAN;}

{boolean_literal}       {return BOOLEAN_LIT;}
{float_literal}         {return FLOAT_LIT;}
{int_literal}           {return INT_LIT;}
{character_literal}     {return CHAR_LIT;}

{identifier}            {return IDENTIFIER;}

[ \t\n]                 ;
.                       {printf("unexpected character ");}

%%
int yywrap (void) {return 1;}