%{
#include "absyn.hpp"
#include "y.tab.hpp"
// #include "tokens.h"
#include <stdio.h>

/* Keep track of current position of lex for error messages, i.e. 
   the position just *after* the last token read */
int line_nr = 0;
int col_nr = 0; 
%}

PRINTVAR println!\(\"\{[a-zA-Z_][a-zA-Z0-9_]*\}\"\)
PRINTSTRING println!\(\"[^\"]*\"\)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
DIGIT [0-9]+

%%

if {col_nr += yyleng; return IF;}
else {col_nr += yyleng; return ELSE;}
while {col_nr += yyleng; return WHILE;}
mut {col_nr += yyleng; return MUT;}
let {col_nr += yyleng; return LET;}
true {
  col_nr += yyleng;
  return TRUE;}
false {
  col_nr += yyleng;
  return FALSE;}
fn {col_nr += yyleng; return FN;}
"i32" {col_nr += yyleng; return INT;}
bool {col_nr += yyleng; return BOOL;}

{PRINTVAR} {
    char var_name[256];
    sscanf(yytext, "println!(\"{%255[^}]}\")", var_name);
    yytext = var_name;
    char* s = (char*) malloc(yyleng+1);
    strcpy(s, yytext);
    yylval.id = s;
    col_nr += yyleng;
    return PRINTVAR;
}
{PRINTSTRING} {
    char string_content[256];
    sscanf(yytext, "println!(\"%255[^\"]\")", string_content);
    yytext = string_content;
    char* s = (char*) malloc(yyleng+1);
    strcpy(s, yytext);
    yylval.id = s;
    col_nr += yyleng; 
    return PRINTSTRING;
}
{IDENTIFIER} {
  col_nr += yyleng;
  char* s = (char*) malloc(yyleng+1);
  strcpy(s, yytext);
  yylval.id = s;
  return IDENTIFIER;}

{DIGIT} {
  col_nr += yyleng;
  yylval.num = atoi(yytext);
  return DEC_LITERAL;}

\( {col_nr += yyleng; return LPAREN;}
\) {col_nr += yyleng; return RPAREN;}
\-\> {col_nr += yyleng; return ARROW;}
\{ {col_nr += yyleng; return LBRACE;}
\} {col_nr += yyleng; return RBRACE;}
\; {col_nr += yyleng; return SEMICOLON;}
\: {col_nr += yyleng; return COLON;}
\= {col_nr += yyleng; return EQ;}
\+ {col_nr += yyleng; return PLUS;}
\- {col_nr += yyleng; return MINUS;}
\* {col_nr += yyleng; return STAR;}
\/ {col_nr += yyleng; return SLASH;}
\+\= {col_nr += yyleng; return PLUSEQ;}
\-\= {col_nr += yyleng; return MINUSEQ;}
\&\& {col_nr += yyleng; return ANDAND;}
\|\| {col_nr += yyleng; return OROR;}
\! {col_nr += yyleng; return NOT;}
\> {col_nr += yyleng; return GT;}
\>\= {col_nr += yyleng; return GE;}
\< {col_nr += yyleng; return LT;}
\<\= {col_nr += yyleng; return LE;}
\=\= {col_nr += yyleng; return EQEQ;}
\!\= {col_nr += yyleng; return NE;}
\& {col_nr += yyleng; return AMPERSAND;}
\, {col_nr += yyleng; return COMMA;}
\/\/.* {col_nr += yyleng;}
[ \t]+ {col_nr += yyleng;}
\n {line_nr++; col_nr = 1;}

. {
  if (yytext[0] < ' ') { /* non-printable char */
    fprintf(stderr, "illegal character: ^%c", yytext[0] + '@');
  } else {
    if (yytext[0] > '~') {
      fprintf(stderr, "illegal character: \\%03o", (int)yytext[0]);
    } else {
      fprintf(stderr, "illegal character: %s", yytext);
    }
  }
  fprintf(stderr, " at line %d column %d\n", line_nr, col_nr);
}

%%

int yywrap() {
  return 1;
}