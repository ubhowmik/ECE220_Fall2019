#include <stdio.h>
#define SIZE 5
//function to interchange 2 rows (x,y) in a 5x5 matrix
//int matrix_change(int matrix[SIZE][SIZE], int x, int y);
int matrix_ptr(int *matrix, int x, int y);
int main()
{
        int i, j;
        int matrix[SIZE][SIZE];

        printf("Initial Matrix: \n");
        for(i=0;i<SIZE;i++)
        {
                for(j=0;j<SIZE;j++)
                {
                        matrix[i][j]= i*SIZE+j;
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }
        printf("New Matrix: \n");
        //int rc = matrix_change(matrix, 2, 4);
        int rc = matrix_ptr(&matrix[0][0], 2, 4);
        if (rc != 0){
                printf("exchange row index out of bound\n");
                return rc;
        }
        
		for(i=0;i<SIZE;i++)
        {
                for(j=0;j<SIZE;j++)
                {
                        printf("%d ", matrix[i][j]);
                }
                printf("\n");
        }
        return 0;
}

int matrix_ptr(int *matrix, int x, int y){
        //if x and y is greater than 5 or less than 0, just exit and return 1
        if((x>SIZE-1) || (y>SIZE-1) || (x<0) || (y<0))
                return 1;

        int j,temp;
        for(j=0;j<SIZE;j++){
                temp=matrix[x*SIZE+j];
                matrix[x*SIZE+j] = matrix[y*SIZE+j];
                matrix[y*SIZE+j] = temp;
        }
        return 0;
}

/*
int matrix_change(int matrix[SIZE][SIZE], int x, int y)
{
        //if x and y is greater than 5 or less than 0, just exit and return 1
        if((x>SIZE-1) || (y>SIZE-1) || (x<0) || (y<0))
                return 1;

        int j, temp=0;
        for(j=0;j<SIZE;j++)
        {
                temp = matrix[x][j];
                matrix[x][j] = matrix[y][j];
                matrix[y][j] = temp;
        }
        return 0;
}
*/