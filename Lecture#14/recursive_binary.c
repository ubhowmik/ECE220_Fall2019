#include <stdio.h>

#define LENGTH 9

int binary(int array[], int num, int start, int end);

int main()
{
	int array[]={1,3,5,7,9,11,13,15,17};

	return binary(array, 3, 0, LENGTH-1);
}

int binary(int array[], int item, int start, int end)
{
	if(start>end)
		return -1;

	int middle = (start+end)/2;

	if(item == array[middle]){
		printf("Found item at index %d\n", middle);
		return middle;}
	else if(item > array[middle])
		return binary(array, item, middle+1, end);
	else //item < array[middle]
		return binary(array, item, start, middle-1);

}
