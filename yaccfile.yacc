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

// vul aan met producties
program : FN IDENTIFIER LPAREN RPAREN LBRACE statements RBRACE
        ;

statements : // body can be empty
           | statements statement SEMICOLON
           ;

statement : LET IDENTIFIER EQ expression
          | LET IDENTIFIER EQ FALSE
          | LET IDENTIFIER EQ TRUE
          | IDENTIFIER EQ expression
          | expression
          | PRINTVAR
          | PRINTSTRING
          | LET IDENTIFIER COLON type
          ;

expression : DEC_LITERAL
           | IDENTIFIER
           | expression PLUS expression
           | expression MINUS expression
           | expression STAR expression
           | expression SLASH expression
           | IDENTIFIER PLUSEQ expression
           | IDENTIFIER MINUSEQ expression
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
