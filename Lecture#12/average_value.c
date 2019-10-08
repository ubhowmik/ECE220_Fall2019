#include <stdio.h>
/* size of the array */
#define N 10
float average(int *input_array, int size);
int main()
{
    int array[N];
    int i;
    float Average = 0.0f;
    /* get array elements from the user */
    for (i = 0; i < N; i++)
    {
         printf("Enter array element %i: ", i);
         scanf("%i", &array[i]);
    }
    Average = average(&array[0], N);
    printf("average=%f\n", Average);
    return 0;
}

float average(int *input_array, int size)
{
    int i;
    float sum = 0.0f;
	float Avg = 0.0f;
    /* sum up the array elements */
    for (i = 0; i < size; i++)
        sum += input_array[i];
    /* average = sum / size */
    Avg = sum/size;
    return Avg;
}
