#include <stdio.h>

int main() {
  FILE *in, *out;
  char buf[5];

  if((in=fopen("Text.txt","r"))==NULL) {
    printf("Unable to open input.\n");
    return -1;
  }
  if((out=fopen("out2.txt","w"))==NULL) {
    printf("Unable to open output.");
    return -1;
  }

  printf("%d\n", sizeof(buf));

  fgets(buf, sizeof(buf), in);
  while(!feof(in)) {
    fputs(buf, out);
    printf("%s\n", buf);
    fgets(buf, sizeof(buf), in);
  }

  fclose(in);
  fclose(out);

  return 0;
}
