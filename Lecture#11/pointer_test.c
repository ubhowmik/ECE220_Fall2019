/* pointer_test.c
   Using the & and * operators */
#include <stdio.h>

int main()
{
   int a;        /* a is an integer */
   int *aPtr;    /* aPtr is a pointer to an integer */

   
   a = 7;
   aPtr = &a;    /* aPtr set to address of a */

   printf( "The address of a is %p"   
           "\nThe value of aPtr is %p", &a, aPtr );

   printf( "\n\nThe value of a is %d"   
           "\nThe value of *aPtr is %d", a, *aPtr);

   printf( "\n\nShowing that * and & are inverses of "
           "each other.\n&*aPtr = %p"   
           "\n*&aPtr = %p\n", &*aPtr, *&aPtr );

   *aPtr = 10;
   printf("\n\n The value of changed *aptr and a are %d %d", *aPtr, a);
   printf("\n");

   return 0;
}



