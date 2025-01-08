FILE := $(word 2, $(MAKECMDGOALS))

all: flex-routine bison-routine

flex:
	win_flex -o lex.yy.cpp lexfile.lex

flex-compile:
	g++ lex.yy.cpp lexer.cpp -o lexer -g

flex-run:
	lexer.exe < $(FILE)

bison:
	win_bison -o y.tab.cpp -d yaccfile.yacc -v

bison-compile:
	g++ y.tab.cpp lex.yy.cpp main.cpp absyn.cpp -o parser

bison-run:
	parser.exe < $(FILE)

bison-routine: bison bison-compile bison-run

flex-routine: flex flex-compile flex-run

build: flex bison
	g++ y.tab.cpp lex.yy.cpp main.cpp absyn.cpp -o typechecker