#include <stdio.h>

int main() {
  int k;
  FILE* out;
  int array[100];

  for(k=0;k<100;++k) {
    array[k] = k;
  }

  out = fopen("data.txt","w");

  for(k=0;k<100;++k) {
    fprintf(out, "%d ", array[k]);
  }

  fclose(out);

  return 0;
}
