parser: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o parser
lex.yy.c: complex_number.l
	flex complex_number.l
y.tab.c: complex_number.y
	bison -dy complex_number.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
