#include <stdio.h>
#define SIZE 7
int main()
{
	int array[] = {35,97,19,4,57,27,36};

	//sort array in ascending order
	int i, j, temp;
        for(i=1;i<SIZE;i++)
	{
		temp = array[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp < array[j])
			{
				//shift element to the right
				array[j+1] = array[j];
				//update empty position
				//insert at the proper location
				array[j] = temp;
			}
		}
		
	}

	printf("sorted array: \n");
	for(i=0;i<SIZE;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
 
	return 0;
}

