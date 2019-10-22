#include <stdio.h>
#include <unistd.h>

int main() {
  putchar('a');
  sleep(5);
  putchar(97);
  sleep(5);
  putchar('\n');

  return 0;
}
