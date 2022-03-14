parser: myscanner.c lex.yy.c lex_myscanner.h
	gcc myscanner.c lex.yy.c -o parser
lex.yy.c: lex_myscanner.l
	flex lex_myscanner.l
