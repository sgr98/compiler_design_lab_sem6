calc: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o calc
lex.yy.c: calc.l
	flex calc.l
y.tab.c: calc.y
	bison -dy calc.y