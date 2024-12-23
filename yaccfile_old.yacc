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
%left PLUSEQ MINUSEQ

%defines

%%

program : // Empty file
        | functions 
        ;

functions : function
          | functions function
          ;

function : FN IDENTIFIER LPAREN params RPAREN blockStatement
         | FN IDENTIFIER LPAREN params RPAREN ARROW type blockStatement
         ;

functionCall : IDENTIFIER LPAREN params RPAREN
             ;

blockStatement : LBRACE statements RBRACE
               ;


statements : // Empty body
           | statements statement SEMICOLON
           | statements declaration SEMICOLON
           | statements assignment SEMICOLON
           | statements functionCall SEMICOLON
           | statements expression
           | statements declaration
           | IF conditionals blockStatement
           | IF conditionals blockStatement ELSE blockStatement
           | WHILE conditionals blockStatement
           ;

statement : LET IDENTIFIER EQ expression
          | LET IDENTIFIER COLON type EQ expression
          | LET MUT IDENTIFIER COLON type EQ expression
          | IDENTIFIER PLUSEQ expression
          | IDENTIFIER MINUSEQ expression
          | STAR IDENTIFIER EQ expression
          | PRINTSTRING
          | PRINTVAR
          | IDENTIFIER LBRACE params RBRACE
          | blockStatement
          ;

// Shift reduce => Parser doens't know if expression is finished or if there will be more because of a blockexpression. the last expression doesn't need to have a semicolon and if this happends the parser gets confused. Because expressions that are not assigned to a variable don't do anything and only give a warning in rust I decided to go with this shift reduce conflict.

expression : DEC_LITERAL
           | IDENTIFIER
           | STAR expression
           | functionCall
           | expression PLUS expression
           | expression MINUS expression
           | expression STAR expression
           | expression SLASH expression
           | TRUE
           | FALSE
           | AMPERSAND MUT IDENTIFIER
           ;

conditionals : conditional
             | conditionals ANDAND conditional
             | conditionals OROR conditional
             ;

conditional : expression LT expression
            | expression LE expression
            | expression GT expression
            | expression GE expression
            | expression NE expression
            | expression EQEQ expression
            | NOT expression
            | expression
            ;

declaration : LET IDENTIFIER COLON type
            | LET IDENTIFIER EQ blockStatement
            | LET MUT IDENTIFIER EQ expression SEMICOLON
            ;

assignment : IDENTIFIER EQ expression
           | IDENTIFIER EQ IF conditional blockStatement
           | IDENTIFIER EQ IF conditional blockStatement ELSE blockStatement
           ;

params : // Empty params
       | IDENTIFIER COLON type
       | IDENTIFIER COLON AMPERSAND MUT type
       | expression
       | expression COMMA params
       ;

type : INT
     | BOOL
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
