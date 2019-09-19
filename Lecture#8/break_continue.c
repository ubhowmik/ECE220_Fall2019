/* Break_Continue Code:*/

#include <stdio.h>

int main()
{
int x;

printf("break_output x = ");

for (x = 0; x < 10; x++){
	if (x == 5)
	break;
	printf(" %d",x);
	}
printf("\ncontinue_output x =");

for (x = 0; x < 10; x++){
	if (x == 5)
	continue;
	printf(" %d",x);
	}
printf("\n");
return 0;

}