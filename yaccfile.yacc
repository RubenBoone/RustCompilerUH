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
        | function
        | functions function
        ;

functions : function function
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
           ;

statement : LET IDENTIFIER EQ expression
          | IDENTIFIER PLUSEQ expression
          | IDENTIFIER MINUSEQ expression
          | PRINTSTRING
          | PRINTVAR
          | IDENTIFIER LBRACE params RBRACE
          ;

expression : DEC_LITERAL
           | IDENTIFIER
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
            | LET MUT IDENTIFIER EQ expression
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
