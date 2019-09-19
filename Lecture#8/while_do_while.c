//while_do_while

#include <stdio.h>

int x=9;

int main()
{
while (x < 10) {
    printf("while loop x= %d\n", x);
    x = x + 1;
}

do {
    printf("do_while loop x= %d\n", x);
    x = x + 1;
} while (x < 10);

return 0;
}
