#include <stdio.h>

void printx(){
	static int x = 0;
	//int x = 0;
	x++;
	printf("value of x is %d \n",x);
}

int main(){
	printx();
	printx();
	printx();
	printx();
    printf("value of x is %d \n",x);
	return 0;
}
