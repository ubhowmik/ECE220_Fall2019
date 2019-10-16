#include <stdio.h>
int run_sum(int n);
//assume n is non-negative
int run_sum(int n)
{
	if(n == 1)
	 return 1;
	else
		return n+run_sum(n-1);
}

int main()
{
	int n=4;
	printf("run_sum(%d)=%d \n",n,run_sum(n));

	return 0;
}

