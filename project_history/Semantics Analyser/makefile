parser: semantic_analyser.y lexical_analyser.l
	flex lexical_analyser.l
	bison -dy semantic_analyser.y
	bison semantic_analyser.y -o gm.cc
	gcc -c lex.yy.c -o lex.yy.o
	c++ lex.yy.o gm.cc -o parser

clean:
	rm y.tab.c y.tab.h lex.yy.c lex.yy.o gm.cc parser.exe