#include<stdio.h>
/*
2nd parameter: 0b is for binary; 0X for hex and 0 for octal
*/

int main()
{

	printf("The decimal value is %d\n",0b0000000001101000);
	printf("The ASCII value is %c\n",0b0000000001101000);
	printf("The Hex Value is %x\n",0b0000000001101000);
	printf("The floating point value is %f\n",0b0000000001101000);
		
	int x=15.32;float y=15.32;
	printf("%f %f %d %d\n",x,y,x,y);
	
	printf("the value of nothing is %f %d\n",5.1);
	
	return 0;
	
}