#include <stdio.h>

int main() {
  char in1, in2;

  int a = 1;
  int b = 2;
  int c = printf("a: %d; b: %d\n", a);
  printf("c: %d\n", c);

  printf("Char1:\n");
  in1 = getchar();

  printf("Char2:\n");
  in2 = getchar();

  printf("Char1: %d\n", (int)in1);
  printf("Char2: %d\n", (int)in2);

  return 0;
}
