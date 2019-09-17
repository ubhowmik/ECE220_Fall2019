/* Pre/Post Increment */

#include <stdio.h>
int main()
{
   /* pre-increment */
   int x, y;
   x = 4;
   printf("x = %d \n", x);
   y = ++x;
   /* the above line is the same as
    * x = x+1;
    * y = x;
    */
   
   printf("after pre-increment (y = ++x): y = %d, x = %d\n", y,x);
   /*printf("x = %d\n", x);*/


   /* post increment */
   x = 4;
   printf("x = %d \n", x);
   y = x++;
   /* the above line is the same as
    * y = x;
    * x = x+1;
    */
   printf("after post-increment (y = x++): y = %d, x = %d\n", y,x);
   /*printf("value of new x is %d\n", x);*/
y=x;
printf("after post-increment and (y = x): y = %d, x = %d\n", y,x);

   return 0;
}