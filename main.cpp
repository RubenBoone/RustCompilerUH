#include <stdio.h>
#include "absyn.hpp"
#include "y.tab.hpp"

extern Stm tree;

int main()
{
  printf("Parsing...\n");

  if (!yyparse())
  {
    printf("Parsing done.\n");
  }
  else
  {
    printf("Parsing ended with error...\n");
  }

  printf("\nType checking...\n");
  Table *t = new Table();
  tree->check(t);

  delete t;
  return 0;
}