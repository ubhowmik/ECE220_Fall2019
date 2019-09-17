/* A program to calculate circumference of a circle given the radius */
#include <stdio.h>

#define PI 3.1416f

int main()
{
   float r, c;

   printf("Enter radius of a circle in cm: ");

   scanf("%f", &r);

   c = 2*PI*r;

   printf("Circumference of the circle is %f cm\n", c);

   return 0;
}
