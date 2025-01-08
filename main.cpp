#include <stdio.h>
#include "absyn.hpp"
#include "y.tab.hpp"

extern Stm tree;

int main()
{
  printf("--== Parsing ==--\n");
  if (!yyparse())
  {
    printf("Parsing done.\n");
  }
  else
  {
    printf("Parsing ended with error...\n");
    return 1;
  }

  printf("\n--== Type checking ==--\n");
  Table *t = new Table();
  tree->check(t);
  if (t->typeCheckCorrect)
  {
    printf("Type checking done.\n");
  }
  else
  {
    printf("Type checking ended with error...\n");
  }

  delete t;
  return 0;
}