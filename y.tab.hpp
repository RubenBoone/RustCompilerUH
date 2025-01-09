/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FN = 258,
     LPAREN = 259,
     RPAREN = 260,
     ARROW = 261,
     LBRACE = 262,
     RBRACE = 263,
     SEMICOLON = 264,
     COLON = 265,
     LET = 266,
     ANDAND = 267,
     OROR = 268,
     NOT = 269,
     GT = 270,
     GE = 271,
     LT = 272,
     LE = 273,
     EQEQ = 274,
     NE = 275,
     AMPERSAND = 276,
     IF = 277,
     ELSE = 278,
     WHILE = 279,
     MUT = 280,
     COMMA = 281,
     INT = 282,
     BOOL = 283,
     MINUS = 284,
     PLUS = 285,
     SLASH = 286,
     STAR = 287,
     IDENTIFIER = 288,
     PRINTSTRING = 289,
     PRINTVAR = 290,
     DEC_LITERAL = 291,
     PLUSEQ = 292,
     MINUSEQ = 293,
     EQ = 294,
     TRUE = 295,
     FALSE = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 23 "yaccfile.yacc"

    char* id;
    int num;
    bool boolean;

    Exp exp;
    Stm stm;
    ExpList explist;
    Func func;
    FuncList funclist;

    Program *program;

    DataType dtype;
    Binop binop;
    AssignOp assignop;
    ConditionalOp condop;

    LetStm *letstm;
    AssignStm *assignstm;
    BlockStm *blockstm;
    DeclarationStm *decstm;
    IfStm *ifstm;
    IfElseStm *ifelsestm;
    PrintStm *printstm;
    VarPrintStm *varprintstm;
    ExprStm *exprstm;
    WhileStm *whilestm;

    IdExp *idexp;
    BoolExp *boolexp;
    NumExp *numexp;
    BinopExp *binopexp;
    BlockExp *blockexp;
    GroupedExp *groupexp;
    FunctionExp *funcexp;
    IfElseExp *ifelseexp;

    PairArgsExpList *arglist;
    LastArgsExpList *lastarglist;
    PairParamExpList *parmlist;
    LastParamExpList *lastparmlist;
    LastFuncList *lastfunclist;
    PairFuncList *pairfunclist;

    NotCondExp *notcondexp;
    CompareCondExp *compcondexp;
    AndCond *andcond;
    OrCond *orcond;

    CompoundStm *compoundstm;
    FuncDefStm *funcdefstm;
    FuncDefExp *funcdefexp;


/* Line 2058 of yacc.c  */
#line 154 "y.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
