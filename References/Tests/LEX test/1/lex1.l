

digit [0-9]
letter_ [A-Za-z_]

%%

"if"                                {printf("\nKeyword %s", yytext);}

{digit}+                            {printf("\nNumber Token %s", yytext);}

{letter_}({letter_}|{digit})*       {printf("\nIdentifier Token %s", yytext);}

%%

int yywrap(){}
int main(int argc, char *argv[]) {

    if(argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }
    yylex();
    return 0;
}