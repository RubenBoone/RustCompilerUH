#include <stdio.h>

#include "y.tab.h"

int main() {
  if (yyparse()) {
    printf("Syntax error\n");
  } else {
    printf("Syntax OK\n");
  }
  return 0;
}