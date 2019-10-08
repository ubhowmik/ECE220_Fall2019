#include <stdio.h>
int CountOccurence(char* cptr, char test)

int CountOccurence(char* cptr, char test) {
  int count = 0;
  while(*cptr!='\0') {
    if(*cptr++==test) {
      ++count;
    }
  }
  return count;
}

int main() {
  char text[50];
  char testchar = 'a';
  int count = 0;

  printf("Enter string: ");
  gets(text);

  count = CountOccurence(text, testchar);

  printf("Character a: %d\n", count);
  return 0;
}
