all: flex-routine bison-routine

flex:
	win_flex -o lex.yy.c lexfile.lex

flex-compile:
	gcc lex.yy.c lexer.c -o lexer -g

flex-run:
	lexer.exe < $(FILE)

bison:
	win_bison -o y.tab.c  yaccfile.yacc

bison-compile:
	gcc y.tab.c lex.yy.c main.c -o parser

bison-run:
	parser.exe < $(FILE)

bison-routine: bison bison-compile bison-run

flex-routine: flex flex-compile flex-run