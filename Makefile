FILE := $(word 2, $(MAKECMDGOALS))

all: flex-routine bison-routine

flex:
	win_flex -o lex.yy.cpp lexfile.lex

flex-compile:
	gcc lex.yy.cpp lexer.cpp -o lexer -g

flex-run:
	lexer.exe < $(FILE)

bison:
	win_bison -o y.tab.cpp  yaccfile.yacc -v

bison-compile:
	gcc y.tab.cpp lex.yy.cpp main.cpp -o parser

bison-run:
	parser.exe < $(FILE)

bison-routine: bison bison-compile bison-run

flex-routine: flex flex-compile flex-run