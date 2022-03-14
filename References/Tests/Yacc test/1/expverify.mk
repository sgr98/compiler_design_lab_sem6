parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: expverify.l
	flex expverify.l
y.tab.c: expverify.y
	bison -dy expverify.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
