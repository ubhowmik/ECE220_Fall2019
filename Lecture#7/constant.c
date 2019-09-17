/* use of const - would this program work? */
#include <stdio.h>
 int y = 15;

void printx(){
	/*static int x = 0;*/
	printf("value of y is %d \n",y);
}

int main()
{
static int y = 15;
y=y+1;
   
   printf("value of y is %d\n", y);
   printx();

   return 0;
}
