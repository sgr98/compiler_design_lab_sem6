parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: lexical_analyser.l
	flex lexical_analyser.l
y.tab.c: syntax_analyser.y
	bison -dy syntax_analyser.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
