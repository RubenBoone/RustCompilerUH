%{
#include "lexer.h"
extern int line_nr;
extern int col_nr;
void yyerror(const char* str);

%}

// tokendeclaraties
%token
  IDENTIFIER PRINTVAR PRINTSTRING DEC_LITERAL TRUE FALSE FN LPAREN RPAREN ARROW LBRACE RBRACE SEMICOLON COLON LET EQ PLUS MINUS STAR SLASH PLUSEQ MINUSEQ ANDAND OROR NOT GT GE LT LE EQEQ NE AMPERSAND IF ELSE WHILE MUT COMMA INT BOOL
  
// voorrangdeclaraties
%left PLUS MINUS
%left STAR SLASH
%left PLUSEQ MINUSEQ EQ

%start program

%defines

%%

program : // Empty file
        | program function
        ;

function : FN IDENTIFIER LPAREN parameter_list RPAREN LBRACE statement_list RBRACE
         | FN IDENTIFIER LPAREN parameter_list RPAREN ARROW type LBRACE statement_list RBRACE
         ;

parameter_list : // no parameter
               | parameter_list COMMA parameter
               | parameter
               ; 

parameter : IDENTIFIER COLON type
          | expression
          ;

type : INT
     | BOOL
     ;

statement_list : // No statements
               | statement_list statement
               | block_expression
               ; 

block_expression : statement_list expression
                 ;

statement : let_statement SEMICOLON
          | assign_statement SEMICOLON
          | expression_statement SEMICOLON
          | if_statement
          | print_statement SEMICOLON
          | declaration_statement SEMICOLON
          ;

declaration_statement : LET mutability IDENTIFIER COLON type
                      ;

print_statement : PRINTSTRING
                | PRINTVAR
                ;

let_statement : LET mutability IDENTIFIER COLON type EQ expression
              | LET mutability IDENTIFIER EQ expression
              ;

assign_statement : IDENTIFIER assignment_operator expression
                 | IDENTIFIER assignment_operator if_statement
                 ;

assignment_operator : EQ
                    | PLUSEQ
                    | MINUSEQ
                    ;

expression_statement : expression
                     ;

expression : value
           | function_call
           | IDENTIFIER
           | expression PLUS expression
           | expression MINUS expression
           | expression STAR expression
           | expression SLASH expression
           ;

function_call : IDENTIFIER LPAREN parameter_list RPAREN
              ;

if_statement : IF conditional block_statement
             | IF conditional block_statement ELSE block_statement
             ;

conditional : expression LT expression
            | expression LE expression
            | expression GT expression
            | expression GE expression
            | expression NE expression
            | expression EQEQ expression
            | NOT expression
            | TRUE
            | FALSE
            ;

block_statement : LBRACE statement_list RBRACE
                ;

value : DEC_LITERAL
      | TRUE
      | FALSE
      ;

mutability : // Not mutable
           | MUT
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
