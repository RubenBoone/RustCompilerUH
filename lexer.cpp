#include "lexer.h"

#include <stdio.h>
#include <string>

#include "tokens.h"

/* Array with tokens such that index = tokenid - 250*/
std::string tokens[] = {
    "IDENTIFIER", "PRINTVAR", "PRINTSTRING", "DEC_LITERAL", "TRUE", "FALSE",
    "FN", "LPAREN", "RPAREN", "ARROW", "LBRACE", "RBRACE",
    "SEMICOLON", "COLON", "LET", "EQ", "PLUS", "MINUS",
    "STAR", "SLASH", "PLUSEQ", "MINUSEQ", "ANDAND", "OROR",
    "NOT", "GT", "GE", "LT", "LE", "EQEQ",
    "NE", "AMPERSAND", "IF", "ELSE", "WHILE", "MUT",
    "COMMA", "INT", "BOOL"};

int main(int argc, char *argv[])
{
  int tokenid;

  /* If we do not explicitly bind yyin to a file, stdin is assumed. */
  while ((tokenid = yylex()))
  {
    /* Token codes start from 250 */
    printf(" %s", tokens[tokenid - 250]);

    /* Append value */
    if ((tokenid == IDENTIFIER) || (tokenid == DEC_LITERAL) ||
        (tokenid == PRINTSTRING) || (tokenid == PRINTVAR))
      printf("=\"%s\"", yytext);
  }
  printf("\n");
  return 0;
}
