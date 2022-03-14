parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: lex_myscanner.l
	flex lex_myscanner.l
y.tab.c: bison_myscanner.y
	bison -dy bison_myscanner.y
