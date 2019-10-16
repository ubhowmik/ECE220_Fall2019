#include <stdio.h>
int Factorial(int n);
//assume n is non-negative
int Factorial(int n)
{
	int fn;
	if(n == 0)
		fn=1;
	else
		fn= n*Factorial(n-1);
	return fn
}

int main()
{
	int n=3;
	int result = Factorial(n);
	printf("Factorial(%d)=%d \n",n,result);

	return 0;
}

