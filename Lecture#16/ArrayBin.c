#include <stdio.h>

int main() {
  int k;
  FILE* out;
  int array[100];

  for(k=0;k<100;++k) {
    array[k] = k;
  }

  out = fopen("data.bin","wb");

  fwrite(array, sizeof(int), 100, out);

  fclose(out);

  return 0;
}
