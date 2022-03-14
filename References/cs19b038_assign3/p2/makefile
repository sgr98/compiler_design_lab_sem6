parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: list.l
	flex list.l
y.tab.c: list.y
	bison -dy list.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
