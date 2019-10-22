#include <stdio.h>

int main() {

  int c;
  FILE *f1, *f2;

  f1 = fopen("out.txt","w");
  if(f1==NULL) {
    printf("Unable to open for output.");
    return 0;
  }

  f2 = fopen("Text.txt","r");
  if(f2==NULL) {
    printf("Unable to open for input.");
    return 0;
  }

  //c = fgetc(f2);
  //while(c!=EOF) {
  //  putchar(c);
  //  fputc(c,f1);
  //  c = fgetc(f2);
  //}

  while((c=fgetc(f2))!=EOF) {
      putchar(c);
      fputc(c,f1);
  }

  fclose(f1);
  fclose(f2);

  return 0;
}
