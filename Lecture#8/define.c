#include<stdio.h>

#define min(a,b) (a<b ? a:b)

int main()
{
	float x=50e5;
	float y=60e6;
	printf("the minimum values is %f\n",min(x,y));
		
	return 0;
}