/* global vs local variables */
#include <stdio.h>

int x = 5;

int main()
{
   printf("value of x is %d\n", x); 
 
   int x = 10;
   printf("value of x is %d\n", x); 
 
   { 
	int x = 15;
   	printf("value of x is %d\n", x); 
   }
   //extern int x;   
   printf("value of x is %d\n",x);

   return 0;
}
