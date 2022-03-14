parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: expval.l
	flex expval.l
y.tab.c: expval.y
	bison -dy expval.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
