#include <stdio.h>

void swap(int *, int *);


int main()
{
	int x = 1;
	int y = 2;

	printf("Before swap: x = %d, y = %d\n", x, y);
	swap(&x, &y);

	//Did the swap function work the way you expect?
	printf("After swap: x = %d, y = %d\n", x, y);

	return 0;
}

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
