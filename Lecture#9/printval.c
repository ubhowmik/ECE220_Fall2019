#include <stdio.h>
void print_val(int x, int y);

void print_val(int x, int y)
{
	printf("first value:%d second value:%d\n", x, y);
}

int main()
{
	int z = 0;
	printf("value of z++:%d\n", z++);
	z = 0;
	printf("value of ++z:%d\n", ++z);

	int val = 10;
	print_val(val, val++);

	return 0;
}
