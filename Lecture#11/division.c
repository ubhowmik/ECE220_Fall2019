#include <stdio.h>

void division(int Divd, int Divs, int *x, int *y);

int main()
{
int divident, divisor, quotient, remainder;
printf("enter the divident:\n");
scanf("%d", &divident);
printf("enter the divisor:\n");
scanf("%d", &divisor);

division(divident, divisor,&quotient, &remainder);

printf("the quotient is : %d\n", quotient);
printf("the remainder is : %d\n", remainder);
return 0;
}

void division(int Divd, int Divs, int *x, int *y)
{
*x=Divd/Divs;
*y=Divd%Divs;
}
