#include <stdio.h>
#define SIZE 8
int main()
{
	int array[] = {6,5,3,1,8,7,2,4};

	//sort array in ascending order
	int i, j, temp;
        for(i=1;i<SIZE;i++)
	{
		temp = array[i];
		for(j=i-1;(j>=0 && (temp < array[j]));j--)
		{
				//shift element to the right
				array[j+1] = array[j];
		}		
		//insert at the proper location
		array[j+1] = temp;
					
	}

	printf("sorted array: \n");
	for(i=0;i<SIZE;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
 
	return 0;
}

