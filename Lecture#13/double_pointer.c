// C program to demonstrate pointer to pointer 
//ref: https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
#include<stdio.h>
int main() 
{ 
	int var = 10; 

	// pointer for var 
	int *ptr1; 

	// storing address of var in ptr1 
	ptr1 = &var; 
	*ptr1=20; //Change the value of var using pointer
	// double pointer for ptr1 
	int **ptr2; 
	
	// Storing address of ptr2 in ptr1 
	ptr2 = &ptr1; 
	
	// Displaying value of var using 
	// both single and double pointers 
	printf("Value of var = %d\n", var ); 
	printf("Value of var using single pointer = %d\n", *ptr1 ); 
	printf("Value of var using double pointer = %d\n", **ptr2); 
	
	**ptr2=30; // change the value of var using double pointer
	
	printf("\nValue of var = %d\n", var ); 
	printf("Value of var using single pointer = %d\n", *ptr1 ); 
	printf("Value of var using double pointer = %d\n", **ptr2); 
	
return 0; 
}
 
