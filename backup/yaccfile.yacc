%{
#include "lexer.h"
#include <iostream>
#include "absyn.hpp"

extern int line_nr;
extern int col_nr;
void yyerror(const char* str);

Stm tree;

%}

// tokendeclaraties
%token
      FN LPAREN RPAREN ARROW LBRACE RBRACE SEMICOLON COLON LET EQ PLUS MINUS STAR SLASH PLUSEQ MINUSEQ ANDAND OROR NOT GT GE LT LE EQEQ NE AMPERSAND IF ELSE WHILE MUT COMMA
  
// voorrangdeclaraties
%left PLUS MINUS
%left STAR SLASH
%left PLUSEQ MINUSEQ EQ

%start program

%union {
    char* id;
    int num;
    bool boolean;
    Exp exp;
    ExpList exp_list;
    Stm stm;
    StmList stm_list;
    BoolExp b_exp;
    AssignOp assign_op;
    Type type;
}

%token <id> IDENTIFIER PRINTVAR PRINTSTRING
%token <num> DEC_LITERAL
%token <b_exp> TRUE FALSE
%token <type> INT BOOL

%type <exp> expression binary_operation grouped_expression function_call if_expression block_expression argument conditional value
%type <exp_list> argument_list
%type <stm_list> statement_list function_list parameter_list
%type <stm> statement assign_statement let_statement if_statement block_statement declaration_statement while_statement print_statement program function parameter
%type <assign_op> assignment_operator
%type <boolean> mutability
%type <type> type return_type

%%

program : // Empty file 
        | function_list { $$ = new Program($1); tree = $$; }
        ;

function_list : function_list function { $$ = new PairStmList($2, $1); }
              | function  { $$ = new LastStmList($1); }
              ;

function : FN IDENTIFIER LPAREN parameter_list RPAREN return_type block_statement { $$ = new FuncExpStm($2, $4, $6, $7); }
         | FN IDENTIFIER LPAREN parameter_list RPAREN return_type block_expression { $$ = new FuncExpStm($2, $4, $6, $7); }
         ;

return_type : // No return type { $$ = None; }
            | ARROW type { $$ = $2; }
            ;

parameter_list : // no parameter
               | parameter_list COMMA parameter { $$ = new PairStmList($3, $1); }
               | parameter { $$ = new LastStmList($1); }
               ; 

parameter : IDENTIFIER COLON mutability type { $$ = new ParamStm($1, $3, $4); }
          ;

argument_list : // No argument_list { $$ = nullptr; }
              | argument_list COMMA argument { $$ = new PairExpList($3, $1);}
              | argument { $$ = new LastExpList($1); }
              ;

argument : expression { $$ = $1; }
         ;

type : INT { $$ = Int; }
     | BOOL { $$ = Bool; }
     ;

statement_list : // No statements
               | statement_list statement { $$ = PairStmList($2, $1); }
               ; 

statement : let_statement SEMICOLON { $$ = $1; }
          | assign_statement SEMICOLON { $$ = $1;}
          | expression SEMICOLON { $$ = new ExpStm($1); }
          | if_statement { $$ = $1; }
          | print_statement SEMICOLON { $$ = $1; }
          | declaration_statement SEMICOLON { $$ = $1; }
          | while_statement { $$ = $1; }
          | block_statement { $$ = $1; }
          ;

while_statement : WHILE conditional block_statement { $$ = new WhileStm($2, $3); }

declaration_statement : LET mutability IDENTIFIER COLON type { $$ = new DeclaringStm($3, $2, $5); }
                      ;

print_statement : PRINTSTRING { $$ = new PrintStm($1); }
                | PRINTVAR { $$ = new PrintStm($1); }
                ;

let_statement : LET mutability IDENTIFIER COLON type EQ expression { $$ = new LetStm($3, $2, $5, $7); }
              | LET mutability IDENTIFIER EQ mutability expression { $$ = new LetStm($3, $2, None, $6); }
              ;

assign_statement : IDENTIFIER assignment_operator expression {  $$ = new AssignStm($1, $2, $3);}
                 | STAR IDENTIFIER assignment_operator expression { $$ = new PointerAssignStm($2, $3, $4); }
                 ;

assignment_operator : EQ { $$ = Equals; }
                    | PLUSEQ { $$ = PlusEquals; }
                    | MINUSEQ { $$ = MinusEquals; }
                    ;

expression : value { $$ = $1; }
           | function_call { $$ = $1; }
           | IDENTIFIER { $$ = new IdExp($1); }
           | if_expression { $$ = $1; }
           | STAR IDENTIFIER {$$ = new IdExp($2); }
           | block_expression { $$ = $1;}
           | binary_operation { $$ = $1; }
           | grouped_expression { $$ = $1;}
           ;

binary_operation : expression PLUS expression { $$ = new OpExp($1, Plus, $3); }
                 | expression MINUS expression { $$ = new OpExp($1, Minus, $3); }
                 | expression STAR expression { $$ = new OpExp($1, Times, $3); }
                 | expression SLASH expression { $$ = new OpExp($1, Divide, $3); }
                 ;

                
grouped_expression : LPAREN binary_operation RPAREN { $$ = $2; }
                   ;


function_call : IDENTIFIER LPAREN argument_list RPAREN {
    $$ = new FuncExp($1, $3);
}
              ;

if_statement : IF conditional block_statement { $$ = new IfStm($2, $3, nullptr); }
             | IF conditional block_statement ELSE block_statement { $$ = new IfStm($2, $3, $5); }
             ;

if_expression : IF conditional block_expression { $$ = new IfExp($2, $3, nullptr);}
              | IF conditional block_expression ELSE block_expression {$$ = new IfExp($2, $3, $5);}
              ;

conditional : expression LT expression { $$ = new ConditionalExp($1, Less, $3); }
            | expression LE expression { $$ = new ConditionalExp($1, LessEqual, $3); }
            | expression GT expression { $$ = new ConditionalExp($1, Greater, $3); }
            | expression GE expression { $$ = new ConditionalExp($1, GreaterEqual, $3); }
            | expression NE expression { $$ = new ConditionalExp($1, NotEqual, $3); }
            | expression EQEQ expression { $$ = new ConditionalExp($1, EqualEqual, $3); }
            | NOT expression { $$ = new NotExp($2);}
            | TRUE { $$ = new BoolExp($1); }
            | FALSE { $$ = new BoolExp($1); }
            ;

block_statement : LBRACE statement_list RBRACE { $$ = new BlockStm($2); }
                ;

block_expression : LBRACE statement_list expression RBRACE { $$ = new BlockExp($2, $3); }
                 ;

value : DEC_LITERAL { $$ = new NumExp($1); }
      | TRUE { $$ = new BoolExp($1); }
      | FALSE { $$ = new BoolExp($1); }
      ;

mutability : // Not mutable { $$ = false; }
           | MUT { $$ = true; }
           | AMPERSAND MUT { $$ = true; }
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