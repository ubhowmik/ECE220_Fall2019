//Calculating the prime number between 2 to 100

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	unsigned int n;
	scanf("%d",&n);
	float range;
	range=ceil(sqrt(n));
	bool prime = true;
	unsigned int num;
	
for (num =2; num<=n;num++){
	prime=true;
	
	for (int i=2; i<=range;i++)
		if ((num%i)==0 && num!=i){
			prime=false;
			break;
			}
	
		if (prime)
			printf("The number %d is a prime number.\n",num);
}
	
	return 0;
}