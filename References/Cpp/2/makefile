run: parser.y lex.l
	flex lex.l
	bison -dy parser.y
	bison parser.y -o gm.cc
	gcc -c lex.yy.c -o lex.yy.o
	c++ lex.yy.o gm.cc -o parser

clean:
	rm y.tab.c y.tab.h lex.yy.c lex.yy.o gm.cc a.out
