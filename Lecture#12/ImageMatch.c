#include <stdio.h>

int Match(int im[][4], int ma[][2], int w, int h, int mw, int mh) {
  int count = 0;
  int x, y, dx, dy;
  int match;

  for(x=0;x<w-mw+1;++x) {
    for(y=0;y<h-mh+1;++y) {
      match = 1;
      for(dx=0;dx<mw;++dx) {
        for(dy=0;dy<mh;++dy) {
          printf("x %d, y %d, dx %d, dy %d\n", x, y, dx, dy);
          if(im[x+dx][y+dy]!=ma[dx][dy]) {
            match = 0;
            break;
          }
        }
      }
      if(match==1) {
        ++count;
      }
    }
  }

  return count;
}


int main() {
  int image[4][4] = {{1,2,3,4},{1,2,3,4},{3,7,1,2},{3,4,1,2}};
  int match[2][2] = {{1,2},{1,2}};
  int count = 0;
  int im_w = 4, im_h = 4;
  int m_w = 2, m_h = 2;

  int *iptr = image[2];

  for(count = 0;count < 4;++count) {
    printf("%d ", iptr[count]);
  }
  printf("\n");

  count = Match(image, match, im_w, im_h, m_w, m_h);

  printf("Count: %d\n", count);

  return 0;
}
