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
%token     IDENTIFIER PRINTVAR PRINTSTRING DEC_LITERAL TRUE FALSE FN LPAREN RPAREN ARROW LBRACE RBRACE SEMICOLON COLON LET EQ PLUS MINUS STAR SLASH PLUSEQ MINUSEQ ANDAND OROR NOT GT GE LT LE EQEQ NE AMPERSAND IF ELSE WHILE MUT COMMA INT BOOL
  
// voorrangdeclaraties
%left PLUS MINUS
%left STAR SLASH
%left PLUSEQ MINUSEQ EQ

%start program


%%

program : /* Empty */
        | function_list
        ;

function_list : function_list function
              | function
              ;

function : FN IDENTIFIER LPAREN parameter_list RPAREN return_type block_statement
         | FN IDENTIFIER LPAREN parameter_list RPAREN return_type block_expression
         ;

return_type : /* Empty */
            | ARROW type
            ;

parameter_list : /* Empty */
               | parameter_list COMMA parameter
               | parameter 
               ; 

parameter : IDENTIFIER COLON mutability type
          ;

argument_list : /* Empty */
              | argument_list COMMA argument
              | argument
              ;

argument : expression
         ;

type : INT
     | BOOL
     ;

statement_list : // No statements
               | statement_list statement
               ; 

statement : let_statement SEMICOLON
          | assign_statement SEMICOLON
          | expression SEMICOLON
          | if_statement
          | print_statement SEMICOLON
          | declaration_statement SEMICOLON
          | while_statement
          | block_statement
          ;

while_statement : WHILE conditional block_statement

declaration_statement : LET mutability IDENTIFIER COLON type
                      ;

print_statement : PRINTSTRING
                | PRINTVAR
                ;

let_statement : LET mutability IDENTIFIER COLON type EQ expression
              | LET mutability IDENTIFIER EQ mutability expression
              ;

assign_statement : IDENTIFIER assignment_operator expression
                 ;

assignment_operator : EQ
                    | PLUSEQ
                    | MINUSEQ
                    ;

expression : value
           | function_call
           | IDENTIFIER
           | if_expression
           | block_expression
           | binary_operation
           | grouped_expression
           ;

binary_operation : expression PLUS expression
                 | expression MINUS expression
                 | expression STAR expression
                 | expression SLASH expression
                 ;

                
grouped_expression : LPAREN binary_operation RPAREN
                   ;


function_call : IDENTIFIER LPAREN argument_list RPAREN
              ;

if_statement : IF conditional block_statement
             | IF conditional block_statement ELSE block_statement
             ;

if_expression : IF conditional block_expression
              | IF conditional block_expression ELSE block_expression
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

block_expression : LBRACE statement_list expression RBRACE
                 ;

value : DEC_LITERAL
      | TRUE
      | FALSE
      ;


mutability : /* Empty */
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