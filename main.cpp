#include <stdio.h>
#include "absyn.hpp"
#include "y.tab.hpp"

int main()
{
  if (!yyparse())
  {
    printf("Parsing done.\n");
  }
  else
  {
    printf("Parsing ended with error...\n");
  }
  return 0;
}