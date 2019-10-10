#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 5
#define COL 4

void print_a_matrix(int *mat);
void exchange_row(int *mat, int row_a, int row_b);

int main()
{
	int x, y;
	int matrix[ROW][COL];
//create matrix with rand om values
srand(time(0));
	for (x=0;x<ROW;x++)
	{
	for (y=0;y<COL;y++)
	{
	matrix[x][y]=(rand()%9)+1;
	}
	}
	printf("The Matrix is: \n");
	//call print_a_matrix function
	print_a_matrix(&matrix[0][0]);

//Call exchange_row(int *mat, int row_a, int row_b) function
	
	exchange_row(&matrix[0][0],2,4);
	printf("\nThe row exchanged matrix is: \n");
	print_a_matrix(&matrix[0][0]);

	return 0;
}
// print_a_matrix function
void print_a_matrix(int *mat)
{
	int i, j;
	for (i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d ", mat[(i*COL+j)]);
		}
		printf("\n");
	}
		
}
// row_exchnaged function:
void exchange_row(int *mat, int row_a, int row_b)
{
	int i, temp;
	for (i=0;i<COL;i++)
	{
		temp=mat[row_a*COL+i];
		mat[row_a*COL+i]=mat[row_b*COL+i];
		mat[row_b*COL+i]=temp;
	}
	
}