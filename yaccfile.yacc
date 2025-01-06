%{
#include "absyn.hpp"
#include "lexer.h"
#include <iostream>

extern int line_nr;
extern int col_nr;
void yyerror(const char* str);

Stm tree;
%}

// tokendeclaraties
%token  FN LPAREN RPAREN ARROW LBRACE RBRACE SEMICOLON COLON LET ANDAND OROR NOT GT GE LT LE EQEQ NE AMPERSAND IF ELSE WHILE MUT COMMA INT BOOL
  
// voorrangdeclaraties
%left PLUS MINUS
%left STAR SLASH
%left PLUSEQ MINUSEQ EQ
%left GT GE LT LE EQEQ
%left ANDAND OROR 
%left SEMICOLON NOT

%union {
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
    IfExp *ifexp;

    PairArgsExpList *arglist;
    LastArgsExpList *lastarglist;
    PairParamExpList *parmlist;
    LastParamExpList *lastparmlist;
    LastFuncList *lastfunclist;
    PairFuncList *pairfunclist;

    ConditionalExp *condexp;
    NotCondExp *notcondexp;
    CompareCondExp *compcondexp;
    AndCond *andcond;
    OrCond *orcond;
    EqualCond *eqcond;

    CompoundStm *compoundstm;
    FuncDefStm *funcdefstm;
    FuncDefExp *funcdefexp;
}

%token <id> IDENTIFIER PRINTSTRING
%token <num> DEC_LITERAL
%token <binop> PLUS MINUS STAR SLASH
%token <assignop> PLUSEQ MINUSEQ EQ
%token <exp> PRINTVAR
%token <bool> TRUE FALSE

%type <boolean> mutability

%type <dtype> type
%type <assignop> assignment_operator
%type <condop> conditional_operator

%type <exp> ExpType CondType
%type <idexp> IdExpType
%type <boolexp> BoolExpType
%type <numexp> NumExpType
%type <binopexp> BinopExpType
%type <blockexp> BlockExpType
%type <groupexp> GroupExpType
%type <funcexp> FunctionExpType
%type <ifexp> IfExpType

%type <notcondexp> NotCondType

%type <stm> StmType
%type <letstm> LetStmType
%type <assignstm> AssignStmType
%type <blockstm> BlockStmType
%type <decstm> DecStmType
%type <ifstm> IfStmType
%type <printstm> PrintStmType
%type <varprintstm> VarPrintStmType
%type <whilestm> WhileStmStype

%type <compoundstm> CompoundStmType

%type <funclist> function_list
%type <func> FunctionType
%type <explist> argument_list parameter_list

%type <program> ProgramType

%start ProgramType

%%

ProgramType : function_list {$$ = new Program($1); tree = $$;}
        ;



CompoundStmType : /* Empty */ { $$ = nullptr;}
                | CompoundStmType StmType {$$ = new CompoundStm($1, $2);}
                ;

StmType : LetStmType SEMICOLON {$$ = $1;}
        | AssignStmType SEMICOLON {$$ = $1;}
        | BlockStmType {$$ = $1;}
        | DecStmType SEMICOLON {$$ = $1;}
        | IfStmType {$$ = $1;}
        | PrintStmType SEMICOLON {$$ = $1;}
        | VarPrintStmType SEMICOLON {$$ = $1;}
        | ExpType SEMICOLON {$$ = new ExprStm($1);}
        | WhileStmStype { $$ = $1;}
        ;

LetStmType : LET mutability IDENTIFIER COLON type EQ ExpType  {$$ = new LetStm($3, $7, $5, $2);}
           | LET mutability IDENTIFIER EQ ExpType {$$ = new LetStm($3, $5, $2);}
           ;

AssignStmType : IDENTIFIER assignment_operator ExpType {$$ = new AssignStm($1, $2, $3);}
              ;

BlockStmType : LBRACE CompoundStmType RBRACE {$$ = new BlockStm($2);}
             ;

DecStmType : LET mutability IDENTIFIER COLON type {$$ = new DeclarationStm($3, $5, $2);}
           ;

IfStmType : IF CondType BlockStmType {$$ = new IfStm($2, $3);}
          | IF CondType BlockStmType ELSE BlockStmType {$$ = new IfStm($2, $3, $5);}
          ;

PrintStmType : PRINTSTRING { $$ = new PrintStm($1);}
             ;

VarPrintStmType : PRINTVAR { $$ = new VarPrintStm($1);}
                ;

