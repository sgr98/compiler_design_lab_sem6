parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: sample.l
	flex sample.l
y.tab.c: sample.y
	bison -dy sample.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
