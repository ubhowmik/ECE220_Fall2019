#include <stdio.h>
void swap(int x, int y);
int z, k;

int main()
{
	int x = 1;
	int y = 2;

	printf("Before swap: x = %d, y = %d\n", x, y);
	swap(x, y);

	//Did the swap function work the way you expect?
	printf("After swap: x = %d, y = %d\n", z, k);

	return 0;
}

void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
	z=x;
	k=y;
}

