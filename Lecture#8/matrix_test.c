#include <stdio.h>
/* use nested for loops to print an n x n matrix */  
/* 0 0 0 0
   0 1 0 0
   0 0 2 0
   0 0 0 3
*/   
int main(){
   int i, j, n=0;
   printf("Enter a number for nxn matrix size: ");
   scanf("%d", &n);
   while(!(0<n && 10>=n))
   {printf("Invalid Input.\n");
   printf("Enter the Number again: ");
   scanf("%d", &n);
   }
   printf("Output Matrix: \n");

   for (i = 0; i < n; i++){
	   if (i==3)
		   break;
	for (j = 0; j < n; j++){
		if(i == j){
		   printf("%d",i);
		   if (i==2 && j==2)
			   break;
		   }
	   	else
		   printf("0");
	}
	printf("\n");
   }
   return 0;
}

