#include <stdio.h>

/*
 * Solve 4x4 n Queen problem using recursion with backtracking
 */

#define N 4
#define true 1
#define false 0


void printSolution(int board[N][N]);
int Solve(int board[N][N], int col);
int isSafe(int board[N][N], int row, int col);

int main()
{
	int board[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	//game started at row 0
	if(Solve(board,0) == false)
	{
		printf("Solution does not exist.\n");
		return 1;
	}

	printf("Solution: \n");
	printSolution(board);
	return 0;
}

int Solve(int board[N][N], int row)
{
	//base case
	if(row>=N)
		return true;

        //find a safe column(j) to place queen
	int j;
	for(j=0;j<N;j++)
	{
		//column j is safe, place queen here
		if(isSafe(board, row, j) == true)
		{
			board[row][j]=1;

			printf("Current Play: \n");
        		printSolution(board);

			//increment row to place the next queen					
			if(Solve(board, row+1) == true)
				return true;

			//attempt to place queen at row+1 failed, backtrack to row and remove queen
			board[row][j]=0;
			printf("Backtrack: \n");
			printSolution(board);
		}
	}

	return false;
}

int isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<N;j++)
		{
			//check whether there's a queen at the same column or the 2 diagonals
			if(((j==col) || (i-j == row-col) || (i+j == row + col)) && (board[i][j]==1))
				return false; 
		}
	}
	return true;
}


void printSolution(int board[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}
