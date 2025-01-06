#include <stdio.h>
#include "absyn.hpp"
#include "y.tab.hpp"

int main()
{
  if (yyparse())
  {
    printf("Syntax error\n");
  }
  else
  {
    printf("Syntax OK\n");
  }
  return 0;
}