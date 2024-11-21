flex:
	flex -o lex.yy.c lexfile.lex

flex-compile:
	gcc lex.yy.c lexer.c -o lexer -g

flex-run:
	./lexer < $(FILE)

bison:
	bison -o y.tab.c  yaccfile.yacc

bison-compile:
	gcc y.tab.c lex.yy.c main.c -o parser -lfl

bison-run:
	./parser < $(FILE)

bison-routine: bison bison-compile bison-run

flex-routine: flex flex-compile flex-run