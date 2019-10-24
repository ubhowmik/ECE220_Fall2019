#include <stdio.h>
#include <unistd.h>

int main()
{
  putchar('a');
  putchar('\n');
  
  sleep(3);
    
  putchar('b');
  putchar('\n');
}
