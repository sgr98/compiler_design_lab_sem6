lexer: lex.yy.c
	gcc lex.yy.c -o lexer

lex.yy.c: constructs.l
	flex constructs.l

clean:
	rm lex.yy.c
	rm lexer