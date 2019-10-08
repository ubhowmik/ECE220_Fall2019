#include <stdio.h>
int foo(int *x);
int main() 
{
  int y[5] = {1,2,3,4,5};
  foo(y);
  printf("%d\n", y[3]);
  return 0;
}

int foo(int *x) 
{ x[3] = 10; 
}


