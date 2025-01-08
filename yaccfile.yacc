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
%left ANDAND OROR
%left EQEQ NE GT GE LT LE
%left PLUS MINUS
%left STAR SLASH
%nonassoc NOT

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
    IfExp *ifexp;
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
    EqualCond *eqcond;

    CompoundStm *compoundstm;
    FuncDefStm *funcdefstm;
    FuncDefExp *funcdefexp;
}

%token <id> IDENTIFIER PRINTSTRING PRINTVAR
%token <num> DEC_LITERAL
%token <binop> PLUS MINUS STAR SLASH
%token <assignop> PLUSEQ MINUSEQ EQ
%token <bool> TRUE FALSE

%type <boolean> mutability

%type <dtype> type
%type <assignop> assignment_operator
%type <condop> conditional_operator

%type <exp> ExpType Term IfExpType
%type <idexp> IdExpType
%type <boolexp> BoolExpType
%type <numexp> NumExpType
%type <binopexp> BinopExpType
%type <blockexp> BlockExpType
%type <groupexp> GroupExpType
%type <funcexp> FunctionExpType

%type <notcondexp> NotCondType
%type <compcondexp> CompareCondExpType

%type <stm> StmType IfStmType
%type <letstm> LetStmType
%type <assignstm> AssignStmType
%type <blockstm> BlockStmType
%type <decstm> DecStmType
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
        | error SEMICOLON { yyerror("Error in statement"); yyclearin; $$ = nullptr; }
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

IfStmType : IF ExpType BlockStmType {$$ = new IfStm($2, $3);}
          | IF ExpType BlockStmType ELSE BlockStmType {$$ = new IfElseStm($2, $3, $5);}
          ;

PrintStmType : PRINTSTRING { $$ = new PrintStm($1);}
             ;

VarPrintStmType : PRINTVAR { $$ = new VarPrintStm($1);}
                ;

WhileStmStype : WHILE ExpType BlockStmType { $$ = new WhileStm($2, $3);}
              ;



CompareCondExpType : ExpType conditional_operator Term {$$ = new CompareCondExp($1, $2, $3);}
                   ;


ExpType : ExpType ANDAND ExpType {$$ = new AndCond($1, $3);}
        | ExpType OROR ExpType {$$ = new OrCond($1, $3);}
        | CompareCondExpType {$$ = $1;}
        | NumExpType {$$ = $1;}
        | IdExpType {$$ = $1;}
        | BinopExpType { $$ = $1;}
        | BlockExpType { $$ = $1;}
        | GroupExpType { $$ = $1;}
        | BoolExpType {$$ = $1;}
        | FunctionExpType { $$ = $1;}
        | IfExpType { $$ = $1;}
        | NotCondType {$$ = $1;}
        ;

Term : NumExpType {$$ = $1;}
     | IdExpType {$$ = $1;}
     | BoolExpType {$$ = $1;}
     | BlockExpType { $$ = $1;}
     | FunctionExpType { $$ = $1;}
     | BinopExpType { $$ = $1;}
     | GroupExpType { $$ = $1;}
     | IfExpType { $$ = $1;}
     | error SEMICOLON { yyerror("Error in expression"); yyclearin; $$ = nullptr; }
     ;



IdExpType : IDENTIFIER {$$ = new IdExp($1);}
          ;

BoolExpType : TRUE { $$ = new BoolExp(true);}
            | FALSE { $$ = new BoolExp(false);}
            ;

NumExpType : DEC_LITERAL {$$ = new NumExp($1);}
           ;

BinopExpType : Term PLUS Term {$$ = new BinopExp($1, Plus, $3);}
             | Term MINUS Term {$$ = new BinopExp($1, Minus, $3);}
             | Term STAR Term {$$ = new BinopExp($1, Times, $3);}
             | Term SLASH Term {$$ = new BinopExp($1, Divide, $3);}
             ;

BlockExpType : LBRACE CompoundStmType ExpType RBRACE {$$ = new BlockExp($2, $3);}
             ;

GroupExpType : LPAREN ExpType RPAREN { $$ = new GroupedExp($2);}
             | LPAREN error RPAREN { yyerror("Error in grouped expression"); yyclearin; $$ = nullptr; }
             ;

FunctionExpType : IDENTIFIER LPAREN argument_list RPAREN { $$ = new FunctionExp($1, $3);}
                ;

IfExpType : IF ExpType BlockExpType {$$ = new IfExp($2, $3);}
          | IF ExpType BlockExpType ELSE BlockExpType {$$ = new IfElseExp($2, $3, $5);}
          ;



FunctionType : FN IDENTIFIER LPAREN parameter_list RPAREN BlockStmType {$$ = new FuncDefStm($2, $4, $6);}
             | FN IDENTIFIER LPAREN parameter_list RPAREN ARROW type BlockExpType {$$ = new FuncDefExp($2, $4, $7, $8);}
             | error RPAREN { yyerror("Error in function definition"); yyclearin; $$ = nullptr; }
             ;

function_list : FunctionType function_list  { $$ = new PairFuncList($1, $2);}
              | FunctionType  { $$ = new LastFuncList($1);}
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
              | ExpType COMMA  argument_list { $$ = new PairArgsExpList($1, $3);}
              | ExpType {$$ = new LastArgsExpList($1);}
              ;

parameter_list : /* Empty */ { $$ = nullptr;}
               | mutability IDENTIFIER COLON type COMMA parameter_list { $$ = new PairParamExpList($2, $4, $6, $1);}
               | mutability IDENTIFIER COLON type { $$ = new LastParamExpList($2, $4, $1);}
               ; 

conditional_operator : LT {$$ = Less;}
                     | LE {$$ = LessEqual;}
                     | GT {$$ = Greater;}
                     | GE {$$ = GreaterEqual;}
                     | EQEQ {$$ = EqualEqual;}
                     | NE {$$ = NotEqual;}
                     ;

assignment_operator : EQ {$$ = Equals;}
                    | PLUSEQ {$$ = PlusEquals;}
                    | MINUSEQ {$$ = MinusEquals;}
                    ;

%%

void yyerror(const char *s) {
    if (!yytext) {
        fprintf(stderr, "Unknown error at token.\n");
    } else {
        fprintf(stderr, "%s:\n", s);
        fprintf(stderr, "Offending token at %i:%i: '%s'\n", line_nr, col_nr, yytext);
    }
}