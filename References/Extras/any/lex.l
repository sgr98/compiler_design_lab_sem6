special_character   [!@#$%^&*\(\)\{\}\[\]\'\":;<>?,./`~+-/*=]

%{
    
%}

%%
:                                           printf("COLON\n");
\'.\'                                       printf("Character literal: %c\n", yytext[1]);
{special_character}                         printf("Special Character\n");

[a-zA-Z][_a-zA-Z0-9]*                       printf("IDENTIFIER\n");
[1-9][0-9]*                                 printf("INTEGER\n");
[ \t\n]                                     ;
.                                           printf("unexpected character\n");
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