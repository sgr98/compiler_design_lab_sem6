t: y.tab.c lex.yy.c y.tab.h
	gcc y.tab.c lex.yy.c -o t
lex.yy.c: t.l
	flex t.l
y.tab.c: t.y
	bison -dy t.y
