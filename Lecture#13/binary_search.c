#include <stdio.h>
#define LENGTH 8

int linearsearch(int array[], int item);
int binarysearch(int array[], int item);

int main()
{
	int array[LENGTH] = {2,3,5,6,8,9,10,13};

	//int idx = linearsearch(array, array[5]);
	int idx = binarysearch(array, 3);

	printf("item is found at index %d \n", idx);
	return 0;
}
//Simple Solution - not efficient:
int linearsearch(int array[], int item)
{
	int i;
	for(i=0;i<LENGTH;i++)
	{
		if(array[i] == item)
			return i;
	}

	return -1; //item not found
}

int binarysearch(int array[], int item)
{
	int n = LENGTH;
	int start=0, end=n-1;
	int middle;

	while(start <= end){
		middle = (start+end)/2;
		if(array[middle] == item){
			return middle;
		}
		else if(array[middle] > item){
			//search lower half if middle value greater than search item
			end = middle-1;
		}
		else{
			//search upper half if middle value smaller than search item
			start = middle+1;
		}
	}

	return -1; //item not found
}