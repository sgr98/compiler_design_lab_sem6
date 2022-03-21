%{
    #include <stdio.h>
    #include <stdlib.h>
%}

boolean_literal     ("true"|"false")
float_literal       [0-9]+\.[0-9]+
int_literal         [0-9]+
character_literal   \'(.|\\"n"|\\"t"|\\\')\'
identifier          [a-zA-Z][a-zA-Z_0-9]*

%%

";"                     {printf("SEMICOLON\n");}
","                     {printf("COMMA ");}
"("                     {printf("LP ");}
")"                     {printf("RP ");}
"{"                     {printf("LC ");}
"}"                     {printf("RC ");}

"+="                    {printf("ADD_ASSIGN_OP ");}
"-="                    {printf("SUB_ASSIGN_OP ");}
"*="                    {printf("MUL_ASSIGN_OP ");}
"/="                    {printf("DIV_ASSIGN_OP ");}
"%="                    {printf("REM_ASSIGN_OP ");}

"=="                    {printf("EQUAL_OP ");}
"!="                    {printf("NOT_EQUALOP ");}
">="                    {printf("MRTE ");}
"<="                    {printf("LSTE ");}
">"                     {printf("MRT ");}
"<"                     {printf("LST ");}

"&&"                    {printf("LOGICAL_AND_OP ");}
"||"                    {printf("LOGICAL_OR_OP ");}
"!"                     {printf("EXCLAMATION_OP ");}

"="                     {printf("ASSIGN_OP ");}
"+"                     {printf("ADD_OP ");}
"-"                     {printf("SUB_OP ");}
"*"                     {printf("MUL_OP ");}
"/"                     {printf("DIV_OP ");}
"%"                     {printf("REM_OP ");}

"main"                  {printf("MAIN ");}
"void"                  {printf("VOID ");}
"return"                {printf("RETURN ");}
"int"                   {printf("INT ");}
"float"                 {printf("FLOAT ");}
"char"                  {printf("CHAR ");}
"boolean"               {printf("BOOLEAN ");}

{boolean_literal}       {printf("BOOLEAN_LIT ");}
{float_literal}         {printf("FLOAT_LIT ");}
{int_literal}           {printf("INT_LIT ");}
{character_literal}     {printf("CHAR_LIT ");}

{identifier}            {printf("IDENTIFIER ");}

[ \t\n]+                ;
.                       {printf("unexpected character ");}

%%

int yywrap (void) { return 1; }

// To run using file: ./parser <file_path>
// e.g) ./parser ./../../example_programs/our_language/arithmetic.xgvs

int main(int argc, char *argv[]) {

    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }

    yylex();

    return 0;
}