WhileStmStype : WHILE CondType BlockStmType { $$ = new WhileStm($2, $3);}
              ;




ExpType : NumExpType {$$ = $1;}
        | BoolExpType {$$ = $1;}
        | IdExpType {$$ = $1;}
        | BinopExpType { $$ = $1;}
        | BlockExpType { $$ = $1;}
        | GroupExpType { $$ = $1;}
        | FunctionExpType { $$ = $1;}
        | IfExpType { $$ = $1;}
        | NotCondType {$$ = $1;}
        ;

IdExpType : IDENTIFIER {$$ = new IdExp($1);}
          ;

BoolExpType : TRUE { $$ = new BoolExp(true);}
            | FALSE { $$ = new BoolExp(false);}
            ;

NumExpType : DEC_LITERAL {$$ = new NumExp($1);}
           ;

BinopExpType : ExpType PLUS ExpType {$$ = new BinopExp($1, Plus, $3);}
             | ExpType MINUS ExpType {$$ = new BinopExp($1, Minus, $3);}
             | ExpType STAR ExpType {$$ = new BinopExp($1, Times, $3);}
             | ExpType SLASH ExpType {$$ = new BinopExp($1, Divide, $3);}
             ;

BlockExpType : LBRACE CompoundStmType ExpType RBRACE {$$ = new BlockExp($2, $3);}
             ;

GroupExpType : LPAREN ExpType RPAREN { $$ = new GroupedExp($2);}
             ;

FunctionExpType : IDENTIFIER LPAREN argument_list RPAREN { $$ = new FunctionExp($1, $3);}
                ;

IfExpType : IF CondType BlockExpType {$$ = new IfExp($2, $3);}
          | IF CondType BlockExpType ELSE BlockExpType {$$ = new IfExp($2, $3, $5);}
          ;



FunctionType : FN IDENTIFIER LPAREN parameter_list RPAREN BlockStmType {$$ = new FuncDefStm($2, $4, $6);}
             | FN IDENTIFIER LPAREN parameter_list RPAREN ARROW type BlockStmType {$$ = new FuncDefStm($2, $4, $7, $8);}
             | FN IDENTIFIER LPAREN parameter_list RPAREN BlockExpType {$$ = new FuncDefExp($2, $4, $6);}
             | FN IDENTIFIER LPAREN parameter_list RPAREN ARROW type BlockExpType {$$ = new FuncDefExp($2, $4, $7, $8);}
             ;

function_list : function_list FunctionType { $$ = new PairFuncList($2, $1);}
              | FunctionType  { $$ = new LastFuncList($1);}
              ;




CondType : ExpType {$$=$1;}
         | ExpType conditional_operator ExpType {$$ = new CompareCondExp($1, $2, $3);}
         | CondType ANDAND CondType {$$ = new AndCond($1, $3);}
         | CondType OROR CondType {$$ = new OrCond($1, $3);}
         ;

NotCondType : NOT ExpType {$$ = new NotCondExp($2);}
            ;




mutability : /* Empty */ {$$ = false;}
           | MUT {$$ = true;}
           ;

type : INT { $$ = Int;}
     | BOOL {$$ = Bool;}
     ;

argument_list : /* Empty */ { $$ = nullptr;}
              | argument_list COMMA ExpType { $$ = new PairArgsExpList($3, $1);}
              | ExpType {$$ = new LastArgsExpList($1);}
              ;

parameter_list : /* Empty */ { $$ = nullptr;}
               | parameter_list COMMA IDENTIFIER COLON type { $$ = new PairParamExpList($3, $5, $1);}
               | IDENTIFIER COLON type { $$ = new LastParamExpList($1, $3);}
               ; 

conditional_operator : LT {$$ = Less;}
                     | LE {$$ = LessEqual;}
                     | GT {$$ = Greater;}
                     | GE {$$ = GreaterEqual;}
                     | NE {$$ = NotEqual;}
                     | EQEQ {$$ = EqualEqual;}
                     ;

assignment_operator : EQ {$$ = Equals;}
                    | PLUSEQ {$$ = PlusEquals;}
                    | MINUSEQ {$$ = MinusEquals;}
                    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s on at %i:%i\n", s, line_nr, col_nr);

    if (yytext) {
        fprintf(stderr, "Offending token: '%s'\n", yytext);
    } else {
        fprintf(stderr, "Unknown error at token.\n");
    }
}