#include <stdio.h>
#include "grid.h"

// Procedure: print_grid
void print_grid(int grid[5][5])
{
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++) {
      printf("%2d", grid[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_grid
void parse_grid(const char fpath[], int grid[5][5]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++) {
      fscanf(reader, "%d", &grid[i][j]);
    }
  }
  fclose(reader);
}

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array grid.
int is_val_in_row(const int val, const int i, const int grid[5][5]) {

  assert(i>=0 && i<=5);

  int j;
  for(j=0; j<5; j++) {
    if(grid[i][j] == val) return 1;
  }
  return 0;
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array grid.
int is_val_in_col(const int val, const int j, const int grid[5][5]) {

  assert(j>=0 && j<=5);

  int i;
  for(i=0; i<5; i++) {
    if(grid[i][j] == val) return 1;
  }
  return 0;
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int grid[5][5]) {
  if(is_val_in_row(val, i, grid)) return 0;
  if(is_val_in_col(val, j, grid)) return 0;
  return 1;
}

// Procedure: solve_grid
// Solve the given grid instance.
int solve_grid(int grid[5][5]) {

int i, j, val;

if (!FindUnassignedLocation(grid,&i,&j)){
return 1;
}						
	for(val=1; val<=5; val++) {
     if(is_val_valid(val, i, j, grid)) {
      grid[i][j] = val;
      if(solve_grid(grid)) {
        return 1;
      }
	    grid[i][j] = 0;
    }
  }
  return 0;
}

int FindUnassignedLocation(int grid[5][5], int *i, int *j) 
{ 
	int m,n;
	for (m = 0; m < 5; m++){
		for (n = 0; n< 5; n++) {
			if (grid[m][n] ==0) {
				*i=m;
				*j=n;
				return 1;
			}
		}
	}
			return 0;
} 

// Procedure: write_grid
void write_grid(const char wpath[], int grid[5][5]) {
  FILE *writer = fopen(wpath, "w");
  assert(writer != NULL);
  int i, j;
  for(i=0; i<5; i++) {
    for(j=0; j<5; j++) {
      fprintf(writer, " %d", grid[i][j]);
    }
     fprintf(writer, "\n");
  }
  fclose(writer);
}