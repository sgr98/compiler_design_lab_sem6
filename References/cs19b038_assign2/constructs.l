
/*All digits*/
digit [0-9]
/*All upper case, lower case letters including underscore*/
letter_ [A-Za-z_]
/*All the special characters except double and single quotes*/
special_characters [!#$%^&*\(\)\[\]=/*-:;,.<>?`~\|]

/* Delimiters */
delim {\t\n}
/* white space */
ws {delim+}

/* The operators would be clubbed together according to their category. */
/* The internal functions required could be returned using yytext and if statements in the action block.*/
/* Unary Opertors */
unary_operator ("++"|"--"|"!"|"~"|"(type)")
/* Arithmetic Operators */
arithmetic_operator ("*"|"/"|"%"|"+"|"-")
/* Shift Operators */
shift_operator ("<<"|">>")
/* Relational Operators */
relational_operator ("<"|"<="|">"|">="|"=="|"!=")
/* Bitwise Operators */
bitwise_operator ("&"|"^"|"|")
/* Logical Operators */
logical_operator ("&&"|"||")
/* Assignment Operators */
assignment_operator ("="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|">>="|"<<=")
/* Comma Operators */
comma_operator (",")

/* The keywords would be clubbed together according to their category. */
/* The internal functions required could be returned using yytext and if statements in the action block.*/
/* Data Types and related Keywords */
data_types_keywords ("char"|"const"|"double"|"enum"|"extern"|"float"|"int"|"long"|"register"|"short"|"signed"|"static"|"struct"|"union"|"unsigned"|"void")
other_keywords ("auto"|"break"|"case"|"continue"|"default"|"do"|"else"|"for"|"goto"|"if"|"return"|"switch"|"typedef"|"volatile"|"while"|"_Packed")

%{
    
%}

%%

"#include"                                          {printf("\nInclude Token %s", yytext);}
"<"(.)*">"                                          {printf("\nIncluded Library %s", yytext);}

'({digit}|{letter_}|{special_characters})'          {printf("\nCHARACTER_CONSTANT %s", yytext);}
\"({digit}|{letter_}|{special_characters})*\"       {printf("\nSTRING_CONSTANT %s", yytext);}
{digit}+\.{digit}+                                  {printf("\nFLOATING_POINT_CONSTANT %s", yytext);}
{digit}+                                            {printf("\nINTEGER_CONSTANT %s", yytext);}
("true"|"false")                                    {printf("\nBOOLEAN_CONSTANT %s", yytext);}

{letter_}({letter_}|{digit})*\(                     {printf("\nFunction %s", yytext);}

{comma_operator}                                    {printf("\nComma Operator %s", yytext);}
{assignment_operator}                               {printf("\nAssignment Operator %s", yytext);}
{logical_operator}                                  {printf("\nLogical Operator %s", yytext);}
{bitwise_operator}                                  {printf("\nBitwise Operator %s", yytext);}
{relational_operator}                               {printf("\nRelational Operator %s", yytext);}
{shift_operator}                                    {printf("\nShift Operator %s", yytext);}
{arithmetic_operator}                               {printf("\nArithmetic Operator %s", yytext);}
{unary_operator}                                    {printf("\nUnary Operator %s", yytext);}

{data_types_keywords}                                 {printf("\nData Type Keyword Token %s", yytext);}
{other_keywords}                                    {printf("\nKeyword Token %s", yytext);}
{letter_}({letter_}|{digit})*                       {printf("\nIdentifier Token %s", yytext);}

%%

int yywrap(){}  // This line is only required in Windows OS
int main(int argc, char *argv[]) {

    // If a file is inputted in the command line
    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }

    yylex();
    return 0;
}