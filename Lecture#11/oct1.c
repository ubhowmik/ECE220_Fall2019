#include<stdio.h>

void division(int A, int B,int *x, int *y);

int main()
{
int divident, divisor, quotient, remainder;

divident=5;
divisor=2;
 division(divident, divisor, &quotient, &remainder);
 printf("quotient is %d\n", quotient);
 printf("remainder is %d\n", remainder);
 
 return 0;
 }
 
 void division(int A, int B,int *x, int *y)
 {
 *x=A/B;
 *y=A%B;
 }
