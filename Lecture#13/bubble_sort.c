#include <stdio.h>
#define SIZE 8

int main()
{
	int n = SIZE-1;
	int array[] = {6,5,3,1,8,7,2,4};

	int i, temp, swap = 0;

	//sort number in ascending order
	do
	{
		swap = 0;
		for(i=0;i<n;i++)
		{
			//swap the two numbers if order is incorrect
			if(array[i]>array[i+1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				//set the swap flag
				swap = 1;
			}
		}
		n--;
	}while(swap != 0);

	printf("sorted array: \n");
	for(i=0;i<SIZE;i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

