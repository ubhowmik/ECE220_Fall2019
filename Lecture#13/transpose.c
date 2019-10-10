#include <stdio.h>
#define ROW 2
#define COL 5

void transpose2(int *in, int *out);
void transpose(int in[ROW][COL], int out[COL][ROW]);
void print_matrix(int *matrix, int row, int col);

int main(){

	int in_array[ROW][COL], out_array[COL][ROW];
	
	//Set in_array value
	int i,j;
        for(i=0;i<ROW;i++){
                for(j=0;j<COL;j++){
			in_array[i][j]=i*COL+j;
                }
	}

	//Print in_array value
	printf("Input Array: \n");
	print_matrix(&in_array[0][0], ROW, COL);

	//Perform transpose
	//transpose(in_array, out_array);
	transpose2(&in_array[0][0], &out_array[0][0]);

	//Print out_array value
	printf("Output Array: \n");
	print_matrix(&out_array[0][0], COL, ROW);
	
	return 0;
}

void transpose(int in_array[ROW][COL], int out_array[COL][ROW]){

	int i,j;
        for(i=0;i<ROW;i++){
                for(j=0;j<COL;j++){
			out_array[j][i] = in_array[i][j];
                }
	}
}

void transpose2(int *in_array, int *out_array){

	int i,j;
        for(i=0;i<ROW;i++){
                for(j=0;j<COL;j++){
			out_array[j*ROW+i] = in_array[i*COL+j];
                }
	}
}

void print_matrix(int *matrix, int row, int col){
        int i,j;
        for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                        printf("%d ", matrix[i*col+j]);
                }
                printf("\n");
        }
}

