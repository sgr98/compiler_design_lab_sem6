parser: lex.yy.c
	gcc lex.yy.c -o parser
lex.yy.c: lexical_analyser.l
	flex lexical_analyser.l
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
