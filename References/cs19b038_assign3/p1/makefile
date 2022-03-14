parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: apple.l
	flex apple.l
y.tab.c: apple.y
	bison -dy apple.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
